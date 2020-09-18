//
//  TTAccount+NetworkTasks.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TTAccount.h"
#import "TTHttpTask.h"
#import "TTAccountDeviceLoginInfo.h"
#import "TTAccountRequestModel.h"
#import "TTAccountDataModel.h"
NS_ASSUME_NONNULL_BEGIN

@class TTAGetThridPartUserInfoModel;

/**
 * @Wiki:  https://wiki.bytedance.net/pages/viewpage.action?pageId=13961678
 */
@interface TTAccount (NetworkTasks)

#pragma mark - 帐号注销提供身份认证接口
/**
 *  帐号注销提供身份认证接口    passport/cancel/post/
 *
 *  @param  idUri1     身份证图片地址(可选)
 *  @param  idUri2     身份证图片地址(可选)
 *  @param  applyUri   申请函地址
 *  @param  ticket     手机验证返回的ticket
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)cancelPostWithIdUri1:(NSString * _Nonnull)idUri1
                                                   idUri2:(NSString * _Nonnull)idUri2
                                                 applyUri:(NSString * _Nullable)applyUri
                                                   ticket:(NSString * _Nullable)ticket
                                               completion:(void(^)(NSString * _Nullable description, NSError * _Nullable error))completedBlock;

/**
 *  帐号注销提供身份认证接口(返回的block提供更多的参数:把接收到的json全部返回  /passport/cancel/post/
 *
 *  @param  idUri1     身份证图片地址(可选)
 *  @param  idUri2     身份证图片地址(可选)
 *  @param  applyUri   申请函地址
 *  @param  ticket     手机验证返回的ticket
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)cancelPostWithIdUri1:(NSString * _Nonnull)idUri1
                                                   idUri2:(NSString * _Nonnull)idUri2
                                                 applyUri:(NSString * _Nullable)applyUri
                                                   ticket:(NSString * _Nullable)ticket
                                               completionNew:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;

/**
 *  帐号注销取消注销  /passport/cancel/do/
 *
 *  @param  type   1 注销 0 放弃
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)cancelAccountWithType:(int)type completion:(void(^)(NSString * _Nullable description, NSError * _Nullable error))completedBlock;

/**
 *  帐号注销取消注销  /passport/cancel/do/
 *
 *  @param  type   1 注销 0 放弃
 *  @param  token   登录请求中注销阻塞返回的token

 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)cancelAccountWithType:(TTAccountCancelScene)cancelScene
                                                     token:(NSString * _Nullable)token
                                                completion:(void(^)(NSString * _Nullable description, NSError * _Nullable error))completedBlock;

/// 新用户注销流程第一步，判断用户的价值并返回可用的身份验证方式 https://doc.bytedance.net/docs/177/266/16981/
/// @param completedBlock 结果回调
/// @return HTTP请求任务
+ (nullable id<TTAccountSessionTask>)cancelCheckUserWithCompletion:(void(^)(TTADataAccountValueModel * _Nullable dataModel, NSError * _Nullable error))completedBlock;

/// 新注销流程，账号注销条件判断 https://doc.bytedance.net/docs/177/266/16982/
/// @param ticket 用户价值接口返回的票据
/// @param extraInfo 其它额外参数，便于扩展
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)cancelCheckWithTicket:(NSString * _Nullable)ticket
                                                     extraInfo:(NSDictionary * _Nullable)extraInfo
                                                completion:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;

/// 账号注销确认 https://doc.bytedance.net/docs/177/266/16983/
/// @param valueTicket 用户价值返回的ticket
/// @param token 手机，第三方，账密认证返回的token或者ticket
/// @param cancelTicket 注销条件验证ticket
/// @param extraInfo 其它额外参数，根据业务需要添加
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)cancelConfirmWithValueTicket:(NSString * _Nonnull)valueTicket
                                                            token:(NSString * _Nullable)token
                                                     cancelTicket:(NSString * _Nullable)cancelTicket
                                                     extraInfo:(NSDictionary * _Nullable)extraInfo
                                                       completion:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;

/// 非低价值账号，账密验证 https://doc.bytedance.net/docs/177/266/25029/
/// @param account 用户名、手机号、邮箱 之一
/// @param passwordString 密码
/// @param accountType 账号类型
/// @param extraInfo 其它额外参数，便于特殊业务扩展
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)cancelPWDAuthorizeWithAccount:(NSString * _Nonnull)account
                                             password:(NSString * _Nonnull)passwordString
                                          accountType:(TTAPWDLoginType)accountType
                                            extraInfo:(NSDictionary * _Nullable)extraInfo
                                                        completion:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;

/// 非低价值账号，三方验证 https://wiki.bytedance.net/pages/viewpage.action?pageId=189657082
/// @param params 认证参数 , 废弃参数 verify_user_id， 新增uid加密参数 sec_verify_user_id，/passport/vcd/get_auth_account/ 下发 sec_user_id 字段
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)cancelAuthAuthorizeWithParams:(NSDictionary * _Nonnull)params
                                                        completion:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;

/**
 *  帐号注销跳转页面接口 /passport/cancel/index/
 *
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
//+ (nullable id<TTAccountSessionTask>)cancelIndexWithCompletion:(void(^)(NSString * _Nullable description, NSError * _Nullable error))completedBlock;
+ (nullable id<TTAccountSessionTask>)cancelIndexWithCompletion:(void(^)(id _Nullable jsonObj, NSError * _Nullable error))completedBlock;
//+ (nullable TTHttpTask *)cancelIndexWithCompletion:(void(^)(id jsonObj, NSError * _Nullable error))completedBlock;

#pragma mark 帐号/手机号/用户名/邮箱+密码登录
/**
 *  使用统一的帐号和密码进行登录(传入什么字段自定义)   /passport/user/login/
 *
 *  @param  account         统一帐号
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @param  accountType     账户形式:username,email,mobile,account其中之一
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)loginWithAccount:(NSString * _Nonnull)account
                                             password:(NSString * _Nonnull)passwordString
                                              captcha:(NSString * _Nullable)captchaString
                                          accountType:(TTAPWDLoginType)accountType
                                           completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;
#pragma mark 手机验证码发送与验证
/**
 *  获取短信认证码【New】/passport/mobile/send_code
 *
 *  @param  phoneString     新手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  unbind          是否解绑已有的绑定关系（0不解绑，1解绑）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)sendSMSCodeWithPhone:(NSString * _Nullable)phoneString /* 某些类型从sessionid中取用户，然后取绑定的手机号 */
                                                  captcha:(NSString * _Nullable)captchaString
                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                              unbindExist:(BOOL)unbind
                                               completion:(void(^)(NSNumber * _Nullable retryTime /* 过期时间 */, UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;

/**
 *  获取短信认证码 /passport/mobile/send_code
 *
 *  @param  phoneString     新手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  extraInfo       额外特殊需求
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)sendSMSCodeWithPhone:(NSString * _Nullable)phoneString /* 某些类型从sessionid中取用户，然后取绑定的手机号 */
                                                  captcha:(NSString * _Nullable)captchaString
                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                              extraInfo:(NSDictionary * _Nullable)extraInfo
                                               completion:(void(^)(id _Nullable data, NSError * _Nullable error))completedBlock;

/**
 *  换绑手机号   /passport/mobile/send_code
 *
 *  @param  phoneString     新手机号
 *  @param  phoneString     旧手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  unbind          是否解绑已有的绑定关系（0不解绑，1解绑）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)sendSMSCodeWithPhone:(NSString * _Nullable)phoneString /* 某些类型从sessionid中取用户，然后取绑定的手机号 */
                                                oldMobile:(NSString *)oldPhoneString
                                                  captcha:(NSString * _Nullable)captchaString
                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                              unbindExist:(BOOL)unbind
                                               completion:(void(^)(NSNumber * _Nullable retryTime /* 过期时间 */, UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;
/**
 *  检验短信验证码的接口（目前只用在重置密码场景）/passport/mobile/check_code/
 *
 *  @param  mobileString    手机号
 *  @param  codeString      短信验证码
 *  @param  codeType        短信验证码类型
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestCheckSMSCodeWithMobile:(NSString *)mobileString
                                                           SMSCode:(NSString *)codeString
                                                          codeType:(NSUInteger)type
                                                        completion:(void(^)(NSDictionary * _Nullable data, NSError * _Nullable error)) completedBlock;

#pragma mark - 使用ticket重置密码
/**
 *  验证短信验证码(带有ticket的新接口)/passport/mobile/validate_code/
 *
 *  @param  codeString      短信验证码
 *  @param  codeType        验证码类型
 *  @param  captchaString   图形验证码
 *  @parem  needTicket      需要返回票据身份的带上1
 *  @param  scene           业务场景
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)validateSMSCode:(NSString * _Nonnull)codeString
                                         SMSCodeType:(TTASMSCodeScenarioType)codeType
                                             captcha:(NSString * _Nullable)captchaString
                                          needTicket:(int)needTicket
                                               scene:(int)scene
                                          completion:(void(^)(UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

#pragma mark 密码设置相关
/**
 *  通过ticket重置密码 /passport/password/reset_by_ticket/
 *
 *  @param  password    新密码
 *  @param  ticket      上面接口返回的ticket
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestResetPasswordByTicketWithPassword:(NSString *)password
                                                                       ticket:(NSString *)ticket
                                                                   completion:(void(^)(NSError * _Nullable error)) completedBlock;
/**
 *  新用户设置密码 /passport/password/set/
 *
 *  @param  passwordString      密码
 *  @param  captchaString       图形验证码
 *  @param  completedBlock      完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)setPasswordWithPassword:(NSString *)passwordString
                                            captcha:(NSString * _Nullable)captchaString
                                         completion:(void (^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  重置密码/找回密码 /passport/password/reset/
 *
 *  @param  phoneString     手机号
 *  @param  codeString      短信验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)resetPasswordWithPhone:(NSString *)phoneString
                                           SMSCode:(NSString *)codeString
                                          password:(NSString *)passwordString
                                           captcha:(NSString *)captchaString
                                completionWithJosn:(void(^)(UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  修改密码 /passport/password/change/
 *
 *  @param  passwordString  新的密码
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)modifyPasswordWithNewPassword:(NSString * _Nonnull)passwordString
                                                           SMSCode:(NSString * _Nonnull)codeString
                                                           captcha:(NSString * _Nullable)captchaString
                                                        completion:(void(^)(UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;

#pragma mark - 手机绑定相关新增
/// 查询用户手机号是否为停机状态 https://doc.bytedance.net/docs/177/266/21639/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)checkPhoneIsUseableWithModel:(TTACheckMobileUseableRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error, TTADataCheckMobileUseableModel * _Nullable dataModel))completedBlock;

/// 查询用户可用验证的登录方式 https://doc.bytedance.net/docs/177/266/21662/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)fetchAvailableWaysWithModel:(TTAOauthAvailableWaysRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error, TTADataUseableLoginWaysModel * _Nullable dataModel))completedBlock;

/// 账密二次验证 https://doc.bytedance.net/docs/177/266/18116/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)verifyAccountWithModel:(TTAAccountVerifyRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error,NSString * _Nullable ticket))completedBlock;


/// 获取短信验证码，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)getSMSCodeWithModel:(TTASendCodeRequestModel * _Nonnull)requestModel
                                completion:(void(^)(NSNumber * _Nullable retryTime /* 过期时间 */, UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;

/// 获取短信验证码，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)getSMSCodeWithModel:(TTASendCodeRequestModel * _Nonnull)requestModel
                                jsonCompletion:(void(^)(NSError * _Nullable error,id _Nullable jsonObj))completedBlock;

/// 换绑手机，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)changeUserPhoneWithModel:(TTAChangeMobilRequestModel * _Nonnull)requestModel
                                completion:(void(^)(NSError * _Nullable error, UIImage * _Nullable captchaImage,id _Nullable jsonObj))completedBlock;

/// 手机号仅注册，返回一个ticket，用户可以使用ticket进行继续登录 ，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)generateTicketByPhoneWithModel:(TTAValidateMobilCodeRequestModel *
                                                                     _Nonnull)requestModel
                                                         completion:(void(^)(NSError * _Nullable error, NSString * _Nullable ticket))completedBlock;

/// 手机号使用上面接口的ticket继续登录
/// @param mobile 手机号
/// @param ticket 上面接口返回的ticket
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)loginContinueWithMobile:(NSString * _Nonnull)mobile
                                                      ticket:(NSString * _Nonnull)ticket
                                                  completion:(void(^)(NSError * _Nullable error))completedBlock;

#pragma mark - 手机号验证码登录
/**
 *  使用手机号注册新帐号    /user/mobile/register/v2/
 *
 *  @param  phoneString     手机号
 *  @param  codeString      短信验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)registerWithPhone:(NSString * _Nonnull)phoneString
                                               SMSCode:(NSString * _Nonnull)codeString
                                              password:(NSString * _Nullable)passwordString
                                               captcha:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;

/**
 *  使用手机号和验证码进行登录(新版,与上面相比,回掉的参数更全面,新用户直接注册) passport/mobile/sms_login/
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)quickLoginWithPhone:(NSString * _Nonnull)phoneString
                                                 SMSCode:(NSString * _Nonnull)codeString
                                                 captcha:(NSString * _Nullable)captchaString
                                       jsonObjCompletion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;


/**
 *  使用手机号和验证码进行登录（新用户接口返回sms_code_key，配合下面的continue 接口进行注册登录） /passport/mobile/sms_login_only/
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)quickLoginOnlyWithPhone:(NSString * _Nonnull)phoneString
                                                 SMSCode:(NSString * _Nonnull)codeString
                                                 captcha:(NSString * _Nullable)captchaString
                                           jsonObjCompletion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  使用手机号和验证码进行登录   /passport/mobile/sms_login_continue/
 *  @param  phoneString     手机号
 *  @param  smsCodeKey        验证码校验token
 *  @param  captchaString       图形验证码
 *  @param  completedBlock      登录完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)quickLoginOnlyContinueWithPhone:(NSString * _Nonnull)phoneString
                                                  smsCodeKey:(NSString *)smsCodeKey
                                                 captcha:(NSString * _Nullable)captchaString
                                       jsonObjCompletion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  使用手机号和token进行登录  /user/mobile/token_login/
 *  @param  phoneString     手机号
 *  @param  tokenString     token
 *  @param  captchaString   图形验证码zhoubiyu
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)loginWithPhone:(NSString * _Nonnull)phoneString
                                              token:(NSString * _Nonnull)tokenString
                                            captcha:(NSString * _Nullable)captchaString
                                         completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;


#pragma mark - 绑定手机号
/**
 *  绑定手机号 passwordString长度大于0， /passport/mobile/bind/v2/；passwordString为空 /passport/mobile/bind/v1/
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  passwordString  密码（v1可空，v2以上强制需要）
 *  @param  captchaString   图形验证码
 *  @param  unbindExisted   YES，绑定过则先解绑再绑定，否则直接解绑（已绑定过则报错）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)bindPhoneWithPhone:(NSString * _Nonnull)phoneString
                                                SMSCode:(NSString * _Nonnull)codeString
                                               password:(NSString * _Nullable)passwordString /* v1可空，v2以上强制需要 */
                                                captcha:(NSString * _Nullable)captchaString
                                                 unbind:(BOOL)unbindExisted
                                             completion:(void (^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  修改用户手机号 /passport/mobile/change/v1/
 *
 *  @param  phoneString     新的手机号
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)changePhoneNumber:(NSString * _Nonnull)phoneString
                                               SMSCode:(NSString * _Nonnull)codeString
                                               captcha:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  修改用户手机号 http://doc.bytedance.net/docs/177/266/3253/ passport/mobile/change/v1/
 *
 *  @param  phoneString     新的手机号
 *  @param  ticket          旧手机号通过验证码校验通过后下发的临时凭据
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)changePhoneNumber:(NSString *)phoneString
                                       ticket:(NSString *)ticket
                                      SMSCode:(NSString *)codeString
                                      captcha:(NSString * _Nullable)captchaString
                                   completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;


///  检测手机号对应账号是否设置过密码
/// @param requestModel 参数
/// @param completedBlock 结果回调，
+ (nullable id<TTAccountSessionTask>)checkHasSetPasswordWithModel:(TTACheckHasPasswordRequestModel * _Nonnull)requestModel
                                                       completion:(void(^)(NSError * _Nullable error,BOOL hasSetPassword, id _Nullable originalJsonObj))completedBlock;


#pragma mark - 刷新图片验证码
/**
 *  结合第三方的，先第三方登录，发现是新用户，就hold住，让客户端绑定手机号，然后创建新用户，同时登录 /passport/mobile/bind_login/， 加下注释
 *
 *  @param  phoneNumber         手机号码
 *  @param  codeString          手机验证码
 *  @param  profileKey          login_only接口返回的参数
 *  @param  codeType            验证码类型
 *  @param  captchaString       安全验证码
 *  @param  completion          登录结果回调
 *  @return HTTP请求任务
 */

+ (nullable id<TTAccountSessionTask>)requesetBindAndLogingWithPhonenumber:(NSString *)phoneNumber
                                                                  SMSCode:(NSString *)codeString
                                                               profileKey:(NSString * _Nullable)profileKey
                                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                                                  captcha:(NSString * _Nullable)captchaString
                                                               completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

#pragma mark - 用户信息
/**
 *  获取用户信息
 *
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)getUserInfoWithScene:(TTAccountRequestScenceType)sceneType
                                               completion:(void (^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;


/**
 /// 主端在用
 *  获取用户审核相关信息 /user/profile/audit_info/"
 *
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)getUserAuditInfoWithCompletion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;

/**
 *  获取用户审核相关信息(PGC、UGC)，若收到会话过期不发送错误通知消息 /user/profile/audit_info/"
 *
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)getUserAuditInfoIgnoreDispatchWithCompletion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;


/**
 *  上传图像接口，返回URI，并不会更新当前用户信息 /user/info/pic/upload
 *
 *  @param  image           图片对象
 *  @param  progress        上传图片进度回调
 *  @param  completedBlock  上传图片完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)startUploadImage:(UIImage * _Nonnull)image
                                             progress:(NSProgress * __autoreleasing _Nullable * _Nullable)progress
                                           completion:(void(^)(TTAccountImageEntity * _Nullable imageEntity, NSError * _Nullable error))completedBlock;

/**
 *  更新用户信息 /user/update/user_info/，废弃/2/user/update/v3/
 *
 *  @param  dict            用户信息字段
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 *
 *  dict字段描述如下: {
 *      TTAccountUserNameKey: ***, // 新昵称
 *      TTAccountUserDescriptionKey: ***, 新简介
 *      TTAccountUserAvatarKey: ***, // 新头像链接
 *      TTAccountUserBirthdayKey: ***, // 生日
 *      TTAccountUserProvinceKey: ***, // 省
 *      TTAccountUserCityKey: ***, // 城市
 *      TTAccountUserAreaKey: ***, // 地区：省+城市，建议使用area
 *      TTAccountUserGenderKey: ***, // 性别
 *      TTAccountUserExpendAttrsKey: ***, // 业务侧定制字段，NSDictionary类型，eg:@{@"user_skin_type":@(0),@"user_weight":@(130)}
 *  }
 *
 */
+ (nullable id<TTAccountSessionTask>)updateUserProfileWithDict:(NSDictionary * _Nonnull)dict
                                                    completion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;

/**
*  查询用户是否可修改用户信息 /user/check/can_modify/
*
*  @param  completedBlock  完成回调
*  @return HTTP请求任务
*/
+ (id<TTAccountSessionTask>)startCheckCanSetUserType:(TTAccountUserUpdateType)type
                                          completion:(TTAccountCheckCanSetCompletedBlock)completedBlock;;

/**
*  获取三方用户信息  /user/get/oauth_profile/
*
*  @param  completedBlock  完成回调
*  @param  dict            三方登录需要的参数，参考：https://doc.bytedance.net/docs/177/266/3433/
*  @return HTTP请求任务
*/
+ (id<TTAccountSessionTask>)getThirdpartUserInfoWithDict:(NSDictionary *)dict
                                                   Completion:(void(^)(TTAGetThridPartUserInfoModel *thirdUserInfo, NSError *error))completedBlock;

/**
*  查看是否默认头像和昵称，用于展示修改引导弹框 /user/check/default_info/
*
*  @param  completedBlock  完成回调
*  @param  scene        场景，用来判断返回文案和频控，需要端上调起sdk时传入
*  @return HTTP请求任务
*/
+ (id<TTAccountSessionTask>)startCheckUserDefaultInfoWithScene:(TTAccountCheckUserSceneType)scene
                                                     completion:(void(^)(TTACheckUserInfoCanModifyModel *resModel, NSError *error))completedBlock;

/**
 ** 头条专用
 *  检查用户名是否冲突，并返回推荐的名字 /2/user/check_name/
 *
 *  @param  nameString      用户名字符串
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)checkUsername:(NSString * _Nonnull)nameString
                                        completion:(void(^)(NSString * _Nullable availableName, NSError * _Nullable error))completedBlock;

/**
 /// TODO: 头条专用
 *  更新用户信息 /user/profile/update_extra
 *
 *  @param  dict            用户信息字段
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 *
 *  dict字段描述如下: {
 *          TTAccountUserGenderKey: ***,
 *          TTAccountUserBirthdayKey: ***,
 *          TTAccountUserProvinceKey: ***,
 *          TTAccountUserCityKey: ***,
 *          TTAccountUserIndustryKey: ***,
 *  }
 */
+ (nullable id<TTAccountSessionTask>)updateUserExtraProfileWithDict:(NSDictionary * _Nonnull)dict
                                                         completion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;

/**
 *  上传封面背景图 /2/user/upload_bg_img/, 废弃
 *
 *  @param  image           图片对象
 *  @param  progress        上传图片进度回调
 *  @param  completedBlock  上传图片完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)startUploadUserBgImage:(UIImage * _Nonnull)image
                                                   progress:(NSProgress * _Nullable __autoreleasing * _Nullable)progress
                                                 completion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;


#pragma mark - 退出帐号
/**
 *  退出当前登录账户 /passport/user/logout/
 *  @param logoutScene          调用登出的场景
 *  @param completedBlock       完成后的回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)logoutInScene:(TTAccountLogoutScene)logoutScene
                                        completion:(void(^)(BOOL success, NSError * _Nullable error))completedBlock;

/**
 *  登出账户
 *
 *  @param logoutScene      登出的场景
 *  @param extraInfo        其他有关调用等出的信息，便于追查掉线原因，例如什么接口返回登录态失效
 *  @param completedBlock   完成后的回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)logoutWithScene:(TTAccountLogoutScene)logoutScene
                                                  extraInfo:(NSDictionary * _Nullable)extraInfo
                                                 completion:(void(^)(BOOL success, NSError * _Nullable error))completedBlock;


#pragma mark - 解绑已绑定的第三方平台
/**
 *  退出绑定的第三方平台帐号 /passport/auth/unbind/
 *
 *  @param platformName     第三方平台名称
 *  @param completedBlock   完成后的回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)logoutPlatform:(NSString * _Nonnull)platformName
                                         completion:(void(^)(BOOL success))completedBlock;


#pragma mark - 请求新的会话，用其他应用的session换取新的session给当前应用
/**
 *  用SessionKey和InstallId请求新的会话进行登录 /auth/chain_login/
 *
 *  @param  sessionKey     共享的SessionKey
 *  @param  installId      当前APP的InstallId
 *  @param  completedBlock 注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestNewSessionWithSessionKey:(NSString * _Nonnull)sessionKey
                                                           installId:(NSString * _Nonnull)installId
                                                          completion:(void(^)(TTAccountUserEntity * _Nullable userEntity, NSError * _Nullable error))completedBlock;
#pragma mark - 帐号切换/票据替换
/**
 *  多帐号切换接口 /passport/account/switch/ 废弃
 *
 *  @param  userId     想要切换帐号的userId
 *  @param  completedBlock 注册完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)switchAccountToUserId:(NSString * _Nonnull)userId
                                                          completion:(void(^)(NSError * _Nullable error))completedBlock __attribute__((deprecated("use switchAccountToSecUserId:completion:")));
/**
*  多帐号切换接口 /passport/account/switch/
*
*  @param  secUserId     想要切换帐号的加密userId
*  @param  completedBlock 注册完成回调
*  @return HTTP请求任务
*/
+ (nullable id<TTAccountSessionTask>)switchAccountToSecUserId:(NSString * _Nonnull)secUserId
                                                   completion:(void(^)(NSError * _Nullable error))completedBlock;



/// 在接入多帐号功能的前提下，当登录某帐号时需要踢掉其他帐号的登录态，可以使用本接口。  passport/account/logout_others/ https://doc.bytedance.net/docs/177/266/18641/
/// @param completedBlock  结果回调
+ (nullable id<TTAccountSessionTask>)logoutOtherAccountsWithCompletion:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/// 在接入多帐号功能的前提下，当需要踢掉某个帐号的登录态时，可以使用本接口，废弃
/// @param userId 要移除账号的userId
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)logoutAccountWithUserId:(NSString * _Nonnull)userId
                                                completion:(void(^)(NSError * _Nullable error))completedBlock __attribute__((deprecated("use logoutAccountWithSecUserId:completion:")));

/// 在接入多帐号功能的前提下，当需要踢掉某个帐号的登录态时，可以使用本接口
/// @param secUserId 要移除账号的加密userId
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)logoutAccountWithSecUserId:(NSString * _Nonnull)secUserId
                                                     completion:(void(^)(NSError * _Nullable error))completedBlock;

