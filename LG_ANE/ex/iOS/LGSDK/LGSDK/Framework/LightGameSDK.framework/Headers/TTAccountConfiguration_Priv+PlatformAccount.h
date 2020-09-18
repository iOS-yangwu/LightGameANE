//
//  TTAccountConfiguration_Priv+PlatformAccount.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/9/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountConfiguration_Priv.h"
#import "TTAccountConfiguration+PlatformAccount.h"
#import "TTAccountAuthDefine.h"



NS_ASSUME_NONNULL_BEGIN


@interface TTAccountConfiguration ()

/** Privated Platform Configurations */
@property (nonatomic, strong) NSMutableDictionary<NSString *, TTAccountPlatformConfiguration *> *platformConfigurations;

@end



@interface TTAccountConfiguration (tta_PlatformAccountInternal)

/** 获取客户端在第三方平台注册的appId */
- (nonnull NSString *)tta_consumerKeyForPlatformType:(TTAccountAuthType)type;

/** 获取客户端在第三方平台注册的consumerSecret*/
- (nonnull NSString *)tta_consumerSecretForPlatformType:(TTAccountAuthType)type;

/** 是否共享第三方平台的用户信息 */
- (BOOL)tta_isShareUserInfoForPlatformType:(TTAccountAuthType)type;

/** 获取第三方平台在头条帐号体系内某产品的唯一标识(平台ID) */
- (nonnull NSString *)tta_platformAppIdForPlatformType:(TTAccountAuthType)type;

/** 获取第三方平台的名称 */
- (nonnull NSString *)tta_platformAppNameForPlatformType:(TTAccountAuthType)type;

/** 获取第三方平台在头条帐号体系内唯一标识的平台ID */
- (nonnull NSString *)tta_platformAppIdForPlatformType:(TTAccountAuthType)type;

- (nonnull NSString *)tta_platformAppDisplayNameForPlatformType:(TTAccountAuthType)type;

- (nullable NSString *)tta_authSchemeCallbackURLForPlatformType:(TTAccountAuthType)type;

/** 获取第三平台的回调地址 */
- (nullable NSString *)tta_redirectURLForPlatformType:(TTAccountAuthType)type;

/** 获取向第三方平台申请授权获取用户信息的权限 */
- (nullable NSString *)tta_scopeForPlatformType:(TTAccountAuthType)type;

/**  获取第三方平台注册时的universalLink */
- (nullable NSString *)tta_universalLinkForPlatformType:(TTAccountAuthType)type;


/** 通过懒加载注册Platform SDK */
- (void)tta_laziedRegisterPlatformAppIDForPlatformType:(TTAccountAuthType)type;

#pragma mark - TTACustomWapAuthViewController

- (BOOL)tta_useDefaultWAPLoginForPlatformType:(TTAccountAuthType)type;

- (BOOL)tta_tryCustomWAPLoginWhenSDKFailureForPlatformType:(TTAccountAuthType)type;

- (BOOL)tta_SNSBarHiddenForPlatformType:(TTAccountAuthType)type;

- (nullable NSString *)tta_SNSBarTextForPlatformType:(TTAccountAuthType)type;

#pragma mark - Bytedancebase SDK

- (nullable NSString *)tta_platformAppInstallUrlForPlatformType:(TTAccountAuthType)type;

- (nullable NSArray<NSString *> *)tta_platformAppInstalledSchemesForPlatformType:(TTAccountAuthType)type;

- (nullable NSArray<NSString *> *)tta_platformAppSupportedSchemesForPlatformType:(TTAccountAuthType)type;

- (nullable NSOrderedSet<NSString *> *)tta_permissionsForPlatformType:(TTAccountAuthType)type;

- (nullable NSOrderedSet<NSDictionary<NSString *,NSString *> *> *)tta_additionalPermissionsForPlatformType:(TTAccountAuthType)type;

@end


NS_ASSUME_NONNULL_END

