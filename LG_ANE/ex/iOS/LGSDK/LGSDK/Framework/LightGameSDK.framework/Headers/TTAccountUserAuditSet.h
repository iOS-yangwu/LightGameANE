//
//  TTAccountUserAuditSet.h
//  BDAccount
//
//  Created by bytedance on 2018/6/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 用户审核信息
 *
 *  @Wiki: https://wiki.bytedance.com/pages/viewpage.action?pageId=62424459#id-帐号合并后的用户和关系API-关注页内的兴趣列表
 */
@interface TTAccountUserAuditEntity : NSObject <NSCopying, NSSecureCoding>
@property (nonatomic,   copy) NSString *name;
@property (nonatomic,   copy) NSString *userDescription;
@property (nonatomic,   copy) NSString *avatarURL;

@property (nonatomic, strong) NSNumber *gender;
@property (nonatomic,   copy) NSString *birthday;
@property (nonatomic,   copy) NSString *industry;
@property (nonatomic,   copy) NSString *area;

- (NSDictionary *)toDictionary;
@end

@interface TTAccountVerifiedUserAuditEntity : TTAccountUserAuditEntity

@end

@interface TTAccountMediaUserAuditEntity : TTAccountUserAuditEntity
// 是否在审核中
@property (nonatomic, assign) BOOL auditing;
@property (nonatomic, strong) NSNumber *expiredTime;
@property (nonatomic, assign) BOOL isPersonalPGC;
@end

@interface TTAccountUserAuditSet : NSObject <NSCopying, NSSecureCoding>
@property (nonatomic, strong) TTAccountUserAuditEntity         *currentUserEntity;
@property (nonatomic, strong) TTAccountVerifiedUserAuditEntity *verifiedUserAuditEntity;
@property (nonatomic, strong) TTAccountMediaUserAuditEntity    *pgcUserAuditEntity;

- (NSDictionary *)toDictionary;
- (NSDictionary *)toOriginalDictionary;

@end

NS_ASSUME_NONNULL_END
