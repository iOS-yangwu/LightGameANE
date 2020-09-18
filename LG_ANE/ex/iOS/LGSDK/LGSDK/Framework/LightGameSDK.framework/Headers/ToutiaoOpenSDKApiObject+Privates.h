//
//  ToutiaoOpenSDKApiObject+Privates.h
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import "ToutiaoOpenSDKApiObject.h"

NS_ASSUME_NONNULL_BEGIN

NSDictionary *ToutiaoOpenSDKProductInfo(void);

#pragma mark - ToutiaoOpenSDKBaseReq

@interface ToutiaoOpenSDKBaseReq ()

/**
 Unique id flag the request.
 */
@property (nonatomic, copy, readwrite, nonnull) NSString *requestId;

/**
 今日头条App发送请求的id
 */
@property (nonatomic, copy, readwrite, nonnull) NSString *provider_requestId;

/**
 语言
 */
@property (nonatomic, copy, readwrite, nullable) NSString *lang;

/**
 国家
 */
@property (nonatomic, copy, readwrite, nullable) NSString *country;

/**
 今日头条打开第三方应用使用的URL 或 第三方程序发送请求给平台程序使用的URL
 */
@property (nonatomic, strong, readwrite, nullable) NSURL *originalURL;

/**
 请求初始创建时间
 */
@property (nonatomic, strong, readwrite, nonnull) NSDate *createDate;

/**
 请求发送时间
 */
@property (nonatomic, strong, readwrite, nonnull) NSDate *sendDate;

/**
 请求发送->收到对应响应的时间
 */
@property (nonatomic, strong, readwrite, nonnull) NSDate *endDate;

@end

#pragma mark - ToutiaoOpenSDKBaseResp

@interface ToutiaoOpenSDKBaseResp ()

/**
 Unique id flag the response.
 */
@property (nonatomic, copy, readwrite, nonnull) NSString *responseId;
@property (nonatomic, copy, readwrite, nullable) NSString *lang;
@property (nonatomic, copy, readwrite, nullable) NSString *country;
@property (nonatomic, strong, readwrite, nonnull) ToutiaoOpenSDKBaseReq *originalBaseReq;

@end

#pragma mark - ToutiaoOpenSDKSendAuthResp

@interface ToutiaoOpenSDKSendAuthResp ()

@property (nonatomic, copy, readwrite, nullable) NSString *code;
@property (nonatomic, copy, readwrite, nullable) NSString *state;

@end

NS_ASSUME_NONNULL_END

