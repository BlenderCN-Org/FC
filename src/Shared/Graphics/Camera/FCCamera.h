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

#ifndef FCCamera_h
#define FCCamera_h

#include "Shared/Core/FCCore.h"
#include "Shared/Graphics/FCViewport.h"

class FCCamera {
public:
	
	FCCamera();
	virtual ~FCCamera();
	
	void Update( float realTime, float gameTime );
	
	void SetPosition( const FCVector3f& pos, float t );
	void SetTarget( const FCVector3f& pos, float t );
	void SetOrthographicProjection( float x, float y );
	void SetPerspectiveProjection( float x, float y );
	
	FCViewport* GetViewport(){ return &m_viewport; }
	
	enum eProjectionType {
		kProjectionTypeUnknown,
		kProjectionTypeOrthographic,
		kProjectionTypePerspective
	};
	
private:
//	FCVector3f	m_target;	// Should be moved into viewport
	
	eProjectionType	m_projectionType;
	FCViewport	m_viewport;

	// position interpolation
	
	bool		m_positionInterpActive;
	FCVector3f	m_positionStartPos;
	FCVector3f	m_positionEndPos;
	FCVector3f	m_positionDeltaPos;
	float		m_positionInterp;
	float		m_positionDuration;
	
	// target interpolation
	
	bool		m_targetInterpActive;
	FCVector3f	m_targetStartPos;
	FCVector3f	m_targetEndPos;
	FCVector3f	m_targetDeltaPos;
	float		m_targetInterp;
	float		m_targetDuration;
};

#endif
