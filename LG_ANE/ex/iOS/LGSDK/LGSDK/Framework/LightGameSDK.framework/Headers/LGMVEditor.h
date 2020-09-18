//
//  LGMVEditor.h
//  LightGameSDK
//
//  Created by peiziming on 2020/4/14.
//  Copyright © 2020 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LightGameManager.h"

/**
 资源类型
 
 - LGMMMVResourcesType_img: 图片
 - LGMMMVResourcesType_gif: gif
 - LGMMMVResourcesType_video: 视频
 - LGMMMVResourcesType_mp3: 音频
 - LGMMMVResourcesType_text: 文本
 */
typedef NS_ENUM(NSInteger, LGMMMVResourcesType) {
//    LGMMMVResourcesType_none,
//    LGMMMVResourcesType_img,
//    LGMMMVResourcesType_gif,
    LGMMMVResourcesType_video = 3,
//    LGMMMVResourcesType_mp3,
//    LGMMMVResourcesType_text,
//    LGMMMVResourcesType_bgimg
};

/*  预览结果回调
    @param result 预览结果
    @param error  预览失败的相关错误,相关自定义错误码如下:
    -4001 正在进行另一个视频的合成
    -4002 网络错误
    -4003 当前机型不支持MV功能
    -4004 不存在对应的MV资源包
 **/
typedef void(^LGMMMVModelBlock)(BOOL result, NSError *error);

/* 分享结果回调
   @param isStartShare 是否开始分享
   @param error  分享失败的相关错误
   -3001  用户在预览页面取消分享(即关闭预览页面, isStartShare为YES时m，预览页面也会关闭)
**/
typedef void(^LGMVVideoShare)(BOOL isStartShare, NSError *error);

/* 预览页面即将展示
   @param isStartShare 是否开始分享
   @param error  分享失败的相关错误
**/
typedef void(^LGMVPreviewShow)(void);

@interface LGMMMVResource : NSObject
/**
 元素类型
*/
@property (nonatomic, assign) LGMMMVResourcesType type;

/**
 模板带入资源地址
*/
@property (nonatomic, copy) NSString *resourceContent;

@end

@interface LGMVEditor : NSObject

@property (nonatomic, assign) BOOL isTraning;

+ (LGMVEditor *)sharedInstance;

- (void)setMVVideResources:(NSArray<LGMMMVResource *> *)resources appletInfo:(LightGameDouYinAppletConfig *)appletInfo state:(NSString *)state completion:(LGMMMVModelBlock)resultCheckCallback previewShowCallBack:(LGMVPreviewShow)previewWillShow videoShare:(LGMVVideoShare)onVideoShare;


@end
