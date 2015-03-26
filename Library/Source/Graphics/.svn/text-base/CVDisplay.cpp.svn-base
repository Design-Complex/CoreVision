/*
 *  CVDisplay.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/11/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVBase.h"
#include "CVDisplay.h"
#include "CVDisplayContext.h"
#include "CVDisplayMode.h"
#include <CoreGraphics/CGDirectDisplay.h>

using namespace CV;

CVRTTIDefine( CVDisplay, CVObject )

CVDisplay::CVDisplay( CVDisplayId did ) : 
	displayId_( did ), 
	displayLink_( 0 ), 
	displayMode_(), 
	displayContext_( CVDisplayContext::fullscreenContext( did ) ) {
#ifdef __APPLE__
	CVReturn err = CVDisplayLinkCreateWithCGDisplay( displayId_, &displayLink_ );
	if( err != kCVReturnSuccess )
		throw CVCoreVideoException( err );
		
		CVDisplayLinkCreateWithActiveCGDisplays( &displayLink_ );
		
		CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext( displayLink_, displayContext_.context(), CGLGetPixelFormat( displayContext_.context() ) );
#else
	
#endif // __APPLE__
}

CVDisplay::~CVDisplay() {
	release();
	
	CVDisplayLinkRelease( displayLink_ );
}

bool CVDisplay::isMainDisplay() const {
	return ( bool )CGDisplayIsMain( displayId_ );
}

bool CVDisplay::isActive() const {
	return ( bool )CGDisplayIsActive( displayId_ );
}

bool CVDisplay::isOnline() const {
	return ( bool )CGDisplayIsOnline( displayId_ );
}

bool CVDisplay::isCaptured() const {
	return ( bool )CGDisplayIsCaptured( displayId_ );
}

void CVDisplay::capture() {
	displayContext_.setCurrent();
	
	GLuint displayMask = CGDisplayIDToOpenGLDisplayMask( displayId_ );
	
	CGLError err = CGLSetFullScreenOnDisplay( displayContext_.context(), displayMask );
	
	CVDisplayLinkStart( displayLink_ );
	
	CGDisplayConfigRef cfg;
	CGBeginDisplayConfiguration( &cfg );
	CVColor & clr = displayContext_.clearColor();
	CGConfigureDisplayFadeEffect( cfg, 1.0f, 1.0f, clr.r, clr.g, clr.b );
	
	err = static_cast<CGLError>( CGCompleteDisplayConfiguration( cfg, kCGConfigureForAppOnly ) );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
	
	err = ( CGLError )CGDisplayCapture( displayId_ );
	if( err != kCGLNoError )
		throw CVGraphicsException( err );
}

void CVDisplay::release() {
	if( !isCaptured() ) return;
	
	displayContext_.clear();
	
	displayContext_.setCurrent( false );
	
	CVDisplayLinkRelease( displayLink_ );
	
	CGDisplayRelease( displayId_ );
}

CVDisplayId CVDisplay::displayId() const {
	return displayId_;
}

CVDisplayContext & CVDisplay::displayContext() {
	return displayContext_;
}

size_t CVDisplay::width() const {
	return CGDisplayPixelsWide( displayId_ );
}

size_t CVDisplay::height() const {
	return CGDisplayPixelsHigh( displayId_ );
}

float CVDisplay::aspect() const {
	return ( float )width() / ( float )height();
}

CVString CVDisplay::description() const {
	CFNumberRef number;
	int32_t mode, ioflags, w, h;
	CGFloat refresh;
	//std::stringstream iss( std::stringstream::in | std::stringstream::out );
	
	CFDictionaryRef currentMode = CGDisplayCurrentMode( displayId_ );
	//iss << "Display " << ( UInt32 )displayId_ << ":" << std::endl;
	
	number = ( CFNumberRef )CFDictionaryGetValue( currentMode, kCGDisplayMode );
	CFNumberGetValue( number, kCFNumberLongType, &mode );
	//iss << "DisplayMode: " << mode << std::endl;
	
	number = ( CFNumberRef )CFDictionaryGetValue( currentMode, kCGDisplayWidth );
	CFNumberGetValue( number, kCFNumberLongType, &w );
	//iss << "DisplayMode: " << mode << std::endl;
	
	number = ( CFNumberRef )CFDictionaryGetValue( currentMode, kCGDisplayHeight );
	CFNumberGetValue( number, kCFNumberLongType, &h );
	//iss << "DisplayMode: " << mode << std::endl;
	
	number = ( CFNumberRef )CFDictionaryGetValue( currentMode, kCGDisplayRefreshRate );
	CFNumberGetValue( number, kCFNumberDoubleType, &refresh );
	//iss << "Refresh Rate: " << refresh << "Hz" << std::endl;
	
	number = ( CFNumberRef )CFDictionaryGetValue( currentMode, kCGDisplayIOFlags );
	CFNumberGetValue( number, kCFNumberLongType, &ioflags );
	//iss << "IOFlags: " << ioflags << std::endl;
	
	CFStringRef str = CFStringCreateWithFormat( 
												  kCFAllocatorDefault, 
												  NULL, 
												  CFSTR( "Display %u:\nDisplay Mode: %u\nWidth: %u Height: %u\nRefresh Rate: %.1f\nIOFlags: %u\n" ), 
												  ( uint32_t )displayId_,
												  mode,
												  width(),
												  height(),
												  refresh,
												  ioflags );
	
	return CVString( str );
}
