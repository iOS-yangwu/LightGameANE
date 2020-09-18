package com.LightGame.ane
{
	
	import com.LightGame.utils.LGFunctions;
	import com.LightGame.utils.LGPrivateConst;
	import flash.display.MovieClip;
	import flash.events.IEventDispatcher;
	import flash.events.StatusEvent;
	import flash.external.ExtensionContext;
	import flash.system.Capabilities;


	public class LGAdvert extends MovieClip implements IEventDispatcher
	{
		internal static var EXTENSION_ID:String = "com.lightGame.ane";
		internal var extContext:ExtensionContext = null;
		internal static var instance:LGAdvert;


		///================ set delegate ================
		//rewardVideo
		private var rewardedVideoAdDidLoadListener:Function;
		private var rewardedVideoAdLoadFailListener:Function;
		private var rewardedVideoAdVideoDidLoadListener:Function;
		private var rewardedVideoAdWillVisibleListener:Function;
		private var rewardedVideoAdDidVisibleListener:Function;
		private var rewardedVideoAdWillCloseListener:Function;
		private var rewardedVideoAdDidCloseListener:Function;
		private var rewardedVideoAdDidClickListener:Function;
		private var rewardedVideoAdDidPlayFinishFailListener:Function;
		private var rewardedVideoAdServerRewardDidSucceedListener:Function;
		private var rewardedVideoAdServerRewardDidFailListener:Function;
		private var rewardedVideoAdDidClickSkipListener:Function;

		//nativeExpressRewardedVideo
		private var nativeExpressRewardedVideoAdDidLoadListener:Function;
		private var nativeExpressRewardedVideoAdFailToLoadListener:Function;
		private var nativeExpressRewardedVideoAdCallbackListener:Function;
		private var nativeExpressRewardedVideoAdDidDownLoadVideoListener:Function;
		private var nativeExpressRewardedVideoAdViewRenderSuccessListener:Function;
		private var nativeExpressRewardedVideoAdViewRenderFailListener:Function;
		private var nativeExpressRewardedVideoAdWillVisibleListener:Function;
		private var nativeExpressRewardedVideoAdDidVisibleListener:Function;
		private var nativeExpressRewardedVideoAdWillCloseListener:Function;
		private var nativeExpressRewardedVideoAdDidCloseListener:Function;
		private var nativeExpressRewardedVideoAdDidClickListener:Function;
		private var nativeExpressRewardedVideoAdDidClickSkipListener:Function;
		private var nativeExpressRewardedVideoAdDidPlayFinishFailListener:Function;
		private var nativeExpressRewardedVideoAdServerRewardDidSucceedListener:Function;
		private var nativeExpressRewardedVideoAdServerRewardDidFailListener:Function;
		private var nativeExpressRewardedVideoAdDidCloseOtherControllerListener:Function;

		//fullscreenVideo
		private var fullscreenVideoMaterialMetaAdDidLoadListener:Function;
		private var fullscreenVideoAdFailToLoadListener:Function;
		private var fullscreenVideoAdVideoDataDidLoadListener:Function;
		private var fullscreenVideoAdWillVisibleListener:Function;
		private var fullscreenVideoAdDidVisibleListener:Function;
		private var fullscreenVideoAdDidClickListener:Function;
		private var fullscreenVideoAdWillCloseListener:Function;
		private var fullscreenVideoAdDidCloseListener:Function;
		private var fullscreenVideoAdDidPlayFinishFailListener:Function;
		private var fullscreenVideoAdDidClickSkipListener:Function;

		//nativeExpressFullscreenVideo
		private var nativeExpressFullscreenVideoAdDidLoadListener:Function;
		private var nativeExpressFullscreenVideoAdFailToLoadListener:Function;
		private var nativeExpressFullscreenVideoAdViewRenderSuccessListener:Function;
		private var nativeExpressFullscreenVideoAdViewRenderFailListener:Function;
		private var nativeExpressFullscreenVideoAdDidDownLoadVideoListener:Function;
		private var nativeExpressFullscreenVideoAdWillVisibleListener:Function;
		private var nativeExpressFullscreenVideoAdDidVisibleListener:Function;
		private var nativeExpressFullscreenVideoAdDidClickListener:Function;
		private var nativeExpressFullscreenVideoAdDidClickSkipListener:Function;
		private var nativeExpressFullscreenVideoAdWillCloseListener:Function;
		private var nativeExpressFullscreenVideoAdDidCloseListener:Function;
		private var nativeExpressFullscreenVideoAdDidPlayFinishFailListener:Function;
		private var nativeExpressFullscreenVideoAdCallbackListener:Function;
		private var nativeExpressFullscreenVideoAdDidCloseOtherControllerListener:Function;


//		private var _main:MovieClip = null;


		private static function _isIOS():Boolean {
			return Capabilities.manufacturer.indexOf("iOS") > -1 && Capabilities.os.indexOf("x86_64") < 0 && Capabilities.os.indexOf("i386") < 0;
		}

		private static function _isAndroid():Boolean {

			return Capabilities.manufacturer.indexOf("Android") > -1;
		}

		//rewardVideo
		public function setRewardedVideoAdDidLoadListener(listener:Function):void{
			this.rewardedVideoAdDidLoadListener = listener;
		}
		
		public function setRewardedVideoAdLoadFailListener(listener:Function):void{
			this.rewardedVideoAdLoadFailListener = listener;
		}
		
		public function setRewardedVideoAdVideoDidLoadListener(listener:Function):void{
			this.rewardedVideoAdVideoDidLoadListener = listener;
		}
		
		public function setRewardedVideoAdWillVisibleListener(listener:Function):void{
			this.rewardedVideoAdWillVisibleListener = listener;
		}
		
		public function setRewardedVideoAdDidVisibleListener(listener:Function):void{
			this.rewardedVideoAdDidVisibleListener = listener;
		}
		
		public function setRewardedVideoAdWillCloseListener(listener:Function):void{
			this.rewardedVideoAdWillCloseListener = listener;
		}
		
		public function setRewardedVideoAdDidCloseListener(listener:Function):void{
			this.rewardedVideoAdDidCloseListener = listener;
		}
		
		public function setRewardedVideoAdDidClickListener(listener:Function):void{
			
			this.rewardedVideoAdDidClickListener = listener;
		}
		
		public function setRewardedVideoAdDidPlayFinishFailListener(listener:Function):void{
			this.rewardedVideoAdDidPlayFinishFailListener = listener;
		}
		
		public function setRewardedVideoAdServerRewardDidSucceedListener(listener:Function):void{
			this.rewardedVideoAdServerRewardDidSucceedListener = listener;
			
		}
		
		public function setRewardedVideoAdServerRewardDidFailListener(listener:Function):void{
			this.rewardedVideoAdServerRewardDidFailListener = listener;
			
		}
		
		public function setRewardedVideoAdDidClickSkipListener(listener:Function):void {
			this.rewardedVideoAdDidClickSkipListener = listener;
		}

		//nativeExpressRewardedVideo
		public function setNativeExpressRewardedVideoAdDidLoadListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidLoadListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdFailToLoadListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdFailToLoadListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdCallbackListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdCallbackListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdDidDownLoadVideoListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidDownLoadVideoListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdViewRenderSuccessListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdViewRenderSuccessListener = listener;
		}

		public function setNativeExpressRewardedVideoAdViewRenderFailListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdViewRenderFailListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdWillVisibleListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdWillVisibleListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidVisibleListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidVisibleListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdWillCloseListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdWillCloseListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdDidCloseListenerVideoDidLoadListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidCloseListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidClickListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidClickListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidClickSkipListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidClickSkipListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdDidPlayFinishFailListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidPlayFinishFailListener = listener;
		}

		public function setNativeExpressRewardedVideoAdServerRewardDidSucceedListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdServerRewardDidSucceedListener = listener;
		}
		
		public function setNativeExpressRewardedVideoAdServerRewardDidFailListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdServerRewardDidFailListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidCloseOtherControllerListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidCloseOtherControllerListener = listener;
		}

		///fullscreenVideo
		public function setFullscreenVideoMaterialMetaAdDidLoadListener(listener:Function):void {
			this.fullscreenVideoMaterialMetaAdDidLoadListener = listener;
		}
		public function setFullscreenVideoAdFailToLoadListener(listener:Function):void{
			this.fullscreenVideoAdFailToLoadListener = listener;
		}

		public function setFullscreenVideoAdVideoDataDidLoadListener(listener:Function):void{
			this.fullscreenVideoAdVideoDataDidLoadListener = listener;
		}
		
		public function setFullscreenVideoAdWillVisibleListener(listener:Function):void{
			this.fullscreenVideoAdWillVisibleListener = listener;
		}
		
		public function setFullscreenVideoAdDidVisibleListener(listener:Function):void{
			this.fullscreenVideoAdDidVisibleListener = listener;
		}
		
		public function setFullscreenVideoAdDidClickListener(listener:Function):void{
			this.fullscreenVideoAdDidClickListener = listener;
		}
		
		public function setFullscreenVideoAdDidCloseListener(listener:Function):void{
			this.fullscreenVideoAdDidCloseListener = listener;
		}

		public function setFullscreenVideoAdDidPlayFinishFailListener(listener:Function):void{
			this.fullscreenVideoAdDidPlayFinishFailListener = listener;
		}

		public function setFullscreenVideoAdDidClickSkipListener(listener:Function):void{
			this.fullscreenVideoAdDidClickSkipListener = listener;
		}

		//nativeExpressFullscreenVideo
		public function setNativeExpressFullscreenVideoAdDidLoadListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidLoadListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdFailToLoadListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdFailToLoadListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdViewRenderSuccessListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdViewRenderSuccessListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdViewRenderFailListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdViewRenderFailListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidDownLoadVideoListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidDownLoadVideoListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdWillVisibleListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdWillVisibleListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidVisibleListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidVisibleListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidClickListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidClickListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidClickSkipListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidClickSkipListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdWillCloseListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdWillCloseListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidCloseListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidCloseListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidPlayFinishFailListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidPlayFinishFailListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdCallbackListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdCallbackListener = listener;
		}

		public function setNativeExpressFullscreenVideoAdDidCloseOtherControllerListener(listener:Function):void{
			this.nativeExpressFullscreenVideoAdDidCloseOtherControllerListener = listener;
		}


		///================ sdk config ================
		/**
		 * @brief  深度转化配置
		 */
		public static function setBDConfig(serviceVendor:int,autoTrackEnabled:Boolean,showDebugLog:Boolean,logNeedEncrypt:Boolean,userUniqueID:String,language:String,abServerVersions:String,customHeaderBlock:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.SET_DBCONFIG,serviceVendor,autoTrackEnabled,showDebugLog,logNeedEncrypt,userUniqueID,language,abServerVersions,customHeaderBlock);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-setBDConfig-Not a Android/iOS module");
			}
		}


		/**
		 * @brief  init sdk
		 */
		public static function starSDK(appId:String,appName:String,channel:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.INIT_SDK,appId,appName,channel);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-starSDK-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief isDebugLog
		 */
		public static function isDebugLog(isDebugLog:Boolean):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.ISDEBUGLOG,isDebugLog);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-isDebugLog-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief debugType
		 */
		public static function debugType(type:int):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.DEBUGTYPE,type);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-debugType-Not a Android/iOS module");
			}
		}

		/**
		 * @brief lightGame sdk version
		 */
		public static function getLightGameVersion():String{
			if (_isIOS()){

				var sdkVersion:String = String(LGAdvert.getInstance().extContext.call(LGFunctions.LG_SDK_VERSION));
				return sdkVersion;

			}else if (_isAndroid()){

				return "nil";

			}else{

				trace("LG-Function-getLightGameVersion-Not a Android/iOS module");
				return "nil";
			}
		}
		
		/**
		 *  @brief setCurrentUserUniqueID
		 */
		public static function setCurrentUserUniqueID(uniqueID:String):void{
			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.SET_CURRENT_USER_ID,uniqueID);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-setCurrentUserUniqueID-Not a Android/iOS module");
			}
		}

		/**
		 *  @brief setCustomHeaderBlock
		 */
		public static function setCustomHeaderBlock(JSONString:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.SET_CUSTOM_HEADER,JSONString);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-setCustomHeaderBlock-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief clearUserUniqueId
		 */
		public static function clearUserUniqueId():void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.CLEAR_USER_UNIQUE_ID);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-clearUserUniqueId-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief setABSDKVersions
		 */
		public static function setABSDKVersions(version:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.SET_ABSDK_VERSION,version);

			}else if (_isAndroid()){


			}else{

				trace("LG-Function-setABSDKVersions-Not a Android/iOS module");
			}
		}

		/**
		 * @brief getABSDKVersions
		 */
		public static function getABSDKVersions():String{

			if (_isIOS()){
				var ABSDKVersion:String = String(LGAdvert.getInstance().extContext.call(LGFunctions.GET_ABSDK_VERSION));
				return ABSDKVersion;

			}else if (_isAndroid()){

				return "";

			}else{

				trace("LG-Function-getABSDKVersions-Not a Android/iOS module");
				return "";
			}
		}

		/**
		 * @brief lg_event
		 */
		public static function lg_event(event:String,paras:String):void{

			if (_isIOS()){

				 LGAdvert.getInstance().extContext.call(LGFunctions.LG_EVENT,event,paras);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-lg_event-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief ABTestConfig
		 */
		public static function ABTestConfig(key:String,defaultValue:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.ABTESTCONFIG,key,defaultValue);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-ABTestConfig-Not a Android/iOS module");
			}
		}

		///================ rewardVideo ================
		/**
		 * @brief loadRewardVideo
		 */
		public static function loadRewardVideo(slotId:String,userId:String,rewardName:String,rewardAmount:String,extra:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.VIDEO_LOAD,slotId,userId,rewardName,rewardAmount,extra);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-loadRewardVideo-Not a Android/iOS module");

			}
		}
		
		/**
		 * @brief isValid
		 */
		public static function isValidRewardVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.VIDEO_ISVALID);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-rewardVideoIsValid-Not a Android/iOS module");
				return false;
			}
		}
		
		/**
		 * @brief showRewardVideo
		 */
		public static function showRewardVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.VIDEO_SHOW);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showRewardVideo-Not a Android/iOS module");
				return false;
			}
		}
		
		/**
		 * @brief showRewardVideoFromScene
		 */
		public static function showRewardVideoFromScene(ritScene:int,ritSceneDesc:String):Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.VIDEO_SHOW_SCENE);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showRewardVideoFromScene-Not a Android/iOS module");
				return false;
			}
		}

		///================ nativeExpressRewardVideo ================

		/**
		 * @brief loadNativeExpressRewardVideo
		 */
		public static function loadNativeExpressRewardVideo(slotId:String,userId:String,rewardName:String,rewardAmount:String,extra:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_VIDEO_LOAD,slotId,userId,rewardName,rewardAmount,extra);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-loadNativeExpressRewardVideo-Not a Android/iOS module");

			}
		}
		
		/**
		 * @brief isValidNativeExpressRewardVideo
		 */
		public static function isValidNativeExpressRewardVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_VIDEO_ISVALID);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-isValidNativeExpressRewardVideo-Not a Android/iOS module");
				return false;
			}
		}
		
		/**
		 * @brief showNativeExpressRewardVideo
		 */
		public static function showNativeExpressRewardVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_VIDEO_SHOW);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showNativeExpressRewardVideo-Not a Android/iOS module");
				return false;
			}
		}
		
		/**
		 * @brief showNativeExpressRewardVideoFromScene
		 */
		public static function showNativeExpressRewardVideoFromScene(ritScene:int,ritSceneDesc:String):Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_VIDEO_SHOW_SCENE,ritScene,ritSceneDesc);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showNativeExpressRewardVideoFromScene-Not a Android/iOS module");
				return false;
			}
		}


		///================ fullScreenRewardVideo ================
		/**
		 * @brief loadFullScreenVideo
		 */
		public static function loadFullScreenVideo(slotId:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.FULL_SCREEN_VIDEO_LOAD,slotId);

			}else if (_isAndroid()){


			}else{

				trace("LG-Function-loadFullScreenVideo-Not a Android/iOS module");
			}
		}

		/**
		 * @brief isValidFullScreenVideo
		 */
		
		public static function isValidFullScreenVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.FULL_SCREEN_VIDEO_ISVALID);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-isValidFullScreenVideo-Not a Android/iOS module");
				return false;
			}
		}
		/**
		 * @brief showFullScreenVideo
		 */
		public static function showFullScreenVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.FULL_SCREEN_VIDEO_SHOW);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-showFullScreenVideo-Not a Android/iOS module");
			}
		}
		
		/**
		 * @brief showFullScreenVideoFromScene
		 */
		public static function showFullScreenVideoFromScene(ritSceneDesc:String):Boolean{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.FULL_SCREEN_VIDEO_SHOW_SCENE,ritSceneDesc);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-showFullScreenVideoFromScene-Not a Android/iOS module");
			}
		}


		public static function showSplash(iap:String,dispatchTime:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.JOYPAC_SPLASH_SHOW,iap,dispatchTime);

			}else if (_isAndroid()){

				//

			}else{

				trace("Joypac-Function-showSplash-Not a Android/iOS module");

			}
		}
		
		/**
		 * isreadyIV
		 */
		public static function isPrepareInterstital():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.JOYPAC_JPCISREADY_IV);

			}else if (_isAndroid()){

				//
				return false;

			}else{

				trace("Joypac-Function-isPrepareInterstital-Not a Android/iOS module");
				return false;
			}
		}

		/**
		 * eventLog
		 */

		 public static function joypacEventLog(eventSort:String,eventType:String,eventPosition:String,eventExtra:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.JOYPAC_EVENT_LOG,eventSort,eventType,eventPosition,eventExtra);

			}else if (_isAndroid()){

				//

			}else{


			}
		}
		
	
		private static var sFunctionTicker:int;
		private static var sFunctionMap:Object = new Object();
		public static function functionToString(name:String,f:Function,singleInstance:Boolean):String{
			if(singleInstance){
				sFunctionMap[name] = f;
				return f == null ? null : name;
			}else{
				var key:String = sFunctionTicker + "";
				sFunctionMap[key] = f;
				sFunctionTicker ++;
				return  f == null ? null : key; 
			}
		}
	

		public function nativeCallBack(e:StatusEvent):void {

			trace("Joypac SDK code:" + e.code + "  level:"+  e.level);

			var code:String = e.code;
			
			var json:String = e.level;

			var resp:Object = JSON.parse(json);
			
			var action:int = resp.what;

			var app_extra:String=resp.app_extra;
			trace("joypac onlinepara "+app_extra);

			switch(action){
				case LGPrivateConst.JoypacInterstitialClick:
				{
					if(this.interstitialClickListener != null){
						this.interstitialClickListener();
					}
				}
					break;
				case LGPrivateConst.JoypacInterstitialClose:
				{
					if(this.interstitialCloseListener != null){
						this.interstitialCloseListener();
					}
				}
					break;
				case LGPrivateConst.JoypacInterstitialDidLoad:
				{
					if(this.interstitialDidLoadListener != null){
						this.interstitialDidLoadListener();
					}
				}
					break;
				case LGPrivateConst.JoypacInterstitialLoadFail:
				{
					if(this.interstitialLoadFailListener != null){
						this.interstitialLoadFailListener();
					}
				}
					break;
				case LGPrivateConst.JoypacInterstitialShow:
				{
					if(this.interstitialShowListener != null){
						this.interstitialShowListener();
					}
				}
					
					break;
				case LGPrivateConst.JoypacInterstitialShowFail:
				{
					if(this.interstitialShowFailListener != null){
						this.interstitialShowFailListener();
					}
				}
					break;
				///==========video============
				case LGPrivateConst.JoypacVideoCilck:
				{
					if(this.videoClickListener != null){
						this.videoClickListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoClose:
				{
					if(this.videoCloseListener != null){
						this.videoCloseListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoDidLoad:
				{
					if(this.videoDidLoadListener != null){
						this.videoDidLoadListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoLoadFail:
				{
					if(this.videoLoadFailListener != null){
						this.videoLoadFailListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoRewardFail:
				{
					if(this.videoRewardFailListener != null){
						this.videoRewardFailListener();
					}
				}
					break;

				case LGPrivateConst.JoypacVideoRewardSuccess:
				{
					if(this.videoRewardSuccessListener != null){
						this.videoRewardSuccessListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoShow:
				{
					if(this.videoShowListener != null){
						this.videoShowListener();
					}
				}
					break;
				case LGPrivateConst.JoypacVideoShowFail:
				{
					if(this.videoShowFailListener != null){
						this.videoShowFailListener();
					}
				}
					break;
				// banner
				case LGPrivateConst.JoypacBannerClose:
				{
					if(this.bannerCloseListener != null){
						this.bannerCloseListener();
					}
				}
					break;
				case LGPrivateConst.JoypacBannerClick:{
					if(this.bannerClickListener != null){
						this.bannerClickListener();
					}
				
				}
					break;
				case LGPrivateConst.JoypacBannerDidLoad:
				{
					if(this.bannerDidLoadListener != null){
						this.bannerDidLoadListener();
					}
				}
					break;
				case LGPrivateConst.JoypacBannerDidShow:
				{
					if(this.bannerDidShowListener != null){
						this.bannerDidShowListener();
					}
				}
					break;
				case LGPrivateConst.JoypacBannerLoadFail:
				{
					if(this.bannerLoadFailListener != null){
						this.bannerLoadFailListener();
					}
				}
					break;
				
				//native
				case LGPrivateConst.JoypacNativeDidShow:
				{
					if(this.nativeDidShowListerner != null){
						this.nativeDidShowListerner();
					}
				}
					break;
				case LGPrivateConst.JoypacNativeLoadFail:
				{
					if(this.nativeLoadFailListerner != null){
						this.nativeLoadFailListerner();
					}
				}				
					break;
				case LGPrivateConst.JoypacNativeClick:
				{
					if(this.nativeClickListerner != null){
						this.nativeClickListerner();
					}
				}
					break;
				
				case LGPrivateConst.JoypacNativeStartPlay:
				{
					if(this.nativeStartPlayListerner != null){
						this.nativeStartPlayListerner();
					}
				}
					break;
				
				case LGPrivateConst.JoypacNativeEndPlay:
				{
					if(this.nativeEndPlayListerner != null){
						this.nativeEndPlayListerner();
					}
				}
					break;
				///MTG
				case LGPrivateConst.MTGInterActivAdsDidload:
				{
					if(this.MTGInterActiveDidLoadListerner !=null){
						this.MTGInterActiveDidLoadListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsLoadFail:
				{
					if(this.MTGInterActiveLoadFailListerner !=null){
						this.MTGInterActiveLoadFailListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsDidShow:
				{
					if(this.MTGInterActiveDidShowListerner !=null){
						this.MTGInterActiveDidShowListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsShowFail:
				{
					if(this.MTGInterActiveShowFailListerner !=null){
						this.MTGInterActiveShowFailListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsDidClick:
				{
					if(this.MTGInterActiveDidClickListerner !=null){
						this.MTGInterActiveDidClickListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsDidMiss:
				{
					if(this.MTGInterActiveDidMissListerner !=null){
						this.MTGInterActiveDidMissListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsDidCompleted:
				{
					if(this.MTGInterActiveDidCompletedListerner !=null){
						this.MTGInterActiveDidCompletedListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsRewardSuccess:
				{
					if(this.MTGInterActiveRewardSuccessListerner !=null){
						this.MTGInterActiveRewardSuccessListerner();
					}
				}
					break;
				case LGPrivateConst.MTGInterActivAdsRewardFail:
				{
					if(this.MTGInterActiveRewardFailListerner !=null){
						this.MTGInterActiveRewardFailListerner();
					}
				}
					break;
				///splash
				case LGPrivateConst.JoypacSplashDidClick:
				{
					if(this.splashDidClickListerner != null){
						this.splashDidClickListerner();
					}
				}
					break;
				
				case LGPrivateConst.JoypacSplashDidClose:
				{
					if(this.splashDidCloseListerner != null){
						this.splashDidCloseListerner();
					}
				}
					break;
				
				case LGPrivateConst.JoypacSplashDidShow:
				{
					if(this.splashDidShowListerner != null){
						this.splashDidShowListerner();
					}
				}
					break;
				case LGPrivateConst.XCodeSendSixty:
				{
					trace("receivedXcodeMessageBeforeXCodeSendSixty",stage.frameRate);
					if(!this._main){
						return;
					}				
					this._main["ActiveGame"]();
					trace("endframerate"+stage.frameRate+"fps"+this._main['fps']+"chudan"+this._main["chudanFlg"]);
					if(this.xcodeDidSendSixtyListerner !=null){
						this.xcodeDidSendSixtyListerner();
					}
				}
					break;
				case LGPrivateConst.XCodeSendZero:
				{
					trace("wy 开始循环"+this._main);
					if (!this._main) {
						trace("wy--循环内部"+this._main);
						return
					}
					trace("beforeframerate"+stage.frameRate+"fps"+this._main['fps']+"chudan"+this._main["chudanFlg"]);
					//					this._main['fps'] = 500;
					this._main["StopGame"]();
					LGAdvert.getInstance().extContext.call(LGFunctions.JOYPAC_STOP_DISPLAYLINK);

					trace("afterframerate"+stage.frameRate+"fps"+this._main['fps']+"chudan"+this._main["chudanFlg"]);
					if(this.xcodeDidSendZeroListerner !=null){
						this.xcodeDidSendZeroListerner();
					}
				}
					break;
				case LGPrivateConst.JoypacOnlinePara:{
					if(this.ReceiveSettingDataListerner!=null){

						this.ReceiveSettingDataListerner(app_extra);
					}
				}
				 break;
			}
		} 
		public function LGAdvert(){
			if (!extContext) {
				extContext = ExtensionContext.createExtensionContext(EXTENSION_ID, null);
				if(extContext == null){
					trace("Joypac createExtensionContext error");
				}
				extContext.addEventListener( StatusEvent.STATUS, nativeCallBack);
			}   
		}
		
		public static function getInstance():LGAdvert {
			if(instance == null)
				instance = new LGAdvert();
			return instance;
		}
		
		public  function setMain(main:MovieClip):void {
			trace("before获取main函数"+ main);
		 	this._main = main;		
		}
	}
}