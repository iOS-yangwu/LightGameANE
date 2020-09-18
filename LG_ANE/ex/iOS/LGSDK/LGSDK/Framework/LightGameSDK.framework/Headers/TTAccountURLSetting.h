//
//  TTAccountURLSetting.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 10/19/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountURLSetting : NSObject

#pragma mark - BASE URL

+ (NSString *)HTTPSBaseURL;

#pragma mark - FULL URL

//  帐号注销提供身份认证信息
+ (NSString *)TTACancelPostURLString;

//  帐号注销
+ (NSString *)TTACancelDoURLString;

//  帐号注销跳转页面
+ (NSString *)TTACancelIndexURLString;

/// 判断用户价值
+ (NSString *)TTACancelCheckUserURLString;

/// 判断注销条件
+ (NSString *)TTACancelCheckURLString;

/// 确认注销
+ (NSString *)TTACancelConfirmURLString;

/// 通过第三方注销时进行三方认证
+ (NSString *)TTACancelAuthAuthorzeURLString;

/// 通过账密注销时进行三方认证
+ (NSString *)TTACancelPWDAuthorzeURLString;

//  新版登录页面账号密码统一登录接口
+ (NSString *)TTAAccountPWDLoginString;

// 一键登录,传入运营商token
+ (NSString *)TTAOneKeyLoginWithTokenURLString;

//  一键登录获取手机号
+ (NSString *)TTAOneKeyLoginGetPhoneNumberURLString;

//  以ticket进行一键登录
+ (NSString *)TTAOneKeyLoginURLString;

// 仅登录接口，取号后使用，新用户拦截
+ (NSString *)TTAOneKeyLoginOnlyURLString;

// 获取用户基础信息后，注册
+ (NSString *)TTAOneKeyLoginContinueURLString;

//  手机号注册
+ (NSString *)TTARegisterURLString;

//  手机号和Token登录
+ (NSString *)TTAPhoneTokenLoginURLString;

///  手机号验证码登录（快速登录,未注册用户自动注册）
+ (NSString *)TTAQuickLoginURLString;

///  手机号验证码登录（快速登录，未注册用户返回用户不存在）
+ (NSString *)TTAQuickLoginOnlyURLString;

/// 配合TTAQuickLoginOnlyURLString 使用
+ (NSString *)TTAQuickLoginOnlyContinueURLString;

/// 游客登录 https://doc.bytedance.net/docs/177/266/28214/
+ (NSString *)TTADeviceLoginURLString;

//  退出登录
+ (NSString *)TTALogoutURLString;

//  绑定手机号V1
+ (NSString *)TTABindPhoneV1URLString;

//  绑定手机号
+ (NSString *)TTABindPhoneURLString;

/// 校验手机号是否可用
+ (NSString *)TTACheckPhoneUseableURLString;

/// 是否有其它登录方式
+ (NSString *)TTAAvailableLoginWaysURLString;

/// 手机密码验证
+ (NSString *)TTAAccountVerifyURLString;

/// 手机仅注册，不会生成用户信息，不会产生登录态
+ (NSString *)TTAMobileGenerateUserTicketURLString;

/// 手机号注册后登录
+ (NSString *)TTAMobileLoginByTicketURLString;

/// 手机号对应的账号是否已设置过密码
+ (NSString *)TTAMobileHasSetPassword;

//通过运营商token一键绑定手机号,V1
+ (NSString *)TTAOneKeyBindPhoneV1URLString;

//通过运营商token一键绑定手机号
+ (NSString *)TTAOneKeyBindPhoneURLString;

// 手机号绑游客
+ (NSString *)TTABindVistorAccountURLString;

//  解绑手机号
+ (NSString *)TTAUnbindPhoneURLString;

//  获取用户信息
+ (NSString *)TTAGetUserInfoURLString;

//  刷新图片验证码
+ (NSString *)TTARefreshCaptchaURLString;

//  获取短信验证码
+ (NSString *)TTAGetSMSCodeURLString;

//  验证短信接口
+ (NSString *)TTAValidateSMSCodeURLString;

//  修改密码
+ (NSString *)TTAModifyPasswordURLString;

//验证短信验证码接口（目前只用在重置密码）
+ (NSString *)TTACheckSMSCodeString;

//使用ticket重置密码接口
+ (NSString *)TTAResetPasswordByTicketString;

///  设置密码，仅支持quick_login之后的调用，并且会校验当前的登录状态https://wiki.bytedance.net/pages/viewpage.action?pageId=179436241
+ (NSString *)TTASetPasswordURLString;

