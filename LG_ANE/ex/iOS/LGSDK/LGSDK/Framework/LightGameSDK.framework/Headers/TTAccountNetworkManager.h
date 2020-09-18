//
//  TTAccountNetworkManager.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/26/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTNetworkManager.h"
#import "TTAccountSessionTaskProtocol.h"
#import "TTAccountCookie.h"



NS_ASSUME_NONNULL_BEGIN

/**
 默认follow 302 Redirect响应
 */
@interface TTAccountNetworkManager : NSObject

+ (id<TTAccountSessionTask>)postRequestForJSONWithURL:(NSString *)URLString
                                               params:(NSDictionary * _Nullable)params
                                     needCommonParams:(BOOL)commonParams
                                             callback:(TTNetworkJSONFinishBlock)callback;

+ (id<TTAccountSessionTask>)postRequestForJSONWithURL:(NSString *)URLString
                                               params:(NSDictionary * _Nullable)params
                                       extraGetParams:(NSDictionary * _Nullable)extraGetParams
                                     needCommonParams:(BOOL)commonParams
                                             callback:(TTNetworkJSONFinishBlock)callback;

+ (id<TTAccountSessionTask>)postRequestForJSONAndResponseWithURL:(NSString *)URLString
                                                          params:(NSDictionary *)params
                                                  extraGetParams:(NSDictionary *_Nullable)extraGetParams
                                                needCommonParams:(BOOL)commonParams
                                                        callback:(TTNetworkJSONFinishBlockWithResponse)callback;

+ (id<TTAccountSessionTask>)getRequestForJSONWithURL:(NSString *)URLString
                                              params:(NSDictionary * _Nullable)params
                                    needCommonParams:(BOOL)commonParams
                                            callback:(TTNetworkJSONFinishBlock)callback;

+ (id<TTAccountSessionTask>)getRequestForJSONWithURL:(NSString *)URLString
                                              params:(NSDictionary * _Nullable)params
                                      extraGetParams:(NSDictionary * _Nullable)extraGetParams
                                    needCommonParams:(BOOL)commonParams
                                            callback:(TTNetworkJSONFinishBlock)callback;

+ (id<TTAccountSessionTask>)getRequestForJSONAndResponseWithURL:(NSString *)URLString
                                              params:(NSDictionary *)params
                                      extraGetParams:(NSDictionary *)extraGetParams
                                    needCommonParams:(BOOL)commonParams
                                                       callback:(TTNetworkJSONFinishBlockWithResponse)callback;

+ (id<TTAccountSessionTask>)requestForJSONWithURL:(NSString *)URLString
                                           method:(NSString *)method
                                           params:(NSDictionary * _Nullable)params
                                   extraGetParams:(NSDictionary * _Nullable)extraGetParams
                                 needCommonParams:(BOOL)needCommonParams
                                follow302Redirect:(BOOL)follow302Redirect
                                         callback:(TTNetworkJSONFinishBlockWithResponse)callback;

+ (id<TTAccountSessionTask>)requestNoDispatchForJSONWithURL:(NSString *)URLString
                                                     method:(NSString *)method
                                                     params:(NSDictionary * _Nullable)params
                                             extraGetParams:(NSDictionary * _Nullable)extraGetParams
                                           needCommonParams:(BOOL)needCommonParams
                                                   callback:(TTNetworkJSONFinishBlock)callback;

+ (id<TTAccountSessionTask>)requestModel:(TTRequestModel *)model
                                callback:(TTNetworkResponseModelFinishBlock)callback;

+ (id<TTAccountSessionTask>)uploadWithURL:(NSString *)URLString
                               parameters:(NSDictionary * _Nullable)parameters
                constructingBodyWithBlock:(TTConstructingBodyBlock)bodyBlock
                                 progress:(NSProgress * __autoreleasing *)progress
                         needcommonParams:(BOOL)needCommonParams
                                 callback:(TTNetworkJSONFinishBlock)callback;
@end

NS_ASSUME_NONNULL_END
