//
//  TTAccountPlatformConfiguration.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 13/12/2017.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN


/**
 第三方平台配置。主要包括以下三方面：
 1. 第三方平台的基本配置信息，必须配置
 2. BytedanceSDK内定义平台的配置信息，有默认值（platformAppInstallUrl、platformInstalledURLSchemes和platformSupportedURLSchemes）
 3. TTACustomWapAuthViewController的外观配置
 */
@interface TTAccountPlatformConfiguration : NSObject

/** 第三方平台类型（文件TTAccountDefine中定义），必须手动赋值，参考TTAccountAuthType；默认为TTAccountAuthTypeUnsupport */
@property (nonatomic, assign) NSInteger platformType;

/** 在第三方平台申请的appId|clientKey|consumerKey；默认采用懒加载方式进行注册 */
@property (nonatomic, copy, nonnull) NSString *consumerKey;

/** 在第三方平台申请的appSecret|clientSecret|consumerSecret */
@property (nonatomic, copy, nullable) NSString *consumerSecret;

/** 是共享第三方平台的登录状态（用户信息），如果使用则帐号中心不会产生新用户，否则产生新用户并绑定到第三方平台 */
@property (nonatomic, assign) BOOL isShareUserInfo;

/** 第三方授权平台在头条帐号系统中的名称，后端给定（联系@张煜卿），platformName将会用platformAppId替代 */
@property (nonatomic, copy, nonnull) NSString *platformName;

/** 第三方授权平台在头条帐号系统中的唯一标识ID，后端给定（联系@张煜卿） */
@property (nonatomic, copy, nonnull) NSString *platformAppId;

/** 第三方授权平台本地化可显示的名称 */
@property (nonatomic, copy, nonnull) NSString *platformAppDisplayName;

/** 第三方授权平台的回调地址（在第三方平台申请APP时填写） <@attention: 微博的回调地址不能为空，其他平台可空> */
@property (nonatomic, copy, nullable) NSString *platformRedirectUrl;

/** 如果使用非微博SDK方式（scheme方式）进行微博授权时，微博callback scheme不能为空；目前仅仅头条代码在使用 */
@property (nonatomic, copy, nullable) NSString *authCallbackSchemeUrl;

/** 由于注册第三方平台比较耗时，可采用懒加载来对第三方平台进行注册 */
@property (nonatomic, copy, nullable) void (^laziedRegisterPlatformHandler)(void) __deprecated_msg("使用consumerKey代替");

/** 设置第三方平台WAP授权登录时，使用第三方SDK默认的WAP登录方式还是自定义WAP授权登录方式；默认是YES */
@property (nonatomic, assign) BOOL useDefaultWAPLogin;

/** 设置当第三方SDK授权失败时，是否使用自定义的WAP方式进行授权登录；默认是YES */
@property (nonatomic, assign) BOOL tryCustomLoginWhenSDKFailure;

#pragma mark - performance optimization

/** 设置注册第三方平台时，是否进行懒注册（当且仅当首次调用头条封装的第三方平台接口时注册）以优化APP启动加载时长；默认是YES */
@property (nonatomic, assign) BOOL bootOptimization;

#pragma mark - TTACustomWapAuthViewController

/** 设置自定义第三方WAP授权登录ViewController下面SNSBar上的文案；默认为 */
@property (nonatomic, copy, nullable) NSString *snsBarText;

/** 设置自定义第三方WAP授权登录ViewController SNSBar是否隐藏；默认为NO */
@property (nonatomic, assign) BOOL snsBarHidden;

#pragma mark - Bytedancebase SDK使用

/** 第三方授权平台APP在App Store上的下载地址；仅仅公司内部产品接入Bytedancebase SDK时需要配置 */
@property (nonatomic, copy, nonnull) NSString *platformAppInstallUrl;

/** 第三方授权平台APP安装所支持的Schemes，用来判断APP是否安装；仅仅公司内部产品接入Bytedancebase SDK时需要配置 */
@property (nonatomic, copy, nonnull) NSArray<NSString *> *platformInstalledURLSchemes;

/** 第三方授权平台APP支持O所支持的Schemes，用来判断APP是否安装；仅仅公司内部产品接入Bytedancebase SDK时需要配置 */
@property (nonatomic, copy, nonnull) NSArray<NSString *> *platformSupportedURLSchemes;

/** 需要使用的的第三方授权平台APP所需权限 **/
@property (nonatomic, strong, nullable) NSOrderedSet<NSString *> *permissions;

/**
 应用程序向第三方平台申请的附加权限类型，用户可以勾选是否给予这部分权限，最终在平台授权完成后根据第三方平台的实际授权结果返回给应用；
 @key permission 权限
 @key defaultChecked 初始勾选状态，@"1"表示勾选，@"0"表示未勾选
 例如 [NSOrderedSet orderedSetWithObjects:@{@"permission":@"user_info",@"defaultChecked":@"0"}, ..., nil]
 */
@property (nonatomic, strong, nullable) NSOrderedSet<NSDictionary<NSString *,NSString *> *> *additionalPermissions;

/// 使用universal link 进行app 跳转时需要配置的跳转链接
@property (nonatomic, copy, nullable) NSString *universalLink;

@end



/**
 *  配置WAP授权登录ViewController信息
 *  Class: TTACustomWapAuthViewController
 */
@interface TTAccountCustomLoginConfiguration : NSObject

#pragma mark - appearance

/** Custom Wap Login NavigationBar barTintColor [Default is whiteColor] */
@property (nonatomic, strong, nullable) UIColor *navBarBackgroundColor;

/** Custom Wap Login NavigationBar tintColor [Default is 0x464646] */
@property (nonatomic, strong, nullable) UIColor *navBarTintColor;

/** Custom Wap Login NavigationBar titleTextColor [Default is 0x464646] */
@property (nonatomic, strong, nullable) UIColor *navBarTitleTextColor;

/** Custom Wap Login NavigationBar line color [Default is 0xe8e8e8]*/
@property (nonatomic, strong, nullable) UIColor *navBarBottomLineColor;

@end


NS_ASSUME_NONNULL_END
