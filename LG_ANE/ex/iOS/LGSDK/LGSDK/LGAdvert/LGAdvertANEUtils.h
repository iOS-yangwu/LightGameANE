//
//  LGAdvertANEUtils.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//



#import "FlashRuntimeExtensions.h"
#import <Foundation/Foundation.h>


#pragma mark - Fucntion
#define LG_IMP_ANE_FUNCTION(f) FREObject (LGANE_##f)(FREContext ctx, void *data, uint32_t argc, FREObject argv[])

#define LG_IMP_MAP_FUNCTION(f, data) { (const uint8_t*)(#f), (data), &(LGANE_##f) }

#define LG_ANE_FUNCTION(f) LG_IMP_ANE_FUNCTION(f)

#define LG_MAP_FUNCTION(f, data) LG_IMP_MAP_FUNCTION(f, data)

/// 从ANE获取参数：字符串类型
/// @param obj FREObject
/// e.g:
/// LGAdvertGetStringFromFREObject(argv[0]); 获取第一个参数
/// LGAdvertGetStringFromFREObject(argv[1]); 获取第二个参数
NSString * LGAdvertGetStringFromFREObject(FREObject obj);


/// 向ANE传递参数
/// @param string NSString 类型
/// e.g :
/// LGAdvertCreateFREString(@"1.0.0.0");
FREObject LGAdvertCreateFREString(NSString * string);


/// 从ANE获取参数：double 类型
/// @param obj FREObject
double LGAdvertGetDoubleFromFREObject(FREObject obj);


/// 向ANE传递参数
/// @param value double 类型
FREObject LGAdvertCreateFREDouble(double value);


/// 从ANE获取参数：int 类型
/// @param obj FREObject
int LGAdvertGetIntFromFREObject(FREObject obj);


/// 向ANE传递参数
/// @param value int 类型
FREObject LGAdvertCreateFREInt(int value);


/// 从ANE获取参数：bool 类型
/// @param obj FREObject
BOOL LGAdvertGetBoolFromFREObject(FREObject obj);


/// 向ANE传递参数
/// @param value bool 类型
FREObject LGAdvertCreateFREBool(BOOL value);


/// obj 转 json 字符串
/// @param obj NSDictionary/NSArray
NSString *LGAdvertObj2ANEJSON(id obj);


///向ANE发送消息（字符串）
void LGAdvertSendANEMessage(int what,NSString *code,NSString *key,NSString *value);


///向ANE发送消息
void LGAdvertSendANEMessageWithDict(NSDictionary *dict,NSString *code);


///向ANE发送消息
void LGAdvertANEDispatchStatusEventAsyn(NSString  * type ,NSString *jsonString);


typedef enum {
    //sdk config
    BDConfigRegisterFinishBlock = 0,
    BDConfigABTestFinishBlock,
    
    //rv
    RVDidLoad,
    RVFailToLoad,
    RVVideoDidLoad,
    RVWillVisible,
    RVDidVisible,
    RVWillClose,
    RVDidClose,
    RVDidClick,
    RVDidPlayFinish,
    RVServerRewardDidSucceed,
    RVServerRewardDidFail,
    RVDidClickSkip,
    //nativeExpressRV
    NERVDidLoad, //14
    NERVFailToLoad,
    NERVCallback,
    NERVDidDownLoadVideo,
    NERVViewRenderSuccess,
    NERVViewRenderFail,
    NERVWillVisible,
    NERVDidVisible,
    NERVWillClose, //22
    NERVDidClose,
    NERVDidClick,
    NERVDidClickSkip,
    NERVDidPlayFinish,
    NERVServerRewardDidSucceed,
    NERVServerRewardDidFail,
    NERVDidCloseOtherController, //29
    //fullScreenVideo
    FSVMateDidLoad,
    FSVMateFailToLoad,
    FSVDataDidLoad,
    FSVWillVisible,
    FSVDidVisible,
    FSVDidClick,
    FSVWillClose,
    FSVDidClose,
    FSVDidFinish,
    FSVDidClickSkip,//39
    //nativeExpressFullScreenVideo
    NEFSVDidLoad,
    NEFSVFailToLoad,
    NEFSVRenderSuccess,
    NEFSVRenderFail,
    NEFSVDownLoad,
    NEFSVWillVisible,
    NEFSVDidVisible,
    NEFSVDidClick,
    NEFSVClickSkip,
    NEFSVWillClose,
    NEFSVDidClose,
    NEFSVPlayFinish,
    NEFSVCallback,
    NSFSVCloseOther, //53
    
    
} LGAdvertANEEvent;

