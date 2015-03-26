/*
 *  CVTexture.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVTexture_
#define _CVTexture_

#include "CVBase.h"
#include "CVGraphicsIncludes.h"
#include "CVTransformer.h"

namespace CV {

	class CVTexture : public CVObject, public CVTransformer {
		CVRTTIDeclare()
		
	private:
		CVPrivateCopyAndAssign( CVTexture );
		
		GLuint		textureId_;
		GLfloat		scale_;
		
	public:
		CVTexture();
		virtual ~CVTexture();
		
	};
	
}

#endif // _CVTexture_
