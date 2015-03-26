/*
 *  CVDisplayController.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVDisplayController.h"
#include "CVDisplay.h"

using namespace CV;

CVRTTIDefine( CVDisplayController, CVObject )

CVSingletonDefine( CVDisplayController )

CVDisplayController::CVDisplayController() :
main_(),
displays_() {
	// Get display Ids
	CVDisplayId displayIds[ kCVMaxDisplays ];
	CGDisplayCount count;
	
	CGDisplayErr ok = CGGetActiveDisplayList( kCVMaxDisplays, displayIds, &count );
	if( ok != kCGErrorSuccess )
		throw CVUnknownException();
	try {
		for( size_t i = 0; i < count; ++i )
			displays_[ displayIds[ i ] ] = new CVDisplay( displayIds[ i ] );
	} CVThrowAllExceptions()
	
	
	// Main display is the first display returned.
	main_ = displays_[ displayIds[ 0 ] ];
}

CVDisplayController::CVDisplayController( const CVDisplayController &rhs ) :
main_(),
displays_() {
	throw CVUnknownException();
}

CVDisplayController::~CVDisplayController() {
	
}

CVDisplayController & CVDisplayController::operator=( const CVDisplayController &rhs ) {
	throw CVUnknownException();
}

CVDisplayList & CVDisplayController::displays() {
	return displays_;
}

CVDisplay * CVDisplayController::mainDisplay() const {
	return main_;
}

void CVDisplayController::setMainDisplay( CVDisplay * display ) {
	main_ = display;
}
