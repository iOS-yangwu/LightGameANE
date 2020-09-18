//
//  LGBDConfig.h
//  LightGameSDK
//
//  Created by peiziming on 2019/7/19.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^LGBDAutoTrackABTestFinishBlock)(BOOL ABTestEnabled, NSDictionary * _Nullable  allConfigs);
typedef void(^LGBDAutoTrackRegisterFinishBlock)(NSString * _Nullable deviceID, NSString * _Nullable installID, NSString * _Nullable ssID, NSString *_Nullable userUniqueID);
typedef NSDictionary<NSString*, id> *_Nonnull (^LGBDAutoTrackCustomHeaderBlock)(void);

typedef NS_ENUM(NSInteger, LGBDAutoTrackServiceVendor) {
    LGBDAutoTrackServiceVendorCN = 0x010,//国内
    LGBDAutoTrackServiceVendorSG,//新加坡
    LGBDAutoTrackServiceVendorVA,//美东
};

NS_ASSUME_NONNULL_BEGIN

@interface LGBDConfig : NSObject

/*
 * 域名默认国内
   新加坡: BDAutoTrackServiceVendorSG
 */
@property (nonatomic, assign) LGBDAutoTrackServiceVendor serviceVendor;

@property (nonatomic, assign) BOOL autoTrackEnabled;
/*
 * 是否在控制台输出⽇日志，仅调试使⽤用。release版本请设置为 NO
 */
@property (nonatomic, assign) BOOL showDebugLog;

/*
 * 是否加密⽇日志，默认加密。release版本请设置为 YES
 */
@property (nonatomic, assign) BOOL logNeedEncrypt;

@property (nonatomic, copy, nullable) NSString *userUniqueID;

@property (nonatomic, copy, nullable) NSString *lauguage;

@property (nonatomic, copy, nullable) NSString *abServerVersions;

@property (nonatomic, copy, nullable) LGBDAutoTrackABTestFinishBlock ABTestFinishBlock;

@property (nonatomic, copy, nullable) LGBDAutoTrackRegisterFinishBlock registerFinishBlock;

@property (nonatomic, copy, nullable) LGBDAutoTrackCustomHeaderBlock customHeaderBlock;

@end

NS_ASSUME_NONNULL_END
