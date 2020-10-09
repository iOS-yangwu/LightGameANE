//
//  JSONSerialization.h
//
//  Created by 洋吴 on 2019/12/25.
//  Copyright © 2019 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JSONSerialization : NSObject

//json字符串转字典
+ (NSString *)convertToJsonData:(NSDictionary *)dict;

//数组转json字符串
+ (NSArray *)toArrayWithJsonString:(NSString *)jsonString;

//字典转json字符串
+ (NSDictionary *)toDictionaryWithJsonString:(NSString *)jsonString;

@end

NS_ASSUME_NONNULL_END
