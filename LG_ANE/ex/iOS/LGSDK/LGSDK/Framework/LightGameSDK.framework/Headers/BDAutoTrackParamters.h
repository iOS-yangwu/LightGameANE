//
//  BDAutoTrackParamters.h
//  RangersAppLog
//
//  Created by bob on 2019/9/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 与AppID等无关状态的参数

FOUNDATION_EXTERN void bd_addCommonParameters(NSMutableDictionary * result);
FOUNDATION_EXTERN void bd_addQueryParameters(NSMutableDictionary * result);
FOUNDATION_EXTERN void bd_addPostParameters(NSMutableDictionary * result);

FOUNDATION_EXTERN void bd_addEventParameters(NSMutableDictionary * result);

FOUNDATION_EXTERN NSDictionary * bd_timeSync(void);
FOUNDATION_EXTERN void bd_updateServerTime(NSDictionary *responseDict);
FOUNDATION_EXTERN BOOL bd_isResponseValidate(NSDictionary * _Nullable responseDict);
FOUNDATION_EXTERN BOOL bd_isResponseMessageSuccess(NSDictionary * _Nullable responseDict);
FOUNDATION_EXTERN NSCharacterSet *bd_URLAllowedCharacters(void);


FOUNDATION_EXTERN NSInteger bd_randomCountWithRate(NSUInteger count, NSInteger rate);
FOUNDATION_EXTERN NSInteger bd_monitorFailTypeFromResponse(NSDictionary *response);
FOUNDATION_EXTERN NSMutableDictionary<NSString *, NSNumber *> *bd_monitorCalculateEvents(NSArray<NSDictionary *> *events);

NS_ASSUME_NONNULL_END
