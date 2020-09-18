//
//  ToutiaoOpenSDKApplicationDelegate.h
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import "ToutiaoOpenSDKApi.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ToutiaoOpenSDKURLServiceProtocol;
@interface ToutiaoOpenSDKApplicationDelegate : NSObject

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
 注册一个处理url请求的service
 
 @param servicer service类
 */
+ (void)registerServiceClass:(Class<ToutiaoOpenSDKURLServiceProtocol>)servicer;

/**
 处理今日头条通过URL启动第三方应用传递过来的数据
 
 @param url         启动第三方应用的URL
 @param delegate    ToutiaoOpenSDKApiDelegate对象，用户处理今日头条发送的消息
 @return 能处理返回YES，否则返回NO
 */
+ (BOOL)handleOpenURL:(NSURL * _Nonnull)url
             delegate:(id<ToutiaoOpenSDKApiDelegate> _Nonnull)delegate;

/**
 第三方应用发送请求，通过URL打开今日头条
 
 @param req 第三方应用发送给今日头条的请求
 @return 能发送返回YES，否则返回NO
 */
+ (BOOL)sendMsgToBytedanceAPPsWithReq:(ToutiaoOpenSDKBaseReq * _Nonnull)req;

/*! @brief 发送Auth请求，唤起今日头条客户端，若用户没安装今日头条则唤起web授权页，等待今日头条返回response
 *
 * 函数调用后，会切换到今日头条的界面。第三方应用程序等待今日头条返回response
 * @param req 具体的发送请求，在调用函数后，请自己释放。
 * @param viewController 当前界面对象，用于展示今日头条的web授权页。
 * @param delegate ToutiaoOpenSDKApiDelegate对象，用来接收今日头条触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)sendAuthToBytedanceAPPsWithReq:(ToutiaoOpenSDKSendAuthReq*)req viewController:(UIViewController*)viewController delegate:(id<ToutiaoOpenSDKApiDelegate>)delegate;

/*! @brief 发送Auth请求，唤起今日头条客户端，若用户没安装今日头条则唤起web授权页，等待今日头条返回response
 *
 * 函数调用后，会切换到今日头条的界面。第三方应用程序等待今日头条返回response
 * @param req 具体的发送请求，在调用函数后，请自己释放。
 * @param viewController 当前界面对象，用于展示今日头条的web授权页。
 * @param delegate ToutiaoOpenSDKApiDelegate对象，用来接收今日头条触发的消息。
 * @param webFirst 可通过webFirst选择优先使用web授权
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)sendAuthToBytedanceAPPsWithReq:(ToutiaoOpenSDKSendAuthReq*)req viewController:(UIViewController*)viewController delegate:(id<ToutiaoOpenSDKApiDelegate>)delegate webFirst:(BOOL)webFirst;

/**
 第三方应用回送响应给今日头条
 
 当今日头条给第三方应用主动发送请求时，第三方应用收到[id<ToutiaoOpenSDKApiDelegate didReceiveRequest:]的请求后，处理完成后并通过[ToutiaoOpenSDKApi sendResp]回送响应给今日头条
 
 @param resp 第三方应用发送给今日头条的响应
 @return 能发送返回YES，否则返回NO
 */
+ (BOOL)sendMsgToBytedanceAPPsWithResp:(ToutiaoOpenSDKBaseResp * _Nonnull)resp;

/**
  预加载优化web授权页首次展示速度
 @param req 预加载的授权请求
  */
+ (void)preloadWebAuthWithReq:(ToutiaoOpenSDKSendAuthReq *)req;

/**
 清理预加载web授权页的缓存
 */
+ (void)clearPreloadWebAuthCache;

@end

#pragma mark - ToutiaoOpenSDKURLServiceProtocol

@protocol ToutiaoOpenSDKURLServiceProtocol <NSObject>
@required

/**
 @return 服务名称
 */
+ (nonnull NSString *)serviceName;
+ (nonnull NSString *)reqClassName;

@optional

#pragma mark - 处理来自平台的GetReq
/**
 今日头条通过URL Scheme方式打开第三方应用，将URL根据不同的服务转化为相应的ToutiaoOpenSDKBaseReq对象
 
 @attention 同步处理
 
 @param url 今日头条打开第三方应用的Scheme URL
 @return 返回url对应服务的ToutiaoOpenSDKBaseReq对象
 */
+ (nonnull ToutiaoOpenSDKBaseReq *)providerGetReqFromURL:(NSURL * _Nonnull)url;

/**
 第三方应用程序收到今日头条的请求后，进行处理并将处理结果通过Scheme方式返回给今日头条
 
 @param consumerGetResp 第三方应用处理今日头条请求的响应结果
 @return 返回第三方应用处理今日头条请求后的结果URL
 */
+ (nonnull NSURL *)URLFromConsumerGetResp:(ToutiaoOpenSDKBaseResp * _Nonnull)consumerGetResp;

#pragma mark - 处理第三方应用发送消息至平台的SendReq

/**
 处理第三方应用通过SDK发送的请求，将ToutiaoOpenSDKBaseReq转化为NSURL，并通过改url打开今日头条
 
 @param consumerReq 第三方应用发送的请求
 @return 返回打开今日头条的URL
 */
+ (NSURL * _Nullable)URLFromConsumerSendReq:(ToutiaoOpenSDKBaseReq * _Nonnull)consumerReq;

#pragma mark - 第三方应用发送消息至今日头条后，处理今日头条回送消息至第三方应用的SendResp

/**
 解析今日头条使用URL打开第三方应用时捎带的数据，生成ToutiaoOpenSDKBaseResp对象
 
 @param url 今日头条打开第三方应用时使用的URL
 @return 返回由url生成的ToutiaoOpenSDKBaseResp对象
 */
+ (ToutiaoOpenSDKBaseResp * _Nullable)consumerSendRespFromURL:(NSURL * _Nonnull)url;

@end

#pragma mark - ToutiaoOpenSDKHandleURLOAuthService 授权服务

@interface ToutiaoOpenSDKHandleURLOAuthService : NSObject
<
ToutiaoOpenSDKURLServiceProtocol
>

@end

NS_ASSUME_NONNULL_END

