/*
 *  CVException.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVException_
#define _CVException_

#include <stdexcept>
#include <exception>

#include "CVTypes.h"
#include "CVDefines.h"
#include "CVString.h"

#define CVThrowAllExceptions() catch( ... ) { throw; }

namespace CV {

	#pragma GCC visibility push(default)
	
	class CVException : public std::exception {
	public:
		CVRTTIDeclare()
		
		CVException();
		explicit CVException( const std::exception &rhs );
		CVException( const CVException &rhs );
		~CVException() throw();
		
		CVException & operator=( const CVException &rhs );
	};
	
	class CVUndefinedMethodException : public CVException {};
	
	class CVUnknownException : public CVException {};
	
	class CVContainerUnderflowException : public CVException {};
	
	class CVContainerNullNodeException : public CVException {};
	
	class CVContainerOverflowException : public CVException {};
	
	class CVCompatibilityException : public CVException {};
	
	class CVBoundsException : public CVException {};
	
	class CVMalformedURLException : public CVException {};
	
	#pragma GCC visibility pop
	
}

#endif // _CVException_
