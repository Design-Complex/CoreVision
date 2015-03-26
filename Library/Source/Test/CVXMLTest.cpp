/*
 *  CVXMLTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/24/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "CoreVision.h"

int32_t main() {
	
	CFURLRef location = CFURLCreateWithFileSystemPath( kCFAllocatorDefault, CFSTR( "/tmp/foo.shdr" ), kCFURLPOSIXPathStyle, false );
	if( !location ) std::cerr << "No location!";
	
	CVDisplayContext *ctx = CVDisplayContext::offscreenContext();
	ctx->setCurrent( true );
	
	char f[] =
	"varying vec3 color;\n"
	"void main (void)\n"
	"{\n"
	"		gl_FragColor = vec4 (color, 1.0);\n"
	"}\n";
	CVShader *fs = new CVShader();
	fs->setSource( new CVString( f ) );
	fs->setIdentifier( "fs" );
	
	char v[] =
	"varying vec3 color;\n"
	"void main(void)\n"
	"{\n"
	"   color = vec3(gl_Vertex.x, 0.25, gl_Vertex.y);\n"
	"	gl_Position = ftransform();\n"
	"}\n";
	CVShader *vs = new CVShader();
	vs->setSource( new CVString( v ) );
	vs->setIdentifier( "vs" );
	
	CVShaderProgram sp( fs, vs );
	sp.setIdentifier( "foo" );
	
	CVShaderDocument doc( &sp );
	doc.save( location );
	
	CVShaderDocument pp( location );
	pp.save();
}