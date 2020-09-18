//
//  TTAccountRequestModel.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/10/17.
//

#import <Foundation/Foundation.h>
#import "TTAccountSMSCodeDef.h"
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 手机号相关

/// 校验手机号是否可用 https://doc.bytedance.net/docs/177/266/21639/
@interface TTACheckMobileUseableRequestModel : NSObject

@property (nonatomic, copy, nonnull) NSString *mobile;    /// 手机号字符串
@property (nonatomic, copy, nullable) NSString *authToken;  /// 身份验证票据，非登录态下查询必传
@property (nonatomic, copy, nullable) NSString *notLoginTicket;  /// 非登录态下查询必传

@end

/// 用户可验证登录方式 https://doc.bytedance.net/docs/177/266/21662/
@interface TTAOauthAvailableWaysRequestModel : NSObject

@property (nonatomic, assign) NSInteger needLimitPlatform;    /// 某些app不支持特定三方验证，需要联系passport oncall配置

@property (nonatomic, copy, nullable) NSString *notLoginTicket;  /// 身份验证票据，非登录态下查询必传

@end


/// 账密验证 https://doc.bytedance.net/docs/177/266/18116/
@interface TTAAccountVerifyRequestModel: NSObject

@property (nonatomic, copy, nullable) NSString *mobile;  /// 手机号，与username、email三选一必填（二次验证场景不必须）
@property (nonatomic, copy, nullable) NSString *email;  /// 邮箱，与username、mobile三选一必填（二次验证场景不必须）
@property (nonatomic, copy, nullable) NSString *userName;  ///用户名，与email、mobile三选一必填（二次验证场景不必须）
@property (nonatomic, copy, nonnull) NSString *password;    /// 密码
@property (nonatomic, copy, nullable) NSString *verifyTicket;  /// 帐号相关场景需要二次验证时产生,非必须

@end

/// 发送手机验证码 https://doc.bytedance.net/docs/177/266/3409/
@interface TTASendCodeRequestModel: NSObject

///命中频控，did黑名单，未通过反作弊监测，非最近使用设备登录都会触发图片验证码；手机号白名单永远不会触发
@property (nonatomic, copy, nullable) NSString *captcha;
@property (nonatomic, copy, nullable) NSString *mobile;  /// 手机号
@property (nonatomic, assign) TTASMSCodeScenarioType smsCodeType; /// 验证码类型
@property (nonatomic, assign) BOOL unbindExist; /// 是否解绑已存在绑定，smsCodeType = TTASMSCodeSceneBind
@property (nonatomic, copy, nullable) NSString *oldMbile; /// 用户旧手机号
@property (nonatomic, assign) BOOL isNeedMix; ///是否需要对mobile、smsCodeType、unbindExist、oldMbile 进行混淆,默认混淆
/// 验证成功的票据，适用于换绑场景，第一步需要校验当前手机号，返回ticket；第二步换绑发送短信，需要校验ticket的合法性；
@property (nonatomic, copy, nullable) NSString *ticket; /// 换绑，原手机号正常必传
@property (nonatomic, copy, nullable) NSString *authToken; /// 换绑场景，原手机不可用，必传,手机密码验证返回
/// 换绑场景，原手机不可用，必传,检测二次手机号不可用时返回
@property (nonatomic, copy, nullable) NSString *unUseableMobileTickt;
@property (nonatomic, assign) BOOL checkRegister; /// 是否校验手机号已注册，默认校验
@property (nonatomic, copy, nullable) NSString *verifyTicket; /// 二次验证票据
@property (nonatomic, copy, nullable) NSDictionary *extraInfo; /// 额外特殊需求参数

@end

/// 换绑手机号 https://doc.bytedance.net/docs/177/266/3253/
@interface TTAChangeMobilRequestModel: NSObject

///命中频控，did黑名单，未通过反作弊监测，非最近使用设备登录都会触发图片验证码；手机号白名单永远不会触发
@property (nonatomic, copy, nullable) NSString *captcha;
@property (nonatomic, copy, nonnull) NSString *mobile;  /// 手机号
@property (nonatomic, copy, nonnull) NSString *codeString; /// 验证码
/// 验证成功的票据，适用于换绑场景，第一步需要校验当前手机号，返回ticket；第二步换绑发送短信，需要校验ticket的合法性；
@property (nonatomic, copy, nullable) NSString *ticket; /// 换绑，原手机号正常必传
@property (nonatomic, copy, nullable) NSString *authToken; /// 换绑场景，原手机不可用，必传,手机密码验证返回
/// 换绑场景，原手机不可用，必传,检测二次手机号不可用时返回
@property (nonatomic, copy, nullable) NSString *unUseableMobileTickt;

@end


// 校验手机号验证码
@interface TTAValidateMobilCodeRequestModel: NSObject

@property (nonatomic, copy, nonnull) NSString *mobile;  /// 手机号
@property (nonatomic, copy, nonnull) NSString *codeString; /// 验证码
@property (nonatomic, assign) TTASMSCodeScenarioType smsCodeType; /// 验证码类型
@property (nonatomic, assign) BOOL needMix;    /// 是否需要混淆手机号、验证码等，默认需要
@property (nonatomic, copy, nullable) NSString *verifyTicket; /// 帐号相关场景需要二次验证时产生
@property (nonatomic, copy, nullable) NSDictionary *extraDic; /// 备用信息，特殊场景业务传入后直接透传给后端

@end

#pragma mark - 可信环境一键登录
@interface TTADeviceLoginRequestModel : NSObject

@property (nonatomic, copy) NSString *secUserId; ///  客户端缓存用户sec_user_id
@property (nonatomic, copy) NSString *userId; ///  客户端缓存用户user_id，已废弃
@property (nonatomic, assign) BOOL hasEncrypted; /// user_id 是否经过kms加密，默认不混淆，已废弃
@property (nonatomic, copy) NSString *dTicket;  ///  cookie中的d_ticket，cookie能带则不用此参数，传此参数必须混淆
@property (nonatomic, assign) TTAccountLoginType loginType; /// 用户上次一登录方式
@property (nonatomic, assign) NSInteger loginTime; /// 上一次登录时间，秒戳
@property (nonatomic, copy) NSString *loginPlatform; ///  如果上一次登陆方式为三方登陆，需要传对应的platform
@property (nonatomic, copy) NSDictionary *extraInfo; ///  备用信息，特殊场景业务方直接传入，SDK 透传
@end

@interface TTACheckHasPasswordRequestModel: NSObject
@property (nonatomic, copy, nonnull) NSString *mobile;  /// 手机号
@property (nonatomic, copy, nullable) NSString *target; /// 目表场景值，用于风控
@property (nonatomic, assign) BOOL needMix;    /// 是否需要混淆手机号、验证码等，默认需要
@property (nonatomic, copy, nullable) NSDictionary *extraDic; /// 备用信息，特殊场景业务传入后直接透传给后端

@end



NS_ASSUME_NONNULL_END
