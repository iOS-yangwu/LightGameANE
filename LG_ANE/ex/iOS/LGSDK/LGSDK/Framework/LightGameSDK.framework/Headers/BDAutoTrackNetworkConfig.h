//
//  BDAutoTrackNetworkConfig.h
//  Applog
//
//  Created by bob on 2019/2/18.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLPickerBind;
FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLPickerQuery;
FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLPickerUpload;
FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLPickerHeat;

FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLPickerLogin;
FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLSimulatorUpload;
FOUNDATION_EXTERN BDAutoTrackRequestURLType const BDAutoTrackRequestURLSimulatorLog;

/// function
FOUNDATION_EXTERN NSString * bd_requestURLForType(BDAutoTrackRequestURLType type, BDAutoTrackServiceVendor vendor);
FOUNDATION_EXTERN NSString * bd_URLSuffixWithType(BDAutoTrackRequestURLType type);

NS_ASSUME_NONNULL_END
