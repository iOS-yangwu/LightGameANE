//
//  BDAutoTrackLocalSettings.h
//  RangersAppLog
//
//  Created by bob on 2019/9/12.
//

#import "BDAutoTrackService.h"
#import "BDAutoTrack.h"

@class BDAutoTrackConfig;

NS_ASSUME_NONNULL_BEGIN

/// 用户传入的参数配置，有部分需要持久化的部分

@interface BDAutoTrackLocalSettings : BDAutoTrackService

/// only once set
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *channel;
@property (nonatomic, assign) BOOL autoActiveUser;
@property (nonatomic, assign) BOOL logNeedEncrypt;
@property (nonatomic, assign) BOOL autoFetchSettings;
@property (nonatomic, assign) BOOL abTestEnabled; 
/// multi times
@property (atomic, assign) NSInteger serviceVendor;
@property (atomic, strong, nullable) BDAutoTrackCustomHeaderBlock customHeaderBlock;
@property (atomic, strong, nullable) BDAutoTrackRequestURLBlock requestURLBlock;
@property (atomic, strong, nullable) BDAutoTrackRequestHostBlock requestHostBlock;
@property (nonatomic, copy, nullable) NSString *pickerHost;

/// 持久化部分
@property (atomic, copy, nullable) NSString *userUniqueID;
@property (atomic, copy, nullable) NSString *userAgent;
@property (atomic, copy, nullable) NSString *appLauguage;
@property (atomic, copy, nullable) NSString *appRegion;

- (instancetype)initWithConfig:(BDAutoTrackConfig *)config;

/// 持久化setter

- (void)saveAppRegion:(nullable NSString *)appRegion;
- (void)saveAppLauguage:(nullable NSString *)appLauguage;
- (void)saveUserAgent:(nullable NSString *)userAgent;
- (void)saveUserUniqueID:(nullable NSString *)userUniqueID;

- (void)addSettingParameters:(NSMutableDictionary *)result isQeury:(BOOL)isQuery;

@end


/// parameters
FOUNDATION_EXTERN void bd_addSettingParameters(NSMutableDictionary *result, NSString *appID, BOOL isQuery);
FOUNDATION_EXTERN BDAutoTrackLocalSettings *_Nullable bd_settingsServiceForAppID(NSString *appID);

NS_ASSUME_NONNULL_END
