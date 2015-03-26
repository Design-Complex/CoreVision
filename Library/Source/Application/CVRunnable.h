/*
 *  CVRunnable.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 3/21/07.
 *  Copyright 2007 Rob Dotson. All rights reserved.
 *
 */

#ifndef _CVRunnable_
#define _CVRunnable_

#include "CVBase.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	class CVRunnable {
		CVPrivateCopyAndAssign( CVRunnable );
		
	public:
		CVRunnable();
		virtual ~CVRunnable();
		virtual void * run() = 0;
		
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVRunnable_
