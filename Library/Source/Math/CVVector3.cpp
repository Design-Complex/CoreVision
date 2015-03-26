/*
 *  CVVector3.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVVector3.h"

using namespace CV;

template<typename T> CVVector3<T>::CVVector3( T a, T b, T c ) : 
	CVVector<T>( 3 ),
	x( ( *this )[ 0 ] ), 
	y( ( *this )[ 1 ] ),
	z( ( *this )[ 2 ] ) {
		
	this->data_[ 0 ] = x;
	this->data_[ 1 ] = y;
	this->data_[ 2 ] = z;
}

template<typename T> CVVector3<T>::CVVector3( const CVMatrix<T> &rhs ) : CVVector<T>( 3 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ) {
	CV_ASSERT( kMatrixToVectorReshapeBoundsMismatch );
	if( !kMatrixToVectorReshapeBoundsMismatch ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < rhs.rows() * rhs.cols(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector3<T>::CVVector3( const CVVector<T> &rhs ) : CVVector<T>( 3 ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ) {	
	if( rhs.length() > 3 ) throw CVMatrixDimensionsException();
	
	for( int32_t i = 0; i < rhs.length(); i++ )
		this->data_[ i ] = rhs[ i ];
}

template<typename T> CVVector3<T>::CVVector3( const CVVector3<T> &rhs ) : CVVector<T>( rhs ), x( ( *this )[ 0 ] ), y( ( *this )[ 1 ] ), z( ( *this )[ 2 ] ) {	
	
}

template<typename T> CVVector3<T>::~CVVector3() {
	
}

template<typename T> CVVector3<T> & CVVector3<T>::operator=( const CVVector3<T> &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVVector<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

CVStandardTypes( CVVector3 );
