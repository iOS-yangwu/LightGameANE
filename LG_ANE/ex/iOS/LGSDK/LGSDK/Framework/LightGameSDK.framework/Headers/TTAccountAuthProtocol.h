//
//  TTOAuthPlatformProtocol.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 3/31/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountAuthDefine.h"
#import "TTAccountAuthResponse.h"
#import "TTAccountAuthRequestModel.h"

NS_ASSUME_NONNULL_BEGIN


@protocol TTAccountAuthProtocol <NSObject>
@required
/**
 * 单例
 */
+ (instancetype)sharedInstance;

@required
/**
 *  只请求第三方登录token等授权新信息,不进行登录逻辑的处理
 *
 *  @param useCustomWap     是否使用自定义容器进行授权
 *  @param completedBlock   授权完成回调
 */
- (void)requestAuthInfoByCustomWebView:(BOOL)useCustomWap
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;
/**
 *  请求登录
 *
 *  @param useCustomWap     是否使用自定义容器进行授权
 *  @param completedBlock   登录完成回调
 */
- (void)requestLoginByCustomWebView:(BOOL)useCustomWap
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 *  请求登录
 *
 *  @param useCustomWap     是否使用自定义容器进行授权
 *  @param willLoginBlock   开始登录回调 （仅仅授权成功才调用该回调）
 *  @param completedBlock   登录完成回调
 */
- (void)requestLoginByCustomWebView:(BOOL)useCustomWap
                          willLogin:(TTAccountAuthWillLoginBlock _Nullable)willLoginBlock
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 *  请求第三方登录，直接返回登录信息 或者 登录 或者 绑定第三方帐号
 *
 *  @param useCustomWap                     是否使用自定义容器进行授权
 *  @param willLoginBlock                   开始登录回调 （仅仅授权成功才调用该回调）
 *  @param TTAccountRequestAuthReason       请求第三方登录的原因
 *  @param completedBlock                   登录完成回调
 */

- (void)requestLoginByCustomWebView:(BOOL)useCustomWap
                          requestAuthReason:(TTAccountRequestAuthReason)requestAuthReason
                          willLogin:(TTAccountAuthWillLoginBlock _Nullable)willLoginBlock
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 * 使用platformType登录第三方平台应用帐号,与上述API的区别在于，上述接口老用户登录，新用户注册；该接口新用户不会进行注册操作，会返回profileKey
 *
 *  @param useCustomWap                  是否使用自定义容器进行授权
 *  @param willLoginBlock                   开始登录回调 （仅仅授权成功才调用该回调）
 *  @param completedBlock                   登录完成回调
 */
- (void)requestLoginOnlyWithwillLogin:(void (^_Nullable)(NSString *_Nonnull))willLoginBlock
                           completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 *  请求第三方登录，直接返回登录信息 或者 登录 或者 绑定第三方帐号
 *
 *  @param useCustomWap                     是否使用自定义容器进行授权
 *  @param willLoginBlock                   开始登录回调 （仅仅授权成功才调用该回调）
 *  @param TTAccountRequestAuthReason       请求第三方登录的原因
 *  @param completedBlock                   登录完成回调
 */

- (void)requestLoginByCustomWebView:(BOOL)useCustomWap
                          requestAuthReason:(TTAccountRequestAuthReason)requestAuthReason
                          willLogin:(TTAccountAuthWillLoginBlock _Nullable)willLoginBlock
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 *  注销账户
 *
 *  @param completedBlock 登出完成回调
 */
- (void)requestLogout:(void(^)(BOOL success, NSError * _Nullable error))completedBlock;

/**
 *  使用AppID注册第三方平台,默认不共享第三方平台信息，创建新用户
 */
+ (void)registerApp:(NSString * _Nonnull)appID;

/**
 *  打开第三方平台
 */
+ (BOOL)handleOpenURL:(NSURL *)url;

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

/**
 *  第三方平台是否支持SSO登录
 */
+ (BOOL)isSupportSSO;

/**
 *  第三方平台是否支持Web SSO登录
 */
+ (BOOL)isSupportWebSSO;

/**
 *  是否支持不通过第三方平台SDK进行SSO授权登录
 */
+ (BOOL)isSupportCustomWebSSO;

/**
 *  是否安装第三方平台
 */
+ (BOOL)isAppInstalled;

/**
 *  是否App可使用的（安装且API支持）
 */
+ (BOOL)isAppAvailable;

/**
 *  第三方平台的版本
 */
+ (nonnull NSString *)currentVersion;

/**
 *  第三方APP Auth平台类型
 */
+ (TTAccountAuthType)platformType;

/**
 *  第三方Auth平台名称
 */
+ (nonnull NSString *)platformName;

/**
 *  第三方帐号在头条系APP中的唯一标识（用于代替老的appID和platformName，老的方式使用appID和platformName来标识第三方帐号在头条系APP中唯一性），以后将使用platformAppID来标识第三方帐号在头条系APP中唯一性
 */
+ (nonnull NSString *)platformAppID;

/**
 *  显示的平台名称
 *
 *  当登录或解绑失败，显示Toast时使用
 */
+ (nonnull NSString *)displayName;

/**
 * 获取第三方APP在app store上的下载地址
 */
+ (nullable NSString *)getAppInstallUrl;

@optional

/**
 检测平台是否支持静态注册
 */
- (void)checkIsSilentRegisterSupportedWithCompleted:(void (^)(BOOL supported))completedBlock;

/**
 静默注册平台帐号再登录
 */
- (void)silentRegisterAndLoginWithCompleted:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 返回该平台是否支持换绑，比如:飞聊帐号A已经绑定到宿主帐号B, 此时是否直接将次飞聊帐号A直接绑定到宿主帐号C
 */
- (BOOL)disableSwitchBind;

/**
 是否支持将第三方平台的手机号码绑定到当前登录帐号，例如同步飞聊帐号中的手机号至当前登录帐号
 */
- (void)checkIsbindMobileFromPlatformSupportedWithCompleted:(void (^)(BOOL supported))completedBlock;

/// 同步三方平台帐号中的手机号至当前登录帐号
- (void)bindMobileFromPlatformWithCompleted:(void (^)(NSError *error, id jsonObj))completedBlock;

/**
 facebook授权登录功能需要在application:didFinishLaunchingWithOptions:中进行调用
 */
+ (BOOL)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/// 根据auth返回结果，返回login/userinfo的参数
/// @param resp auth返回值
- (NSDictionary *)thirdPartAuthParams:(TTAccountAuthResponse *)resp;

/// 请求第三方登录注册、仅登录、绑定等
/// @param request 请求授权的内容
/// @param willLoginBlock 开始登录回调 （仅仅授权成功才调用该回调）
/// @param completedBlock 登录、绑定等完成后回调
- (void)requestAuthWithRequest:(TTAccountAuthRequest *)request
                          willLogin:(TTAccountAuthWillLoginBlock _Nullable)willLoginBlock
                         completion:(TTAccountAuthLoginCompletedBlock _Nullable)completedBlock;

/**
 通过universalLink 授权登录时需要在application:continueUserActivity:restorationHandler：中进行调用
 */
+ (BOOL)continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

@end


NS_ASSUME_NONNULL_END
