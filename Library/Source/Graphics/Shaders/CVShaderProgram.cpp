/*
 *  CVShaderProgram.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVShaderProgram.h"
#include "CVGraphicsController.h"
#include "CVFragmentShader.h"
#include "CVGeometryShader.h"
#include "CVVertexShader.h"

using namespace CV;

CVRTTIDefine( CVShaderProgram, CVObject )

CVShaderProgram::CVShaderProgram() try : 
CVObject::CVObject(),
CVUnique::CVUnique( "" ),
programId_( glCreateProgram() ),
programLog_(),
fragmentShaders_(), 
//geometryShaders_(), 
vertexShaders_()
//uniforms_(),
//attributes_() 
{	
	if( !CVGraphicsController::sharedInstance().isGLSLSupported() )
		throw CVGLSLCompatibilityException();
} CVThrowAllExceptions()

CVShaderProgram::CVShaderProgram( CVFragmentShader & frag, CVVertexShader & vert )  try : 
CVObject::CVObject(),
CVUnique::CVUnique( "" ),
programId_( glCreateProgram() ), 
fragmentShaders_(), 
//geometryShaders_(), 
vertexShaders_(),
programLog_()
//uniforms_(),
//attributes_() 
{
		CVGraphicsController & gc = CVGraphicsController::sharedInstance();
		
		if( !gc.isGLSLSupported() )
			throw CVGLSLCompatibilityException();
	
		// Add & attach the shaders
		attach( frag );
		attach( vert );
	} CVThrowAllExceptions()

CVShaderProgram::~CVShaderProgram() {
	// Fragment Shaders
	for( size_t i = 0; i < fragmentShaders_.size(); ) {
		detach( *( fragmentShaders_[ i ] ) );
		fragmentShaders_.pop_back();
	}
	
	// Geometry Shaders
	for( size_t i = 0; i < geometryShaders_.size(); ) {
		//detach( geometryShaders_[ i ] );
		geometryShaders_.pop_back();
	}
	
	// Vertex Shaders
	for( size_t i = 0; i < vertexShaders_.size();) {
		detach( *( vertexShaders_[ i ] ) );
		vertexShaders_.pop_back();
	}	
}

GLuint CVShaderProgram::programId() const {
	return programId_;
}

CVShaderProgram & CVShaderProgram::attach( CVVertexShader & vs ) {
	try {
		bool ok = vs.compile();
		if( !ok ) throw CVGLSLCompileException();
		
		glAttachShader( programId_, vs.shaderId() );
		
		vertexShaders_.push_back( &vs );
		
	} catch( CVGLSLCompileException &e ) { // TODO: log error
		throw;
	}
	
	return *this;
}



CVShaderProgram & CVShaderProgram::attach( CVFragmentShader & fs ) {
	try {
		bool ok = fs.compile();
		if( !ok ) throw CVGLSLCompileException();
		
		glAttachShader( programId_, fs.shaderId() );
		
		fragmentShaders_.push_back( &fs );
		
	} catch( CVGLSLCompileException &e ) { // TODO: log error
		throw;
	}
	
	return *this;
}

CVShaderProgram & CVShaderProgram::attach( CVGeometryShader & gs ) {
	try {
		//bool ok = vs->compile();
		//if( !ok ) throw CVGLSLCompileException();
		
		//glAttachShader( programId_, vs->shaderId() );
		
		geometryShaders_.push_back( &gs );
		
	} catch( CVGLSLCompileException &e ) { // TODO: log error
		throw;
	}
	
	return *this;
}

CVShaderProgram & CVShaderProgram::detach( const CVShader & shader ) {
	glDetachShader( programId_, shader.shaderId() );
	
	return *this;
}

CVShaderProgram & CVShaderProgram::link() {
	glLinkProgram( programId_ );
	
	if( !isLinked() ) {
		std::cerr << log().utf8String() << std::endl;
	}
	
	//	getUniforms();
	//	getAttributes();
	
	return *this;
}

CVString & CVShaderProgram::log() {
	return programLog_;
}

void CVShaderProgram::getLog() {
	GLint status;	
	glGetProgramiv( programId_, GL_INFO_LOG_LENGTH, &status );
	
	GLchar log[ status ];
	
	glGetProgramInfoLog( programId_, status, &status, log );
	
	programLog_ = CVString( log );
}

bool CVShaderProgram::isFlaggedForDeletion() {
	GLint status;
	
	glGetProgramiv( programId_, GL_DELETE_STATUS, &status );
	
	return ( status == GL_TRUE ) ? true : false;
}

bool CVShaderProgram::isValid() {
	GLint status;
	glGetProgramiv( programId_, GL_VALIDATE_STATUS, &status );
		
	if( status != GL_TRUE ) {
		getLog();
		
		return false;
	}
		
	return true;
}

bool CVShaderProgram::isLinked() {
	GLint status;
	glGetProgramiv( programId_, GL_LINK_STATUS, &status );
		
	if( status != GL_TRUE ) {
		getLog();
		
		return false;
	}
	
	return true;
}

CVShaderProgram & CVShaderProgram::enable() {
	glUseProgram( programId_ );
	
	return *this;
}

CVShaderProgram & CVShaderProgram::disable() {
	glUseProgram( 0 );
	
	return *this;
}

//GLint CVShaderProgram::activeAttributeCount() {
//	GLint count;
//	glGetProgramiv( programId_, GL_ACTIVE_ATTRIBUTES, &count );
//	
//	return count;
//}
//
//void CVShaderProgram::getAttributes() {
//	int32_t count = activeAttributeCount();
//	for( int32_t i = 0; i < count; i++ ) {
//		GLsizei bufSize = 128;
//		
//		GLint vSize;
//		GLenum vType;
//		char vName[ bufSize ];
//		
//		glGetActiveAttrib( programId_, i, bufSize, NULL, &vSize, &vType, ( GLchar * )&vName );
//		attributes_.insert( CVGLSLVariablePair( CVString( vName ), i ) );
//	}
//}
//
//GLint CVShaderProgram::activeUniformCount() {
//	GLint count;
//	glGetProgramiv( programId_, GL_ACTIVE_UNIFORMS, &count );
//	
//	return count;
//}
//
//void CVShaderProgram::getUniforms() {
//	int32_t count = activeUniformCount();
//	for( int32_t i = 0; i < count; i++ ) {
//		GLsizei bufSize = 128;
//		
//		GLint vSize;
//		GLenum vType;
//		char vName[ bufSize ];
//		
//		glGetActiveUniform( programId_, i, bufSize, NULL, &vSize, &vType, ( GLchar * )&vName );
//		CVString key( vName );
//		uniforms_.insert( CVGLSLVariablePair( key, i ) );
//	}
//}

CVString CVShaderProgram::description() const {
	return CVString(); // TODO : description
}

CFXMLNodeRef CVShaderProgram::XMLNode() {
	CFStringRef  attr[ 2 ] = { 
		CFSTR( "uuid" ), 
		CFSTR( "identifier" ) 
	};
	
	CFMutableDictionaryRef dict = CFDictionaryCreateMutable( kCFAllocatorDefault, 2, NULL, NULL );
	CFDictionaryAddValue( dict, attr[ 0 ], this->uuidString().utf8String() );
	CFDictionaryAddValue( dict, attr[ 1 ], this->name().stringRef() );
	
	CFXMLElementInfo info;
	info.attributes = CFDictionaryCreateCopy( kCFAllocatorDefault, dict );
	info.attributeOrder = CFArrayCreate( kCFAllocatorDefault, ( const void ** )attr, 2, NULL );
	info.isEmpty = static_cast<Boolean>( ( fragmentShaders_.empty() && geometryShaders_.empty() && vertexShaders_.empty() ) ? true : false );
	
	CFXMLNodeRef node = CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeElement, CFSTR( "shaderprogram" ), &info, kCFXMLNodeCurrentVersion );
	
	return node;
}

CFXMLTreeRef CVShaderProgram::XMLTree() {
	CFXMLNodeRef node = this->XMLNode();
	CFXMLTreeRef tree = CFXMLTreeCreateWithNode( kCFAllocatorDefault, node );
	
	// Get Fragment Shaders
	for( size_t i = 0; i < fragmentShaders_.size(); ++i ) {
		CFXMLTreeRef child = fragmentShaders_[ i ]->XMLTree();
		CFTreeAppendChild( tree, child );
		CFRelease( child );
	}
	
	// Get Geometry Shaders
	for( size_t i = 0; i < geometryShaders_.size(); ++i  ) {
		CFXMLTreeRef child = geometryShaders_[ i ]->XMLTree();
		CFTreeAppendChild( tree, child );
		CFRelease( child );
	}
	
	// Get Vertex Shaders
	for( size_t i = 0; i < vertexShaders_.size(); ++i  ) {
		CFXMLTreeRef child = vertexShaders_[ i ]->XMLTree();
		CFTreeAppendChild( tree, child );
		CFRelease( child );
	}
	
	CFRelease( node );
	
	return tree;
}
