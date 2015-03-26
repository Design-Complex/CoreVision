/*
 *  CVXMLObject.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/10/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVXMLObject_
#define _CVXMLObject_

#include "CVBase.h"

namespace CV {

	#pragma GCC visibility push(default)
	
	class CVXMLObject {
		CVPrivateCopyAndAssign( CVXMLObject );
		
	public:
		CVRTTIDeclare()
		
		virtual ~CVXMLObject() {}
		
		/*!
		 @method     
		 @abstract   Return a CoreFoundation CFXMLNodeRef description of the object.
		 @discussion Return an XML 1.1 description of the object and its contents. This method must
		 be overloaded by all subclasses of object.
		 */
		
		virtual CFXMLNodeRef XMLNode() const;
		
		/*!
		 @method     
		 @abstract   Return a CoreFoundation CFXMLTreeRef description of the object.
		 @discussion Return an XML 1.1 description of the object and its contents as
		 an XML tree. This method must be overloaded by all subclasses of object.
		 */
		virtual CFXMLTreeRef XMLTree() const;
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVXMLObject_
