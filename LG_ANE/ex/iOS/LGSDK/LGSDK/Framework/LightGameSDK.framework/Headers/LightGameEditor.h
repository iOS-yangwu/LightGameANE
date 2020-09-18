//
//  LightGameEditor.h
//  LightGameSDK
//
//  Created by peiziming on 2019/6/10.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LightGameVideoApplyProtocol <NSObject>

@optional
- (void)videoMergeProgress:(NSInteger)progress;

@end

@interface LightGameEditor : NSObject {
    
}

@property (nonatomic, assign, readwrite) BOOL isActiveCall;

/**
 * 视频处理回调
 */
@property (nonatomic, weak) id <LightGameVideoApplyProtocol> delegate;

/**
 * @param path 视频存储路径 按照SDK提供的默认模版编辑视频
 * @param isSaveToAlbum 是否保存到相册，默认为NO
 * @param complete 视频编辑完成后的回调，返回参数是合成后视频所在的路径;当设置isSaveToAlbum=YES时返回的是在相册的标识
 */
- (void)editVideo:(NSString *)path isSaveToAlbum:(BOOL)isSaveToAlbum complete:(void(^)(NSString *result))complete;

@end
