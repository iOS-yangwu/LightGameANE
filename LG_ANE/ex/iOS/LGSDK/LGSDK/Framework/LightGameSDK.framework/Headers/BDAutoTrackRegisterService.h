//
//  BDAutoTrackRegisterService.h
//  RangersAppLog
//
//  Created by bob on 2019/9/13.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackRegisterService : BDAutoTrackService

@property (atomic, copy, readonly) NSString *deviceID;
@property (atomic, copy, readonly) NSString *installID;
@property (atomic, copy, readonly) NSString *ssID;

- (instancetype)initWithAppID:(NSString *)appID;

- (void)reloadParameters;
/// 已经注册成功，给其他请求提供参数
- (void)addRegisteredParameters:(NSMutableDictionary *)result isQeury:(BOOL)isQuery;

/// 注册额外参数，给自己提供
- (void)addRegisterParameters:(NSMutableDictionary *)result;
/// update
- (BOOL)updateParametersWithResponse:(NSDictionary *)responseDict;

/// Notification
- (void)postRegisterNotification;


@end

FOUNDATION_EXTERN BOOL bd_registerServiceAvailableForAppID(NSString *appID);
FOUNDATION_EXTERN void bd_registeredAddParameters(NSMutableDictionary *result, NSString *appID, BOOL isQuery);
FOUNDATION_EXTERN void bd_registerAddParameters(NSMutableDictionary *result, NSString *appID);
FOUNDATION_EXTERN BOOL bd_registerUpdateParameters(NSDictionary *response, NSString *appID);
FOUNDATION_EXTERN void bd_registerReloadParameters(NSString *appID);
FOUNDATION_EXTERN void bd_registerPostNotification(NSString *appID);

FOUNDATION_EXTERN NSString *_Nullable bd_registerRangersDeviceID(NSString *appID);
FOUNDATION_EXTERN NSString *_Nullable bd_registerinstallID(NSString *appID);
FOUNDATION_EXTERN NSString *_Nullable bd_registerSSID(NSString *appID);

NS_ASSUME_NONNULL_END
