/*
 *  CVPolygon.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVPolygon_
#define _CVPolygon_

#include "CVPrimitive.h"

namespace CV {
	
	class CVPolygon : public CVPrimitive {
		CVRTTIDeclare()
		
	public:
		CVPolygon( CVVertex *verts = 0, size_t count = 0 );
		CVPolygon( const CVPolygon &rhs );
		virtual ~CVPolygon();
		
		CVPolygon & operator=( const CVPolygon &rhs );
		
		virtual void build();
		
	};
	
}

#endif // _CVPolygon_