/**
 *  结合第三方的，先第三方登录，发现是新用户，就hold住，让客户端绑定手机号，然后创建新用户，同时登录
 *
 *  @param  phoneNumber         手机号码
 *  @param  codeString          手机验证码
 *  @param  profileKey          login_only接口返回的参数
 *  @param  codeType            验证码类型
 *  @param  captchaString       安全验证码
 *  @param  completion          登录结果回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requesetBindAndLogingWithPhonenumber:(NSString *)phoneNumber
                                                                  SMSCode:(NSString *)codeString
                                                               profileKey:(NSString * _Nullable)profileKey
                                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                                                  captcha:(NSString * _Nullable)captchaString
                                                               completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 不同系统之间的登录票据替换 /passport/auth/switch_ticket/
 */
+ (nullable id<TTAccountSessionTask>)requestAuthSwitchTicketWithCipher:(NSString *)cipher
                                                            completion:(void(^)(NSError * _Nullable error))completedBlock;

#pragma mark - 一键登录
/// 返回的是当前使用流量卡所属运营商
- (nullable NSString *)service;

/**
 * 注册运营商SDK (前往中国移动开发者社区（dev.10086.cn)，按照文档要求创建开发者帐号并申请appid和appkey)
 *
 *  @param  serviceName 运营商标识: 中国移动 "mobile" , 中国电信 "telecom" , 中国联通 "unicom"
 *  @param  appId  申请的appId
 *  @param  appKey 申请的appKey
 *  @param  isTestChannel  true: InHouse证书， false: 生产环境证书
 */
