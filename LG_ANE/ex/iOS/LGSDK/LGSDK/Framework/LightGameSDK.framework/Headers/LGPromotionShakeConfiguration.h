//
//  LGPromotionTranslationConfiguration.h
//  LightGameSDK
//
//  Created by peiziming on 2019/5/23.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import "LGPromotionBehaviorConfiguration.h"
#import <UIKit/UIKit.h>

@interface LGPromotionShakeConfiguration : LGPromotionBehaviorConfiguration

/**
 *  交叉推广页面显示坐标点，如果设置成（0，0）则起始点位手机左上角。如果接入方传如屏幕外的坐标，则会做修正，以供正常显示。
 */
@property (nonatomic, assign) CGPoint origin;

@end