//  重置密码
+ (NSString *)TTAResetPasswordURLString;

//  修改手机号
+ (NSString *)TTAChangePhoneNumberURLString;

//  检查用户名
+ (NSString *)TTACheckNameURLString;

//  获取用户审核信息
+ (NSString *)TTAGetUserAuditInfoURLString;

//  更新用户Profile
+ (NSString *)TTAUpdateUserProfileURLString;

//  更新用户Extra Profile字段（province, city, birthday, gender）
+ (NSString *)TTAUpdateUserExtraProfileURLString;

//  上传用户照片
+ (NSString *)TTAUploadUserPhotoURLString;

+ (NSString *)TTAUploadUserImageURLString;

//  上传用户封面背景图
+ (NSString *)TTAUploadUserBgImageURLString;

//  请求新的回话
+ (NSString *)TTARequestNewSessionURLString;

//  解绑第三方平台
+ (NSString *)TTALogoutThirdPartyPlatformURLString;

// 多帐号切换
+ (NSString *)TTASwitchAccountURLString;

// 在接入多帐号功能的前提下，当登录某帐号时需要踢掉其他帐号的登录态，可以使用本接口
+ (NSString *)TTALogoutOtherAccountsURLString;

// 在接入多帐号功能的前提下，需要踢掉某个账号的登录态时，可使用本接口
+ (NSString *)TTARemoveAccountURLString;

/**
 不同系统之间的登录换票接口

 @return 接口完整的URL字符串
 */
+ (NSString *)TTAauthSwitchTicketString;

///  取消注销，并进行登录
+ (NSString *)TTACancelLogoutURLString;

# pragma mark - 扫码授权登录相关

/// 获取验证码
+ (NSString *)TTAGetQrCodeURLString;

/// 检测二维码状态
+ (NSString *)TTACheckQrCodeURLString;

/// 扫描二维码
+ (NSString *)TTAScanQrCodeURLString;

/// 确认授权登录
+ (NSString *)TTAConfirmLoginByQrCodeURLString;

# pragma mark - 登录方式相关

+ (NSString *)deviceLoginIngoURLString;

+ (NSString *)trustedDeviceOnekeyLoginURLString;

+ (NSString *)canDeviceOnekeyLoginURLString;

+ (NSString *)trustedDeviceOnekeyLoginContinueURLString;


#pragma mark - path of URL

//  手机号和Token登录
+ (NSString *)TTAPhoneTokenLoginURLPathString;

//  密码登录
+ (NSString *)TTALoginURLPathString;

//  退出登录
+ (NSString *)TTALogoutURLPathString;

//  绑定手机号V1接口
+ (NSString *)TTABindPhoneV1URLPathString;

//  绑定手机号
+ (NSString *)TTABindPhoneURLPathString;

//通过运营商token一键绑定手机号V1接口
+ (NSString *)TTAOneKeyBindPhoneV1URLPathString;

//通过运营商token一键绑定手机号
+ (NSString *)TTAOneKeyBindPhoneURLPathString;

//  解绑手机号
+ (NSString *)TTAUnbindPhoneURLPathString;

//  获取登录用户的信息
+ (NSString *)TTAGetUserInfoURLPathString;

//  刷新图片验证码
+ (NSString *)TTARefreshCaptchaURLPathString;

//  验证短信验证码
+ (NSString *)TTAValidateSMSCodeURLPathString;

//  修改密码
+ (NSString *)TTAModifyPasswordURLPathString;

//  重置密码
+ (NSString *)TTAResetPasswordURLPathString;

//  修改用户手机号
+ (NSString *)TTAChangePhoneNumberURLPathString;

//  检查用户名
+ (NSString *)TTACheckNameURLPathString;

//  获取用户审核信息
+ (NSString *)TTAGetUserAuditInfoURLPathString;

//  更新用户Profile
+ (NSString *)TTAUpdateUserProfileURLPathString;

//  更新用户Extra字段（province, city, birthday, gender）
+ (NSString *)TTAUpdateUserExtraProfileURLPathString;

//  上传用户照片
+ (NSString *)TTAUploadUserPhotoURLPathString;

//  上传用户图像（NEW)
+ (NSString *)TTAUploadUserImageURLPathString;

//  上传用户封面背景图
+ (NSString *)TTAUploadUserBgImageURLPathString;

//  请求新的回话
+ (NSString *)TTARequestNewSessionURLPathString;

//  解绑第三方帐号
+ (NSString *)TTALogoutThirdPartyPlatformURLPathString;

