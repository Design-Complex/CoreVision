/*
 *  CVDisplay.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDisplay_
#define _CVDisplay_

#include "CVGraphicsIncludes.h"
#include "CVGraphicsException.h"

#include "CVDisplayContext.h"
#include "CVDisplayMode.h"

namespace CV {

	class CVDisplayContext;
	class CVDisplayMode;
	
	class CVDisplay : public CVObject {
		friend class CVDisplayController;
		
		CVRTTIDeclare()
		CVPrivateConstructors( CVDisplay );
		
		CVDisplay( CVDisplayId did = kCVMainDisplay );
		
		CVDisplayId			displayId_;
		CVDisplayContext	displayContext_;
		CVDisplayMode		displayMode_;
		CVDisplayLinkRef	displayLink_;	
		
	public:
		virtual ~CVDisplay();
		
		bool isMainDisplay() const;
		bool isActive() const;
		bool isOnline() const;
		bool isCaptured() const;
		
		void capture();
		void release();
		
		CVDisplayId displayId() const;
		CVDisplayContext & displayContext();
		
		size_t width() const;
		size_t height() const;
		float aspect() const;
		
		virtual CVString description() const;
	};
}

#endif // _CVDisplay_
