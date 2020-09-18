//
//  TTAccountUserEntity.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TTAccountDefine.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  头条帐号用户实体
 *  @Wiki: https://wiki.bytedance.net/pages/viewpage.action?pageId=524948#id-享评SDK-获取当前登录用户的个人信息
 */
@class TTAccountMediaUserEntity;
@class TTAccountPlatformEntity;
@class TTAccountUserAuditEntity;
@class TTAccountVerifiedUserAuditEntity;
@class TTAccountMediaUserAuditEntity;
@class TTAccountUserAuditSet;
@interface TTAccountUserEntity : NSObject <NSCopying, NSSecureCoding>

/*
    鉴于目前有些业务方会自己维护用户数据，该接口只能保证如下数据一定是准确的以下是/passport/account/info/v2/，确保准确的信息
 */
/// 第三方平台绑定后的帐号信息
@property (nonatomic, copy) NSArray<TTAccountPlatformEntity *> *connects;
/// 打码的邮箱
@property (nonatomic,   copy) NSString *email;
/// 掩码手机号
@property (nonatomic,   copy) NSString *mobile;
/// 手机还号所属区号, 中国默认为0
@property (nonatomic, copy) NSString *countryCode;
/// 系统新生成的session标识符
@property (nonatomic,  copy, nonnull) NSString *sessionKey;
/// 是否设置过password，非头条系能用
@property (nonatomic, assign) BOOL hasPassword;
/*
 以下是/passport/account/info/v2/提供，但需要确定业务app 是否有其它用户信息接口
 */

/// 用户头像（小图URL）
@property (nonatomic, copy) NSString *avatarURL;
/// 用户Profile背景图
@property (nonatomic, copy) NSString *bgImgURL;
/// 能否通过手机号被发现
@property (nonatomic, assign) BOOL canBeFoundByPhone;
/// 用户签名
@property (nonatomic,   copy) NSString *userDescription;

/// 性别  (0： 未知， 1： 男， 2： 女)
@property (nonatomic, strong) NSNumber *gender;
/// 登录用户是否拉黑目标用户
@property(nonatomic,  assign) BOOL isBlocking;
///
@property(nonatomic,  assign) BOOL isBlocked;
/// 是否允许被推荐
@property(nonatomic,  assign) BOOL isRecommendAllowed;

/// 用户名
@property (nonatomic,   copy) NSString *name;
/// 推荐提示信息，如：“同时推荐给我的粉丝"
@property(nonatomic,    copy) NSString *recommendHintMessage;
/// 屏幕显示名
@property (nonatomic,   copy) NSString *screenName;
/// 用户唯一标识
@property (nonatomic, strong, nonnull) NSNumber *userID;
/// 区分是否是认证用户
@property (nonatomic, assign) BOOL userVerified __deprecated;
/// https://wiki.bytedance.net/pages/viewpage.action?pageId=62426617
@property (nonatomic,   copy) NSString *verifiedContent __deprecated;


/*
 以下是头条专用信息
 */
// 帐号合并时用属性
@property (nonatomic, copy) NSString *otherToken;
@property (nonatomic, copy) NSString *otherScreenName;
@property (nonatomic, copy) NSString *otherAvatarUrl;
@property (nonatomic, copy) NSString *otherMobile;

// 是否是头条内测用户
@property (nonatomic, assign) BOOL isToutiao;

// IM类APP需使用
@property (nonatomic, copy, nullable) NSString *token;

// 是否是新用户
@property (nonatomic, assign) BOOL newUser;

// 是否跳过用户编辑页面
@property (nonatomic, assign) BOOL skipEditProfile;


// PGC用户的唯一标识；如存在media_id则表示为是PGC用户，否则表示该用户是非PGC用户
@property (nonatomic, strong, nullable) NSNumber *mediaID;

// PGC用户详细信息
@property (nonatomic, strong, nullable) TTAccountMediaUserEntity *media;


// 默认是否开放用户隐私信息，默认为0
@property (nonatomic, assign) NSInteger userPrivacyExtend;

// 生日
@property (nonatomic,   copy) NSString *birthday;

// 地区
@property (nonatomic,   copy) NSString *area;

// 行业
@property (nonatomic,   copy) NSString *industry;

// 用户头像（大图URL）
@property (nonatomic,   copy) NSString *avatarLargeURL;

// 用户佩饰
@property (nonatomic,   copy) NSString *userDecoration;

// 头条认证展现
@property(nonatomic,    copy) NSString *userAuthInfo;

//
@property (nonatomic,   copy) NSString *verifiedReason;

//
@property (nonatomic,   copy) NSString *verifiedAgency;

//
@property (nonatomic,   copy) NSString *recommendReason;

//
@property (nonatomic,   copy) NSString *reasonType;

//
@property (nonatomic, strong) NSNumber *point;

// 个人主页分享url
@property (nonatomic,   copy) NSString *shareURL;

// safe表示是否设置过密码，如果该字段不存在或不为1表示没有设置过密码，否则设置过
@property (nonatomic, strong) NSNumber *safe;


// 是否已关注该用户
@property(nonatomic,  assign) BOOL isFollowing;

// 是否被别人关注
@property(nonatomic,  assign) BOOL isFollowed;



