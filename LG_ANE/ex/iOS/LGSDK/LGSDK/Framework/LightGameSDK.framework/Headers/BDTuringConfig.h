//
//  BDTuringConfig.h
//  BDTuring
//
//  Created by bob on 2019/8/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! @abstract 验证码地区属性
@discussion  验证码地区属性请勿擅自选择，需要明确知道属于哪个地区
*/
typedef NS_ENUM(NSInteger, BDTuringRegionType){
    BDTuringRegionTypeCN = 1,  /// Domestic
    BDTuringRegionTypeSG,      /// Singapore
    BDTuringRegionTypeVA,      /// EastAmerica
};

/*! @abstract BDTuringConfigDelegate 回调，用于获取需要信息，相关信息可以从logSDK获取
*/
@protocol BDTuringConfigDelegate <NSObject>

- (NSString *)deviceID;
- (NSString *)sessionID;/// 注意，这里的SessionID是获取用户相关的信息，并非BDTracker生成的随机SessionID字符串
- (NSString *)installID;
- (nullable NSString *)userID;

@end

/*!
验证码初始化配置
*/
@interface BDTuringConfig : NSObject

/*! @abstract AppID，非空，必须设置 */
@property (nonatomic, copy) NSString *appID;

/*! @abstract channel要求非空，默认@"App Store"， Release版本只有 @"App Store"， debug版本可以任意设置. */
@property (nonatomic, copy) NSString *channel;

/*! @abstract 申请appID时候填写的英文名称，非空 */
@property (nonatomic, copy) NSString *appName;

/*! @abstract appKey，非空，当前版本没有使用，后续会要求 */
@property (nonatomic, copy) NSString *appKey;

/*! @abstract 验证码地区属性
@discussion  初始化时一定要传正确的值
*/
@property (nonatomic, assign) BDTuringRegionType regionType;

/*! @abstract 验证码语言，支持中文、英文等，比如
 @discussion 中文 zh-Hant zh-Hans
 @discussion 英文 en
 */
@property (nonatomic, copy, nullable) NSString *language;

/*! @abstract Delegate 必须设置
*/
@property (nonatomic, weak)  id<BDTuringConfigDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
