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

// TODO: Needs its own center outside of physics

#import <Foundation/Foundation.h>

#import "FCActorSystem.h"

#import "FCCore.h"
#import "FCGraphics.h"

#include "Shared/Physics/FCPhysics.h"
#include "Shared/Core/FCXML.h"
#include "FCResource.h"

#if defined (FC_GRAPHICS)
@class FCModel;
#endif


@protocol FCActorBase

-(id)initWithDictionary:(NSDictionary*)dictionary 
				   body:(NSDictionary*)bodyDict 
				  model:(NSDictionary*)modelDict 
			   resource:(FCResourcePtr)res 
				   name:(NSString*)name
				 handle:(FCHandle)handle;

-(void)dealloc;

@optional
-(void)update:(float)gameTime;
-(void)render;
-(BOOL)needsUpdate;
-(BOOL)needsRender;
-(BOOL)respondsToTapGesture;
-(float)radius;
-(BOOL)posWithinBounds:(FCVector2f)pos;

@end

@interface FCActor : NSObject <FCActorBase> 
{
	FCHandle			_handle;
	NSString*			_name;
	NSString*			_id;			// deprecate
	NSString*			_fullName;
	FCXMLNode			_createXML;
#if defined (FC_GRAPHICS)
	FCModel*			_model;
#endif
#if defined (FC_PHYSICS)
	FCPhysics2DBodyPtr	_physicsBody;
#endif
}
@property(nonatomic) FCHandle handle;
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong, readonly) NSString* Id;
@property(nonatomic, strong) NSString* fullName;
@property(nonatomic, readonly) FCXMLNode createXML;
#if defined (FC_GRAPHICS)
@property(nonatomic, strong, readonly) FCModel* model;
#endif
#if defined (FC_PHYSICS)
@property(nonatomic, readonly) FCPhysics2DBodyPtr	physicsBody;
#endif

-(id)initWithXML:(FCXMLNode)xml 
			body:(FCXMLNode)bodyXML 
		   model:(FCXMLNode)modelXML 
		resource:(FCResourcePtr)res
			name:(NSString*)name
		  handle:(FCHandle)handle;

// TODO: Get these two into a property
-(void)setPosition:(FCVector3f)pos;
-(FCVector3f)position;

-(void)setLinearVelocity:(FCVector3f)vel;
-(FCVector3f)linearVelocity;

-(void)setDebugModelColor:(FCColor4f)color;

#if defined (FC_PHYSICS)
-(void)applyImpulse:(FCVector3f)impulse atWorldPos:(FCVector3f)pos;
-(FCVector3f)getCenter;
#endif
@end

