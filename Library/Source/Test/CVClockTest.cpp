/*
 *  CVClockTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 11/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "CoreVision.h"

namespace CV {
	class CVClockWatcher : public CVRunnable {
	private:
		CVClock * clock_;
		
	public:
		CVClockWatcher( CVClock * clock ) : clock_( clock ) {}
		
		void * run() {
			int err = CVClock::waitForTick( clock_ );
			uint64_t t0 = clock_->time();
			uint32_t dt = clock_->interval();
			if( err ) {
				std::cout << "error: " << err << std::endl;
			}
			while( err == 0 ) {
				uint64_t t = CVClock::waitForTick( clock_ ); 
				std::cout << t - t0 - dt << std::endl;
			}
			
			return NULL;
		}
		
		
	};
};

using namespace CV;

int main() {
	CVClock * clock = new CVClock( NSEC_PER_SEC / 2 ); // default clock 100 ns
	
	CVThreadManager &tm = CVThreadManager::sharedInstance();
	
	CVThread * heartbeat = tm.spawn( clock );
	std::cout << CVClock::waitForTick( clock ) << std::endl;
	CVThread * watcher = tm.spawn( new CVClockWatcher( clock ) );
	
	CVIndex i = 0;
	int err = 0;
	while( i++ < 128 ) {
		err = CVClock::waitForTick( clock );
		if( err )
			goto cleanup;
		
		std::cout << "TICK!" << std::endl;
	}
	
cleanup:
	heartbeat->join();
	watcher->join();
	exit( 0 );
}