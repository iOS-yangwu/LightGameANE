//
//  TTAccountEmailRegistration.h
//  Pods
//
//  Created by 王鹏 on 2019/3/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountEmailRegistration : NSObject

/**
 *  验证邮箱是否可用
 *
 *  @param  emailString     邮箱
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)checkEmailRegistedWithEmail:(NSString *)emailString
                                           captcha:(NSString *)captchaString
                                        completion:(void(^)(UIImage *captchaImage, BOOL isRegistered, NSError *error))completedBlock;
/**
 *  使用邮箱注册新帐号, 后面废弃
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  passwordString  密码
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startRegisterWithEmail:(NSString *)emailString
                                           emailCode:(NSString *)codeString
                                          password:(NSString *)passwordString
                                           captcha:(NSString *)captchaString
                                        completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

/**
*  使用邮箱注册新帐号v2
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
+ (id<TTAccountSessionTask>)startRegisterV2WithEmail:(NSString *)emailString
                                           emailCode:(NSString *_Nullable)codeString
                                            password:(NSString *)passwordString
                                             captcha:(NSString *_Nullable)captchaString
                                      recaptchaToken:(NSString *_Nullable)recaptchaTokenString
                                               extra:(NSDictionary *_Nullable)extra
                                          completion:(void(^)(UIImage *_Nullable captchaImage, NSError *_Nullable error))completedBlock;


/**
 *  获取邮箱注册的验证码
 *
 *  @param  emailString     邮箱
 *  @param  captchaString   图形验证码
 *  @param  codeType        验证码类型
 *  @param  passwordString  密码
 *  @param  jumpUrl         邮件正文中的跳转链接
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startGetEmailCodeWithEmail:(NSString *)emailString
                                         emailCodeType:(TTAEmailCodeScenarioType)codeType
                                              password:(NSString *)passwordString
                                               jumpUrl:(NSString *)jumpUrl
                                               captcha:(NSString *)captchaString
                                          completion:(void(^)(UIImage *captchaImage , NSError *error))completedBlock;



/**
 *  邮箱注册验证
 *
 *  @param  emailString     邮箱
 *  @param  codeString      邮箱验证码
 *  @param  codeType        验证码类型
 *  @param  captchaString   图形验证码
 *  @param  completedBlock  完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)startValidateEmailRegister:(NSString *)emailString
                                                  emailCode:(NSString *)codeString
                                           emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         captchaString:(NSString *)captchaString
                                        completion:(void(^)(UIImage *captchaImage, NSError *error))completedBlock;

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
+ (id<TTAccountSessionTask>)startRegisterWithEmail:(NSString *_Nonnull)emailString
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
+ (id<TTAccountSessionTask>)startBindWithEmail:(NSString *_Nonnull)emailString
                                                  emailCode:(NSString *_Nonnull)codeString
                                           emailCodeType:(TTAEmailCodeScenarioType)codeType
                                         captchaString:(NSString * _Nullable)captchaString
                                            completion:(void(^)(UIImage * _Nullable captchaImage, NSError * _Nullable error,id _Nullable jsonObj))completedBlock;
///  登录态下绑定邮箱并设置密码
/// @param emailString 邮箱
/// @param passwordString 密码
/// @param completedBlock 完成回调
+ (id<TTAccountSessionTask>)startBindWithEmail:(NSString *)emailString
                                      password:(NSString *)passwordString
                                    completion:(void(^)(NSError * _Nullable error,id _Nullable jsonObj))completedBlock;

///  登录态下校验用户绑定的邮箱
/// @param codeString 邮箱验证码
/// @param codeType 验证码类型
/// @param completedBlock 结果回调
+ (id<TTAccountSessionTask>)startVerifyEmailWithCode:(NSString * _Nonnull)codeString
                                      emailCodeType:(TTAEmailCodeScenarioType)codeType
                                    completion:(void(^)(NSError * _Nullable error,NSString * _Nullable ticket,id _Nullable jsonObj))completedBlock;

@end

NS_ASSUME_NONNULL_END
