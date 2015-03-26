/*
 *  CVGraphicsController.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/10/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVGraphicsController.h"
#include "CVGraphicsIncludes.h"

using namespace CV;

CVRTTIDefine( CVGraphicsController, CVStack<CVDisplayContext *> )

CVSingletonDefine( CVGraphicsController )

std::map<CVString,bool> CVGraphicsController::extensions_;

CVGraphicsController::CVGraphicsController() {
	
}

CVGraphicsController::~CVGraphicsController() {
	
}

CVDisplayContext & CVGraphicsController::currentContext() {
	try {
		return *( this->top() );
	} catch( CVContainerUnderflowException &e ) {
		throw CVGraphicsException( kCGLBadContext );
	} CVThrowAllExceptions()
}

void CVGraphicsController::push( const CVDisplayContext *ctx ) {
	try {
		this->CVStack<CVDisplayContext *>::push( const_cast<CVDisplayContext *>( ctx ) );
		this->top()->setCurrent( true );
		
	} catch( CVContainerOverflowException &e ) {
		throw; // TODO 
	} catch( CVContainerNullNodeException &e ) {
		throw CVGraphicsException( kCGLBadContext );
	} CVThrowAllExceptions()
}

CVDisplayContext * CVGraphicsController::pop() {
	try {
		CVDisplayContext *ctx = this->CVStack<CVDisplayContext *>::pop();
		if( !isEmpty() )
			this->top()->setCurrent( true );
		else
			ctx->setCurrent( false );
		
		return ctx;
	} catch( CVContainerUnderflowException &e ) {
		throw CVGraphicsException( kCGLBadContext );
	} CVThrowAllExceptions()
}

CVVector2<int32_t> CVGraphicsController::glVersion() const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	int32_t major, minor;
	
	const char * ver = reinterpret_cast<const char * >( glGetString( GL_VERSION ) );
	if( ( ver == NULL ) || ( sscanf( ver, "%d.%d", &major, &minor ) != 2 ) ) {
		major = minor = 0;
	}
	
	return CVVector2<int32_t>( major, minor );
}

CVVector2<int32_t> CVGraphicsController::glslVersion() const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	try {
		int32_t major, minor;
		
		CVVector2<int32_t> vers = this->glVersion();
		if( vers[ 0 ] == 1 ) {
			if( this->isGLSLSupported() ) {
				major = 1;
				minor = 0;
			} else {
				major = 0;
				minor = 0;
			}
		} else if( vers[ 0 ] >= 2 ) {
			const char * ver = ( const char * )glGetString( GL_SHADING_LANGUAGE_VERSION );
			if( ( ver == NULL ) || ( sscanf( ver, "%d.%d", &major, &minor ) != 2 ) ) {
				major = minor = 0;
			}
		} else {
			major = minor = 0;
		}
		
		return CVVector2<int32_t>( major, minor );
	} CVThrowAllExceptions()
}

bool CVGraphicsController::isEnabled( int32_t mode ) const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	GLboolean setting;
	
	glGetBooleanv( mode, &setting );
	
	if( setting ) return true;
	
	return false;
}

bool CVGraphicsController::isExtensionSupported( const CVString & ext ) const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	std::map<CVString,bool> & exts = CVGraphicsController::extensions_;
	const GLubyte * key = reinterpret_cast<const GLubyte *>( ext.utf8String() );
	
	if( glVersion().x < 3 ) {
		if( exts.count( ext ) == 0 ) {
			const GLubyte * dict = glGetString( GL_EXTENSIONS );
			
			GLboolean ok = gluCheckExtension( key, dict );
			exts[ ext ] = ( ok == GL_TRUE ) ? true : false;
		}
	} else { // > 3.0 // TODO
		
	}
	
	if( exts.count( ext ) == 0 ) // key doesn't exist
		return ( exts[ ext ] = false );
	
	return exts[ ext ];
}

bool CVGraphicsController::isGLSLSupported() const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	try {
		bool ok = ( this->isExtensionSupported( "GL_ARB_shader_objects" ) ) ? true : false;
		ok = ( ok && this->isExtensionSupported( "GL_ARB_vertex_shader" ) ) ? true : false;
		ok = ( ok && this->isExtensionSupported( "GL_ARB_fragment_shader" ) ) ? true : false;
		ok = ( ok && this->isExtensionSupported( "GL_ARB_shading_language_100" ) ) ? true : false;
		
		return ok;
	} CVThrowAllExceptions()
}

void CVGraphicsController::enable( int32_t mode ) const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	glEnable( mode );
}

void CVGraphicsController::disable( int32_t mode ) const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	glDisable( mode );
}

void CVGraphicsController::toggle( int32_t mode ) const {
	if( isEmpty() ) // No current graphics context!
		throw CVGraphicsException( kCGLBadConnection );
	
	try {
		if( isEnabled( mode ) )
			disable( mode );
		else
			enable( mode );
	} CVThrowAllExceptions()
	
}
