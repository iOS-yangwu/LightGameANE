//
//  TTAccount+Notifications.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TTAccount.h"



@interface TTAccount (AppLaunchHelper)

+ (BOOL)isAPPFirstInstall;

+ (void)setAPPHasInstalled;

@end



@interface TTAccount (Notifications)

/**
 *  Register notifications
 */
- (void)__registerNotifications__;

/**
 *  Unregister notifications
 */
- (void)__unregisterNotifications__;

/**
 *  当没有登录但sessionKey存在时，尝试从网络同步用户状态
 */
+ (void)synchronizeAccountUserStatusByNetwork:(void (^)(BOOL loggedOnCurrently))completedBlock
                                waitUntilDone:(BOOL)wait;

@end
