//
//  LGAdvertANE.h
//  LGSDK
//
//  Created by 洋吴 on 2019/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGAdvertANEUtils.h"
#import "LGFunctions.h"


FREContext LGANEEventContext;

#pragma mark - sdk config
/// setBDConfig
LG_ANE_FUNCTION(SET_DBCONFIG);

///Init SDK
LG_ANE_FUNCTION(INIT_SDK);

/// isDebuLog
LG_ANE_FUNCTION(ISDEBUGLOG);

/// debugType
LG_ANE_FUNCTION(DEBUGTYPE);

/// /// LGSDK Version
LG_ANE_FUNCTION(LG_SDK_VERSION);

/// setCurrentUserUniqueID
LG_ANE_FUNCTION(SET_CURRENT_USER_ID);

/// setCustomHeaderBlock
LG_ANE_FUNCTION(SET_CUSTOM_HEADER);

/// clearUserUniqueId
LG_ANE_FUNCTION(CLEAR_USER_UNIQUE_ID);

/// setABSDKVersions
LG_ANE_FUNCTION(SET_ABSDK_VERSION);

/// getABSDKVersions
LG_ANE_FUNCTION(GET_ABSDK_VERSION);

/// lg_event
LG_ANE_FUNCTION(LG_EVENT);

/// ABTestConfig
LG_ANE_FUNCTION(ABTESTCONFIG);


#pragma mark - rewardVideo
/// load
LG_ANE_FUNCTION(VIDEO_LOAD);

/// isvalid
LG_ANE_FUNCTION(VIDEO_ISVALID);

/// showRewardVideo
LG_ANE_FUNCTION(VIDEO_SHOW);

/// showRewardVideoFromScene
LG_ANE_FUNCTION(VIDEO_SHOW_SCENE);


#pragma mark - nativeExpressRewardVideo
/// load
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_LOAD);

/// isvalid
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_ISVALID);

/// show
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW);

/// showFromScene
LG_ANE_FUNCTION(NATIVE_EXPRESS_VIDEO_SHOW_SCENE);


#pragma mark - fullScreen
/// load
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_LOAD);

/// isvalid
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_ISVALID);

/// show
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_SHOW);

/// showFromScene
LG_ANE_FUNCTION(FULL_SCREEN_VIDEO_SHOW_SCENE);


#pragma mark - nativeExpressFullScreen
/// load
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_LOAD);

/// isvalid
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_ISVALID);

/// show
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW);

/// showFromScene
LG_ANE_FUNCTION(NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE);


#pragma mark - customAutoTrack
/// registerEventByMethod
LG_ANE_FUNCTION(REGISTER_EVENT);

/// purchaseEventWithContentType
LG_ANE_FUNCTION(PURCHASE_EVENT);

/// loginEventByMethod
LG_ANE_FUNCTION(LOGIN_EVENT);

/// accessAccountEventByType
LG_ANE_FUNCTION(ACCESSACCOUNT_EVENT);

/// questEventWithQuestID
LG_ANE_FUNCTION(QUEST_EVENT);

/// updateLevelEventWithLevel
LG_ANE_FUNCTION(UPDATELEVEL_EVENT);

/// createGameRoleEventByID
LG_ANE_FUNCTION(CREATEGAMEROLE_EVENT);

/// viewContentEventWithContentType
LG_ANE_FUNCTION(VIEWCONTENT_EVENT);

/// addCartEventWithContentType
LG_ANE_FUNCTION(ADDCART_EVENT);

/// checkoutEventWithContentType
LG_ANE_FUNCTION(CHECKOUT_EVENT);

/// accessPaymentChannelEventByChannel
LG_ANE_FUNCTION(ACCESSPAYMENTCHANNEL_EVENT);

/// addToFavouriteEventWithContentType
LG_ANE_FUNCTION(ADDTOFAVOURITE_EVENT);

/*
#pragma mark - splash
/// load
LG_ANE_FUNCTION(SPLASH_LOAD);
/// isValid
LG_ANE_FUNCTION(SPLASH_ISVALID);
/// show
LG_ANE_FUNCTION(SPLASH_SHOW);
*/












