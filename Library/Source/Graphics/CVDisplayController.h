/*
 *  CVDisplayController.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDisplayController_
#define _CVDisplayController_

#include "CVGraphicsIncludes.h"
#include "CVSingleton.h"

namespace CV {
	
	class CVDisplay;
	
	typedef std::map<CVDisplayId, CVDisplay * > CVDisplayList;
	
	class CVDisplayController : public CVObject {
		CVSingletonDeclare( CVDisplayController )
		CVRTTIDeclare()
		
	private:
		
		CVDisplay * main_;
		CVDisplayList displays_;
		
	public:
		CVDisplayList & displays();
		
		CVDisplay * mainDisplay() const;
		void setMainDisplay( CVDisplay * display );
	};
	
}

#endif // _CVDisplayController_
