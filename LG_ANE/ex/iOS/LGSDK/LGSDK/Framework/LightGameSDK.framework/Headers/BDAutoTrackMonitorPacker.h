//
//  BDAutoTrackMonitorPacker.h
//  RangersAppLog
//
//  Created by bob on 2019/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackMonitorPacker : NSObject

@property (nonatomic, assign) NSInteger monitorRate;

- (instancetype)initWithAppID:(NSString *)appID;

- (NSDictionary *)monitorRequestData;
- (void)onRequestSuccess;
- (void)onRecordEvent:(NSString *)event failType:(NSInteger)failType;
- (NSInteger)onRecordRequestWithData:(NSDictionary *)sendingData
                             success:(BOOL)success
                            response:(NSDictionary *)response;
@end

NS_ASSUME_NONNULL_END
