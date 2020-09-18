//
//  TTAccountSettingManager.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/8/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountSettingManager : NSObject

+ (instancetype)sharedInstance;

- (void)updateSettings:(NSDictionary *)settings;

- (NSDictionary *)currentSettings;

/**
 开机启动优化setting，冷起时是否开启子线程异步读写keychain

 @return 是否开启子线程读写keychain
 */
- (BOOL)openAsyncKeychain;

/**
三方登录后需不需要立即调用2/user/info同步用户信息setting

@return 是否立即调用2/user/info
*/
- (BOOL)openAutoSyncAfterAuthLogin;

///  缓存和用户登录信息的最大条数
- (NSInteger)maxCacheOfLoginInfo;

@end

NS_ASSUME_NONNULL_END
