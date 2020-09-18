//
//  TTAccount.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"
#import "TTAccountConfiguration.h"

#define tta_IsLogin() ([[TTAccount sharedAccount] isLogin])

NS_ASSUME_NONNULL_BEGIN

/**
 *  1. 目前，收到服务端会话过期通知，会将用户登录状态置为FALSE
 *  2. 用户登出成功后，会清空cookie
 */
@interface TTAccount : NSObject
/**
 *  帐号单例
 */
+ (TTAccount *)sharedAccount;

/**
 是否展示新帐号库UI，settings下发（tt_profile_config）
 */
+ (void)configNewAccountUIBlock:(BOOL(^)(void))newAccountUIBlock;
+ (BOOL)newAccountUIIsActive;
+ (nullable TTAccountUserEntity *)currentAccountUserInDisk;
/**
 解决crash的方案开关
 0 保持原样
 1 遍历的时候加Synchronized
 2 遍历的时候加Synchronized，并且使用强引用容器
 */
@property (nonatomic, assign) int accountCrashResolveSwitch;

/// 允许多账号登录时，多账号的票据
@property (nonatomic, copy, nullable) NSString *multiSids;

///  dticket，用于可信环境一键登录认证
@property (nonatomic, copy, nullable) NSString *dTicket;
/**
 *  设置用户登录状态,设置为非登录态，不会自动清除用户信息，需要调用setUser
 *
 *  @param  isLogin 登录状态
 */
- (void)setIsLogin:(BOOL)isLogin;


/**
 *  用户是否登录
 *
 *  @return  用户是否登录
 */
- (BOOL)isLogin;


/**
 *  设置头条平台SessionKey
 *
 *  @param  sessionKey 登录sessionKey
 */
- (void)setSessionKey:(NSString * _Nullable)sessionKey;

/**
 *  获取头条平台的SessionKey
 *
 *  @return  用户的登录sessionKey
 */
- (nullable NSString *)sessionKey;

/**
 *  返回字符串类型的用户ID
 *
 *  @return  头条用户ID字符串
 */
- (nullable NSString *)userIdString;

/**
 *  获取当前登录用户帐号信息
 *
 *  @return  登录用户信息
 */
- (nullable TTAccountUserEntity *)user;

/**
 *  更新帐号用户信息,
 *
 *  @param  userEntity 用户信息，为空时清除用户信息
 */
- (void)setUser:(TTAccountUserEntity * _Nullable)userEntity;

/**
 *  置登录态为非登录态，清除单例和本地存储的用户信息
 *
 */
- (void)cleanLoginStatusAndUserInfo;

/**
 *  获取指定的第三方帐号
 *
 *  @param   platformName 第三方平台名称
 *  @return  第三方平台信息
 */
- (nullable TTAccountPlatformEntity *)connectedAccountForPlatform:(NSString * _Nonnull)platformName;

/**
 *  持久化用户信息
 */
- (void)persistence;

/**
 *  当前SDK 的版本号
 */
-(NSString *)passportSDKVersion;

/**
 *  当前票据SDK 对应的版本号，专门用于票据生成
 */
- (NSString *)sdkVersion;

/// 更新settings
/// @param settings app 透传的settings
- (void)updateSettings:(NSDictionary *)settings;

@end

#pragma mark - 帐号SDK配置

@interface TTAccount (Configuration)
/**
 *  设置帐号相关的配置参数
 *  若不手动设置将使用默认的配置
 */
@property (nonatomic, strong, class) TTAccountConfiguration *accountConf;

@end

#pragma mark - helper

@interface NSDictionary (AccountHelper)

- (BOOL)tta_boolForKey:(NSObject<NSCopying> *)key;

- (BOOL)tta_boolForKey:(NSObject<NSCopying> *)key defaultValue:(BOOL)defaultValue;

- (BOOL)tta_boolForEnumKey:(NSInteger)enumInt /** enumInt to @(enumInt) or @(enumInt).stringValue */;

- (NSString *)tta_stringForKey:(NSObject<NSCopying> *)key;

- (NSString *)tta_stringForEnumKey:(NSInteger)enumInt /** enumInt to @(enumInt) or @(enumInt).stringValue */;

- (nullable NSDictionary *)tta_dictionaryForKey:(NSObject<NSCopying> *)key;

- (NSInteger)tta_integerForKey:(NSObject<NSCopying> *)key;

@end

NS_ASSUME_NONNULL_END
