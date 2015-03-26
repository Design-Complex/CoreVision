/*
 *  CVDisplayContext.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVDisplayContext_
#define _CVDisplayContext_

#include "CVObject.h"
#include "CVLockable.h"
#include "CVGraphicsException.h"
#include "CVColor.h"
#include <OpenGL/OpenGL.h>

namespace CV {

	class CVDisplayContext : public CVObject, public CVLockable {
		friend class CVDisplay;
		
		CVRTTIDeclare()
		
	private:
		CVColor			clearColor_;
		GLclampd		clearDepth_;
		
		CGLContextObj	context_;
		void *			buffer_;
		
		CVDisplayContext( CGLContextObj ctx );
		
		void setupOffscreenBuffer( const uint32_t width, const uint32_t height );
		
		CGLContextObj context();
		void setContext( CGLContextObj context );
		
		void * buffer();
		
	public:
		static CVDisplayContext fullscreenContext( UInt32 displayId );
		static CVDisplayContext offscreenContext( const size_t width = 128, const size_t height = 128 );
		static CVDisplayContext currentContext();
#ifdef __APPLE__
		CVDisplayContext( CGLPixelFormatObj pixelFormatObj = 0 );
#else
		CVDisplayContext(); // TODO
#endif
		CVDisplayContext( const CVDisplayContext &rhs );
		CVDisplayContext & operator=( const CVDisplayContext &rhs );
		virtual ~CVDisplayContext();
		
		CVColor & clearColor();
		void setClearColor( const CVColor &clr );
		
		GLclampd clearDepth();
		void setClearDepth( const GLclampd depth );
		
		virtual void lock();
		virtual void unlock();
		
		void setCurrent( bool flag = true );
		
		void setVBLSync( bool flag = true );
		
		void grabRect( CVIndex top, CVIndex left, CVIndex bottom, CVIndex right, void * buffer );
		void * grabFrame();
		
		//	void blitRect( CVIndex x, CVIndex y, CVIndex w, CVIndex h, void * buffer );
		//	void blitFrame( void * buffer );
		
		void clear();
		void flush();
		
		GLsizei width();
		GLsizei height();
		void reshape( GLsizei w, GLsizei h );
	};
	
}

#endif // _CVDisplayContext_
