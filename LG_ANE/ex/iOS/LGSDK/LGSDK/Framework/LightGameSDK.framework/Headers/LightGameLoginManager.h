//
//  LightGameLoginManager.h
//  LightGameSDK
//
//  Created by wangchao on 2019/8/14.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGUserModel.h"
#import "LightGameManager.h"
#import "TikTokOpenPlatformAuth.h"


@class LightGameDouYinAuthConfig;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LGADouyinOpenSDKErrorCode) {
    LGADouyinOpenSDKSuccess                = 0,    /** 成功 */
    LGADouyinOpenSDKErrorCodeCommon        = -1,   /** 通用错误类型 <包括网络错误> */
    LGADouyinOpenSDKErrorCodeUserCanceled  = -2,   /** 用户手动取消 */
    LGADouyinOpenSDKErrorCodeSendFailed    = -3,   /** 发送失败 */
    LGADouyinOpenSDKErrorCodeAuthDenied    = -4,   /** 权限错误 */
    LGADouyinOpenSDKErrorCodeUnsupported   = -5,   /** 不支持 */
};

// 登录结果
typedef NS_ENUM(NSInteger, LGLoginResult) {
    LGLoginResultLoginSucc              = 1,     /** 登录成功 */
    LGLoginResultChangeSucc             = 2,     /** 切换成功 */
    LGLoginResultBindSucc               = 3,     /** 绑定成功 */
    LGLoginResultErrorCommon            = -1,    /** 通用错误类型 <包括网络错误> */
    LGLoginResultErrorBoundAlready      = -2,    /** 账号已经绑定或者当前第三方已经被绑定过 */
    LGLoginResultErrorUserCanceled      = -3,    /** 用户手动取消 */
    LGLoginResultErrorSendFailed        = -4,    /** 授权请求发送失败 */
    LGLoginResultErrorAuthDenied        = -5,    /** 权限错误 */
    LGLoginResultErrorAuthUnsupported   = -6,    /** 授权不支持 */
    LGLoginResultErrorChangeUnsupported = -7,    /** 不支持切换账号(当前用户未登录) */
    LGLoginResultErrorChangeCanceled    = -8,    /** 用户取消切换账户*/
    LGLoginResultErrorBindUnsupported   = -9,    /** 不支持绑定账号(只有游客才支持) */
    LGLoginResultErrorBindCanceled      = -10,   /** 用户取消绑定账户*/
    LGLoginResultErrorForLoginModeNoSet = -11,   /** 用户取消绑定账户*/
    LGLoginResultErrorForGuestRecreate  = -12    /** 15天内重复创建游客账号*/
};

// 登录模式
typedef NS_ENUM(NSInteger, LGLoginMode) {
    LGLoginModeNoSet = 0,   // 模式未设置,设置是不能选择该项 只能从以下两项选择
    LGLoginModePopView,     // 弹框登录
    LGLoginModeSilent       // 静默登录
};


@protocol LGTikTokAuthDelegate <NSObject>

- (void)didReceiveAuthErrorCode:(LGADouyinOpenSDKErrorCode)errorCode errorString:(NSString *)errorString state:(NSString *)state authCode:(NSString *)authCode;

@end

/**
 登录结果回调
 
 @param loginResult 登录结果
 @param loginUser 登录成功的用户数据
 */
typedef void(^LGLoginResultCallBack)(LGLoginResult loginResult, LGUserModel * _Nullable loginUser);



@interface LightGameLoginManager : NSObject

/**
    登录模式，接入登录模块前必须通过setLoginMode接口设置，否则登录功能不可用
 */
@property(nonatomic, assign, readonly) LGLoginMode loginMode;

/**
    是否开启登录功能的Toast提醒，默认开启 第三方可设置关闭 非SDK必须配置项,开启后在使用账户功能时，会有相关成功或失败提示
 */
@property (nonatomic, assign) BOOL isLoginToastPrompt;

// 是否是账号用户(YES)，不接账号的即为设备用户(NO)
@property(nonatomic, assign, readonly) BOOL isNormalUser;

@property (nonatomic, weak) id <LGTikTokAuthDelegate> delegate;

/**
 登录结果回调
 */
@property(nonatomic, copy) LGLoginResultCallBack loginResultCallBack;

/**
 单例构造

 @return 账号功能管理类
 */
+ (LightGameLoginManager *)sharedInstance;

- (BOOL)douyinAuthRequest:(LightGameDouYinAuthConfig *)cfg viewController:(UIViewController *)vc ;

/**
 设置登录模式，SDK必须设置项
 @param loginMode 登录模式 静默登录(LGLoginModeSilent)和弹框登录(LGLoginModePopView)
 */
+ (void)setLoginMode:(LGLoginMode)loginMode;

/**
 是否开启登录功能的Toast提醒，默认开启 第三方可设置关闭 非SDK必须配置项
 开启后在使用账户功能时，会有相关成功或失败提示
 @param isOpen yes开启，no关闭
 */
+ (void)setIsLoginToastPrompt:(BOOL)isOpen;

/**
一键登录功能注册移动运营商参数

@param appId 移动对应的appID
@param appKey 移动对应的appKey

*/
- (void)registerOneKeyLoginMobileAppId:(NSString *)appId appKey:(NSString *)appKey;
/**
一键登录功能注册电信运营商参数

@param appId 电信对应的appID
@param appKey 电信对应的appSecret

*/
- (void)registerOneKeyLoginTelecomAppId:(NSString *)appId appKey:(NSString *)appKey;
/**
一键登录功能注册联通运营商参数

@param appId 联通对应的appID
@param appKey 联通对应的appSecret

*/
- (void)registerOneKeyLoginUnionAppId:(NSString *)appId appKey:(NSString *)appKey;


/**
 一键登录功能
 
 @param loginResultCallBack 切换结果回调
 */
- (void)oneClickLoginAccount:(LGLoginResultCallBack)loginResultCallBack;
/**
账号切换功能，只有用户登录后才能调用

@param loginResultCallBack 切换结果回调
*/
- (void)oneClickChangeAccount:(LGLoginResultCallBack)loginResultCallBack;
/**
账号绑定功能，只有游客模式可以进行绑定操作

@param loginResultCallBack 绑定结果回调
*/
- (void)oneClickBindAccount:(LGLoginResultCallBack)loginResultCallBack;

/**
 账号登录功能
 
 @param loginResultCallBack 切换结果回调
 */
- (void)loginAccount:(LGLoginResultCallBack)loginResultCallBack;


/**
 账号切换功能，只有用户登录后才能调用

 @param loginResultCallBack 切换结果回调
 */
- (void)changeAccount:(LGLoginResultCallBack)loginResultCallBack;


/**
 账号绑定功能，只有游客模式可以进行绑定操作

 @param loginResultCallBack 绑定结果回调
 */
- (void)bindAccount:(LGLoginResultCallBack)loginResultCallBack;

/**
 判断当前用户是否为游客
 
 @return bool yes为游客，no为非游客
 */
- (BOOL)isCurrentUserGuest;


/**
 内部测试用
 清除本地Token和所有登录数据
 */
+ (void)clearAllUserData;


@end

NS_ASSUME_NONNULL_END
