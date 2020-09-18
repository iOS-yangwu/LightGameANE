//
//  TTAccountDataModel.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/10/17.
//

#import <Foundation/Foundation.h>
#import "TTResponseModelProtocol.h"
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  所有ResponseModel中的数据Model都继承该类
 */
@interface TTADataRespModel : NSObject
<
TTResponseModelProtocol
>

/**
 *  Transform Dictionary
 */
- (NSDictionary *)toDictionary;

@end


#pragma mark - 检测手机号是否可用
//  检测手机是否可用的 DataModel
@interface TTADataCheckMobileUseableModel: TTADataRespModel
@property (nonatomic, assign) BOOL isUnusable; /// 手机号是否为不可用状态
@property (nonatomic, assign) BOOL isVerified; /// 手机号是否为不可用状态
@property (nonatomic, assign) BOOL mnoSupport; /// 手机号是否为不可用状态
@property (nonatomic, copy, nullable)NSString *ticket; /// 手机号不可用状态凭证
@end


#pragma mark - 查看某个账户可用登录方式
@interface TTADataUseableLoginWaysModel : NSObject
@property (nonatomic, assign) BOOL hasEmail; /// 是否绑定邮箱
@property (nonatomic, assign) BOOL hasMobile; /// 是否绑定手机号
@property (nonatomic, assign) BOOL hasOauth; /// 是否绑定第三方
@property (nonatomic, assign) BOOL hasPwd; /// 是否设置密码
@property (nonatomic, assign) BOOL isMostDevice; /// 是否是常用设备
@property (nonatomic, copy, nullable) NSString *email; /// 掩码邮箱
@property (nonatomic, copy, nullable) NSString *mobiel; /// 掩码手机号
@property (nonatomic, copy, nullable) NSArray<NSString *> *oauthPlatforms; /// 绑定的三方平台
@property (nonatomic, copy) NSString *token;
@end

// 三方同步用户信息返回值
@interface TTAGetThridPartUserInfoModel : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *avatarUrl;

@end

// 查询用户是否可修改用户信息
@interface TTACheckUserCanSetModel : NSObject

@property (nonatomic, assign) BOOL canSet;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy) NSString *descriptionMsg;

@end

@interface TTACheckUserInfoCanModifyModel : NSObject

@property (strong, nonatomic) NSNumber *errorCode;
@property (strong, nonatomic) NSString *descriptionMsg;
@property (strong, nonatomic) NSNumber *show;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *avatarUrl;
@property (strong, nonatomic) NSNumber *isNameValid;
@property (strong, nonatomic) NSNumber *isAvatarValid;
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSString *save;
@property (strong, nonatomic) NSString *tips;

@end

#pragma mark - 账号注销，价值判断
@interface TTADataAccountValueModel : TTADataRespModel

/// 用户价值类型
@property (nonatomic, assign) TTAccountValueType userType;

/// 用户认证方式
@property (nonatomic, assign) TTAccountCancelAuthorizeType authType;

/// 如果是认证方式为三方认证，可使用的第三方
@property (nonatomic, copy, nullable) NSArray<NSString *> *oauthPlatforms;

/// 价值认证的ticket
@property (nonatomic, copy) NSString *valueTicket;
@end


NS_ASSUME_NONNULL_END
