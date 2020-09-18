//
//  TTAccount+SessionToken.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/5/16.
//

#import "TTAccount.h"
#import "TTNetworkManager.h"


NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString *, NSString *> *(^BDAccountTokenManagerCommonparamBlock)(void);

@interface TTAccount (SessionToken)

/**
 业务方业务接口发起请求前需要添加票据字段
 *
 *  @param request  需要添加票据的请求
 */
+ (void)addTokenToRequest:(TTHttpRequest * _Nullable)request;

/**
 业务方在TTNet 设置返回的过滤器，调用该接口，SDK内部将更新票据。
 *
 *  @param response     接口返回的response
 *  @param responseError    请求错误
 *  @param hasExpired    业务接口是否返回session过期，如果为YES,SDK 会结合票据当前的票据判断是否过期，设置登录态
 *  @return 设置token 是否成功
 */
+ (BOOL)setXTokenWithResponse:(TTHttpResponse * _Nullable)response responseError:(NSError * _Nullable)responseError sessionHasExpired:(BOOL)hasExpired;

/**
 业务方使用wap 登录后，调用该接口，接口内部会根据wap登录后用户态生成新的x-tt-token
 *
 */
+ (void)wapLoginSuccessRefreshToken;

/**
 * 返回当前帐号对应的票据
 */
+ (NSString *)currentXttToken;

/**
 * 清除当前token
 */
+ (void)cleanXttToken;

@end

NS_ASSUME_NONNULL_END
