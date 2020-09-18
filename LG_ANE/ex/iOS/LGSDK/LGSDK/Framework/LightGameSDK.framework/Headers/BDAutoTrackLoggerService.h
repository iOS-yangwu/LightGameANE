//
//  BDAutoTrackLoggerService.h
//  RangersAppLog
//
//  Created by bob on 2019/9/12.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackService.h"
#import "BDCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackLoggerService : BDAutoTrackService

- (instancetype)initWithAppID:(NSString *)appID logger:(BDAutoTrackLogger)logger;

- (void)logger:(nullable NSString *)log;

@end

NS_ASSUME_NONNULL_END
