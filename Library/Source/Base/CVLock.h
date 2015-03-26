/*
 *  CVLock.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVLock_
#define _CVLock_

#include "CVDefines.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @abstract    A fly-weight abstract class for implementation-specific thread locking.
	 @discussion  Override this class's methods to implement different types of implementation specific locks.
	 @namespace   CV
	 
	 */
		
	class CVLock {
		CVPrivateCopyAndAssign( CVLock );
		
	protected:
		bool locked_;
		
	public:
		CVLock() : locked_( false ) {}
		virtual ~CVLock() {};
		
		/*!
		 @method     
		 @abstract   Acquire the lock
		 */
		virtual bool acquire() = 0;
		
		/*!
		 @method     
		 @abstract   Release the lock.
		 */
		virtual bool release() = 0;
		
		/*!
		 @method     
		 @abstract   Test to see if the lock is already held.
		 */
		virtual bool isLocked() {
			return locked_;
		}
	};
	
	#pragma GCC visibility pop
}

#endif // _CVLock_
