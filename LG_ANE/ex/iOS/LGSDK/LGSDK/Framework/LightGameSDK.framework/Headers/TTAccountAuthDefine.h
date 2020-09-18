//
//  TTAccountAuthDefine.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 16/12/7.
//  Copyright © 2016年 com.bytedance.news. All rights reserved.
//

#ifndef TTAccountAuthDefine_h
#define TTAccountAuthDefine_h

#import "TTAccountDefine.h"



NS_ASSUME_NONNULL_BEGIN


/**
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=524948#id-享评SDK-更新当前登录用户的个人信息
 */



#define TTAccountAuthCorpProductMinType   (10)

#define TTAccountAuthCorpProductMaxType   (999)



/** 第三方平台授权登录相关的错误码 */
typedef
NS_ENUM(NSInteger, TTAccountAuthErrCode) {
    TTAccountAuthErrCodeUnknown           = -1,/** 未知 */
    TTAccountAuthSuccess                  = 0, /** 成功 */
    
    TTAccountAuthErrCodeCommon            = 1, /** 普通错误 */
    TTAccountAuthErrCodeURAppId           = 2, /** 没有注册(unregistered)AppID */
    TTAccountAuthErrCodeUserCancel        = 3, /** 用户主动取消 */
    TTAccountAuthErrCodeSendFail          = 4, /** 发送失败 */
    TTAccountAuthErrCodeNetworkFail       = 5, /** 网络错误 */
    TTAccountAuthErrCodeAuthDeny          = 6, /** 授权失败 */
    TTAccountAuthErrCodeUnsupport         = 7, /** 平台不支持 */
    TTAccountAuthErrCodeCancelInstall     = 8, /** 取消应用下载 */
    TTAccountAuthErrCodeCSRFAttack        = 9, /** csrf 攻击 */
};




/**
 *  UserInfo in notification:
 *  {
 *      TTAccountStatusCodeKey: ***,
 *      TTAccountAuthPlatformTypeKey: ***,
 *      TTAccountAuthPlatformNameKey: ***,
 *      TTAccountAuthPlatformResponseKey: ***,
 *  }
 *
 */
/** 第三方平台授权完成通知 */
FOUNDATION_EXPORT
NSString * TTAccountPlatformDidAuthorizeCompletionNotification;

/** 第三方授权平台类型 NSNumber(TTAccountAuthType) */
FOUNDATION_EXPORT
NSString * TTAccountAuthPlatformTypeKey;

/** 第三方授权平台响应 */
FOUNDATION_EXPORT
NSString * TTAccountAuthPlatformResponseKey;

/**
 *  获取错误码描述
 */
FOUNDATION_EXPORT NSString *TTAccountGetAuthErrorCodeDescription(TTAccountAuthErrCode errcode);

/// 获取前后台切换时 账号SDK 自动取消的error 信息
FOUNDATION_EXPORT NSError *TTAccountGetAuthCancelError();

/// 获取授权失败的 error 信息
FOUNDATION_EXPORT NSError *TTAccountGetAuthError(TTAccountAuthErrCode errcode,NSInteger originErrCode, NSString *originErrMsg);

@class TTAccountAuthResponse;
@class TTAGetThridPartUserInfoModel;
typedef
void (^TTAccountAuthWillLoginBlock)(NSString * _Nonnull platformName);
/// 获取三方授权code/token 等信息
typedef
void (^TTAccountAuthLoginCompletedBlock)(TTAccountAuthResponse * _Nullable resp, NSError * _Nullable error);
typedef
void (^TTAccountAuthUserInfoCompletedBlock)(TTAGetThridPartUserInfoModel *  _Nullable thirdUserInfo, NSError * _Nullable error);



NS_ASSUME_NONNULL_END



#endif /* TTAccountAuthDefine_h */
