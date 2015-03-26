///*
// *  CVDeque.cpp
// *  CoreVision
// *
// *  Created by Rob Dotson on 4/3/08.
// *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
// *
// */
//
#include "CVDeque.h"
#include "CVListNode.h"
//#include "CVException.h"

using namespace CV;

//CVRTTIDefine( CVDeque, CVObject );

//
//template<typename T>
//CVDeque<T>::CVDeque( uint64_t len ) : first_( 0 ), last_( 0 ), push_( 0 ), pop_( 0 ), maxLength_( len ) {
//	
//}
//
//template<typename T>
//CVDeque<T>::~CVDeque() {
//	this->empty();
//}
//
//template<typename T>
//bool CVDeque<T>::isEmpty() {
//	if( first_ && last_ ) return false;
//	
//	return true;
//}
//
//template<typename T>
//void CVDeque<T>::empty() {
//	while( !isEmpty() )
//		delete this->popFront();
//}
//
//template<typename T>
//CVListNode<T> * CVDeque<T>::first() {
//	return first_;
//}
//
//template<typename T>
//void CVDeque<T>::setFirst( CVListNode<T> *node ) {
//	first_ = node;
//}
//
//template<typename T>
//CVListNode<T> * CVDeque<T>::last() {
//	return last_;
//}
//
//template<typename T>
//uint64_t CVDeque<T>::length() {
//	return push_ - pop_;
//}
//
//template<typename T>
//uint64_t CVDeque<T>::maxLength() {
//	return maxLength_;
//}
//
//template<typename T>
//void CVDeque<T>::setMaxLength( uint64_t len ) {
//	if( len > kCVMaxContainerLength )
//		throw CVContainerOverflowException();
//	
//	maxLength_ = len;
//}
//
//template<typename T>
//void CVDeque<T>::setLast( CVListNode<T> *node ) {
//	last_ = node;
//}
//
//template<typename T>
//void CVDeque<T>::pushFront( const T & val ) {
//	try {
//		pushFront( new CVListNode<T>( val ) );
//	} catch(...) { throw; }
//}
//
//template<typename T>
//void CVDeque<T>::pushFront( CVListNode<T> *node ) {
//	if( node == NULL )
//		throw CVContainerNullNodeException();
//	
//	if( ( push_ - pop_ ) >= maxLength_ )
//		throw CVContainerOverflowException();
//	
//	push_++;
//	if( isEmpty() ) first_ = last_ =  node;
//	else {
//		first_->setPrev( node );
//		node->setNext( first_ );
//		first_ = node;
//	}
//}
//
//template<typename T>
//CVListNode<T> * CVDeque<T>::popFront() {
//	if( !isEmpty() ) {
//		pop_++;
//		
//		CVListNode<T> *tmp = first_;
//		first_ = first_->next();
//		if( first_ )
//			first_->setPrev( NULL );
//		
//		return tmp;
//	}
//	
//	return NULL;
//}
//
//template<typename T>
//void CVDeque<T>::pushBack( const T & val ) {
//	try {
//		pushBack( new CVListNode<T>( val ) );
//	} catch(...) { throw; }
//}
//
//template<typename T>
//void CVDeque<T>::pushBack( CVListNode<T> *node ) {
//	if( node == NULL )
//		throw CVContainerNullNodeException();
//	
//	if( ( push_ - pop_ ) >= maxLength_ )
//		throw CVContainerOverflowException();
//	
//	push_++;
//	if( isEmpty() ) first_ = last_ =  node;
//	else {
//		node->setPrev( last_ );
//		last_->setNext( node );
//		last_ = node;
//	}
//}
//
//template<typename T>
//CVListNode<T> * CVDeque<T>::popBack() {
//	if( !isEmpty() ) {
//		pop_++;
//		
//		CVListNode<T> *tmp = last_;
//		last_ = last_->prev();
//		if( last_ )
//			last_->setNext( NULL );
//		
//		return tmp;
//	}
//	
//	return NULL;
//}
//
//template<typename T>
//void CVDeque<T>::alternatingPush( const T & val ) {
//	try {
//		alternatingPush( new CVListNode<T>( val ) );
//	} catch(...) { throw; }
//}
//
//template<typename T>
//void CVDeque<T>::alternatingPush( CVListNode<T> *node ) {
//	try {
//		if( push_ % 2 )
//			pushFront( node );
//		else
//			pushBack( node );
//	} catch(...) { throw; }
//}
//
//template<typename T>
//CVListNode<T> * CVDeque<T>::alternatingPop() {
//	try {
//		if( pop_ % 2 )
//			return popFront();
//		else
//			return popBack();
//	} catch(...) { throw; }
//}
//
//CVStandardTemplateTypes( CVDeque )