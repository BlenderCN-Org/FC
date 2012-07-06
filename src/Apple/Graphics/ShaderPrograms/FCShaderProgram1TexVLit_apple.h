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

#import "FCShaderProgram_apple.h"

@class FCShader_apple;
@class FCShaderAttribute_apple;

@interface FCShaderProgram1TexVLit_apple : FCShaderProgram_apple {
	
	FCGLShaderUniform*	_ambientUniform;
	FCGLShaderUniform*	_lightColorUniform;
	FCGLShaderUniform*	_textureUniform;
	
	FCShaderAttribute_apple*	_positionAttribute;
	FCShaderAttribute_apple*	_normalAttribute;
	FCShaderAttribute_apple*	_diffuseColorAttribute;
	FCShaderAttribute_apple*	_specularColorAttribute;
	FCShaderAttribute_apple*	_uv1Attribute;
}
@property(nonatomic) FCGLShaderUniform* ambientUniform;
@property(nonatomic) FCGLShaderUniform* lightColorUniform;
@property(nonatomic) FCGLShaderUniform* textureUniform;

@property(nonatomic, strong) FCShaderAttribute_apple* positionAttribute;
@property(nonatomic, strong) FCShaderAttribute_apple* normalAttribute;
@property(nonatomic, strong) FCShaderAttribute_apple* diffuseColorAttribute;
@property(nonatomic, strong) FCShaderAttribute_apple* specularColorAttribute;
@property(nonatomic, strong) FCShaderAttribute_apple* uv1Attribute;

-(id)initWithVertex:(FCShader_apple *)vertexShader andFragment:(FCShader_apple *)fragmentShader;
-(void)bindUniformsWithMesh:(FCMesh_apple*)mesh;
-(void)bindAttributes;
@end
