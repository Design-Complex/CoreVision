/*
 *  CVObject.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVObject_
#define _CVObject_

#include "CVDefines.h"
#include "CVRTTI.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @abstract    An abstract base class for the CoreVision framework.
	 @discussion  An abstract base class for the CoreVision framework, defining default methods for RTTI (Run-Time Type Information) introspection, and basic comparisons.
	 */
	class CVObject {
	
	public:
		CVRTTIDeclare()
		
		virtual ~CVObject();
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of a secified class.
		 @param type A CVRTTI class reference to be compared against.
		 @return A boolean value indicating if the current object is a member of the specified class.
		 */
		virtual bool isExactly( const CVRTTI & type ) const;
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of the specified object's class.
		 @param obj The CVObject pointer whose class is to be compared against.
		 @return A boolean value indicating if the current object is a member of the specified object's class.
		 */
		virtual bool isExactlyTypeOf( const CVObject * obj ) const;
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of the specified object's class.
		 @param obj The CVObject reference whose class is to be compared against.
		 @return A boolean value indicating if the current object is a member of the specified object's class.
		 */
		virtual bool isExactlyTypeOf( const CVObject & obj ) const;
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of any subclass of a secified class.
		 @param type A CVRTTI class reference to be compared against.
		 @return A boolean value indicating if the current object is a member of any subclass of the specified class.
		 */
		virtual bool isDerived( const CVRTTI & type ) const;
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of any subclass of the specified object's class.
		 @param obj The CVObject pointer whose class is to be compared against.
		 @return A boolean value indicating if the current object is a member of any subclass of the specified object's class.
		 */
		virtual bool isDerivedTypeOf( const CVObject * obj ) const;
		
		/*!
		 @method     
		 @abstract   A method to query if the current object is a member of any subclass of the specified object's class.
		 @param obj The CVObject reference whose class is to be compared against.
		 @return A boolean value indicating if the current object is a member of any subclass of the specified object's class.
		 */
		virtual bool isDerivedTypeOf( const CVObject & obj ) const;
		
		/*!
		 @method     
		 @abstract   The assignment operator for an object.
		 */
		const CVObject & operator=( const CVObject &rhs );
		
		/*!
		 @method     
		 @abstract   The equality comparison operator for an object.
		 @discussion This operator first checks the address of the object and compares the contents, if any.
		 */
		virtual bool operator==( const CVObject &rhs ) const;
		
		/*!
		 @method     
		 @abstract   The inequality comparison operator for an object.
		 @discussion The default implementation of this operator is the negation of the equality operator.
		 */
		virtual bool operator!=( const CVObject &rhs ) const;
		
		
		/*!
		 @method     
		 @abstract   A method to print the string descriptor of an object
		 @discussion The default implementation returns a string containing "<type>@<address>".
		 */
		virtual CVString description() const;
	};
	
	#pragma GCC visibility pop
	
}

#endif // _CVObject_
