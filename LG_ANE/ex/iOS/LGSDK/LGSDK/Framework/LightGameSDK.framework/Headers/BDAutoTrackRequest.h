//
//  BDAutoTrackRequest.h
//  RangersAppLog
//
//  Created by bob on 2019/9/15.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackNetworkConfig.h"

NS_ASSUME_NONNULL_BEGIN
@class BDAutoTrackRequest;

@interface BDAutoTrackRequest : NSObject

@property (nonatomic, copy, readonly) NSString *appID;
@property (nonatomic, strong, nullable) BDAutoTrackRequest *nextRequest;
@property (nonatomic, assign) BDAutoTrackRequestURLType requestType;
@property (nonatomic, assign) CFTimeInterval startTime;
@property (nonatomic, assign) CFTimeInterval requestStartTime;
@property (nonatomic, copy, readonly, nullable) NSString *eventName;

- (instancetype)initWithAppID:(NSString *)appID next:(nullable BDAutoTrackRequest *)nextRequest;
- (void)startRequestWithRetry:(NSInteger)retry;
- (nullable NSDictionary *)requestParameters;
- (BOOL)handleResponse:(nullable NSDictionary *)response;

@end

NS_ASSUME_NONNULL_END
