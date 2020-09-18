//
//  BDAutoTrackNetworkConnection.h
//  BDTracker
//
//  Created by hopo on 2018/4/17.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackReachability.h"

NS_ASSUME_NONNULL_BEGIN


@interface BDAutoTrackNetworkConnection : NSObject

@property (nonatomic, assign, readonly) BDAutoTrackNetworkConnectionType connection;
@property (nonatomic, copy, readonly) NSString *connectMethodName;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
