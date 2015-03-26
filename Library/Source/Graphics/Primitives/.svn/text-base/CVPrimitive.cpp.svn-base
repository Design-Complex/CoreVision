/*
 *  CVPrimitive.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMath.h"
#include "CVProperties.h"
#include "CVPrimitive.h"

using namespace CV;

CVRTTIDefine( CVPrimitive, CVObject )

CVPrimitive::CVPrimitive() try : CVObject::CVObject(), displayList_( glGenLists( 1 ) ), vertices_( ) {
	
} CVThrowAllExceptions()

CVPrimitive::CVPrimitive( const CVPrimitive &rhs ) try : displayList_( glGenLists( 1 ) ), vertices_( rhs.vertices_ ) {
	
} CVThrowAllExceptions()

CVPrimitive::~CVPrimitive() {
	glDeleteLists( displayList_, 1 );
	
	vertices_.clear();
	//vertices_.resize(0);
}

CVPrimitive & CVPrimitive::operator=( const CVPrimitive &rhs ) {
	if( this != &rhs ) {
		
		try {
			//CVTransformer::operator=( rhs ); // not sure if i want to do this
			
			// Set the instance variables
			glDeleteLists( displayList_, 1 );
			displayList_ = glGenLists( 1 );
			
			vertices_ = rhs.vertices_;
			
		} CVThrowAllExceptions()
	}
	
	this->build();
	
	return *this;
}

void CVPrimitive::build() {
	
}

void CVPrimitive::draw() {
	glCallList( displayList_ );
}
