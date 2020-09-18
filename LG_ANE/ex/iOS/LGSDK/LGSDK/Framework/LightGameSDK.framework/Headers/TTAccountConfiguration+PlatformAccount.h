//
//  TTAccountConfiguration+PlatformAccount.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 03/07/2017.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import "TTAccountConfiguration.h"
#import "TTAccountAuthDefine.h"
#import "TTAccountPlatformConfiguration.h"



NS_ASSUME_NONNULL_BEGIN

/**
 @attention: 配置一定在applicationDidFinishLaunching中同步完成，否则可能导致`热启动`过程中因异步致使调用handleOpenURL:时未注册第三方平台
 */
@interface TTAccountConfiguration (PlatformAccount)

/**
 配置第三方平台帐号信息
 
 @param platformConf 第三方平台配置信息
 */
- (void)addPlatformConfiguration:(TTAccountPlatformConfiguration *)platformConf;
- (void)addPlatformConfigurations:(NSArray<TTAccountPlatformConfiguration *> *)platformConfs;


/** 动态配置自定义WAP授权登录面板的配置信息 */
@property (nonatomic, strong, readonly, nullable) TTAccountCustomLoginConfiguration *wapLoginConf;

@end

NS_ASSUME_NONNULL_END
