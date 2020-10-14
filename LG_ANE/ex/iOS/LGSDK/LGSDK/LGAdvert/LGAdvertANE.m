//
//  LGAdvertANE.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGAdvertANE.h"
#import "LGManager.h"
#import "LGRewardVideoManager.h"
#import "LGNativeExpressRewardedVideoManager.h"
#import "LGFullScreenVideoManager.h"
#import "LGNativeExpressFullScreenVideoManager.h"
#import "LGCustomAutoTrack_ANE.h"
#import "LGSplashAd.h"

#pragma mark - sdk config
/// setBDConfig
LG_ANE_FUNCTION(SET_DBCONFIG){
    
    int serviceVendor   = LGAdvertGetIntFromFREObject(argv[0]);
    BOOL autoTrackEnabled = LGAdvertGetBoolFromFREObject(argv[1]);
    BOOL showDebugLog = LGAdvertGetBoolFromFREObject(argv[2]);
    BOOL logNeedEncrypt = LGAdvertGetBoolFromFREObject(argv[3]);
    NSString *userUniqueID = LGAdvertGetStringFromFREObject(argv[4]);
    NSString *language = LGAdvertGetStringFromFREObject(argv[5]);
    NSString *abServerVersions = LGAdvertGetStringFromFREObject(argv[6]);
    NSString *customHeaderBlock = LGAdvertGetStringFromFREObject(argv[7]);
    
    [[LGManager shareManager]setBDConfigWithServiceVendor:serviceVendor autoTrackEnabled:autoTrackEnabled showDebugLog:showDebugLog logNeedEncrypt:logNeedEncrypt userUniqueID:userUniqueID lauguage:language abServerVersions:abServerVersions customHeaderBlock:customHeaderBlock];
    return NULL;
    
}

/// Init SDK
LG_ANE_FUNCTION(INIT_SDK) {
    
    NSString *appID   = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *appName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *channel = LGAdvertGetStringFromFREObject(argv[2]);
    [[LGManager shareManager] startWithAppID:appID appName:appName channel:channel];
    return NULL;
}

/// isDebuLog
LG_ANE_FUNCTION(ISDEBUGLOG){
    
    BOOL isDebugLog= LGAdvertGetBoolFromFREObject(argv[0]);
    [LGManager isDebuLog:isDebugLog];
    return NULL;
}

/// debugType
LG_ANE_FUNCTION(DEBUGTYPE){
    
    int debugType = LGAdvertGetIntFromFREObject(argv[0]);
    [LGManager debugType:debugType];
    return NULL;
}

/// /// LGSDK Version
LG_ANE_FUNCTION(LG_SDK_VERSION){
    
    int version = [LGManager getLightGameVersion];
    return LGAdvertCreateFREInt(version);
}

/// setCurrentUserUniqueID
LG_ANE_FUNCTION(SET_CURRENT_USER_ID){
    
    NSString *uniqueId   = LGAdvertGetStringFromFREObject(argv[0]);
    [LGManager setCurrentUserUniqueID:uniqueId];
    return NULL;
}

/// setCustomHeaderBlock
LG_ANE_FUNCTION(SET_CUSTOM_HEADER){
    
    NSString *JSONString = LGAdvertGetStringFromFREObject(argv[0]);
    [LGManager setCustomHeaderBlock:JSONString];
    return NULL;
}

/// clearUserUniqueId
LG_ANE_FUNCTION(CLEAR_USER_UNIQUE_ID){
    
    [LGManager clearUserUniqueID];
    return NULL;
}

/// setABSDKVersions
LG_ANE_FUNCTION(SET_ABSDK_VERSION){
    
    NSString *version = LGAdvertGetStringFromFREObject(argv[0]);
    [LGManager setABSDKVersions:version];
    return NULL;
}

/// getABSDKVersions
LG_ANE_FUNCTION(GET_ABSDK_VERSION){
    
    NSString *version = [LGManager getABSDKVersions];
    return LGAdvertCreateFREString(version);
}

