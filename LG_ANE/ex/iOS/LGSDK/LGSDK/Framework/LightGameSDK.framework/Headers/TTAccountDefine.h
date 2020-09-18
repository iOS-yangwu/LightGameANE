//
//  TTAccountDefine.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#ifndef TTAccountDefine_h
#define TTAccountDefine_h

#import "TTAccountMacros.h"
#import "TTAccountSMSCodeDef.h"
#import "TTAccountStatusCodeDef.h"

NS_ASSUME_NONNULL_BEGIN

/** 帐号中错误码相关信息 */
FOUNDATION_EXPORT NSString * const TTAccountErrorDomain;
/** 错误键 */
FOUNDATION_EXPORT NSString * const TTAccountErrorKey;
/** 0表示成功，其它表示失败 */
FOUNDATION_EXPORT NSString * const TTAccountStatusCodeKey;
/** 当状态码非0时，错误消息的键值 */
FOUNDATION_EXPORT NSString * const TTAccountErrMsgKey;
/** 通知中第三方平台名称的键值 */
FOUNDATION_EXPORT NSString * const TTAccountAuthPlatformNameKey;
/** 错误类型
 - 取消授权： -1001
 - 获取掩码错误：-1002
 - 获取token错误：-1003
 - 授权失败：-1004
 - passport接口客户端网络层错误：-1005
 - 其它错误：-1006
 - Passport服务端接口透传接口返回的错误码：都是正数
 */
FOUNDATION_EXPORT NSString * const TTAccountCommonErrCodeKey;
/** 错误描述
 透传passport接口返回的错误信息，其他情况暂时返回null
 */
FOUNDATION_EXPORT NSString * const TTAccountCommonErrMsgKey;

/** 原始错误码:
 透传三方/一键登录错误码 /passport接口错误码/网络层(TTNet)客户端错误
 */
FOUNDATION_EXPORT NSString * const TTAccountOrignalErrCodeKey;
/** 原始错误信息*/
FOUNDATION_EXPORT NSString * const TTAccountOrignalErrMsgKey;

/** 中国移动标识 */
FOUNDATION_EXPORT NSString* const TTAccountMobile;
/** 中国电信标识 */
FOUNDATION_EXPORT NSString* const TTAccountTelecom;
/** 中国联通标识 */
FOUNDATION_EXPORT NSString* const TTAccountUnion;
/** 多账号切换header 标识 */
FOUNDATION_EXPORT NSString* const TTAccountMultiSidsKey;
/** csrf token 校验标识 */
FOUNDATION_EXPORT NSString* const TTAccountCSRFTokenKey;


/// 通过密码登录的类型,
typedef NS_ENUM(NSInteger, TTAPWDLoginType) {
    TTAPWDLoginTypeUserName         = 1,  /// 用户名
    TTAPWDLoginTypeEmail            = 2,  /// 邮箱
    TTAPWDLoginTypePhone            = 3,  /// 手机号
    TTAPWDLoginTypeAccount          = 4,  ///  服务端根据account依次按email、mobile、username判断
};

/**
 *  帐号登录状态发生改变时的原因（如手机号、微信、微博登录、登出、过期等)
 *
 *  如下通知中会包含该值：
 *  TTAccountLoginCompletedNotification
 *  TTAccountLogoutCompletedNotification
 *  TTAccountForceLogoutCompletedNotificiaton
 *  TTAccountSessionExpiredNotificiaton
 */
typedef NS_ENUM(NSInteger, TTAccountStatusChangedReasonType) {
    TTAccountStatusChangedReasonTypeAutoSyncLogin,      // 自动同步登录(user/info)，可能因存储信息丢失导致
    TTAccountStatusChangedReasonTypeFindPasswordLogin,  // 通过找回密码/重置密码登录
    TTAccountStatusChangedReasonTypePasswordLogin,      // 手机号和密码登录
    TTAccountStatusChangedReasonTypeSMSCodeLogin,       // 手机号和验证码登录
    TTAccountStatusChangedReasonTypeEmailLogin,         // 邮箱和密码登录
    TTAccountStatusChangedReasonTypeTokenLogin,         // token和手机号登录
    TTAccountStatusChangedReasonTypeSessionKeyLogin,    // sessionKey和installId登录
    TTAccountStatusChangedReasonTypeAuthPlatformLogin,  // 第三方平台授权登录
    TTAccountStatusChangedReasonTypeLogout,             // 退出登录
    TTAccountStatusChangedReasonTypeSessionExpiration,  // 会话过期
    TTAccountStatusChangedReasonTypeSwitchAccount,      // 多帐号支持的情况下，切换帐号
    TTAccountStatusChangedReasonAuthSwitchTicket,       //不同系统之间的登录票据替换
    TTAccountStatusChangedReasonTypeDeviceOnekeyLogin,  //可信设备一键登录
    TTAccountStatusChangedReasonTypeDeviceLogin,        /// 游客登录
    TTAccountStatusChangedReasonTypeOnekeyLogin,        /// 运营商一键登录
};

