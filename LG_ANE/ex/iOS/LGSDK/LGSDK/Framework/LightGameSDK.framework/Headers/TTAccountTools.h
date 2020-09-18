//
//  TTAccountTools.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/5/29.

#import <Foundation/Foundation.h>
#import "TTNetworkManager.h"
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN

#define GetCommonTrackParams(response, error) ([TTAccountTrackerHelper trackParamsFromResponse:(response) error:(error)])

@interface TTAccountTrackerHelper: NSObject

/**
 * 接口事件上报参数
 *
 * @param response  接口返回的resonse
 * @param error     接口请求错误时返回的错误信息
 * @return  事件上报的参数集合
 */

+ (NSDictionary * _Nullable)trackParamsFromResponse:(TTHttpResponse * _Nullable)response error:(NSError * _Nullable)error;

/**
 * 第三方授权结果事件上报
 *
 * @param platform      第三方应用平台
 * @param requestReason 请求授权的原因
 * @param error         三方授权失败返回的error
 */
+ (void)trackAuthCallBackEventWithPlatform:(NSString * _Nullable)platform requestReason:(TTAccountRequestAuthReason)requestReason error:(NSError * _Nullable)error;

/**
 * 事件上报
 *
 * @param eventName     事件名称
 * @param response      上报参数
 * @param error         接口请求错误时返回的错误信息
 *
 */
+ (void)trackEventName:(NSString *)eventName resonse:(TTHttpResponse * _Nullable)response error:(NSError * _Nullable)error;

/**
* 事件上报
*
* @param eventName     事件名称
* @param error         接口请求错误时返回的错误信息
*
*/
+ (void)trackEventName:(NSString *)eventName error:(NSError * _Nullable)error;

/**
 * 事件上报
 *
 * @param eventName     事件名称
 * @param params        上报参数
 */
+ (void)trackEventName:(NSString *)eventName params:(NSDictionary * _Nullable)params;

@end

NS_ASSUME_NONNULL_END