/// lg_event
LG_ANE_FUNCTION(LG_EVENT){
    
    NSString *event = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *para = LGAdvertGetStringFromFREObject(argv[1]);
    [LGManager lg_event:event params:para];
    return NULL;
}

/// ABTestConfig
LG_ANE_FUNCTION(ABTESTCONFIG){
    
    NSString *key = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *defaultValue = LGAdvertGetStringFromFREObject(argv[1]);
    [LGManager ABTestConfigValueForKey:key defaultValue:defaultValue];
    return NULL;
}


#pragma mark - rewardVideo
/// load
LG_ANE_FUNCTION(VIDEO_LOAD){
    
    NSString *slotId = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *userId = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *rewardName = LGAdvertGetStringFromFREObject(argv[2]);
    int rewardAmount = LGAdvertGetIntFromFREObject(argv[3]);
    NSString *extra = LGAdvertGetStringFromFREObject(argv[4]);
    [[LGRewardVideoManager manager] loadAd:slotId userId:userId rewardName:rewardName rewardAmount:rewardAmount extra:extra];
    return NULL;
}

/// isvalid
LG_ANE_FUNCTION(VIDEO_ISVALID){
    
    BOOL isvalid = [[LGRewardVideoManager manager] isAdValid];
    return LGAdvertCreateFREBool(isvalid);
}

/// show
LG_ANE_FUNCTION(VIDEO_SHOW){
    
    BOOL showSuccess = [[LGRewardVideoManager manager] showAd];
    return LGAdvertCreateFREBool(showSuccess);
}

/// showFromScene
LG_ANE_FUNCTION(VIDEO_SHOW_SCENE){
    
    int ritScene = LGAdvertGetIntFromFREObject(argv[0]);
    NSString *ritSceneDesc = LGAdvertGetStringFromFREObject(argv[1]);
    BOOL showSuccess = [[LGRewardVideoManager manager] showAdFromRitScene:ritScene ritSceneDescribe:ritSceneDesc];
    return LGAdvertCreateFREBool(showSuccess);
}


#pragma mark - nariveExpressRewardVideo
/// load
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_LOAD){
    
    NSString *slotId = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *userId = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *rewardName = LGAdvertGetStringFromFREObject(argv[2]);
    int rewardAmount = LGAdvertGetIntFromFREObject(argv[3]);
    NSString *extra = LGAdvertGetStringFromFREObject(argv[4]);
    [[LGNativeExpressRewardedVideoManager manager] loadAd:slotId userId:userId rewardName:rewardName rewardAmount:rewardAmount extra:extra];
    return NULL;
}

/// isvalid
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_ISVALID){
    
    BOOL isvalid = [[LGNativeExpressRewardedVideoManager manager] isAdValid];
    return LGAdvertCreateFREBool(isvalid);
}

/// show
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW){
    
    BOOL showSuccess = [[LGNativeExpressRewardedVideoManager manager] showAd];
    return LGAdvertCreateFREBool(showSuccess);
}

/// showFromScene
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW_SCENE){
    
    int ritScene = LGAdvertGetIntFromFREObject(argv[0]);
    NSString *ritSceneDesc = LGAdvertGetStringFromFREObject(argv[1]);
    BOOL showSuccess = [[LGNativeExpressRewardedVideoManager manager] showAdFromRitScene:ritScene ritSceneDescribe:ritSceneDesc];
    return LGAdvertCreateFREBool(showSuccess);
}


#pragma mark - fullScreen
/// load
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_LOAD){
    
    NSString *slotId = LGAdvertGetStringFromFREObject(argv[0]);
    [[LGFullScreenVideoManager manager] loadAd:slotId];
    return NULL;
}

/// isvalid
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_ISVALID){
    
    BOOL isvalid = [[LGFullScreenVideoManager manager] isAdValid];
    return LGAdvertCreateFREBool(isvalid);
}

/// show
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_SHOW){
    
    BOOL showSuccess = [[LGFullScreenVideoManager manager] showAd];
    return LGAdvertCreateFREBool(showSuccess);
}

