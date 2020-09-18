//
//  BDAutoTrackBatchService.h
//  Applog
//
//  Created by bob on 2019/1/28.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackBatchService : BDAutoTrackService

- (instancetype)initWithAppID:(NSString *)appID;
- (void)sendTrackDataFrom:(NSInteger)from;

@end

FOUNDATION_EXTERN void bd_batchUpdateTimer(CFTimeInterval interval, BOOL skipLaunch, NSString *appID);
FOUNDATION_EXTERN BOOL bd_batchIsEventInBlockList(NSString *event, NSString *appID);

NS_ASSUME_NONNULL_END
