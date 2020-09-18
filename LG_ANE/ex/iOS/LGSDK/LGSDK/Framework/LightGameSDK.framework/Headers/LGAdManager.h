//
//  LightGameAd.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/8.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface LGAdManager : NSObject

@property (nonatomic, copy, readonly, class) NSString *SDKVersion;

/**
 Register the App key that’s already been applied before requesting an ad from TikTok Audience Network.
 @param appID : the unique identifier of the App
 */
+ (void)setAppID:(NSString *)appID;

/**
 Configure development mode.
 @param level : default BUAdSDKLogLevelNone
 */
+ (void)setLoglevel:(LGAdSDKLogLevel)level;

/// Set the user's keywords, such as interests and hobbies, etc.
+ (void)setUserKeywords:(NSString *)keywords;

/* set additional user information. Must follow the format.
data格式 : @"[{\"name\":\"device_id\",\"value\":\"62271333038\"},{\"name\":\"AAA\",\"value\":\"222\"}]"*/
+ (void)setUserExtData:(NSString *)data;

/// Set whether the app is a paid app, the default is a non-paid app
+ (void)setIsPaidApp:(BOOL)isPaidApp;

+ (NSString *)appID;
+ (BOOL)isPaidApp;

@end

NS_ASSUME_NONNULL_END
