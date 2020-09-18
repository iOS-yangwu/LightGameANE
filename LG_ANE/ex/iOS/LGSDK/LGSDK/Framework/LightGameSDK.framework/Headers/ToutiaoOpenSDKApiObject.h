//
//  ToutiaoOpenSDKApiObject.h
//  Api对象，包含所有接口和对象数据定义
//
//  Created by 今日头条 on 18/9/2017.
//  Copyright (c) 2018年 今日头条. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ToutiaoOpenSDKErrorCode) {
    ToutiaoOpenSDKSuccess                = 0,    /** 成功 */
    ToutiaoOpenSDKErrorCodeCommon        = -1,   /** 通用错误类型 <包括网络错误> */
    ToutiaoOpenSDKErrorCodeUserCanceled  = -2,   /** 用户手动取消 */
    ToutiaoOpenSDKErrorCodeSendFailed    = -3,   /** 发送失败 */
    ToutiaoOpenSDKErrorCodeAuthDenied    = -4,   /** 权限错误 */
    ToutiaoOpenSDKErrorCodeUnsupported   = -5,   /** 不支持 */
};

#pragma mark - ToutiaoOpenSDKBaseReq

@interface ToutiaoOpenSDKBaseReq : NSObject

@end

#pragma mark - ToutiaoOpenSDKSendAuthReq

/**
 第三方程序向今日头条请求认证授权的消息结构
 
 第三方程序向今日头条发送认证用户的某些权限的请求，今日头条处理完成后会向第三方回送一个处理结果。
 */
@interface ToutiaoOpenSDKSendAuthReq : ToutiaoOpenSDKBaseReq

/**
 第三方应用程序向今日头条申请的必需权限类型，最终在今日头条App授权完成后根据实际授权结果返回给第三方应用；
 例如 [NSOrderedSet orderedSetWithObjects:@"user_info", ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *permissions;

/**
 第三方应用程序向今日头条申请的附加权限类型，用户可以勾选是否给予这部分权限，最终在今日头条App授权完成后根据实际授权结果返回给第三方应用；
 @key permission 权限
 @key defaultChecked 初始勾选状态，@"1"表示勾选，@"0"表示未勾选
 例如 [NSOrderedSet orderedSetWithObjects:@{@"permission":@"user_info",@"defaultChecked":@"0"}, ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSDictionary<NSString *,NSString *> *> *additionalPermissions;

/**
 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由今日头条App回传
 */
@property (nonatomic, copy, nullable) NSString *state;

@end

#pragma mark - ToutiaoOpenSDKBaseResp

@interface ToutiaoOpenSDKBaseResp : NSObject

/**
 错误码
 */
@property (nonatomic, assign) ToutiaoOpenSDKErrorCode errCode;

/**
 错误描述
 */
@property (nonatomic, copy, nullable) NSString *errString;

@end

#pragma mark - ToutiaoOpenSDKSendAuthResp

/**
 今日头条处理完成第三方应用的认证与权限申请后，回送给第三方应用的处理结果。
 
 第三方程序向今日头条申请权限认证，需要调用ToutiaoOpenSDKApi的[sendAuthReq:viewController:delegate:]函数，向今日头条发送ToutiaoOpenSDKSendAuthReq的请求，今日头条处理完成后会向第三方回送一个ToutiaoOpenSDKSendAuthResp对象的响应。
 */
@interface ToutiaoOpenSDKSendAuthResp : ToutiaoOpenSDKBaseResp

/**
 第三方应用向今日头条申请某些权限，最终在今日头条App授权完成后根据实际授权结果返回给第三方应用
 */
@property (nonatomic, copy, readonly, nullable) NSString *code;

/**
 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由今日头条回传
 */
@property (nonatomic, copy, readonly, nullable) NSString *state;

/**
 今日头条用户同意给予第三方应用程序的权限，若授权成功则包括全部必需权限和用户勾选的附加权限；
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *grantedPermissions;

@end

NS_ASSUME_NONNULL_END

