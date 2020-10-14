//
//  LGManager.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGManager.h"
#import <LightGameSDK/LightGameSDK.h>
#import "JSONSerialization.h"
#import "LGAdvertANEUtils.h"



@interface LGManager ()

//@property (nonatomic,strong)LGBDConfig *config;

@end

@implementation LGManager

+ (LGManager *) shareManager{
    
    static LGManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{

        manager = [[LGManager alloc]init];
    });
    return manager;
    
}

- (void) setBDConfigWithServiceVendor:(int)serviceVendor
 autoTrackEnabled:(BOOL)autoTrackEnabled
     showDebugLog:(BOOL)showDebugLog
   logNeedEncrypt:(BOOL)logNeedEncrypt
     userUniqueID:(NSString *)userUniqueID
         lauguage:(NSString *)lauguage
 abServerVersions:(NSString *)abServerVersions
customHeaderBlock:(NSString *)customHeaderBlock{
    
    LGBDConfig *bdCfg = [[LGBDConfig alloc] init];
    if (serviceVendor == 0) {
        bdCfg.serviceVendor = LGBDAutoTrackServiceVendorCN;
    }else if (serviceVendor == 1){
        bdCfg.serviceVendor = LGBDAutoTrackServiceVendorSG;
    }else if (serviceVendor == 2){
        bdCfg.serviceVendor = LGBDAutoTrackServiceVendorVA;
    }
    bdCfg.autoTrackEnabled = autoTrackEnabled;
    bdCfg.showDebugLog = showDebugLog;
    bdCfg.logNeedEncrypt = logNeedEncrypt;
    bdCfg.userUniqueID = userUniqueID;
    bdCfg.lauguage = lauguage;
    bdCfg.abServerVersions = abServerVersions;
    NSDictionary *dict = [JSONSerialization toDictionaryWithJsonString:customHeaderBlock];
    bdCfg.customHeaderBlock = ^NSDictionary<NSString *,id> * _Nonnull{
        return dict;
    };
    
    __block NSString *deviceId;
    __block NSString *installId;
    __block NSString *ssId;
    __block NSString *userUniqueId;
    bdCfg.registerFinishBlock = ^(NSString * _Nullable deviceID, NSString * _Nullable installID, NSString * _Nullable ssID, NSString * _Nullable userUniqueID) {


        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{

            deviceId = deviceID == nil?@"":deviceID;
            installId = installID == nil?@"":installID;
            ssId = ssID == nil?@"":ssID;
            userUniqueId = userUniqueID == nil?@"":userUniqueID;
    
            NSDictionary *dic = @{@"deviceID":deviceId,@"installID":installId,@"ssID":ssId,@"userUniqueID":userUniqueId};
            NSString *jsonStr = [JSONSerialization convertToJsonData:dic];
            LGAdvertSendANEMessage(BDConfigRegisterFinishBlock,BDConfigRegisterFinishBlockCode,@"BDConfigRegisterFinishBlock",jsonStr);

            });

    };
    bdCfg.ABTestFinishBlock = ^(BOOL ABTestEnabled, NSDictionary * _Nullable allConfigs) {
        if (ABTestEnabled) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{

                NSString *jsonStr = [JSONSerialization convertToJsonData:allConfigs];

                LGAdvertSendANEMessage(BDConfigABTestFinishBlock,BDConfigABTestFinishBlockCode,@"BDConfigABTestFinishBlock",jsonStr);

                });

        }
    };
    [[LightGameManager sharedInstance] configTTTrack:bdCfg];

    
}
- (void)startWithAppID:(NSString *)appID appName:(NSString *)appName channel:(NSString *)channel{
    
    
    [LightGameManager startWithAppID:appID appName:appName channel:channel];
    
        
}

+ (void)isDebuLog:(BOOL)isNeedDebugLog{
    
    [LightGameManager isDebuLog:isNeedDebugLog];
}

+ (void)debugType:(int)logType{
    
    [LightGameManager debugType:logType];
    
}

+ (int)getLightGameVersion{
    
    return (int)[[LightGameManager sharedInstance] getLightGameVersion];
}

+ (void)setCurrentUserUniqueID:(NSString *)uniqueID{
    
    [LightGameManager setCurrentUserUniqueID:uniqueID];
}

+ (void)setCustomHeaderBlock:(NSString *)customHeaderBlock{
    
    NSDictionary *dict = [JSONSerialization toDictionaryWithJsonString:customHeaderBlock];
    [LightGameManager setCustomHeaderBlock:^NSDictionary<NSString *,id> * _Nonnull{
        
        return dict;
    }];
}

+ (void)clearUserUniqueID{
    
    [LightGameManager clearUserUniqueID];
}

+ (void)setABSDKVersions:(NSString *)versions{
    
    [LightGameManager setABSDKVersions:versions];
}

+ (NSString *)getABSDKVersions{
    
     return [LightGameManager getABSDKVersions];
}

+ (void)lg_event:(NSString *)event params:(NSString *)params{
    
    NSDictionary *para = [JSONSerialization toDictionaryWithJsonString:params];
    [LightGameManager lg_event:event params:para];
}

+ (id)ABTestConfigValueForKey:(NSString *)key defaultValue:(id)defaultValue{
    
    return [LightGameManager ABTestConfigValueForKey:key defaultValue:defaultValue];
}



@end
