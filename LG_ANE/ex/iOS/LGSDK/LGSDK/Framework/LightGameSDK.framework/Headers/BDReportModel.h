//
//  BDReportModel.h
//  RangersAppLog
//
//  Created by bob on 2019/7/29.
//

#import <Foundation/Foundation.h>
#import "BDReportCode.h"

NS_ASSUME_NONNULL_BEGIN

@class BDReportModel;

@interface BDReportModel : NSObject

@property (nonatomic, copy) NSString *event;
@property (nonatomic, copy) NSString *trackID;
@property (nonatomic, assign, readonly) BOOL isNotEmpty;

+ (instancetype)modelWithEvent:(NSString *)event;
+ (instancetype)modelWithV3Data:(NSDictionary *)data;

- (NSInteger)onReprtResult:(BOOL)success
                  addCount:(NSUInteger)count
                  failType:(NSInteger)type
                      rate:(NSInteger)rate;

- (void)updateFailType:(NSInteger)type addCount:(NSUInteger)count;

#pragma mark - eventV3

- (NSMutableArray *)eventV3ArrayWithParameters:(NSDictionary *)insert;
- (NSMutableDictionary *)dataBaseInsertParam;

@end

NS_ASSUME_NONNULL_END
