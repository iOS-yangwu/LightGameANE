//
//  LGSplashAd.h
//  LGSDK
//
//  Created by 洋吴 on 2020/10/12.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGSplashAd : NSObject

+ (LGSplashAd *) manager;

- (void) loadAd:(NSString *)slotId tolerateTimeout:(int)tolerateTimeout;

- (BOOL) isAdValid;

- (void) showAd;

@end

NS_ASSUME_NONNULL_END
