/*
 *  CVApplication.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVApplication_
#define _CVApplication_

#include "CVSingleton.h"

namespace CV {
	
	#pragma GCC visibility push(default)
	
	/*!
	 @class
	 @superclass  CVObject
	 @abstract    CVApplication is the abstract superclass for Application objects.
	 @discussion  CVApplication sets up a default runloop, signal handler, thread handler and deals with shell command processing and pipes.
	 */

	class CVApplication : public CVObject {
		CVSingletonDeclare( CVApplication )
		CVRTTIDeclare()
		
	public:
		/*!
		 @method     
		 @abstract   Initialize the CVApplication class, optionally performing commandline arguments.
		 @discussion Override this method if you'd like to modify default command-line argument processing or to set up additional threads.
		 */
		virtual int init( int argc, char *argv[] );
	};
	
	#pragma GCC visibility pop
	
}

extern "C" {
	/*!
	 @function     
	 @abstract   The default replacement for the main() function for C/C++ programs.
	 @discussion You should not override this function, it initializes the CVApplication singleton for this class. Instead, you should pass a non-const reference to the CVApplication subclass you'd like to run. By default, a default CVApplication will be created.
	 */
	int CVApplicationMain( int argc, char *argv[] );
}

#endif // _CVApplication_
