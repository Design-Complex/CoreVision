/*
 *  CVMatrix2.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVMatrix2_
#define _CVMatrix2_

#include "CVMatrix.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	template <typename T> class CVMatrix2 : public CVMatrix<T> {
		CVRTTIDeclare()
		
	public:
		CVMatrix2( T a = 0, T b = 0, T c = 0, T d = 0 );
		CVMatrix2( const CVMatrix<T> &rhs );
		CVMatrix2( const CVMatrix2 &rhs );
		virtual ~CVMatrix2();
		
		CVMatrix2 & operator=( const CVMatrix2 &rhs );
		
		virtual T det();
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVMatrix2<T>, CVMatrix<T> )
	
	#pragma GCC visibility pop
	
}

#endif // _CVMatrix2_
