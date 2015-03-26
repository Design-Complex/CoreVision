/*
 *  CVThread.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 3/21/07.
 *  Copyright 2007 Rob Dotson. All rights reserved.
 *
 */
#include "CVThread.h"
#include "CVRunnable.h"

using namespace CV;

CVRTTIDefine( CVThread, CVObject )

void * CVThread::run( void *obj ) {
	if( obj ) {
		return ( void * )( ( CVRunnable * )obj )->run();
	}
	
	return NULL;
}

CVThread::CVThread( CVRunnable *obj ) : CVObject::CVObject(), key_( 0 ), ret_( 0 ), func_( obj ), detached_( false ), thread_(), attr_() {
	pthread_attr_init( &attr_ );
}

CVThread::~CVThread() {
	pthread_cancel( thread_ );
	pthread_exit( thread_ );
	
	delete func_;
}

CVRunnable * CVThread::func() {
	return func_;
}

void CVThread::setFunc( CVRunnable *obj ) {
	delete func_;
	func_ = obj;
}

void * CVThread::attr( CVThreadAttribute a ) {
	int32_t i;
	struct sched_param sp;
	size_t sz;
	void *addr;
	
	switch( a ) {
		case kCVInheritSchedAttr:
			pthread_attr_getinheritsched( &attr_, &i );
			return ( void * )i;
			break;
		case kCVSchedParamAttr:
			pthread_attr_getschedparam( &attr_, &sp );
			return ( void * ) new sched_param( sp );
			break;
		case kCVSchedPolicyAttr:
			pthread_attr_getschedpolicy( &attr_, &i );
			return ( void * )i;
			break;
		case kCVContentionScopeAttr:
			pthread_attr_getscope( &attr_, &i );
			return ( void * )i;
			break;
		case kCVStackSizeAttr:
			pthread_attr_getstacksize( &attr_, &sz );
			return ( void * )sz;
			break;
		case kCVStackAddressAttr:
			pthread_attr_getstackaddr( &attr_, &addr );
			return addr;
			break;
		case kCVDetachStateAttr:
			pthread_attr_getdetachstate( &attr_, &i );
			return ( void * )i;
			break;
		default:
			return NULL;
	};
}

void CVThread::setAttr( CVThreadAttribute a, void * val ) {
	switch( a ) {
		case kCVInheritSchedAttr:
			pthread_attr_setinheritsched( &attr_, *( ( int32_t * )val ) );
			break;
		case kCVSchedParamAttr:
			pthread_attr_setschedparam( &attr_, ( struct sched_param * )val );
			break;
		case kCVSchedPolicyAttr:
			pthread_attr_setschedpolicy( &attr_, *( ( int32_t * )val ) );
			break;
		case kCVContentionScopeAttr:
			pthread_attr_setscope( &attr_, *( ( int32_t * )val ) );
			break;
		case kCVStackSizeAttr:
			pthread_attr_setstacksize( &attr_, ( size_t )val );
			break;
		case kCVStackAddressAttr:
			pthread_attr_setstackaddr( &attr_, val );
			break;
		case kCVDetachStateAttr:
			pthread_attr_setdetachstate( &attr_, *( ( int32_t * )val ) );
			break;
		default:
			return;
	};
}

int32_t CVThread::priority() {
	struct sched_param sp;
	int32_t priority;
	
	int32_t err = pthread_getschedparam( thread_, &priority, &sp );
	if( err != 0 ) {
		// FIX ME
		std::cerr << "The thread doesn't exist?!" << std::endl;
	}
	
	return priority;
}

int32_t CVThread::setPriority( int32_t priority ) {
	struct sched_param sp;
	
	memset( &sp, 0, sizeof( struct sched_param ) );
	sp.sched_priority = priority;
	
	int32_t err = pthread_setschedparam( thread_, priority, &sp );
	if( err != 0 ) {
		// FIX ME
		std::cerr << "Failed to change thread priority!" << std::endl;
	}
	
	return err;
}

int32_t CVThread::create() {
	return pthread_create( &thread_, &attr_, &CVThread::run, ( void * )func_ );
}

int32_t CVThread::detach() {
	detached_ = true;
	return pthread_detach( thread_ );
}

int32_t CVThread::exit() {
	pthread_exit( &ret_ );
	return 0;
}

int32_t CVThread::join() {
	if( !detached_ ) return pthread_join( thread_, &ret_ );
	
	return 0; // Thread is detached, so cannot be joined
}

int32_t CVThread::cancel() {
	return pthread_cancel( thread_ );
}

bool CVThread::operator== ( const CVThread &thd ) {
	return static_cast<bool>( pthread_equal( thread_, thd.thread_ ) ); 
}
