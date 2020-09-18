//
//  TTAccountAuthLoginManager.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/26/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountAuthDefine.h"
#import "TTAccountAuthProtocol.h"


NS_ASSUME_NONNULL_BEGIN

@interface TTAccountAuthLoginManager : NSObject

#pragma mark - register
/**
 * 注册从第三方应用平台获取AppId
 *
 * @param appId  第三方应用平台申请的appId
 * @param type   第三方平台类型
 */
+ (void)registerAppId:(NSString * _Nonnull)appId
          forPlatform:(TTAccountAuthType)type;

/**
 * 动态注册支持的第三方平台帐号
 *
 * @param cls  第三方平台帐号Class对象
 */
+ (void)registerPlatformAuthAccount:(Class<TTAccountAuthProtocol> _Nonnull)cls;

#pragma mark - handle URL

/**
 * 需要在application:openURL:sourceApplication:annotation:或者application:handleOpenURL(9.0)中调用。
 *
 * @param url 第三方应用打开APP时传递过来的URL
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL * _Nonnull)url;

/**
 *  打开第三方平台,接入谷歌和Facebook在9.0后 必须在application:openURL:url options:中调用该接口
 * @attention 必须在主线程中调用
 *
 * @param   url         第三方应用打开APP时传递过来的URL
 * @param   options     第三方应用打开APP时传递过来的options
 * @return  成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/**
 *  打开第三方平台,接入谷歌和Facebook在8.0系统中 必须在application:openURL:sourceApplication:annotation:中调用该接口
 * @attention 必须在主线程中调用
 *
 * @param   url                     第三方应用打开APP时传递过来的URL
 * @param   sourceApplication       第三方应用打开APP时传递过来的sourceApplication
 * @paran   annotation              第三方应用打开APP是传递过来的annotation
 * @return  成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

#pragma mark - Platform Info

/**
 * 获取平台名称对应类型
 *
 * @param   platformName 第三方应用名称
 * @return  返回平台类型
 */
+ (TTAccountAuthType)accountAuthTypeForPlatform:(NSString * _Nullable)platformName;

/**
 * 获取平台类型的名称
 *
 * @param   type 第三方平台类型
 * @return  返回平台名称
 */
+ (nullable NSString *)platformForAccountAuthType:(TTAccountAuthType)type;

/**
 * 获取第三方平台在头条平台的platformAppId
 *
 * @param   type 第三方平台类型
 * @return  返回平台APPID
 */
+ (nullable NSString *)platformAppIdForAccountAuthType:(TTAccountAuthType)type;

/**
 * 第三方平台是否支持SSO授权登录
 *
 * @param  type       第三方平台类型
 * @return 支持返回YES，否则返回NO
 */
+ (BOOL)canSSOForPlatform:(TTAccountAuthType)type;

/**
 * 第三方平台是否支持WAP授权登录
 *
 * @param  type       第三方平台类型
 * @return 支持返回YES，否则返回NO
 */
+ (BOOL)canWebSSOForPlatform:(TTAccountAuthType)type;

/**
 * 是否支持在自定义容器中对第三方平台进行授权登录
 *
 * @param  type       第三方平台类型
 * @return 支持返回YES，否则返回NO
 */
+ (BOOL)canCustomWebSSOForPlatform:(TTAccountAuthType)type;

/**
 * 第三方应用是否安装
 *
 * @param  type       第三方平台类型
 * @return 安装返回YES，否则返回NO
 */
+ (BOOL)isAppInstalledForPlatform:(TTAccountAuthType)type;

/**
 * 显示的本地第三方应用名称
 *
 * @param  type       第三方平台类型
 * @return 返回第三方应用本地化名称
 */
+ (nonnull NSString *)localizedDisplayNameForPlatform:(TTAccountAuthType)type;

/**
 * 获取第三方应用在App Store上的下载地址
 *
 * @param  type       第三方平台类型
 * @return 存在返回对应安装地址，否则返回nil
 */
+ (nullable NSString *)getAppInstallUrlForPlatform:(TTAccountAuthType)type;

#pragma mark - login
/**
 获取当前第三方平台是否可用。（应对鹅厂的屏蔽）

 @param type 第三方平台类型
 @param completedBlock 请求完成的回调
 */
+ (void)requestLoginSuggestionForPlatform:(TTAccountAuthType)type completion:(TTAccountAuthLoginSuggestCompletedBlock)completedBlock;

/**
 *  只请求第三方登录token等授权新信息,不进行登录逻辑的处理
 *
 * @param type              第三方平台类型
 *  @param useCustomWap     是否使用自定义容器进行授权
 *  @param completedBlock   授权完成回调
 */
