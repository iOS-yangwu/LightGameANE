//
//  TTAccountPhoneRegistration.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/25/17.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TTAccountDefine.h"
#import "TTAccountRespModel.h"
#import "TTAccountRequestModel.h"

@interface TTAccountPhoneRegistration : NSObject
/**
 *  使用手机号注册新帐号
 *
 *  @param  phoneString     手机号
 *  @param  codeString      短信验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startRegisterWithPhone:(NSString *)phoneString
                                           SMSCode:(NSString *)codeString
                                          password:(NSString *)passwordString
                                           captcha:(NSString *)captchaString
                                        completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

/**
 *  使用帐号和密码进行登录(新版)
 *
 *  @param  account         帐号
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startAccountLogin:(NSString *)account
                                     password:(NSString *)passwordString
                                      captcha:(NSString *)captchaString
                                  accountType:(TTAPWDLoginType)accountType
                                   completion:(void(^)(UIImage *captchaImage, NSError *error, id jsonObj))completedBlock;

/**
 *  使用手机号和token进行登录
 *
 *  @param  phoneString     手机号
 *  @param  tokenString     token
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startTokenLoginWithPhone:(NSString *)phoneString
                                               token:(NSString *)tokenString
                                             captcha:(NSString *)captchaString
                                          completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

/**
 *  使用手机号和验证码进行登录，新用户登录时直接注册 https://wiki.bytedance.net/pages/viewpage.action?pageId=181592821)
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startQuickLoginWithPhone:(NSString *)phoneString
                                             SMSCode:(NSString *)codeString
                                             captcha:(NSString *)captchaString
                                   jsonObjCompletion:(void(^)(UIImage *captchaImage, NSError *error , id jsonObj))completedBlock;


/**
 *  使用手机号和验证码进行登录(新用户登录时，返回错误  https://wiki.bytedance.net/pages/viewpage.action?pageId=181592821)
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startQuickLoginOnlyWithPhone:(NSString *)phoneString
                                                 SMSCode:(NSString *)codeString
                                                 captcha:(NSString *)captchaString
                                       jsonObjCompletion:(void(^)(UIImage *captchaImage, NSError *error , id jsonObj))completedBlock;

/**
 *  使用手机号和验证码进行登录(新用户登录时，返回错误  https://wiki.bytedance.net/pages/viewpage.action?pageId=181592821)
 *
 *  @param  phoneString     手机号
 *  @param  smsCodeKey    验证码校验token
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  登录完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startQuickLoginOnlyContinueWithPhone:(NSString *)phoneString
                                                      smsCodeKey:(NSString *)smsCodeKey
                                                         captcha:(NSString *)captchaString
                                               jsonObjCompletion:(void(^)(UIImage *captchaImage, NSError *error , id jsonObj))completedBlock;


/**
 *  获取短信认证码【Deprecated】
 *
 *  @param  oldPhoneString  旧手机号
 *  @param  newPhoneString  新手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  unbind          是否解绑已有的绑定关系（0不解绑，1解绑）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startGetSMSCodeWithOldPhone:(NSString *)oldPhoneString
                                               newPhone:(NSString *)newPhoneString
                                                captcha:(NSString *)captchaString
                                            SMSCodeType:(TTASMSCodeScenarioType)codeType
                                            unbindExist:(BOOL)unbind
                                             completion:(void(^)(NSNumber *retryTime /* 过期时间 */, UIImage *captchaImage /* 图形验证码 */, NSError *error))completedBlock __deprecated_msg("Method deprecated. Use `startGetSMSCodeWithPhone:captcha:SMSCodeType:unbindExist:completion:`");


/**
 *  获取短信认证码【New】
 *
 *  @param  phoneString     新手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  unbind          是否解绑已有的绑定关系（0不解绑，1解绑）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startGetSMSCodeWithPhone:(NSString *)phoneString
                                             captcha:(NSString *)captchaString
                                         SMSCodeType:(TTASMSCodeScenarioType)codeType
                                         unbindExist:(BOOL)unbind
                                          completion:(void(^)(NSNumber *retryTime /* 过期时间 */, UIImage *captchaImage /* 图形验证码 */, NSError *error))completedBlock;

/// 发送验证码
/// @param phoneString 手机号
/// @param captchaString 图形验证码
/// @param codeType 验证码类型
/// @param extraInfo 特殊业务需要传递的信息
/// @param completedBlock 结果回到
+ (id<TTAccountSessionTask>)startGetSMSCodeWithPhone:(NSString * _Nullable)phoneString
                                             captcha:(NSString * _Nullable)captchaString
                                         SMSCodeType:(TTASMSCodeScenarioType)codeType
                                           extraInfo:(NSDictionary * _Nullable)extraInfo
                                          completion:(void(^)(id _Nullable data, NSError * _Nullable error))completedBlock;

