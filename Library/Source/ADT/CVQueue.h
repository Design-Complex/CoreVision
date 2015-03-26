/*
 *  CVQueue.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 5/28/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVQueue_
#define _CVQueue_

#include "CVDefines.h"
#include "CVDeque.h"

namespace CV {

	#pragma GCC visibility push(default)
	
	template<typename T>
	class CVQueue : public CVObject {
	private:
		CVPrivateCopyAndAssign( CVQueue<T> );
		
		CVDeque<T> deque_;
		
	public:
		CVRTTIDeclare()
		
		CVQueue( size_t len = kCVMaxContainerLength ) : deque_( len ) {}
		virtual ~CVQueue() {}
		
		bool isEmpty() const {
			return deque_.isEmpty();
		}
		
		void empty() {
			deque_.empty();
		}
		
		size_t length() const {
			return deque_.length();
		}
		
		size_t maxLength() const {
			return deque_.maxLength();
		}
		
		void setMaxLength( size_t len ) {
			try {
				deque_.setMaxLength( len );
			} CVThrowAllExceptions()
		}
		
		virtual void enqueue( const T & val ) {
			try {
				enqueue( new CVListNode<T>( val ) );
			} CVThrowAllExceptions()
		}
		
		virtual void enqueue( CVListNode<T> * node ) {
			try {
				deque_.pushBack( node );
			} CVThrowAllExceptions()
		}
		
		virtual T dequeue() {
			try {
				return deque_.popFront();
			} CVThrowAllExceptions()
		}
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVQueue<T>, CVObject )
	
	#pragma GCC visibility pop
	
}

#endif // _CVQueue_
