//
//  LGRewardVideoManager.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGRewardVideoManager : NSObject

+ (LGRewardVideoManager *)manager;

- (void) loadAd:(NSString *)slotID userId:(NSString *)userId rewardName:(NSString *)rewardName rewardAmount:(NSInteger)rewardAmount extra:(NSString *)extra;

- (BOOL) isAdValid;

- (BOOL) showAd;

- (BOOL) showAdFromRitScene:(NSInteger)ritSceneType ritSceneDescribe:(NSString *)sceneDescirbe;

@end

NS_ASSUME_NONNULL_END
