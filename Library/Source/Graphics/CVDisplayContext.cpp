/*
 *  CVDisplayContext.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVDisplayContext.h"
#include "CVGraphicsException.h"

using namespace CV;

CVRTTIDefine( CVDisplayContext, CVObject )

CVDisplayContext CVDisplayContext::fullscreenContext( UInt32 displayId ) {
	CGLError err = kCGLNoError;
	GLint numPixelFormats;
	CGLPixelFormatObj pixelFormatObj;
	
	CGLPixelFormatAttribute attribs[] = {
		kCGLPFADoubleBuffer,
        kCGLPFAFullScreen,
		kCGLPFAAccelerated,
		kCGLPFANoRecovery,
        kCGLPFADisplayMask,
        ( _CGLPixelFormatAttribute )CGDisplayIDToOpenGLDisplayMask( displayId ),
		kCGLPFAColorSize, static_cast<CGLPixelFormatAttribute>( 24 ), // 8 bits per channel
		kCGLPFAAlphaSize, static_cast<CGLPixelFormatAttribute>( 8 ), // 8 bits of alpha
		kCGLPFAMultisample, // Anti-alias
		kCGLPFASampleBuffers, static_cast<CGLPixelFormatAttribute>( 1 ),
		kCGLPFASamples, static_cast<CGLPixelFormatAttribute>( 4 ),
        ( CGLPixelFormatAttribute )NULL
    };
	
	err = CGLChoosePixelFormat( attribs, &pixelFormatObj, &numPixelFormats );
	
	if( pixelFormatObj == NULL ) {
		std::cerr << "Couldn't find an FSAA pixel format, trying something more basic" << std::endl;
		
		CGLPixelFormatAttribute attribs[] = {
			kCGLPFADoubleBuffer,
			kCGLPFAFullScreen,
			kCGLPFAAccelerated,
			kCGLPFANoRecovery,
			kCGLPFADisplayMask,
			( _CGLPixelFormatAttribute )CGDisplayIDToOpenGLDisplayMask( displayId ),
			( CGLPixelFormatAttribute )NULL
		};
		
		err = CGLChoosePixelFormat( attribs, &pixelFormatObj, &numPixelFormats );
	}
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	
	try {
		return CVDisplayContext( pixelFormatObj );
	} catch( CVGraphicsException &ge ) {
		throw ge;
	} catch(...) {
		throw CVUnknownException();
	}
}

CVDisplayContext CVDisplayContext::offscreenContext( const size_t width, const size_t height ) {
	CGLError err = kCGLNoError;
	GLint numPixelFormats;
	CGLPixelFormatObj pixelFormatObj;
	
	CGLPixelFormatAttribute attribs[] = {
		kCGLPFAOffScreen,
		kCGLPFAColorSize, ( CGLPixelFormatAttribute )32,
        ( CGLPixelFormatAttribute )NULL
    };
	
	err = CGLChoosePixelFormat( attribs, &pixelFormatObj, &numPixelFormats );
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	
	try {
		CVDisplayContext ctx( pixelFormatObj );
		ctx.setupOffscreenBuffer( width, height );
		
		return ctx;
	} catch( CVGraphicsException &ge ) {
		throw;
	} CVThrowAllExceptions()
}

CVDisplayContext CVDisplayContext::currentContext() {
	return CVDisplayContext( CGLGetCurrentContext() );
}

CVDisplayContext::CVDisplayContext( CGLPixelFormatObj pixelFormatObj ) : 
	CVObject::CVObject(),  
	context_(),
	clearColor_( kNeutralGreyColor ),
	clearDepth_( 1.0 ),
	buffer_( 0 ) {
	CGLError err = kCGLNoError;
	GLint numPixelFormats;
	
	// If no pixel format has been specified, choose a default
	if( !pixelFormatObj ) {
		CGLPixelFormatAttribute attribs[] = { // Default
			kCGLPFADoubleBuffer,
			kCGLPFAFullScreen,
			kCGLPFAAccelerated,
			kCGLPFANoRecovery,
			( CGLPixelFormatAttribute )NULL
		};
		
		err = CGLChoosePixelFormat( attribs, &pixelFormatObj, &numPixelFormats );
		if( err != kCGLNoError )
			throw CVGraphicsException( err );
	}
	
	err = CGLCreateContext( pixelFormatObj, NULL, &context_ );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	CGLRetainContext( context_ );
	
	// Attempt to enable multi-threaded OpenGL
	err = CGLEnable( context_, kCGLCEMPEngine ); // This should be a no-op on PPC machines
	if( err != kCGLNoError )
		std::cerr << "Couldn't enable Multi-Threaded GL!";
	
	CGLDestroyPixelFormat( pixelFormatObj );
}

CVDisplayContext::CVDisplayContext( CGLContextObj context ) : 
	CVObject::CVObject(), 
	context_( CGLRetainContext( context ) ),
	clearColor_( kNeutralGreyColor ),
	clearDepth_( 1.0 ),
	buffer_( 0 ) {}

CVDisplayContext::CVDisplayContext( const CVDisplayContext &rhs ) : 
	CVObject::CVObject(), 
	context_(),
	clearColor_( rhs.clearColor_ ),
	clearDepth_( rhs.clearDepth_ ),
	buffer_( 0 ) {
		
	CGLError err = CGLCreateContext( CGLGetPixelFormat( rhs.context_ ), rhs.context_, &context_ );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
		
	err = CGLCopyContext( rhs.context_, context_, GL_ALL_ATTRIB_BITS );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
}

CVDisplayContext & CVDisplayContext::operator=( const CVDisplayContext &rhs ) { // TODO: Hide This??
	if( this != &rhs ) {
		try {
			this->setContext( rhs.context_ );
			
		} CVThrowAllExceptions()
	}
	
	return *this;
}

CVDisplayContext::~CVDisplayContext() {
	CGLReleaseContext( context_ );
}

CGLContextObj CVDisplayContext::context() {
	return context_;
}

void CVDisplayContext::setContext( CGLContextObj context ) {
	CGLReleaseContext( context_ );
	context_ = CGLRetainContext( context_ ); 
}

CVColor & CVDisplayContext::clearColor() {
	return clearColor_;
}

void CVDisplayContext::setClearColor( const CVColor &clr ) {
	clearColor_ = clr;
}

GLclampd CVDisplayContext::clearDepth() {
	return clearDepth_;
}

void CVDisplayContext::setClearDepth( GLclampd depth ) {
	clearDepth_ = depth;
}

void CVDisplayContext::lock() {
	CGLError err = CGLLockContext( context_ );
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	
	CVLockable::lock();
}

void CVDisplayContext::unlock() {
	CGLError err = CGLUnlockContext( context_ );
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	
	CVLockable::unlock();
}

void CVDisplayContext::setCurrent( bool flag ) {
	CGLError err;
	
	err = ( flag ) ? CGLSetCurrentContext( context_ ) : CGLSetCurrentContext( NULL );
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
}

void CVDisplayContext::setupOffscreenBuffer( const uint32_t width, const uint32_t height ) {
	try {
		if( buffer_ ) free( buffer_ );
		buffer_ = malloc( width * height * 32 / sizeof( char ) );
		CGLError err = CGLSetOffScreen( context_, width, height, width * 4, buffer_ );
		if( err != kCGLNoError )
			throw CVGraphicsException( err );
	} CVThrowAllExceptions()
}

void CVDisplayContext::setVBLSync( bool flag ) {
	GLint sync = ( flag ) ? 1 : 0;
	
	CGLSetParameter( context_,  kCGLCPSwapInterval, &sync );
}

void CVDisplayContext::grabRect( CVIndex top, CVIndex left, CVIndex bottom, CVIndex right, void * buffer ) {
	//CVMutexGuard( lock_ ); // TODO : Figure out why lock isn't working.
	
	// Choose which buffer to read from
	// FIX ME! Make this settable
	glReadBuffer( GL_FRONT );
	
	// For extra safety, save & restore OpenGL states that are changed
    glPushClientAttrib( GL_CLIENT_PIXEL_STORE_BIT );
    
    glPixelStorei( GL_PACK_ALIGNMENT, 4 ); /* Force 4-byte alignment */
    glPixelStorei( GL_PACK_ROW_LENGTH, 0 );
    glPixelStorei( GL_PACK_SKIP_ROWS, 0 );
    glPixelStorei( GL_PACK_SKIP_PIXELS, 0 );
	
	// See sample code for this. We may (probably) need to swizzle this code
	glReadPixels( left, top, right, bottom, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, buffer );
	
	glPopClientAttrib();
	
	GLenum err = glGetError();
   
	if( err != GL_NO_ERROR )
		throw CVGraphicsException( static_cast<CGLError>( err ) );
}

void * CVDisplayContext::grabFrame() {
	try {
		CVIndex w = this->width(); 
		CVIndex h = this->height();
		
		CVIndex size = ( ( w * 4 ) + 3 ) & ~3; // 32 bit pixels? align to 4 bytes
		
		uint32_t * data = new uint32_t[ size * h ];
		
		grabRect( 0, 0, this->width(), this->height(), static_cast<void *>( data ) );
		
		return data;
	} CVThrowAllExceptions()
}
 
void CVDisplayContext::clear() {
	CGLError err = CGLClearDrawable( context_ );
	
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
}

void CVDisplayContext::flush() {
	CGLError err = CGLFlushDrawable( context_ );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
}

GLsizei CVDisplayContext::width() {
	return 0;
}

GLsizei CVDisplayContext::height() {
	return 0;
}

void CVDisplayContext::reshape( GLsizei w, GLsizei h ) {
	
}