// 表示用户是否允许开启站外分享，默认 -1
@property(nonatomic,  assign) NSInteger shareToRepost;
// 粉丝数
@property (nonatomic, assign) long long followersCount;

// 关注数
@property (nonatomic, assign) long long followingsCount;

// 最近访问好友数
@property (nonatomic, assign) long long visitCountRecent;

// 动态数
@property (nonatomic, assign) long long momentsCount;
// 点赞数
@property (nonatomic, assign) long long diggsCount;

// 手机号登陆后返回是否可以绑定游客的提示
@property (nonatomic, assign) BOOL canBindVisitorAccount;

// 是否手动设置了头像和昵称
@property (nonatomic, assign) BOOL isManualSetUserInfo;

// 是否是游客账号
@property (nonatomic, assign) BOOL isVisitorAccount;

// 用户审核信息集
@property (nonatomic, strong) TTAccountUserAuditSet *auditInfoSet;

/// 该用户的游客方式注册时的deviceId，游客账号升级为正常账号后，对应的还是之前注册是的did
@property (nonatomic, copy) NSString *deviceId;

// 业务方特殊用户信息字段，SDK透传
@property (nonatomic, copy) NSDictionary *expendAttrs;

// 加密uid
@property (nonatomic, copy) NSString *secUserId;

// 返回用户`id`对应字符串
- (nullable NSString *)userIDString;

// Media用户返回对应string，否则返回nil
- (nullable NSString *)mediaIDString;

- (NSDictionary *)toDictionary;

/// 根据dic 生成
/// @param dict 登录、注册接口返回的json 结构
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end



/**
 *  媒体(PGC)用户信息
 */
@interface TTAccountMediaUserEntity : NSObject <NSCopying, NSSecureCoding>
// PGC用户，老的PGC用户ID与登录用户ID不同
@property (nonatomic, strong, nonnull) NSNumber *mediaID;

// 媒体名称
@property (nonatomic,   copy) NSString *name;

// 审核通过的头像
@property (nonatomic,   copy) NSString *avatarURL;

// 是否通过认证
@property (nonatomic, assign) BOOL userVerified;

// 是否展示 "实名认证" 入口(1 展示 0 不展示)
@property (nonatomic, assign) BOOL displayAppOcrEntrance;

- (NSDictionary *)toDictionary;
@end



/**
 *  绑定的第三方平台帐号信息
 */
@interface TTAccountPlatformEntity : NSObject <NSCopying, NSSecureCoding>
// 用户在头条平台唯一标识
@property (nonatomic, strong, nonnull) NSNumber *userID;

// 第三方平台的唯一标识
@property (nonatomic,   copy, nonnull) NSString *platformUID;

// 头条内部定义的平台名称
@property (nonatomic,   copy, nonnull) NSString *platform;

// 用户在第三方平台设置的名称
@property (nonatomic,   copy) NSString *platformScreenName;

// 用户在第三方平台的头像链接
@property (nonatomic,   copy) NSString *profileImageURL;

/// 同一帐号组的apps 对于同一个第三方可能返回多条，对应每个绑定发生的时间
@property (nonatomic, strong) NSNumber *modifyTime;
// 第三方平台授权的过期时间
@property (nonatomic, strong) NSNumber *expiredIn;
@property (nonatomic, strong) NSNumber *expiredTime;

- (NSDictionary *)toDictionary;
@end

/**
 *  上传图片后，返回的图片实体
 */
@interface TTAccountImageListEntity : NSObject
@property (nonatomic, copy) NSString *origin_url;
@property (nonatomic, copy) NSString *thumb_url;
@property (nonatomic, copy) NSString *medium_url;
@end

@interface TTAccountImageEntity : NSObject
@property (nonatomic,   copy) NSString *web_uri;
// 图片 URL list
//@property (nonatomic, strong) TTAccountImageListEntity *url_list;
@end

@interface TTADeviceLoginUserInfo:NSObject

@property (nonatomic, assign) TTADeviceLoginInfoType deviceLoginType; /// 目前都是上一次登录TTADeviceLoginInfoOfLatest
@property (nonatomic, assign) TTAccountLoginType loginType; /// 登录类型
@property (nonatomic, copy) NSString *userId;   /// 用户id
@property (nonatomic, copy) NSString *secUserId; /// 加密uid
@property (nonatomic, copy) NSString *accountInfo; ///用户登录的（手机号、账号、邮箱、第三方平台的名称等）
@property (nonatomic, copy) NSString *countryCode;  /// 电话号码的地区代码，需要配置    [TTAccount accountConf].mobileSeparator
@property (nonatomic, copy) NSString *maskAccountInfo;  /// 用户手机号、邮箱掩码信息
@property (nonatomic, copy) NSString *screenName;   /// 用户昵称
@property (nonatomic, copy) NSString *avatarUrl;    /// 用户头像
@property (nonatomic, copy) NSString *platformScreenName; ///第三方平台的上的用户名称
@property (nonatomic, copy) NSString *platformImageUrl;  /// 第三方平台对应的用户头像
@property (nonatomic, copy) NSString *ticket; /// 暂时忽略
@property (nonatomic, assign) NSInteger ticketExpiredTime; /// 暂时忽略
@property (nonatomic, assign) NSInteger loginTime; /// 登录时间，秒戳

@end

NS_ASSUME_NONNULL_END
