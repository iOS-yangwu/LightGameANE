//
//  LGNativeExpressFullScreenVideoManager.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/15.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGNativeExpressFullScreenVideoManager.h"
#import <LightGameSDK/BUNativeExpressFullscreenVideoAd.h>
#import "LGAdvertANEUtils.h"

@interface LGNativeExpressFullScreenVideoManager ()<BUNativeExpressFullscreenVideoAdDelegate>

@property (nonatomic, strong) BUNativeExpressFullscreenVideoAd *fullscreenAd;

@end

@implementation LGNativeExpressFullScreenVideoManager

+ (LGNativeExpressFullScreenVideoManager *)manager{
    
    static LGNativeExpressFullScreenVideoManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGNativeExpressFullScreenVideoManager alloc]init];
    });
    return manager;
}

- (void) loadAd:(NSString *)slotId{
    
    if (slotId) {
        self.fullscreenAd = [[BUNativeExpressFullscreenVideoAd alloc] initWithSlotID:slotId];
        self.fullscreenAd.delegate = self;
        [self.fullscreenAd loadAdData];
    }
    
}

- (BOOL) isAdValid{
    
    return [self.fullscreenAd isAdValid];
}

- (BOOL) showAd{
    
    return [self.fullscreenAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

- (BOOL) showAdWithRitSceneDescribe:(NSString *)sceneDescirbe{
    
    return [self.fullscreenAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController ritSceneDescribe:sceneDescirbe];
}


#pragma mark - delegate
- (void)nativeExpressFullscreenVideoAdDidLoad:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVDidLoad,NEFSVDidLoadCode,@"",@"");
}

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)nativeExpressFullscreenVideoAd:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NEFSVFailToLoad,NEFSVFailToLoadCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);
}

/**
 This method is called when rendering a nativeExpressAdView successed.
 It will happen when ad is show.
 */
-(void)nativeExpressFullscreenVideoAdViewRenderSuccess:(BUNativeExpressFullscreenVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NEFSVRenderSuccess,NEFSVRenderSuccessCode,@"",@"");
}

/**
 This method is called when a nativeExpressAdView failed to render.
 @param error : the reason of error
 */
- (void)nativeExpressFullscreenVideoAdViewRenderFail:(BUNativeExpressFullscreenVideoAd *)rewardedVideoAd error:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NEFSVRenderFail,NEFSVRenderFailCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);
}

/**
 This method is called when video cached successfully.
 */
-(void)nativeExpressFullscreenVideoAdDidDownLoadVideo:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVDownLoad,NEFSVDownLoadCode,@"",@"");
}

/**
 This method is called when video ad slot will be showing.
 */
- (void)nativeExpressFullscreenVideoAdWillVisible:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVWillVisible,NEFSVWillVisibleCode,@"",@"");
}

/**
 This method is called when video ad slot has been shown.
 */
- (void)nativeExpressFullscreenVideoAdDidVisible:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVDidVisible,NEFSVDidVisibleCode,@"",@"");
}

/**
 This method is called when video ad is clicked.
 */
- (void)nativeExpressFullscreenVideoAdDidClick:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVDidClick,NEFSVDidClickCode,@"",@"");
}

/**
 This method is called when the user clicked skip button.
 */
- (void)nativeExpressFullscreenVideoAdDidClickSkip:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVClickSkip,NEFSVClickSkipCode,@"",@"");
}

/**
 This method is called when video ad is about to close.
 */
- (void)nativeExpressFullscreenVideoAdWillClose:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVWillClose,NEFSVWillCloseCode,@"",@"");
}

/**
 This method is called when video ad is closed.
 */
- (void)nativeExpressFullscreenVideoAdDidClose:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(NEFSVDidClose,NEFSVDidCloseCode,@"",@"");
}

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)nativeExpressFullscreenVideoAdDidPlayFinish:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NEFSVPlayFinish,NEFSVPlayFinishCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);
}

/**
This method is used to get the type of nativeExpressFullScreenVideo ad
 */
- (void)nativeExpressFullscreenVideoAdCallback:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd withType:(BUNativeExpressFullScreenAdType) nativeExpressVideoAdType{
    
    LGAdvertSendANEMessage(NEFSVCallback,NEFSVCallbackCode,@"",@"");
}

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
-(void)nativeExpressFullscreenVideoAdDidCloseOtherController:(BUNativeExpressFullscreenVideoAd *)fullscreenVideoAd interactionType:(BUInteractionType)interactionType{
    
    LGAdvertSendANEMessage(NSFSVCloseOther,NSFSVCloseOtherCode,@"",@"");
    
}
@end
