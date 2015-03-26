/*
 *  CVPrimitive.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVPrimitive_
#define _CVPrimitive_

#include "CVObject.h"
#include "CVTransformer.h"
#include "CVVector4.h"
#include "CVGraphicsIncludes.h"
#include <list>

namespace CV {
	
	class CVPrimitive : public CVObject, public CVTransformer {
		CVRTTIDeclare()
		
	protected:
		GLuint					displayList_;
		std::vector<CVVertex>	vertices_;
		
	public:
		CVPrimitive();
		CVPrimitive( const CVPrimitive &rhs );
		virtual ~CVPrimitive();
		
		CVPrimitive & operator=( const CVPrimitive &rhs );
		
		virtual void build();
		virtual void draw();
	};
	
}

#endif // _CVPrimitive_
