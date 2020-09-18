//
//  LGUserModel.h
//  LightGameSDK
//
//  Created by wangchao on 2019/8/12.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 登录类型
typedef NS_ENUM(NSInteger, LGLoginType) {
    LGLoginTypeGuest = 1,       // 游客登录
    LGLoginTypeToutiao,         // 头条授权登录
    LGLoginTypeDouyin,          // 抖音授权登录
    LGLoginTypePhone,           // 手机号登录
    LGLoginTypeApple            // 苹果登录
};

// 用户信息类
@interface LGUserModel : NSObject<NSCopying, NSMutableCopying>

@property (nonatomic, copy) NSString *openID;   // openID
@property (nonatomic, copy) NSString *autoLoginToken;   // 登录Token
@property (nonatomic, assign) LGLoginType loginType;    // 登录类型
@property (nonatomic, copy) NSString *lastOpenID;       // 上次登录类型的openID
@property (nonatomic, copy) NSString *nickName;         // 第三方用户名
@property (nonatomic, copy) NSString *avator;           // 第三方头像地址
@property (nonatomic, copy) NSString *errCode;          // 错误码
@property (nonatomic, copy) NSString *errMsg;           // 错误信息
@property (nonatomic, copy) NSString *mobile;           // 手机号信息
@property (nonatomic, strong) NSArray *thirdScopes;           // 三方授权域
@property (nonatomic, assign) BOOL isRealNameVerified;     // 用户是否实名认证
@property (nonatomic, assign) BOOL isAdult;    // 用户是否成年，当isRealNameVerified=true时该属性才有效
@property (nonatomic, copy) NSString *thirdPartyOpenID;   // 第三方 open id（仅对部分cp返回，如有需要，请联系pm）

+ (LGUserModel *)currentUserInfo;

@end

NS_ASSUME_NONNULL_END
