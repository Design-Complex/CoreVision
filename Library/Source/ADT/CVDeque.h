/*
 *  CVDeque.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDeque_
#define _CVDeque_

#include "CVObject.h"
#include "CVListNode.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	template<typename T>
	class CVDeque : public CVObject {
	private:
		CVPrivateCopyAndAssign( CVDeque<T> );
		size_t			maxLength_;
		
		size_t			push_, pop_;
		
		CVListNode<T>	*head_, *tail_;
		
	public:
		CVRTTIDeclare()
		
		CVDeque( size_t len = kCVMaxContainerLength ) : push_( 0 ), pop_( 0 ), head_( 0 ), tail_( 0 ), maxLength_( len ) {}
		
		virtual ~CVDeque() {
			this->empty();
			
			push_ = pop_ = 0;
			head_ = tail_ = NULL;
		}
		
		bool isEmpty() const {
			return push_ == pop_;
		}
		
		void empty() {
			while( !isEmpty() )
				this->popFront();
		}
		
		size_t length() const {
			return push_ - pop_;
		}
		
		size_t maxLength() const {
			return maxLength_;
		}
		
		void setMaxLength( uint64_t len ) {
			if( len > kCVMaxContainerLength )
				throw CVContainerOverflowException();
			
			maxLength_ = len;
		}
		
		void pushFront( const T & val ) {
			try {
				pushFront( new CVListNode<T>( val ) );
			} CVThrowAllExceptions()
		}
		
		void pushFront( CVListNode<T> *node ) {
			if( node == NULL )
				throw CVContainerNullNodeException();
			
			if( length() >= maxLength_ )
				throw CVContainerOverflowException();
			
			if( isEmpty() ) {
				head_ = tail_ = node;
			} else {
				head_->setPrev( node );
				node->setNext( head_ );
				head_ = node;
			}
			
			push_++;
		}
		
		T popFront() {
			if( isEmpty() )
				throw CVContainerUnderflowException();
			
			pop_++;
			
			CVListNode<T> * tmp = head_;
			head_ = head_->next();
			if( head_ != NULL ) 
				head_->setPrev( NULL );
			
			T val = tmp->value(); // save the value
			
			delete tmp; // cleanup
			
			return val;
		}
		
		T & peekFront() const {
			if( isEmpty() )
				throw CVContainerUnderflowException();
			
			return head_->value();
		}
		
		void pushBack( const T & val ) {
			try {
				pushBack( new CVListNode<T>( val ) );
			} CVThrowAllExceptions()
		}
		
		void pushBack( CVListNode<T> *node ) {
			if( node == NULL )
				throw CVContainerNullNodeException();
			
			if( length() >= maxLength_ )
				throw CVContainerOverflowException();
			
			if( isEmpty() ) {
				tail_ = head_ = node;
			} else {
				node->setPrev( tail_ );
				tail_->setNext( node );
				tail_ = node;
			}
			
			push_++;
		}
		
		T popBack() {
			if( isEmpty() )
				throw CVContainerUnderflowException();
			
			pop_++;
			
			CVListNode<T> * tmp = tail_;
			tail_ = tail_->prev();
			if( tail_ != NULL )
				tail_->setNext( NULL );
			
			T val = tmp->value(); // save the value
			
			delete tmp; // cleanup
			
			return val;
		}
		
		T & peekBack() const {
			if( isEmpty() )
				throw CVContainerUnderflowException();
			
			return tail_->value();
		}
		
		void alternatingPush( const T & val ) {
			try {
				alternatingPush( new CVListNode<T>( val ) );
			} catch(...) { throw; }
		}
		
		void alternatingPush( CVListNode<T> *node ) {
			try {
				( push_ % 2 ) ? pushFront( node ) : pushBack( node );
			} catch(...) { throw; }
		}
		
		CVListNode<T> * alternatingPop() {
			try {
				return ( pop_ % 2 ) ? popFront() : popBack();
			} catch(...) { throw; }
		}
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVDeque<T>, CVObject )
	
	#pragma GCC visibility pop
}

#endif // _CVDeque_
