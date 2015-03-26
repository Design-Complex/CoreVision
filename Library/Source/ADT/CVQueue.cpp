///*
// *  CVQueue.cpp
// *  CoreVision
// *
// *  Created by Rob Dotson on 5/28/09.
// *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
// *
// */
//
#include "CVQueue.h"

using namespace CV;

//CVRTTIDefine( CVQueue, CVObject );

//
//template<typename T>
//CVQueue<T>::CVQueue( uint64_t len ) : deque_( len ) {
//	
//}
//
//template<typename T>
//CVQueue<T>::~CVQueue() {
//	
//}
//
//template<typename T>
//bool CVQueue<T>::isEmpty() {
//	try {
//		return deque_.isEmpty();
//	} catch( ... ) { throw; }
//}
//
//template<typename T>
//void CVQueue<T>::empty() {
//	try {
//		deque_.empty();
//	} catch( ... ) { throw; }
//}
//
//template<typename T>
//uint64_t CVQueue<T>::length() {
//	return deque_.length();
//}
//
//template<typename T>
//uint64_t CVQueue<T>::maxLength() {
//	return deque_.maxLength();
//}
//
//template<typename T>
//void CVQueue<T>::setMaxLength( uint64_t len ) {
//	try {
//		deque_.setMaxLength( len );
//	} catch( ... ) { throw; }
//}
//
//template<typename T>
//void CVQueue<T>::enqueue( const T & val ) 
//
//template<typename T>
//void CVQueue<T>::enqueue( CVListNode<T> *node ) 
//
//template<typename T>
//CVListNode<T> * CVQueue<T>::dequeue() 
//
//CVStandardTemplateTypes( CVQueue )
