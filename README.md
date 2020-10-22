# LightGameANE
## Integration
### Catalog Description
![image.png](https://upload-images.jianshu.io/upload_images/1483801-30b64899cd4e89e7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

1、iOS Project
Object-C Code
Export static library required by ANE（libLGSDK.a）:
Execute in the Terminal: 1.cd to the current directory 2. Execute: ./build.sh;
Get libLGSDK.a in the figure below
![image.png](https://upload-images.jianshu.io/upload_images/1483801-296f3f1806444207.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



2、ActionScript Project
Use the IntelliJ IDEA development tool to open the Lib directory, that is, import the project, and the Flash call interface is in this project. Every time you modify the interface, you need to regenerate the LGAdvertLib.swc file

3、build
Use the terminal, cd to the tools directory and execute: ./buildANE.sh, you can get the required LGAdvert.ane

## Interface
### Deep Conversion Configuration
        
	LGAdvert.getInstance().setBDConfigRegisterFinishBlockListener(BDConfigRegisterFinishBlock);
    LGAdvert.getInstance().setBDConfigABTestFinishBlockListener(BDConfigABTestFinishBlock);
    LGAdvert.setBDConfig(serviceVendor:int,autoTrackEnabled:Boolean,showDebugLog:Boolean,logNeedEncrypt:Boolean,userUniqueID:String,language:String,abServerVersions:String,customHeaderBlock:String)

    function BDConfigRegisterFinishBlock(jstr:String):void{
		trace("BDConfigRegisterFinishBlock:",jstr);
	}
	function BDConfigABTestFinishBlock(jstr:String):void{
		trace("BDConfigABTestFinishBlock:",jstr);
	}

    LGCustomAutoTrack.registerEvent(method:String,isSuccess:Boolean);
    LGCustomAutoTrack.viewContentEvent(contentType:String,contentName:String,contentId:String);
    LGCustomAutoTrack.purchaseEvent(contentType:String,contentName:String,contentID:String,contentNum:int,paymentChannel:String,currency:String,amount:int,isSuccess:Boolean);
    LGCustomAutoTrack.addCartEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isSuccess:Boolean);
    LGCustomAutoTrack.loginEvent(method:String,isSuccess:Boolean);
    LGCustomAutoTrack.checkoutEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isVirtualCurrency:Boolean,virtualCurrency:String,currency:String,currencyAmount:int,isSuccess:Boolean);
    LGCustomAutoTrack.accessAccountEvent(type:String,isSuccess:Boolean);
    LGCustomAutoTrack.accessPaymentChannelEvent(channel:String,isSuccess:Boolean);
    LGCustomAutoTrack.questEvent(questId:String,questType:String,questName:String,questNumber:int,description:String,isSuccess:Boolean);
    LGCustomAutoTrack.addToFavouriteEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isSuccess:Boolean);
    LGCustomAutoTrack.updateLevelEvent(level:int);
    LGCustomAutoTrack.createGameRoleEvent(roleId:String);

### Initialize the SDK
 
    LGAdvert.starSDK("Your App ID","Your App Name","channel");

### rewardVideo
#### load

    delegate(optional)
    LGAdvert.getInstance().setRewardedVideoAdDidLoadListener(rewardVideoDidLoad);
    LGAdvert.getInstance().setRewardedVideoAdLoadFailListener(rewardVideoFailToLoad);
    LGAdvert.getInstance().setRewardedVideoAdVideoDidLoadListener(rewardVideoAdVideoDidLoad);
    LGAdvert.getInstance().setRewardedVideoAdWillVisibleListener(rewardVideoWillVisable);
    LGAdvert.getInstance().setRewardedVideoAdDidVisibleListener(rewardVideoDidVisable);
    LGAdvert.getInstance().setRewardedVideoAdWillCloseListener(rewardVideoWillClose);
    LGAdvert.getInstance().setRewardedVideoAdDidCloseListener(rewardVideoDidClose);
    LGAdvert.getInstance().setRewardedVideoAdDidClickListener(rewardVideoDidClick);
    LGAdvert.getInstance().setRewardedVideoAdDidPlayFinishFailListener(rewardVideoFinishPlay);
    LGAdvert.getInstance().setRewardedVideoAdServerRewardDidSucceedListener(rewardVideoRewardSuccess);
    
    function rewardVideoDidLoad():void{
		trace("rewardVideoDidLoad");
	}
    LGAdvert.loadRewardVideo("slotId","userId(optional)","rewardName(optional)","rewardAmount(optional)","extra(optional)");

#### show

    if(LGAdvert.isValidRewardVideo()){
		Boolean success = LGAdvert.showRewardVideo();
	}

