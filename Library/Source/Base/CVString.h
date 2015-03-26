/*
 *  CVString.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVString_
#define _CVString_

#include "CVObject.h"
#include <CoreFoundation/CoreFoundation.h>

namespace CV {
	
#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @superclass  CVObject
	 @abstract    A general string manipulation class.
	 @discussion  CVString is a cross platform class that takes char * and wchar * buffers and converts them to string objects that can be compared and manipulated.
	 */
	class CVString : public CVObject {
	private:
		CFStringRef str_;
		
	public:
		CVRTTIDeclare()
		
		/*!
		 @method     
		 @abstract   The default constructor for a CVString object from a character buffer.
		 */
		CVString( const char * buf = "" );
		
		/*!
		 @method     
		 @abstract   This constructor creates a CVString object from a wide-character buffer.
		 */
		CVString( const wchar_t * buf );
		
		/*!
		 @method     
		 @abstract   This constructor creates a CVString object from a wide-character buffer.
		 */
		CVString( CFStringRef str );
		
		/*!
		 @method     
		 @abstract   The copy constructor for a CVString object.
		 */
		CVString( const CVString & rhs );
		
		/*!
		 @method     
		 @abstract   The destructor for a CVString object.
		 */
		virtual ~CVString();
		
		/*!
		 @method     
		 @abstract   The assignment operator for a CVString object.
		 */
		const CVString & operator=( const CVString & rhs );
		
		/*!
		 @method     
		 @abstract   The equality comparison operator for a CVString object.
		 @discussion This operator first checks the address of the string, and compares the string contents, if any.
		 */
		virtual bool operator==( const CVString & rhs ) const;
		
		/*!
		 @method     
		 @abstract   The inequality comparison operator for a CVString object.
		 @discussion The default implementation of this operator is the negation of the equality operator.
		 */
		virtual bool operator!=( const CVString & rhs ) const;
		
		/*!
		 @method     
		 @abstract   The less-than comparison operator for a CVString object.
		 @return A boolean value which is true if the current string would come before the specified string in an alphabetically sorted list and false otherwise.
		 */
		virtual bool operator<( const CVString &rhs ) const;
		
		/*!
		 @method     
		 @abstract   The greater-than comparison operator for a CVString object.
		 @return A boolean value which is true if the current string would come after the specified string in an alphabetically sorted list and false otherwise.
		 */
		virtual bool operator>( const CVString &rhs ) const;
		
		/*!
		 @method     
		 @abstract   The character length of the string, not including the terminating NULL character.
		 */
		virtual CVIndex length() const;
		
		/*!
		 @method     
		 @abstract   The string concatenation operator.
		 @return A new CVString object containing the concatenation of two CVStrings.
		 */
		virtual CVString operator+( const CVString & rhs ) const;
		
		/*!
		 @method     
		 @abstract   The string append operator.
		 @discussion The string append operator resizes the current string and appends the specified string to it.
		 @return A reference to the current string after another has been appended.
		 */
		virtual CVString & operator+=( const CVString & rhs );
		
		/*!
		 @method     
		 @abstract   Returns a utf-8 encoded c-string pointer.
		*/
		virtual const char * utf8String() const;
		
		/*!
		 @method     
		 @abstract   Returns the CFStringRef used to store the CVString's data.
		 */
		CFStringRef	stringRef() const;
		
		/*!
		 @method     
		 @abstract   A method to print the string descriptor of an object
		 @discussion The default implementation returns a copy of the current string. For the default implementation, use str->CVObject::description() instead.
		 */
		virtual CVString description() const;
		
		// Static Methods
		/*!
		 @method     
		 @abstract   A method convert a basic numeric type to a CVString object.
		 @discussion The default implementation returns a copy of the current string. For the default implementation, use str->CVObject::description() instead.
		 @param val The only parameter, val, can be any of the following basic types: bool, int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t, float, double, or long double.
		 */
		
		static CVString toString( bool val );
		static CVString toString( int8_t val );
		static CVString toString( uint8_t val );
		
		static CVString toString( int16_t val );
		static CVString toString( uint16_t val );
		
		static CVString toString( int32_t val );
		static CVString toString( uint32_t val );
		
		static CVString toString( int64_t val );
		static CVString toString( uint64_t val );
		
		static CVString toString( float val );
		static CVString toString( double val );
		static CVString toString( long double val );
	};
	
#pragma GCC visibility pop

}
#endif // _CVString_
