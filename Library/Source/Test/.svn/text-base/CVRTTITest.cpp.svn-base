/*
 *  CVRTTITEst.cpp
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
	
	class CVRTTITest : public ::testing::Test {
	protected:
		CVObject	obj;
		CVString	str;
		
		virtual void SetUp() {

		}
		
		virtual void TearDown() {
			
		}
	};
	
	TEST_F( CVRTTITest, isTypeOf ) {
		std::cout << obj.description().utf8String() << std::endl;
		
		ASSERT_TRUE( CVObject::type_.isExactly( obj.type() ) );
		
		ASSERT_TRUE( obj.type().isExactly( CVObject::type_ ) );
		
		ASSERT_TRUE( obj.type().isExactly( obj.type() ) );
		
		ASSERT_TRUE( obj.isExactlyTypeOf( obj ) );
		
		ASSERT_TRUE( obj.isExactlyTypeOf( &obj ) );
		
		std::cout << str.CVObject::description().utf8String() << std::endl;
		ASSERT_FALSE( CVString::type_.isExactly( obj.type() ) );
		
		ASSERT_FALSE( str.type().isExactly( CVObject::type_ ) );
		
		ASSERT_FALSE( str.type().isExactly( obj.type() ) );
		
		ASSERT_FALSE( str.isExactlyTypeOf( obj ) );
		
		ASSERT_FALSE( str.isExactlyTypeOf( &obj ) );
	}
	
	TEST_F( CVRTTITest, isDerivedTypeOf ) {
		ASSERT_TRUE( CVString::type_.isDerived( obj.type() ) );
		
		ASSERT_TRUE( str.type().isDerived( CVObject::type_ ) );
		
		ASSERT_TRUE( str.type().isDerived( obj.type() ) );
		
		ASSERT_TRUE( str.type().isDerived( CVString::type_ ) );
		
		ASSERT_TRUE( str.isDerivedTypeOf( obj ) );
		
		ASSERT_TRUE( str.isDerivedTypeOf( &obj ) );
		
		ASSERT_FALSE( CVObject::type_.isDerived( str.type() ) );
		
		ASSERT_FALSE( obj.type().isDerived( str.type() ) );
		
		ASSERT_FALSE( obj.isDerivedTypeOf( str ) );
		
		ASSERT_FALSE( obj.isDerivedTypeOf( &str ) );
	}
};

int main( int argc, char **argv ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}