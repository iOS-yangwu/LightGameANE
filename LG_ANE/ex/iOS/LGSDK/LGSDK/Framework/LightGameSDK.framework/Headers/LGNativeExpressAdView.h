//
//  LGNativeExpressAdView.h
//  LightGameSDK
//
//  Created by wangchao on 2019/10/10.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGNativeExpressAdView : UIView

/**
 * Whether render is ready
 */
@property (nonatomic, assign, readonly) BOOL isReady;

/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 required
 */
- (void)render;


@end

NS_ASSUME_NONNULL_END
