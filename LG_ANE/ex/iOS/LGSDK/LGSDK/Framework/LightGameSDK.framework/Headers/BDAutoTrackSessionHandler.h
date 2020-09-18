//
//  BDAutoTrackSessionHandler.h
//  Applog
//
//  Created by bob on 2019/1/18.
//

#import <Foundation/Foundation.h>
#import "BDCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackSessionHandler : NSObject

@property (atomic, copy, readonly) NSString *sessionID;
@property (nonatomic, assign) BDAutoTrackLaunchFrom launchFrom;
@property (nonatomic, copy, readonly) NSArray *previousLaunchs;
@property (nonatomic, copy, readonly) NSArray *previousTerminates;

+ (instancetype)sharedHandler;

/// 返回调用之前是否 sessionStart
/// 调用之后 sessionStart肯定是yes
- (BOOL)checkAndStartSession;

/// for unit test
- (void)startSessionWithIDChange:(BOOL)change;


- (void)onUUIDChanged;
- (void)createUUIDChangeSession;

@end

NS_ASSUME_NONNULL_END
