//
//  TTAccountConfiguration.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/8/17.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTAccountDefine.h"
#import "TTAccountMulticast.h"



NS_ASSUME_NONNULL_BEGIN

/**
 帐号相关的配置
 */
@interface TTAccountConfiguration : NSObject

/** 动态设置网络请求通用参数句柄 */
@property (nonatomic,   copy, nonnull) NSDictionary * _Nonnull (^networkParamsHandler)(void);


/** 动态配置APP接口所需的必要参数，installId和fromSessionKey用于请求NewSession */
FOUNDATION_EXPORT NSString *TTAccountInstallIdKey;      // installId
FOUNDATION_EXPORT NSString *TTAccountDeviceIdKey;       // deviceId
FOUNDATION_EXPORT NSString *TTAccountSessionKeyKey;     // sessionKey
FOUNDATION_EXPORT NSString *TTAccountFromSessionKeyKey; // 共享APP的sessionKey
FOUNDATION_EXPORT NSString *TTAccountSSAppIdKey;        // SSAppID
@property (nonatomic,   copy, nonnull) NSDictionary * _Nonnull (^appRequiredParamsHandler)(void);


/** 帐号用户数据是否支持多线程安全访问 [Default is YES] */
@property (nonatomic, assign) BOOL multiThreadSafeEnabled;

/** 跨group访问共享的帐号数据，仅仅在同一个帐号下（同TEAM ID)适用；形式(TEAM ID).[***] */
@property (nonatomic,   copy, nullable) NSString *sharingKeyChainGroup;

/** 当第三方平台登录或绑定出现已绑定异常时，是否弹出alertView提示解绑 [Default is YES] */
@property (nonatomic, assign) BOOL unbindAlertEnabled;

/** 当用第三方平台登录或绑定失败时，是否弹出alertView提示，提示信息 <***帐号登录|绑定异常> [Default is YES] */
@property (nonatomic, assign) BOOL showAlertWhenLoginFail;

/** 是否可通过找回密码实现登录 [Default is YES] */
@property (nonatomic, assign) BOOL byFindPasswordLoginEnabled;

/** 外部设置帐号相关接口的域名 */
@property (nonatomic,   copy, nullable) NSString *domain;

/** 设置帐号消息第一响应者；当帐号信息发生变更时，将首先发送给该代理 */
@property (nonatomic, strong, nullable) NSObject<TTAccountMessageFirstResponder> *accountMessageFirstResponder;

/** 动态获取当前的ViewController句柄 */
@property (nonatomic,   copy, nullable) UIViewController * __nonnull (^visibleViewControllerHandler)(void);

/// 是否支持多帐号登录
@property (nonatomic,  assign) BOOL isSupportMutilLogin;

/// 第三方登录/绑定成功后是否需要同步用户信息,默认NO，需要则在第三方平台登录成功后，调用获取用户信息接口
@property (nonatomic, assign) BOOL sysnUserInfoAfterAuthLogin DEPRECATED_MSG_ATTRIBUTE("auth/login和bind接口返回信息已补全，不需要再调用该2/user/info");

/// 是否为boe测试环境，允许HTTP请求,默认为NO.正式上线请确保设置为NO。
@property (nonatomic, assign) BOOL isBoe;

/// 解绑第三方平台地址，默认走/passport/auth/unbind/接口
@property (nonatomic, copy) NSString *unbindThirdPartyURLPath;

///前后台切换时是否自动同步用户信息 [Default is NO]；策略是：当前是登录状态，则首次启动或从后台到前台时同步
@property (nonatomic, assign) BOOL autoSynchronizeUserInfo;

/// 获取用户信息的api地址，默认走/passport/account/info/v2/接口
@property (nonatomic, copy) NSString *userInfoURLPath;

/// 是否开启userInfo 接口定时轮询的功能，默认关闭,策略是：当前是登录状态，则冷起后定时请求account/info/v2 接口
@property (nonatomic, assign) BOOL autoSynchronizeUserInfoByTimer;

/// 定时轮询userInfo 接口的时间设定，默认10min
@property (nonatomic, assign) NSInteger autoSynchronizeUserInfoTimeInterval;

/// 需要添加token的域名集合，一般为业务方现有线上可跨域的集合
@property (atomic, copy) NSArray<NSString *> *needTokenDomins;

/// cookie跨域集合新增的域名集合，业务方可以配置setting，以支持动态增加一些域名
@property (atomic, copy) NSArray<NSString *> *addtionalTokenDomins;

/// x_tt_token 长票据功能是否可用,默认开启
@property (nonatomic, assign) BOOL isXTTTokenActive;

/// x_tt_token 长票据功能轮询间隔，默认 10 min
@property (nonatomic, assign) TTATokenPollingInterveral tokenPollingInterveral;


/// 是否开启登录方式本地缓存功能，默认不开启
@property (nonatomic, assign) BOOL openCacheLoginInfo;

/// 手机号与国家码分割线
@property (nonatomic, copy, nullable) NSString *mobileSeparator;

@end

NS_ASSUME_NONNULL_END
