/*
 *  CVGraphicsException.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 6/5/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVGraphicsException_
#define _CVGraphicsException_

#include "CVBase.h"
#include "CVGraphicsIncludes.h"

#ifdef __APPLE__
	typedef CGLError CVGraphicsErrorCode;
	typedef CVReturn CVVideoErrorCode;
#else
	typedef enum {
		kCVReturnSuccess		= 0,
		kCVBadDisplayContext
	} CVGraphicsErrorCode;

	typedef enum {
		kCVReturnSuccess	= 0,
		kCVReturnUnknown	= kCVReturnError
	} CVVideoErrorCode;
#endif 

namespace CV {

	class CVGraphicsException : public CVException {
		CVRTTIDeclare()
		
	protected:
		CVGraphicsErrorCode error_;
		
	public:
		CVGraphicsException( CVGraphicsErrorCode error = static_cast<CVGraphicsErrorCode>( kCVReturnSuccess ) );
		CVGraphicsException( const CVGraphicsException &rhs );
		CVGraphicsException & operator=( const CVGraphicsException &rhs );
		
		virtual const char * what() const throw();
	};
	
	class CVCoreVideoException : public CVGraphicsException {
		CVRTTIDeclare()
	public:
		CVCoreVideoException( CVVideoErrorCode error = kCVReturnError ) {
			error_ = static_cast<CVGraphicsErrorCode>( error );
		}
		
		virtual const char * what() const throw() {
			switch( error_ ) {
#ifdef __APPLE__
				case kCVReturnSuccess:
					return "No Error";
					break;
				case kCVReturnInvalidArgument:
					return "Invalid function parameter. For example, out of range or the wrong type.";
					break;
				case kCVReturnAllocationFailed:
					return "Memory allocation for a buffer or buffer pool failed.";
					break;
				case kCVReturnInvalidDisplay:
					return "The display specified when creating a display link is invalid.";
					break;
				case kCVReturnDisplayLinkAlreadyRunning:
					return "The specified display link is already running.";
					break;
				case kCVReturnDisplayLinkNotRunning:
					return "The specified display link is not running.";
					break;
				case kCVReturnDisplayLinkCallbacksNotSet:
					return "No callback registered for the specified display link. You must set either the output callback or both the render and display callbacks.";
					break;
				case kCVReturnInvalidPixelFormat:
					return "The buffer does not support the specified pixel format.";
					break;
				case kCVReturnInvalidSize:
					return "The buffer cannot support the requested buffer size (usually too big).";
					break;
				case kCVReturnInvalidPixelBufferAttributes:
					return "A buffer cannot be created with the specified attributes.";
					break;
				case kCVReturnPixelBufferNotOpenGLCompatible:
					return "The pixel buffer is not compatible with OpenGL due to an unsupported buffer size, pixel format, or attribute.";
					break;
				case kCVReturnPoolAllocationFailed:
					return "Allocation for a buffer pool failed, most likely due to a lack of resources. Check to make sure your parameters are in range.";
					break;
				case kCVReturnInvalidPoolAttributes:
					return "A buffer pool cannot be created with the specified attributes.";
					break;
				case kCVReturnLast:
				case kCVReturnError:
				default:
					return "An undefined CoreVideo Error occurred";
					break;
#else
#endif // __APPLE__
			}
		}
	};

}

#endif // _CVGraphicsException_
