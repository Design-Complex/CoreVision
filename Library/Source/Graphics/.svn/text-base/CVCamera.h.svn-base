/*
 *  CVCamera.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVCamera_
#define _CVCamera_

#include "CVObject.h"
#include "CVGraphicsIncludes.h"
#include "CVMath.h"
#include "CVTransformer.h"

namespace CV {
	
	class CVCamera : public CVObject, public CVTransformer {
		CVRTTIDeclare()
		
	private:
		CVPrivateCopyAndAssign( CVCamera );
		
	protected:
		bool				scissor_;
		float				zoom_;
		CVPixel				origin_;
		CVPixel				dimensions_;
		
	public:
		CVCamera( CVPixel origin = CVPixel( 0, 0 ), CVPixel dims = CVPixel( 1, 1 ), float zoom = 1.0, bool scissor = false );
		virtual ~CVCamera();
		
		virtual void reset();
		
		float zoom();
		void setZoom( float z );
		
		virtual void setup();
		virtual void view();
	};
	
	class CVOrthographicCamera : public CVCamera {
	private:
		CVPrivateCopyAndAssign( CVOrthographicCamera );
		
	public:
		CVOrthographicCamera( CVPixel origin = CVPixel( 0, 0 ), CVPixel dims = CVPixel( 1, 1 ), float zoom = 1.0 , bool scissor = false );
		virtual ~CVOrthographicCamera();
		
		virtual void setup();
	};
	
	//class CVPerspectiveCamera : public CVCamera {
	//private:
	//	CVPrivateCopyAndAssign( CVPerspectiveCamera );
	//	
	//	CVPixel		leftRight_;
	//	CVPixel		topBottom_;
	//	CVPixel		nearFar_;
	//	
	//public:
	//	CVPerspectiveCamera( CVPixel lr, CVPixel tb, CVPixel nf );
	//	virtual ~CVPerspectiveCamera();
	//	
	//	void frustum( CVPixel lr, CVPixel tb, CVPixel nf );
	//	
	//	virtual void reset();
	//	
	//	virtual void view();
	//};
	
}	

#endif // _CVCamera_
