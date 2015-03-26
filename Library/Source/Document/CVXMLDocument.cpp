/*
 *  CVXMLDocument.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVXMLDocument.h"
#include "CVString.h"

using namespace CV;

CVRTTIDefine( CVXMLDocument, CVDocument )

CVXMLDocument::CVXMLDocument( CFURLRef loc ) : CVDocument::CVDocument( loc ), tree_(), doc_(), info_() {
	if( !loc ) { // If no location is defined, we don't want to read a document, we want to create a new one
		info_.sourceURL = NULL;
		info_.encoding = kCFStringEncodingUTF8;
		doc_ = CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeDocument, CFSTR( "" ), &info_, kCFXMLNodeCurrentVersion );
		tree_ = CFXMLTreeCreateWithNode( kCFAllocatorDefault, doc_ );
		
		CVXMLDocument::appendInstructionTag();
	} else {
		CFDataRef data;
		
		CFURLCreateDataAndPropertiesFromResource( kCFAllocatorDefault, loc, &data, NULL, NULL, NULL );
		tree_ = CFXMLTreeCreateFromData( kCFAllocatorDefault, data, loc, kCFXMLParserSkipWhitespace, kCFXMLNodeCurrentVersion );
		
		doc_ = CFXMLTreeGetNode( tree_ );
		
		this->parseTree();
	}
	
}

CVXMLDocument::~CVXMLDocument() {
	if( doc_ ) CFRelease( doc_ );
	if( tree_ ) CFRelease( tree_ );
}

void CVXMLDocument::appendInstructionTag() {
	CFXMLProcessingInstructionInfo info;
	info.dataString = CFSTR( "version=\"1.0\" encoding=\"utf-8\"" );
	CFXMLNodeRef node = CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeProcessingInstruction, CFSTR( "xml" ), &info, kCFXMLNodeCurrentVersion );
	CFXMLTreeRef tree = CFXMLTreeCreateWithNode( kCFAllocatorDefault, node );
	CFTreeAppendChild( tree_, tree );
	CFRelease( tree );
	CFRelease( node );
}

void CVXMLDocument::parseTree() {
	std::cout << "parsing tree!" << std::endl;
}

void CVXMLDocument::writeToFile( CVString path ) {
	try {
		info_.sourceURL = location_; 
		
		// Create the data from the document tree
		CFDataRef data = CFXMLTreeCreateXMLData( kCFAllocatorDefault, tree_ );
		
		try {
			// Write the data to disk
			std::ofstream of( path.utf8String(), std::ofstream::binary );
			of.write( ( const char * )CFDataGetBytePtr( data ), CFDataGetLength( data ) );
		} catch( ... ) {
			CFRelease( data );
			
			throw;
		}
		
		CFRelease( data );
	} CVThrowAllExceptions()
}