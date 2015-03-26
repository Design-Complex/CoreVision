/*
 *  CVVector4.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVVector4_
#define _CVVector4_

#include "CVVector.h"

namespace CV {

	template<typename T> class CVMatrix4;
	
	template<typename T> class CVVector4 : public CVVector<T> {
		CVRTTIDeclare()
		
	public:
		T &x, &y, &z, &w;
		
		CVVector4( T a = 0, T b = 0, T c = 0, T d = 1 );
		CVVector4( const CVMatrix<T> &rhs );
		CVVector4( const CVVector<T> &rhs );
		CVVector4( const CVVector4 &rhs );
		virtual ~CVVector4();
		
		CVVector4 & operator=( const CVVector4 &rhs );
		
		// Vector / Vector Operations
		T inner( const CVVector4 &rhs );
		CVMatrix4<T> outer( const CVVector4 &rhs );
		CVVector4 cross( const CVVector4 &rhs );
	};
	
	typedef CVVector4<float> CVVertex;
	#define kCVOrigin CVVertex( 0, 0, 0, 1 )
	
	template <typename T> CVRTTIDefineTemplate( T, CVVector4<T>, CVVector4<T> )
	
}

#endif // _CVVector4_
