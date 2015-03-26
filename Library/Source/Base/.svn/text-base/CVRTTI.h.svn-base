/*
 *  CVRTTI.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVRTTI_
#define _CVRTTI_

#include "CVDefines.h"

namespace CV {
	
	// Forward Declarations
	class CVString;

	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @abstract    A lightweight class for determining object-types at runtime.
	 @discussion  A class for determining RTTI (Run-Time Type Information) about objects at runtime. This allows dynamic type introspection and behavior modification at runtime. Supports single- and multiple-inheritance models.
	 @namespace   CV
	
	 */
	class CVRTTI {
	private:
		CVPrivateCopyAndAssign( CVRTTI );
		
		/*!
		 @var name_
		 @abstract  A CVString object containing the human-readable name of the object.
		 */
		CVString const *		name_;
		
		/*!
		 @var baseType_
		 @abstract  A pointer a CVRTTI object representing the superclass's base type.
		 */
		const CVRTTI *	baseClass_;
		
	public:
		/*!
			@function     
			@abstract   Default constructor for CVRTTI objects
			@discussion This constructor should not be called directly. It should only be called once to define the typename of CVObject subclasses.
		*/
		CVRTTI( CVString const * name = 0, const CVRTTI * superClass = 0 );
		
		/*!
		 @function     
		 @abstract   Default Destructor
		 */
		virtual ~CVRTTI();
		
		/*!
			@function     
			@abstract   A method to return the object's type name.
			@result A const reference to a CVString containing the human-readable type name of the object.
		*/
		const CVString & name() const;
		
		/*!
		 @function     
		 @abstract   A method to determine if a class's type exactly matches the given parameter at runtime.
		 @param type A CVRTTI object to compare.
		
		 */
		bool isExactly( const CVRTTI & type ) const;
		
		/*!
		 @function     
		 @abstract   A method to determine if a class inherits from the given parameter at runtime.
		 @param type A CVRTTI object to compare.
		 */
		bool isDerived( const CVRTTI & type ) const;
		
	};
	
	#pragma GCC visibility pop
	
}

/*!
    @defined
    @abstract   A macro to declare RTTI (Run Time Type Information) methods for a class.
*/

#define CVRTTIDeclare() \
public: \
	static const CVRTTI type_; \
	virtual const CVRTTI & type() const;


/*!
 @defined	
 @abstract   A macro to define RTTI (Run Time Type Information) methods for a class, as declared with CVRTTIDeclare()
 @param		class The name of the class to be registered with the type system.
 @param		baseClass The name of the base class this class inherits from.
 */

#define CVRTTIDefine(class,baseClass) \
	const CVRTTI class::type_(new CVString(#class),&baseClass::type_); \
	const CVRTTI & class::type() const { return class::type_; }

/*!
 @defined	
 @abstract   A macro to define RTTI (Run Time Type Information) methods for a template class, as declared with CVRTTIDeclare()
 @param		T The typename of the template class.
 @param		class The name of the class to be registered with the type system.
 @param		baseClass The name of the base class this class inherits from.
 */

#define CVRTTIDefineTemplate(T, class, baseClass ) \
	const CVRTTI class::type_(new CVString(#class),&baseClass::type_); \
	template <typename T> const CVRTTI & class::type() const { return class::type_; }

#endif // _CVRTTI_
