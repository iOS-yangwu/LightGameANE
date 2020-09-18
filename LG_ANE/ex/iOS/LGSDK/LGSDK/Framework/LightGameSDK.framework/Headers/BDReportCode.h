//
//  BDReportCode.h
//  RangersAppLog
//
//  Created by bob on 2019/7/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDReportFailType) {
    BDReportFailTypeSerializationFail = 1,
    BDReportFailTypeFormatError,
    BDReportFailTypeCustomIllegal,
    BDReportFailTypeSecondAppIllegal,
    BDReportFailTypeOtherInputIllegal = 10,
    BDReportFailTypeInitFailed,     // iOS 没有
    BDReportFailTypeBlackList,      // iOS 目前没有，后续可能添加
    BDReportFailTypeRetryOverTimes, // iOS 没有
    BDReportFailTypeRetryTimeout,   // iOS 没有
    BDReportFailTypeNoSessionID,    // iOS 没有
    BDReportFailTypeEventToManyBeforeInit,  // iOS 没有
    BDReportFailTypeOtherSDKError = 20,
    BDReportFailTypeDatabaseFileRemoved,
    BDReportFailTypeLogRequestRetryFail,
    BDReportFailTypeOtherFail = 100,
    BDReportFailTypeLogRequestMessageFail,
    BDReportFailTypeLogRequestNoMessage,
};  

FOUNDATION_EXTERN NSString * const BDReportMonitorEvent;
FOUNDATION_EXTERN NSString * const kBDReportEventName;
FOUNDATION_EXTERN NSString * const kBDReportType;
FOUNDATION_EXTERN NSString * const kBDReportOtherEvent;
FOUNDATION_EXTERN NSString * const kBDReportMonitorRate;
FOUNDATION_EXTERN NSString * const kBDReportMonitorStatus;
FOUNDATION_EXTERN NSString * const kBDReportMonitorNum;

FOUNDATION_EXTERN NSString * const kBDReportDataSuccess;
FOUNDATION_EXTERN NSString * const kBDReportDataRetrySuccess;
FOUNDATION_EXTERN NSString * const kBDReportDataHTTPFail;

NS_ASSUME_NONNULL_END
