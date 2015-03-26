/*
 *  CVMatrix4.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVMatrix4_
#define _CVMatrix4_

#include "CVMatrix.h"

namespace CV {

#pragma GCC visibility push(default)
	
	template <typename T> class CVMatrix4 : public CVMatrix<T> {
		CVRTTIDeclare()
		
	public:
		CVMatrix4();
		CVMatrix4( const CVMatrix<T> &rhs );
		CVMatrix4( const CVMatrix4 &rhs );
		virtual ~CVMatrix4();
		
		CVMatrix4 & operator=( const CVMatrix4 &rhs );
		
		CVMatrix4 inverse();
		
		virtual T det();
	};
	
	typedef CVMatrix4<float> CVTransform;
	
	template <typename T> CVRTTIDefineTemplate( T, CVMatrix4<T>, CVMatrix<T> )
	
#pragma GCC visibility push(default)
	
}

#endif // _CVMatrix4_
