//
//  BDAutoTrackBatchPacker.h
//  RangersAppLog
//
//  Created by bob on 2019/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BDAutoTrackBatchData, BDAutoTrackBatchItem;

FOUNDATION_EXTERN BDAutoTrackBatchItem * bd_batchPackRawTracks(NSArray *rawTracks,
                                                               NSString *tableName,
                                                               NSString *currentSession);

FOUNDATION_EXTERN BDAutoTrackBatchData *bd_batchPackAllTracks(NSDictionary<NSString *, NSArray *> *allTracks,
                                                                                NSUInteger maxCountPerTask);

NS_ASSUME_NONNULL_END
