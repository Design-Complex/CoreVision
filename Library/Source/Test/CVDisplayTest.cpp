/*
 *  CVDisplayTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 6/3/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CoreVision.h"
#include <gtest/gtest.h>

using namespace CV;

namespace {
	
	class CVDisplayTest : public testing::Test {
	protected:		
		virtual void SetUp() {
			
		}
		
		virtual void TearDown() {
			
		}
	};
	
	TEST_F( CVDisplayTest, sharedDisplayController ) {
		
		CVDisplayController & dc = CVDisplayController::sharedInstance();
		
		ASSERT_TRUE( &dc != 0 ); // << "no display controller found!";
		
		CVDisplayController & dc1 = CVDisplayController::sharedInstance();
		
		ASSERT_TRUE( dc == dc1 ); // << "multiple display controllers created!";
	}
	
	TEST_F( CVDisplayTest, mainDisplay ) {
		CVDisplayController & dc = CVDisplayController::sharedInstance();
		ASSERT_TRUE( &dc != NULL ); // << "no display controller found!";
		
		CVDisplayList & dl = dc.displays();
		ASSERT_GT( dl.size(), 0 ); // << "no displays found!";
		
		CVDisplay * disp = dl[ kCVMainDisplay ];
		ASSERT_TRUE( disp != NULL ); // << "couldn't find main display!";
		
		CVDisplay * d1 = dc.mainDisplay();
		ASSERT_TRUE( d1 != NULL ); // << "couldn't get copy of main display!";
		ASSERT_EQ( disp, d1 ); // << "display pointers not equal!";
		
		d1 = NULL;
		
		CVDisplay &d = *disp;
		d.capture();
		ASSERT_TRUE( d.isCaptured() ); // << "Couldn't caputure display: " << d.displayId();
		
		d.release();
		ASSERT_FALSE( d.isCaptured() ); // << "Couldn't release display: " << d.displayId();
		
	}
	
	TEST_F( CVDisplayTest, infoTest ) {
		CVDisplayController & dc = CVDisplayController::sharedInstance();
		
		ASSERT_TRUE( &dc != NULL ) << "no display controller found!";
		
		CVDisplayList & dl = dc.displays();
		ASSERT_TRUE( dl.size() != 0 ) << "no displays found!";
		
		CVDisplayList::iterator dli;
		for( dli = dl.begin(); dli != dl.end(); dli++ ) {
			CVDisplay *d = dli->second;
			std::cout << d->description().utf8String();
		}
	}
	
	TEST_F( CVDisplayTest, captureTest ) {
		CVDisplayController & dc = CVDisplayController::sharedInstance();
		
		ASSERT_TRUE( &dc != NULL ); // << "no display controller found!";
		
		CVDisplayList & dl = dc.displays();
		ASSERT_TRUE( dl.size() != 0 ); // << "no displays found!";
		
		CVDisplayList::iterator dli;
		for( dli = dl.begin(); dli != dl.end(); dli++ ) {
			CVDisplay *d = dli->second;
			d->capture();
			ASSERT_TRUE( d->isCaptured() ); // << "Couldn't caputure display: " << d->displayId();
			
			d->release();
			ASSERT_FALSE( d->isCaptured() ); // << "Couldn't release display: " << d->displayId();
		}
	}
	
	TEST_F( CVDisplayTest, clearTest ) {
		
	}
};

int main( int argc, char **argv ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}