/**
 *  换绑手机号获取验证码【New】
 *
 *  @param  phoneString     新手机号
 *  @param  oldPhoneString  旧手机号
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  unbind          是否解绑已有的绑定关系（0不解绑，1解绑）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startGetSMSCodeWithPhone:(NSString *)phoneString
                                           oldMobile:(NSString *)oldPhoneString
                                             captcha:(NSString *)captchaString
                                         SMSCodeType:(TTASMSCodeScenarioType)codeType
                                         unbindExist:(BOOL)unbind
                                          completion:(void(^)(NSNumber *retryTime /* 过期时间 */, UIImage *captchaImage /* 图形验证码 */, NSError *error))completedBlock;


/**
 *  验证短信验证码
 *
 *  @param  codeString      短信验证码
 *  @param  codeType        验证码类型
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startValidateSMSCode:(NSString *)codeString
                                     SMSCodeType:(TTASMSCodeScenarioType)codeType
                                   captchaString:(NSString *)captchaString
                                      completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

/**
 *  验证短信验证码(带有ticket)
 *
 *  @param  codeString      短信验证码
 *  @param  codeType        验证码类型
 *  @param  captchaString   图形验证码
 *  @param  needTicket      需要返回票据身份的带上1
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startValidateSMSCode:(NSString *)codeString
                                     SMSCodeType:(TTASMSCodeScenarioType)codeType
                                   captchaString:(NSString * _Nullable)captchaString
                                      needTicket:(int)needTicket
                                      completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error, NSString * _Nullable ticket))completedBlock;
/**
 *  验证短信验证码(带有ticket)
 *
 *  @param  codeString      短信验证码
 *  @param  codeType        验证码类型
 *  @param  captchaString   图形验证码
 *  @param  needTicket      需要返回票据身份的带上1
 *  @param  scene           业务场景
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startValidateSMSCode:(NSString *)codeString
                                     SMSCodeType:(TTASMSCodeScenarioType)codeType
                                   captchaString:(NSString *)captchaString
                                      needTicket:(int)needTicket
                                           scene:(int)scene
                                      completion:(void(^)(UIImage *captchaImage, NSError *error, id jsonObj))completedBlock;

/**
 *  新用户设置密码
 *
 *  @param  passwordString      密码
 *  @param  captchaString       图形验证码
 *  @param  completedBlock      完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startSetPasswordWithPassword:(NSString *)passwordString
                                                 captcha:(NSString * _Nullable)captchaString
                                              completion:(void (^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  重置密码/找回密码
 *
 *  @param  phoneString     手机号
 *  @param  codeString      短信验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
//+ (id<TTAccountSessionTask>)startResetPasswordWithPhone:(NSString *)phoneString
//                                                SMSCode:(NSString *)codeString
//                                               password:(NSString *)passwordString
//                                                captcha:(NSString *)captchaString
//                                             completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

+ (id<TTAccountSessionTask>)startResetPasswordWithPhone:(NSString *)phoneString
                                                SMSCode:(NSString *)codeString
                                               password:(NSString *)passwordString
                                                captcha:(NSString *)captchaString
                                  completionWithJsonObj:(void(^)(UIImage *captchaImage, NSError *error, id jsonObj))completedBlock;


/**
 *  修改密码
 *
 *  @param  passwordString  新的密码
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startModifyPasswordWithNewPassword:(NSString *)passwordString
                                                       SMSCode:(NSString *)codeString
                                                       captcha:(NSString *)captchaString
                                                    completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;


/**
 *  修改用户手机号
 *
 *  @param  phoneString     新的手机号
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startChangeUserPhone:(NSString *)phoneString
                                         SMSCode:(NSString *)codeString
                                         captcha:(NSString *)captchaString
                                      completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;


/**
 *  修改用户手机号 http://doc.bytedance.net/docs/177/266/3253/
 *
 *  @param  phoneString     新的手机号
 *  @paran  ticket          旧手机号通过验证码校验通过后下发的临时凭据
 *  @param  codeString      短信验证码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startChangeUserPhone:(NSString *)phoneString
                                          ticket:(NSString *)ticket
                                         SMSCode:(NSString *)codeString
                                         captcha:(NSString * _Nullable)captchaString
                                      completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;

/**
 *  刷新并获取新的图形验证码
 *
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startRefreshCaptchaWithCompletion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;


/**
 *  绑定手机号. 密码为空使用V1接口，否则使用V2接口
 *
 *  @param  phoneString     手机号
 *  @param  codeString      验证码
 *  @param  passwordString  密码（v1可空，v2以上强制需要）
 *  @param  captchaString   图形验证码
 *  @param  unbindExisted   YES，绑定过则先解绑再绑定，否则直接解绑（已绑定过则报错）
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startBindPhone:(NSString *)phoneString
                                   SMSCode:(NSString *)codeString
                                  password:(NSString *)passwordString
                                   captcha:(NSString *)captchaString
                                    unbind:(BOOL)unbindExisted
                                completion:(void (^)(UIImage *captchaImage, NSError *error))completedBlock;


/**
 *  解绑绑定的手机号
 *
 *  @param  captchaString     图片验证码
 *  @param  completedBlock    解绑完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startUnbindPhoneWithSMSCode:(NSString *)codeString
                                                captcha:(NSString *)captchaString
                                             completion:(void (^)(UIImage *captchaImage, NSError *error))completedBlock;


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
+ (nullable id<TTAccountSessionTask>)startBindAndLogingWithPhonenumber:(NSString *)phoneNumber
                                                                  SMSCode:(NSString *)codeString
                                                               profileKey:(NSString * _Nullable)profileKey
                                                              SMSCodeType:(TTASMSCodeScenarioType)codeType
                                                                  captcha:(NSString * _Nullable)captchaString
                                                               completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error))completedBlock;
/**
 *  通过token 取消注销操作
 *
 *  @param  token       任何登录接口返回错误码1075时，接口返回的token
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)startCancelLogoutWithToken:(NSString * _Nonnull)token
                                                completion:(void(^)(NSError * _Nullable error, id jsonObj))completedBlock;

/// 查询用户手机号是否为停机状态 https://doc.bytedance.net/docs/177/266/21639/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startCheckPhoneIsUseableWithModel:(TTACheckMobileUseableRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error, TTADataCheckMobileUseableModel * _Nullable dataModel))completedBlock;

/// 查询用户可用验证的登录方式 https://doc.bytedance.net/docs/177/266/21662/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startFetchAvailableWaysWithModel:(TTAOauthAvailableWaysRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error, TTADataUseableLoginWaysModel * _Nullable dataModel))completedBlock;

/// 账密二次验证 https://doc.bytedance.net/docs/177/266/18116/
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startAccountVerifyWithModel:(TTAAccountVerifyRequestModel * _Nonnull)requestModel
                                              completion:(void(^)(NSError * _Nullable error, NSString * _Nullable ticket))completedBlock;


/// 获取短信验证码，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startGetSMSCodeWithModel:(TTASendCodeRequestModel * _Nonnull)requestModel
                                completion:(void(^)(NSNumber * _Nullable retryTime /* 过期时间 */, UIImage * _Nullable captchaImage /* 图形验证码 */, NSError * _Nullable error))completedBlock;

