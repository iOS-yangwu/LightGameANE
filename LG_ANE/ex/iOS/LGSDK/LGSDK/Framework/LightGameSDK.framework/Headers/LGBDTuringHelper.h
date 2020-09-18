//
//  BDTuringHelper.m
//  LightGameSDK
//
//  Created by wangchao on 2019/12/24.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import "LGBDTuringHelper.h"
#import "LGSDKInitHelper.h"
// 滑块验证码
#import "BDTuring.h"


typedef void(^LGVerificationViewCallBack)(BDTuringVerifyStatus verifyStatus, NSString * _Nullable token, NSString * _Nullable mobile);

@interface LGBDTuringHelper : LGSDKInitHelper

@property(copy, nonatomic)LGVerificationViewCallBack _Nullable verificationViewCallBack;

- (LGBDTuringHelper *_Nonnull)initSDK:(NSString *_Nonnull)appID channel:(NSString *_Nonnull)channel appName:(NSString *_Nonnull)appName;

//  显示验证码
- (void)popupVerificationView:(UIView *_Nullable)view;

@end
