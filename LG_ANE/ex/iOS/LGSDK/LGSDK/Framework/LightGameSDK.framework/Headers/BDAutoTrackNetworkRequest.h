//
//  BDAutoTrackNetworkRequest.h
//  RangersAppLog
//
//  Created by bob on 2019/9/13.
//

#import "BDAutoTrackNetworkManager.h"
#import "BDAutoTrackNetworkConfig.h"

NS_ASSUME_NONNULL_BEGIN

/// extern for Unit Test
FOUNDATION_EXTERN NSMutableDictionary * bd_requestURLParameters(NSString *appID);
FOUNDATION_EXTERN NSString * bd_validateRequestURL(NSString *requestURL);
FOUNDATION_EXTERN NSString * bd_requestURL(BDAutoTrackRequestURLType type, NSString *appID);
FOUNDATION_EXTERN NSMutableDictionary * bd_requestPostHeaderParameters(NSString *appID);
FOUNDATION_EXTERN BOOL bd_isRequestTypeLog(BDAutoTrackRequestURLType type);

/// 
FOUNDATION_EXTERN void bd_asyncRequest(NSString *appID,
                     BDAutoTrackRequestURLType type,
                     NSDictionary *_Nullable parameters,
                     BDAutoTrackNetworkFinishBlock callback,
                     dispatch_queue_t _Nullable queue);

FOUNDATION_EXTERN NSDictionary *_Nullable bd_syncRequest(NSString *appID,
                                                         BDAutoTrackRequestURLType type,
                                                         NSDictionary *_Nullable parameters);
NS_ASSUME_NONNULL_END
