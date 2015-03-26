/*
 *  CVDisplayThread.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVDisplayThread.h"
#include "CVGraphics.h"

using namespace CV;

CVRTTIDefine( CVDisplayThread, CVThread )

CVDisplayThread::CVDisplayThread() {
	
}

CVDisplayThread::CVDisplayThread( const CVDisplayThread &rhs ) {
	
}

CVDisplayThread::~CVDisplayThread() {
	
}

CVDisplayThread & CVDisplayThread::operator=( const CVDisplayThread &rhs ) {
	return *this;
}

void * CVDisplayThread::run() {
	return NULL;
}
