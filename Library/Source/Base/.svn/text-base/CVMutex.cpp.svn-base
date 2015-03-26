/*
 *  CVMutex.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMutex.h"

using namespace CV;

CVMutex::CVMutex() : CVLock::CVLock(), mutex_() {
	pthread_mutex_init( &mutex_, NULL ); // Default attributes
}

CVMutex::~CVMutex() {
	pthread_mutex_destroy( &mutex_ );
}

bool CVMutex::acquire() {
	CV_ASSERT( this->isLocked() != true );
	
	int32_t err = pthread_mutex_lock( &mutex_ );
	switch( err ) {
		case 0:
			locked_ = true;
			return true;
		case EDEADLK:
			// CVLog( potential deadlock );
			break;
		case EINVAL:
			// CVLog( invalid lock );
			break;
	}
	
	return false;
}

bool CVMutex::release() {
	CV_ASSERT( this->isLocked() );
	
	int32_t err = pthread_mutex_unlock( &mutex_ );
	switch( err ) {
		case 0:
			locked_ = false;
			return true;
		case EINVAL:
			// CVLog( invalid lock );
			break;
		case EPERM:
			// CVLog( lock not held );
			break;
	}
	
	return false;
}

pthread_mutex_t * CVMutex::raw() {
	return &mutex_;
}
