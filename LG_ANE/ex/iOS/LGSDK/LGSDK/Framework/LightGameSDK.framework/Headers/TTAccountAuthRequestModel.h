//
//  TTAccountAuthRequestModel.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/11/22.
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountAuthRequest : NSObject


/// 请求授权的场景，场景不同授权成功后调用的帐号接口不同
@property (nonatomic, assign) TTAccountRequestAuthReason requestReason;

/// YES 表示强制绑定手机号，手机号未填写或绑定冲突时会返回特定错误；NO 非强制绑定时，与正常三方注册逻辑一致
@property (nonatomic, assign) BOOL needMobile;

/// YES 表示三方手机号已经存在帐号，且该帐号已有三方，直接解绑原有三方并绑定当前三方
@property (nonatomic, assign) BOOL changeBind;

/** 需要使用的的第三方授权平台APP所需权限,目前仅头条、抖音等公司内app使用,空值时 默认权限为user_info **/
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *permissions;

/**
 应用程序向第三方平台申请的附加权限类型，用户可以勾选是否给予这部分权限，最终在平台授权完成后根据第三方平台的实际授权结果返回给应用；
 @key permission 权限
 @key defaultChecked 初始勾选状态，@"1"表示勾选，@"0"表示未勾选
 例如 [NSOrderedSet orderedSetWithObjects:@{@"permission":@"mobile",@"defaultChecked":@"0"}, ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSDictionary<NSString *,NSString *> *> *additionalPermissions;

/// 三方授权wap 页是否需要强制竖屏
@property (nonatomic, assign) BOOL mustPortrait;

/// 主要用于公司内部平台（头条、抖音等）授权时传入特殊字段，例如
//extra_info = @{
//   @"skip_tel_num_bind":@(YES)//抖音端跳过强制绑定手机号流程

//};
@property (nonatomic, strong, nullable) NSDictionary *extraInfo;

/// 某些特殊场景需要跳过某些scheme 的授权，强制走web 授权，目前只有抖音平台支持，例如在安装抖音低版本时,可以填
@property (nonatomic, copy) NSArray <NSNumber *> *fallbackIgnore;

@end

/**
 * 使用第三方平台SDK认证时，出现第三方平台已被绑定，后台要求改变绑定的ResponseModel
 * 场景如下：1. 例如微信绑定了手机A，然后使用手机B登录；再绑定微信时，就会提示微信已绑定到某某手机号，请先解绑；
 *         2. 手机A登录，然后微博登录；再用手机A登录并绑定微博时，会出现微博已绑定，请先解绑
 */
@interface TTASNSSDKAuthSwitchBindReqModel : NSObject

/** 第三方平台返回的code，profileKey、code、auth_token三选一*/
@property (nonatomic, copy) NSString *code;

/// 三方授权时的临时凭证，profileKey、code、auth_token三选一
@property (nonatomic, copy) NSString *profileKey;

/** 服务端返回的第三方平台认证的token(auth_token)，profileKey、code、auth_token三选一 */
@property (nonatomic, copy) NSString *authToken;

/// 仅google平台需要
@property (nonatomic, copy) NSString *authTokenSecret;


/// token过期时间
@property (nonatomic, assign) long expireIn;

/// 第三方平台openId
@property (nonatomic, copy) NSString *openid;

/// 第三方平台类型
@property (nonatomic, assign) TTAccountAuthType platformType;

/// 三方手机号已经存在帐号，且该帐号已有三方，直接解绑原有三方并绑定当前三方
@property (nonatomic, assign) BOOL chanageBind;

@end

NS_ASSUME_NONNULL_END
