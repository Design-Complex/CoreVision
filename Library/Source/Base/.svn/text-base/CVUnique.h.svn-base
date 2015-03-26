/*
 *  CVUnique.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 10/20/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVUnique_
#define _CVUnique_

#include <CoreFoundation/CoreFoundation.h>

/*!
    @defined 
    @abstract   <#(description)#>
    @discussion <#(description)#>
*/

#define kCVUUIDFormatString "%08x-%04x-%04x-%04x-%012x"

namespace CV {
	
	class CVString;
	
	#pragma GCC visibility push(default)

	class CVUnique {
	private:
		CFUUIDRef		uuid_;
		
		CVUnique & operator=( const CVUnique &rhs );
		
	public:
		CVUnique( const CVString &uuid );
		CVUnique( const CVUnique &rhs );
		virtual ~CVUnique();
		
		CVString uuidString() const;
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVUnique_