/// showFromScene
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_SHOW_SCENE){
    
    NSString *ritSceneDesc = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL showSuccess = [[LGFullScreenVideoManager manager]showAdWithRitSceneDescribe:ritSceneDesc];
    return LGAdvertCreateFREBool(showSuccess);
}


#pragma mark - nativeExpressFullScreen
/// load
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_LOAD){
    
    NSString *slotId = LGAdvertGetStringFromFREObject(argv[0]);
    [[LGNativeExpressFullScreenVideoManager manager] loadAd:slotId];
    return NULL;
    
}

/// isvalid
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_ISVALID){
    
    BOOL isvalid = [[LGNativeExpressFullScreenVideoManager manager] isAdValid];
    return LGAdvertCreateFREBool(isvalid);
}

/// show
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW){
    
    BOOL showSuccess = [[LGNativeExpressFullScreenVideoManager manager] showAd];
    return LGAdvertCreateFREBool(showSuccess);
    
}

/// showFromScene
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE){
    
    NSString *ritSceneDesc = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL showSuccess = [[LGNativeExpressFullScreenVideoManager manager] showAdWithRitSceneDescribe:ritSceneDesc];
    return LGAdvertCreateFREBool(showSuccess);
}


#pragma mark - customAutoTrack
/// registerEventByMethod
LG_ANE_FUNCTION(REGISTER_EVENT){
    
    NSString *method = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[1]);
    
    [LGCustomAutoTrack_ANE registerEventByMethod:method isSuccess:isSuccess];
    return NULL;
    
}

/// purchaseEventWithContentType
LG_ANE_FUNCTION(PURCHASE_EVENT){
    
    NSString *contentType = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *contentName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *contentID = LGAdvertGetStringFromFREObject(argv[2]);
    int contentNum = LGAdvertGetIntFromFREObject(argv[3]);
    NSString *paymentChannel = LGAdvertGetStringFromFREObject(argv[4]);
    NSString *currency = LGAdvertGetStringFromFREObject(argv[5]);
    int amount = LGAdvertGetIntFromFREObject(argv[6]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[7]);
    
    [LGCustomAutoTrack_ANE purchaseEventWithContentType:contentType contentName:contentName contentID:contentID contentNumber:contentNum paymentChannel:paymentChannel currency:currency currency_amount:amount isSuccess:isSuccess];
    return NULL;
}

/// loginEventByMethod
LG_ANE_FUNCTION(LOGIN_EVENT){
    
    NSString *method = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[1]);
    
    [LGCustomAutoTrack_ANE loginEventByMethod:method isSuccess:isSuccess];
    return NULL;
    
}

/// accessAccountEventByType
LG_ANE_FUNCTION(ACCESSACCOUNT_EVENT){
    
    NSString *type = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[1]);
    
    [LGCustomAutoTrack_ANE accessAccountEventByType:type isSuccess:isSuccess];
    return NULL;
}

/// questEventWithQuestID
LG_ANE_FUNCTION(QUEST_EVENT){
    
    NSString *questId = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *questType = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *questName = LGAdvertGetStringFromFREObject(argv[2]);
    int questNumber = LGAdvertGetIntFromFREObject(argv[3]);
    NSString *description = LGAdvertGetStringFromFREObject(argv[4]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[5]);
    
    [LGCustomAutoTrack_ANE questEventWithQuestID:questId questType:questType questName:questName questNumer:questNumber description:description isSuccess:isSuccess];
    return NULL;
}

/// updateLevelEventWithLevel
LG_ANE_FUNCTION(UPDATELEVEL_EVENT){
    
    int level = LGAdvertGetIntFromFREObject(argv[0]);
    [LGCustomAutoTrack_ANE updateLevelEventWithLevel:level];
    return NULL;
}

