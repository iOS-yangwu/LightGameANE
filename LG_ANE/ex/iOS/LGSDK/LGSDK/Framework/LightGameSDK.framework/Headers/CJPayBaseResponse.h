//
//  CJPayBaseResponse.h
//  CJPay
//
//  Created by jiangzhongping on 2018/8/24.
//

#import "JSONModel.h"
#import <Foundation/Foundation.h>

@interface CJPayBaseResponse : JSONModel

// 返回码和信息
@property (nonatomic,copy)NSString *code; // 
@property (nonatomic,copy)NSString *msg;

// 其他信息
@property (nonatomic,copy)NSString *version;
@property (nonatomic,copy)NSString *sign;

// 标记是否来自缓存
@property (nonatomic,assign)BOOL isFromCache;
// 请求响应的时间间隔
@property (nonatomic,assign)NSTimeInterval responseDuration;

- (BOOL)isSuccess;
- (BOOL)isNeedThrottle;
- (NSTimeInterval)throttleTime;

+ (NSMutableDictionary *)basicDict;

@end
