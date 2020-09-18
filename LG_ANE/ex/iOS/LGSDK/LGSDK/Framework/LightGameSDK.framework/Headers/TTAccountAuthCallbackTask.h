//
//  TTAccountAuthCallbackTask.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 3/31/17.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TTAccountAuthRespModel.h"
#import "TTAccountAuthRequestModel.h"
#import "TTAccountNetworkManager.h"
#import "TTAccountAuthDefine.h"

/**
 *  @Wiki:  https://wiki.bytedance.net/pages/viewpage.action?pageId=13961678
 */
@interface TTAccountAuthCallbackTask : NSObject

#pragma mark - [SNSSDK Auth] sso_callback
/**
 *  使用SNSSDK授权成功后，与头条服务器交互的回调接口,账户后台产生新用户并绑定到第三方平台
 */
+ (id<TTAccountSessionTask>)startSNSSDKSSOAuthCallbackWithParams:(NSDictionary *)params
                                                  completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;

/**
 *  使用SNSSDK授权成功后，与头条服务器交互的回调接口,仅用于登录
 */
+ (id<TTAccountSessionTask>)startSNSSDKSSOAuthLoginCallbackWithParams:(NSDictionary *)params
                                                       completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;

/**
 *  使用SNSSDK授权成功后，与头条服务器交互的回调接口，账户后台不会产生新用户，直接返回第三方平台本身的用户信息
 */
+ (id<TTAccountSessionTask>)startSNSSDKSSOAuthShareUserInfoCallbackWithParams:(NSDictionary *)params
                                                  completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;

/**
 *  使用SNSSDK授权成功后，与头条服务器交互的回调接口,用于同第三方进行绑定
 */
+ (id<TTAccountSessionTask>)startSNSSDKSSOAuthBindThirdPlatformCallbackWithParams:(NSDictionary *)params
                                                  completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;
/**
 *  使用SNSSDK授权成功后，与头条服务器交互的回调接口，老用户登录，新用户不会进行注册，后续需要绑定手机号进行注册
 */

+ (id<TTAccountSessionTask>)startSNSSDKSSOAuthLoginOnlyCallbackWithParams:(NSDictionary *)params
                                                           completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;

/**
 *  使用SNSSDK授权成功后，与用户中心后台交互，获取三方平台用户的绑定手机号，并为该手机号关联的uid完成三方帐号绑定，主要适用于公司内部三方平台抖音、头条等
 */

+ (id)startSNSSDKSSOAuthCallbackWithRequestReason:(TTAccountRequestAuthReason)requestReason
                                                  params:(NSDictionary *)params
                                          completedBlock:(void(^)(TTASNSSDKAuthCallbackRespModel *aRespMdl, NSError *error))completedBlock;


#pragma mark - [SNSSDK Auth SwitchBind] sso_switch_bind
/**
 *  解绑以前通过OAuth-SNSSDK绑定的第三方平台
 */
+ (id<TTAccountSessionTask>)startSNSSDKAuthSwitchBindWithReq:(TTASNSSDKAuthSwitchBindReqModel *)reqMdl
                                              completedBlock:(void(^)(TTASNSSDKAuthSwitchBindRespModel *aRespMdl, NSError *error))completedBlock;

#pragma mark - [Custom WAP Auth SwitchBind] login_continue
/**
 *  解绑以前通过OAuth-WAP绑定的第三方平台
 */
+ (id<TTAccountSessionTask>)startWAPAuthSwitchBindWithReq:(TTASNSSDKAuthSwitchBindReqModel *)reqMdl
                                           completedBlock:(void(^)(TTACustomWAPAuthSwitchBindRespModel *aRespMdl, NSError *error, NSInteger httpStatusCode))completedBlock;

#pragma mark - share app to sns platform
+ (id<TTAccountSessionTask>)shareAppToSNSPlatform:(NSString *)platformString
                                   completedBlock:(void (^)(BOOL success, NSError *error))completedBlock;

@end