+ (void)registerOneKeyLoginService:(NSString *)serviceName appId:(NSString *)appId appKey:(NSString *)appKey isTestChannel:(BOOL)isTestChannel;

/**
 一键登录取号和获取token超时设置

 @param timeoutInterval 单位ms（默认3000毫秒）
 */
+ (void)setTimeoutInterval:(NSTimeInterval)timeoutInterval;

/**
 * 发起取号请求，缓存凭证
 */
+ (void)getOneKeyLoginPhoneNumberCompleted:(void(^)(NSString * _Nullable phoneNumber, NSString * _Nullable serviceName, NSError * _Nullable error))completedBlock;

/**
 *  一键登录 "/passport/auth/one_login/
 *
 *  @param  completedBlock  结果回调，成功error为nil
 */
+ (void)oneKeyLoginWithCompleted:(void(^)(NSError * _Nullable error))completedBlock;

/**
 *  一键登录,与上面接口区别在于新用户直接拦截
 *
 *  @param  extranTrackInfo 获取token时业务方自定义需要附加的埋点参数，可空
 *  @param  completedBlock  结果回调，成功error为nil
 */
+ (void)oneKeyLoginOnlyWithExtraTrackInfo:(NSDictionary * _Nullable)extranTrackInfo
                            completed:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  一键登录,新用户被拦截完成一定条件后，继续注册、登录
 *
 *  @param  smsCodeKey 上一步是新用户是返回的key
 *  @param  completedBlock  结果回调，成功error为nil
 */
