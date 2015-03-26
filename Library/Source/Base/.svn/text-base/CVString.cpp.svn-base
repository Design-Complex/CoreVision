/*
 *  CVString.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVString.h"
#include <wchar.h>
#include <iostream>

using namespace CV;

CVRTTIDefine( CVString, CVObject )

static inline CFStringEncoding CVGetWideStringEncoding() {
	
	return ( CFByteOrderGetCurrent() == CFByteOrderLittleEndian ) 
	? ( sizeof( wchar_t ) == 4 ) 
	? kCFStringEncodingUTF32LE : kCFStringEncodingUTF16LE
	: ( sizeof( wchar_t ) == 4 ) 
	? kCFStringEncodingUTF32BE : kCFStringEncodingUTF16BE;
}

CVString::CVString( const char * buf ) : str_( NULL ) {
	if( ( str_ = CFStringCreateWithCString( kCFAllocatorDefault, buf, CFStringGetSystemEncoding() ) ) == NULL ) {
		// Throw an error
	}
}

CVString::CVString( const wchar_t * buf ) : str_( 0 ) {	
	if( ( str_ = CFStringCreateWithBytes( kCFAllocatorDefault, ( const uint8_t * )buf, wcslen( buf ) * sizeof( wchar_t ), CVGetWideStringEncoding(), false ) ) == NULL ) {
		// Throw an error
	}
}

CVString::CVString( CFStringRef str ) : str_( 0 ) {	
	if( ( str_ = CFStringCreateCopy( kCFAllocatorDefault, str ) ) == NULL ) {
		// Throw an error
	}
}

CVString::CVString( const CVString &rhs ) : str_( 0 ) {
	if( ( str_ = CFStringCreateCopy( kCFAllocatorDefault, rhs.str_ ) ) == NULL ) {
		// Throw an error
	}
}

CVString::~CVString() {
	if( str_ != NULL ) CFRelease( str_ );
}

const CVString & CVString::operator=( const CVString & rhs ) {
	if( this != &rhs ) {
		CFStringRef tmp = CFStringCreateCopy( kCFAllocatorDefault, rhs.str_ );
		if( tmp != NULL ) {
			CFRelease( str_ );
			str_ = tmp;
		} else {
			// Throw an error
		}
		
	}
	
	return *this;
}

bool CVString::operator==( const CVString &rhs ) const {
	return CVObject::operator==( rhs ) ? true : ( CFStringCompare( str_, rhs.str_, 0 ) == kCFCompareEqualTo );
}

bool CVString::operator!=( const CVString &rhs ) const {
	return !( *this == rhs );
}

bool CVString::operator<( const CVString &rhs ) const {
	return ( CFStringCompare( str_, rhs.str_, 0 ) == kCFCompareLessThan );
}

bool CVString::operator>( const CVString &rhs ) const {
	return ( CFStringCompare( str_, rhs.str_, 0 ) == kCFCompareGreaterThan );
}

CVIndex CVString::length() const {
	return CFStringGetLength( str_ );
}

CVString CVString::operator+( const CVString & rhs ) const {
	CVString str( *this );
	
	str += rhs;
	
	return str;
}

CVString & CVString::operator+=( const CVString & rhs ) {
	CFMutableStringRef tmp = CFStringCreateMutableCopy( kCFAllocatorDefault, 0, str_ );
	if( tmp != NULL ) {
		CFStringAppend( tmp, rhs.str_ );
		
		if( labs( CFStringGetLength( tmp ) ) == ( this->length() + rhs.length() ) ) {
			CFRelease( str_ );
			str_ = tmp;
		} else {
			CFRelease( tmp );
			
			// Throw an error
		}
	} else {
		// Throw an error
	}
	
	return *this;
}

const char * CVString::utf8String() const {
	const char * str;
	
	if( !( str = CFStringGetCStringPtr( str_, kCFStringEncodingUTF8 ) ) ) {
		CVIndex len = this->length() + 1;
		char * buf = ( char * )malloc( len );
		
		if( CFStringGetCString( str_, buf, len, kCFStringEncodingUTF8 ) )
			str = const_cast<char *>( buf );
	}
	   
	return str;
}

CFStringRef CVString::stringRef() const {
	return str_;
}

CVString CVString::description() const {
	return *this;
}

CVString CVString::toString( bool val ) {
	return ( val ) ? CVString( "true" ) : CVString( "false" );
}

CVString CVString::toString( int8_t val ) {
	char str[ 2 ];
	sprintf( str, "%i", val );
	return CVString( str );
}

CVString CVString::toString( uint8_t val ) {
	char str[ 2 ];
	sprintf( str, "%u", val );
	return CVString( str );
}

CVString CVString::toString( int16_t val ) {
	char str[ 128 ];
	sprintf( str, "%i", val );
	return CVString( str );
}

CVString CVString::toString( uint16_t val ) {
	char str[ 128 ];
	sprintf( str, "%u", val );
	return CVString( str );
}

CVString CVString::toString( int32_t val ) {
	char str[ 128 ];
	sprintf( str, "%d", val );
	return CVString( str );
}

CVString CVString::toString( uint32_t val ) {
	char str[ 128 ];
	sprintf( str, "%u", val );
	return CVString( str );
}

CVString CVString::toString( int64_t val ) {
	char str[ 128 ];
	sprintf( str, "%lli", val );
	return CVString( str );
}

CVString CVString::toString( uint64_t val ) {
	char str[ 128 ];
	sprintf( str, "%llu", val );
	return CVString( str );
}

CVString CVString::toString( float val ) {
	char str[ 128 ];
	sprintf( str, "%f", val );
	return CVString( str );
}

CVString CVString::toString( double val ) {
	char str[ 128 ];
	sprintf( str, "%f", val );
	return CVString( str );
}

CVString CVString::toString( long double val ) {
	char str[ 128 ];
	sprintf( str, "%Lf", val );
	return CVString( str );
}
