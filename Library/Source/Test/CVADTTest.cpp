/*
 *  CVADTTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/4/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CoreVision.h"
#include <gtest/gtest.h>

using namespace CV;

namespace  {
	// ADT Tests
	
	class DequeTest : public ::testing::Test {
	
	protected:
		
		CVDeque<uint64_t>	d;
		
		virtual void SetUp() {
			
		}
		
		virtual void TearDown() {
			d.empty();
		}
	};
	
	TEST_F( DequeTest, isEmptyInitially ) {		
		ASSERT_TRUE( d.isEmpty() );
		
		EXPECT_EQ( d.length(), 0 );
		
		ASSERT_THROW( d.popFront(), CVContainerUnderflowException );
	}
	
	TEST_F( DequeTest, pushCount ) {
		size_t length = 0;
		do {
			try {
				d.pushFront( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
			
		} while( length < 5 );
		
		EXPECT_EQ( length, d.length() );
		
		do {
			try {
				d.pushBack( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
		} while( length < 10 );
		
		EXPECT_EQ( length, d.length() );
		
		ASSERT_GT( d.length(), 0 );
		
		ASSERT_FALSE( d.isEmpty() );
		
		d.empty();
		ASSERT_TRUE( d.isEmpty() );
	}
	
	TEST_F( DequeTest, popCount ) {
		size_t length = 0;
		do {
			try {
				d.pushBack( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
		} while( length < 5 );
		
		ASSERT_TRUE( length == d.length() );
		
		uint64_t pop = d.length();
		
		while( d.length() ) {
			d.popBack();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( d.isEmpty() );
		
		length = 0;
		do {
			try {
				d.pushFront( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
		} while( length < 5 );
		
		ASSERT_TRUE( length == d.length() );
		
		pop = d.length();
		
		while( d.length() ) {
			d.popFront();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( d.isEmpty() );
		
		length = 0;
		do {
			try {
				d.pushFront( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
		} while( length < 5 );
		
		ASSERT_TRUE( length == d.length() );
		
		pop = d.length();
		
		while( d.length() ) {
			d.popBack();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( d.isEmpty() );
		
		length = 0;
		do {
			try {
				d.pushBack( length++ );
			} catch( CVException &e ) {
				std::cout << e.what();
			}
		} while( length < 5 );
		
		ASSERT_TRUE( length == d.length() );
		
		pop = d.length();
		
		while( d.length() ) {
			d.popFront();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( d.isEmpty() );
	}
	
	TEST_F( DequeTest, pushMax ) {
		d.setMaxLength( 5 );
		
		for( size_t i = 0; i < d.maxLength(); ++i )
			d.pushBack( i );
		
		ASSERT_THROW( d.pushBack( static_cast<uint64_t>( 0 ) );, CVContainerOverflowException );
	}
	
	class StackTest : public ::testing::Test {
	protected:
		CVStack<uint32_t>	s;
		
		virtual void SetUp() {
			
		}
		
		virtual void TearDown() {
			s.empty();
		}
	};
	
	TEST_F( StackTest, isEmptyInitially ) {
		ASSERT_TRUE( s.isEmpty() );
		
		EXPECT_EQ( s.depth(), 0 );
		
		ASSERT_THROW( s.pop(), CVContainerUnderflowException );
	}
	
	TEST_F( StackTest, pushCount ) {
		uint64_t i = 0;
		do {
			s.push( (uint32_t)i++ );
		} while( i < 5 );
		
		uint64_t count = i, deep = s.depth();
		EXPECT_EQ( count, deep );
		
		do {
			s.push( (uint32_t)i++ );
		} while( i < 10 );
		
		count = i, deep = s.depth();
		EXPECT_EQ( count, deep );
		
		ASSERT_TRUE( deep != 0 );
		
		ASSERT_FALSE( s.isEmpty() );
	}
	
	TEST_F( StackTest, popCount ) {
		uint64_t i = 0;
		do {
			s.push( (uint32_t)i++ );
		} while( i < 5 );
		
		uint64_t count = i, len = s.depth();
		ASSERT_TRUE( count == len );
		
		uint64_t pop = s.depth();
		
		while( s.depth() ) {
			s.pop();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( s.isEmpty() );
	}
	
	class QueueTest : public ::testing::Test {
	protected:
		CVQueue<uint32_t>	q;
		
		virtual void SetUp() {
			
		}
		
		virtual void TearDown() {
			q.empty();
		}
	};
	
	TEST_F( QueueTest, isEmptyInitially ) {
		EXPECT_EQ( 0, q.length() );
		
		ASSERT_TRUE( q.isEmpty() );
		
		ASSERT_THROW( q.dequeue(), CVContainerUnderflowException );
	}
	
	TEST_F( QueueTest, enqueue ) {
		uint64_t i = 0;
		do {
			q.enqueue( (uint32_t)i++ );
		} while( i < 5 );
		
		uint64_t count = i, len = q.length();
		EXPECT_EQ( count, len );
		
		ASSERT_TRUE( len != 0 );
		ASSERT_FALSE( q.isEmpty() );
	}
	
	TEST_F( QueueTest, dequeue ) {
		uint64_t i = 0;
		do {
			q.enqueue( (uint32_t)i++ );
		} while( i < 5 );
		
		uint64_t count = i, len = q.length();
		ASSERT_TRUE( count == len );
		
		uint64_t pop = q.length();
		uint32_t n = 0;
		
		while( q.length() ) {
			n = q.dequeue();
			--pop;
		}
		
		ASSERT_TRUE( 0 == pop );
		ASSERT_TRUE( q.isEmpty() );
	}
}

int main(int argc, char **argv) {
	::testing::GTEST_FLAG(print_time) = true;
	
	::testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}
