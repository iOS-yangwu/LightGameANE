//
//  TTAccountAuthResponse.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 2/9/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountAuthResponse : NSObject

/** 区分是通过第三方自带的SDK还是自定义WAP进行授权 */
@property (nonatomic, assign, getter=isSDKAuth) BOOL sdkAuth;

/** 区分是通过SSO还是WAP SSO进行授权 */
@property (nonatomic, assign, getter=isSSOAuth) BOOL ssoAuth;

/** 第三方授权平台名称 */
@property (nonatomic,   copy, nonnull) NSString *platformName;

/** 第三方授权平台在头条用户平台的唯一标识；【用来替代platformName和appID】 */
@property (nonatomic,   copy, nonnull) NSString *platformAppId;

/** 第三方授权平台类型<TTAccountAuthType> */
@property (nonatomic, assign) NSInteger platformType;

/** 客户端在第三方平台注册的应用唯一标识 */
@property (nonatomic,   copy, nullable) NSString *appId;

/** 客户端在第三方平台注册的应用密钥 */
@property (nonatomic,   copy, nullable) NSString *appSecret;

/** 请求向第三方平台申请的权限 */
@property (nonatomic,   copy, nullable) NSString *scope;

/** 自定义用户信息 */
@property (nonatomic, copy, nullable) NSDictionary *customUserInfo;

/** 是否推荐App给好友并关注App官方 */
@property (nonatomic, assign) BOOL shareToSnsUser;

/** 错误码 */
@property (nonatomic, assign) NSInteger errCode;

/** 错误消息 */
@property (nonatomic,   copy, nullable) NSString *errmsg;

@end

NS_ASSUME_NONNULL_END
