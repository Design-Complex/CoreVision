/*
 *  CVXMLDocument.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVXMLDocument_
#define _CVXMLDocument_

#include "CVDocument.h"

namespace CV {
	
	#pragma GCC visibility push(default)

	class CVXMLDocument : public CVDocument {
	private:
		CVPrivateCopyAndAssign( CVXMLDocument );
		
		void appendInstructionTag();
		
	protected:	
		CFXMLTreeRef		tree_;
		CFXMLNodeRef		doc_;
		CFXMLDocumentInfo	info_;
		
	public:
		CVRTTIDeclare()
		
		CVXMLDocument( CFURLRef loc = NULL );
		virtual ~CVXMLDocument();
		
		virtual void parseTree();
		virtual void writeToFile( CVString path );
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVXMLDocument_