/// 获取短信验证码，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startGetSMSCodeWithModel:(TTASendCodeRequestModel * _Nonnull)requestModel
                                          jsonCompletion:(void(^)(NSError * _Nullable error,id _Nullable jsonObj))completedBlock;
/// 换绑手机，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startChangeUserPhoneWithModel:(TTAChangeMobilRequestModel * _Nonnull)requestModel
                                completion:(void(^)(NSError * _Nullable error, UIImage * _Nullable captchaImage,id _Nullable jsonObj))completedBlock;

/// 手机号仅注册，返回一个ticket，用户可以使用ticket进行继续登录 ，requestModel 属性根据需要设置
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startgenerateTicketByPhoneWithModel:(TTAValidateMobilCodeRequestModel *
                                                                     _Nonnull)requestModel
                                                         completion:(void(^)(NSError * _Nullable error,NSString * _Nullable ticket))completedBlock;
/// 手机号使用上面接口的ticket继续登录
/// @param mobile 手机号
/// @param ticket 上面接口返回的ticket
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startloginContinueWithMobile:(NSString * _Nonnull)mobile
                                                      ticket:(NSString * _Nonnull)ticket
                                                  completion:(void(^)(NSError * _Nullable error))completedBlock;

#pragma mark - 手机号对应账号是否已设置过密码

///  检测手机号对应账号是否设置过密码
/// @param mobile 手机还哦啊
/// @param completedBlock 结果回调，
+ (nullable id<TTAccountSessionTask>)startCheckHasSetPasswordWithModel:(TTACheckHasPasswordRequestModel * _Nonnull)requestModel
                                                   completion:(void(^)(NSError * _Nullable error,BOOL hasSetPassword, id _Nullable jsonObj))completedBlock;

#pragma mark - 安全校验相关

/// 触发风控j后的安全校验
/// @param requestModel 请求model
/// @param completedBlock 结果回调
+ (nullable id<TTAccountSessionTask>)startCheckMobileCodeWithModel:(TTAValidateMobilCodeRequestModel *_Nonnull)requestModel
                                                        completion:(void(^)(NSError * _Nullable error, NSString * _Nullable ticket, id _Nullable jsonObj))completedBlock;

@end
