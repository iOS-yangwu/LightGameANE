//
//  TTAccountDeviceLoginInfo.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/9/3.
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"
#import "TTAccountUserEntity.h"
#import "TTAccountRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountDeviceLoginInfo : NSObject

+ (instancetype)sharedInstance;

///各种login_only接口登录时，暂时记录登录信息
- (void)setCurrentloginOnlyInfoWithType:(TTAccountLoginType)loginType accountInfo:(NSString *)accountInfo;

/**
 登录成功后，更新最新的登录信息

 @param loginType 登录类型
 @param accountInfo 手机、邮箱等的明文信息，或者第三方平台的名称
 */
+ (void)updateLastLoginType:(TTAccountLoginType)loginType accountInfo:(NSString *)accountInfo;

/**
登录成，更新最新的登录信息

@param loginType 登录类型
@param accountInfo 手机、邮箱等的明文信息，或者第三方平台的名称
@param user 用户实体，传入此参数则忽略，SDK 内部存储信息
*/
+ (void)updateLastLoginType:(TTAccountLoginType)loginType accountInfo:(NSString *)accountInfo user:(TTAccountUserEntity *)userEntity;

/**
 loginOnly方式登录时，continue登录成功后缓存更新用户信息
 */
+ (void)updateLastLoginInfoWithContinue;

/**
 最近一次登录的本地缓存信息

 @return 本地缓存的用户登录信息
 */
+ (nullable TTADeviceLoginUserInfo *)latestLocalDeviceLoginInfo;

/// 获取SDK 缓存的登录信息
/// @param duplicateUid 是否进行进行uid 去重,YES, 去重；NO 不去重
+ (nullable NSArray<TTADeviceLoginUserInfo *> *)fetchHistoryLoginInfoWithDuplicateUid:(BOOL)duplicateUid;

/**
更新上次登录的本地缓存信息

 */
+ (void)updateLatestedLocalDeviceLoginInfo:(TTAccountUserEntity *)userEntity;


/**
 获取该设备下最近一次、最长活跃、常用登录方式的登录信息

 @param type 不同类型的登录信息
 @param timeRange 时间长度，最长活跃、常用登录方式需要
 @param completedBlock 结果回调
 @return 网络请求
 */
+ (nullable id<TTAccountSessionTask>)fetchDeviceLoginInfoWithType:(TTADeviceLoginInfoType)type
                                                        timeRange:(NSInteger)timeRange
                                                     completetion:(void(^)(NSArray<TTADeviceLoginUserInfo *>  * _Nullable userInfos, NSError *_Nullable error))completedBlock;
#pragma mark - 一键登录
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

@end


NS_ASSUME_NONNULL_END
