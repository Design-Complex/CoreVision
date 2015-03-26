/*
 *  CVNamed.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/16/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVNamed.h"
#include "CVString.h"

using namespace CV;

CVNamed::CVNamed() : name_() {}

CVNamed::CVNamed( const CVNamed &rhs ) : name_( ( CVString() != rhs.name_ ) ? CVString( rhs.name() + " copy" ) : CVString() ) {}

CVNamed::~CVNamed() {
	
}

CVNamed & CVNamed::operator=( const CVNamed &rhs ) {
	if( this != &rhs ) {
		name_ = ( CVString() != rhs.name_ ) ? CVString( rhs.name_ + " copy" ) : CVString();
	}
	
	return *this;
}

const CVString & CVNamed::name() const {
	return name_;
}

CVNamed & CVNamed::setName( const CVString &rhs ) {
	name_ = rhs;
	
	return *this;
}
