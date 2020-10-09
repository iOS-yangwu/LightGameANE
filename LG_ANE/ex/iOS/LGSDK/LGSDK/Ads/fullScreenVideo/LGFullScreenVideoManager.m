//
//  LGFullScreenVideoManager.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LGFullScreenVideoManager.h"
#import <LightGameSDK/LGFullScreenVideoAd.h>
#import "LGAdvertANEUtils.h"

@interface LGFullScreenVideoManager ()<LGFullScreenVideoAdDelegate>

@property (nonatomic, strong) LGFullScreenVideoAd *fullScreenVideoAd;

@end


@implementation LGFullScreenVideoManager

+ (LGFullScreenVideoManager *)manager{
    static LGFullScreenVideoManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGFullScreenVideoManager alloc]init];
    });
    return manager;
}

- (void) loadAd:(NSString *)slotID{
    
    if (slotID) {
        
        self.fullScreenVideoAd = [[LGFullScreenVideoAd alloc] initWithSlotID:slotID];
        self.fullScreenVideoAd.delegate = self;
        [self.fullScreenVideoAd loadAdData];
    }
}

- (BOOL) isAdValid{
    
    return [self.fullScreenVideoAd isAdValid];
}

- (BOOL) showAd{
    
    return [self.fullScreenVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

- (BOOL) showAdWithRitSceneDescribe:(NSString *)sceneDescirbe{
    
    return [self.fullScreenVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController ritSceneDescribe:sceneDescirbe];;
}

#pragma mark - delegate
/**
 This method is called when video ad material loaded successfully.
 */
- (void)fullscreenVideoMaterialMetaAdDidLoad:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVMateDidLoad,FSVMateDidLoadCode,@"",@"");
}

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)fullscreenVideoAd:(LGFullScreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *)error{
    
    LGAdvertSendANEMessage(FSVMateFailToLoad,FSVMateFailToLoadCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);

}

/**
 This method is called when video cached successfully.
 */
- (void)fullscreenVideoAdVideoDataDidLoad:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVDataDidLoad,FSVDataDidLoadCode,@"",@"");

}

/**
 This method is called when video ad slot will be showing.
 */
- (void)fullscreenVideoAdWillVisible:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVWillVisible,FSVWillVisibleCode,@"",@"");

}

/**
 This method is called when video ad slot has been shown.
 */
- (void)fullscreenVideoAdDidVisible:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVDidVisible,FSVDidVisibleCode,@"",@"");

}

/**
 This method is called when video ad is clicked.
 */
- (void)fullscreenVideoAdDidClick:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVDidClick,FSVDidClickCode,@"",@"");

}

/**
 This method is called when video ad is about to close.
 */
- (void)fullscreenVideoAdWillClose:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVWillClose,FSVWillCloseCode,@"",@"");

}

/**
 This method is called when video ad is closed.
 */
- (void)fullscreenVideoAdDidClose:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVDidClose,FSVDidCloseCode,@"",@"");

}

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)fullscreenVideoAdDidPlayFinish:(LGFullScreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *)error{
    
    LGAdvertSendANEMessage(FSVDidFinish,FSVDidFinishCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);
}

/**
 This method is called when the user clicked skip button.
 */
- (void)fullscreenVideoAdDidClickSkip:(LGFullScreenVideoAd *)fullscreenVideoAd{
    
    LGAdvertSendANEMessage(FSVDidClickSkip,FSVDidClickSkipCode,@"",@"");

}

@end
