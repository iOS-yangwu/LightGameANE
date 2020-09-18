//
//  LGRealNameVerifiedManager.h
//  LightGameSDK
//
//  Created by wangchao on 2019/11/20.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LGRealNameVerifiedModel.h"


NS_ASSUME_NONNULL_BEGIN


// 实名认证结果
typedef NS_ENUM(NSInteger, LGRNVerifiedResult) {
    LGRNVerifiedResultSuccForAdult = 1,             // 认证成功且为成年人
    LGRNVerifiedResultSuccForMinorAdult = 2,        // 认证成功且为未成年人
    LGRNVerifiedResultAlreadyVerified = -1,          // 该信息已实名认证过
    LGRNVerifiedResultFailCommon= -2,               // 认证失败，通用错误，如必要模型为空等
    LGRNVerifiedResultFailNet= -3,                  // 认证失败，网络错误
    LGRNVerifiedResultFailInvalidCardID = -4,        // 认证失败，身份证号不合法
    LGRNVerifiedResultFailInvalidLoginToken = -5,    // 认证失败，登录Token非法
    LGRNVerifiedResultFailNotMatch = -6,             // 认证失败，信息不匹配
    LGRNVerifiedResultFailUserCancle = -7,           // 认证失败，手动关闭认证窗口
    LGRNVerifiedResultFailForNotLogin = -8,         // 认证失败，登录体系未登录
    LGRNVerifiedResultFailForRequestFrequent = -9,         // 认证失败，请求过于频繁
};

// 实名框展示来自哪里
typedef NS_ENUM(NSInteger, LGRNVerifiedSituationFrom) {
    LGRNVerifiedSituationFromThirdPart = 0,                // 第三方调用
    LGRNVerifiedSituationFromNormalUser,                   // 正式账号
    LGRNVerifiedSituationFromGuestUser,                    // 游客账号
    LGRNVerifiedSituationFromNoUser,                       // 无账号体系
    LGRNVerifiedSituationFromGuestExperenceCountLimit,     // 游客账号15天无法重复体验
    LGRNVerifiedSituationFromGuestExperenceTimeLimit,      // 游客账号15天体验时长用尽
    LGRNVerifiedSituationFromNoAdultLimit                  // 触发未成年防沉迷
};


typedef void(^LGRNVerifiedResultCallBack)(LGRNVerifiedResult verifiedResult);
typedef void(^LGDeviceVerifiedInfoCallBack)(LGRealNameVerifiedModel * __nullable deviceVerifiedModel,  NSError * __nullable error);


@interface LGRealNameVerifiedManager : NSObject

// 是否SDK内部自主调用,第三方无需配置
@property(nonatomic, assign) BOOL isCalledBySdk;

// 实名认证从哪里触发 第三方无需配置
@property(nonatomic, assign) LGRNVerifiedSituationFrom verifiedSituationFrom;

+ (LGRealNameVerifiedManager *_Nonnull)sharedInstance;

/**  实名认证接口, 该接口会使用SDK内部的身份信息输入UI 对外接口
  @param completion 认证结果
 */
- (void)dealRealNameVerifiedWithCompletion:(LGRNVerifiedResultCallBack)completion;

/**  查询当前设备实名认证信息，该接口针对不接入账号体系的第三方调用；接入账号体系的会从登录结果中获取到  对外接口
 @param deviceVerifiedInfoCallBack 设备实名认证信息
*/
- (void )getCurrentDeviceVerifiedInfo:(LGDeviceVerifiedInfoCallBack)deviceVerifiedInfoCallBack;

/**
 处理接了登录但未调用的实名情况  第三方无需关注
 */
- (void)dealDeviceRealNameVerifiedWhenLoginIsNotSure;

/**
 取消处理接了登录但未调用的实名情况  第三方无需关注
 */
- (void)cancleDeviceRealNameVerifiedWhenLogin;

@end

NS_ASSUME_NONNULL_END
