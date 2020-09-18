//
//  LGFunctions.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//


#pragma mark - sdk init
/// setBDConfig
#define SET_DBCONFIG                        setBDConfig

/// Init SDK
#define INIT_SDK                             initSDK

/// isDebuLog
#define ISDEBUGLOG                           isDebugLog

/// debugType
#define DEBUGTYPE                            debugType

/// LGSDK Version
#define LG_SDK_VERSION                       getLGSDKVersion

/// setCurrentUserUniqueID
#define SET_CURRENT_USER_ID                  setCurrentUserUniqueId

/// setCustomHeaderBlock
#define SET_CUSTOM_HEADER                    setCustomHeader

/// clearUserUniqueId
#define CLEAR_USER_UNIQUE_ID                 clearUserUniqueId

/// setABSDKVersions
#define SET_ABSDK_VERSION                    setABSDKVersion

/// getABSDKVersions
#define GET_ABSDK_VERSION                    getABSDKVersion

/// lg_event
#define LG_EVENT                             lgEvent
/// ABTest
#define ABTESTCONFIG                         ABTestConfig



#pragma mark - rewardVideo
/// load
#define VIDEO_LOAD                          loadRewardVideo

/// isValid
#define VIDEO_ISVALID                       isValidRewardVideo

/// show
#define VIDEO_SHOW                          showRewardVideo

/// showFromScene
#define VIDEO_SHOW_SCENE                    showRewardVideoFromScene



#pragma mark - nativeExpressRewardVideo
/// load
#define NATIVE_EXPRESS_VIDEO_LOAD           loadNativeExpressVideo
/// isvalid
#define NATIVE_EXPRESS_VIDEO_ISVALID        isValidNativeExpressVideo

/// show
#define NATIVE_EXPRESS_VIDEO_SHOW           showNativeExpressVideo

/// showFromScene
#define NATIVE_EXPRESS_VIDEO_SHOW_SCENE     showNativeExpressVideoFromScene



#pragma mark - fullScreenRewardVideo
/// load
#define FULL_SCREEN_VIDEO_LOAD               loadFullScreenVideo

/// isVail
#define FULL_SCREEN_VIDEO_ISVALID            isvalidFullScreenVideo

/// show
#define FULL_SCREEN_VIDEO_SHOW               showFullScreenVideo

/// showFromScene
#define FULL_SCREEN_VIDEO_SHOW_SCENE         showFullScreenVideoFromScene



#pragma mark - nativeExpressFullScreenVideo
/// load
#define NATIVE_EXPRESS_FULL_SCREEN_LOAD      loadNativeExpressFullScreenVideo

/// isVail
#define NATIVE_EXPRESS_FULL_SCREEN_ISVALID   isValidNativeExpressFullScreenVideo

/// show
#define NATIVE_EXPRESS_FULL_SCREEN_SHOW      showNativeExpressFullScreenVideo

/// showFromScene
#define NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE showNativeExpressFullScreenVideoFromScene



#pragma mark - customAutoTrack
/// registerEventByMethod
#define REGISTER_EVENT                       registerEvent

/// purchaseEventWithContentType
#define PURCHASE_EVENT                       purchaseEvent

/// loginEventByMethod
#define LOGIN_EVENT                          loginEvent

/// accessAccountEventByType
#define ACCESSACCOUNT_EVENT                  accessAccountEvent

/// questEventWithQuestID
#define QUEST_EVENT                          questEvent

/// updateLevelEventWithLevel
#define UPDATELEVEL_EVENT                    updateLevelEvent

/// createGameRoleEventByID
#define CREATEGAMEROLE_EVENT                 createGameRoleEvent

/// viewContentEventWithContentType
#define VIEWCONTENT_EVENT                    viewContentEvent

/// addCartEventWithContentType
#define ADDCART_EVENT                        addCartEvent

/// checkoutEventWithContentType
#define CHECKOUT_EVENT                       checkoutEvent

/// accessPaymentChannelEventByChannel
#define ACCESSPAYMENTCHANNEL_EVENT           accessPaymentChannelEvent

/// addToFavouriteEventWithContentType
#define ADDTOFAVOURITE_EVENT                 addToFavouriteEvent

