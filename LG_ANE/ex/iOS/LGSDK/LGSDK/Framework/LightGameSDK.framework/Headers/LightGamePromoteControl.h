//
//  LightGamePromoteCreator.h
//  LightGameSDK
//
//  Created by peiziming on 2019/5/23.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGPromotionShakeConfiguration.h"

@interface LightGamePromoteControl : NSObject

/**
 * 创建推广弹窗，并初始化平移动画参数
 *
 * @param configuration 推广页面动画参数设置类
 * 创建的弹窗固定大小为(140, 210)
 */
- (void)promotionAlertWindow:(LGPromotionShakeConfiguration *)configuration;

/**
 * 显示推广弹窗
 */
- (void)show;

/**
 * 隐藏推广弹窗
 */
- (void)hide;

@end
