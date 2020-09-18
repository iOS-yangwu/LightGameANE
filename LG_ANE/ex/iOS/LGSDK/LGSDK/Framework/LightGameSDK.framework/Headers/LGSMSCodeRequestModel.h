//
//  LGSMSCodeRequestModel.h
//  LightGameSDK
//
//  Created by wangchao on 2019/8/1.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGSMSCodeRequestModel : NSObject<NSCopying, NSMutableCopying>

// 头条账号clienkKey
@property (nonatomic, assign) NSString *appID;
// 手机号
@property (nonatomic, copy) NSString *mobile;
@property (nonatomic, copy) NSString *zoneNum;
@property (nonatomic, copy) NSString *captcha;
/**
 授权作用域
 @"user_info"   用户信息
 @“relations”   好友列表，群信息等
 @“friend_relation”     好友关系
 @“message”     同步会话信息
 @“aweme.share”     抖音分享
 注意：多和作用域用逗号分隔
 */
@property (nonatomic, copy) NSString *scope;
// 第三方应用校验参 用于保持请求和回调状态，授权请求后会原样返回给第三方应用,如果是App则不用传该参数
@property (nonatomic, copy) NSString *state;
// 来源  非必填
@property (nonatomic, copy) NSString *from;
// 手机验证码
@property (nonatomic, copy) NSString *SMSCode;
// 手机验证码换a取的临时地凭据
@property (nonatomic, copy) NSString *ticket;
@property (nonatomic, copy) NSString *errCode;
@property (nonatomic, copy) NSString *errMsg;

@end

NS_ASSUME_NONNULL_END
