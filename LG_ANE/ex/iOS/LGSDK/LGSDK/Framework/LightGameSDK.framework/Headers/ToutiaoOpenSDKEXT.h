//
//  ToutiaoOpenSDKEXT.h
//  内部SDK扩展
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import "ToutiaoOpenSDKApi.h"

@protocol ToutiaoOpenSDKApiDelegate;

//扩展协议接口定义如下，请直接实现在实现了ToutiaoOpenSDKApiDelegate的类中
@protocol ToutiaoOpenSDKApiDelegateEXT <NSObject>

@optional

//web授权页行为埋点，接入方可通过url里面的参数埋点
- (void)webAuthLog:(NSURL *)url;

@end

@interface ToutiaoOpenSDKApi (EXT)

//可通过webFirst选择优先使用web授权
+ (BOOL)sendAuthReq:(ToutiaoOpenSDKSendAuthReq*)req viewController:(UIViewController*)viewController delegate:(id<ToutiaoOpenSDKApiDelegate>)delegate webFirst:(BOOL)webFirst;

@end