+ (void)oneKeyLoginContinueWithSMSCodeKey:(NSString * _Nonnull)smsCodeKey
                            completed:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  通过运营商Token一键绑定手机号
 *
 *  @param  passwordString  密码，如果需要强制绑定,则输入密码，否则可以为空
 *  @param  unbindExisted   YES，绑定过则先解绑再绑定，否则直接解绑（已绑定过则报错）
 *  @param  completedBlock  绑定结果回调，error为Null则绑定成功
 */
+ (void)oneKeyBindPhoneWithPassword:(NSString * _Nullable)passwordString
                             unbind:(BOOL)unbindExisted
                          completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 结合第三方的绑定流程，第三方登录调用requestLoginOnlyForPlatform:willLogin:completion,新用户成功返回profileKey
 @param profileKey 新用户授权登录时返回的profileKey
 @param completedBlock
 */
+ (void)oneKeyBindPhoneWithProfileKey:(NSString * _Nullable) profileKey
                            completed:(void(^)(NSError * _Nullable error))completedBlock;


#pragma mark - 邮箱注册/登录/重置密码相关
/**
 *  验证邮箱是否可用 /passport/user/check_email_registered/
 *
 *  @param  emailString     邮箱
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)checkEmailRegistedWithEmail:(NSString *)emailString
                                                captcha:(NSString * _Nullable)captchaString
                                             completion:(void(^)(UIImage * _Nullable captchaImage, BOOL isRegistered, NSError * _Nullable error))completedBlock;
/**
 *  使用邮箱注册新帐号 /passport/email/register/ ，后面会废弃，建议使用/passport/email/register/v2/
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)registerWithEmail:(NSString *)emailString
                                    emailCode:(NSString * _Nullable)codeString
                                     password:(NSString *)passwordString
                                      captcha:(NSString * _Nullable)captchaString
                                   completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  使用邮箱注册新帐号 /passport/email/register/v2/
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  recaptchaTokenString  Google reCapthca验证码,使用google reCaptcha的业务必须填
 *  @param  extra           扩展字段
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)registerV2WithEmail:(NSString *)emailString
                                      emailCode:(NSString * _Nullable)codeString
                                       password:(NSString *)passwordString
                                        captcha:(NSString * _Nullable)captchaString
                                 recaptchaToken:(NSString * _Nullable)recaptchaTokenString
                                          extra:(NSDictionary *_Nullable)extra
                                     completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  获取邮箱验证码 /passport/email/send_code/
 *
 *  @param  emailString     邮箱
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  passwordString  密码,注册必须，绑定不需要
 *  @param  jumpUrl         邮件正文中的跳转链接
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)getEmailCodeWithEmail:(NSString *)emailString
                                    emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         password:(NSString * _Nullable)passwordString
                                          jumpUrl:(NSString * _Nullable)jumpUrl
                                          captcha:(NSString * _Nullable)captchaString
                                       completion:(void(^)(UIImage * _Nullable captchaImage , NSError * _Nullable error))completedBlock;



/**
 *  邮箱注册+登录  /passport/email/register_verify_login/
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  codeType          邮箱验证码类型
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)validateRegisterWithEmail:(NSString * _Nonnull)emailString
                                                  emailCode:(NSString * _Nonnull)codeString
                                           emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         captchaString:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  邮箱注册,只提供注册能力，不能用于老用户登录
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  codeType        邮箱验证码的类型
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)registerWithEmail:(NSString *_Nonnull)emailString
                                                  emailCode:(NSString *_Nonnull)codeString
                                           emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         captchaString:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  邮箱绑定功能
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  codeType        邮箱验证码的类型
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)bindWithEmail:(NSString *_Nonnull)emailString
                                                  emailCode:(NSString *_Nonnull)codeString
                                           emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         captchaString:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error,id _Nullable jsonObj))completedBlock;


#pragma mark - 重置密码时邮箱验证码分步校验
/**
 *  检验邮箱验证码的接口 /passport/email/check_code/，验通过返回ticket ，
 *
 *  @param  emailString    邮箱
 *  @param  codeString     邮箱验证码
 *  @param  codeType       邮箱验证码类型
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestCheckEmailCodeWithEmail:(NSString *)emailString
                                                          emailCode:(NSString *)codeString
                                                      emailCodeType:(TTAEmailCodeScenarioType)codeType
                                                         completion:(void(^)(NSDictionary * _Nullable data, NSError * _Nullable error)) completedBlock;

/**
 *  通过上个接口获得的ticket重置密码 /passport/password/reset_by_email_ticket/
 *
 *  @param  password    新密码
 *  @param  ticket      上面接口返回的ticket
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestEmailResetPasswordByTicketWithPassword:(NSString *)password
                                                                       ticket:(NSString *)ticket
                                                                   completion:(void(^)(NSError * _Nullable error)) completedBlock;

///  登录态下用户绑定邮箱、密码;先绑定邮箱，已经绑定回返回1023,绑定成功后去设置密码，如果已经设置就直接返回成功，不会更新密码
/// @param emailString 邮箱
/// @param passwordString 密码
/// @param completedBlock 完成回调
+ (nullable id<TTAccountSessionTask>)requestBindEmail:(NSString *)emailString
                                      password:(NSString *)passwordString
                                    completion:(void(^)(NSError * _Nullable error,id _Nullable jsonObj))completedBlock;

///  登录态下校验用户绑定的邮箱
/// @param codeString 邮箱验证码
/// @param codeType 验证码类型
/// @param completedBlock 结果回调
+ (id<TTAccountSessionTask>)requestVerifyEmailWithCode:(NSString * _Nonnull)codeString
                                      emailCodeType:(TTAEmailCodeScenarioType)codeType
                                    completion:(void(^)(NSError * _Nullable error,NSString * _Nullable ticket,id _Nullable jsonObj))completedBlock;


#pragma mark - 取消注销操作
/**
 *  通过token 取消注销操作
 *
 *  @param  token       任何登录接口返回错误码1075时，接口返回的token
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)cancelLogoutWithToken:(NSString * _Nonnull)token
                                                completion:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

#pragma mark - 登录方式

+ (nullable id<TTAccountSessionTask>)fetchLatestLoginInfoWithcompletion:(void(^)(TTADeviceLoginUserInfo * _Nullable lastLoginUserInfo, NSError * _Nullable error))completedBlock;

+ (nullable id<TTAccountSessionTask>)fetchDeviceLoginInfoWithType:(TTADeviceLoginInfoType)type
                                                        timeRange:(NSInteger)timeRange
                                                     completetion:(void(^)(NSArray<TTADeviceLoginUserInfo *>  * _Nullable userInfos, NSError *_Nullable error))completedBlock;

/**
 可信设备一键登录， 前提： 所有登录方式使用的是TTAccountSDK ，且[TTAccount accountConf].openCacheLoginInfo = YES

 @param completedBlock 登录结果回调
 @return 网络任务
 */
