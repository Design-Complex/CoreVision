/*
 *  CVVector.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVVector_
#define _CVVector_

#include "CVMatrix.h"

namespace CV {
	template<typename T> class CVVector : public CVMatrix<T> {
		CVRTTIDeclare()
		
	public:
		// Special Constructors
		static CVVector & gaussian( const int32_t step );
		
		// Constructors
		CVVector( const size_t len = 1, const T &a = 0 );
		CVVector( const CVVector &rhs );
		CVVector( const CVMatrix<T> &rhs );
		virtual ~CVVector();
		
		// Operators
		CVVector & operator= ( const CVVector &rhs );
		
		// Accessors
		bool isRow() const;
		bool isColumn() const;
		
		size_t length() const;
		
		T magnitude();
		
		// Transformations
		virtual void transpose();
		
		// Vector / Vector Operations
		T inner( const CVVector &rhs );
		CVMatrix<T> outer( const CVVector &rhs );
		CVVector cross( const CVVector &rhs );
	};
	
	typedef CVVector<float> CVFloatVector;
	typedef CVFloatVector * CVFloatVectorRef;
	
	typedef CVVector<double> CVDoubleVector;
	typedef CVDoubleVector * CVDoubleVectorRef;
	
	template <typename T> CVRTTIDefineTemplate( T, CVVector<T>, CVMatrix<T> )
	
}

#endif // _CVVector_
