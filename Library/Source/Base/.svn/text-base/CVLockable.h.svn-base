/*
 *  CVLockable.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVLockable_
#define _CVLockable_

#include "CVDefines.h"
#include "CVMutex.h"
#include "CVGuard.h"

namespace CV {
	
	#pragma GCC visibility push(default)
		
	class CVLockable {
		CVPrivateCopyAndAssign( CVLockable );
		
	protected:
		CVMutex lock_;
		
	public:
		CVLockable();
		virtual ~CVLockable();
		
		virtual void lock();
		virtual void unlock();
	};
	
	#pragma GCC visibility pop
}

#endif // _CVLockable_
