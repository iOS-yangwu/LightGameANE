//
//  BDAutoTrackBatchTimer.h
//  RangersAppLog
//
//  Created by bob on 2019/9/11.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN
@class BDAutoTrackBatchService;

typedef NS_ENUM(NSInteger, BDAutoTrackCleanType) {
    /// app启动触发
    BDAutoTrackCleanTypeInitApp = 0x01,
    /// 定时器触发
    BDAutoTrackCleanTypeTimer,
    /// 切到前台触发
    BDAutoTrackCleanTypeEnterForground,
    BDAutoTrackCleanTypeEnterBackground,
    /// UUID 变化触发
    BDAutoTrackCleanTypeUUIDChanged,
};

@interface BDAutoTrackBatchTimer : NSObject

@property (nonatomic, assign) BOOL skipLaunch;
@property (nonatomic, assign) CFTimeInterval batchInterval;
@property (nonatomic, assign) CFTimeInterval backgroundTimeout;
@property (nonatomic, weak) BDAutoTrackBatchService *request;

- (instancetype)initWithAppID:(NSString *)appID;

- (void)endBackgroundTask;
- (void)updateTimerInterval:(NSTimeInterval)batchInterval;
- (void)stopTimer;

@end

NS_ASSUME_NONNULL_END
