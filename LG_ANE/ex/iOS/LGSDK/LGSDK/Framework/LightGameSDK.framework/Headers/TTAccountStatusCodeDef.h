//
//  TTAccountStatusCodeDef.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/28/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#ifndef TTAccountStatusCodeDef_h
#define TTAccountStatusCodeDef_h



#pragma mark - 状态码

/**
 *  帐号体系的所有错误码
 *
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=13962019
 */
typedef NS_ENUM(NSInteger, TTAccountErrCode) {
    TTAccountErrCodeUnknown                         = -1, // 未知错误
    TTAccountSuccess                                = 0,  // 成功
    
    // 第三方平台授权错误类型
    TTAccountErrCodeAuthCommon                      = 1, // 第三方授权：普通授权错误
    TTAccountErrCodeAuthURAppId                     = 2, // 第三方授权：没有注册AppID
    TTAccountErrCodeAuthUserCancel                  = 3, // 第三方授权：用户主动取消授权
    TTAccountErrCodeAuthSendFail                    = 4, // 第三方授权：发送失败
    TTAccountErrCodeAuthNetworkFail                 = 5, // 第三方授权：网络错误
    TTAccountErrCodeAuthDeny                        = 6, // 第三方授权：授权失败
    TTAccountErrCodeAuthUnsupport                   = 7, // 第三方授权：平台不支持
    TTAccountErrCodeAuthCancelInstall               = 8, // 第三方授权：取消应用下载
    TTAccountErrCodeAuthCSRFAttack                  = 9, // 第三方授权：csrf 攻击

    TTAccountErrCodeNotSupport                      = 11, /// 不支持该功能
    // 与服务端定义一致错误码
   	TTAccountErrCodeHasRegistered                   = 1001, // 已注册  仅type=1,2时返回
    TTAccountErrCodePhoneIsEmpty                    = 1002, // 手机号为空
    TTAccountErrCodePhoneError                      = 1003, // 手机号错误
    TTAccountErrCodeBindPhoneError                  = 1004, // 手机号绑定错误
    TTAccountErrCodeUnbindPhoneError                = 1005, // 解绑手机号错误
    TTAccountErrCodeBindPhoneNotExist               = 1006, // 绑定不存在
    TTAccountErrCodePhoneHasBound                   = 1007, // 该手机号已绑定
    TTAccountErrCodeUnregistered                    = 1008, // 未注册
    TTAccountErrCodePasswordError                   = 1009, // 密码错误
    TTAccountErrCodePasswordIsEmpty                 = 1010, // 密码为空
    TTAccountErrCodeUserNotExist                    = 1011, // 用户不存在
    TTAccountErrCodePasswordAuthFailed              = 1012, // 密码验证失败（如位数错误）
    TTAccountErrCodeUserIdIsEmpty                   = 1013, // 用户id为空
    TTAccountErrCodeEmailIsEmpty                    = 1014, // 邮箱为空
    TTAccountErrCodeGetSMSCodeTypeError             = 1015, // 获取验证码类型错误
    TTAccountErrCodeSMSCodeNotExistOrExpired        = 1016, // 验证码不存在或已过期
    TTAccountErrCodeOneKeyLoginRetryLater           = 1017, // 一键登录中稍后重试
    TTAccountErrCodeOneKeyLoginFailed               = 1018, // 一键登录失败
    TTAccountErrCodeOneKeyLoginGetSMSCodeTimeout    = 1019, // 一键登录获取短信超时
    TTAccountErrCodeOneKeyLoginSuccess              = 1020, // 一键登录成功
    TTAccountErrCodeThirdPartyUnauthorized          = 1021, // 未认证的第三方
    TTAccountErrCodeOneKeyLoginGetSMSCodeSuccess    = 1022, // 一键登录验证码获取成功
    TTAccountErrCodeClientAuthParamIsEmpty          = 1023, // 未传入认证client参数
    TTAccountErrCodeThirdSecretMissing              = 1024, // 缺少第三方secret

    /** 当前帐号绑定冲突，第三方帐号已绑定过其他头条帐号 */
    TTAccountErrCodeAccountBoundForbid              = 1030, // connect_switch
    TTAccountErrCodePasswordErrorLevel2             = 1032, // 密码登录和设置密码时非可信设备强制使用短信验证码校验
    TTAccountErrCodePasswordErrorLevel3             = 1033, // 密码登录和设置密码时非可信设备强制使用短信验证码校验

    TTAccountErrCodeForbidWhenUnbindOnlyOneWay      = 1038, // 当前帐号仅存在一种绑定，禁止解绑第三方帐号
    TTAccountErrCodeNeedSMSCodeVerifyDevice         = 1039, // 密码登录和设置密码等操作时发现非可信设备强制使用短信验证码校验
    /** 第三方授权帐号绑定冲突，已有第三方授权帐号绑定过头条当前帐号 */
    TTAccountErrCodeAuthPlatformBoundForbid         = 1041, // connect_exist
    TTAccountErrCodeTwoStepRegisterTicketExpird     = 1042, // ticket expired
    
    // 绑定或者换绑手机号时，手机号已经绑定其他帐号，需要跳转URLj进行处理，https://docs.bytedance.net/doc/FcEhnIIX4k5Koso0tnEE4g
    TTAccountErrCodeCurrPhoneIsBindedAndNeedJumpToUrl  = 1057,

    TTAccountErrCodeInLoggingout                    = 1075, /// 帐号注销中

    TTAccountErrCodeAccountBanned                   = 1091, /// 帐号封禁中
    TTAccountErrCodeAccountLimited                  = 1092, /// 帐号权限受限
    TTAccountErrCodeDeviceBanned                    = 1093, /// 设备封禁中

    // 图片验证码错误类型 (1101-1199)
    TTAccountErrCodeCaptchaMissing                  = 1101, // 需要图片验证码 同时返回captcha的值
    TTAccountErrCodeCaptchaError                    = 1102, // 图片验证码错误 同时返回新的captcha的值
    TTAccountErrCodeCaptchaExpired                  = 1103, // 图片验证码失效 同时返回新的captcha的值
    TTAccountErrCodeSGMClickVerification            = 1104, // 需要SGM点选验证
    TTAccountErrCodeSGMSlideVerification            = 1105, // 需要SGM滑动验证
    
    // 短信验证码错误类型 (1201-1299)
   	TTAccountErrCodeSMSCodeMissing                  = 1201, // 缺少验证码
    TTAccountErrCodeSMSCodeError                    = 1202, // 验证码错误
    TTAccountErrCodeSMSCodeExpired                  = 1203, // 验证码过期
    TTAccountErrCodeSMSCodeTypeError                = 1204, // 验证码类型错误
    TTAccountErrCodeSMSCodeSendError                = 1205, // 验证码发送错误
    TTAccountErrCodeSMSCodeFreqError                = 1206, // 验证码频率控制错误（如发送太频繁）

    TTAccountErrCodePlatformUnusual                 = 1905, //第三方登录平台异常
    TTAccountErrCodePlatformUnavailable             = 1906, //第三方登录平台不可用
    TTAccountErrCodeForceBindPhone                  = 2001, //新注册用户强制绑定手机号
    TTAccountErrCodeUntrustworthyEnv                = 2029, //环境不可信
    TTAccountErrCodeCSRFTokenError                  = 2035, //接口请求csrftoken 校验未通过
    
    
    /** Custom Error Code  [-5000~-6000] */
    // 网络不可用
    TTAccountErrCodeNetworkFailure                  = -5000, // 当前网络不可用，请稍后重试
    
    
    // 服务端数据格式不正确类型
    TTAccountErrCodeServerDataFormatInvalid         = -5001, // 服务端返回异常, 返回的json数据不是dict或服务端返回数据格式与规定不一致
    TTAccountErrCodeServerException                 = -5002,
    
    TTAccountErrCodeClientParamsInvalid             = -5005,
    TTAccountErrCodeUserNotLogin                    = -5006,
    
    /** 认证失败 */
    TTAccountErrCodeAuthorizationFailed             = -5010, // 对应服务端 auth_failed/login_failed
    /** 头条的登录过期 */
    TTAccountErrCodeSessionExpired                  = -5011, // 对应服务端 session_expired
    /** 第三方授权是否过期，防止用户因某个平台登出而导致账户退出（仅用在话题中） */
    TTAccountErrCodePlatformExpired                 = -5012, // 对应服务端 expired_platform
    TTAccountErrCodeUserNotExisted                  = -5013, // 对应服务端 user_not_exist
    TTAccountErrCodeNameExisted                     = -5014, // 对应服务端 name_existed
    
    /** unused */
    TTAccountErrCodeMissingSessionKey               = -5020,
};



/**
 *  获取错误码描述
 */
FOUNDATION_EXPORT NSString *TTAccountGetErrorCodeDescription(TTAccountErrCode errcode);



#endif /* TTAccountStatusCodeDef_h */
