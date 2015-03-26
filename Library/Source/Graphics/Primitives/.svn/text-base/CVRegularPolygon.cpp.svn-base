/*
 *  CVRegularPolygon.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/28/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVRegularPolygon.h"

using namespace CV;

CVRTTIDefine( CVRegularPolygon, CVPolygon )

CVRegularPolygon::CVRegularPolygon( size_t verts ) try : CVPolygon::CVPolygon() {
	try {
		float theta = CVMath::PI2;
		float phi = ( 2.0 * CVMath::PI ) / verts;
		float gamma = 1. / sqrt( 2 );
		
		// Center
		vertices_.push_back( CVVertex( 0, 0, 0, 0 ) );
		
		// n - 1 vertices
		while( verts-- ) {
			vertices_.push_back( CVVertex( gamma * cos( theta ), gamma * sin( theta ), 0., 1. ) );
			theta -= phi;
		}
		
		// close the polygon
		vertices_.push_back( CVVertex( gamma, 0, 0, 0 ) );
		
		this->build();
	} CVThrowAllExceptions()
} CVThrowAllExceptions()

CVRegularPolygon::CVRegularPolygon( const CVRegularPolygon &rhs ) try : CVPolygon( rhs ) {
	
} CVThrowAllExceptions()

CVRegularPolygon::~CVRegularPolygon() {
	
}

CVRegularPolygon & CVRegularPolygon::operator=( const CVRegularPolygon &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVPolygon::operator=( rhs );
		} CVThrowAllExceptions()
	}
	
	return *this;
}
