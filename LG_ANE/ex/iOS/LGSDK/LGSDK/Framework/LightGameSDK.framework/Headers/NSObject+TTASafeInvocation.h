//
//  NSObject+TTASafeInvocation.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 5/3/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface NSObject (tta_SafeInvocation)

- (id)tta_safePerformSelector:(SEL)aSelector withObjects:(NSArray *)args;

- (id)tta_safePerformSelector:(SEL)aSelector withObject:(id)object withPrimitive:(void *)pointer;

- (id)tta_safePerformSelector:(SEL)aSelector withPrimitive:(void *)pointer;

- (id)tta_safePerformSelector:(SEL)aSelector withPrimitive:(void *)pointer withObjects:(NSArray *)args;

- (id)tta_safePerformSelector:(SEL)aSelector withPrimitive:(void *)pointer1 withPrimitive:(void *)pointer2;

@end
