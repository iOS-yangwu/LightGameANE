//
//  LightGameRecorder.h
//  LightGameSDK
//
//  Created by peiziming on 2019/4/23.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LightGameDouYinAppletConfig;

@interface LightGameRecorder : NSObject

@property (nonatomic, assign, readonly) BOOL isRecording;
/**
    录制屏幕后是否一键分享抖音，如果视频超过1分钟或者视频体积大于300M，则会自动进入普通流程的分享， 默认是NO
*/
@property (nonatomic, assign) BOOL isNeedQuickShare;

/**
 * 录制屏幕保存的视频路径
 */
@property (nonatomic, copy, readonly) NSString * _Nonnull resultPath;

/**
 * 停止录制后是否需要直接对视频进行编辑 接入方可通过 ‘LightGameEditor’ 自行对视频进行编 默认是NO
 */
@property (nonatomic, assign) BOOL isNeedEditor;

/**
 * 录制的视频希望的最大帧率 默认 15 最大 24
 */
@property (nonatomic, assign) int32_t frameIntervalKey;

/**
 * 录制的视频的平均码率 默认是 设备高度 * 设备宽度 * 6(一个像素的bit数) * 当前设备缩放比例 且为最大值
 */
@property (nonatomic, assign) double averageBit;

/**
 * 编辑视频的进度回调 回调会在主线程执行
 */
@property (nonatomic, copy) void(^ _Nullable editVideoProgress)(NSInteger progress);

+ (LightGameRecorder *_Nonnull)shareInstance;


/**
 分享到抖音 使用SDK录屏功能的接入方，使用此接口可以直接将视频分享到抖音app，会跳转到抖音APP
 @param state 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由抖音短视频App回传
 @param info 游戏小程序相关信息 传空则默认不分享小程序
 */
- (void)recordVideoShareToDouYinWithState:(NSString *_Nonnull)state appletInfo:(LightGameDouYinAppletConfig * _Nullable )info;

/**
 快速分享视频到抖音，首次分享会拉起抖音授权；要求视频长度不能长于1min;该接口不会跳转到抖音APP
 @param state 第三方应用程序用来标识请求的唯一性，最后跳转回第三方程序时由抖音短视频App回传
 @param info 游戏小程序相关信息 传空则默认不分享小程序
 @param complete 分享结果，YES表示开始分享视频
*/
- (void)quickVideoShareToDouYinWithState:(NSString *_Nullable)state appletInfo:(LightGameDouYinAppletConfig * _Nullable)info complete:(void(^_Nullable)(BOOL isStartShare, NSError * _Nullable err))complete;

/**
 *
 * 是否正暂停中
 **/
- (BOOL)isPausing;

/**
 *
 * 开始录制屏幕
 * 此方法必须和- (void)stopRecording成对出现,且必须在主线程启动
 * 由于stopRecording有相册存储的操作，为保证用户体验，可先提示用户相册权限。
 * 录制功能只支持iOS11及以上版本，为保证用户体验，iOS11以下版本接入方录制前可自行增加弹窗提示。
 * 录制过程中切到后台，录制屏幕自动停止，并且不会保存之前已经录制的视频。
 **/
- (void)startRecording;

/**
 *
 * 暂停录制 此方法并没有真正暂停录制，只是丢弃了录制的媒体数据
 **/
- (void)pauseRecording;

/**
 *
 * 继续录制
 **/
- (void)continueRecording;

/**
 *
 * 停止录制
 * 此方法必须和- (void)startRecording成对出现，且必须在主线程停止
 * complete 录屏是否成功，录屏成功后才能够进行分享
 **/
- (void)stopRecording:(void(^_Nonnull)(BOOL success))complete;

/**
 *
 * 停止录制(包括中间异常)，建议设置 当视频时长超过3分钟，SDK会自动停止录制，并把视频保存;一些录屏异常导致的失败也会通过它返回
 * complete 停止录制后的回调
 **/
- (void)setStopRecordingByLightGameBlock:(void(^_Nonnull)(BOOL success))complete;


@end
