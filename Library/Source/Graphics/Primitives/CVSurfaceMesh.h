/*
 *  CVSurfaceMesh.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 2/3/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVSurfaceMesh_
#define _CVSurfaceMesh_

#include "CVPrimitive.h"

namespace CV {
	
	class CVSurfaceMesh : public CVPrimitive {
		CVRTTIDeclare()
		
	private:
		CVPrivateCopyAndAssign( CVSurfaceMesh );
	public:
		CVSurfaceMesh();
		virtual ~CVSurfaceMesh();
	};
	
}

#endif // _CVSurfaceMesh_
