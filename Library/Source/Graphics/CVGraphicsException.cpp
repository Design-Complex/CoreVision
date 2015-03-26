/*
 *  CVGraphicsException.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 6/5/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVGraphicsException.h"

using namespace CV;

CVRTTIDefine( CVGraphicsException, CVException )

CVGraphicsException::CVGraphicsException( CGLError error ) : error_( error ) {}

CVGraphicsException::CVGraphicsException( const CVGraphicsException &rhs ) : error_( rhs.error_ ) {}

CVGraphicsException & CVGraphicsException::operator=( const CVGraphicsException &rhs ) {
	if( this != &rhs ) {
		error_ = rhs.error_;
	}
	
	return *this;
}

const char * CVGraphicsException::what() const throw() {
	return CGLErrorString( error_ );
}

CVRTTIDefine( CVCoreVideoException, CVGraphicsException )
