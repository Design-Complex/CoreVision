/*
 *  CVShaderTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/27/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include <gtest/gtest.h>
#include "CoreVision.h"

using namespace CV;

namespace {
	
	class CVShaderTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			
		}
		
		virtual void TearDown() {
			
		}
	};
	
	TEST_F( CVShaderTest, glsl ) {
		CVDisplay * disp = 0;
		CVDisplayList &displays = CVDisplayController::sharedInstance().displays();
		CVDisplayList::iterator it;
		for( it = displays.begin(); it != displays.end(); it++ ) {
			if( it != displays.begin() ) {
				disp = it->second;
				break;
			}
		}
		
		
		ASSERT_TRUE( disp != NULL ) << "Couldn't find a display!";
		
		CVDisplayContext & ctx = disp->displayContext();
		ASSERT_TRUE( &ctx != NULL ) << "Couldn't get display context!";
		
		ASSERT_NO_THROW( disp->capture() ) << "Couldn't capture display!";
		
		CVGraphicsController::sharedInstance().push( &ctx );
		ASSERT_TRUE( CVGraphicsController::sharedInstance().isGLSLSupported() ) << "Display doesn't support GLSL!";
		
		//char f[] =
//		"varying vec3 color;\n"
//		"void main (void)\n"
//		"{\n"
//		"		gl_FragColor = vec4 (color, 1.0);\n"
//		"}\n";
//		CVFragmentShader fs = CVFragmentShader();
//		fs.setSource( CVString( f ) );
//		
//		char v[] =
//		"varying vec3 color;\n"
//		"void main(void)\n"
//		"{\n"
//		"   color = vec3(gl_Vertex.x, 0.25, gl_Vertex.y);\n"
//		"	gl_Position = ftransform();\n"
//		"}\n";
//		CVVertexShader vs = CVVertexShader();
//		vs.setSource( CVString( v ) );
//		
//		CVShaderProgram sp( fs, vs );
//		sp.link();
		//sp.enable();
		
		ctx.lock();
		ctx.clear();
		
		CVOrthographicCamera cam( CVPixel( 0, 0 ), CVPixel( disp->width(), disp->height() ), 1.5, true );
		cam.view();
		
		CVColor fg( 1.0, .85, .35 );
		glColor3f( fg.r, fg.g, fg.b );
		
			CVRegularPolygon * gon = new CVRegularPolygon( 4 );
			gon->draw();
			gon->rotate( CVMath::PI / 6, CVVertex( 0, 0, 1 ) );
			gon->build();
			gon->draw();
		delete gon;
		
		//sp.disable();
		
		ctx.flush();
		ctx.unlock();
		
		CVGraphicsController::sharedInstance().pop();
		
		disp->release();
	}

};

int main( int argc, char **argv ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}