//
//  BDAutoTrackDeviceHelper.h
//  Applog
//
//  Created by bob on 2019/1/18.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/// 设备相关信息

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *bd_base64_string(NSString *base64);
FOUNDATION_EXTERN BOOL bd_device_isJailBroken(void);
FOUNDATION_EXTERN NSString * bd_device_platformName(void);
FOUNDATION_EXTERN NSString * bd_device_machineModel(void);
FOUNDATION_EXTERN NSString * bd_device_decivceModel(void);
FOUNDATION_EXTERN CGFloat bd_device_screenScale(void);
FOUNDATION_EXTERN NSString * bd_device_resolutionString(void);
FOUNDATION_EXTERN CGSize bd_device_resolution(void);
FOUNDATION_EXTERN NSString * bd_device_openUDID(void);
FOUNDATION_EXTERN void bd_device_saveOpenUDIDToKeychain(NSString *_Nullable openUDID);
FOUNDATION_EXTERN NSString *_Nullable bd_device_fetchOpenUDIDFromKeychain(void);
FOUNDATION_EXTERN NSString *bd_device_IDFA(void);
FOUNDATION_EXTERN NSString * bd_device_IDFV(void);
FOUNDATION_EXTERN NSString * bd_device_currentSystemLanguage(void);
FOUNDATION_EXTERN NSString * bd_device_currentLanguage(void);
FOUNDATION_EXTERN NSString * bd_device_currentRegion(void);
FOUNDATION_EXTERN NSString * bd_device_timeZoneName(void);
FOUNDATION_EXTERN NSInteger bd_device_timeZoneOffset(void);
FOUNDATION_EXTERN NSString * bd_device_systemVersion(void);

NS_ASSUME_NONNULL_END
