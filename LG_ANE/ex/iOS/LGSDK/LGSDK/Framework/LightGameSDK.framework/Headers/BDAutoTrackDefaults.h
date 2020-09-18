//
//  BDAutoTrackDefaults.h
//  Aspects
//
//  Created by bob on 2019/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// path: [BDAutoTrackUtility trackerDocumentPath]/{$appid}/config.plist

@interface BDAutoTrackDefaults : NSObject

+ (nullable instancetype)defaultsWithAppID:(NSString *)appID;

/// for sepecific use like database
- (instancetype)initWithAppID:(NSString *)appID name:(NSString *)name;

- (BOOL)boolValueForKey:(NSString *)key;
- (double)doubleValueForKey:(NSString *)key;
- (NSInteger)integerValueForKey:(NSString *)key;
- (NSUInteger)unsignedIntegerValueForKey:(NSString *)key;
- (long long)longlongValueForKey:(NSString *)key;
- (nullable NSString *)stringValueForKey:(NSString *)key;
- (nullable NSDictionary *)dictionaryValueForKey:(NSString *)key;
- (nullable NSArray *)arrayValueForKey:(NSString *)key;

- (void)setValue:(nullable id)value forKey:(NSString *)key;

- (void)saveDataToFile;
- (void)clearAllData;

@end

NS_ASSUME_NONNULL_END
