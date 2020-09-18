//
//  ToutiaoOpenSDKApi.h
//  所有Api接口
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToutiaoOpenSDKApiObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ToutiaoOpenSDKApiDelegate <NSObject>

@optional

/**
 接收并处理来自今日头条的请求消息
 
 @param req 今日头条主动发送的具体请求内容
 */
- (void)didReceiveRequest:(ToutiaoOpenSDKBaseReq * _Nonnull)req;

/**
 第三方应用程序通过sendReq向今日头条发送请求后，收到来自今日头条的响应
 
 @param resp 今日头条回应的具体内容
 */
- (void)didReceiveResponse:(ToutiaoOpenSDKBaseResp * _Nonnull)resp;

@end

@protocol ToutiaoOpenSDKLogDelegate <NSObject>

/**
 接收来自今日头条的日志，可供调试用
 
 @param log 日志内容
 */
- (void)onLog:(NSString *)log;

@end

@interface ToutiaoOpenSDKApi : NSObject

/**
 设置SDK日志代理，可供调试
 
 同时仅允许存在一个日志代理，每次调用将覆盖之前的delegate
 
 SDK会弱引用这个logDelegate
 
 @param logDelegate 日志代理
 */
+ (void)registerLogDelegate:(id<ToutiaoOpenSDKLogDelegate>)logDelegate;

/**
 清除SDK日志代理，停止调试
 
 会清除之前设置的日志代理
 */
+ (void)unregisterLogDelegate;

/**
 向今日头条注册第三方应用
 
 需要在每次启动第三方应用程序时调用。第一次调用后，将添加到头条的可用应用列表中
 
 @attention       必须在主线程执行
 
 @param appId       第三方应用在今日头条开放平台申请的appId（appId也称ClientKey）
 @return 成功返回YES，否则返回NO
 */
+ (BOOL)registerAppId:(NSString * _Nonnull)appId;

/**
 处理今日头条通过URL启动第三方应用时传递的数据，需在[application:openURL:sourceApplication:annotation:]或者[application:handleOpenURL:]中调用
 
 @attention 必须在主线程执行
 
 @param url         启动第三方应用的URL
 @param delegate    ToutiaoOpenSDKApiDelegate对象，用来接收今日头条触发的消息
 @return 成功处理返回YES，否则返回NO
 */
+ (BOOL)handleOpenURL:(NSURL * _Nonnull)url
             delegate:(id<ToutiaoOpenSDKApiDelegate> _Nullable)delegate;

/**
 获取当前SDK的版本
 
 @return 返回SDK当前版本号
 */
+ (nonnull NSString *)currentVersion;

/**
 判断用户是否安装了今日头条
 
 @return 安装返回YES，否则返回NO
 */
+ (BOOL)isAppInstalled;

/**
 判断当前今日头条版本是否支持授权登录
 
 @return 支持返回YES，否则返回NO
 */
+ (BOOL)isAppSupportAuthorization;

/**
 获取今日头条在iTunes上的下载地址
 
 @return 返回今日头条的安装地址
 */
+ (nonnull NSString *)getAppiTunesUrl;

/**
 由第三方APP给今日头条发送请求，今日头条处理完成后通过didReceiveResponse:回调
 
 @attention 必须运行在主线程
 
 @param req 发送给今日头条的请求
 @return 发送请求成功返回YES，否则返回NO并终止流程
 */
+ (BOOL)sendReq:(ToutiaoOpenSDKBaseReq * _Nonnull)req;

/*! @brief 发送Auth请求，唤起今日头条客户端，若用户没安装今日头条则唤起web授权页，等待今日头条返回response
 *
 * 函数调用后，会切换到今日头条的界面。第三方应用程序等待今日头条返回response
 * @param req 具体的发送请求，在调用函数后，请自己释放。
 * @param viewController 当前界面对象，用于展示今日头条的web授权页。
 * @param delegate ToutiaoOpenSDKApiDelegate对象，用来接收今日头条触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)sendAuthReq:(ToutiaoOpenSDKSendAuthReq*)req viewController:(UIViewController*)viewController delegate:(id<ToutiaoOpenSDKApiDelegate>)delegate;

/**
 进行web授权页预加载缓存，针对web页展示慢做的优化，使授权请求中展示web页更快
 若无需求可以不调用
 @param req 预加载的授权请求
*/
+ (void)preloadWebAuthWithReq:(ToutiaoOpenSDKSendAuthReq *)req;

/**
 清理web授权页预加载缓存
 若无需求可以不调用
*/
+ (void)clearPreloadWebAuthCache;

/**
 今日头条给第三方APP发送请求后，第三方APP通过didReceiveRequest:接收到请求后，第三方APP使用SendResp:给今日头条回送响应
 
 @attention 必须运行在主线程
 
 @param resp 回送给今日头条的响应
 @return 发送请求成功返回YES，否则返回NO并终止流程
 */
+ (BOOL)sendResp:(ToutiaoOpenSDKBaseResp * _Nonnull)resp;

@end

NS_ASSUME_NONNULL_END

