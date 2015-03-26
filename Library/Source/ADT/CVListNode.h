/*
 *  CVListNode.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVListNode_
#define _CVListNode_

#include "CVNode.h"

namespace CV {
	
	#pragma GCC visibility push(default)

	template<typename T>
	class CVListNode : public CVNode<T> {
		CVPrivateCopyAndAssign( CVListNode<T> );
		
		CVListNode<T> *prev_;
		CVListNode<T> *next_;
		
	public:
		CVRTTIDeclare()
		
		CVListNode( const T &rhs = 0, CVListNode<T> *prev = 0, CVListNode<T> *next = 0 ) 
		: CVNode<T>::CVNode( rhs ), prev_( prev ), next_( next ) {}
		virtual ~CVListNode() {
			prev_ = next_ = 0;
		}
		
		CVListNode<T> * next() const {
			return next_;
		}
		
		void setNext( CVListNode<T> *node ) {
			next_ = node;
		}
		
		CVListNode<T> * prev() const {
			return prev_;
		}
		
		void setPrev( CVListNode<T> *node ) {
			prev_ = node;
		}
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVListNode<T>, CVNode<T> )
	
	#pragma GCC visibility pop
	
}

#endif // _CVListNode_