+ (nullable id<TTAccountSessionTask>)trustedDeviceOnekeyLoginWithCompleted:(void(^)(NSError * _Nullable error))completedBlock;


/**
 可信设备一键登录

 @param dataModel 可信一键登录的参数
 @param completedBlock 登录结果回调
 @return 网络任务
 */
+ (nullable id<TTAccountSessionTask>)trustedDeviceOnekeyLoginWithModel:(TTADeviceLoginRequestModel *)dataModel
                                                    completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 是否可进行一键登录,  前提： 所有登录方式使用的是TTAccountSDK ，且[TTAccount accountConf].openCacheLoginInfo = YES

 @param dataModel 可信一键登录的参数
 @param completedBlock 结果回调,若可以进行可信设备一键登录，则oneLoginTicket 不为空
 @return 网络任务
 */
+ (nullable id<TTAccountSessionTask>)canDeviceOnekeyLoginWithCompleted:(void(^)(NSString * _Nullable oneLoginTicket, NSError * _Nullable error))completedBlock;

///  是否可进行一键登录
/// @param dataModel  可信一键登录的参数
/// @param completedBlock 若可以进行可信设备一键登录，则oneLoginTicket 不为空
+ (nullable id<TTAccountSessionTask>)canDeviceOnekeyLoginWithModel:(TTADeviceLoginRequestModel *)dataModel
                                                         completed:(void(^)(NSString * _Nullable oneLoginTicket, NSError * _Nullable error))completedBlock;

