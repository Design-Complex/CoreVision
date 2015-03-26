/*
 *  CVRuntime.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 2/11/10.
 *  Copyright 2010 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVRuntime.h"

using namespace CV;

CVRTTIDefine( CVRuntime, CVApplication )
CVSingletonDefine( CVRuntime )

CVRuntime::CVRuntime() : status( 0 ) {
	
}

CVRuntime::~CVRuntime() {
	
}

void CVRuntime::setStatus( uint32_t s ) {
	status = s;
}

extern "C" {
	int CVRuntimeInit( int argc, char *argv[] ) {
		return CVRuntime::sharedInstance().init( argc, argv );
	}
	
	void CVRuntimeShutdown( uint32_t status ) {
		CVRuntime::sharedInstance().setStatus( status );
	}
}

int CVRuntime::init( int argc, char *argv[] ) {
	status = 1;
	while( status ) {
		
	}
	
	return status;
}