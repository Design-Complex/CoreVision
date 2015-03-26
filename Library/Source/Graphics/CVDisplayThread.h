/*
 *  CVDisplayThread.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDisplayThread_
#define _CVDisplayThread_

#include "CVBase.h"
#include "CVApp.h"

namespace CV {

	class CVDisplayThread : public CVRunnable {
		CVRTTIDeclare()
		
	private:
		CVDisplayThread( const CVDisplayThread &rhs );
		CVDisplayThread & operator=( const CVDisplayThread &rhs );
		
	public:
		CVDisplayThread();
		virtual ~CVDisplayThread();
		
		virtual void * run() = 0;
	};
	
}

#endif // _CVDisplayThread_
