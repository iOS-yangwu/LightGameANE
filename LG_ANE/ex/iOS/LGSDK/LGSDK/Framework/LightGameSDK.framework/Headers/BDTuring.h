//
//  BDTuring.h
//  BDTuring
//
//  Created by bob on 2019/8/23.
//

#import <Foundation/Foundation.h>
#import "BDTuringConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class UIView, BDTuringConfig, BDTuring;

/*! @abstract 验证结果Code
*/
typedef NS_ENUM(NSInteger, BDTuringVerifyStatus) {
    BDTuringVerifyStatusOK              = 0,    ///< 验证通过
    BDTuringVerifyStatusError           = 1,    ///< 验证失败
    BDTuringVerifyStatusClose           = 2,    ///< 验证中断，如关闭了验证窗口
    BDTuringVerifyStatusNetworkError    = 3,    ///< 网络原因，验证码无法获取
    BDTuringVerifyStatusCloseFromMask   = 4,    ///< 验证中断，用户点击蒙层关闭
    BDTuringVerifyStatusCloseFromAPI    = 6,    ///< 验证中断，接入方手动调用关闭
    BDTuringVerifySystemVersionLow      = 999,    ///< 系统版本低于 iOS 8
};

/*! @abstract 验证类型定义
*/
typedef NS_ENUM(NSInteger, BDTuringVerifyType) {
    BDTuringVerifyTypeSMS       = 1,      ///< 短信 目前不支持
    BDTuringVerifyTypePicture   = 2,      ///< 图片
};

/*! @abstract 验证结果回调
 @param status 验证结果
 @param token  短信验证码token
 @param mobile  短信验证码mobile手机号
 @discussion 图片验证码后面两个参数是nil；短信验证码，如果是手动触发关闭验证而非前端回调，参数可能是nil
*/
typedef void (^BDTuringVerifyCallback)(BDTuringVerifyStatus status,
                                       NSString *_Nullable token,
                                       NSString *_Nullable mobile);

/*! @abstract 验证码加载回调
*/
@protocol BDTuringDelegate <NSObject>

@optional;

/*! @abstract 验证码View已经展示出来
*/
- (void)turingDidShow:(BDTuring *)turing;

/*! @abstract 验证码View已经隐藏
*/
- (void)turingDidHide:(BDTuring *)turing;

/*! @abstract 验证码View已经销毁
*/
- (void)turingDidDismiss:(BDTuring *)turing;

/*! @abstract 验证码WebView 已经加载成功
*/
- (void)turingWebViewDidLoadSuccess:(BDTuring *)turing;

/*! @abstract 验证码WebView 加载失败
*/
- (void)verifyWebViewDidLoadFail:(BDTuring *)turing;

@end

/*! @abstract 验证码
@discussion 特别说明，验证码View是由一个UIView包裹一个WKWebview组成，验证码核心交互都在WKWebView层
 只有WKWebview加载成功，才能够进行验证交互
*/
@interface BDTuring : NSObject

/*! @abstract 当前验证码点击蒙层是否关闭，默认是YES
 @discussion 设置时机，如果WebView加载失败，尽量保持默认值
*/
@property (nonatomic, assign) BOOL closeVerifyViewWhenTouchMask;

/*! @abstract 当前是否在展示验证码
*/
@property (atomic, assign, readonly) BOOL isShowVerifyView;

/*! @abstract Delegate,用于接受回调
*/
@property (nonatomic, weak, nullable) id<BDTuringDelegate> delegate;

/*! @abstract 初始化方法，初始化一个BDTuring实例
@param config 初始化配置，AppID AppName Channel是必须的
@discussion 初始化接口可以重复调用，会返回新的实例，推荐返回之后，引用住这个实例，下次呼起验证码方便使用。
@result 一个BDTuring实例
*/
- (instancetype)initWithConfig:(BDTuringConfig *)config;

/*! @abstract 设置BOE 环境
@param useBOE 是否开启 BOE 环境
*/
- (void)setUseBOE:(BOOL)useBOE;

/*! @abstract 呼起图片验证码
 @param regionType CN SG或者VA，参考 <BDTuring/BDTuringConfig.h>头文件
 @param presentingView 验证码 展示到presentingView上
 @param challengeCode 验证码类型，challengeCode，对应业务的errorCode
 @param callback callback on main queue
*/
- (void)popPictureVerifyViewWithRegionType:(BDTuringRegionType)regionType
                            presentingView:(nullable UIView *)presentingView
                             challengeCode:(NSInteger)challengeCode
                                  callback:(BDTuringVerifyCallback)callback __attribute__((deprecated("presentingView参数废弃，默认为nil")));


/*! @abstract 呼起图片验证码
 @param regionType CN SG或者VA，参考 <BDTuring/BDTuringConfig.h>头文件
 @param challengeCode 验证码类型，challengeCode，对应业务的errorCode
 @param callback callback on main queue
*/
- (void)popPictureVerifyViewWithRegionType:(BDTuringRegionType)regionType
                             challengeCode:(NSInteger)challengeCode
                                  callback:(BDTuringVerifyCallback)callback;

/*! @abstract 呼起短信验证码 暂时不支持
 @param regionType CN SG或者VA，参考 <BDTuring/BDTuringConfig.h>头文件
 @param presentingView 验证码展示到presentingView上
 @param scene 验证场景，后端根据scene可以获取手机号等相关信息
 @param callback callback on main queue
*/
- (void)popSMSVerifyViewWithRegionType:(BDTuringRegionType)regionType
                        presentingView:(nullable UIView *)presentingView
                                 scene:(NSString *)scene
                              callback:(BDTuringVerifyCallback)callback __attribute__((deprecated("presentingView参数废弃，默认为nil")));


/*! @abstract 呼起短信验证码 暂时不支持
 @param regionType CN SG或者VA，参考 <BDTuring/BDTuringConfig.h>头文件
 @param scene 验证场景，后端根据scene可以获取手机号等相关信息
 @param callback callback on main queue
*/
- (void)popSMSVerifyViewWithRegionType:(BDTuringRegionType)regionType
                                 scene:(NSString *)scene
                              callback:(BDTuringVerifyCallback)callback;


/*! @abstract  关闭验证码
 @discussion 如果切后台需要关闭验证码，可以主动调用关闭验证码
*/
- (void)closeVerifyView;

/*! @abstract
 SDK版本号.
 */
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
