/*
 *  CVMatrix.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMatrix.h"
#include "CVVector.h"
#include "CVBase.h"

using namespace CV;

// Special Constructors
template <typename T> CVMatrix<T> CVMatrix<T>::identity( const size_t c, const size_t r ) {
	try {
		CVMatrix<T> mtx( c, r );
		
		for( size_t i = 0; i < ( ( c < r ) ? c : r ); ++i ) mtx( i, i ) =  1;
		
		return mtx;
	} CVThrowAllExceptions()
}

template<typename T> CVMatrix<T> CVMatrix<T>::random( const size_t c, const size_t r, const T lo, const T hi ) {

	int32_t seed = ( int32_t )kCFAbsoluteTimeIntervalSince1904;
	
	try {
		CVMatrix<T> mtx( c, r );
		
		for( size_t i = 0; i < ( r * c ); ++i )
			mtx.data_[ i ] = CVMath::rand<T>( &seed, lo, hi );
		
		return mtx;
	} CVThrowAllExceptions()
}

// Constructors & Destructor
template <typename T> CVMatrix<T>::CVMatrix( const size_t c, const size_t r, const T & a ) : CVObject::CVObject(), rows_( r ), cols_( c ), data_( new T[ r * c ] ) {
	CV_ASSERT( kMatrixDimensionsGreaterThanZero );
	if( !kMatrixDimensionsGreaterThanZero ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < ( r * c ); ++i ) data_[ i ] = a;
}

template <typename T> CVMatrix<T>::CVMatrix( const CVMatrix &rhs ) : CVObject::CVObject( rhs ), rows_( rhs.rows_ ), cols_( rhs.cols_ ), data_( new T[ rhs.rows_ * rhs.cols_ ] ) {	
	T * src = rhs.data_;
	T * dst = data_;
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i ) *dst++ = *src++;
}

template <typename T> CVMatrix<T>::~CVMatrix() { delete[] data_; }

// Standard Operators
template <typename T> CVMatrix<T> & CVMatrix<T>::operator= ( const CVMatrix &rhs ) {
	if( this != &rhs ) {
		
		try {			
			// Set the instance variables
			rows_ = rhs.rows_;
			cols_ = rhs.cols_;
			
			// Free the matrix buffer
			delete data_;
			
			// Attempt to allocate new memory
			data_ = new T[ rhs.rows_ * rhs.cols_ ];
			
			// Copy the data like the copy constructor
			T * src = rhs.data_;
			T * dst = this->data_;
			for( size_t i = 0; i < ( rows_ * cols_ ); ++i ) *dst++ = *src++;
			
		} catch( ... ) {
			delete data_;
			throw;
		}
	}
	
	return *this;
}

template <typename T> T & CVMatrix<T>::operator() ( const size_t c, const size_t r ) throw( CVMatrixBoundsException ) {
	if( r >= rows_ || c >= cols_ ) throw CVMatrixBoundsException();
	
	return data_[ r * rows_ + c ];
}

template <typename T> const T & CVMatrix<T>::operator() ( const size_t c, const size_t r ) const throw( CVMatrixBoundsException ) {
	if( r >= rows_ || c >= cols_ ) throw CVMatrixBoundsException();
	
	return data_[ r * rows_ + c ];
}

template <typename T> T & CVMatrix<T>::operator[] ( const size_t i ) throw( CVMatrixBoundsException ) { 
	if( i >= ( rows_ * cols_ ) ) throw CVMatrixBoundsException();
	
	return this->data_[ i ]; 
}
template <typename T> const T & CVMatrix<T>::operator[] ( const size_t i ) const throw( CVMatrixBoundsException ) {
	if( i >= ( rows_ * cols_ ) ) throw CVMatrixBoundsException();
	
	return this->data_[ i ]; 
}

// Accessor Methods
template <typename T> size_t CVMatrix<T>::rows() const { return rows_; }

template <typename T> size_t CVMatrix<T>::cols() const { return cols_; }

template <typename T> T* CVMatrix<T>::data() const { return &data_[ 0 ]; }

template <typename T> bool CVMatrix<T>::isSquare() const {
	return ( rows_ != cols_ ) ? false : true;
}

template <typename T> bool CVMatrix<T>::isVector() const {
	return ( rows_ == 1 || cols_ == 1 ) ? true : false;
}

template <typename T> bool CVMatrix<T>::isScalar() const {
	return ( rows_ == 1 && cols_ == 1 ) ? true : false;
}

template <typename T> T CVMatrix<T>::min() const {
	T mn = data_[ 0 ];
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i ) 
		mn = ( data_[ i ] < mn ) ? data_[ i ] : mn;
	
	return mn;
}

template <typename T> T CVMatrix<T>::max() const {
	T mx = data_[ 0 ];
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i ) 
		mx = ( data_[ i ] < mx ) ? mx : data_[ i ];
	
	return mx;
}

template <typename T> T CVMatrix<T>::avg() const {
	T av = data_[ 0 ];
	
	for( size_t i = 0; i < rows_; ++i )
		for( size_t j = 0; j < cols_; j++ ) {  av = ( av + data_[ i * cols_ + j ] ) / static_cast<T>( 2.0 ); }
	
	return av;
}

template <typename T> T CVMatrix<T>::sum() const {
	return sum() / static_cast<T>( ( rows_ * cols_ ) );
}

template <typename T> bool CVMatrix<T>::operator==( const CVMatrix<T> &rhs ) const {
	if( this != &rhs ) {
		
		if( !kMatrixDimensionsMatchAssertion ) return false;
		
		for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
			if( data_[ i ] != rhs.data_[ i ] ) return false;
	}
	
	return true;
}

template <typename T> bool CVMatrix<T>::operator!=( const CVMatrix<T> &rhs ) const {
	return !( this->operator==( rhs ) );
}

// Matrix - Matrix Ops
template <typename T> const CVMatrix<T> CVMatrix<T>::operator+ ( const CVMatrix<T> &rhs ) const throw( CVMatrixDimensionsException ) {
	try {
		return CVMatrix<T>( *this ) += rhs;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator+= ( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] += rhs.data_[ i ];
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator- ( const CVMatrix<T> &rhs ) const throw( CVMatrixDimensionsException ) {
	try {
		return CVMatrix<T>( *this ) -= rhs;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator-= ( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] -= rhs.data_[ i ];
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator* ( const CVMatrix<T> &rhs ) const throw( CVMatrixDimensionsException ) {
	try {
		return CVMatrix<T>( *this ) *= rhs;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator*= ( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] *= rhs.data_[ i ];
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator/ ( const CVMatrix<T> &rhs ) const throw( CVMatrixDimensionsException ) {
	try {
		return CVMatrix<T>( *this ) /= rhs;
	} CVThrowAllExceptions();
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator/= ( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] /= rhs.data_[ i ];
	
	return *this;
}

// Matrix - Scalar Ops
template <typename T> const CVMatrix<T> CVMatrix<T>::operator+ ( const T val ) const throw( CVMatrixDimensionsException ) { 
	try {
		return CVMatrix<T>( *this ) += val;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator+= ( const T val ) throw( CVMatrixDimensionsException ) {	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] += val;
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator- ( const T val ) const throw( CVMatrixDimensionsException ) { 
	try {
		return CVMatrix<T>( *this ) -= val;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator-= ( const T val ) throw( CVMatrixDimensionsException ) {	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] -= val;
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator* ( const T val ) const throw( CVMatrixDimensionsException ) { 
	try {
		return CVMatrix<T>( *this ) *= val;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator*= ( const T val ) throw( CVMatrixDimensionsException ) {		
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] *= val;
	
	return *this;
}

template <typename T> const CVMatrix<T> CVMatrix<T>::operator/ ( const T val ) const throw( CVMatrixDimensionsException ) { 
	try {
		return CVMatrix<T>( *this ) /= val;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::operator/= ( const T val ) throw( CVMatrixDimensionsException ) {		
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] /= val;
	
	return *this;
}

// Matrix - Matrix Ops
template <typename T> CVMatrix<T> CVMatrix<T>::mult( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException ) {
	CV_ASSERT( kMatrixMultiplicationDimensionsMismatch );
	if( !kMatrixMultiplicationDimensionsMismatch ) throw CVMatrixDimensionsException();
	
	try {
		CVMatrix<T> mtx( cols_, rhs.cols_ );
		
		for( size_t i = 0; i < cols_; ++i )
			for( size_t j = 0; j < rhs.rows_; j++ )
				for( size_t k = 0; k < rows_; k++ )
					mtx( i, j ) += ( *this )( i, k ) * rhs( k, j );
		
		return mtx;
	} CVThrowAllExceptions()
}

// Transformations
template <typename T> void CVMatrix<T>::swapRows( const size_t r0, const size_t r1 ) throw( CVMatrixBoundsException ) {
	CV_ASSERT( r0 != r1 || r0 >= 0 || r1 < rows_ );
	
	if( r0 < 0 || r1 >= rows_ ) throw CVMatrixBoundsException();
	
	if( r0 != r1 ) {
		CVMatrix<T> &m = *this;
		for( size_t i = 0; i < cols_; ++i )
			CVMath::swap( &m( i, r0 ), &m( i, r1 ) );
	}
}

template <typename T> void CVMatrix<T>::swapCols( const size_t c0, const size_t c1 ) throw( CVMatrixBoundsException ) {
	CV_ASSERT( c0 != c1 || c0 >= 0 || c1 < cols_ );
	
	if( c0 < 0 || c1 >= cols_ ) throw CVMatrixBoundsException();
	
	if( c0 != c1 ) {
		CVMatrix<T> &m = *this;
		for( size_t i = 0; i < rows_; ++i )
			CVMath::swap( &m( c0, i ), &m( c1, i ) );
	}
}


template <typename T> void CVMatrix<T>::transpose() {
	if( !isVector() ) {
		for( size_t i = 0; i < rows_; ++i ) 
			for( size_t j = i; j < cols_; j++ ) {
				T * src = &( data_[ i * rows_ + j ] );
				T * dst = &( data_[ j * rows_ + i ] );
				CVMath::swap( src, dst );
			}
	}
	
	CVMath::swap( &rows_, &cols_ );
}

template <typename T> void CVMatrix<T>::clamp( T hi, T lo ) {
	if( hi < lo )
		CVMath::swap( &hi, &lo );
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] = ( data_[ i ] > hi ) ? hi : ( data_[ i ] < lo ) ? lo : data_[ i ];
}

template <typename T> CVMatrix<T> & CVMatrix<T>::find( T lo, T hi ) const {
	if( hi < lo )
		CVMath::swap( &hi, &lo );
	
	try {
		CVMatrix<T> * mtx = new CVMatrix<T>( cols_, rows_ );
		
		for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
			mtx->data_[ i ] = ( data_[ i ] > hi ) ? 0 : ( data_[ i ] < lo ) ? 0 : 1;
		
		return *mtx;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::abs() {
	try {
		CVMatrix<T> * mtx = new CVMatrix<T>( cols_, rows_ );
		
		for( size_t i = 0; i < ( cols_ * rows_ ); ++i )
			mtx->data_[ i ] = static_cast<T>( ::abs( data_[ i ] ) );
		
		return *mtx;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::max( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	try {
		CVMatrix<T> * mtx = new CVMatrix<T>( cols_, rows_ );
		
		for( size_t i = 0; i < ( cols_ * rows_ ); ++i )
			mtx->data_[ i ] = ( data_[ i ] > rhs.data_[ i ] ) ? data_[ i ] : rhs.data_[ i ];
		
		return *mtx;
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> & CVMatrix<T>::min( const CVMatrix<T> &rhs ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	try {
		CVMatrix<T> * mtx = new CVMatrix<T>( cols_, rows_ );
		
		for( size_t i = 0; i < ( cols_ * rows_ ); ++i )
			mtx->data_[ i ] = ( data_[ i ] < rhs.data_[ i ] ) ? data_[ i ] : rhs.data_[ i ];
		
		return *mtx;
	} CVThrowAllExceptions()
}

template <typename T> void CVMatrix<T>::normalize() {
	*this /= max();
}

template <typename T> void CVMatrix<T>::normalize( T lo, T hi ) {
	T a = lo, b = hi, c = min(), d = max();
	
	for( size_t i = 0; i < ( rows_ * cols_ ); ++i )
		data_[ i ] = ( ( data_[ i ] - c ) * ( ( b - a ) / ( c - d ) ) ) + a;
}

template <typename T> CVMatrix<T> CVMatrix<T>::interpolate( const CVMatrix<T> &rhs, const double t ) throw( CVMatrixDimensionsException ) {
	if( !kMatrixDimensionsMatchAssertion ) throw CVMatrixDimensionsException();
	
	try {
		CVMatrix<T> mtx( cols_, rows_ );
		
		
		for( size_t i = 0; i < ( rows_ * cols_ ); ++i ) {
			T l = data_[ i ], r = rhs.data_[ i ];
			mtx.data_[ i ] = static_cast<T>( l - t * ( l + r ) ); // Interpolated value
			//mtx->data_[ i ] = ( ( 1. - t ) * rhs.data_[ i ] + t * data_[ i ] ); // Interpolated value
		}
		
		return mtx;
	} CVThrowAllExceptions()
}

template <typename T> CVVector<T> CVMatrix<T>::row( const size_t r ) const throw( CVMatrixBoundsException ) {
	try {
		CVVector<T> rw( submatrix( r, 0, 1, cols_ ) );
		rw.transpose();
		
		return rw;
	} CVThrowAllExceptions()
}
					   
template <typename T> CVVector<T> CVMatrix<T>::col( const size_t c ) const throw( CVMatrixBoundsException ) {
	try {
		return CVVector<T>( submatrix( 0, c, rows_, 1 ) );
	} CVThrowAllExceptions()
}

template <typename T> CVMatrix<T> CVMatrix<T>::submatrix( const size_t r0, const size_t c0, const size_t height, const size_t width ) const throw( CVMatrixBoundsException ) {
	if( ( r0 + height ) > rows_ || ( c0 + width ) > cols_ ) throw CVMatrixBoundsException();
	
	try {
		CVMatrix<T> mtx( height, width );
		
		for( size_t i = r0; i < ( r0 + height ); ++i ) {
			for( size_t j = c0; j < ( c0 + width ); j++ ) {
				mtx( i - r0, j - c0 ) = data_[ i * rows_ + j ];
			}
		}
		
		return mtx;
	} CVThrowAllExceptions()
}

template <typename T> T CVMatrix<T>::det() const {
	if( !isSquare() ) return 0;
	
	// FIX ME
	return 0;
}

template <typename T> CVString CVMatrix<T>::description() const {
	return( CVString( "Rows: " ) + CVString( " Cols: " ) ); // TODO : description
}

CVStandardTypes( CVMatrix )
