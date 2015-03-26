/*
 *  CVMatrix3.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMatrix3.h"
#include "CVMatrix2.h"

using namespace CV;

template<typename T> CVMatrix3<T>::CVMatrix3( T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3 ) : CVMatrix<T>( 3, 3 ) {
	CVMatrix3 &m = *this;
	m( 0, 0 ) = a1; m( 0, 1 ) = a2; m( 0, 2 ) = a3;
	m( 1, 0 ) = b1; m( 1, 1 ) = b2; m( 1, 2 ) = b3;
	m( 2, 0 ) = c1; m( 2, 1 ) = c2; m( 2, 2 ) = c3;	
}

template<typename T> CVMatrix3<T>::CVMatrix3( const CVMatrix<T> &rhs ) : CVMatrix<T>( 3, 3 ) {
	bool ok = ( rhs.rows() <= 3 && rhs.cols() <= 3 );
	
	CV_ASSERT( ok );
	if( !ok ) throw CVMatrixDimensionsException();
	
	CVMatrix3 &m = *this;
	m( 0, 0 ) = rhs( 0, 0 );
	m( 0, 1 ) = rhs( 0, 1 );
	m( 0, 2 ) = rhs( 0, 2 );
	m( 1, 0 ) = rhs( 1, 0 );
	m( 1, 1 ) = rhs( 1, 1 );
	m( 1, 2 ) = rhs( 1, 2 );
	m( 2, 0 ) = rhs( 2, 0 );
	m( 2, 1 ) = rhs( 2, 1 );
	m( 2, 2 ) = rhs( 2, 2 );
}

template<typename T> CVMatrix3<T>::CVMatrix3( const CVMatrix3<T> &rhs ) : CVMatrix<T>( rhs ) {

}

template<typename T> CVMatrix3<T>::~CVMatrix3() {
	
}

template<typename T> CVMatrix3<T> & CVMatrix3<T>::operator=( const CVMatrix3<T> &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVMatrix<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

template <typename T> T CVMatrix3<T>::det() {
	CVMatrix3 &m = *this;
	
	return	m( 0, 0 ) * CVMatrix2<T>( m( 1, 1 ), m( 1, 2 ), m( 2, 1 ), m( 2, 2 ) ).det() -
			m( 1, 0 ) * CVMatrix2<T>( m( 0, 1 ), m( 0, 2 ), m( 2, 1 ), m( 2, 2 ) ).det() +
			m( 2, 0 ) * CVMatrix2<T>( m( 0, 1 ), m( 0, 2 ), m( 1, 1 ), m( 1, 2 ) ).det();
			
}

CVStandardTypes( CVMatrix3 );
