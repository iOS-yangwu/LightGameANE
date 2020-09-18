//
//  TTAccountMulticast.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/25/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"


NS_ASSUME_NONNULL_BEGIN

/**
 *  定义帐号状态变更通知
 */
@protocol TTAccountMulticastProtocol <NSObject>
@optional
/**
 *  登录成功；如果想知道登录成功的Reason，使用onAccountStatusChanged
 */
- (void)onAccountLogin;

#pragma mark - logout success
/**
 *  登出成功
 */
- (void)onAccountLogout;


/**
 *  登出成功，使用 logoutInScene:completion: 才会调用
 *  onAccountLogout 与onAccountLogoutInScene是互斥关系，优先
 *  调用onAccountLogoutInScene，如果没有实现onAccountLogoutInScene：，则尝试调用onAccountLogout
 *
 *  @param  logoutScene     登出的场景
 */
- (void)onAccountLogoutInScene:(TTAccountLogoutScene)logoutScene; 

/**
 *  会话过期
 *
 *  @param error   错误描述
 */
- (void)onAccountSessionExpired:(NSError * _Nullable)error;

/**
 *  用户帐号状态发生变更（登录、登出和会话过期都会调用该消息）
 *
 *  @param reasonType    帐号状态变更的原因
 *  @param platformName  第三方平台名称
 */
- (void)onAccountStatusChanged:(TTAccountStatusChangedReasonType)reasonType
                      platform:(NSString * _Nullable)platformName;

/**
 *  登录成功或手动调用接口`2/user/info`成功获取用户信息都会发送该通知
 */
- (void)onAccountGetUserInfo;

/**
 *  用户profile变更；当同时修改多个字段时，可能出现某几个成功和失败并存的case
 *
 *  @param changedFields    修改的用户Profile描述
 *  @param error            错误描述
 *
 *  Example:
 *      {
 *          @(TTAccountUserProfileTypeUserName): @(YES|NO), // YES表示修改成功，否则修改失败
 *          ......
 *      }
 */
- (void)onAccountUserProfileChanged:(NSDictionary * _Nonnull)changedFields
                              error:(NSError * _Nullable)error;

/**
 *  用户帐号绑定第三方平台帐号发生变更
 *
 *  1. 绑定新的平台
 *  2. 解绑已绑定平台
 *  3. 已绑定平台过期
 *
 *  @param reasonType    第三方平台状态变更的原因
 *  @param platformName  第三方平台名称
 *  @param error         错误描述
 */
- (void)onAccountAuthPlatformStatusChanged:(TTAccountAuthPlatformStatusChangedReasonType)reasonType
                                  platform:(NSString *)platformName
                                     error:(NSError *)error;

@end



/**
 *  该协议为了兼容头条老版本中数据处理逻辑，会在帐号状态变更第一时间执行对应的回调
 */
@protocol TTAccountMessageFirstResponder <TTAccountMulticastProtocol>

@end



@interface TTAccountMulticast : NSObject

+ (instancetype)sharedInstance;

/**
 *  注册接受消息的实例
 *
 *  @param delegate 接受消息的对象
 */
- (void)registerDelegate:(NSObject<TTAccountMulticastProtocol> * _Nonnull)delegate;

/**
 *  解绑接受消息的实例
 *
 *  @param delegate 接受消息的对象
 */
- (void)unregisterDelegate:(NSObject<TTAccountMulticastProtocol> * _Nonnull)delegate;

@end

NS_ASSUME_NONNULL_END
