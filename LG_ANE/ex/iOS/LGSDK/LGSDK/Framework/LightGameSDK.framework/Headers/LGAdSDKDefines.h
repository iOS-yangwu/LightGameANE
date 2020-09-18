//
//  LGAdSDKDefines.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, LGUserGender) {
    LGUserGenderUnknown,
    LGUserGenderMan,
    LGUserGenderWoman,
};

typedef NS_ENUM(NSInteger, LGAdSDKLogLevel) {
    LGAdSDKLogLevelNone,
    LGAdSDKLogLevelError,
    LGAdSDKLogLevelDebug
};

typedef NS_ENUM(NSInteger, LGPlayerPlayState) {
    LGPlayerStateFailed    = 0,
    LGPlayerStateBuffering = 1,
    LGPlayerStatePlaying   = 2,
    LGPlayerStateStopped   = 3,
    LGPlayerStatePause     = 4,
    LGPlayerStateDefalt    = 5
};

@protocol BUToDictionary <NSObject>
- (NSDictionary *)dictionaryValue;
@end



NS_ASSUME_NONNULL_END
