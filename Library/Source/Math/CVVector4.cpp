/*
 *  CVVector4.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVVector4.h"
#include "CVMatrix4.h"

using namespace CV;

template<typename T> CVVector4<T>::CVVector4( T a, T b, T c, T d ) : CVVector<T>( 4 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ), w( ( *this )[ 3 ] ) {
	this->data_[ 0 ] = a;
	this->data_[ 1 ] = b;
	this->data_[ 2 ] = c;
	this->data_[ 3 ] = d;
}

template<typename T> CVVector4<T>::CVVector4( const CVMatrix<T> &rhs ) : CVVector<T>( 4 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ), w( ( *this )[ 3 ] ) {
	CV_ASSERT( kMatrixToVectorReshapeBoundsMismatch );
	if( !kMatrixToVectorReshapeBoundsMismatch ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < rhs.rows() * rhs.cols(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector4<T>::CVVector4( const CVVector<T> &rhs ) : CVVector<T>( 4 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ), w( ( *this )[ 3 ] ) {
	if( rhs.length() > 4 ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < rhs.length(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector4<T>::CVVector4( const CVVector4<T> &rhs ) : CVVector<T>( rhs ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ), w( ( *this )[ 3 ] ) {
	
}

template<typename T> CVVector4<T>::~CVVector4() {
	
}

template<typename T> CVVector4<T> & CVVector4<T>::operator=( const CVVector4<T> &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVVector<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}
// Vector / Vector Ops
template <typename T> T CVVector4<T>::inner( const CVVector4<T> &rhs ) {
	CVVector4<T> &vec = *this;	
	T sum = 0;
	
	sum += vec[ 0 ] * rhs[ 0 ];
	sum += vec[ 1 ] * rhs[ 1 ];
	sum += vec[ 2 ] * rhs[ 2 ];
	sum += vec[ 3 ] * rhs[ 3 ];
	
	return sum;
}

template <typename T> CVMatrix4<T> CVVector4<T>::outer( const CVVector4<T> &rhs ) {
	CVMatrix4<T> mtx;
	CVVector4<T> &vec = *this;	
	
	for( size_t i = 0; i < 4; i++ ) {
		mtx( i, 0 ) = vec[ i ] * rhs[ 0 ];
		mtx( i, 1 ) = vec[ i ] * rhs[ 1 ];
		mtx( i, 2 ) = vec[ i ] * rhs[ 2 ];
		mtx( i, 3 ) = vec[ i ] * rhs[ 3 ];
	}
	
	return mtx;
}

template <typename T> CVVector4<T> CVVector4<T>::cross( const CVVector4<T> &rhs ) {
	CVVector4<T> &vec = *this;	
	
	return CVVector4<T>( 
						( vec[ 1 ] * rhs[ 2 ] ) - ( vec[ 2 ] * rhs[ 1 ] ), 
						( vec[ 2 ] * rhs[ 0 ] ) - ( vec[ 0 ] * rhs[ 2 ] ),
						( vec[ 0 ] * rhs[ 1 ] ) - ( vec[ 1 ] * rhs[ 0 ] ), 1 );
}

CVStandardTypes( CVVector4 );