//
//  LGVideoAdView.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LGMaterialMeta.h"
#import "LGAdSDKDefines.h"


NS_ASSUME_NONNULL_BEGIN


/**
 Control TikTok Audience Network video player.
 */
@protocol BUAdVideoEngine <NSObject>

/**
 Get the already played time.
 */
- (CGFloat)currentPlayTime;
@end


@protocol LGVideoAdViewDelegate;

@interface LGVideoAdView : UIView

@property (nonatomic, weak, nullable) id<LGVideoAdViewDelegate> delegate;

/// required. Root view controller for handling ad actions.
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Whether to allow pausing the video by clicking, default NO. Only for draw video(vertical video ads).
 **/
@property (nonatomic, assign) BOOL drawVideoClickEnable;

/**
 material information.
 */
@property (nonatomic, strong, readwrite, nullable) LGMaterialMeta *materialMeta;

- (instancetype)initWithMaterial:(LGMaterialMeta *)materialMeta;

/**
 Resume to the corresponding time.
 */
- (void)playerSeekToTime:(CGFloat)time;

/**
 Support configuration for pause button.
 @param playImg : the image of the button
 @param playSize : the size of the button. Set as cgsizezero to use default icon size.
 */
- (void)playerPlayIncon:(UIImage *)playImg playInconSize:(CGSize)playSize;

@end


@protocol LGVideoAdViewDelegate <NSObject>

@optional

/**
 This method is called when videoadview failed to play.
 @param error : the reason of error
 */
- (void)videoAdView:(LGVideoAdView *)videoAdView didLoadFailWithError:(NSError *_Nullable)error;

/**
 This method is called when videoadview playback status changed.
 @param playerState : player state after changed
 */
- (void)videoAdView:(LGVideoAdView *)videoAdView stateDidChanged:(LGPlayerPlayState)playerState;

/**
 This method is called when videoadview end of play.
 */
- (void)playerDidPlayFinish:(LGVideoAdView *)videoAdView;

@end

NS_ASSUME_NONNULL_END
