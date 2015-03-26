/*
 *  CVShaderDocument.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVShaderDocument_
#define _CVShaderDocument_

#include "CVXMLDocument.h"

namespace CV {
	
	#pragma GCC visibility push(default)

	class CVShaderProgram;
	
#define kCVShaderDocumentExtension .shdr
	
	class CVShaderDocument : public CVXMLDocument {
	private:
		CVPrivateCopyAndAssign( CVShaderDocument );
		CVShaderProgram		*program_;
		
	public:
		CVRTTIDeclare()
		
		CVShaderDocument( CFURLRef loc = NULL );
		CVShaderDocument( CVShaderProgram *prog = 0 );
		
		virtual ~CVShaderDocument();
		
		CVShaderProgram * program();
		void setProgram( CVShaderProgram *prog );
		
		virtual void parseTree();
	};
	
	class CVShaderDocumentNULLProgramException : public CVException {};
	class CVShaderDocumentInvalidXMLException : public CVException {};
	
	#pragma GCC visibility pop
	
}

#endif // _CVShaderDocument_