/// createGameRoleEventByID
LG_ANE_FUNCTION(CREATEGAMEROLE_EVENT){
    
    NSString *roleId = LGAdvertGetStringFromFREObject(argv[0]);
    [LGCustomAutoTrack_ANE createGameRoleEventByID:roleId];
    return NULL;
    
}
/// viewContentEventWithContentType
LG_ANE_FUNCTION(VIEWCONTENT_EVENT){
    
    NSString *contentType = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *contentName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *contentId   = LGAdvertGetStringFromFREObject(argv[2]);
    
    [LGCustomAutoTrack_ANE viewContentEventWithContentType:contentType contentName:contentName contentID:contentId];
    return NULL;
}

/// addCartEventWithContentType
LG_ANE_FUNCTION(ADDCART_EVENT){
    
    NSString *contentType = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *contentName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *contentId   = LGAdvertGetStringFromFREObject(argv[2]);
    int contentNumber = LGAdvertGetIntFromFREObject(argv[3]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[4]);
    
    [LGCustomAutoTrack_ANE addCartEventWithContentType:contentType contentName:contentName contentID:contentId contentNumber:contentNumber isSuccess:isSuccess];
    return NULL;
}

/// checkoutEventWithContentType
LG_ANE_FUNCTION(CHECKOUT_EVENT){
    
    NSString *contentType = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *contentName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *contentId   = LGAdvertGetStringFromFREObject(argv[2]);
    int contentNumber = LGAdvertGetIntFromFREObject(argv[3]);
    BOOL isVirtualCurrency = LGAdvertGetBoolFromFREObject(argv[4]);
    NSString *virtualCurrency = LGAdvertGetStringFromFREObject(argv[5]);
    NSString *currency = LGAdvertGetStringFromFREObject(argv[6]);
    int currencyAmount = LGAdvertGetIntFromFREObject(argv[7]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[8]);

    [LGCustomAutoTrack_ANE checkoutEventWithContentType:contentType contentName:contentName contentID:contentId contentNumber:contentNumber isVirtualCurrency:isVirtualCurrency virtualCurrency:virtualCurrency currency:currency currency_amount:currencyAmount isSuccess:isSuccess];
    return NULL;
}

/// accessPaymentChannelEventByChannel
LG_ANE_FUNCTION(ACCESSPAYMENTCHANNEL_EVENT){
    
    NSString *channel = LGAdvertGetStringFromFREObject(argv[0]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[1]);

    [LGCustomAutoTrack_ANE accessPaymentChannelEventByChannel:channel isSuccess:isSuccess];
    return NULL;
    
}
/// addToFavouriteEventWithContentType
LG_ANE_FUNCTION(ADDTOFAVOURITE_EVENT){
    
    NSString *contentType = LGAdvertGetStringFromFREObject(argv[0]);
    NSString *contentName = LGAdvertGetStringFromFREObject(argv[1]);
    NSString *contentId   = LGAdvertGetStringFromFREObject(argv[2]);
    int contentNumber = LGAdvertGetIntFromFREObject(argv[3]);
    BOOL isSuccess = LGAdvertGetBoolFromFREObject(argv[4]);
    
    [LGCustomAutoTrack_ANE addToFavouriteEventWithContentType:contentType contentName:contentName contentID:contentId contentNumber:contentNumber isSuccess:isSuccess];
    return NULL;
    
}
/*
#pragma mark - splash
/// load
LG_ANE_FUNCTION(SPLASH_LOAD){
    
    NSString *slotId = LGAdvertGetStringFromFREObject(argv[0]);
    int timeout = LGAdvertGetIntFromFREObject(argv[1]);
    [[LGSplashAd manager] loadAd:slotId tolerateTimeout:timeout];
    return NULL;
}

/// isValid
LG_ANE_FUNCTION(SPLASH_ISVALID){
    
    BOOL isValid = [[LGSplashAd manager] isAdValid];
    return LGAdvertCreateFREBool(isValid);
}

/// show
LG_ANE_FUNCTION(SPLASH_SHOW){
    
    [[LGSplashAd manager] showAd];
    return NULL;
}
*/

