package com.LightGame.ane {

import flash.events.IEventDispatcher;
import flash.display.MovieClip;
import flash.external.ExtensionContext;
import flash.system.Capabilities;
import com.LightGame.utils.LGFunctions;

    public class LGCustomAutoTrack extends MovieClip implements IEventDispatcher{
        internal static var EXTENSION_ID:String = "com.lightGame.ane";
        internal var extContext:ExtensionContext = null;
        internal static var instance:com.LightGame.ane.LGCustomAutoTrack;

        public function LGCustomAutoTrack(){
            if (!extContext) {
                extContext = ExtensionContext.createExtensionContext(EXTENSION_ID, null);
                if(extContext == null){
                    trace("LG createExtensionContext error");
                }
            }
        }

        public static function getInstance():LGCustomAutoTrack {
            if(instance == null)
                instance = new LGCustomAutoTrack();
            return instance;
        }

        /**
         * @brief registerEvent
         */
        public static function registerEvent(method:String,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.REGISTER_EVENT,method,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-registerEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief purchaseEvent
         */
        public static function purchaseEvent(contentType:String,contentName:String,contentID:String,contentNum:int,paymentChannel:String,currency:String,amount:int,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.PURCHASE_EVENT,contentType,contentName,contentID,contentNum,paymentChannel,currency,amount,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-purchaseEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief loginEvent
         */
        public static function loginEvent(method:String,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.LOGIN_EVENT,method,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-loginEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief accessAccountEvent
         */
        public static function accessAccountEvent(type:String,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.ACCESSACCOUNT_EVENT,type,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-accessAccountEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief questEvent
         */
        public static function questEvent(questId:String,questType:String,questName:String,questNumber:int,description:String,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.QUEST_EVENT,questId,questType,questName,questNumber,description,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-questEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief updateLevelEvent
         */
        public static function updateLevelEvent(level:int):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.UPDATELEVEL_EVENT,level);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-updateLevelEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief createGameRoleEvent
         */
        public static function createGameRoleEvent(roleId:String):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.CREATEGAMEROLE_EVENT,roleId);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-createGameRoleEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief viewContentEvent
         */
        public static function viewContentEvent(contentType:String,contentName:String,contentId:String):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.VIEWCONTENT_EVENT,contentType,contentName,contentId);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-viewContentEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief addCartEvent
         */
        public static function addCartEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.ADDCART_EVENT,contentType,contentName,contentId,contentNumber,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-addCartEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief checkoutEvent
         */
        public static function checkoutEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isVirtualCurrency:Boolean,virtualCurrency:String,currency:String,currencyAmount:int,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.CHECKOUT_EVENT,contentType,contentName,contentId,contentNumber,isVirtualCurrency,virtualCurrency,currency,currencyAmount,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-checkoutEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief accessPaymentChannelEvent
         */
        public static function accessPaymentChannelEvent(channel:String,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.ACCESSPAYMENTCHANNEL_EVENT,channel,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-accessPaymentChannelEvent-Not a Android/iOS module");
            }
        }

        /**
         * @brief addToFavouriteEvent
         */
        public static function addToFavouriteEvent(contentType:String,contentName:String,contentId:String,contentNumber:int,isSuccess:Boolean):void{

            if (_isIOS()){

                LGCustomAutoTrack.getInstance().extContext.call(LGFunctions.ADDTOFAVOURITE_EVENT,contentType,contentName,contentId,contentNumber,isSuccess);

            }else if (_isAndroid()){

            }else{

                trace("LG-Function-addToFavouriteEvent-Not a Android/iOS module");
            }
        }


        private static function _isIOS():Boolean {
            return Capabilities.manufacturer.indexOf("iOS") > -1 && Capabilities.os.indexOf("x86_64") < 0 && Capabilities.os.indexOf("i386") < 0;
        }

        private static function _isAndroid():Boolean {

            return Capabilities.manufacturer.indexOf("Android") > -1;
        }

    }
}
