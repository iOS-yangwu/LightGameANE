//
//  BDWebAuthViewController.h
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ToutiaoOpenSDKApi.h"

@protocol ToutiaoOpenSDKWebAuthViewDelegate <NSObject>

- (void)finishWithResp:(ToutiaoOpenSDKSendAuthResp *)resp sdkDelegate:(id<ToutiaoOpenSDKApiDelegate>)sdkDelegate;

@end

@interface ToutiaoOpenSDKWebAuthViewController :UIViewController

@property (nonatomic, strong) ToutiaoOpenSDKSendAuthReq *req;
@property (nonatomic, weak) id<ToutiaoOpenSDKApiDelegate> sdkDelegate;
@property (nonatomic, weak) id<ToutiaoOpenSDKWebAuthViewDelegate> authDelegate;

- (void)reload;

@end

