/*
 *  CVShader.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVShader_
#define _CVShader_

#include "CVGraphicsIncludes.h"
#include "CVGraphicsException.h"

namespace CV {
	
	typedef enum {
		kCVGeometryShaderType = 0,
		kCVVertexShaderType = GL_VERTEX_SHADER,
		kCVFragmentShaderType = GL_FRAGMENT_SHADER
	} CVGLShaderType;
	
	class CVShader : public CVObject, public CVUnique, public CVNamed {
		CVRTTIDeclare()
		
	private:
		GLuint		shaderId_;
		CVString 	shaderSource_;
		CVString	shaderLog_;

	public:
		static CVShader * shaderFromSource( CVString path, GLenum type = kCVVertexShaderType );
		
		CVShader();
		virtual ~CVShader();
		
		GLuint shaderId() const;
		GLint shaderType() const;
		
		const CVString & source() const;
		void setSource( const CVString &src );
		
		bool compile() const;
		CVString log();
		
		bool isFlaggedForDeletion() const;
		
		CVString description() const;
		virtual CFXMLNodeRef XMLNode();
		virtual CFXMLTreeRef XMLTree();
	};
	
	class CVGLSLCompileException : public CVGraphicsException {};
	
}

#endif // _CVShader_