// nativeExpressFullScreenVideo
NSString* const NEFSVDidLoadCode = @"nativeExpressFullscreenVideoAdDidLoad";
NSString* const NEFSVFailToLoadCode = @"nativeExpressFullscreenVideoAd:didFailWithError:";
NSString* const NEFSVRenderSuccessCode = @"nativeExpressFullscreenVideoAdViewRenderSuccess";
NSString* const NEFSVRenderFailCode = @"nativeExpressFullscreenVideoAdViewRenderFail";
NSString* const NEFSVDownLoadCode = @"nativeExpressFullscreenVideoAdDidDownLoadVideo";
NSString* const NEFSVWillVisibleCode = @"nativeExpressFullscreenVideoAdWillVisible";
NSString* const NEFSVDidVisibleCode = @"nativeExpressFullscreenVideoAdDidVisible";
NSString* const NEFSVDidClickCode = @"nativeExpressFullscreenVideoAdDidClick";
NSString* const NEFSVClickSkipCode = @"nativeExpressFullscreenVideoAdDidClickSkip";
NSString* const NEFSVWillCloseCode = @"nativeExpressFullscreenVideoAdWillClose";
NSString* const NEFSVDidCloseCode = @"nativeExpressFullscreenVideoAdDidClose";
NSString* const NEFSVPlayFinishCode = @"nativeExpressFullscreenVideoAdDidPlayFinish:didFailWithError";
NSString* const NEFSVCallbackCode = @"nativeExpressFullscreenVideoAdCallback";
NSString* const NSFSVCloseOtherCode = @"nativeExpressFullscreenVideoAdDidCloseOtherController";


//fullScreenVideo
NSString* const FSVMateDidLoadCode = @"fullscreenVideoMaterialMetaAdDidLoad";
NSString* const FSVMateFailToLoadCode = @"fullscreenVideoAd:didFailWithError:";
NSString* const FSVDataDidLoadCode = @"fullscreenVideoAdVideoDataDidLoad";
NSString* const FSVWillVisibleCode = @"fullscreenVideoAdWillVisible";
NSString* const FSVDidVisibleCode = @"fullscreenVideoAdDidVisible";
NSString* const FSVDidClickCode = @"fullscreenVideoAdDidClick";
NSString* const FSVWillCloseCode = @"fullscreenVideoAdWillClose";
NSString* const FSVDidCloseCode = @"fullscreenVideoAdDidClose";
NSString* const FSVDidFinishCode = @"fullscreenVideoAdDidPlayFinish:didFailWithError";
NSString* const FSVDidClickSkipCode = @"fullscreenVideoAdDidClickSkip";


//nativeExpressRV
NSString* const NERVDidLoadCode = @"nativeExpressRewardedVideoAdDidLoad";
NSString* const NERVFailToLoadCode = @"nativeExpressRewardedVideoAd:didFailWithError:";
NSString* const NERVCallbackCode = @"nativeExpressRewardedVideoAdCallback";
NSString* const NERVDidDownLoadVideoCode = @"nativeExpressRewardedVideoAdDidDownLoadVideo";
NSString* const NERVViewRenderSuccessCode = @"nativeExpressRewardedVideoAdViewRenderSuccess";
NSString* const NERVViewRenderFailCode = @"nativeExpressRewardedVideoAdViewRenderFail:error:";
NSString* const NERVWillVisibleCode = @"nativeExpressRewardedVideoAdWillVisible";
NSString* const NERVDidVisibleCode = @"nativeExpressRewardedVideoAdDidVisible";
NSString* const NERVWillCloseCode = @"nativeExpressRewardedVideoAdWillClose";
NSString* const NERVDidCloseCode = @"nativeExpressRewardedVideoAdDidClose";
NSString* const NERVDidClickCode = @"nativeExpressRewardedVideoAdDidClick";
NSString* const NERVDidClickSkipCode = @"nativeExpressRewardedVideoAdDidClickSkip";
NSString* const NERVDidPlayFinishCode = @"nativeExpressRewardedVideoAdDidPlayFinish:didFailWithError:";
NSString* const NERVServerRewardDidSucceedCode = @"nativeExpressRewardedVideoAdServerRewardDidSucceed:verify:";
NSString* const NERVServerRewardDidFailCode = @"nativeExpressRewardedVideoAdServerRewardDidFail";
NSString* const NERVDidCloseOtherControllerCode = @"nativeExpressRewardedVideoAdDidCloseOtherController:interactionType:";


//rv
NSString* const RVDidLoadCode = @"rewardedVideoAdDidLoad";
NSString* const RVFailToLoadCode = @"rewardedVideoAd:didFailWithError:";
NSString* const RVVideoDidLoadCode = @"rewardedVideoAdVideoDidLoad";
NSString* const RVWillVisibleCode = @"rewardedVideoAdWillVisible";
NSString* const RVDidVisibleCode = @"rewardedVideoAdDidVisible";
NSString* const RVWillCloseCode = @"rewardedVideoAdWillClose";
NSString* const RVDidCloseCode = @"rewardedVideoAdDidClose";
NSString* const RVDidClickCode = @"rewardedVideoAdDidClick";
NSString* const RVDidPlayFinishCode = @"rewardedVideoAdDidPlayFinish:didFailWithError:";
NSString* const RVServerRewardDidSucceedCode = @"rewardedVideoAdServerRewardDidSucceed:verify:";
NSString* const RVServerRewardDidFailCode = @"rewardedVideoAdServerRewardDidFail";
NSString* const RVDidClickSkipCode = @"rewardedVideoAdDidClickSkip";

//sdk congig
NSString* const BDConfigRegisterFinishBlockCode = @"BDConfigRegisterFinishBlock";
NSString* const BDConfigABTestFinishBlockCode = @"BDConfigABTestFinishBlock";


