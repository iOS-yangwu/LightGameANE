//
//  BDTuringTimer.h
//  BDTuring
//
//  Created by bob on 2019/10/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDTuringTimer : NSObject

+ (instancetype)sharedInstance;

/// start interval 毫秒
- (void)scheduledDispatchTimerWithName:(NSString *)timerName
                                 start:(long long)start
                          timeInterval:(long long)interval
                                 queue:(nullable dispatch_queue_t)queue
                               repeats:(BOOL)repeats
                                action:(dispatch_block_t)action;

- (void)cancelTimerWithName:(NSString *)timerName;

@end

NS_ASSUME_NONNULL_END
