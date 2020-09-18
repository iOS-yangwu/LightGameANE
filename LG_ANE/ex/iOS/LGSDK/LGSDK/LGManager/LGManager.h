//
//  LGManager.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGManager : NSObject

+ (LGManager *) shareManager;

- (void) setBDConfigWithServiceVendor:(int)serviceVendor
                     autoTrackEnabled:(BOOL)autoTrackEnabled
                         showDebugLog:(BOOL)showDebugLog
                       logNeedEncrypt:(BOOL)logNeedEncrypt
                         userUniqueID:(NSString *)userUniqueID
                             lauguage:(NSString *)lauguage
                     abServerVersions:(NSString *)abServerVersions
                    customHeaderBlock:(NSString *)customHeaderBlock;

- (void) startWithAppID:(NSString *)appID appName:(NSString *)appName channel:(NSString *)channel;

+ (void) isDebuLog:(BOOL)isNeedDebugLog;

+ (void) debugType:(int)logType;

+ (int) getLightGameVersion;

+ (void) setCurrentUserUniqueID:(NSString *)uniqueID;

+ (void) setCustomHeaderBlock:(NSString *)customHeaderBlock;

+ (void) clearUserUniqueID;

+ (void) setABSDKVersions:(NSString *)versions;

+ (NSString *) getABSDKVersions;

+ (void) lg_event:(NSString *)event params:(NSString *)params;

+ (id) ABTestConfigValueForKey:(NSString *)key defaultValue:(id)defaultValue;


@end

NS_ASSUME_NONNULL_END
