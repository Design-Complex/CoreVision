/*
 *  CVShader.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVShader.h"
#include "CVFragmentShader.h"
#include "CVGeometryShader.h"
#include "CVVertexShader.h"

using namespace CV;

CVRTTIDefine( CVShader, CVObject )

CVShader * CVShader::shaderFromSource( CVString path, GLenum type ) {
	try {
		// Open the file
		std::ifstream is( path.utf8String(), std::ifstream::in );
		
		// Get length of file
		is.seekg( 0, std::ios_base::end );
		int32_t count = is.tellg();
		is.seekg( 0, std::ios::beg );
		
		// Create the string buffer
		std::string tmp( count, '0' );
		
		// Read the data as a block
		is.read( &tmp[ 0 ], count );
		
		// Create a new shader object
		CVShader *sh;
		switch( type ) {
			case kCVFragmentShaderType:
				sh = new CVFragmentShader();
				break;
			case kCVVertexShaderType:
				sh = new CVVertexShader();
				break;
			case kCVGeometryShaderType: // TODO: Geometry Shaders
			default:
				break;
		}
		sh->setSource( tmp.c_str() ); // TODO: optimize this
		
		return sh;
		
	} CVThrowAllExceptions()
}

CVShader::CVShader() try : 
CVObject::CVObject(),
CVUnique::CVUnique( "" ),
shaderId_( 0 ),
shaderSource_(),
shaderLog_() {

} CVThrowAllExceptions()

CVShader::~CVShader() {
	glDeleteShader( shaderId_ );
	
	shaderId_ = 0;
}

GLuint CVShader::shaderId() const {
	return shaderId_;
}

GLint CVShader::shaderType() const {
	GLint status;
	
	glGetShaderiv( shaderId_, GL_SHADER_TYPE, &status );
	
	return status;
}

const CVString & CVShader::source() const {
	return shaderSource_;
}

void CVShader::setSource( const CVString &src ) {
	try {
		shaderSource_ = src;
		
		const GLchar * str = shaderSource_.utf8String();
				
		//const GLchar **programPtr = ( const GLchar ** )&(  );
		glShaderSource( shaderId_, 1, &str, 0 );
	} CVThrowAllExceptions()
}

bool CVShader::compile() const {
	GLint status;
	
	glCompileShader( shaderId_ );
	glGetShaderiv( shaderId_, GL_COMPILE_STATUS, &status );
		
	return static_cast<bool>( status );
}

CVString CVShader::log() {
	GLint status;
	
	try {
		glGetShaderiv( shaderId_, GL_INFO_LOG_LENGTH, &status );
		
		GLchar * str = ( GLchar * )malloc( sizeof( GLchar ) * status + 1 );
		if( str == NULL )
			std::bad_alloc();
		
		glGetShaderInfoLog( shaderId_, status, &status, str );
		
		return str;
				
	} CVThrowAllExceptions()
}

bool CVShader::isFlaggedForDeletion() const {
	GLint status;
	
	glGetShaderiv( shaderId_, GL_DELETE_STATUS, &status );
	
	return ( status == GL_TRUE ) ? true : false;
}

CVString CVShader::description() const {
	return shaderSource_;
}

CFXMLNodeRef CVShader::XMLNode() {
	// Type
	CFStringRef type;
	switch( this->shaderType() ) {
		case kCVVertexShaderType:
			type = CFSTR( "vertex" );
			break;
		case kCVFragmentShaderType:
			type = CFSTR( "fragment" );
			break;
		default:
			type = CFSTR( "unknown" );
			break;
	}
	
	CFStringRef  attr[ 3 ] = { 
		CFSTR( "uuid" ), 
		CFSTR( "identifier" ), 
		CFSTR( "type" ) 
	};
	
	CFMutableDictionaryRef dict = CFDictionaryCreateMutable( kCFAllocatorDefault, 2, NULL, NULL );
	CFDictionaryAddValue( dict, attr[ 0 ], this->uuidString().stringRef() );
	CFDictionaryAddValue( dict, attr[ 1 ], this->name().stringRef() );
	CFDictionaryAddValue( dict, attr[ 2 ], type );
	
	CFXMLElementInfo info;
	info.attributes = CFDictionaryCreateCopy( kCFAllocatorDefault, dict );
	info.attributeOrder = CFArrayCreate( kCFAllocatorDefault, ( const void ** )attr, 3, NULL );
	info.isEmpty = false;
	
	CFXMLNodeRef node = CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeElement, CFSTR( "shader" ), &info, kCFXMLNodeCurrentVersion );
	
	return node;
}

CFXMLTreeRef CVShader::XMLTree() {
	CFXMLNodeRef node = this->XMLNode();
	CFXMLTreeRef tree = CFXMLTreeCreateWithNode( kCFAllocatorDefault, node );
	
	CFStringRef code = this->shaderSource_.stringRef();
	CFXMLTreeRef src = CFXMLTreeCreateWithNode( kCFAllocatorDefault, CFXMLNodeCreate( kCFAllocatorDefault, kCFXMLNodeTypeText, code, NULL, kCFXMLNodeCurrentVersion ) );
	CFTreeAppendChild( tree, src );
	
	CFRelease( node );
	CFRelease( code );
	CFRelease( src );
	
	return tree;
}
