/*
 *  CVLockable.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVLockable.h"

using namespace CV;

CVLockable::CVLockable() : lock_( ) {
	
}

CVLockable::~CVLockable() {
	
}

void CVLockable::lock() {
	if( !lock_.acquire() ) {
		// CVLog( unable to acquire lock );
	}
}

void CVLockable::unlock() {
	if( !lock_.release() ) {
		// CVLog( unable to release lock );
	}
}
