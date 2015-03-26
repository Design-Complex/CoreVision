/*
 *  CVFragmentShader.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/14/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVFragmentShader.h"

using namespace CV;

CVRTTIDefine( CVFragmentShader, CVShader );

CVFragmentShader::CVFragmentShader() : CVShader::CVShader() {
	glCreateShader( kCVFragmentShaderType );
}

CVFragmentShader::CVFragmentShader( const CVFragmentShader &rhs ) {
	glCreateShader( rhs.shaderType() );
}

CVFragmentShader::~CVFragmentShader() {
	
}

const CVFragmentShader & CVFragmentShader::operator=( const CVFragmentShader &rhs ) {
	if( this != &rhs ) {
		/*
		 Add assignment operations here
		 */
	}
	
	return *this;
}

bool CVFragmentShader::operator==( const CVFragmentShader &rhs ) {
	if( this != &rhs ) {
		return false;
	}
	
	return true;
}

bool CVFragmentShader::operator!=( const CVFragmentShader &rhs ) {
	return ( *this == rhs ) ? false : true;
}
