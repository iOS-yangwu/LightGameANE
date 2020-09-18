//
//  ToutiaoOpenSDKThirdApp.h
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//当前接入SDK的App信息
@interface ToutiaoOpenSDKThirdApp : NSObject

@property (nonatomic, strong) NSString *appId;

+ (ToutiaoOpenSDKThirdApp *)sharedInstance;

@end

NS_ASSUME_NONNULL_END

