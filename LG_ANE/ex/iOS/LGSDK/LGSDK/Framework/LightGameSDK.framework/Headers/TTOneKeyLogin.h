//
//  TTAccountAuthWeChat.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 2/9/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TTOneKeyLogin : NSObject

/// 当前流量卡所属运营商
@property (nonatomic, copy, readonly) NSString *service;

/// 手机卡号
@property (nonatomic, copy, readonly) NSString *oneKeyLoginMaskPhoneNumber DEPRECATED_MSG_ATTRIBUTE("不再保存手机号");

+ (instancetype)sharedInstance;

/**
 *  注册一键登录
 *
 * @param serviceName       运营商，移动："mobile"；电信："telecom"；联通;
 * @param appId             从运营商申请的appId
 * @param appKey            从运营上申请的appKey
 * @param isTestChannel     是不是测试通道，如果是测试包，传Yes,正式包传NO
 */
- (void)registerOneKeyLoginService:(NSString *)serviceName appId:(NSString *)appId appKey:(NSString *)appKey isTestChannel:(BOOL)isTestChannel;

/**
 *  获取一键登录的掩码手机号
 *
 * @param completedBlock    获取手机掩码结果回调
 */

- (void)getOneKeyLoginPhoneNumberCompleted:(void(^)(NSString * _Nullable phoneNumber, NSString * _Nullable serviceName, NSError * _Nullable error))completedBlock;

/**
 *  获取一键登录的掩码手机号
 *
 * @param extraTrackInfo    业务方自定义需要附加的埋点参数
 * @param completedBlock    获取手机掩码结果回调
 */

- (void)getOneKeyLoginPhoneNumberWithExtraTrackInfo:(NSDictionary * _Nullable)extraTrackInfo
                                          completed:(void(^)(NSString * _Nullable phoneNumber,  NSString * _Nullable serviceName, NSError * _Nullable error))completedBlock;
/**
 *  一键登录
 *
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyLoginWithCompleted:(void(^)(NSError * _Nullable error))completedBlock;

/**
 *  一键登录
 *
 *  @param  extraTrackInfo 获取token时业务方自定义需要附加的埋点参数
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyLoginWithExtraTrackInfo:(NSDictionary * _Nullable)extraTrackInfo
                            completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 *  一键登录,与上面接口区别在于新用户直接拦截
 *
 *  @param  extranTrackInfo 获取token时业务方自定义需要附加的埋点参数
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyLoginOnlyWithExtraTrackInfo:(NSDictionary * _Nullable)extranTrackInfo
                            completed:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  一键登录,新用户被拦截完成一定条件后，继续注册、登录
 *
 *  @param  smsCodeKey 上一步是新用户是返回的key
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyLoginContinueWithSMSCodeKey:(NSString * _Nonnull)smsCodeKey
                            completed:(void(^)(NSError * _Nullable error, id _Nullable jsonObj))completedBlock;

/**
 *  一键绑定手机号
 *
 *  @param  codeString      验证码
 *  @param  passwordString  密码，如果需要强制绑定,则输入密码，否则可以为空
 *  @param  unbindExisted   YES，绑定过则先解绑再绑定，否则直接解绑（已绑定过则报错）
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyBindPhoneWithPassword:(NSString * _Nullable)passwordString
                             unbind:(BOOL)unbindExisted
                          completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 结合第三方的绑定流程，第三方登录调用requestLoginOnlyForPlatform:willLogin:completion,新用户成功返回profileKey
 @param profileKey 新用户授权登录时返回的profileKey
 @param completedBlock
 */
- (void)oneKeyBindPhoneWithProfileKey:(NSString * _Nullable) profileKey
                            completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 *  一键绑定手机号
 *
 *  @param  codeString      验证码
 *  @param  passwordString  密码，如果需要强制绑定,则输入密码，否则可以为空
 *  @param  unbindExisted   YES，绑定过则先解绑再绑定，否则直接解绑（已绑定过则报错）
 *  @param  completedBlock  结果回调，成功error为nil
 */
- (void)oneKeyBindPhoneWithPassword:(NSString * _Nullable)passwordString
                             unbind:(BOOL)unbindExisted
                    extranTrackInfo:(NSDictionary * _Nullable)extraTrackInfo
                          completed:(void(^)(NSError * _Nullable error))completedBlock;

/**
 更新BDUGOnekeyLogin SDK相关settings

 @param settings 最新的settings
 */
- (void)updateSettings:(NSDictionary *)settings;

@end
