/*
 *  CVGraphicsControllerTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/10/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "CoreVision.h"
#include <gtest/gtest.h>

using namespace CV;

namespace {
	
	class CVGraphicsControllerTest : public ::testing::Test {
		
		virtual void SetUp(){
			
		}
		
		virtual void TearDown() {
			
		}
	};
	
	TEST_F( CVGraphicsControllerTest, sharedController ) {
		CVGraphicsController &gc = CVGraphicsController::sharedInstance();
		
		ASSERT_TRUE( &gc != NULL );
		
		CVGraphicsController &gc1 = CVGraphicsController::sharedInstance();
		
		ASSERT_TRUE( gc == gc1 );
	};
	
	TEST_F( CVGraphicsControllerTest, openGL ) {
		CVGraphicsController &gc = CVGraphicsController::sharedInstance();
		ASSERT_TRUE( &gc != NULL );
		
		ASSERT_THROW( gc.currentContext(), CVGraphicsException );
		
		ASSERT_THROW( gc.isGLSLSupported(), CVGraphicsException );
		
		CVDisplayContext ctx = CVDisplayContext::fullscreenContext( kCVMainDisplay );
		
		ASSERT_NO_THROW( gc.push( &ctx ) );
		
		CVVector2<int32_t> vers = gc.glVersion();
		if( vers.x < 2 ) {
			ASSERT_TRUE( gc.isExtensionSupported( "GL_ARB_shader_objects" ) );
			ASSERT_TRUE( gc.isExtensionSupported( "GL_ARB_vertex_shader" ) );
			ASSERT_TRUE( gc.isExtensionSupported( "GL_ARB_fragment_shader" ) );
			ASSERT_TRUE( gc.isExtensionSupported( "GL_ARB_shading_language_100" ) );
			
			ASSERT_TRUE( gc.isGLSLSupported() );
		} else {
			// TODO
		}
		
		ASSERT_FALSE( gc.isEnabled( GL_LIGHTING ) );
		
		gc.enable( GL_LIGHTING );
		ASSERT_TRUE( gc.isEnabled( GL_LIGHTING ) );
		
		gc.toggle( GL_LIGHTING );
		ASSERT_FALSE( gc.isEnabled( GL_LIGHTING ) );
		
		gc.toggle( GL_LIGHTING );
		ASSERT_TRUE( gc.isEnabled( GL_LIGHTING ) );
	}
	
}

int main( int argc, char **argv ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
