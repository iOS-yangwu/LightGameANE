//
//  LGFullScreenVideoManager.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGFullScreenVideoManager : NSObject

+ (LGFullScreenVideoManager *)manager;

- (void) loadAd:(NSString *)slotID;

- (BOOL) isAdValid;

- (BOOL) showAd;

- (BOOL) showAdWithRitSceneDescribe:(NSString *)sceneDescirbe;

@end

NS_ASSUME_NONNULL_END
