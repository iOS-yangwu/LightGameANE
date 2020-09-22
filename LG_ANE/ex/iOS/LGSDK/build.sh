# define output folder environment variable
RootPath=$(cd "$(dirname "$0")"; pwd)

BUILD_DIR=build
CONFIGURATION=Release
BUILD_ROOT=build
TARGET_NAME=LGSDK
UNIVERSAL_OUTPUTFOLDER=Release

cd ${RootPath}



# Step 1. 清除旧构建
rm -rf ${BUILD_ROOT}
rm -rf ${UNIVERSAL_OUTPUTFOLDER}


# Step 2. 构建ios静态库
xcodebuild -target ${TARGET_NAME} -configuration ${CONFIGURATION} -sdk iphoneos  BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}"
#xcodebuild -target ${TARGET_NAME} -configuration ${CONFIGURATION} -sdk iphonesimulator -arch x86_64 -arch i386 BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}"


# make sure the output directory exists
mkdir ${UNIVERSAL_OUTPUTFOLDER}
# Step 3. 合并ios静态库

cp  ${BUILD_DIR}/${CONFIGURATION}-iphoneos/lib${TARGET_NAME}.a  ${RootPath}/${UNIVERSAL_OUTPUTFOLDER}/lib${TARGET_NAME}.a
#cp  ${BUILD_DIR}/${CONFIGURATION}-iphoneos/lib${TARGET_NAME}.a  ${RootPath}/${UNIVERSAL_OUTPUTFOLDER}/lib${TARGET_NAME}-iphoneos.a
#cp  ${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/lib${TARGET_NAME}.a  ${RootPath}/${UNIVERSAL_OUTPUTFOLDER}/lib${TARGET_NAME}-iphonesimulator.a

#lipo -create -output "${RootPath}/${UNIVERSAL_OUTPUTFOLDER}/lib${TARGET_NAME}.a" "${BUILD_DIR}/${CONFIGURATION}-iphoneos/lib${TARGET_NAME}.a" "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/lib${TARGET_NAME}.a"

rm -r ../../../tools/ios/
mkdir ../../../tools/ios/
cp -r ${UNIVERSAL_OUTPUTFOLDER}/libLGSDK.a  ../../../tools/ios/

rm -rf build
