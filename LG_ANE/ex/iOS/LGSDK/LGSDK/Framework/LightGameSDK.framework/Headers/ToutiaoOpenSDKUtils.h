//
//  ToutiaoOpenSDKUtils.h
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ToutiaoOpenSDK_isEmptyString(str)        (![str isKindOfClass:[NSString class]] || [str length] == 0)

#define ToutiaoOpenSDK_CHECK_MainThread()    NSCAssert([NSThread isMainThread], @"Must run in main thread")

@interface NSURL (ToutiaoOpenSDK_URLUtils)

/**
 追加items项至NSURL查询部分并生成新的URL
 
 @param items 查询参数
 @return 新的NSURL对象
 */
- (nullable NSURL *)bdsdk_URLByAppendQueryItems:(NSDictionary * _Nullable)items;

/**
 获取NSURL中查询参数
 
 @return 查询参数
 */
- (nullable NSDictionary *)bdsdk_queryDictionary;

@end

@interface NSString (ToutiaoOpenSDK_StringUtils)

/**
 追加items项至NSString后作为NSURL查询参数部分
 
 @param items 查询参数
 @return 返回string+items所生成的新NSURL对象
 */
- (nullable NSURL *)bdsdk_URLByAppendQueryItems:(NSDictionary * _Nullable)items;

/**
 获取字符串对应NSURL中查询参数
 
 @return 查询参数
 */
- (nullable NSDictionary *)bdsdk_queryDictionary;

+ (NSString * _Nonnull)bdsdk_timeStamp;

@end

@interface NSString (ToutiaoOpenSDK_URLEnDecoder)

/** 将字符串进行URL编码 */
- (nullable NSString *)bdsdk_URLEncodedString;

/** 将字符串进行URL解密 */
- (nullable NSString *)bdsdk_URLDecodedString;

/** 将字符串反序列化为JSON对象（字典、数组等） */
- (nullable id)bdsdk_deserializeJSONObject;

@end

@interface NSArray (ToutiaoOpenSDK_ToSerializatedString)

/**
 将数组转化为UTF8编码的字符串
 
 @return 编码字符串
 */
- (nonnull NSString *)bdsdk_serializatedString;

@end

@interface NSOrderedSet (ToutiaoOpenSDK_PermissionToString)

/**
 将必选权限集合转化为字符串
 
 @return 编码字符串
 */
- (nonnull NSString *)bdsdk_permissionString;

/**
 将附加可选权限集合转化为字符串
 
 @return 编码字符串
 */
- (nonnull NSString *)bdsdk_additionPermissionString;

@end

@interface NSDictionary (ToutiaoOpenSDK_ToSerializatedString)

/**
 将字典转化为UTF8编码的字符串
 
 @return 编码字符串
 */
- (nonnull NSString *)bdsdk_serializatedString;

@end

