#!/bin/sh

rm -rf tmp
rm -f JoypacAdvert.ane

RootPath=$(cd "$(dirname "$0")"; pwd)
echo $RootPath

mkdir tmp
cp -r ../Lib/bin/JoypacAdvertLib.swc  tmp

#GoogleMobileAds
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/GoogleMobileAds.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/PersonalizedAdConsent.framework tmp
#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/AnyThinkAdmobBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/AnyThinkAdmobInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/AnyThinkAdmobRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Admob/AnyThinkAdmobNativeAdapter.framework tmp

admob="GoogleMobileAds.framework AnyThinkAdmobBannerAdapter.framework AnyThinkAdmobInterstitialAdapter.framework AnyThinkAdmobRewardedVideoAdapter.framework AnyThinkAdmobNativeAdapter.framework PersonalizedAdConsent.framework"

#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkSDK.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkBanner.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkInterstitial.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkRewardedVideo.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkSDK.bundle tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkNative.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/jplogo@2x.png tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkHeaderBidding.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkMyOffer.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkMyOfferInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkMyOfferRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UparpuSDK/AnyThinkSplash.framework tmp


AnyThink="AnyThinkSDK.framework AnyThinkBanner.framework AnyThinkInterstitial.framework AnyThinkRewardedVideo.framework AnyThinkSDK.bundle/ AnyThinkNative.framework jplogo@2x.png AnyThinkHeaderBidding.framework AnyThinkMyOffer.framework AnyThinkMyOfferInterstitialAdapter.framework AnyThinkMyOfferRewardedVideoAdapter.framework AnyThinkSplash.framework"

# Unity 2
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UnityAds/UnityAds.framework tmp
#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UnityAds/AnyThinkUnityAdsRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/UnityAds/AnyThinkUnityAdsInterstitialAdapter.framework tmp

unity="UnityAds.framework AnyThinkUnityAdsInterstitialAdapter.framework AnyThinkUnityAdsRewardedVideoAdapter.framework"


# Vungle 3
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Vungle/VungleSDK.framework tmp
# AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Vungle/AnyThinkVungleInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Vungle/AnyThinkVungleRewardedVideoAdapter.framework tmp

vungle="VungleSDK.framework AnyThinkVungleInterstitialAdapter.framework AnyThinkVungleRewardedVideoAdapter.framework"

# AppLovin 4
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AppLovinSDK.framework tmp

#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AnyThinkApplovinBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AnyThinkApplovinInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AnyThinkApplovinRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AnyThinkApplovinNativeAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Applovin/AppLovinSDKResources.bundle tmp

applovin="AppLovinSDK.framework AnyThinkApplovinNativeAdapter.framework AnyThinkApplovinBannerAdapter.framework AnyThinkApplovinInterstitialAdapter.framework AnyThinkApplovinRewardedVideoAdapter.framework AppLovinSDKResources.bundle/"

# GDT 5
#cp -r ../ex/iOS/JoypacSDK/UPSDK/3rdsdk/GDT/libGDTMobSDK.a tmp

#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/GDT/AnyThinkGDTBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/GDT/AnyThinkGDTInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/GDT/AnyThinkGDTRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/GDT/AnyThinkGDTNativeAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/GDT/AnyThinkGDTSplashAdapter.framework tmp

gdt="AnyThinkGDTNativeAdapter.framework AnyThinkGDTBannerAdapter.framework AnyThinkGDTInterstitialAdapter.framework AnyThinkGDTRewardedVideoAdapter.framework AnyThinkGDTSplashAdapter.framework"

# Mintegral 6
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDK.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKReward.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKInterstitial.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKInterstitialVideo.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKInterActive.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKBidding.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/MTGSDKBanner.framework tmp

#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/AnyThinkMintegralInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/AnyThinkMintegralRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/AnyThinkMintegralNativeAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Mintegral/AnyThinkMintegralBannerAdapter.framework tmp


#
mintegral="MTGSDK.framework MTGSDKReward.framework MTGSDKInterActive.framework MTGSDKInterstitial.framework MTGSDKInterstitialVideo.framework AnyThinkMintegralInterstitialAdapter.framework AnyThinkMintegralRewardedVideoAdapter.framework AnyThinkMintegralNativeAdapter.framework MTGSDKBidding.framework MTGSDKBanner.framework AnyThinkMintegralBannerAdapter.framework"


# Toutiao 7
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/BUAdSDK.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/BUAdSDK.bundle tmp
#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/AnyThinkTTBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/AnyThinkTTInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/AnyThinkTTRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/TT/AnyThinkTTNativeAdapter.framework tmp

