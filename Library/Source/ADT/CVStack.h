/*
 *  CVStack.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVStack_
#define _CVStack_

#include "CVDefines.h"

#include "CVObject.h"
#include "CVDeque.h"

namespace CV {

	#pragma GCC visibility push(default)
	
	template<class T>
	class CVStack : public CVObject {
	private:
		CVPrivateCopyAndAssign( CVStack<T> );
		
		CVDeque<T>	deque_;
		
	public:
		CVRTTIDeclare()
		
		CVStack( size_t deep = kCVMaxContainerLength ) : deque_( deep ) {}
		virtual ~CVStack() {}
		
		bool isEmpty() const {
			return deque_.isEmpty();
		}
		
		void empty() {
			try {
				deque_.empty();
			} CVThrowAllExceptions()
		}
		
		size_t depth() const {
			return deque_.length();
		}
		
		size_t maxDepth() const {
			return deque_.maxLength();
		}
		
		void setMaxDepth( size_t deep ) {
			try {
				deque_.setMaxDepth( deep );
			} CVThrowAllExceptions()
			
		}
		
		virtual void push( const T & val ) {
			try {
				push( new CVListNode<T>( val ) );
			} CVThrowAllExceptions()
		}
		
		void push( CVListNode<T> *node ) {
			try {
				deque_.pushFront( node );
			} CVThrowAllExceptions()
		}
		
		virtual T pop() {
			try {
				return deque_.popFront();
			} CVThrowAllExceptions()
		}
		
		virtual T & top() const {
			try {
				return deque_.peekFront();
			} CVThrowAllExceptions()
		}
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVStack<T>, CVObject )
	
	#pragma GCC visibility pop
	
}

#endif // _CVStack_
