/*
 *  CVVector2.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVVector2_
#define _CVVector2_

#include "CVVector.h"

namespace CV {

	template<typename T> class CVVector2 : public CVVector<T> {
		CVRTTIDeclare()
		
	public:
		CVVector2( T a = 0, T b = 0 );
		CVVector2( const CVMatrix<T> &rhs );
		CVVector2( const CVVector<T> &rhs );
		CVVector2( const CVVector2 &rhs );
		virtual ~CVVector2();
		
		CVVector2 & operator=( const CVVector2 &rhs );
		
		T &x, &y;
	};
	
	typedef CVVector2<float> CVPixel;
	
	template <typename T> CVRTTIDefineTemplate( T, CVVector2<T>, CVVector<T> )
}

#endif // _CVVector2_
