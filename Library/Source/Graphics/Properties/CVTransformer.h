/*
 *  CVTransformer.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/8/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVTransformer_
#define _CVTransformer_

#include "CVMath.h"

namespace CV {
	
	class CVTransformer {
	private:
		bool			identity_;
		
	protected:
		CVPrivateCopyAndAssign( CVTransformer );
		CVTransform		transform_;
		
	public:
		CVTransformer();
		virtual ~CVTransformer();
		
		CVTransform * data();
		
		virtual void transform();
		virtual void inverseTransform();
		CVVertex position();
		
		virtual void reset();
		
		virtual void perspective( const float d );
		virtual void rotate( const float theta, const CVVertex &vec );
		virtual void scale( const CVVertex &vec );
		virtual void translate( const CVVertex &vec );
	};
	
}

#endif // _CVTransformer_
