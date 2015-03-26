/*
 *  CVVector2.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVVector2.h"

using namespace CV;

template<typename T> CVVector2<T>::CVVector2( T a, T b ) : CVVector<T>( 2 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ) {
	this->data_[ 0 ] = a; this->data_[ 1 ] = b;
}

template<typename T> CVVector2<T>::CVVector2( const CVMatrix<T> &rhs ) : CVVector<T>( 2 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ) {
	CV_ASSERT( kMatrixToVectorReshapeBoundsMismatch );
	if( !kMatrixToVectorReshapeBoundsMismatch ) throw CVMatrixDimensionsException();
	
	for( int32_t i = 0; i < rhs.rows() * rhs.cols(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector2<T>::CVVector2( const CVVector<T> &rhs ) : CVVector<T>( 2 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ) {
	if( rhs.length() != 2 ) throw CVMatrixDimensionsException();
	
	for( int32_t i = 0; i < rhs.length(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector2<T>::CVVector2( const CVVector2 &rhs ) : CVVector<T>( rhs ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ) {
	
}

template<typename T> CVVector2<T>::~CVVector2() {
	
}

template<typename T> CVVector2<T> & CVVector2<T>::operator=( const CVVector2 &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVVector<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

CVStandardTypes( CVVector2 );
