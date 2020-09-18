//
//  BDAutoTrackBatchData.h
//  Applog
//
//  Created by bob on 2019/2/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackBatchData : NSObject

@property (nonatomic, assign) BOOL autoTrackEnabled;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray *> *realSentData;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray *> *sendingTrackData;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray *> *sendingTrackID;

@property (nonatomic, assign) NSUInteger maxEventCount;

- (void)filterData;

@end

@interface BDAutoTrackBatchItem : NSObject

@property (nonatomic, copy) NSArray *trackData;
@property (nonatomic, copy) NSArray *trackID;

@end

NS_ASSUME_NONNULL_END
