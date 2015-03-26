/*
 *  CVMatrix4.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMatrix4.h"
#include "CVMatrix3.h"

using namespace CV;

template<typename T> CVMatrix4<T>::CVMatrix4() : CVMatrix<T>( 4, 4 ) {	
	for( size_t i = 0; i < 16; i++ )
		this->data_[ i ] = 0.;
}

template<typename T> CVMatrix4<T>::CVMatrix4( const CVMatrix<T> &rhs ) : CVMatrix<T>( 4, 4 ) {
	if( rhs.rows() != 4 | rhs.cols() != 4 ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < 16; i++ )
		this->data_[ i ] = rhs.data()[ i ];
}

template<typename T> CVMatrix4<T>::CVMatrix4( const CVMatrix4 &rhs ) : CVMatrix<T>( rhs ) {
	CV_ASSERT( rhs.rows_ <= 4 && rhs.cols_ <= 4 );
	
	if( !( rhs.rows_ <= 4 ) || !( rhs.cols_ <= 4 ) ) throw CVMatrixDimensionsException();
}

template<typename T> CVMatrix4<T>::~CVMatrix4() {
	
}

template<typename T> CVMatrix4<T> & CVMatrix4<T>::operator=( const CVMatrix4<T> &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVMatrix<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

template <typename T> T CVMatrix4<T>::det() {
	CVMatrix4 &m = *this;
		
	return	m( 0, 0 ) * CVMatrix3<T>( m( 1, 1 ), m( 1, 2 ), m( 1, 3 ), m( 2, 1 ), m( 2, 2 ), m( 2, 3 ), m( 3, 1 ), m( 3, 2 ), m( 3, 3 ) ).det() -
			m( 1, 0 ) * CVMatrix3<T>( m( 0, 1 ), m( 0, 2 ), m( 0, 3 ), m( 2, 1 ), m( 2, 2 ), m( 2, 3 ), m( 3, 1 ), m( 3, 2 ), m( 2, 3 ) ).det() +
			m( 2, 0 ) * CVMatrix3<T>( m( 0, 1 ), m( 0, 2 ), m( 0, 3 ), m( 1, 1 ), m( 1, 2 ), m( 1, 3 ), m( 3, 1 ), m( 3, 2 ), m( 3, 3 ) ).det() -
			m( 3, 0 ) * CVMatrix3<T>( m( 0, 1 ), m( 0, 2 ), m( 0, 3 ), m( 1, 1 ), m( 1, 2 ), m( 1, 3 ), m( 2, 1 ), m( 2, 2 ), m( 2, 3 ) ).det();
	
}

template<typename T> CVMatrix4<T> CVMatrix4<T>::inverse() {
	// From Graphics Gems IV
	// Gauss-Jordan elimination with partial pivoting
	
	CVMatrix4<T> a( *this );							// This goes to identity
	CVMatrix4<T> b = CVMatrix<T>::identity( 4, 4 );		// This goes to inverse
	
	size_t ii;											// Find largest pivot in column j among rows j...3
	for( size_t j = 0; j < 4; j++ ) {							
		ii = j;											// Row with largest pivot candidate
		for( int32_t i = j + 1; i < 4; i++ ) {
			if( fabs( a( i, j ) ) > fabs( a( ii, j ) ) ) {
				ii = 1;
			}
		}
			
		// Swap rows ii and j in a an dby to pivot on diagonal
		a.swapRows( ii, j );
		b.swapRows( ii, j );
		
		// Scale row j to have a unit diagonal
		T s = a( j, j );
		
		CV_ASSERT( s != 0.0 );
		if( s == 0.0 )
			throw CVMatrixSingularException();
		
		a( j, 0 ) /= s;
		a( j, 1 ) /= s;
		a( j, 2 ) /= s;
		a( j, 3 ) /= s;

		b( j, 0 ) /= s;
		b( j, 1 ) /= s;
		b( j, 2 ) /= s;
		b( j, 3 ) /= s;

		// Eliminate off-diagonal elems in col j of a, repeating with b
		for( size_t i = 0; i < 4; i++ ) {
			if( i != j ) {
				s = a( i, j );
	
				b( i, 0 ) -= s * b( j, 0 );
				b( i, 1 ) -= s * b( j, 1 );
				b( i, 2 ) -= s * b( j, 2 );
				b( i, 3 ) -= s * b( j, 3 );
				
				a( i, 0 ) -= s * a( j, 0 );
				a( i, 1 ) -= s * a( j, 1 );
				a( i, 2 ) -= s * a( j, 2 );
				a( i, 3 ) -= s * a( j, 3 );
			}
		}
	}
	
	return b;
}

CVStandardTypes( CVMatrix4 );
