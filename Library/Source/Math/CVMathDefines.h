/*
 *  CVMathDefines.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/10/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CVMathDefines_
#define _CVMathDefines_

#include "CVBase.h"
#include <cmath>
#include <Accelerate/Accelerate.h>

namespace CV {

struct CVMath {

	static const double PI;
	static const double PI2;
	static const double PI_2;
	static const double PI_4;
	
	static double rand( int32_t * seed );
	template<typename T> static T rand( int32_t * seed, T min = 0, T max = 1 );
	
	template<typename T> static void swap( T * src, T * dst ) {
		T tmp = *dst;
		*dst = *src;
		*src = tmp;
	}
	
	template<typename T> static T det2( T a, T b, T c, T d );
	template<typename T> static T det3( T a, T b, T c, T d, T e, T f, T g, T h, T i );
};

#ifndef M_PI
#define M_PI CVMath::PI
#endif // M_PI
	
#define CVXOR(x,y) ( ( (x) || (y) ) && !( (x) && (y) ) )
	
#define kMatrixDimensionsGreaterThanZero ((c) > 0 && (r) > 0)
#define kMatrixMultiplicationDimensionsMismatch (cols_ == rhs.rows_)
#define kMatrixToVectorReshapeBoundsMismatch CVXOR( ( rhs.cols() == 1 && rhs.rows() <= this->length() ), ( rhs.cols() <= this->length() && rhs.rows() == 1 ) )
#define kMatrixDimensionsMatchAssertion ( ( rows_ == rhs.rows_ ) && ( cols_ == rhs.cols_ ) )
	
	class CVMatrixBoundsException		: public CVException {};
	class CVMatrixDimensionsException	: public CVException {};
	class CVMatrixSingularException		: public CVException {};
}

#endif // _CVMathDefines_
