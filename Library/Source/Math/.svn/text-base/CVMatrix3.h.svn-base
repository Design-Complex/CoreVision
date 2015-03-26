/*
 *  CVMatrix3.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVMatrix3_
#define _CVMatrix3_

#include "CVMatrix.h"

namespace CV {
	
#pragma GCC visibility push(default)
	
	template <typename T> class CVMatrix3 : public CVMatrix<T> {
		CVRTTIDeclare()
		
	public:
		CVMatrix3( T a1 = 0, T a2 = 0, T a3 = 0, T b1 = 0, T b2 = 0, T b3 = 0, T c1 = 0, T c2 = 0, T c3 = 0 );
		CVMatrix3( const CVMatrix<T> &rhs );
		CVMatrix3( const CVMatrix3 &rhs );
		virtual ~CVMatrix3();
		
		CVMatrix3 & operator=( const CVMatrix3 &rhs );
		
		virtual T det();
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVMatrix3<T>, CVMatrix<T> )
		
#pragma GCC visibility pop
		
}

#endif // _CVMatrix3_