+ (void)requestAuthInfoForPlatform:(TTAccountAuthType)type
                inCustomWebView:(BOOL)useCustomWap
                     completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 * 向第三方应用请求授权登录，优先选择使用SDK SSO授权登录
 *
 * @param type              第三方平台类型
 * @param willLoginBlock    授权成功，开始登录回调
 * @param completedBlock    登录完成后的回调
 */
+ (void)requestLoginForPlatform:(TTAccountAuthType)type
                      willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                     completion:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

/**
 * 向第三方应用请求授权登录
 *
 * @param type              第三方平台类型
 * @param useCustomWap      是否使用自定义包装的容器授权登录
 * @param willLoginBlock    授权成功，开始登录回调
 * @param completedBlock    登录完成后的回调
 */
+ (void)requestLoginForPlatform:(TTAccountAuthType)type
                inCustomWebView:(BOOL)useCustomWap
                      willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                     completion:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

/**
 * 使用platformType登录第三方平台应用帐号,与上述API的区别在于，上述接口老用户登录，新用户注册；该接口新用户不会进行注册操作，会返回profileKey
 *
 *  @param type                             第三方平台类型
 *  @param willLoginBlock                   开始登录回调 （仅仅授权成功才调用该回调）
 *  @param completedBlock                   登录完成回调
 */
+ (void)requestLoginOnlyForPlatform:(TTAccountAuthType)type
                          willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                         completion:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

/// 使用platformType获取第三方平台的用户信息
/// @param type 第三方平台类型
/// @param useCustomWap 是否使用自定义包装的容器授权登录
/// @param completedBlock 获取用户信息的回调
+ (void)requestAuthUserInfoForPlatform:(TTAccountAuthType)type
                       inCustomWebView:(BOOL)useCustomWap
                            completion:(TTAccountAuthUserInfoCompletedBlock _Nullable)completedBlock;

/**
 * 向第三方应用请求登出
 *
 * @param type              第三方平台类型
 * @param completedBlock    登出完成后回调
 */
+ (void)requestLogoutForPlatform:(TTAccountAuthType)type
                      completion:(void (^_Nullable)(BOOL success, NSError *error))completedBlock;

/**
 * 绑定第三方平台至当前登录帐号,只适用于单帐号登录,允许多帐号登录的情况下会走登录逻辑
 *
 * @param type              第三方平台类型
 * @param willBindBlock     授权成功，开始绑定回调
 * @param completedBlock    登录完成后的回调
 */
+ (void)requestBindForPlatform:(TTAccountAuthType)type
                      willBind:(void (^_Nullable)(NSString *_Nonnull))willBindBlock
                    completion:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

/**
 * 绑定第三方平台至当前登录帐号，适用于多帐号和单帐号
 *
 * @param type              第三方平台类型
 * @param useCustomWap      是否使用自定义包装的容器授权登录
 * @param willBindBlock     授权成功，开始绑定回调
 * @param completedBlock    登录完成后的回调
 */
+ (void)requestBindV2ForPlatform:(TTAccountAuthType)type
                 inCustomWebView:(BOOL)useCustomWap
                        willBind:(void (^_Nullable)(NSString *_Nonnull))willBindBlock
                      completion:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

/// 请求第三方授权、登录注册、仅登录、绑定等
/// @param type     第三方平台类型
/// @param request 请求授权的场景、权限以及其它可选参数
/// @param willLoginBlock 开始登录回调 （仅仅授权成功才调用该回调）
/// @param completedBlock 登录、绑定等完成后回调
+ (void)requestAuthForPlatform:(TTAccountAuthType)type
                       request:(TTAccountAuthRequest *)request
                     willLogin:(TTAccountAuthWillLoginBlock _Nullable)willLoginBlock
                    authCompletion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

