//
//  LGSplashAd.m
//  LGSDK
//
//  Created by 洋吴 on 2020/10/12.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGSplashAd.h"
#import "LGAdvertANEUtils.h"
#import <LightGameSDK/LightGameSDK.h>

@interface LGSplashAd ()<BUSplashAdDelegate>

@property(nonatomic, strong)BUSplashAdView *splashAdView;

@end

@implementation LGSplashAd

+ (LGSplashAd *) manager{
    
    static LGSplashAd *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGSplashAd alloc]init];
    });
    return manager;
}

- (void) loadAd:(NSString *)slotId tolerateTimeout:(int)tolerateTimeout{
    
    _splashAdView = [[BUSplashAdView alloc] initWithSlotID:slotId frame:[UIScreen mainScreen].bounds];
        _splashAdView.tolerateTimeout = tolerateTimeout;
    _splashAdView.delegate = self;
    [_splashAdView loadAdData];
    
    
}

- (BOOL) isAdValid{
    
    return self.splashAdView.isAdValid;
}

- (void) showAd{
    
    [[UIApplication sharedApplication].keyWindow.rootViewController.view addSubview:self.splashAdView];
}

/**
 This method is called when splash ad material loaded successfully.
 */
- (void)splashAdDidLoad:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashDidLoad,SplashDidLoadCode,@"",@"");
    
}

/**
 This method is called when splash ad material failed to load.
 @param error : the reason of error
 */
- (void)splashAd:(BUSplashAdView *)splashAd didFailWithError:(NSError * _Nullable)error{
    
    [self.splashAdView removeFromSuperview];
    LGAdvertSendANEMessage(SplashFailToLoad, SplashFailToLoadCode, @"errorMsg", [NSString stringWithFormat:@"%@",error]);
    
}

/**
 This method is called when splash ad slot will be showing.
 */
- (void)splashAdWillVisible:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashWillVisible, SplashWillVisibleCode, @"", @"");
}

/**
 This method is called when splash ad is clicked.
 */
- (void)splashAdDidClick:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashDidClick, SplashDidClickCode, @"", @"");

}

/**
 This method is called when splash ad is closed.
 */
- (void)splashAdDidClose:(BUSplashAdView *)splashAd{
    
    [self.splashAdView removeFromSuperview];
    LGAdvertSendANEMessage(SplashDidClose, SplashDidCloseCode, @"", @"");
}

/**
 This method is called when splash ad is about to close.
 */
- (void)splashAdWillClose:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashWillClose, SplashWillCloseCode, @"", @"");
}

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)splashAdDidCloseOtherController:(BUSplashAdView *)splashAd interactionType:(BUInteractionType)interactionType{
    
    LGAdvertSendANEMessage(SplashDidCloseOtherController, SplashDidCloseOtherControllerCode, @"", @"");
}

/**
 This method is called when spalashAd skip button  is clicked.
 */
- (void)splashAdDidClickSkip:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashDidClickSkip, SplashDidClickSkipCode, @"", @"");
}

/**
 This method is called when spalashAd countdown equals to zero
 */
- (void)splashAdCountdownToZero:(BUSplashAdView *)splashAd{
    
    LGAdvertSendANEMessage(SplashCountdownToZero, SplashCountdownToZeroCode, @"", @"");
}

@end
