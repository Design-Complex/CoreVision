/*
 *  CVVertexShader.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/14/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVVertexShader.h"

using namespace CV;

CVRTTIDefine( CVVertexShader, CVShader )

CVVertexShader::CVVertexShader() {
	
}

CVVertexShader::CVVertexShader( const CVVertexShader &rhs ) {
	
}

CVVertexShader::~CVVertexShader() {
	
}

const CVVertexShader & CVVertexShader::operator=( const CVVertexShader &rhs ) {
	if( this != &rhs ) {
		/*
		 Add assignment operations here
		 */
	}
	
	return *this;
}

bool CVVertexShader::operator==( const CVVertexShader &rhs ) {
	if( this != &rhs ) {
		return false;
	}
	
	return true;
}

bool CVVertexShader::operator!=( const CVVertexShader &rhs ) {
	return ( *this == rhs ) ? false : true;
}
