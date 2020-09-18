//
//  TTAccountAuthRespModel.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 3/31/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountBaseModel.h"
#import "TTAccountRespModel.h"



/**
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=1148503#id-享评SDK2.0-享评SDK2.0-客户端SNSSSO成功后回调
 *         https://wiki.bytedance.net/pages/viewpage.action?pageId=53809581#id-用户登录相关API-SSO回调/sso_callback
 *
 */
#pragma mark - SNS SDK Login Callback
/**
 *  SNSSDK Callback DataModel
 */
@interface TTASNSSDKAuthCallbackModel : TTAUserModel

/* 错误类型 [connect_switch：绑定冲突; login_failed：绑定失败; connect_exist：第三方授权帐号绑定冲突]) */
//@property (nonatomic,   copy) NSString *name;

/** 登录状态，用于下次免授权，缓存10分钟 */
@property (nonatomic,   copy) NSString *auth_token;

/** 用户选择是解绑老帐号还是登录老帐号时显示提示 */
@property (nonatomic,   copy) NSString *dialog_tips;

@end

@interface TTASNSSDKAuthSilentRegisterModel : TTADataRespModel
@property (nonatomic,   copy) NSString *ticket;
@end

@interface TTASNSSDKAuthSilentRegisterRespModel : TTABaseRespModel
@property (nonatomic, strong) TTASNSSDKAuthSilentRegisterModel *data;
@end

/**
 *  SNSSDK Callback ResponseModel
 */
@interface TTASNSSDKAuthCallbackRespModel : TTABaseRespModel

/** 用于去飞飞平台换取用户信息 */
@property (nonatomic,   copy) NSString *session_key;

/** 是否新用户 */
@property (nonatomic, assign) BOOL new_user;

/**  是否是新授权的平台 */
@property (nonatomic, assign) BOOL new_platform;

/** 是否需要绑定手机号 [0: 不需要绑定；1: 推荐绑定；2：强制绑定] */
@property (nonatomic, strong) NSNumber *should_bind_mobile;

/** 数据信息 */
@property (nonatomic, strong) TTASNSSDKAuthCallbackModel *data;

/**
 *  第三方平台已绑定其它头条帐号冲突
 */
- (BOOL)isBindConflict;

/**
 *  已有第三方授权帐号绑定过当前头条帐号
 */
- (BOOL)isAuthPlatformConflict;

/**
 *  第三方平台绑定失败
 */
- (BOOL)isBindFailed;

@end



#pragma mark - SNSSDK Auth SwitchBind

/**
 *  SNSSDK SwitchBind ResponseModel
 *
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=53809581#id-用户登录相关API-SSO回调/sso_callback
 *
 *  返回值和sso_callback一样
 */
@interface TTASNSSDKAuthSwitchBindRespModel : TTASNSSDKAuthCallbackRespModel

@end



#pragma mark - Custom WAP Auth SwitchBind

/**
 *  Custom WAP Auth SwitchBind ResponseModel
 */
@interface TTACustomWAPAuthSwitchBindRespModel : TTASNSSDKAuthCallbackRespModel

@end



#pragma mark - Custom WAP Auth [snssdk***://callback] 重定向数据
/**
 *  [Custom WAP Login] login_success > redirect to <snssdk***://callback?>
 */
@interface TTACustomWapAuthCallbackModel : TTADataRespModel
/** 错误码 */
@property (nonatomic, assign) NSInteger error_code;
/** 错误描述 */
@property (nonatomic,   copy) NSString *error_description;

@property (nonatomic,   copy) NSString *dialog_tips;

/** 错误类型 [connect_switch：绑定冲突; login_failed：绑定失败] */
@property (nonatomic,   copy) NSString *error_name; // error_name

@property (nonatomic,   copy) NSString *name; // name

/** 头条平台生成的Session Key，有有效期 */
@property (nonatomic,   copy) NSString *session_key;

/** 第三方平台返回的授权码 */
@property (nonatomic,   copy) NSString *code;

/** 调用第三方平台授权时带过去的参数，第三方平台授权后回传过来，用于校验的CSRF攻击 */
@property (nonatomic,   copy) NSString *state;

@property (nonatomic,   copy) NSString *auth_token;

/** 授权的第三方平台是否是新平台 */
@property (nonatomic, assign) BOOL new_platform;

/** 是否是头条帐号系统的新用户 */
@property (nonatomic, assign) BOOL new_user;

@property (nonatomic, copy) NSDictionary *otherInfo;

@end

@interface TTACustomWapAuthCallbackRespModel : TTABaseRespModel
/** Wap认证回调数据 */
@property (nonatomic, strong) TTACustomWapAuthCallbackModel *data;

- (instancetype)initWithWapAuthCallbackURL:(NSURL *)URL;

/**
 *  第三方平台已绑定过其它头条帐号冲突
 */
- (BOOL)isBindConflict;

/**
 *  已有第三方授权帐号绑定过当前头条帐号
 */
- (BOOL)isAuthPlatformConflict;

/**
 *  出现第三方平台绑定失败
 */
- (BOOL)isBindFailed;

@end



#pragma mark - 绑定该App官方帐号到第三方平台

@interface TTShareAppToSNSPlatformModel : TTADataRespModel

@end

@interface TTShareAppToSNSPlatformRespModel : TTABaseRespModel

@property (nonatomic, strong) TTShareAppToSNSPlatformModel *data;

@end


