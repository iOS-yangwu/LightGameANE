//
//  BDAutoTrackMonitorService.h
//  RangersAppLog
//
//  Created by bob on 2019/9/15.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackMonitorService : BDAutoTrackService

- (instancetype)initWithAppID:(NSString *)appID;
- (void)onRecordRequestWithData:(nullable NSDictionary *)sendingData
                        success:(BOOL)success
                       response:(nullable NSDictionary *)response;

- (void)onRecordEvent:(nullable NSString *)event failType:(NSInteger)failType;

@end

FOUNDATION_EXTERN void bd_monitorUpdateRate(NSInteger monitorRate, NSString *appID);
FOUNDATION_EXTERN void bd_monitorRecordFail(NSString *_Nullable event,
                                            NSInteger failType,
                                            NSString *appID);
FOUNDATION_EXTERN void bd_monitorRecordRequest(NSDictionary *_Nullable sendingData,
                                               BOOL success,
                                               NSDictionary *_Nullable response,
                                               NSString *appID);
NS_ASSUME_NONNULL_END