typedef NS_ENUM(NSInteger, TTAccountLogoutScene) {
    TTAccountLogoutSceneNormal,                 // 正常的退出登录
    TTAccountLogoutSceneCancel,                 // 注销状态下，确认注销退出
    TTAccountLogoutSceneSessionExpired,         // 检测到session过期，调用登出
};

typedef NS_ENUM(NSInteger, TTAccountCancelScene) {
    TTAccountCancelSceneAbandon,                 /// 放弃注销
    TTAccountCancelSceneConfirm,                 /// 确认注销
};


/// 账号价值类型
typedef NS_ENUM(NSInteger, TTAccountValueType) {
    TTAAccountValueTypeLow          = 0,    /// 低价值账号
    TTAAccountValueTypeNormal       = 1,    /// 普通账号
    TTAAccountValueTypeHigh         = 2,    /// 高价值账号
};

/// 注销时可提供身份验证的方式
typedef NS_ENUM(NSInteger, TTAccountCancelAuthorizeType) {
    TTAAccountCancelAuthorizeTypeUnkonwn        = -1,   /// 无法认证
    TTAAccountCancelAuthorizeTypeNotNeed        = 0,    /// 低价值账号不需认证
    TTAAccountCancelAuthorizeTypeSMSCode        = 1,    /// 手机验证码
    TTAAccountCancelAuthorizeTypeThirdParty     = 2,    /// 三方授权验证
    TTAAccountCancelAuthorizeTypePWD            = 3,    /// 账密验证
};



FOUNDATION_EXPORT NSString *TTAccountStatusChangedReasonKey;


typedef void(^TTAccountLoginCompletedBlock)(BOOL success, NSError * _Nullable error);
typedef void(^TTAccountAuthLoginSuggestCompletedBlock)(NSError * _Nullable errorInfo, id _Nullable jsonObj);


typedef NS_ENUM(NSInteger, TTAccountUserProfileType) {
    TTAccountUserProfileTypeUserName,
    TTAccountUserProfileTypeUserPhone,
    TTAccountUserProfileTypeUserAvatar,
    TTAccountUserProfileTypeUserBgImage,
    TTAccountUserProfileTypeUserDesp,
    TTAccountUserProfileTypeUserGender,
    TTAccountUserProfileTypeUserBirthday,
    TTAccountUserProfileTypeUserProvince,
    TTAccountUserProfileTypeUserCity,
    TTAccountUserProfileTypeUserIndustry,
};

#define TTAccountEnumString(enumInt) ([@(enumInt) stringValue])

FOUNDATION_EXPORT NSString * const TTAccountUserNameKey;
FOUNDATION_EXPORT NSString * const TTAccountUserPhoneKey;
FOUNDATION_EXPORT NSString * const TTAccountUserAvatarKey; // 用户主动上传头像后返回的票据upload_ticket
FOUNDATION_EXPORT NSString * const TTAccountUserAvatarUrlKey; // 用户头像的链接
FOUNDATION_EXPORT NSString * const TTAccountUserBackgroundImageKey;
FOUNDATION_EXPORT NSString * const TTAccountUserDescriptionKey;
FOUNDATION_EXPORT NSString * const TTAccountUserGenderKey; // 性别
FOUNDATION_EXPORT NSString * const TTAccountUserBirthdayKey;
FOUNDATION_EXPORT NSString * const TTAccountUserProvinceKey;
FOUNDATION_EXPORT NSString * const TTAccountUserCityKey;
FOUNDATION_EXPORT NSString * const TTAccountUserIndustryKey;
FOUNDATION_EXPORT NSString * const TTAccountUserAreaKey; // 地区
FOUNDATION_EXPORT NSString * const TTAccountUserExpendAttrsKey; // 扩展字段



typedef NS_ENUM(NSInteger, TTAccountAuthPlatformStatusChangedReasonType) {
    TTAccountAuthPlatformStatusChangedReasonTypeLogin,
    TTAccountAuthPlatformStatusChangedReasonTypeLogout,
    TTAccountAuthPlatformStatusChangedReasonTypeExpiration,
};