/// 进行一键登录
/// @param ticket 校验一键登录是够可以进行接口返回的ticket
/// @param completedBlock 登录结果
+ (nullable id<TTAccountSessionTask>)trustedDeviceOnekeyLoginContinueWithTicket:(NSString *)ticket
                                                                      completed:(void(^)(NSError * _Nullable error))completedBlock;
/**
 最近一次登录的本地缓存信息

 @return 本地缓存的用户登录信息
 */
+ (nullable TTADeviceLoginUserInfo *)latestLocalDeviceLoginInfo;


/// 获取本地缓存的历史登录信息
/// @param duplicateUid 是否进行进行uid 去重,YES, 去重；NO 不去重
+ (nullable NSArray<TTADeviceLoginUserInfo *> *)fetchHistoryLoginInfoWithDuplicateUid:(BOOL)duplicateUid;

/**
 *  刷新并获取新的图形验证码 /passport/mobile/refresh_captcha/
 *
 *  codeType                验证码类型 （经和服务端确认不需要该参数）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)refreshCaptchaWithCompletion:(void(^)(UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;


/// 用户免注册，直接通过设备以游客身份进行登录 https://doc.bytedance.net/docs/177/266/28214/
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)userDeviceLoginWithCompleted:(void(^)(NSError * _Nullable error))completedBlock;


///  游客账号登录后绑定手机账号
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)bindVistorAccountWithCompleted:(void(^)(NSError * _Nullable error))completedBlock;

#pragma mark - 安全验证相关

///  触发风控后，手机号安全校验 https://doc.bytedance.net/docs/177/266/14800/
/// @param requestModel 安全校验所需参数
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)checkMobileCodeWithModel:(TTAValidateMobilCodeRequestModel *
                                                               _Nonnull)requestModel
                                                   completion:(void(^)(NSError * _Nullable error, NSString * _Nullable ticket, id _Nullable jsonObj))completedBlock;

@end



NS_ASSUME_NONNULL_END
