/*
 *  CVThreadManager.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 3/21/07.
 *  Copyright 2007 Rob Dotson. All rights reserved.
 *
 */

#include "CVThreadManager.h"
#include "CVMutex.h"
#include "CVGuard.h"

using namespace CV;

CVRTTIDefine( CVThreadManager, CVObject )

CVSingletonDefine( CVThreadManager )

CVThreadManager::CVThreadManager() : CVObject::CVObject(), threads_() {	
	
}

CVThreadManager::~CVThreadManager() {
	cleanup();
}

int32_t CVThreadManager::threadCount() {
	return ( int32_t )threads_.size();
}

CVThread * CVThreadManager::spawn( CVRunnable *obj, bool detach ) {
	CVThread *thr = new CVThread( obj );
	
	if( thr->create() != 0 ) {
		delete thr;
		return NULL;
	}
	
	if( detach ) {
		if( thr->detach() != 0 ) {
			delete thr;
			return NULL;
		}
	}
	
	threads_.push_back( thr );
	return thr;
}

void CVThreadManager::cleanup() {
	while( threads_.size() ) {
		CVThread *thr = threads_.back();
		threads_.pop_back();
		thr->join();
		delete thr;
	}
}
