/*
 Copyright (C) 2011-2012 by Martin Linklater
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#ifndef CR1_FCGLShaderProgramFlatUnlit_h
#define CR1_FCGLShaderProgramFlatUnlit_h

#include "GLES/FCGLShaderProgram.h"

class FCGLShaderProgramFlatUnlit : public FCGLShaderProgram
{
public:
	FCGLShaderProgramFlatUnlit( FCGLShaderRef vertexShader, FCGLShaderRef fragmentShader )
	: FCGLShaderProgram( vertexShader, fragmentShader )
	{
		m_stride = 16;
		m_positionAttribute = m_attributes[ "position" ];
		m_diffuseColorAttribute = m_attributes[ "diffuse_color" ];
	}
	
	virtual ~FCGLShaderProgramFlatUnlit()
	{
		
	}
	
	void BindUniformsWithMesh( FCGLMesh* mesh )
	{
	}
	
	void BindAttributes()
	{
		FCglVertexAttribPointer( m_positionAttribute->Location(), 3, GL_FLOAT, GL_FALSE, m_stride, (void*)0);
		FCglEnableVertexAttribArray( m_positionAttribute->Location() );
		
		FCglVertexAttribPointer( m_diffuseColorAttribute->Location(), 4, GL_UNSIGNED_BYTE, GL_TRUE, m_stride, (void*)20);
		FCglEnableVertexAttribArray( m_diffuseColorAttribute->Location() );
	}
	
	FCGLShaderAttributeRef	m_positionAttribute;
	FCGLShaderAttributeRef	m_diffuseColorAttribute;
};

#endif
