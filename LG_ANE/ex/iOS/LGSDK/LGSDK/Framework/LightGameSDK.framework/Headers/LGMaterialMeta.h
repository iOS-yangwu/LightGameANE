//
//  LGMaterialMeta.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGAdImage.h"


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, LGInteractionType) {
    LGInteractionTypeCustorm = 0,
    LGInteractionTypeNO_INTERACTION = 1,  // pure ad display
    LGInteractionTypeURL = 2,             // open the webpage using a browser
    LGInteractionTypePage = 3,            // open the webpage within the app
    LGInteractionTypeDownload = 4,        // download the app
    LGInteractionTypePhone = 5,           // make a call
    LGInteractionTypeMessage = 6,         // send messages
    LGInteractionTypeEmail = 7,           // send email
    LGInteractionTypeVideoAdDetail = 8    // video ad details page
};

typedef NS_ENUM(NSInteger, LGFeedADMode) {
    LGFeedADModeSmallImage = 2,
    LGFeedADModeLargeImage = 3,
    LGFeedADModeGroupImage = 4,
    LGFeedVideoAdModeImage = 5, // video ad || rewarded video ad horizontal screen
    LGFeedVideoAdModePortrait = 15, // rewarded video ad vertical screen
    LGFeedADModeImagePortrait = 16
};


@interface LGMaterialMeta : NSObject

/// interaction types supported by ads.
@property (nonatomic, assign) LGInteractionType interactionType;

/// material pictures.
@property (nonatomic, strong) NSArray<LGAdImage *> *imageAry;

/// ad logo icon.
@property (nonatomic, strong) LGAdImage *icon;

/// ad headline.
@property (nonatomic, copy) NSString *AdTitle;

/// ad description.
@property (nonatomic, copy) NSString *AdDescription;

/// ad source.
@property (nonatomic, copy) NSString *source;

/// text displayed on the creative button.
@property (nonatomic, copy) NSString *buttonText;

/// display format of the in-feed ad, other ads ignores it.
@property (nonatomic, assign) LGFeedADMode imageMode;

/// Star rating, range from 1 to 5.
@property (nonatomic, assign) NSInteger score;

/// Number of comments.
@property (nonatomic, assign) NSInteger commentNum;

/// ad installation package size, unit byte.
@property (nonatomic, assign) NSInteger appSize;

/// media configuration parameters.
@property (nonatomic, strong) NSDictionary *mediaExt;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

- (id)getBuMaterialMeta;

@end


NS_ASSUME_NONNULL_END