### FullScreenVideo
#### load

    delegate(optional)
    LGAdvert.getInstance().setFullscreenVideoMaterialMetaAdDidLoadListener(FullscreenVideoMaterialMetaAdDidLoad);
	LGAdvert.getInstance().setFullscreenVideoAdFailToLoadListener(FullscreenVideoAdFailToLoad);
	LGAdvert.getInstance().setFullscreenVideoAdVideoDataDidLoadListener(FullscreenVideoAdVideoDataDidLoad);
	LGAdvert.getInstance().setFullscreenVideoAdWillVisibleListener(FullscreenVideoAdWillVisible);
	LGAdvert.getInstance().setFullscreenVideoAdDidVisibleListener(FullscreenVideoAdDidVisible);
	LGAdvert.getInstance().setFullscreenVideoAdDidClickListener(FullscreenVideoAdDidClick);
	LGAdvert.getInstance().setFullscreenVideoAdWillCloseListener(FullscreenVideoAdWillClose);
	LGAdvert.getInstance().setFullscreenVideoAdDidCloseListener(FullscreenVideoAdDidClose);
	LGAdvert.getInstance().setFullscreenVideoAdDidPlayFinishListener(FullscreenVideoAdDidPlayFinish);
	LGAdvert.getInstance().setFullscreenVideoAdDidClickSkipListener(FullscreenVideoAdDidClickSkip);

    LGAdvert.loadFullScreenVideo("slotId");

#### show
    if(LGAdvert.isValidFullScreenVideo()){
		Boolean success = LGAdvert.showFullScreenVideo();
    }

### nativeExpressRewardedVideo
#### load

	delegate(optional)
    LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidLoadListener(NativeExpressRewardedVideoAdDidLoad);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdFailToLoadListener(NativeExpressRewardedVideoAdFailToLoad);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdCallbackListener(NativeExpressRewardedVideoAdCallback);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidDownLoadVideoListener(NativeExpressRewardedVideoAdDidDownLoadVideo);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdViewRenderSuccessListener(NativeExpressRewardedVideoAdViewRenderSuccess);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdViewRenderFailListener(NativeExpressRewardedVideoAdViewRenderFail);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdWillVisibleListener(NativeExpressRewardedVideoAdWillVisible);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidVisibleListener(NativeExpressRewardedVideoAdDidVisible);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdWillCloseListener(NativeExpressRewardedVideoAdWillClose);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidCloseListener(NativeExpressRewardedVideoAdDidClose);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidClickListener(NativeExpressRewardedVideoAdDidClick);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidClickSkipListener(NativeExpressRewardedVideoAdDidClickSkip);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidPlayFinishListener(NativeExpressRewardedVideoAdDidPlayFinish);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdServerRewardDidSucceedListener(NativeExpressRewardedVideoAdServerRewardDidSucceed);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdServerRewardDidFailListener(NativeExpressRewardedVideoAdServerRewardDidFail);
	LGAdvert.getInstance().setNativeExpressRewardedVideoAdDidCloseOtherControllerListener(NativeExpressRewardedVideoAdDidCloseOtherController);
    
    LGAdvert.loadNativeExpressRewardVideo("slotId","userId(optional)","rewardName(optional)","rewardAmount(optional)","extra(optional)");

#### show
    if(LGAdvert.isValidNativeExpressRewardVideo()){
		Boolean success = LGAdvert.showNativeExpressRewardVideo();
	}

### nativeExpressFullScreenVideo
#### load
    delegate(optional)
    LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidLoadListener(NativeExpressFullScreenVideoAdDidLoad);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdFailToLoadListener(NativeExpressFullScreenVideoAdFailToLoad);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdViewRenderSuccessListener(NativeExpressFullScreenVideoAdViewRenderSuccess);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdViewRenderFailListener(NativeExpressFullScreenVideoAdViewRenderFail);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidDownLoadVideoListener(NativeExpressFullScreenVideoAdDidDownLoadVideo);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdWillVisibleListener(NativeExpressFullScreenVideoAdWillVisible);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidVisibleListener(NativeExpressFullScreenVideoAdDidVisible);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidClickListener(NativeExpressFullScreenVideoAdDidClick);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidClickSkipListener(NativeExpressFullScreenVideoAdDidClickSkip);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdWillCloseListener(NativeExpressFullScreenVideoAdWillClose);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidCloseListener(NativeExpressFullScreenVideoAdDidClose);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidPlayFinishFailListener(NativeExpressFullScreenVideoAdDidPlayFinishFail);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdCallbackListener(NativeExpressFullScreenVideoAdCallback);
	LGAdvert.getInstance().setNativeExpressFullScreenVideoAdDidCloseOtherControllerListener(NativeExpressFullScreenVideoAdDidCloseOtherController);

    LGAdvert.loadNativeExpressFullScreenVideo("slotId");

#### show
    if(LGAdvert.isValidNativeExpressFullScreenVideo()){
		Boolean success = LGAdvert.showNativeExpressFullScreenVideo();
	}
