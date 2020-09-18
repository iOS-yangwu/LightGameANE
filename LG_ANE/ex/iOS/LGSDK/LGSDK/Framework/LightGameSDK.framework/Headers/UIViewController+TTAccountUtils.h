//
//  UIViewController+TTAccountUtils.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/2/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (TTAccountUtils)

+ (UIViewController *)tta_topViewController;

+ (UIViewController *)tta_topViewControllerForController:(UIViewController *)rootViewController;
@end

NS_ASSUME_NONNULL_END
