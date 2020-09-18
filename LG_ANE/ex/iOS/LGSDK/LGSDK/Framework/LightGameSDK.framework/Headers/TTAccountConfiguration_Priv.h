//
//  TTAccountConfiguration_Priv.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/9/17.
//
//

#import <Foundation/Foundation.h>
#import "TTAccountConfiguration.h"



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountConfiguration (tta_internal)

/** 获取登录模块必要的参数 */
- (nullable NSDictionary *)tta_appRequiredParameters;

/** 登录模块公共的网络参数 */
- (nullable NSDictionary *)tta_commonNetworkParameters;
+ (nullable NSDictionary *)tta_defaultURLParameters;

/** 获取当前的ViewController */
- (UIViewController *)tta_currentViewController;

+ (nullable NSString *)tta_appBundleID;

- (nullable NSString *)tta_ssAppID;

- (nullable NSString *)tta_ssMID;

- (nullable NSString *)tta_deviceID;

- (nullable NSString *)tta_installID;

- (nullable NSString *)tta_sharingKeyChainGroup;

@end

NS_ASSUME_NONNULL_END
