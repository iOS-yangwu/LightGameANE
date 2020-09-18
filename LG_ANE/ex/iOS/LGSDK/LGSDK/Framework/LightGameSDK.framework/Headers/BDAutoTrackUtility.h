//
//  BDAutoTrackUtility.h
//  Applog
//
//  Created by bob on 2019/1/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *bd_base64_string(NSString *base64);
FOUNDATION_EXTERN NSDateFormatter * bd_dateFormatter(void);
FOUNDATION_EXTERN NSDateFormatter * bd_dayFormatter(void);
/// UUID 每次调用产生新的，如果需要保存唯一，得自行处理
FOUNDATION_EXTERN NSString * bd_UUID(void);
FOUNDATION_EXTERN NSNumber * bd_currentInterval(void);
FOUNDATION_EXTERN NSTimeInterval bd_currentIntervalValue(void);
FOUNDATION_EXTERN NSNumber * bd_milloSecondsInterval(void);
FOUNDATION_EXTERN NSString *bd_dateNowString(void);
FOUNDATION_EXTERN NSString *bd_dateTodayString(void);
FOUNDATION_EXTERN NSString *bd_queryFromDictionary(NSDictionary *params);
FOUNDATION_EXTERN NSString *bd_trackerDocumentPath(void);
FOUNDATION_EXTERN NSString *bd_trackerDocumentPathForAppID(NSString *appID);

/// 其实是返回可序列化对象，不是说深拷贝
FOUNDATION_EXTERN id bd_trueDeepCopyOfObj(id obj);
FOUNDATION_EXTERN NSMutableArray *bd_trueDeepCopyOfArray(NSArray *array);
FOUNDATION_EXTERN NSMutableDictionary *bd_trueDeepCopyOfDictionary(NSDictionary *_Nullable params);


FOUNDATION_EXTERN NSString *_Nullable bd_JSONRepresentation(id _Nullable param);
FOUNDATION_EXTERN id _Nullable bd_JSONValueForString(NSString *_Nullable inJSON);
FOUNDATION_EXTERN NSMutableDictionary *_Nullable bd_dictionaryFromQuery(NSString *_Nullable query);

NS_ASSUME_NONNULL_END
