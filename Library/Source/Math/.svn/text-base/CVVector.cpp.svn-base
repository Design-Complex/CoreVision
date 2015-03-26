/*
 *  CVVector.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVVector.h"

using namespace CV;

// Special Constructors
template <typename T> CVVector<T> & gaussian( const int32_t step ) {
	CVVector<T> vec = CVVector<T>( step );
	int32_t mid = step / 2 + 1;
	
	double x, val, sigma = 1. / sqrt( CVMath::PI2 );
	
	for( int32_t i = 0; i < mid; i++ ) {
		x = -5. + ( i * ( 10. / step ) );
		val = sigma * exp( -( ( x * x ) / ( step / 2 ) ) );
		vec.data_[ i ] = val;
		vec.data_[ ( step - 1 ) - i ] = val;
	}
	
	return *vec;
}

// Constructors & Destructors
template <typename T> CVVector<T>::CVVector( const size_t len, const T &a ) : CVMatrix<T>::CVMatrix( len, 1, a ) {}

template <typename T> CVVector<T>::CVVector( const CVVector &rhs ) : CVMatrix<T>::CVMatrix( rhs ) {}

template <typename T> CVVector<T>::CVVector( const CVMatrix<T> &rhs ) : CVMatrix<T>::CVMatrix( rhs ) {
	if( ( this->rows_ > 1 ) && ( this->cols_ > 1 ) )
		throw CVMatrixDimensionsException();
}

template <typename T> CVVector<T>::~CVVector() {}

// Operators
template <typename T> CVVector<T> & CVVector<T>::operator= ( const CVVector<T> &rhs ) {
	if( this != &rhs ) {
		try {
			// Call the super class's assignment operator
			CVMatrix<T>::operator=( rhs );	
		} CVThrowAllExceptions()
	}
	
	return *this;
}

// Accessors
template <typename T> bool CVVector<T>::isRow() const { return ( this->cols_ == 1 ) ? false : true; }

template <typename T> bool CVVector<T>::isColumn() const { return ( this->rows_ == 1 ) ? true : false; }

template <typename T> size_t CVVector<T>::length() const { return ( this->rows_ > this->cols_ ) ? this->rows_ : this->cols_; }

template <typename T> T CVVector<T>::magnitude() {
	T val = 0;
	
	for( size_t i = 0; i < ( this->rows_ * this->cols_ ); i++ )
		val += this->data_[ i ] * this->data_[ i ];
	
	return ( T )sqrt( val );
}

// Transformations
template <typename T> void CVVector<T>::transpose() { int32_t tmp = this->rows_; this->rows_ = this->cols_; this->cols_ = tmp; }

// Vector / Vector Ops
template <typename T> T CVVector<T>::inner( const CVVector &rhs ) {
	CV_ASSERT( length() == rhs.length() );
	
	if( length() != rhs.length() ) throw CVMatrixDimensionsException();
	
	T sum = 0;
	for( int32_t i = 0; i < length(); i++ )
		sum += this->data_[ i ] * rhs[ i ];
	
	return sum;
}

template <typename T> CVMatrix<T> CVVector<T>::outer( const CVVector &rhs ) {
	CVMatrix<T> mtx( length(), rhs.length() );
	
	for( int32_t i = 0; i < length(); i++ ) {
		for( int32_t j = 0; j < rhs.length(); j++ ) {
			mtx( i, j ) = this->data_[ i ] * rhs[ j ];
		}
	}
	
	return mtx;
}

template <typename T> CVVector<T> CVVector<T>::cross( const CVVector &rhs ) {
	return CVVector<T>( length() ); // FIX ME
}

CVStandardTypes( CVVector );
