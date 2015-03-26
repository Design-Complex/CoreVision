/*
 *  CVThreadManager.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 3/21/07.
 *  Copyright 2007 Rob Dotson. All rights reserved.
 *
 */

#ifndef _CVThreadManager_
#define _CVThreadManager_

#include "CVObject.h"
#include "CVSingleton.h"
#include "CVThread.h"

#include <vector>

namespace CV {
	
	#pragma GCC visibility push(default)

#define CVThreadList std::vector<CVThread *>;
	
	class CVThreadManager : public CVObject {
		CVSingletonDeclare( CVThreadManager )
		CVRTTIDeclare()
		
	private:
		std::vector<CVThread *> threads_;
		
	public:		
		int32_t threadCount();
		
		CVThread * spawn( CVRunnable *obj, bool detach = false );
		
		void cleanup();
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVThreadManager_
