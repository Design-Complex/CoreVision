/*
 *  CVNamed.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/16/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVNamed_
#define _CVNamed_

#include "CVString.h"

namespace CV {
	
	// Forward Declarations
	class CVString;
	
	#pragma GCC visibility push(default)
	
	class CVNamed {
	private:		
		CVString name_;
		
	public:
		CVNamed();
		CVNamed( const CVNamed &rhs );
		virtual ~CVNamed();
		
		CVNamed & operator=( const CVNamed &rhs );
		
		const CVString & name() const;
		CVNamed & setName( const CVString & name );
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVNamed_
