/*
 *  CVClock.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 11/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVClock.h"
#include "CVGuard.h"
#include "CVMutex.h"

#include <cerrno>
#include <ctime>
#include <time.h>
#include <pthread.h>
#include <stdexcept>

using namespace CV;

CVRTTIDefine( CVClock, CVObject )

CVClock::CVClock( uint32_t interval ) : last_( mach_absolute_time() ), ticker_(), interval_(), next_() {
	int err = pthread_cond_init( &ticker_, NULL );
	switch( err ) {
		case EAGAIN:
			throw std::runtime_error( "Couldn't create thread condition at __FILE__, __LINE__" );
			break;
		case EINVAL:
			throw std::runtime_error( "Invalid thread condition attribute at __FILE__, __LINE__" );
			break;
		case ENOMEM:
			// "Couldn't allocate thread condition at __FILE__, __LINE__"
			throw std::bad_alloc();
			break;
		default: // no error
			break;
	}
	interval_.tv_sec = 0;
	interval_.tv_nsec = interval;
}

CVClock::~CVClock() {
	int err = 0;
	while( 0 != ( err = pthread_cond_destroy( &ticker_ ) ) ) {
		if( err == EBUSY )
			pthread_cond_broadcast( &ticker_ );
	}
}

uint64_t CVClock::waitForTick( CVClock & clock ) {	
	int err = pthread_cond_wait( clock.ticker(), clock.mutex().raw() );
	if( err ) {
		throw err;
	}
	
	return clock.time();
}

pthread_cond_t * CVClock::ticker() {
	return &ticker_;
}

CVMutex & CVClock::mutex() {
	return lock_;
}

const uint32_t CVClock::interval() const {
	return interval_.tv_nsec;
}

void CVClock::setInterval( uint32_t interval ) {
	CVSynchronize();
	
	interval_.tv_nsec = interval;
	this->tick();
}

uint64_t CVClock::tick() {
	CVSynchronize();
	
	last_ += static_cast<uint64_t>( interval_.tv_nsec ); // Calculate the current
	
	pthread_cond_broadcast( &ticker_ ); // Notify anyone waiting on a tick that we're done
	
	next_.tv_sec = 0; // always 0
	next_.tv_nsec = static_cast<clock_res_t>( interval_.tv_nsec - ( mach_absolute_time() - last_ ) );
	
	nanosleep( ( const timespec * )&next_, NULL );
	
	return last_;
}

const uint64_t CVClock::time() const {
	return mach_absolute_time();
}

void * CVClock::run() {
	while( 1 )
		this->tick();
	
	return NULL;
}
