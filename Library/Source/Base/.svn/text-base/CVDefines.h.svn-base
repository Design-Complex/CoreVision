/*
 *  CVDefines.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

/*!
    @header CVDefines
    @abstract   <#abstract#>
    @discussion <#description#>
*/


#ifndef _CVDefines_
#define _CVDefines_

#include <limits.h>

// Warnings

#pragma GCC diagnostic warning "-Wformat"

/*!
    @defined 
    @abstract   A macro to throw a warning when a compiler links against a deprecated class or method.
*/
#define CV_DEPRECATED __attribute__((deprecated))

#define CV_WARN(x) warning( #x )

#define CV_TODO(x) CV_WARN( "TODO: ", #x )

#define CV_ASSERT(x) \
	if( !( x ) ) { \
		std::cout << "CVError: Assertion " << #x << " failed!" << std::endl; \
		std::cout << "\ton line " << __LINE__ << std::endl; \
		std::cout << "\tin file " << __FILE__ << std::endl; \
	}

// Processor Alignment

#define CV_ALIGN_TLS	__declspec(thread)
#define CV_ALIGN_64		__declspec(align(64))
#define CV_ALIGN_32		__declspec(align(32))
#define CV_ALIGN_16		__declspec(align(16))
#define CV_ALIGN_00		__unaligned

// Class Definitions
#define CVPrivateCopyAndAssign( TypeName ) \
	private: \
	TypeName( const TypeName& ); \
	void operator=( const TypeName & ) \

#define CVPrivateConstructors( TypeName ) \
	private: \
	TypeName(); \
	TypeName( const TypeName & ); \
	TypeName & operator=( const TypeName & ) \


// Includes

#include <errno.h>

#include "CVTypes.h"

// Constants

enum {
	kCVMaxPathLen			= 1024,
	kCVMaxContainerLength	= ( ULLONG_MAX - 1 )
};


#endif // _CVDefines_
