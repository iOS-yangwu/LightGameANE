//
//  BDAutoTrack+Private.h
//  Pods-BDAutoTracker_Example
//
//  Created by bob on 2019/6/4.
//

#import "BDAutoTrack.h"
#import "BDCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class BDAutoTrackDataCenter;

@interface BDAutoTrack (Private)

@property (nonatomic, strong) BDAutoTrackDataCenter *dataCenter;
@property (nonatomic, assign) BOOL showDebugLog;
@property (nonatomic, assign) BOOL gameModeEnable;

+ (void)trackUIEventWithData:(NSDictionary *)data;

+ (void)trackLaunchEventWithData:(NSMutableDictionary *)data;

+ (void)trackTerminateEventWithData:(NSMutableDictionary *)data;

+ (void)trackPlaySessionEventWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
