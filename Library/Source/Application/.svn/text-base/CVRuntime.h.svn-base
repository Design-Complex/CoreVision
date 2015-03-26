/*
 *  CVRuntime.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 2/11/10.
 *  Copyright 2010 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVRuntime_
#define _CVRuntime_

#include "CVApplication.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @superclass  CVApplication
	 @abstract    CVRuntime is a concrete subclass of CVApplication. It's purpose is to be run in a separate thread under another task, such as Matlab.
	 @discussion  <#(comprehensive description)#>
	 */

	class CVRuntime : public CVApplication {
		CVSingletonDeclare( CVRuntime )
		CVRTTIDeclare()
		
	private:
		uint32_t status;
		
	protected:
		
	public:
		virtual int init( int argc, char *argv[] );
		
		void setStatus( uint32_t status );
	};
	
	#pragma GCC visibility pop
	
};

extern "C" {
	/*!
	 @function     
	 @abstract   The default replacement for the main() function for C/C++ runtime contexts.
	 @discussion You should not override this function, it initializes the CVRuntime singleton for this class. Instead, you should pass a non-const reference to the CVRuntime subclass you'd like to run. By default, a default CVApplication will be created.
	 */
	int CVRuntimeInit( int argc, char *argv[] );
	
	void CVRuntimeShutdown( uint32_t status );
}

#endif // _CVRuntime_
