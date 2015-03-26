/*
 *  CVDocument.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDocument_
#define _CVDocument_

#include "CVBase.h"

namespace CV {
	
	#pragma GCC visibility push(default)

	class CVString;
	
	class CVDocument : public CVObject {
	private:
		CVPrivateCopyAndAssign( CVDocument );
		
	protected:
		CFURLRef	location_;
		
	public:
		CVRTTIDeclare()
		
		CVDocument( CFURLRef loc = 0 );
		virtual ~CVDocument();
		
		void revert();
		void save( CFURLRef loc = 0 );
		virtual void writeToFile( CVString path );
	};
	
	class CVDocumentNULLLocationException : public CVException {};
	
	#pragma GCC visibility pop
	
}

#endif // _CVDocument_