typedef NS_ENUM(NSInteger, TTAEmailCodeScenarioType) {
    TTASMSCodeScenarioEmailRegister        = 1,  // 注册
    TTASMSCodeScenarioEmailRegisterRetry   = 2,  // 注册重发
    TTASMSCodeScenarioEmailForgetPassword   = 4,  // 忘记密码
    TTASMSCodeScenarioEmailForgetPasswordRetry   = 5,  // 忘记密码重发
    TTASMSCodeScenarioValidateEmail   = 6,  //验证旧邮箱
    TTASMSCodeScenarioChangeEmail   = 7,  // 换绑邮箱
    TTASMSCodeScenarioBindEmail   = 8,  // 绑定邮箱
    TTASMSCodeScenarioEmailChangePassword   = 11,  // 修改密码
};

@protocol TTAccountSessionTask;
@class TTAccountUserEntity;
@class TTAccountMediaUserEntity;
@class TTAccountPlatformEntity;
@class TTAccountUserAuditEntity;
@class TTAccountVerifiedUserAuditEntity;
@class TTAccountMediaUserAuditEntity;
@class TTAccountUserAuditSet;
@class TTAccountImageEntity;
@class TTAccountImageListEntity;
@class TTADataCheckMobileUseableModel;
@class TTADataUseableLoginWaysModel;

/** 第三方帐号平台类型 */
typedef
NS_ENUM(NSInteger, TTAccountAuthType) {  //需要同步BD3rdPlatformTypeXXX
    TTAccountAuthTypeUnsupport =-1, /** None */
    TTAccountAuthTypeWeChat    = 0, /** 微信 */
    TTAccountAuthTypeTencentQQ = 1, /** Tencent QQ */
    TTAccountAuthTypeTencentWB = 2, /** Tencent微博 */
    TTAccountAuthTypeSinaWeibo = 3, /** 新浪微博 */
    TTAccountAuthTypeTianYi    = 4, /** 电信天翼 */
    TTAccountAuthTypeRenRen    = 5, /** 人人网 */
    TTAccountAuthTypeKaixin    = 6, /** 开心网 */
    TTAccountAuthTypeFacebook  = 7, /** Facebook */
    TTAccountAuthTypeTwitter   = 8, /** Twitter */

    /** attention: [10-1000) 之间为公司产品类型；与BDSDKProductType定义产品类型顺序一致 */
    TTAccountAuthTypeToutiao    = 10, /** 今日头条 */
    TTAccountAuthTypeDouyin     = 11, /** 抖音 */
    TTAccountAuthTypeHuoshan    = 12, /** 火山 */
    TTAccountAuthTypeTTVideo    = 13, /** 西瓜视频 */
    TTAccountAuthTypeTTWukong   = 14, /** 悟空问答 */
    TTAccountAuthTypeTTFinance  = 15, /** 财经 */
    TTAccountAuthTypeTTCar      = 16, /** 懂车帝 */
    TTAccountAuthTypeRocket     = 17, /** 飞聊 */
    TTAccountAuthTypeTiktok     = 18, /** Tiktok */
    TTAccountAuthTypeGoogle     = 19, /// google
    TTAccountAuthTypeLine       = 20, /// line
    TTAccountAuthTypeKakaotalk  = 21, /// kakao
    TTAccountAuthTypeApple      = 22,  /// apple sign
    TTAccountAuthTypeVK         = 23, /// VK
};

///  请求接口的场景，部分接口需要，目前 userinfo 需要
typedef NS_ENUM(NSInteger, TTAccountRequestScenceType) {
    TTAccountRequestNormal                  = 1,    /// 普通请求
    TTAccountRequestWhenFinishLaunching     = 2,    /// 冷启动时请求
    TTAccountRequestByPooling               = 3,    /// 轮询请求
    TTAccountRequestWhenEnterForeground     = 4,    /// 前后台切换，进入前台
    TTAccountRequestAfterLogin              = 5,    /// 登录成功后
};
FOUNDATION_EXPORT NSString *TTAccountRequestScenceTypeToString(TTAccountRequestScenceType requestScenceType);

