//
//  BDTuringSwizzle.h
//  BDTuring
//
//  Created by bob on 2019/8/30.
//

#import <Foundation/Foundation.h>
#import <objc/message.h>

NS_ASSUME_NONNULL_BEGIN

extern IMP turing_swizzle_instance_methodWithBlock(Class c, SEL origSEL, id block);

NS_ASSUME_NONNULL_END
