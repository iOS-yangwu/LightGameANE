//
//  BDAutoTrackRegisterRequest.h
//  RangersAppLog
//
//  Created by bob on 2019/9/15.
//

#import "BDAutoTrackRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackRegisterRequest : BDAutoTrackRequest

@property (nonatomic, assign) BOOL needRegister;
@property (nonatomic, copy, nullable) dispatch_block_t successCallback;


@end

NS_ASSUME_NONNULL_END
