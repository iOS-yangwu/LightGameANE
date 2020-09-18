//
//  LightGameManager.h
//  LightGameSDK
//
//  Created by 李盛 on 2019/4/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGBDConfig.h"
#import "TikTokOpenPlatformShare.h"
#import "LGAntiAddictionResultModel.h"

@class DouyinOpenSDKBaseResp;
@class LightGameDouYinAuthConfig;


// 防沉迷服务回调
typedef void(^LGAntiAddictionResultBlock)(LGAntiAddictionResultModel * _Nullable antiAddictionResult);


@interface LightGameDouYinAppletConfig : NSObject

/**
 * 小程序id 发起分享的App需要在开放平台绑定对应的小程序，分享视频时判定，非合法小程序appid返回错误码，分享失败。
 */
@property (nonatomic, copy) NSString * _Nullable appletID;

/**
 * 具体页面 指定页面，为空或解析不正确则跳转小程序首页
 */
@property (nonatomic, copy) NSString * _Nullable startPageUrl;

/**
 * 标题 指定页面，为空或解析不正确则跳转小程序首页
 */
@property (nonatomic, copy) NSString * _Nullable title;

/**
 * 副标题 显示在评论区小程序入口的副标题，为空显示“小程序/小游戏”
 */
@property (nonatomic, copy) NSString * _Nullable descriptionTitle;

@end

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LGDebugLogType) {
    LGDebugLogType_Chinese,
    LGDebugLogType_English
};

typedef NS_ENUM(NSUInteger, LGADouyinOpenSDKShareMediaType) {
    LGADouyinOpenSDKShareMediaTypeImage = 0, // 对应 PHAssetMediaTypeImage
    LGADouyinOpenSDKShareMediaTypeVideo, // 对应 PHAssetMediaTypeVideo
};

@protocol LGTikTokShareDelegate <NSObject>

@optional

/**
 第三方应用程序通过sendReq向抖音短视频发送请求后，收到来自抖音短视频的响应
 
 @param resp 抖音短视频回应的具体内容
 */
-  (void)didReceiveShareResponse:(TikTokOpenPlatformShareResponse *)resp;

@end

@protocol LGTikTokLogDelegate <NSObject>
/**
 接收来自抖音短视频的日志，可供调试用
 
 @param log 日志内容
 */
- (void)onLog:(NSString *)log;

@end

@interface LightGameManager : NSObject

@property (nonatomic, strong) NSString *abVersions;/** abTest版本*/

@property (nonatomic, copy, readonly) NSString * _Nonnull appID;/** 应用唯一标示 */
@property (nonatomic, copy, readonly) NSString *channel;/** 应用渠道 */
@property (nonatomic, copy, readonly) NSString *appName; /** 名称 */
@property (nonatomic, copy, readonly) NSString *clientKeyBD; /** 深度转化 key*/
@property (nonatomic, copy, readonly) NSString * _Nonnull clientKeyDouyin;/** 抖音分享clientKeyDouyin */
@property (nonatomic, copy, readonly) NSString *clientKeyTtAuth;  /** 头条账号授权申请的clientKey */
@property (nonatomic, copy, readonly) NSString * _Nonnull clientKeyAd; /** 穿山甲广告平台申请的appKey */
@property (nonatomic, copy, readonly) NSString *clientKeyBDTuring;  /* BDTuring(验证码模块)申请的appid */
@property (nonatomic, copy) NSString *_Nonnull deviceID; // 为内部测试使用
@property (nonatomic, copy, readonly) NSString *oldKey;

@property (nonatomic, copy) NSString *platformAppId; // 登录id


+ (LightGameManager *)sharedInstance;

/** 
 @param isNeedDebugLog 是不是需要调试状态的log YES控制台会有log输出方便错误定位，NO没有相关错误定位输出，默认是NO
 */
+ (void)isDebuLog:(BOOL)isNeedDebugLog;

/**
 @param logType 默认是中文
 */
+ (void)debugType:(LGDebugLogType)logType;

/**
 初始化广告变现SDK
 
 @param appID 平台所申请的appID
 @param appName 发布包名
 @param channel 发布渠道 iOS 一般为 “APP Store”
 */
+ (void)startWithAppID:(NSString *_Nonnull)appID appName:(NSString *_Nonnull)appName channel:(NSString *_Nonnull)channel;

/**
 超休闲SDK版本号
 */
- (NSUInteger)getLightGameVersion;

/**
注册防沉迷服务，当游戏时间到达防沉迷规定限制后，SDK会采取一定措施:
 当初始化启动游戏即发现到达限制，SDK会弹框阻止游戏进行；如果在游戏中达到限制，SDK会通过回调告诉第三方
 @param antiAddictionResult 防沉迷服务时长打到限制需要回调给cp的信息
*/
- (void)registerAntiAddictionService:(LGAntiAddictionResultBlock)antiAddictionResult;

/// 用于设置隐私弹窗的相关信息
/// @param gameName 游戏名称
/// @param componyName 主体名称
/// @param updateDate 更新日期
/// @param validDate 生效日期
- (void)setPrivacyPopupWithGameName:(NSString*)gameName andComponyName:(NSString*)componyName andUpdateDate:(NSString*)updateDate andValidDate:(NSString*)validDate;

