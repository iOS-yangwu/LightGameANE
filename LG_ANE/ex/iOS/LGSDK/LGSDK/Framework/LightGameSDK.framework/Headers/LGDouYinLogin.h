//
//  LGDouYinLogin.h
//  LightGameSDK
//
//  Created by peiziming on 2019/7/28.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import "LGDefaultLogin.h"

@interface LightGameDouYinAuthConfig : NSObject

/**
 第三方应用程序向抖音短视频申请的必需权限类型，最终在抖音短视频App授权完成后根据实际授权结果返回给第三方应用；
 例如 [NSOrderedSet orderedSetWithObjects:@"user_info", ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *permissions;

/**
 第三方应用程序向抖音短视频申请的附加权限类型，用户可以勾选是否给予这部分权限，最终在抖音短视频App授权完成后根据实际授权结果返回给第三方应用；
 @key permission 权限
 @key defaultChecked 初始勾选状态，@"1"表示勾选，@"0"表示未勾选
 例如 [NSOrderedSet orderedSetWithObjects:@{@"permission":@"user_info",@"defaultChecked":@"0"}, ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSDictionary<NSString *,NSString *> *> *additionalPermissions;

/**
 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由抖音短视频App回传
 */
@property (nonatomic, copy, nullable) NSString *state;

@end


@interface LGDouYinLogin : LGDefaultLogin

+ (LGDouYinLogin *_Nullable)sharedInstance;

- (void)authWithConfig:(LightGameDouYinAuthConfig *_Nonnull)cfg viewController:(UIViewController *_Nullable)vc;

@end
