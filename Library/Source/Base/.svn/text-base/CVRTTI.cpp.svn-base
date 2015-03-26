/*
 *  CVRTTI.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVRTTI.h"
#include "CVString.h"

using namespace CV;
	
CVRTTI::CVRTTI( CVString const * name, const CVRTTI * baseClass ) : name_( name ), baseClass_( baseClass ) {
	
}

CVRTTI::~CVRTTI() {
	delete name_;
}

const CVString & CVRTTI::name() const {
	return *name_;
}

bool CVRTTI::isExactly( const CVRTTI & type ) const {
	return &type == this;
}

bool CVRTTI::isDerived( const CVRTTI & type ) const {
	const CVRTTI * search = this;
	while( search ) {
		if( search == &type ) return true;
		
		search = search->baseClass_;
	}
	
	return false;
}	
