/*
 *  CVThread.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 3/21/07.
 *  Copyright 2007 Rob Dotson. All rights reserved.
 *
 */

#ifndef _CVThread_
#define _CVThread_

#include <pthread.h>

#include "CVObject.h"

namespace CV {
	
	#pragma GCC visibility push(default)

	class CVRunnable;
	
	typedef enum {
		kCVInheritSchedAttr,
		kCVSchedParamAttr,
		kCVSchedPolicyAttr,
		kCVContentionScopeAttr,
		kCVStackSizeAttr,
		kCVStackAddressAttr,
		kCVDetachStateAttr
	} CVThreadAttribute;
	
	class CVThread : public CVObject {
		CVPrivateCopyAndAssign( CVThread );
		CVRTTIDeclare()
	
	private:
		pthread_t		thread_;
		pthread_attr_t	attr_;
		pthread_key_t	key_;
		void *			ret_;
		CVRunnable		* func_;
		bool			detached_;
		
		static void * run( void *thr );
		
	public:
		CVThread( CVRunnable *obj = NULL );
		~CVThread();
		
		// Access Routines
		CVRunnable * func();
		void setFunc( CVRunnable *obj );
		
		void * attr( CVThreadAttribute a );
		void setAttr( CVThreadAttribute a, void * val );
		
		int32_t priority();
		int32_t setPriority( int32_t priority );
		
		// Thread Routines
		int32_t create();
		int32_t detach();
		int32_t exit();
		int32_t join();
		int32_t cancel();
		
		// Operators
		virtual bool operator== ( const CVThread &rhs );
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVThread_
