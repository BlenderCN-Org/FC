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

#import "FCPersistentData_apple.h"
#include <string>
#include "Shared/Core/FCCore.h"

void plt_FCPersistentData_Load();
void plt_FCPersistentData_Save();
void plt_FCPersistentData_Clear();
void plt_FCPersistentData_Print();
void plt_FCPersistentData_SetValueForKey( std::string value, std::string key );
std::string plt_FCPersistentData_ValueForKey( std::string key );

void plt_FCPersistentData_Load()
{
	[[FCPersistentData_apple instance] load];
}

void plt_FCPersistentData_Save()
{
	[[FCPersistentData_apple instance] save];	
}

void plt_FCPersistentData_Clear()
{
	[[FCPersistentData_apple instance] clear];	
}

void plt_FCPersistentData_Print()
{
	[[FCPersistentData_apple instance] print];	
}

void plt_FCPersistentData_SetValueForKey( std::string value, std::string key )
{
	[[FCPersistentData_apple instance].dataRoot setValue:[NSString stringWithUTF8String:value.c_str()] forKey:[NSString stringWithUTF8String:key.c_str()]];
}

std::string plt_FCPersistentData_ValueForKey( std::string key )
{
	NSString* ret = [[FCPersistentData_apple instance].dataRoot valueForKey:[NSString stringWithUTF8String:key.c_str()]];
		
	if (ret) {
		FC_ASSERT( [ret isKindOfClass:[NSString class]] );
		return [ret UTF8String];
	} else {
		return "";
	}
}

@implementation FCPersistentData_apple
@synthesize dataRoot = _dataRoot;

+(FCPersistentData_apple*)instance
{
	static FCPersistentData_apple* s_pInstance;
	if (!s_pInstance) {
		s_pInstance = [[FCPersistentData_apple alloc] init];
	}
	return s_pInstance;
}

-(id)init
{
	self = [super init];
	if (self) {
	}
	return self;
}

-(NSString*)filename
{
	NSArray* documentDirectories = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString* documentDirectory = [documentDirectories objectAtIndex:0];
	return [documentDirectory stringByAppendingPathComponent:@"savedata"];
}

-(void)load
{
	self.dataRoot = [NSKeyedUnarchiver unarchiveObjectWithFile:[self filename]];
	
	if (!self.dataRoot) {
		self.dataRoot = [NSMutableDictionary dictionary];
	}	
}

-(void)save
{
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSKeyedArchiver archiveRootObject:self.dataRoot toFile:[self filename]];
	});	
}

-(void)clear
{
	self.dataRoot = [NSMutableDictionary dictionary];
	[self save];
}

-(void)print
{
	
}

@end