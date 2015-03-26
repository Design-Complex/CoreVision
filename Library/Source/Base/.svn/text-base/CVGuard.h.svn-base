/*
 *  CVGuard.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVGuard_
#define _CVGuard_

#include "CVDefines.h"
#include "CVMutex.h"

namespace CV {
	
	#pragma GCC visibility push(default)
		
	template <class LOCK>
	class CVGuard {
		CVPrivateCopyAndAssign( CVGuard );
		
	private:
		LOCK &lock_;
		
	public:
		CVGuard( LOCK &lock ) : lock_( lock ) {
			lock_.acquire();
		}
		
		~CVGuard() {
			lock_.release();
		}
	};
	
	typedef CVGuard<CVMutex> CVMutexGuard;
	
	#pragma GCC visibility pop
}

#define CVSynchronize() CVMutexGuard guard( CVMutex() )

#endif // _CVGuard_
