//
//  TTAccountMulticast+Internal.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/25/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountMulticast.h"



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountMulticast ()

/**
 *  Broadcast 用户帐号Profile发生变更
 *
 *  @param changedFields  用户信息变更字段
 *  @param error          错误描述
 */
- (void)broadcastAccountProfileChanged:(NSDictionary * _Nonnull)changedFields
                                 error:(NSError * _Nullable)error;


/**
 *  Broadcast 用户登录过期
 *
 *  @param  error   过期错误描述
 */
- (void)broadcastAccountSessionExpired:(NSError *_Nonnull)error;


/**
 *  Broadcast 登录成功
 *
 *  @param user         用户信息
 *  @param platformName 第三方授权平台名称
 *  @param reasonType   登录的方式
 */
- (void)broadcastLoginSuccess:(TTAccountUserEntity * _Nonnull)user
                     platform:(NSString * _Nullable)platformName
                       reason:(TTAccountStatusChangedReasonType)reasonType;

/**
 *  Broadcast 登出成功
 */
- (void)broadcastLogout;

/**
 * 
 *  Broadcast 登出成功，使用 logoutInScene:completion: 才会调用
 *
 *  @param  logoutScene     调用登出的场景
 */
- (void)broadcastLogoutInScene:(TTAccountLogoutScene)logoutScene;

/**
 *  Broadcast 成功获取用户信息
 */
- (void)broadcastGetUserInfo;


/**
 *  Broadcast 帐号绑定平台信息发生变更
 *
 *  @param platformName 第三方平台名
 *  @param error        错误描述，为空表示成功
 */
- (void)broadcastLoginAccountAuthPlatform:(NSString * _Nonnull)platformName
                                    error:(NSError * _Nullable)error;


/**
 *  Broadcast 解绑已绑定的帐号平台信息
 *
 *  @param platformName 第三方平台名
 *  @param error        绑定错误描述，为空表示成功
 */
- (void)broadcastLogoutAccountAuthPlatform:(NSString * _Nonnull)platformName
                                     error:(NSError * _Nullable)error;


/**
 *  Broadcast 收到已绑定的帐号平台过期通知
 *
 *  @param platformName 第三方平台名，多个平台拼接的字符串
 *  @param error        错误描述
 */
- (void)broadcastExpireAccountAuthPlatform:(NSString * _Nonnull)platformName
                                     error:(NSError * _Nullable)error;
@end

NS_ASSUME_NONNULL_END
