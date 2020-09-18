//
//  BDTuringEventService.h
//  BDTuring
//
//  Created by bob on 2019/9/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class UIEvent, UITouch, BDTuringConfig;

@protocol BDTuringEventReporter <NSObject>

- (void)reportEvents:(NSArray *)action;

@end

@interface BDTuringEventService : NSObject

/// 是否采集触摸事件
@property (atomic, assign) BOOL isCollectTouch;
@property (nonatomic, weak) id<BDTuringEventReporter> reporter;
@property (atomic, copy, readonly) NSString *appID;


+ (instancetype)sharedInstance;

- (void)loadDataForConfig:(BDTuringConfig *)config;
- (void)collectEvent:(NSString *)event data:(nullable NSDictionary *)params;

/// fetch完了会清空
- (NSArray *)fetchAndCleanEvents;

/// fetch完了不会清空，单独上报
- (NSArray *)fetchTouchEvents;

/// save to database
- (void)saveEventData:(NSArray *)data;

@end

FOUNDATION_EXTERN void turing_collectTouchEvent(UIEvent *event);

NS_ASSUME_NONNULL_END
