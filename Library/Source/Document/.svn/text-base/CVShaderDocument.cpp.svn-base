/*
 *  CVShaderDocument.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVShaderDocument.h"
#include "CVShaderProgram.h"

using namespace CV;

CVRTTIDefine( CVShaderDocument, CVXMLDocument );

CVShaderDocument::CVShaderDocument( CFURLRef loc ) : CVXMLDocument::CVXMLDocument( loc ) {
	this->parseTree();
}

CVShaderDocument::CVShaderDocument( CVShaderProgram *prog ) : CVXMLDocument::CVXMLDocument( 0 ), program_( prog ) {
	try {
		CFXMLTreeRef tree = program_->XMLTree();
		CFTreeAppendChild( tree_, tree );
		CFRelease( tree );
	} CVThrowAllExceptions()
}

CVShaderDocument::~CVShaderDocument() {
	
}

CVShaderProgram * CVShaderDocument::program() {
	return program_;
}

void CVShaderDocument::setProgram( CVShaderProgram *prog ) {
	program_ = prog;
}

void CVShaderDocument::parseTree() {
	try {
		CFIndex count = CFTreeGetChildCount( tree_ );
		if( count != 2 ) std::cout << count << std::endl;
			//throw CVShaderDocumentInvalidXMLException();
		
		CFXMLNodeRef programXML = CFXMLTreeGetNode( CFTreeGetChildAtIndex( tree_, 1 ) );
		CFShow( CFXMLNodeGetString( programXML ) );
		
	} CVThrowAllExceptions()
}