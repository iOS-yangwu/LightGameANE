#!/bin/sh

rm -rf tmp
rm -f LGAdvert.ane

RootPath=$(cd "$(dirname "$0")"; pwd)
echo $RootPath

mkdir tmp
cp -r ../Lib/bin/LGAdvertLib.swc  tmp


# AnyThink
cp -r ../ex/iOS/LGSDK/LGSDK/Framework/LightGameSDK.framework tmp
cp -r ../ex/iOS/LGSDK/LGSDK/Framework/BDTuringResource.bundle tmp
cp -r ../ex/iOS/LGSDK/LGSDK/Framework/BUAdSDK.bundle tmp
cp -r ../ex/iOS/LGSDK/LGSDK/Framework/IESPhoto.bundle tmp
cp -r ../ex/iOS/LGSDK/LGSDK/Framework/LightGameSDK.bundle tmp

lightGame="LightGameSDK.framework BDTuringResource.bundle BUAdSDK.bundle IESPhoto.bundle LightGameSDK.bundle"


cp ./ios/libLGSDK.a tmp

cd tmp


pathString="${lightGame}"

unzip ./LGAdvertLib.swc

#iOS
adt -package -target ane ../LGAdvert.ane ../extension.xml -swc LGAdvertLib.swc -platform iPhone-ARM -platformoptions ../platformoptions.xml library.swf ${pathString} libLGSDK.a


cd ..


rm -rf tmp
