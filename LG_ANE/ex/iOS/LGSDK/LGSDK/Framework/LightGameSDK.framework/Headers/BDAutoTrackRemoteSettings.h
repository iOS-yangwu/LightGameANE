//
//  BDAutoTrackRemoteSettings.h
//  RangersAppLog
//
//  Created by bob on 2019/9/12.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

/// 通过logsetting 请求拉回来的settings，优先级高于初始化设置
@interface BDAutoTrackRemoteSettings : BDAutoTrackService

@property (nonatomic, assign, readonly) NSTimeInterval batchInterval;     /// batch_event_interval
@property (nonatomic, assign, readonly) NSTimeInterval abFetchInterval;   /// abtest_fetch_interval 目前后台没有下发，取值默认 600
@property (nonatomic, assign) BOOL abTestEnabled;               /// bav_ab_config
@property (nonatomic, assign, readonly) NSInteger monitorRate;            /// bav_monitor_rate
@property (nonatomic, assign) BOOL autoTrackEnabled;                      /// bav_log_collect
@property (nonatomic, assign, readonly) BOOL skipLaunch;       /// send_launch_timely 取反
@property (atomic, copy, readonly) NSArray *realTimeEvents;               /// real_time_events 目前没有实时上报通道

- (instancetype)initWithAppID:(NSString *)appID;
- (void)updateRemoteWithResponse:(NSDictionary *)responseDict;

@end

FOUNDATION_EXTERN BDAutoTrackRemoteSettings *_Nullable bd_remoteSettingsForAppID(NSString *appID);

NS_ASSUME_NONNULL_END
