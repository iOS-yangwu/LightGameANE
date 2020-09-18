//
//  LGNativeExpressFullScreenVideoManager.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/15.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGNativeExpressFullScreenVideoManager : NSObject

+ (LGNativeExpressFullScreenVideoManager *) manager;

- (void) loadAd:(NSString *)slotId;

- (BOOL) isAdValid;

- (BOOL) showAd;

- (BOOL) showAdWithRitSceneDescribe:(NSString *)sceneDescirbe;


@end

NS_ASSUME_NONNULL_END
