//
//  BDTuringUIHelper.h
//  BDTuring
//
//  Created by bob on 2019/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class UIWindow;

@interface BDTuringUIHelper : NSObject

+ (UIWindow *)keyWindow;
+ (CGFloat)statusBarHeight;

@end

NS_ASSUME_NONNULL_END
