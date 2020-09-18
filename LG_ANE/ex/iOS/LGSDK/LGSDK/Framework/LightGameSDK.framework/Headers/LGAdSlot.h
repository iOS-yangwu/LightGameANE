//
//  LGAdSlot.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGAdSize.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, LGAdSlotAdType) {
    LGAdSlotAdTypeUnknown       = 0,
    LGAdSlotAdTypeBanner        = 1,       // banner ads
    LGAdSlotAdTypeInterstitial  = 2,       // interstitial ads
    LGAdSlotAdTypeSplash        = 3,       // splash ads
    LGAdSlotAdTypeSplash_Cache  = 4,       // cache splash ads
    LGAdSlotAdTypeFeed          = 5,       // feed ads
    LGAdSlotAdTypePaster        = 6,       // paster ads
    LGAdSlotAdTypeRewardVideo   = 7,       // rewarded video ads
    LGAdSlotAdTypeFullscreenVideo = 8,     // full-screen video ads
    LGAdSlotAdTypeDrawVideo     = 9,       // vertical (immersive) video ads
};

typedef NS_ENUM(NSInteger, LGAdSlotPosition) {
    LGAdSlotPositionTop = 1,
    LGAdSlotPositionBottom = 2,
    LGAdSlotPositionFeed = 3,
    LGAdSlotPositionMiddle = 4, // for interstitial ad only
    LGAdSlotPositionFullscreen = 5,
};


@interface LGAdSlot : NSObject

/// required. The unique identifier of a native ad.
@property (nonatomic, copy) NSString *ID;

/// required. Ad type.
@property (nonatomic, assign) LGAdSlotAdType AdType;

/// required. Ad display location.
@property (nonatomic, assign) LGAdSlotPosition position;

/// Accept a set of image sizes, please pass in the BUSize object.
@property (nonatomic, strong) NSMutableArray<LGAdSize *> *imgSizeArray;

/// required. Image size.
@property (nonatomic, strong) LGAdSize *imgSize;

/// Icon size.
@property (nonatomic, strong) LGAdSize *iconSize;

/// Maximum length of the title.
@property (nonatomic, assign) NSInteger titleLengthLimit;

/// Maximum length of description.
@property (nonatomic, assign) NSInteger descLengthLimit;

/// Whether to support deeplink.
@property (nonatomic, assign) BOOL isSupportDeepLink;

/// Native banner ads and native interstitial ads are set to 1, other ad types are 0, the default is 0.
@property (nonatomic, assign) BOOL isOriginAd;

- (NSDictionary *)dictionaryValue;
- (id)getBuAdSlot;

@end

NS_ASSUME_NONNULL_END
