/*
 *  CVDocument.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVDocument.h"
#include "CVBase.h"

using namespace CV;

CVRTTIDefine( CVDocument, CVObject )

CVDocument::CVDocument( CFURLRef loc ) : CVObject::CVObject(), location_( loc ) {
	if( loc != NULL )
		CFRetain( location_ );
}

CVDocument::~CVDocument() {
	CFRelease( location_ );
}

void CVDocument::revert() {
	
}

void CVDocument::save( CFURLRef loc ) {
	try {
		// Make sure we have a location to save the document
		// If loc is valid, we're performing a 'Save As...',
		// otherwise, save the document in-place.
		CV_ASSERT( loc || location_ );
		if( loc ) {
			if( location_ ) CFRelease( location_ );
			location_ = loc;
			CFRetain( location_ );
		}
		if( !location_ || CFURLHasDirectoryPath( location_ ) ) throw CVDocumentNULLLocationException(); // no location was specified
		
		// Get the path from the url. If no path was specified, throw an exception.
		UInt8 path[ kCVMaxPathLen ];
		if( !CFURLGetFileSystemRepresentation( location_, false, path, kCVMaxPathLen ) ) throw CVDocumentNULLLocationException();
		
		this->writeToFile( ( const char * )path );
		
	} CVThrowAllExceptions()
}

void CVDocument::writeToFile( CVString path ) {
	// Do Nothing
}
