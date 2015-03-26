/*
 *  CVXMLObject.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/10/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVXMLObject.h"
#include "CVException.h"

using namespace CV;

CVRTTIDefine( CVXMLObject, CVObject )

CFXMLNodeRef CVXMLObject::XMLNode() const {
	throw CVUndefinedMethodException();
}

CFXMLTreeRef CVXMLObject::XMLTree() const {
	throw CVUndefinedMethodException();
}

//CFXMLNodeRef CVObject::XMLNode() const {
//	CFXMLElementInfo info;
//	info.attributes = NULL;
//	info.attributeOrder = NULL;
//	info.isEmpty = true;
//	
//	return CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeElement, CFSTR( "object" ), &info, kCFXMLNodeCurrentVersion );
//}
//
//CFXMLTreeRef CVObject::XMLTree() const {
//	CFXMLNodeRef node = this->XMLNode();
//	CFXMLTreeRef tree = CFXMLTreeCreateWithNode( kCFAllocatorDefault, node );
//	
//	CFRelease( node );
//	
//	return tree;
//}