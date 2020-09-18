//
//  BDAutoTrackNetworkManager.h
//  Applog
//
//  Created by bob on 2019/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^BDAutoTrackNetworkFinishBlock)(NSError * _Nullable error, id  _Nullable jsonObj);

/// 提供基础的网络请求封装

FOUNDATION_EXTERN void bd_network_asyncRequestForURL(NSString *requestURL,
                                                     NSString *method,
                                                     NSDictionary *headerField,
                                                     BOOL needEncrypt,
                                                     BOOL needCompress,
                                                     NSDictionary *parameters,
                                                     BDAutoTrackNetworkFinishBlock _Nullable callback,
                                                     dispatch_queue_t _Nullable queue);

FOUNDATION_EXTERN NSDictionary * bd_network_syncRequestForURL(NSString *requestURL,
                                                              NSString *method,
                                                              NSDictionary *headerField,
                                                              BOOL needEncrypt,
                                                              NSDictionary *parameters);

NS_ASSUME_NONNULL_END
