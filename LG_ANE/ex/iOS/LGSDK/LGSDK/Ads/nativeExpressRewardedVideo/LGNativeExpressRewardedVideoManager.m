//
//  LGNativeExpressRewardedVideoManager.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGNativeExpressRewardedVideoManager.h"
#import <LightGameSDK/BUNativeExpressRewardedVideoAd.h>
#import <LightGameSDK/BURewardedVideoModel.h>
#import "LGAdvertANEUtils.h"

@interface LGNativeExpressRewardedVideoManager ()<BUNativeExpressRewardedVideoAdDelegate>

@property (nonatomic, strong) BUNativeExpressRewardedVideoAd *rewardedVideoAd;

@end

@implementation LGNativeExpressRewardedVideoManager

+ (LGNativeExpressRewardedVideoManager *)manager{
    static LGNativeExpressRewardedVideoManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGNativeExpressRewardedVideoManager alloc]init];
    });
    return manager;
    
}


- (void) loadAd:(NSString *)slotID userId:(NSString *)userId rewardName:(NSString *)rewardName rewardAmount:(NSInteger)rewardAmount extra:(NSString *)extra{
    
    BURewardedVideoModel *model = [[BURewardedVideoModel alloc] init];
    model.userId = userId;
    model.rewardName = rewardName;
    model.rewardAmount = rewardAmount;
    model.extra = extra;
    
    if (slotID) {
        self.rewardedVideoAd = [[BUNativeExpressRewardedVideoAd alloc] initWithSlotID:slotID rewardedVideoModel:model];
        self.rewardedVideoAd.delegate = self;
        [self.rewardedVideoAd loadAdData];
    }
    
}

- (BOOL) isAdValid{
    
    return [self.rewardedVideoAd isAdValid];
}

- (BOOL) showAd{
    
    return [self.rewardedVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

- (BOOL) showAdFromRitScene:(NSInteger)ritSceneType ritSceneDescribe:(NSString *)sceneDescirbe{
    
    return [self.rewardedVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController ritScene:ritSceneType ritSceneDescribe:sceneDescirbe];;
    
}

#pragma mark - delegate
- (void)nativeExpressRewardedVideoAdDidLoad:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidLoad,NERVDidLoadCode,@"",@"");
}

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)nativeExpressRewardedVideoAd:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NERVFailToLoad,NERVFailToLoadCode,@"",@"");
    
}
/**
  this methods is to tell delegate the type of native express rewarded video Ad
 */
- (void)nativeExpressRewardedVideoAdCallback:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd withType:(BUNativeExpressRewardedVideoAdType)nativeExpressVideoType{
    
    LGAdvertSendANEMessage(NERVCallback,NERVCallbackCode,@"",@"");
    
}

/**
 This method is called when cached successfully.
 */
- (void)nativeExpressRewardedVideoAdDidDownLoadVideo:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidDownLoadVideo,NERVDidDownLoadVideoCode,@"",@"");
    
}

/**
 This method is called when rendering a nativeExpressAdView successed.
 It will happen when ad is show.
 */
- (void)nativeExpressRewardedVideoAdViewRenderSuccess:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVViewRenderSuccess,NERVViewRenderSuccessCode,@"",@"");
    
}

/**
 This method is called when a nativeExpressAdView failed to render.
 @param error : the reason of error
 */
- (void)nativeExpressRewardedVideoAdViewRenderFail:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd error:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NERVViewRenderFail,NERVViewRenderFailCode,@"",@"");
    
}

/**
 This method is called when video ad slot will be showing.
 */
- (void)nativeExpressRewardedVideoAdWillVisible:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVWillVisible,NERVWillVisibleCode,@"",@"");
    
}

/**
 This method is called when video ad slot has been shown.
 */
- (void)nativeExpressRewardedVideoAdDidVisible:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidVisible,NERVDidVisibleCode,@"",@"");
    
}

/**
 This method is called when video ad is about to close.
 */
- (void)nativeExpressRewardedVideoAdWillClose:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVWillClose,NERVWillCloseCode,@"",@"");
    
}

/**
 This method is called when video ad is closed.
 */
- (void)nativeExpressRewardedVideoAdDidClose:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidClose,NERVDidCloseCode,@"",@"");
    
}

/**
 This method is called when video ad is clicked.
 */
- (void)nativeExpressRewardedVideoAdDidClick:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidClick,NERVDidClickCode,@"",@"");
    
}

/**
 This method is called when the user clicked skip button.
 */
- (void)nativeExpressRewardedVideoAdDidClickSkip:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVDidClickSkip,NERVDidClickSkipCode,@"",@"");
    
}

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)nativeExpressRewardedVideoAdDidPlayFinish:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error{
    
    LGAdvertSendANEMessage(NERVDidPlayFinish,NERVDidPlayFinishCode,@"",@"");
    
}

/**
 Server verification which is requested asynchronously is succeeded. now include two v erify methods:
      1. C2C need  server verify  2. S2S don't need server verify
 @param verify :return YES when return value is 2000.
 */
- (void)nativeExpressRewardedVideoAdServerRewardDidSucceed:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify{
    
    LGAdvertSendANEMessage(NERVServerRewardDidSucceed,NERVServerRewardDidSucceedCode,@"verify",[NSString stringWithFormat:@"%d",verify]);
    
}

/**
 Server verification which is requested asynchronously is failed.
 Return value is not 2000.
 */
-(void)nativeExpressRewardedVideoAdServerRewardDidFail:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(NERVServerRewardDidFail,NERVServerRewardDidFailCode,@"",@"");
    
}

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
-(void)nativeExpressRewardedVideoAdDidCloseOtherController:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd interactionType:(BUInteractionType)interactionType{
    
    LGAdvertSendANEMessage(NERVDidCloseOtherController,NERVDidCloseOtherControllerCode,@"",@"");
    
}

@end
