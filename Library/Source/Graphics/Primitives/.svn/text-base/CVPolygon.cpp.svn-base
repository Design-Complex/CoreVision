/*
 *  CVPolygon.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVPolygon.h"

using namespace CV;

CVRTTIDefine( CVPolygon, CVPrimitive )

CVPolygon::CVPolygon( CVVertex * verts, size_t count ) try : CVPrimitive::CVPrimitive() {
	try {
		for( size_t i = 0; i < count; i++ ) {
			this->vertices_.push_back( *( verts + i ) );
		}
	} CVThrowAllExceptions()
} CVThrowAllExceptions()

CVPolygon::CVPolygon( const CVPolygon &rhs ) try : CVPrimitive( rhs ) {
	
} CVThrowAllExceptions()

CVPolygon::~CVPolygon() {
	
}

CVPolygon & CVPolygon::operator=( const CVPolygon &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVPrimitive::operator=( rhs );
		} CVThrowAllExceptions()
	}
	
	return *this;
}

void CVPolygon::build() {
	glNewList( displayList_, GL_COMPILE );
	
	glPushMatrix();
	
	CVTransformer::transform();
	
	glBegin( GL_TRIANGLE_FAN );
	for( std::vector<CVVertex>::iterator it = vertices_.begin(); it != vertices_.end(); it++ )
		glVertex3fv( ( *it ).data() );
	glEnd();
	
	glPopMatrix();
	
	glEndList();
}
