/*
 *  CVMatrix.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVMatrix_
#define _CVMatrix_

#include "CVMathDefines.h"
#include "CVObject.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	template <typename T> class CVVector;
	template <typename T> class CVMatrix : public CVObject {
	protected:
		size_t rows_, cols_;
		T * data_;
		
	public:
		CVRTTIDeclare()
		
		// Special Constructor Methods
		static CVMatrix identity( const size_t cols, const size_t rows );
		static CVMatrix random( const size_t cols, const size_t rows, const T lo = 0, const T hi = 1 );
		
		CVMatrix( const size_t cols = 1, const size_t rows = 1, const T & a = 0 );
		CVMatrix( const CVMatrix &rhs );
		virtual ~CVMatrix();
		
		CVMatrix & operator=( const CVMatrix &rhs );
		
		// Accessor Methods
		T & operator() ( const size_t c, const size_t r ) throw( CVMatrixBoundsException );
		const T & operator() ( const size_t c, const size_t r ) const throw( CVMatrixBoundsException );
		
		T & operator[] ( const size_t i ) throw( CVMatrixBoundsException );
		const T & operator[] ( const size_t i ) const throw( CVMatrixBoundsException );
		
		size_t rows() const;
		size_t cols() const;
		
		T * data() const;
		
		inline bool isSquare() const;
		inline bool isVector() const;
		inline bool isScalar() const;
		
		T min() const;
		T max() const;
		T avg() const;
		T sum() const;
		
		virtual CVString description() const;
		
		// Comparison Operators
		virtual bool operator==( const CVMatrix &rhs ) const;
		virtual bool operator!=( const CVMatrix &rhs ) const;
		
		// Element-wise Matrix Ops
		const CVMatrix operator+ ( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator+= ( const CVMatrix &rhs ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator- ( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator-= ( const CVMatrix &rhs ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator* ( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator*= ( const CVMatrix &rhs ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator/ ( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator/= ( const CVMatrix &rhs ) throw( CVMatrixDimensionsException );
		
		// Element-wise Scalar Ops
		const CVMatrix operator+ ( const T val ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator+= ( const T val ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator- ( const T val ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator-= ( const T val ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator* ( const T val ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator*= ( const T val ) throw( CVMatrixDimensionsException );
		
		const CVMatrix operator/ ( const T val ) const throw( CVMatrixDimensionsException );
		CVMatrix & operator/= ( const T val ) throw( CVMatrixDimensionsException );
		
		// Matrix - Matrix Ops
		CVMatrix mult( const CVMatrix &rhs ) const throw( CVMatrixDimensionsException );
		
		// Transformations
		void swapRows( const size_t r0, const size_t r1 ) throw( CVMatrixBoundsException );
		void swapCols( const size_t c0, const size_t c1 ) throw( CVMatrixBoundsException );
		
		virtual void transpose();
		
		virtual void clamp( const T hi, const T lo );
		
		virtual CVMatrix & find( const T lo, const T hi ) const;
		
		virtual CVMatrix & abs();
		
		virtual CVMatrix & max( const CVMatrix &rhs ) throw( CVMatrixDimensionsException );
		virtual CVMatrix & min( const CVMatrix &rhs ) throw( CVMatrixDimensionsException ); 
		
		virtual void normalize();
		virtual void normalize( const T lo, const T hi );
		
		virtual CVMatrix interpolate( const CVMatrix<T> &rhs, const double t ) throw( CVMatrixDimensionsException );
		
		CVVector<T> row( const size_t r ) const throw( CVMatrixBoundsException );
		CVVector<T> col( const size_t c ) const throw( CVMatrixBoundsException );
		CVMatrix<T> submatrix( const size_t r0, const size_t c0, const size_t height, const size_t width ) const throw( CVMatrixBoundsException );
		
		// Linear Properties
		virtual T det() const;
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVMatrix<T>, CVObject )
	
#define CVFloatMatrix CVMatrix<float>
#define CVDoublematrix CVMatrix<double>
	
	#pragma GCC visibility pop
}

#endif // _CVMatrix_
