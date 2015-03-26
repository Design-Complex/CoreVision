/*
 *  CVVector3.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVVector3_
#define _CVVector3_

#include "CVVector.h"

namespace CV {

	template<typename T> class CVVector3 : public CVVector<T> {
		CVRTTIDeclare()
		
	public:
		T &x, &y, &z;
		
		CVVector3( T a = 0, T b = 0, T c = 0 );
		CVVector3( const CVMatrix<T> &rhs );
		CVVector3( const CVVector<T> &rhs );
		CVVector3( const CVVector3 &rhs );
		virtual ~CVVector3();
		
		CVVector3 & operator=( const CVVector3 &rhs );
	};
	
	template <typename T> CVRTTIDefineTemplate( T, CVVector3<T>, CVVector<T> )
	
}

#endif // _CVVector3_
