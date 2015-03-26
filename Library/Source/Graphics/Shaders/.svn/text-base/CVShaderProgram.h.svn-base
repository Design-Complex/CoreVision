/*
 *  CVShaderProgram.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVShaderProgram_
#define _CVShaderProgram_

#include "CVBase.h"
#include "CVShader.h"
#include "CVGeometryShader.h"

namespace CV {
	
	typedef std::map<CVString, GLint> CVGLSLVariableMap;
	typedef std::pair<CVString, GLint> CVGLSLVariablePair;
	
	class CVFragmentShader;
	class CVGeometryShader;
	class CVVertexShader;
	
	class CVShaderProgram : public CVObject, public CVUnique, public CVNamed {
		CVRTTIDeclare()
		
	private:
		CVPrivateCopyAndAssign( CVShaderProgram );
		
		GLuint programId_;
		
		std::vector<CVFragmentShader *>	fragmentShaders_;
		std::vector<CVGeometryShader *>	geometryShaders_;
		std::vector<CVVertexShader *>	vertexShaders_;
		
//		CVGLSLVariableMap uniforms_;
//		CVGLSLVariableMap attributes_;
		
		CVString programLog_;
		
		void getLog();
		
//		inline void getAttributes();
//		inline GLint activeAttributeCount();
//		
//		inline void getUniforms();
//		inline GLint activeUniformCount();
		
	public:
		CVShaderProgram();
		CVShaderProgram( CVFragmentShader & frag, CVVertexShader & vert  );
		virtual ~CVShaderProgram();
		
		GLuint programId() const;
		
		CVShaderProgram & attach( CVVertexShader & vs );
		CVShaderProgram & attach( CVFragmentShader & fs );
		CVShaderProgram & attach( CVGeometryShader & gs );
		
		CVShaderProgram & detach( const CVShader & shader );
		CVShaderProgram & link();
		
		CVString & log();
		
		bool isFlaggedForDeletion();
		bool isValid();
		bool isLinked();
		
		CVShaderProgram & enable();
		CVShaderProgram & disable();
		
		virtual CVString description() const;
		virtual CFXMLNodeRef XMLNode();
		virtual CFXMLTreeRef XMLTree();
		
	};
	
	class CVGLSLCompatibilityException : public CVCompatibilityException {};
	
}

#endif // _CVShaderProgram_