/// 更新token 的时间请求间隔，单位 min
typedef NS_ENUM(NSInteger, TTATokenPollingInterveral) {
    TTATokenPollingInterveralTen        = 10,   /// 10 mins
    TTATokenPollingInterveralFifteen    = 15,   /// 15 mins
    TTATokenPollingInterveralTwenty     = 20,   /// 20mins
    TTATokenPollingInterveralTwentyfive = 25,   /// 25 mins
    TTATokenPollingInterveralThirty     = 30,   /// 30 mins
};
typedef
NS_ENUM(NSInteger, TTAccountRequestAuthReason) {
    TTAccountRequestAuthOnly                        = 1,    /** 只获取第三方授权信息*/
    TTAccountRequestAuthForLogin                    = 2,    /** 获取第三方授权信息并登录,老用户登录，新用户注册*/
    TTAccountRequestAuthForBind                     = 3,    /** 获取第三方授权信息并绑定第三方平台 */
    TTAccountRequestAuthForLoginOnly                = 4,    /** 获取第三方授权信息并绑定第三方平台，新用户不进行注册，返回profileKey,绑定手机号*/
    TTAccountRequestAuthForShareLogin               = 5,    ///适用于公司内部平台，同帐号组授权不产生新的uid
    TTAccountRequestAuthForLoginWithBindMobile      = 6,    /// 适用于公司内部平台,第三方授权登录并绑定第三方平台上的手机号
    TTAccountRequestAuthForBindWithMobile           = 7,    /// 适用于公司内部平台,绑定第三方，并同步绑定第三方平台的手机号
};

/// 设备登录信息
typedef NS_ENUM(NSInteger, TTADeviceLoginInfoType) {
    TTADeviceLoginInfoOfLatest      = 1 << 0,  /// 最近一次登录,获取did下最近一次登录的uid，再去拿uid下最近一次登录方式
    TTADeviceLoginInfoOfMostUsed    = 1 << 1,  /// 获取did下最近一次登录的uid，再去拿uid下最常用登录方式
    TTADeviceLoginInfoOfLongestUsed = 1 << 2,  /// 获取did下最活跃（90天）uid，再去获取最近一次登录方式
    TTADeviceLoginInfoOfAll         = TTADeviceLoginInfoOfLatest|
                                      TTADeviceLoginInfoOfMostUsed|
                                      TTADeviceLoginInfoOfLongestUsed,  /// 获取did下最活跃（90天）uid，再去获取最近一次登录方式
};

/// 登录方式缓存，目前可信环境登录、游客登录暂不缓存
typedef NS_ENUM(NSInteger, TTAccountLoginType) {
    TTAccountLoginTypeUnknown                   = -1,       /// 未知
    TTAccountLoginTypeOnekeyLogin               = 1,        /// 运营商一键登录
    TTAccountLoginTypePhoneAndSMSCode           = 2,        /// 手机号验证码登录
    TTAccountLoginTypePhoneAndPwd               = 3,        /// 手机号密码登录
    TTAccountLoginTypeEmail                     = 4,        /// 邮箱密码/邮箱验证码登录
    TTAccountLoginTypeAccountAndPwd             = 5,        /// 帐号密码登录
    TTAccountLoginTypeThirdPart                 = 6,        /// 第三方登录
};

/// 用户信息修改类型
typedef NS_OPTIONS(NSInteger, TTAccountUserUpdateType) {
    TTAccountUserUpdateTypeAvatar                   = 1 << 0,        /// 头像
    TTAccountUserUpdateTypeName                     = 1 << 1,        /// 昵称
    TTAccountUserUpdateTypeDescription              = 1 << 2,        /// 描述
};

/// 用户信息修改类型
typedef NS_ENUM(NSInteger, TTAccountCheckUserSceneType) {
    TTAccountCheckUserSceneTypeAppLaunch                   = 1,        /// 冷启动
    TTAccountCheckUserSceneTypeComment                     = 2,        /// 评论
    TTAccountCheckUserSceneTypePublish                     = 3,        /// 发布内容
};

@class TTACheckUserCanSetModel;
typedef
void (^TTAccountCheckCanSetCompletedBlock)(TTACheckUserCanSetModel *model, NSError *error);

NS_ASSUME_NONNULL_END

///  非服务端返回错误的类型,对应TTAccountCommonErrCodeKey的值；服务端接口错误码直接c透传
typedef NS_ENUM(NSInteger, TTAccountCommonErrCode) {
    TTAccountCommonErrCodeAuthCancel               = -1001,        ///  三方授权取消
    TTAccountCommonErrCodeFetchMaskPhoneFailure    = -1002,        /// 运营商一键登录获取掩码错误
    TTAccountCommonErrCodeGetTokenFailure          = -1003,        /// 运营商一键登录获取token失败
    TTAccountCommonErrCodeAuthFailure              = -1004,        /// 三方授权失败
    TTAccountCommonErrCodeNetWorkFailure           = -1005,        ///  网络层错误
    TTAccountCommonErrCodeUnkonwn                  = -1006,        ///  其它未知错误
};
#endif /* TTAccountDefine_h */
