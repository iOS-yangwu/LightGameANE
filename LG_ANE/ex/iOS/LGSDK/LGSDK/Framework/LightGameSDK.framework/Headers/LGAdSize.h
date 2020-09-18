//
//  LGBuSize.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 Get the view with the best results by using the predefined size in pixels.
 When it comes to view display, it is recommended to use the same scaling.
 */
typedef NS_ENUM(NSInteger, LGProposalSize) {
    LGProposalSize_Banner600_90,
    LGProposalSize_Banner600_100,
    LGProposalSize_Banner600_150,
    LGProposalSize_Banner600_260,
    LGProposalSize_Banner600_286,
    LGProposalSize_Banner600_300,
    LGProposalSize_Banner600_388,
    LGProposalSize_Banner600_400,
    LGProposalSize_Banner600_500,
    LGProposalSize_Feed228_150,
    LGProposalSize_Feed690_388,
    LGProposalSize_Interstitial600_400,
    LGProposalSize_Interstitial600_600,
    LGProposalSize_Interstitial600_900,
    LGProposalSize_DrawFullScreen
};


@interface LGAdSize : NSObject
// width unit pixel.
@property (nonatomic, assign) NSInteger width;

// height unit pixel.
@property (nonatomic, assign) NSInteger height;

- (NSDictionary *)dictionaryValue;

- (id)getBuSize;

@end

@interface LGAdSize (BU_SizeFactory)
+ (instancetype)sizeBy:(LGProposalSize)proposalSize;
@end


NS_ASSUME_NONNULL_END