//===================================================================================================
//==================================抖音分享相关方法====================================================
//===================================================================================================

/**
 分享到抖音 (使用SDK内部录屏功能的接入方可以使用LightGameRecorder类的接口直接分享到抖音App，无需调用此接口。此接口是提供给使用自身游戏内部录屏功能，想分享到抖音的接入方提供)
 
 @param mediaType urlPaths在相册中对应的Media类型，urlPaths里面的必须都是同一种类型
 @param localIdentifiers 第三方应用程序向抖音短视频分享的视频或图片在 **相册** 中的中的local identifier，上限为12个，内容须全部为图片，或者全部为视频。
 若内容为视频，视频总时长应该大于3s；
 图片的宽高比应满足：1/2.2<=宽高比<=2.2；
 视频分辨率应满足：1/2.2<=宽高像素比<=2.2；
 请三方应用程序自行检查分享的内容是否满足要求；
 此处需注意，带品牌logo或品牌水印的视频，会命中抖音的审核逻辑，有比较大的概率导致分享视频推荐降权处理/分享视频下架处理/分享账号被封禁处理，请予以重视；
 强烈建议第三方应用自行处理好分享内容中的不合规水印。
 @param state 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由抖音短视频App回传
 @param info 游戏小程序相关信息 传空则默认不分享小程序
 */
- (BOOL)douyinShareWithMediaType:(LGADouyinOpenSDKShareMediaType)mediaType localIdentifiers:(NSArray *)localIdentifiers state:(NSString *)state appletInfo:(LightGameDouYinAppletConfig * _Nullable )info;
/**
 处理抖音短视频通过URL启动第三方应用时传递的数据，需在[application:openURL:sourceApplication:annotation:]或者[application:handleOpenURL:]中调用
 
 @attention 必须在主线程执行
 
 @param url         启动第三方应用的URL
 @param delegate    LGADouyinOpenSDKApiDelegate对象，用来接收抖音短视频触发的消息
 @return 成功处理返回YES，否则返回NO
 */
+ (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options delegate:(id<LGTikTokShareDelegate>)delegate;

/**
 设置SDK日志代理，可供调试
 
 同时仅允许存在一个日志代理，每次调用将覆盖之前的delegate
 
 SDK会弱引用这个logDelegate
 
 @param logDelegate 日志代理
 */
+ (void)registerLogDelegate:(id<LGTikTokLogDelegate>)logDelegate;

/**
 清除SDK日志代理，停止调试
 
 会清除之前设置的日志代理
 */
+ (void)unregisterLogDelegate;

/**
 判断用户是否安装了抖音短视频
 
 @return 安装返回YES，否则返回NO
 */
+ (BOOL)isAppInstalled;

/**
 判断当前TOREPLACEPRODUCTNAME版本是否支持分享
 
 @return 支持返回YES，否则返回NO
 */
+ (BOOL)isAppSupportShare;

/**
 获取抖音短视频在iTunes上的下载地址
 
 @return 返回抖音短视频的安装地址
 */
+ (nonnull NSString *)getAppiTunesUrl;

//====================================================================================
//==================================深度转化===========================================
//====================================================================================

/**
 * 配置深度转化参数
 */
- (void)configTTTrack:(LGBDConfig *)config;


/*! @abstract UserUniqueID发生变化时设置
 @discussion 有值，则设置为ID值；登出 请调用 [BDAutoTrack clearUserUniqueID] 或者传 nil
 @discussion SDK会保存，因此只需要变化的时候设置。
 @param uniqueID 用户id，如无特殊需求，请勿传 空字符串 或者 全是空格的字符串
 */
+ (void)setCurrentUserUniqueID:(NSString *_Nullable)uniqueID;

+ (void)setCustomHeaderBlock:(LGBDAutoTrackCustomHeaderBlock)customHeaderBlock;

/*! @abstract 登出 logout
 @discussion 登出 logout
 */
+ (void)clearUserUniqueID;

+ (void)setABSDKVersions:(NSString *)versions;

+ (NSString *)getABSDKVersions;

/**
 * 自定义埋点上报
 * @param event 埋点事件
 * @param params 属性参数
 * 举例:[BDAutoTrack eventV3:@"video_play_clicks" params:@{@"video_title":@"LadyGaga"}];
 */
+ (void)lg_event:(NSString *)event params:(NSDictionary *)params;

/**
 * 如果需要使⽤用 A/B Test 请联系支持同学开通
 @param key ABTest的key
 @param defaultValue 默认值，如果没有配置，或者未开启ABTest则返回默认值
 @discussion 未开启ABTest或者ABTest配置了默认值，都是返回默认值，因此建议监听ABTestFinishBlock来判断是否开启了ABTest
 @result 返回ABTest的配置值
 */
+ (id)ABTestConfigValueForKey:(NSString * _Nonnull)key defaultValue:(id _Nonnull)defaultValue;



@end

NS_ASSUME_NONNULL_END
