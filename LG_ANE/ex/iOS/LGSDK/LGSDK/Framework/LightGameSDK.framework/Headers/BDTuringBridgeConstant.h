//
//  BDTuringBridgeConstant.h
//  BDTuring
//
//  Created by bob on 2019/8/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDTuringBridgeType){
    BDTuringBridgeUnkown = 1,
    BDTuringBridgeCall,
    BDTuringBridgeOn,
    BDTuringBridgeOff,
};

typedef NS_ENUM(NSInteger, BDTuringBridgeMsg){
    BDTuringBridgeMsgSuccess = 1,
    BDTuringBridgeMsgFailed = 0,
    BDTuringBridgeMsgParamError = -3,
    BDTuringBridgeMsgNoHandler = -2,
    BDTuringBridgeMsgNoPermission = -1,
};

typedef void (^BDTuringBridgeCallCompletion)(id _Nullable result, NSError * _Nullable error);

typedef void (^BDTuringBridgeOnCallback)(BDTuringBridgeMsg msg, NSDictionary *_Nullable params, BDTuringBridgeCallCompletion _Nullable completion);
typedef void (^BDTuringBridgeOnHandler)(NSDictionary *_Nullable params, BDTuringBridgeOnCallback _Nullable callback);

FOUNDATION_EXTERN NSString * const kBDTuringCallMethod;

FOUNDATION_EXTERN NSString *const kBDTuringBridgeCallbackID;
FOUNDATION_EXTERN NSString *const kBDTuringBridgeMsgType;
FOUNDATION_EXTERN NSString *const kBDTuringBridgeName;
FOUNDATION_EXTERN NSString *const kBDTuringBridge2JSParams;
FOUNDATION_EXTERN NSString *const kBDTuringBridge2NativeParams;
FOUNDATION_EXTERN NSString *const kBDTuringBridgeErrorCode;
FOUNDATION_EXTERN NSString *const kBDTuringBridgeCode;
FOUNDATION_EXTERN NSString *const kBDTuringBridgeData;

FOUNDATION_EXTERN NSString *const BDTuringBridgeMsgTypeEvent;
FOUNDATION_EXTERN NSString *const BDTuringBridgeMsgTypeOn;
FOUNDATION_EXTERN NSString *const BDTuringBridgeMsgTypeCall;
FOUNDATION_EXTERN NSString *const BDTuringBridgeMsgTypeOff;
FOUNDATION_EXTERN NSString *const BDTuringBridgeMsgTypeCallback;

FOUNDATION_EXTERN NSString * kBDTuringBridgeJSHandler;

FOUNDATION_EXTERN NSString *const kBDTuringBridgeReport;
FOUNDATION_EXTERN NSString *const BDTuringVerifyEventBridge2SDK;
FOUNDATION_EXTERN NSString *const BDTuringVerifyEventBridge2FE;

NS_ASSUME_NONNULL_END
