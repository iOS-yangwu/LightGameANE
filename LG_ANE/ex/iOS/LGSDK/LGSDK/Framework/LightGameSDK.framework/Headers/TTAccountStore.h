//
//  TTAccountStore.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 11/28/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountStoreProtocol.h"



/**
 *  使用KeyChain存储
 */
@interface TTAccountStore : NSObject
<
TTAccountStoreProtocol
>
/**
 *  单例
 *
 *  默认的serviceName: bundleIdentifier
 *       accessGroup: nil
 */
+ (instancetype)sharedStore;

/**
 *  使用指定的serviename和accessGroup
 */
+ (instancetype)storeWithServiceName:(NSString *)serviceName
                         accessGroup:(NSString *)accessGroupName;

- (NSString *)serviceName;

//- (NSString *)accessGroup;

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


#pragma mark - set values

- (void)tt_setString:(NSString *)string forKey:(NSString *)key;
- (void)tt_setArray:(NSArray *)array forKey:(NSString *)key;
- (void)tt_setDictionary:(NSDictionary *)dictionary forKey:(NSString *)key;
- (void)tt_setData:(NSData *)data forKey:(NSString *)key;

#pragma mark - get values

- (BOOL)tt_boolForKey:(NSString *)key;
- (NSNumber *)tt_numberForKey:(NSString *)key;
- (NSString *)tt_stringForKey:(NSString *)key;
- (NSArray *)tt_arrayForKey:(NSString *)key;
- (NSDictionary *)tt_dictionaryForKey:(NSString *)key;
- (NSData *)tt_dataForKey:(NSString *)key;

/**
 *  Get all Keys
 */
- (NSArray *)tt_allKeys;

/**
 *  Get all Items
 */
- (NSArray *)tt_allItems;

/**
 *  Remove all items
 */
- (BOOL)tt_removeAllItems;

/**
 *  Remove item of key
 */
- (BOOL)tt_removeItemForKey:(NSString *)key;


/**
 *  Subscript access
 */
//- (id)objectForKeyedSubscript:(NSString<NSCopying> *)key;

/**
 *  Set by subscript
 */
- (void)setObject:(id)obj forKeyedSubscript:(NSString<NSCopying> *)key;

@end
