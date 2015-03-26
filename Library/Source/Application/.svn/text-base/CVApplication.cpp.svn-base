/*
 *  CVApplication.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVApplication.h"

using namespace CV;

CVRTTIDefine( CVApplication, CVObject )
CVSingletonDefine( CVApplication )

CVApplication::CVApplication() {}

CVApplication::~CVApplication() {}

extern "C" {
	int CVApplicationMain( int argc, char *argv[] ) {
		return CVApplication::sharedInstance().init( argc, argv );
	}
}

int CVApplication::init( int argc, char *argv[] ) {
	return EXIT_SUCCESS;
}
