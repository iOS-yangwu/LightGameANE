//
//  LGConfigSplashAdView.h
//  LightGameSDK
//
//  Created by bytedance on 2020/6/17.
//  Copyright © 2020 byteDance. All rights reserved.
//

#import <LightGameSDK/LightGameSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LGConfigSplashAdViewDelegate <NSObject>

- (void)strategySplashAdTriggerWithCode:(int)code message:(NSString *)message;

@end

@interface LGConfigSplashAdView : BUSplashAdView

/// strategyDelegate 回调
/// When triggering the splash Ad corresponding to the group strategy,
/// the method will be called back with the  code and message
@property (nonatomic, weak) id<LGConfigSplashAdViewDelegate> strategyDelegate;

/// 根据配置判断是否可以展示广告
- (BOOL)canShowAdAccordingToConfig;

@end

NS_ASSUME_NONNULL_END
