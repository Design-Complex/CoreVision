/*
 *  CVUnique.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVUnique.h"
#include "CVString.h"

using namespace CV;

CVUnique::CVUnique( const CVString &uuid ) : uuid_( 0 ) {
	if( CVString() == uuid )
		uuid_ = CFUUIDCreate( kCFAllocatorDefault );
	else
		uuid_ = CFUUIDCreateFromString( kCFAllocatorDefault, uuid.stringRef() );
	
	CFRetain( uuid_ );
}

CVUnique::CVUnique( const CVUnique &rhs ) : uuid_( CFUUIDCreate( kCFAllocatorDefault ) ) {
	CFRetain( uuid_ );
}

CVUnique::~CVUnique() {
	if( uuid_ != NULL )
		CFRelease( uuid_ );
}

CVString CVUnique::uuidString() const {
	return CVString( CFUUIDCreateString( kCFAllocatorDefault, uuid_ ) );
}
