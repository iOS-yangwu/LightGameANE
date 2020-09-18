//
//  TTAccountNoDispatchJSONResponseSerializer.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import "TTHTTPResponseSerializerBase.h"
#import "TTNetworkManager.h"



@interface TTAccountNoDispatchJSONResponseSerializer : TTHTTPJSONResponseSerializerBase
<
TTJSONResponseSerializerProtocol
>

+ (void)error:(NSError *__autoreleasing *)error addHTTPStatusCodeWithResponse:(TTHttpResponse *)response;

+ (void)handleResponseResult:(id)responseObject
               responseError:(NSError *)responseError
                 resultError:(NSError *__autoreleasing *)resultError
                 originalURL:(NSURL *)reqURL;

@end
