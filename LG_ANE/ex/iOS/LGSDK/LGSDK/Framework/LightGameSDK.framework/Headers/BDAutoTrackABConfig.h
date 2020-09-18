//
//  BDAutoTrackABConfig.h
//  RangersAppLog
//
//  Created by bob on 2019/9/12.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackABConfig : BDAutoTrackService

@property (atomic, copy, nullable, readonly) NSString *abVersions;
@property (nonatomic, copy) NSDictionary *currentRawData;

- (instancetype)initWithAppID:(NSString *)appID;

- (nullable id)getConfig:(NSString *)key defaultValue:(nullable id)defaultValue;
- (nullable NSString *)allABVersions;
/// key - value
- (NSDictionary *)allABTestConfigs;

- (void)updateABConfigWithRawData:(nullable NSDictionary<NSString *, NSDictionary *> *)rawData;

- (void)setExternalABVersion:(NSString *)versions;

@end

FOUNDATION_EXTERN BDAutoTrackABConfig *_Nullable bd_abTestServiceForAppID(NSString *appID);
FOUNDATION_EXTERN void bd_abAddParameters(NSMutableDictionary *result, NSString *appID, BOOL isEvent);

NS_ASSUME_NONNULL_END
