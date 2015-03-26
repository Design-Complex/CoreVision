/*
 *  CVStringTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/17/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include <gtest/gtest.h>
#include "CoreVision.h"

using namespace CV;

namespace {
	
	class CVStringTest : public ::testing::Test {
	protected:
		CVString	str;
		
		virtual void SetUp() {
		
		}
		
		virtual void TearDown() {
			
		}
	};
	
	TEST_F( CVStringTest, RTTI ) {
		ASSERT_TRUE( str.isExactly( str.type() ) );
		
		ASSERT_TRUE( str.isExactly( CVString::type_ ) );
		
		ASSERT_TRUE( str.isExactlyTypeOf( CVString() ) );
		
		CVString * s = new CVString();
		ASSERT_TRUE( str.isExactlyTypeOf( s ) );
		delete s;
		
		ASSERT_TRUE( str.isDerived( CVObject().type() ) );
		
		ASSERT_TRUE( str.isDerivedTypeOf( CVObject() ) );
		
		CVObject * o = new CVObject();
		ASSERT_TRUE( str.isDerivedTypeOf( o ) );
		delete o;
		
		ASSERT_FALSE( CVObject().isDerived( str.type() ) );
	}
	
	TEST_F( CVStringTest, description ) {
		str = CVString( "Hello!" );
		std::cout << str.CVObject::description().utf8String() << std::endl;
		std::cout << str.description().utf8String() << std::endl;
	}
	
	TEST_F( CVStringTest, charPointer ) {
		str = CVString( "Hello!" );
		
		ASSERT_TRUE( str == str );
		
		ASSERT_FALSE( str != str );
		
		ASSERT_TRUE( str == CVString( str ) );
		
		ASSERT_TRUE( str == CVString( "Hello!" ) );
		
		ASSERT_TRUE( CVString() == CVString( "" ) );
		
	}
	
	TEST_F( CVStringTest, wideCharPointer ) {
		str = CVString( L"Hello!" );
		
		ASSERT_TRUE( str == str );
		
		ASSERT_FALSE( str != str );
		
		ASSERT_TRUE( str == CVString( str ) );
		
		ASSERT_TRUE( str == CVString( L"Hello!" ) );
		
		ASSERT_TRUE( CVString() == CVString( L"" ) );
		
		ASSERT_TRUE( str == CVString( "Hello!" ) );
	}
	
	TEST_F( CVStringTest, concat ) {
		const char * foo = "foo";
		
		str = CVString( foo );
		
		ASSERT_GT( str.length(), 0 );
		
		ASSERT_EQ( str.length(), strlen( foo ) );
		
		ASSERT_TRUE( ( str += CVString( foo ) ) == CVString( "foofoo" ) );
		
		const wchar_t * woo = L"woo";
		
		str = CVString( woo );
		
		ASSERT_GT( str.length(), 0 );
		
		ASSERT_EQ( str.length(), wcslen( woo ) );
		
		ASSERT_TRUE( ( str += CVString( woo ) ) == CVString( L"woowoo" ) );
		
	}
	
	TEST_F( CVStringTest, utf8String ) {
		str = CVString( "foo" );
		
		const char * utf = str.utf8String();
		
		ASSERT_TRUE( utf );
		
		ASSERT_GE( strlen( str.utf8String() ), 0 );
		
		ASSERT_TRUE( str == CVString( str.utf8String() ) );
	}
	
	TEST_F( CVStringTest, stringComparison ) {
		ASSERT_TRUE( CVString( "foo" ) > CVString( "bar" ) );
		
		ASSERT_TRUE( CVString( "bar" ) < CVString( "foo" ) );
		
		ASSERT_TRUE( CVString( "Foo" ) < CVString( "foo" ) );
	}
	
	TEST_F( CVStringTest, toString ) {
		ASSERT_TRUE( CVString::toString( true ) == CVString( "true" ) );
		ASSERT_TRUE( CVString::toString( false ) == CVString( "false" ) );
		
		ASSERT_TRUE( CVString::toString( static_cast<int8_t>( 127 ) ) == CVString( "127" ) );
		ASSERT_TRUE( CVString::toString( static_cast<int8_t>( -126 ) ) == CVString( "-126" ) );
		ASSERT_TRUE( CVString::toString( static_cast<uint8_t>( 255 ) ) == CVString( "255" ) );
		
		ASSERT_TRUE( CVString::toString( static_cast<int16_t>( 127 ) ) == CVString( "127" ) );
		ASSERT_TRUE( CVString::toString( static_cast<int16_t>( -126 ) ) == CVString( "-126" ) );
		ASSERT_TRUE( CVString::toString( static_cast<uint16_t>( 255 ) ) == CVString( "255" ) );
		
		ASSERT_TRUE( CVString::toString( static_cast<int32_t>( 127 ) ) == CVString( "127" ) );
		ASSERT_TRUE( CVString::toString( static_cast<int32_t>( -126 ) ) == CVString( "-126" ) );
		ASSERT_TRUE( CVString::toString( static_cast<uint32_t>( 255 ) ) == CVString( "255" ) );
		
		ASSERT_TRUE( CVString::toString( static_cast<int64_t>( 127 ) ) == CVString( "127" ) );
		ASSERT_TRUE( CVString::toString( static_cast<int64_t>( -126 ) ) == CVString( "-126" ) );
		ASSERT_TRUE( CVString::toString( static_cast<uint64_t>( 255 ) ) == CVString( "255" ) );
	}
};

int main( int argc, char **argv ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}