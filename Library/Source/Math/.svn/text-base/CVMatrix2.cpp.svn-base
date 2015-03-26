/*
 *  CVMatrix2.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMatrix2.h"

using namespace CV;

template<typename T> CVMatrix2<T>::CVMatrix2( T a, T b, T c, T d ) : CVMatrix<T>( 2, 2 ) {
	CVMatrix2 &m = *this;
	
	m( 0, 0 ) = a;
	m( 0, 1 ) = b;
	m( 1, 0 ) = c;
	m( 1, 1 ) = d;
}

template<typename T> CVMatrix2<T>::CVMatrix2( const CVMatrix<T> &rhs ) : CVMatrix<T>( 2, 2 ) {
	bool ok = ( rhs.rows() <= 2 && rhs.cols() <= 2 );
	
	if( !ok ) throw CVMatrixDimensionsException();
	
	CVMatrix2 &m = *this;
	m( 0, 0 ) = rhs( 0, 0 );
	m( 0, 1 ) = rhs( 0, 1 );
	m( 1, 0 ) = rhs( 1, 0 );
	m( 1, 1 ) = rhs( 1, 1 );
}

template<typename T> CVMatrix2<T>::CVMatrix2( const CVMatrix2<T> &rhs ) : CVMatrix<T>( rhs ) {
	
}

template<typename T> CVMatrix2<T>::~CVMatrix2() {
	
}

template<typename T> CVMatrix2<T> & CVMatrix2<T>::operator=( const CVMatrix2 &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVMatrix<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

template <typename T> T CVMatrix2<T>::det() {
	return this->data_[ 0 ] * this->data_[ 3 ] - this->data_[ 1 ] * this->data_[ 2 ];
}

CVStandardTypes( CVMatrix2 )