#pragma mark- FLASH
void LGANEInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToTest, const FRENamedFunction** functionsToSet)
{
    
    static FRENamedFunction func[] =
    {
        // sdk config
        LG_MAP_FUNCTION(SET_DBCONFIG, NULL),
        LG_MAP_FUNCTION(INIT_SDK,NULL),
        LG_MAP_FUNCTION(ISDEBUGLOG, NULL),
        LG_MAP_FUNCTION(DEBUGTYPE, NULL),
        LG_MAP_FUNCTION(LG_SDK_VERSION, NULL),
        LG_MAP_FUNCTION(SET_CURRENT_USER_ID, NULL),
        LG_MAP_FUNCTION(SET_CUSTOM_HEADER, NULL),
        LG_MAP_FUNCTION(CLEAR_USER_UNIQUE_ID, NULL),
        LG_MAP_FUNCTION(SET_ABSDK_VERSION, NULL),
        LG_MAP_FUNCTION(GET_ABSDK_VERSION, NULL),
        LG_MAP_FUNCTION(LG_EVENT, NULL),
        LG_MAP_FUNCTION(ABTESTCONFIG, NULL),
        
        // rewardvideo
        LG_MAP_FUNCTION(VIDEO_LOAD, NULL),
        LG_MAP_FUNCTION(VIDEO_ISVALID, NULL),
        LG_MAP_FUNCTION(VIDEO_SHOW, NULL),
        LG_MAP_FUNCTION(VIDEO_SHOW_SCENE, NULL),
        
        // nativeExpressRewardVideo
        LG_MAP_FUNCTION(NATIVE_EXPRESS_VIDEO_LOAD, NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_VIDEO_ISVALID, NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW, NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW_SCENE, NULL),
        
        /// fullScreenVideo
        LG_MAP_FUNCTION(FULL_SCREEN_VIDEO_LOAD,NULL),
        LG_MAP_FUNCTION(FULL_SCREEN_VIDEO_ISVALID,NULL),
        LG_MAP_FUNCTION(FULL_SCREEN_VIDEO_SHOW,NULL),
        LG_MAP_FUNCTION(FULL_SCREEN_VIDEO_SHOW_SCENE,NULL),
        
        /// nativeExpressFullScreenVideo
        LG_MAP_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_LOAD,NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_ISVALID,NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW,NULL),
        LG_MAP_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE,NULL),
        
        /// customAutoTrack
        LG_MAP_FUNCTION(REGISTER_EVENT, NULL),
        LG_MAP_FUNCTION(PURCHASE_EVENT, NULL),
        LG_MAP_FUNCTION(LOGIN_EVENT, NULL),
        LG_MAP_FUNCTION(ACCESSACCOUNT_EVENT, NULL),
        LG_MAP_FUNCTION(QUEST_EVENT, NULL),
        LG_MAP_FUNCTION(UPDATELEVEL_EVENT, NULL),
        LG_MAP_FUNCTION(CREATEGAMEROLE_EVENT, NULL),
        LG_MAP_FUNCTION(VIEWCONTENT_EVENT, NULL),
        LG_MAP_FUNCTION(ADDCART_EVENT, NULL),
        LG_MAP_FUNCTION(CHECKOUT_EVENT, NULL),
        LG_MAP_FUNCTION(ACCESSPAYMENTCHANNEL_EVENT, NULL),
        LG_MAP_FUNCTION(ADDTOFAVOURITE_EVENT, NULL),
        
        /*
        /// splash
        LG_MAP_FUNCTION(SPLASH_LOAD, NULL),
        LG_MAP_FUNCTION(SPLASH_ISVALID, NULL),
        LG_MAP_FUNCTION(SPLASH_SHOW, NULL),
         */

        
    };
    
    *numFunctionsToTest = sizeof(func) / sizeof(FRENamedFunction);
    *functionsToSet = func;
    LGANEEventContext = ctx;
    
}

void LGANEFinalizer(FREContext ctx) {
    // clean
}

void LGANEExtensionInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet) {
    *extDataToSet = NULL;
    *ctxInitializerToSet = &LGANEInitializer;
    *ctxFinalizerToSet = &LGANEFinalizer;
}

void LGANEExtensionFinalizer(void* extData) {
    // clean
}

