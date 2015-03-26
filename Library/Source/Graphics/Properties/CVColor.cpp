/*
 *  CVColor.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVColor.h"

using namespace CV;

CVRTTIDefine( CVColor, CVVector4<float> )

// Static colors

const CVColor CVColor::white	= CVColor( 1.0f, 1.0f, 1.0f, 1.0f );
const CVColor CVColor::black	= CVColor( 0.0f, 0.0f, 0.0f, 1.0f );
const CVColor CVColor::neutral	= CVColor( 0.5f, 0.5f, 0.5f, 1.0f );
const CVColor CVColor::red		= CVColor( 1.0f, 0.0f, 0.0f, 1.0f );
const CVColor CVColor::green	= CVColor( 0.0f, 1.0f, 0.0f, 1.0f );
const CVColor CVColor::blue		= CVColor( 0.0f, 0.0f, 1.0f, 1.0f );

CVColor::CVColor( float x, float y, float z, float w ) : CVVector4<float>( x, y, z, w ), r( ( *this )[ 0 ] ), g( ( *this )[ 1 ] ), b( ( *this )[ 2 ] ), a( ( *this )[ 3 ] ) {
	
}

CVColor::CVColor( const CVColor &rhs ) : CVVector4<float>( rhs ), r( ( *this )[ 0 ] ), g( ( *this )[ 1 ] ), b( ( *this )[ 2 ] ), a( ( *this )[ 3 ] ) {
	
}

CVColor::~CVColor() {
	
}

CVColor & CVColor::operator=( const CVColor &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVVector4<float>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}
