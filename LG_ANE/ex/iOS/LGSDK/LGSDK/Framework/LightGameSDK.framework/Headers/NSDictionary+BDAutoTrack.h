//
//  NSDictionary+BDAutoTrack.h
//  RangersAppLog
//
//  Created by bob on 2019/7/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (BDAutoTrack)

- (BOOL)applog_boolValueForKey:(NSString *)key;
- (double)applog_doubleValueForKey:(NSString *)key;
- (NSInteger)applog_integerValueForKey:(NSString *)key;
- (NSUInteger)applog_unsignedIntegerValueForKey:(NSString *)key;
- (long long)applog_longlongValueForKey:(NSString *)key;
- (nullable NSString *)applog_stringValueForKey:(NSString *)key;
- (nullable NSDictionary *)applog_dictionaryValueForKey:(NSString *)key;
- (nullable NSArray *)applog_arrayValueForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