/// 结合第三方的，先第三方登录，发现是新用户，就hold住，让客户端绑定手机号，然后创建新用户，同时登录
+ (NSString *)TTAPhoneBindAndloginURLString;

// 查询用户是否可修改用户信息
+ (NSString *)TTACheckUserCanSetURLString;

// 获取三方用户信息
+ (NSString *)TTAGetThirdPartUserInfoURLString;

// 查看是否默认头像和昵称
+ (NSString *)TTACheckDefaultUserInfoURLString;

#pragma mark - 邮箱注册、登录相关

// 邮箱注册，后面废弃
+ (NSString *)TTAEmailRegisterURLString;

// 邮箱注册v2
+ (NSString *)TTAEmailRegisterV2URLString;

// 验证邮箱是否可用
+ (NSString *)TTAValidateEmailURLString;

// 发送邮箱验证码
+ (NSString *)TTAEmailSendCodeURLString;

// 邮箱验证后注册或登录
+ (NSString *)TTAEmailRegisterVerifyLoginURLString;

// 通过邮箱重置密码获得ticket
+ (NSString *)TTAResetPasswordByEmailCheckCodeURLString;

// 通过邮箱重置密码获得ticket
+ (NSString *)TTAResetPasswordByEmailTicketURLString;

# pragma mark - session续期改版

///// 改版后的session 续期接口
+ (NSString *)TTATokenBeatURLString;

//提供邮箱注册&登录能力
+ (NSString *)TTAEmailRegisterVerifyURLString;

// 绑定邮箱
+ (NSString *)TTAEmailBindURLString;

@end



@interface TTAccountURLSetting (InterfaceV2)

#pragma mark - URL Path

//  手机号注册接口
+ (NSString *)TTAPhoneRegisterV2URLPathString;

//以下三个接口为手机快捷登录相关接口 https://wiki.bytedance.net/pages/viewpage.action?pageId=181592821
///  验证码登录接口（默认注册）
+ (NSString *)TTAPhoneSMSLoginV2URLPathString;

///  验证码登录接口（仅登录，未注册用户返回用户不存在）
+ (NSString *)TTAPhoneSMSLoginOnlyV2URLPathString;

/// 手机快速登录（配合sms_login_only场景）
+ (NSString *)TTAPhoneSMSLoginContinueV2URLPathString;

//  手机号发送验证码接口
+ (NSString *)TTAGetSMSCodeV2URLPathString;

/// 手机注册登录，如果当前手机号已注册，则正常登录；如果未注册，则先走注册流程再走登录流程
+ (NSString *)TTAPhoneBindAndloginURLPathString;

#pragma mark - 邮箱注册、登录相关

// 邮箱注册，后面废弃
+ (NSString *)TTAEmailRegisterURLPathString;

// 邮箱注册v2接口
+ (NSString *)TTAEmailRegisterV2URLPathString;

// 验证邮箱是否可用
+ (NSString *)TTAValidateEmailURLPathString;

// 发送邮箱验证码
+ (NSString *)TTAEmailSendCodeURLPathString;

// 验证邮箱验证码
+ (NSString *)TTAEmailRegisterVerifyLoginURLPathString;

// 通过邮箱重置密码获得ticket
+ (NSString *)TTAResetPasswordByEmailCheckCodeURLPathString;

//通过邮箱获得ticket重置密码
+ (NSString *)TTAResetPasswordByEmailTicketURLPathString;

// 登录态绑定邮箱并设置密码
+ (NSString *)TTABindEmailAndSetPWDURLString;

/// 登陆态下的验证邮箱
+ (NSString *)TTAEmailVerifyURLString;

# pragma mark - 扫码授权登录相关 http://doc.bytedance.net/docs/177/266/4291/

/// 获取验证码
+ (NSString *)TTAGetQrCodeURLPathString;

/// 检测二维码状态
+ (NSString *)TTACheckQrCodeURLPathString;

/// 扫描二维码
+ (NSString *)TTAScanQrCodeURLPathString;

/// 确认授权登录
+ (NSString *)TTAConfirmLoginByQrCodeURLPathString;

# pragma mark - session续期改版
/// 改版后的session 续期接口
+ (NSString *)TTATokenBeatURLPathString;

# pragma mark - 第三方相关

//  第三方绑定,产生新的用户
+ (NSString *)TTAPlatformAuthBindV2URLPathString;

//  第三方平台登录或绑定时解绑接口
+ (NSString *)TTAPlatformAuthSwitchBindV2URLPathString;


@end

NS_ASSUME_NONNULL_END
