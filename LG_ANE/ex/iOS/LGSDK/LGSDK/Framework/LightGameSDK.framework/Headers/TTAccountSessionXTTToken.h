//
//  BDAccountSessionXTTToken.h
//  BDAccountSessionSDK
//
//  Created by bytedance on 2018/5/15.
//

#import <Foundation/Foundation.h>
#import "TTNetworkManager.h"

extern NSString * const SessionXTTTokenNotificationV2;
extern NSString * const SessionXTTTokenSuccessV2;
extern NSString * const SessionXTTTokenSDKVersionV2;
extern NSString * const SessionXTTTokenV2;
extern NSString * const SessionXTTTokenSignV2;
extern NSString * const BDAccountSessionXTTTokenFirstBeat;
extern NSString * const BDAccountSessionXTTTokenKeyV2;

//wap登录的时候清掉长票据
extern NSString * const WapLoginClearXTTTokenV2;

@interface TTAccountSessionXTTToken : NSObject

@property (nonatomic, copy) NSString *x_tt_token;
@property (nonatomic, assign) BOOL firstBeat;

/**
 @return 单例对象
 */
+ (TTAccountSessionXTTToken *)shared;

/**
 *   app启动时开启心跳，每10分钟一次，如果有x-tt-token且过期，会给x-tt-token续期=
 *
 *  @param request      请求的request
 */
+ (void)tokenBeatAfterLaunching;

/**
 *
 *  @param scene    请求的request
 *  @param completed    调用token/beat 结果回调
 */
+ (void)tokenBeatWithScene:(NSString *)scene
                 completed:(void(^)(TTHttpResponse * _Nullable response, NSError * _Nullable error))completedBlock;

/**
 添加token 和 version 到请求的header 中
 *
 * @param request   需要添加header 的 requet
 */
+ (void)addXTokenToRequest:(TTHttpRequest *)request;

/**
 业务方使用wap 登录后，调用该接口，接口内部会根据wap登录后用户态生成新的x-tt-token
 *
 */
+ (void)wapLoginSuccessRefreshToken;

/**
 业务方在TTNet 设置返回的过滤器，调用该接口，SDK内部将更新票据、进行登出操作等。
 *
 *  @param response     接口返回的response
 *  @param responseError    请求错误
 *  @param sessionHasExpired    业务接口是否返回session过期，如果为YES,SDK 将SDK 登录态设为NO后调用logout 接口
 */
+ (BOOL)setXTokenWithResponse:(TTHttpResponse *)response responseError:(NSError *)responseError sessionHasExpired:(BOOL)hasExpired;

/**
 更新token,只有签名验证通过后才会更新token；签名校验失败，清除之前的token，
 *
 * @param x_tt_token        登录、登出或者beat接口返回的token
 * @param hexString         接口对应返回的签名
 * @return 更新token是否成功
 */
- (BOOL)setXToken:(NSString * _Nonnull)x_tt_token tokenSign:(NSString * _Nonnull)hexString;

/// 清除token
- (void)cleanToken;

@end
