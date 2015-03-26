/*
 *  CVMutex.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVMutex_
#define _CVMutex_

#include "CVLock.h"
#include <pthread.h>

namespace CV {
	
	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @abstract    A fly-weight concrete wrapper interface for pthread mutexes.
	 @namespace   CV
	 */
		
	class CVMutex : public CVLock {
		CVPrivateCopyAndAssign( CVMutex );
		
		friend class CVClock;
		
	private:
		pthread_mutex_t mutex_;
		
	protected:
		pthread_mutex_t * raw();
		
	public:
		/*!
		 @method     
		 @abstract   Default initializer. This initializer doesn't acquire the mutex.
		 */
		CVMutex();
		virtual ~CVMutex();
		
		bool acquire();
		bool release();
	};
	
	#pragma GCC visibility pop
}

#endif // _CVMutex_
