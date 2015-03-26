/*
 *  CVNode.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVNode_
#define _CVNode_

#include "CVBase.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	template<typename T>
	class CVNode : public CVObject {
	private:
		T	data_;
		
	public:
		CVRTTIDeclare()
		
		CVNode( const T &rhs = 0 ) : CVObject::CVObject(), data_( rhs ) {}
		CVNode( const CVNode<T> &rhs ) : CVObject::CVObject( rhs ), data_( rhs.data_ ) {}
		virtual ~CVNode() {}
		
		CVNode<T> & operator=( const CVNode<T> &rhs ) {
			if( this != &rhs ) {
				this->CVObject::operator=( rhs );
				data_ = rhs.data_;
			}
			
			return *this;
		}
		
		virtual bool operator==( const CVNode<T> &rhs ) const {
			if( this == &rhs || data_ == rhs.data_ )
				return true;
			
			return false;
		}
		
		T & value() {
			return data_;
		}
		
		void setValue( T rhs ) {
			data_ = rhs;
		}
		
		virtual void operator==( const T & rhs ) const {
			data_ == rhs;
		}
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVNode<T>, CVObject )
	
	#pragma GCC visibility pop
	
}	

#endif // _CVNode_
