//
//  LGPromotionBehaviorConfiguration.h
//  LightGameSDK
//
//  Created by peiziming on 2019/5/23.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/CAAnimation.h>
#import <UIKit/UIKit.h>
@class LGPromotionView;

@protocol LGPromotionBehaviorConfiguration <NSObject>

- (CAAnimation *)configurationShowAnimation:(UIView *)view;
- (CAAnimation *)configurationHideAnimation:(UIView *)view;

- (LGPromotionView *)createPromotionView;

// 目前先写在这里
- (void)statusBarOrientationChange:(LGPromotionView *)promotion;

@end

@interface LGPromotionBehaviorConfiguration : NSObject <LGPromotionBehaviorConfiguration>

/**
 * displayVC 用于显示的视图控制器，不传则通过presentedViewController查找到最合适的视图控制器
 */
@property (nonatomic, strong) UIViewController *displayVC;

/**
 * superView 用于显示推广视图的view,不传则通过presentedViewController查找到最合适的视图显示
 */
@property (nonatomic, strong) UIView *superView;

@end
