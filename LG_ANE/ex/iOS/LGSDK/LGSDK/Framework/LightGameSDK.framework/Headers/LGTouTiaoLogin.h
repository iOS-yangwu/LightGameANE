//
//  LGTouTiaoLogin.h
//  LightGameSDK
//
//  Created by peiziming on 2019/7/28.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import "LGDefaultLogin.h"

NS_ASSUME_NONNULL_BEGIN


@interface LGTtOpenSDKSendAuthReq : NSObject

/**
 第三方应用程序向今日头条申请的必需权限类型，最终在今日头条App授权完成后根据实际授权结果返回给第三方应用；
 例如 [NSOrderedSet orderedSetWithObjects:@"user_info", ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *permissions;

/**
 第三方应用程序向今日头条申请的附加权限类型，用户可以勾选是否给予这部分权限，最终在今日头条App授权完成后根据实际授权结果返回给第三方应用；
 @key permission 权限
 @key defaultChecked 初始勾选状态，@"1"表示勾选，@"0"表示未勾选
 例如 [NSOrderedSet orderedSetWithObjects:@{@"permission":@"user_info",@"defaultChecked":@"0"}, ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSDictionary<NSString *,NSString *> *> *additionalPermissions;

/**
 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由今日头条App回传
 */
@property (nonatomic, copy, nullable) NSString *state;

@end


@protocol LGTtOpenSDKLogDelegate <NSObject>

/**
 接收来自今日头条的日志，可供调试用
 
 @param log 日志内容
 */
- (void)onLog:(NSString *)log;

@end


@interface LGTouTiaoLogin : LGDefaultLogin

+ (LGTouTiaoLogin *)sharedInstance;

- (void)authWithRequest:(LGTtOpenSDKSendAuthReq *)req;

/**
 设置SDK日志代理，可供调试
 
 同时仅允许存在一个日志代理，每次调用将覆盖之前的delegate
 
 SDK会弱引用这个logDelegate
 
 @param logDelegate 日志代理
 */
+ (void)registerLogDelegate:(id<LGTtOpenSDKLogDelegate>)logDelegate;

/**
 清除SDK日志代理，停止调试
 
 会清除之前设置的日志代理
 */
+ (void)unregisterLogDelegate;

/**
 处理今日头条通过URL启动第三方应用时传递的数据，需在[application:openURL:sourceApplication:annotation:]或者[application:handleOpenURL:]中调用
 
 @attention 必须在主线程执行
 
 @param url         启动第三方应用的URL
 @return 成功处理返回YES，否则返回NO
 */
+ (BOOL)handleOpenURL:(NSURL * _Nonnull)url;


@end

NS_ASSUME_NONNULL_END
