//
//  TTAccountLogoutTask.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/26/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"

/**
 *  退出登录网络请求
 */
@protocol TTAccountSessionTask;
@interface TTAccountLogoutTask : NSObject

/**
 *  登出账户
 *
 *  @param logoutScene      登出的场景
 *  @param completedBlock   完成后的回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestLogoutWithScene:(TTAccountLogoutScene)logoutScene
                                          completion:(void(^)(BOOL success, NSError * _Nullable error))completedBlock;

/**
 *  登出账户
 *
 *  @param logoutScene      登出的场景
 *  @param extraInfo        其他有关调用等出的信息，便于追查掉线原因，例如什么接口返回登录态失效
 *  @param completedBlock   完成后的回调
 *  @return HTTP请求任务
 */
+ (nullable id<TTAccountSessionTask>)requestLogoutWithScene:(TTAccountLogoutScene)logoutScene
                                                  extraInfo:(NSDictionary * _Nullable)extraInfo
                                                 completion:(void(^)(BOOL success, NSError * _Nullable error))completedBlock;

#pragma mark - 解绑第三方帐号
/**
 *  注销绑定的第三方平台帐号
 *
 *  @param platformName     第三方平台名称
 *  @param completedBlock   完成后的回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)requestLogoutPlatform:(NSString *)platformName
                                       completion:(void(^)(BOOL success, NSError *error))completedBlock;


@end
