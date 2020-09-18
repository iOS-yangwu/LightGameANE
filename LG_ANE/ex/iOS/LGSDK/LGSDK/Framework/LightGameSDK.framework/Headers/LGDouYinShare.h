//
//  LGDouYinShare.h
//  LightGameSDK
//
//  Created by peiziming on 2019/10/15.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LightGameManager.h"

@class LGMVVideoPreviewVC;

typedef void(^LGDouyinShareWillPreview)(void);
typedef void(^LGDouyinShareEndPreview)(void);

#define kLGDouyinShareErrorDomain @"com.LightGame.DouyinShare.Upload"
#define kLGDouYinShareErrorUserCancle -3001
#define kLGDouYinShareErrorNoSource   -3002
#define kLGDouYinShareErrorNet        -3003
#define kLGDouYinShareErrorNoShareCount   30000

@interface LGDouYinShare : NSObject

@property(nonatomic, assign, readonly)BOOL isOnlineVideo;

/* 快速分享预览前后，第三方可在这两个回调做对应自定义处理
 eg:预览出现时关闭游戏背景音以更好地观看预览视频;
    预览结束后恢复游戏背景音
 */
@property(nonatomic, copy)LGDouyinShareWillPreview _Nullable willPreview; // 即将预览视频
@property(nonatomic, copy)LGDouyinShareEndPreview _Nullable endPreview; // 预览视频结束

+ (LGDouYinShare *_Nonnull)sharedInstance;


/**
 优质视频一键分享
 通过该接口一键分享服务端配置的优质视频，第三方可以结合奖励机制应用

 @param complete 返回结果：isStartShare=YES,开始分享视频；isStartShare=NO，可根据error查看错误
 */
- (void)douyinShareForHighQualityVideo:(void(^_Nullable)(BOOL isStartShare, NSError * _Nullable error))complete;


/**
 抖音视频一键分享

 @param info 附带小程序信息
 @param videoPath 分享视频路径
 @param complete 分享回调
 @param state 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由抖音短视频App回传
 */
- (void)quickVideoShareWithAppletInfo:(LightGameDouYinAppletConfig *_Nullable)info state:(NSString *_Nullable)state videoPath:(NSString *_Nullable)videoPath complete:(void(^_Nullable)(NSString * _Nullable videoPath, NSError * _Nullable error))complete;

- (void)mvVideoShareWithAppletInfo:(LightGameDouYinAppletConfig *_Nullable)info state:(NSString *_Nullable)state complete:(void(^_Nullable)(NSString * _Nullable videoPath, BOOL isStartShare, NSError * _Nullable error))complete key:(NSString *_Nullable)key vc:(LGMVVideoPreviewVC *_Nullable)preVC;

@end
