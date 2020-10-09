//
//  LGRewardVideoManager.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGRewardVideoManager.h"
#import <LightGameSDK/LGRewardedVideoAd.h>
#import <UIKit/UIKit.h>
#import "LGAdvertANEUtils.h"

@interface LGRewardVideoManager ()<LGRewardedVideoAdDelegate>

@property (nonatomic, strong) LGRewardedVideoAd *rewardedVideoAd;

@end

@implementation LGRewardVideoManager

+ (LGRewardVideoManager *)manager{
    static LGRewardVideoManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGRewardVideoManager alloc]init];
    });
    return manager;
    
}

- (void)loadAd:(NSString *)slotID userId:(NSString *)userId rewardName:(NSString *)rewardName rewardAmount:(NSInteger)rewardAmount extra:(NSString *)extra{
    
    LGRewardedVideoModel *rewardModel = [[LGRewardedVideoModel alloc] init];
    rewardModel.userId = userId;
    rewardModel.rewardName = rewardName;
    rewardModel.rewardAmount = rewardAmount;
    rewardModel.extra = extra;
    
    if (slotID) {
        self.rewardedVideoAd = [[LGRewardedVideoAd alloc] initWithSlotID:slotID rewardedVideoModel:rewardModel];
        self.rewardedVideoAd.delegate = self;
        [self.rewardedVideoAd loadAdData];
    }
    
}

- (BOOL)isAdValid{
    
    return [self.rewardedVideoAd isAdValid];
}

- (BOOL) showAd{
    
    return [self.rewardedVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

- (BOOL) showAdFromRitScene:(NSInteger)ritSceneType ritSceneDescribe:(NSString *)sceneDescirbe{
    
    return [self.rewardedVideoAd showAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController ritScene:ritSceneType ritSceneDescribe:sceneDescirbe];
    
}

#pragma mark - delegate
/**
 This method is called when video ad material loaded successfully.
 */
- (void)rewardedVideoAdDidLoad:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVDidLoad,RVDidLoadCode,@"",@"");
}

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)rewardedVideoAd:(LGRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    
    LGAdvertSendANEMessage(RVFailToLoad,RVFailToLoadCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);
}

/**
 This method is called when cached successfully.
 */
- (void)rewardedVideoAdVideoDidLoad:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVVideoDidLoad,RVVideoDidLoadCode,@"",@"");
}
/**
 This method is called when video ad slot will be showing.
 */
- (void)rewardedVideoAdWillVisible:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVWillVisible,RVWillVisibleCode,@"",@"");

}

/**
 This method is called when video ad slot has been shown.
 */
- (void)rewardedVideoAdDidVisible:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVDidVisible,RVDidVisibleCode,@"",@"");

}

/**
 This method is called when video ad is about to close.
 */
- (void)rewardedVideoAdWillClose:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVWillClose,RVWillCloseCode,@"",@"");

}

/**
 This method is called when video ad is closed.
 */
- (void)rewardedVideoAdDidClose:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVDidClose,RVDidCloseCode,@"",@"");

}

/**
 This method is called when video ad is clicked.
 */
- (void)rewardedVideoAdDidClick:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVDidClick,RVDidClickCode,@"",@"");

}

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)rewardedVideoAdDidPlayFinish:(LGRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    
    LGAdvertSendANEMessage(RVDidPlayFinish,RVDidPlayFinishCode,@"errorMsg",[NSString stringWithFormat:@"%@",error]);

}

/**
 Server verification which is requested asynchronously is succeeded.
 @param verify :return YES when return value is 2000.
 */
- (void)rewardedVideoAdServerRewardDidSucceed:(LGRewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify{
    
    LGAdvertSendANEMessage(RVServerRewardDidSucceed,RVServerRewardDidSucceedCode,@"verify",[NSString stringWithFormat:@"%d",verify]);

}

/**
 Server verification which is requested asynchronously is failed.
 Return value is not 2000.
 */
- (void)rewardedVideoAdServerRewardDidFail:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVServerRewardDidFail,RVServerRewardDidFailCode,@"",@"");
}
/**
 This method is called when the user clicked skip button.
 */
- (void)rewardedVideoAdDidClickSkip:(LGRewardedVideoAd *)rewardedVideoAd{
    
    LGAdvertSendANEMessage(RVDidClickSkip,RVDidClickSkipCode,@"",@"");
}

@end
