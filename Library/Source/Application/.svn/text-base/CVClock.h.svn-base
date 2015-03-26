/*
 *  CVClock.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 11/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVClock_
#define _CVClock_

#include "CVRunnable.h"
#include "CVLockable.h"

#include <mach/mach.h>
#include <mach/mach_time.h>
#include <mach/clock_types.h>

namespace CV {
	
	#pragma GCC visibility push(default)

	class CVClock : public CVRunnable, public CVLockable {
		CVPrivateCopyAndAssign( CVClock );
		CVRTTIDeclare()
	
	private:
		pthread_cond_t	ticker_;
		mach_timespec_t	interval_;
		mach_timespec_t next_;
		uint64_t		last_;
		
		pthread_cond_t * ticker();
		
		CVMutex & mutex();
		
	public:
		static uint64_t waitForTick( CVClock & clock );
		
		CVClock( uint32_t interval = 100 );
		virtual ~CVClock();
		
		// Accessor Methods
		
		const uint32_t interval() const;
		void setInterval( uint32_t interval );
		
		const uint64_t time() const;
		
		virtual uint64_t tick();
		
		virtual void * run();
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVClock_
