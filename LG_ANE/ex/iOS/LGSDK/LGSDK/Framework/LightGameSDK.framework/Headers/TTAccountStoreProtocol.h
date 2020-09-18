//
//  TTAccountProtocol.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#ifndef TTAccountProtocol_h
#define TTAccountProtocol_h


@protocol TTAccountStoreProtocol <NSObject>
@required
/**
 *  使用默认的service和accessGroup
 */
+ (void)tt_setBool:(BOOL)aBool forKey:(NSString *)key;
+ (void)tt_setNumber:(NSNumber *)aNumber forKey:(NSString *)key;
+ (void)tt_setString:(NSString *)string forKey:(NSString *)key;
+ (void)tt_setArray:(NSArray *)array forKey:(NSString *)key;
+ (void)tt_setDictionary:(NSDictionary *)dictionary forKey:(NSString *)key;
+ (void)tt_setData:(NSData *)data forKey:(NSString *)key;

+ (BOOL)tt_boolForKey:(NSString *)key;
+ (NSNumber *)tt_numberForKey:(NSString *)key;
+ (NSString *)tt_stringForKey:(NSString *)key;
+ (NSArray  *)tt_arrayForKey:(NSString *)key;
+ (NSDictionary *)tt_dictionaryForKey:(NSString *)key;
+ (NSData *)tt_dataForKey:(NSString *)key;


/**
 *  使用指定的service和accessGroup访问
 */
+ (void)tt_setBool:(BOOL)aBool forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (void)tt_setNumber:(NSNumber *)aNumber forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (void)tt_setString:(NSString *)string forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (void)tt_setArray:(NSArray *)array forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (void)tt_setDictionary:(NSDictionary *)dictionary forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (void)tt_setData:(NSData *)data forKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;


+ (BOOL)tt_boolForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (NSNumber *)tt_numberForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (NSString *)tt_stringForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (NSArray  *)tt_arrayForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (NSDictionary *)tt_dictionaryForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
+ (NSData *)tt_dataForKey:(NSString *)key service:(NSString *)serviceName accessGroup:(NSString *)accessGroup;
@end

#endif /* TTAccountProtocol_h */
