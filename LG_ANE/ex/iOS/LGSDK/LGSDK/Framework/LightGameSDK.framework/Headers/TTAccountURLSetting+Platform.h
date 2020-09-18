//
//  TTAccountURLSetting+Platform.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 2/8/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import "TTAccountURLSetting.h"



NS_ASSUME_NONNULL_BEGIN

/**
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=15141286#OAUTH2授权登录-1.登录地址
 *         https://wiki.bytedance.net/pages/viewpage.action?pageId=52903405
 *         https://wiki.bytedance.net/pages/viewpage.action?pageId=53809581#id-用户登录相关API-WAPOAUTHAPI
 */
@interface TTAccountURLSetting (TTThirdPartyPlatform)

#pragma mark - Full URL

/**
 第三方平台状态校验接口

 @return url
 https://docs.bytedance.net/doc/Gm0up2wvotBijAiBX1kFcd
 */
+ (NSString *)TTASNSAuthLoginSuggestURLString;

/** 使用第三方SDK(SNSSDK)进行第三方平台授权相关的接口 */

/// 只允许单帐号登录的情况下调用，如果当前是登录状态，走绑定逻辑；如果当前非登录态，走登录逻辑
+ (NSString *)TTASNSSDKAuthCallbackURLString;

/// 三方平台授权成功后走登录逻辑，内部app之间的相互授权，帐号不共享
+ (NSString *)TTASNSSDKAuthCallbackLoginURLString;

/// 三方平台授权成功后走登录逻辑，内部app之间的相互授权，app 间共享一个帐号
+ (NSString *)TTASNSSDKAuthShareUserInfoCallbackURLString;

/// 三方平台授权成功后走登录逻辑 https://doc.bytedance.net/docs/177/266/3433/
+ (NSString *)TTASNSSDKAuthCallbackLoginOnlyURLString;

/** 使用第三方SDK(SNSSDK)进行第三方平台授权,不产生新的用户 */
+ (NSString *)TTASNSSDKAuthShareUserInfoCallbackURLString;

/// 是否支持抖音快速登陆
+ (NSString *)TTAccountCanAwemeQuickLoginURLString;

/// 带手机号的三方授权绑定登陆
+ (NSString *)TTASNSSDKAuthLoginWithBindmobile;

/// 三方绑定并同步三方手机号
+ (NSString *)TTASNSSDKAuthBindWithMobile;

/// 第三方绑定
+ (NSString *)TTASNSSDKAuthCallbackBindURLString;

/// 第三方换绑
+ (NSString *)TTASNSSDKSwitchBindURLString;

/** 使用自定义WAP进行第三方平台授权相关的接口 */
+ (NSString *)TTACustomWAPLoginURLString;

+ (NSString *)TTACustomWAPLoginSuccessURLString;

+ (NSString *)TTACustomWAPLoginContinueURLString;

+ (NSString *)TTAShareAppToSNSPlatformURLString;



#pragma mark - URL Path

/** SNSSDK -- 第三方平台SDK */
/** 使用第三方平台自带SDK授权成功后，调用web服务端绑定头条用户信息的接口 */
+ (NSString *)TTASNSSDKAuthCallbackURLPathString;

/** 使用第三方平台自带SDK授权成功后，在和头条用户信息绑定时发现已经被绑定，进行解绑的接口 */
+ (NSString *)TTASNSSDKSwitchBindURLPathString;

/** 使用自定义WAP授权第三方平台时请求web服务器的接口 */
+ (NSString *)TTACustomWAPLoginURLPathString;

/** 使用自定义WAP授权第三方平台时，第三方平台调用的回调地址 */
+ (NSString *)TTACustomWAPLoginSuccessURLPathString;

/** 使用自定义WAP授权第三方平台时，可能出现已绑定的错误，此时用户授权已完成，所以用auth_token来保持用户授权状态，在用户做出选择后不用再次授权就可以登录 (解绑) */
+ (NSString *)TTACustomWAPLoginContinueURLPathString;

+ (NSString *)TTAShareAppToSNSPlatformURLPathString;

@end



@interface TTAccountURLSetting (PlatformInterfaceV2)

#pragma mark - URL PATH

//  第三方登录: 主要获取第三方wap授权页面
+ (NSString *)TTAPlatformAuthWapLoginV2URLPathString;

//  第三方登录
+ (NSString *)TTAPlatformAuthLoginV2URLPathString;

/// 老用户登录，新用户则返回profile_key https://doc.bytedance.net/docs/177/266/3433/
+ (NSString *)TTAPlatformAuthLoginOnlyV2URLPathString;

/** 使用第三平台授权后成功后，不产生新的用户，直接返回第三方平台的用户信息 */
+ (NSString *)TTAPlatformAuthShareUserInfoURLPathString;

@end

NS_ASSUME_NONNULL_END
