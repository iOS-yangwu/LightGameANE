//
//  TTAccountDraft.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/26/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountDraft : NSObject
/** 手机号 */
+ (void)setDraftPhone:(NSString *)draftPhoneString;
+ (NSString *)draftPhone;

/** 用户昵称 */
+ (void)setNickname:(NSString *)nicknameString;
+ (NSString *)nickname;

/** 用户生日 */
+ (void)setBirthday:(NSString *)birthdayString;
+ (NSString *)birthday;

/** 用户性别 */
+ (void)setUserGender:(NSString *)despString;
+ (NSString *)userGender;

/** 用户签名 */
+ (void)setUserSignature:(NSString *)despString;
+ (NSString *)userSignature;
@end

NS_ASSUME_NONNULL_END
