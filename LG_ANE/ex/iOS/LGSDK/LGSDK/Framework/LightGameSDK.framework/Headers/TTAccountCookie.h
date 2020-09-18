//
//  TTAccountCookie.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 2/27/17.
//
//

#import <Foundation/Foundation.h>



@interface TTAccountCookie : NSObject

/**
 *  清除默认（名为"sessionid"）的Cookie
 */
+ (void)clearAccountCookie;

/**
 *  清理Cookie
 */
+ (void)clearAllCookies;

/**
 *  获取当前所有的Cookie
 */
+ (NSArray<NSHTTPCookie *> *)cookies;

/// 获取cookie 中的session 信息
+ (NSString *)sessionIDInCookie;

/// 获取cookie中指定name的value
+ (NSString *)cookieForName:(NSString *)name;

@end
