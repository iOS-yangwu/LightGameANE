package com.LightGame.ane
{
	
	import com.LightGame.utils.LGFunctions;
	import com.LightGame.utils.LGPrivateConst;
	import flash.display.MovieClip;
	import flash.events.IEventDispatcher;
	import flash.events.StatusEvent;
	import flash.external.ExtensionContext;
	import flash.media.SoundLoaderContext;
	import flash.system.Capabilities;


	public class LGAdvert extends MovieClip implements IEventDispatcher
	{
		internal static var EXTENSION_ID:String = "com.lightGame.ane";
		internal var extContext:ExtensionContext = null;
		internal static var instance:LGAdvert;


		///================ set delegate ================
		// sdk
		private var BDConfigRegisterFinishBlockListener:Function;
		private var BDConfigABTestFinishBlockListener:Function;

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
		private var nativeExpressRewardedVideoAdDidPlayFinishListener:Function;
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
		private var fullscreenVideoAdDidPlayFinishListener:Function;
		private var fullscreenVideoAdDidClickSkipListener:Function;

		//nativeExpressFullscreenVideo
		private var nativeExpressFullScreenVideoAdDidLoadListener:Function;
		private var nativeExpressFullScreenVideoAdFailToLoadListener:Function;
		private var nativeExpressFullScreenVideoAdViewRenderSuccessListener:Function;
		private var nativeExpressFullScreenVideoAdViewRenderFailListener:Function;
		private var nativeExpressFullScreenVideoAdDidDownLoadVideoListener:Function;
		private var nativeExpressFullScreenVideoAdWillVisibleListener:Function;
		private var nativeExpressFullScreenVideoAdDidVisibleListener:Function;
		private var nativeExpressFullScreenVideoAdDidClickListener:Function;
		private var nativeExpressFullScreenVideoAdDidClickSkipListener:Function;
		private var nativeExpressFullScreenVideoAdWillCloseListener:Function;
		private var nativeExpressFullScreenVideoAdDidCloseListener:Function;
		private var nativeExpressFullScreenVideoAdDidPlayFinishListener:Function;
		private var nativeExpressFullScreenVideoAdCallbackListener:Function;
		private var nativeExpressFullScreenVideoAdDidCloseOtherControllerListener:Function;


		private var _main:MovieClip = null;

		//sdk
		public  function  setBDConfigRegisterFinishBlockListener(listener:Function):void{
			this.BDConfigRegisterFinishBlockListener = listener;
		}

		public  function  setBDConfigABTestFinishBlockListener(listener:Function):void{
			this.BDConfigABTestFinishBlockListener = listener;
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

		public function setNativeExpressRewardedVideoAdDidCloseListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidCloseListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidClickListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidClickListener = listener;
		}
		public function setNativeExpressRewardedVideoAdDidClickSkipListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidClickSkipListener = listener;
		}

		public function setNativeExpressRewardedVideoAdDidPlayFinishListener(listener:Function):void {
			this.nativeExpressRewardedVideoAdDidPlayFinishListener = listener;
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

		public function setFullscreenVideoAdWillCloseListener(listener:Function):void{
			this.fullscreenVideoAdWillCloseListener = listener;
		}

		public function setFullscreenVideoAdDidCloseListener(listener:Function):void{
			this.fullscreenVideoAdDidCloseListener = listener;
		}

		public function setFullscreenVideoAdDidPlayFinishListener(listener:Function):void{
			this.fullscreenVideoAdDidPlayFinishListener = listener;
		}

		public function setFullscreenVideoAdDidClickSkipListener(listener:Function):void{
			this.fullscreenVideoAdDidClickSkipListener = listener;
		}

		//nativeExpressFullscreenVideo
		public function setNativeExpressFullScreenVideoAdDidLoadListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidLoadListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdFailToLoadListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdFailToLoadListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdViewRenderSuccessListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdViewRenderSuccessListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdViewRenderFailListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdViewRenderFailListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidDownLoadVideoListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidDownLoadVideoListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdWillVisibleListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdWillVisibleListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidVisibleListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidVisibleListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidClickListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidClickListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidClickSkipListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidClickSkipListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdWillCloseListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdWillCloseListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidCloseListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidCloseListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidPlayFinishFailListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidPlayFinishListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdCallbackListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdCallbackListener = listener;
		}

		public function setNativeExpressFullScreenVideoAdDidCloseOtherControllerListener(listener:Function):void{
			this.nativeExpressFullScreenVideoAdDidCloseOtherControllerListener = listener;
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

				return false;
			}else{

				trace("LG-Function-showFullScreenVideo-Not a Android/iOS module");
				return false;
			}
		}

		/**
		 * @brief showFullScreenVideoFromScene
		 */
		public static function showFullScreenVideoFromScene(ritSceneDesc:String):Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.FULL_SCREEN_VIDEO_SHOW_SCENE,ritSceneDesc);

			}else if (_isAndroid()){

				return false;
			}else{

				trace("LG-Function-showFullScreenVideoFromScene-Not a Android/iOS module");
				return false;
			}
		}


		///================ nativeExpressFullScreenVideo ================

		/**
		 * @brief loadNativeExpressFullScreenVideo
		 */
		public static function loadNativeExpressFullScreenVideo(slotId:String):void{

			if (_isIOS()){

				LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_FULL_SCREEN_LOAD,slotId);

			}else if (_isAndroid()){

			}else{

				trace("LG-Function-loadNativeExpressFullScreenVideo-Not a Android/iOS module");

			}
		}

		/**
		 *@brief isValidNativeExpressFullScreenVideo
		 */
		public static function isValidNativeExpressFullScreenVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_FULL_SCREEN_ISVALID);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-isValidNativeExpressFullScreenVideo-Not a Android/iOS module");
				return false;
			}
		}

		/**
		 *@brief showNativeExpressFullScreenVideo
		 */
		 public static function showNativeExpressFullScreenVideo():Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_FULL_SCREEN_SHOW);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showValidNativeExpressFullScreenVideo-Not a Android/iOS module");
				return false;
			}
		}

		/**
		 *@brief showNativeExpressFullScreenVideoFromScene
		 */
		public static function showNativeExpressFullScreenVideoFromScene(ritSceneDesc:String):Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE,ritSceneDesc);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showNativeExpressFullScreenVideoFromScene-Not a Android/iOS module");
				return false;
			}
		}


		///================ customAutoTrack ================
		public static function registerEventByMethod(ritSceneDesc:String):Boolean{

			if (_isIOS()){

				return LGAdvert.getInstance().extContext.call(LGFunctions.NATIVE_EXPRESS_FULL_SCREEN_SHOW_SCENE,ritSceneDesc);

			}else if (_isAndroid()){

				return false;

			}else{

				trace("LG-Function-showNativeExpressFullScreenVideoFromScene-Not a Android/iOS module");
				return false;
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

			trace("LG SDK code:" + e.code + "  level:"+  e.level);

			var code:String = e.code;

			var json:String = e.level;

			var resp:Object = JSON.parse(json);

			var action:int = resp.what;

			var verify:String=resp.verify;

			switch(action){
				case LGPrivateConst.BDConfigRegisterFinishBlock:
				{
					if(this.BDConfigRegisterFinishBlockListener != null){
						this.BDConfigRegisterFinishBlockListener();
					}
				}
					break;

				case LGPrivateConst.BDConfigABTestFinishBlock:
				{
					if(this.BDConfigABTestFinishBlockListener != null){
						this.BDConfigABTestFinishBlockListener();
					}
				}
					break;

				case LGPrivateConst.RVDidLoad:
				{
					if(this.rewardedVideoAdDidLoadListener != null){
						this.rewardedVideoAdDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.RVFailToLoad:
				{
					if(this.rewardedVideoAdLoadFailListener != null){
						this.rewardedVideoAdLoadFailListener();
					}
				}
					break;

				case LGPrivateConst.RVVideoDidLoad:
				{
					if(this.rewardedVideoAdDidLoadListener != null){
						this.rewardedVideoAdDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.RVWillVisible:
				{
					if(this.rewardedVideoAdWillVisibleListener != null){
						this.rewardedVideoAdWillVisibleListener();
					}
				}
					break;

				case LGPrivateConst.RVDidVisible:
				{
					if(this.rewardedVideoAdDidVisibleListener != null){
						this.rewardedVideoAdDidVisibleListener();
					}
				}
					break;

				case LGPrivateConst.RVWillClose:
				{
					if(this.rewardedVideoAdWillCloseListener != null){
						this.rewardedVideoAdWillCloseListener();
					}
				}
					break;

				case LGPrivateConst.RVDidClose:
				{
					if(this.rewardedVideoAdDidCloseListener != null){
						this.rewardedVideoAdDidCloseListener();
					}
				}
					break;

				case LGPrivateConst.RVDidClick:
				{
					if(this.rewardedVideoAdDidClickListener != null){
						this.rewardedVideoAdDidClickListener();
					}
				}
					break;

				case LGPrivateConst.RVDidPlayFinish:
				{
					if(this.rewardedVideoAdDidPlayFinishFailListener != null){
						this.rewardedVideoAdDidPlayFinishFailListener();
					}
				}
					break;

				case LGPrivateConst.RVServerRewardDidSucceed:
				{
					if(this.rewardedVideoAdServerRewardDidSucceedListener != null){
						this.rewardedVideoAdServerRewardDidSucceedListener(verify);
					}
				}
					break;
				case LGPrivateConst.RVServerRewardDidFail:
				{
					if(this.rewardedVideoAdServerRewardDidFailListener != null){
						this.rewardedVideoAdServerRewardDidFailListener();
					}
				}
					break;

				case LGPrivateConst.RVDidClickSkip:
				{
					if(this.rewardedVideoAdDidClickSkipListener != null){
						this.rewardedVideoAdDidClickSkipListener();
					}
				}
					break;

				// nativeExpressRV
				case LGPrivateConst.NERVDidLoad:
				{
					if(this.nativeExpressRewardedVideoAdDidLoadListener != null){
						this.nativeExpressRewardedVideoAdDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.NERVFailToLoad:{
					if(this.nativeExpressRewardedVideoAdFailToLoadListener != null){
						this.nativeExpressRewardedVideoAdFailToLoadListener();
					}

				}
					break;

				case LGPrivateConst.NERVCallback:
				{
					if(this.nativeExpressRewardedVideoAdCallbackListener != null){
						this.nativeExpressRewardedVideoAdCallbackListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidDownLoadVideo:
				{
					if(this.nativeExpressRewardedVideoAdDidDownLoadVideoListener != null){
						this.nativeExpressRewardedVideoAdDidDownLoadVideoListener();
					}
				}
					break;

				case LGPrivateConst.NERVViewRenderSuccess:
				{
					if(this.nativeExpressRewardedVideoAdViewRenderSuccessListener != null){
						this.nativeExpressRewardedVideoAdViewRenderSuccessListener();
					}
				}
					break;

				case LGPrivateConst.NERVViewRenderFail:
				{
					if(this.nativeExpressRewardedVideoAdViewRenderFailListener != null){
						this.nativeExpressRewardedVideoAdViewRenderFailListener();
					}
				}
					break;

				case LGPrivateConst.NERVWillVisible:
				{
					if(this.nativeExpressRewardedVideoAdWillVisibleListener != null){
						this.nativeExpressRewardedVideoAdWillVisibleListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidVisible:
				{
					if(this.nativeExpressRewardedVideoAdDidVisibleListener != null){
						this.nativeExpressRewardedVideoAdDidVisibleListener();
					}
				}
					break;

				case LGPrivateConst.NERVWillClose:
				{
					if(this.nativeExpressRewardedVideoAdWillCloseListener != null){
						this.nativeExpressRewardedVideoAdWillCloseListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidClose:
				{
					if(this.nativeExpressRewardedVideoAdDidCloseListener != null){
						this.nativeExpressRewardedVideoAdDidCloseListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidClick:
				{
					if(this.nativeExpressRewardedVideoAdDidClickListener !=null){
						this.nativeExpressRewardedVideoAdDidClickListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidClickSkip:
				{
					if(this.nativeExpressRewardedVideoAdDidClickSkipListener !=null){
						this.nativeExpressRewardedVideoAdDidClickSkipListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidPlayFinish:
				{
					if(this.nativeExpressRewardedVideoAdDidPlayFinishListener !=null){
						this.nativeExpressRewardedVideoAdDidPlayFinishListener();
					}
				}
					break;

				case LGPrivateConst.NERVServerRewardDidSucceed:
				{
					if(this.nativeExpressRewardedVideoAdServerRewardDidSucceedListener !=null){
						this.nativeExpressRewardedVideoAdServerRewardDidSucceedListener(verify);
					}
				}
					break;

				case LGPrivateConst.NERVServerRewardDidFail:
				{
					if(this.nativeExpressRewardedVideoAdServerRewardDidFailListener !=null){
						this.nativeExpressRewardedVideoAdServerRewardDidFailListener();
					}
				}
					break;

				case LGPrivateConst.NERVDidCloseOtherController:
				{
					if(this.nativeExpressRewardedVideoAdDidCloseOtherControllerListener !=null){
						this.nativeExpressRewardedVideoAdDidCloseOtherControllerListener();
					}
				}
					break;

				//fullScreenVideo
				case LGPrivateConst.FSVMateDidLoad:
				{
					if(this.fullscreenVideoMaterialMetaAdDidLoadListener !=null){
						this.fullscreenVideoMaterialMetaAdDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.FSVMateFailToLoad:
				{
					if(this.fullscreenVideoAdFailToLoadListener !=null){
						this.fullscreenVideoAdFailToLoadListener();
					}
				}
					break;

				case LGPrivateConst.FSVDataDidLoad:
				{
					if(this.fullscreenVideoAdVideoDataDidLoadListener !=null){
						this.fullscreenVideoAdVideoDataDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.FSVWillVisible:
				{
					if(this.fullscreenVideoAdWillVisibleListener != null){
						this.fullscreenVideoAdWillVisibleListener();
					}
				}
					break;

				case LGPrivateConst.FSVDidVisible:
				{
					if(this.fullscreenVideoAdDidVisibleListener != null){
						this.fullscreenVideoAdDidVisibleListener();
					}
				}
					break;

				case LGPrivateConst.FSVDidClick:
				{
					if(this.fullscreenVideoAdDidClickListener != null){
						this.fullscreenVideoAdDidClickListener();
					}
				}
					break;

				case LGPrivateConst.FSVWillClose:
				{
					if(this.fullscreenVideoAdWillCloseListener !=null){
						this.fullscreenVideoAdWillCloseListener();
					}
				}
					break;

				case LGPrivateConst.FSVDidClose:
				{
					if(this.fullscreenVideoAdDidCloseListener !=null){
						this.fullscreenVideoAdDidCloseListener();
					}
				}
					break;

				case LGPrivateConst.FSVDidFinish:{
					if(this.fullscreenVideoAdDidPlayFinishListener!=null){
						this.fullscreenVideoAdDidPlayFinishListener();
					}
				}
				 break;

				case LGPrivateConst.FSVDidClickSkip:{
					if(this.fullscreenVideoAdDidClickSkipListener!=null){
						this.fullscreenVideoAdDidClickSkipListener();
					}
				}
					break;

				///nativeExpressFullScreenVideo
				case LGPrivateConst.NEFSVDidLoad:{
					if(this.nativeExpressFullScreenVideoAdDidLoadListener!=null){
						this.nativeExpressFullScreenVideoAdDidLoadListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVFailToLoad:{
					if(this.nativeExpressFullScreenVideoAdFailToLoadListener!=null){
						this.nativeExpressFullScreenVideoAdFailToLoadListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVRenderSuccess:{
					if(this.nativeExpressFullScreenVideoAdViewRenderSuccessListener!=null){
						this.nativeExpressFullScreenVideoAdViewRenderSuccessListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVRenderFail:{
					if(this.nativeExpressFullScreenVideoAdViewRenderFailListener!=null){
						this.nativeExpressFullScreenVideoAdViewRenderFailListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVDownLoad:{
					if(this.nativeExpressFullScreenVideoAdDidDownLoadVideoListener!=null){
						this.nativeExpressFullScreenVideoAdDidDownLoadVideoListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVWillVisible:{
					if(this.nativeExpressFullScreenVideoAdWillVisibleListener!=null){
						this.nativeExpressFullScreenVideoAdWillVisibleListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVDidVisible:{
					if(this.nativeExpressFullScreenVideoAdDidVisibleListener!=null){
						this.nativeExpressFullScreenVideoAdDidVisibleListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVDidClick:{
					if(this.nativeExpressFullScreenVideoAdDidClickListener!=null){
						this.nativeExpressFullScreenVideoAdDidClickListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVClickSkip:{
					if(this.nativeExpressFullScreenVideoAdDidClickSkipListener!=null){
						this.nativeExpressFullScreenVideoAdDidClickSkipListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVWillClose:{
					if(this.nativeExpressFullScreenVideoAdWillCloseListener!=null){
						this.nativeExpressFullScreenVideoAdWillCloseListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVDidClose:{
					if(this.nativeExpressFullScreenVideoAdDidCloseListener!=null){
						this.nativeExpressFullScreenVideoAdDidCloseListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVPlayFinish:{
					if(this.nativeExpressFullScreenVideoAdDidPlayFinishListener!=null){
						this.nativeExpressFullScreenVideoAdDidPlayFinishListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVCallback:{
					if(this.nativeExpressFullScreenVideoAdCallbackListener!=null){
						this.nativeExpressFullScreenVideoAdCallbackListener();
					}
				}
					break;

				case LGPrivateConst.NEFSVCloseOther:{
					if(this.nativeExpressFullScreenVideoAdDidCloseOtherControllerListener!=null){
						this.nativeExpressFullScreenVideoAdDidCloseOtherControllerListener();
					}
				}
					break;
			}
		}
		public function LGAdvert(){
			if (!extContext) {
				extContext = ExtensionContext.createExtensionContext(EXTENSION_ID, null);
				if(extContext == null){
					trace("LG createExtensionContext error");
				}
				extContext.addEventListener( StatusEvent.STATUS, nativeCallBack);
			}
		}

		public static function getInstance():LGAdvert {
			if(instance == null)
				instance = new LGAdvert();
			return instance;
		}

		private static function _isIOS():Boolean {
			return Capabilities.manufacturer.indexOf("iOS") > -1 && Capabilities.os.indexOf("x86_64") < 0 && Capabilities.os.indexOf("i386") < 0;
		}

		private static function _isAndroid():Boolean {

			return Capabilities.manufacturer.indexOf("Android") > -1;
		}

		public  function setMain(main:MovieClip):void {
		 	this._main = main;
		}
	}
}