toutiao="BUAdSDK.framework BUAdSDK.bundle/ AnyThinkTTBannerAdapter.framework AnyThinkTTInterstitialAdapter.framework AnyThinkTTRewardedVideoAdapter.framework AnyThinkTTNativeAdapter.framework"

# IronSource 8
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/IronSource/IronSource.framework tmp
#AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/IronSource/AnyThinkIronSourceInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/IronSource/AnyThinkIronSourceRewardedVideoAdapter.framework tmp

ironsource="IronSource.framework AnyThinkIronSourceInterstitialAdapter.framework AnyThinkIronSourceRewardedVideoAdapter.framework"


# Facebook 9
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/FBAudienceNetwork.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/FBAudienceNetworkBiddingKit.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/FBSDKCoreKit.framework tmp


## AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/AnyThinkFacebookBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/AnyThinkFacebookInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/AnyThinkFacebookRewardedVideoAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Facebook/AnyThinkFacebookNativeAdapter.framework tmp
facebook="FBAudienceNetwork.framework FBSDKCoreKit.framework AnyThinkFacebookBannerAdapter.framework AnyThinkFacebookInterstitialAdapter.framework AnyThinkFacebookRewardedVideoAdapter.framework AnyThinkFacebookNativeAdapter.framework FBAudienceNetworkBiddingKit.framework"


# adcolony 10
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/AdColony/AdColony.framework tmp
# AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/AdColony/AnyThinkAdColonyInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/AdColony/AnyThinkAdColonyRewardedVideoAdapter.framework tmp


adcolony="AdColony.framework AnyThinkAdColonyInterstitialAdapter.framework AnyThinkAdColonyRewardedVideoAdapter.framework"


#Baidu
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/BaiduMobAdSDK.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/baidumobadsdk.bundle tmp
# AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/AnyThinkBaiduBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/AnyThinkBaiduSplashAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/AnyThinkBaiduInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Baidu/AnyThinkBaiduRewardedVideoAdapter.framework tmp

baidu="BaiduMobAdSDK.framework baidumobadsdk.bundle/ AnyThinkBaiduBannerAdapter.framework AnyThinkBaiduInterstitialAdapter.framework AnyThinkBaiduRewardedVideoAdapter.framework AnyThinkBaiduSplashAdapter.framework"

#maio
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Maio/Maio.framework tmp

# AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Maio/AnyThinkMaioInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Maio/AnyThinkMaioRewardedVideoAdapter.framework tmp

maio="Maio.framework AnyThinkMaioInterstitialAdapter.framework AnyThinkMaioRewardedVideoAdapter.framework"

#nend
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Nend/NendAd.framework tmp

# AnyThink
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Nend/AnyThinkNendBannerAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Nend/AnyThinkNendInterstitialAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Nend/AnyThinkNendNativeAdapter.framework tmp
cp -r ../ex/iOS/JoypacSDK/JoypacSDK/Thirds/Nend/AnyThinkNendRewardedVideoAdapter.framework tmp

nend="NendAd.framework AnyThinkNendBannerAdapter.framework AnyThinkNendInterstitialAdapter.framework AnyThinkNendNativeAdapter.framework AnyThinkNendRewardedVideoAdapter.framework"


cp ./ios/libJoypacSDK-iphonesimulator.a tmp
cp ./ios/libJoypacSDK-iphoneos.a tmp

#Android
#cp ./Android-ARM/xxxx.jar tmp


cd tmp


#test
pathString="${AnyThink} ${mintegral} ${toutiao}"

#pathString="${admob} ${AnyThink} ${mintegral} ${gdt} ${unity} ${vungle} ${toutiao} ${baidu} ${applovin} ${facebook} ${ironsource} ${maio} ${nend}"



unzip ./JoypacAdvertLib.swc

#iOS
adt -package -target ane ../JoypacAdvert.ane ../extension.xml -swc JoypacAdvertLib.swc -platform iPhone-ARM -platformoptions ../platformoptions.xml library.swf ${pathString} libJoypacSDK-iphoneos.a -platform iPhone-x86 -platformoptions ../platformoptions.xml library.swf ${pathString} libJoypacSDK-iphonesimulator.a

#adt -package -target ane ../JoypacAdvert.ane ../extension.xml -swc JoypacAdvertLib.swc -platform iPhone-ARM -platformoptions ../platformoptions.xml library.swf ${pathString} libJoypacSDK-iphoneos.a -platform iPhone-x86 -platformoptions ../platformoptions.xml library.swf ${pathString} libJoypacSDK-iphonesimulator.a -platform Android-ARM -C Android-ARM . -platformoptions ../platformoptions.xml

cd ..


rm -rf tmp
