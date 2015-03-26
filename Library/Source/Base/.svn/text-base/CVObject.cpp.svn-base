/*
 *  CVObject.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVObject.h"
#include "CVString.h"

#include <sstream>

using namespace CV;

const CVRTTI CVObject::type_( new CVString( "CVObject" ), NULL );

const CVRTTI & CVObject::type() const {
	return CVObject::type_;
}

CVObject::~CVObject() {
	
}

bool CVObject::isExactly( const CVRTTI & type ) const {
	return this->type().isExactly( type );
}

bool CVObject::isExactlyTypeOf( const CVObject * obj ) const {
	return obj && this->isExactly( obj->type() );
}

bool CVObject::isExactlyTypeOf( const CVObject & obj ) const {
	return this->isExactlyTypeOf( &obj );
}

bool CVObject::isDerived( const CVRTTI & type ) const {
	return this->type().isDerived( type );
}

bool CVObject::isDerivedTypeOf( const CVObject * obj ) const {
	return obj && this->isDerived( obj->type() );
}

bool CVObject::isDerivedTypeOf( const CVObject & obj ) const {
	return this->isDerivedTypeOf( &obj );
}

bool CVObject::operator==( const CVObject &rhs ) const {
	return ( this == &rhs ) ? true : false;
}

bool CVObject::operator!=( const CVObject &rhs ) const {
	return !( *this == rhs );
}

CVString CVObject::description() const {
	char ptr[ 128 ];
	sprintf( ptr, "@%p", this );
	
	return this->type().name() + CVString( ptr );
}
