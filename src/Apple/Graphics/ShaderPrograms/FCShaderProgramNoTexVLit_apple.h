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

#if 0


class FCGLShader;

@interface FCShaderProgramNoTexVLit_apple : FCShaderProgram_apple {
	
	FCGLShaderUniformPtr	_ambientUniform;
	FCGLShaderUniformPtr	_lightColorUniform;
	
	FCGLShaderAttributePtr	_positionAttribute;
	FCGLShaderAttributePtr	_normalAttribute;
	FCGLShaderAttributePtr	_diffuseColorAttribute;
	FCGLShaderAttributePtr	_specularColorAttribute;
}
@property(nonatomic) FCGLShaderUniformPtr ambientUniform;
@property(nonatomic) FCGLShaderUniformPtr lightColorUniform;

@property(nonatomic) FCGLShaderAttributePtr positionAttribute;
@property(nonatomic) FCGLShaderAttributePtr normalAttribute;
@property(nonatomic) FCGLShaderAttributePtr diffuseColorAttribute;
@property(nonatomic) FCGLShaderAttributePtr specularColorAttribute;

-(id)initWithVertex:(FCGLShaderPtr)vertexShader andFragment:(FCGLShaderPtr)fragmentShader;
-(void)bindUniformsWithMesh:(FCMesh_apple*)mesh;
-(void)bindAttributes;
@end
#endif