#pragma mark - 第三方帐号调用sso_callback接口进行登录（生成新的帐号或登录到已有三方帐号）或绑定至当前登录帐号
/**
 *  使用第三方平台授权信息登录头条帐号系统
 *
 *  @param params         第三方平台返回信息
 *  @param willLoginBlock 授权成功，开始登录或者绑定回调
 *  @param completedBlock 登录或绑定完成回调
 *  @return HTTP请求任务
 *
 *  文档：https://doc.bytedance.net/docs/177/266/3186/
 *  参数params的Key描述如下：
 *  key包括: {
 *      @"platform_name",   第三方平台在头条帐号体系中指定的名称。老的方案使用，将被platform_app_id替代。
 *      @"platform_app_id", 第三方平台在头条帐号体系中指定的平台appid，用于唯一绑定头条系产品与第三方产品。
 *      @"code",            第三方平台通过authorizationCode授权后返回的code，用于换取access_token。 [微信、腾讯微博、电信天翼、火山、抖音]
 *      @"access_token",    第三方平台通过token授权后返回的在三方后台获取用户资源的唯一标识。 [腾讯QQ、新浪微博]
 *      @"refresh_token",   第三方平台通过token授权后同access_token一起返回的refresh_token，用于刷新access_token。 [新浪微博]
 *      @"expires_in",      第三方平台通过token授权后返回的access_token有效期字段。 [腾讯QQ、新浪微博]
 *      @"uid",             第三方平台授权后返回的uid，是平台对该用户的唯一标识。 [新浪微博]
 *      @"openid",          第三方平台授权后返回的openid，是平台对该用户的唯一标识。 [腾讯QQ、]
 *  }
 */
+ (nullable id<TTAccountSessionTask>)loginWithSSOCallback:(NSDictionary * _Nonnull)params
                                              forPlatform:(NSInteger)platformType
                                                willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                                               completion:(void(^)(BOOL success /** 操作是否成功 */, BOOL loginOrBind /** 登录还是绑定，登录和以前绑定过该三方帐号再次绑定都返回登录 */, NSError * _Nullable error))completedBlock;

/**
 *  使用第三方平台授权信息进行登录
 *
 *  @param params         第三方平台返回信息
 *  @param willLoginBlock 授权成功，开始登录
 *  @param completedBlock 登录完成回调
 *  @return HTTP请求任务
 *
 */

+ (nullable id<TTAccountSessionTask>)pureLoginWithThirdPartySSOCallback:(NSDictionary * _Nonnull)params
                                                        forPlatform:(NSInteger)platformType
                                                          willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                                                         completion:(void(^)(BOOL success /** 操作是否成功 */,  NSError * _Nullable error))completedBlock;

/**
 *  使用第三方平台授权信息绑定头条帐号系统
 *
 *  @param params         第三方平台返回信息
 *  @param willLoginBlock 授权成功，开始登录或者绑定回调
 *  @param completedBlock 绑定完成回调
 *  @return HTTP请求任务
 *
 */
+ (nullable id<TTAccountSessionTask>)bindWithThirdPartySSOCallback:(NSDictionary * _Nonnull)params
                                              forPlatform:(NSInteger)platformType
                                                willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                                               completion:(void(^)(BOOL success /** 操作是否成功 */, NSError * _Nullable error))completedBlock;

+ (nullable id<TTAccountSessionTask>)authCallbacContinuekForReason:(TTAccountRequestAuthReason)authReason
                                                    params:(NSDictionary * _Nonnull)params
                                               forPlatform:(NSInteger)platformType
                                                 willLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                                                completion:(void(^)(BOOL success /** 操作是否成功 */, NSError * _Nullable error))completedBlock;
#pragma mark - 静默注册与同步 目前仅R 项目使用
/// 检测是否支持静默注册平台帐号
+ (void)checkIsSilentRegisterSupportedForPlatform:(TTAccountAuthType)type
                                        completed:(void (^)(BOOL supported))completed;

+ (void)silentRegisterAndLoginPlatform:(TTAccountAuthType)type
                             completed:(TTAccountLoginCompletedBlock _Nullable)completedBlock;

+ (void)checkIsbindMobileFromPlatformSupported:(TTAccountAuthType)type
                                     completed:(void (^)(BOOL supported))completed;

/// 同步三方平台帐号中的手机号至当前登录帐号
+ (void)bindMobileFromPlatform:(TTAccountAuthType)type
                     completed:(void (^)(BOOL successed))completed;

/**
 *  目前仅Facebook需要在application:didFinishLaunchingWithOptions:中调用

 *  @param launchOptions 就是启动application:didFinishLaunchingWithOptions中的options
 *  @return 第三方SDK处理结果回调
 */
+ (BOOL)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/// 该设备是否可以支持抖音授权登录
/// @param completedBlock 完成回调
+ (nullable id<TTAccountSessionTask>)canQuickLoginWithAweme:(void(^)(BOOL canQucikLogin, NSError * _Nullable error))completedBlock;

/**
 *  第三方绑定冲突是，换绑
 */
+ (id<TTAccountSessionTask>)startAuthSwitchBindWithReq:(TTASNSSDKAuthSwitchBindReqModel *)reqMdl
                                              completedBlock:(void(^)(NSError * _Nullable error))completedBlock;

/// universal linl 授权需要
/// @param userActivity
/// @param restorationHandler 
+ (BOOL)continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

@end

NS_ASSUME_NONNULL_END
