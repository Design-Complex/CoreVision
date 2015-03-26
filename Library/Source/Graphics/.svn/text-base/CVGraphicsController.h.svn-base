/*
 *  CVGraphicsController.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/10/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVGraphicsController_
#define _CVGraphicsController_

#include "CVBase.h"
#include "CVADT.h"
#include "CVVector2.h"
#include "CVSingleton.h"
#include "CVDisplayContext.h"

namespace CV {

	class CVGraphicsController : public CVStack<CVDisplayContext * >, virtual CVLockable {
		CVRTTIDeclare()
		CVSingletonDeclare( CVGraphicsController )
		
		static std::map<CVString,bool> extensions_;
		
	protected:
		
	public:
		CVDisplayContext & currentContext();
		
		virtual void push( const CVDisplayContext *ctx );
		virtual CVDisplayContext * pop();
		
		CVVector2<int32_t> glVersion() const;
		CVVector2<int32_t> glslVersion() const;
		
		bool isExtensionSupported( const CVString &ext ) const;
		bool isGLSLSupported() const;
		
		bool isEnabled( int32_t mode ) const;
		void enable( int32_t mode ) const;
		void disable( int32_t mode ) const;
		void toggle( int32_t mode ) const;
	};
	
}

#endif // _CVGraphicsController_
