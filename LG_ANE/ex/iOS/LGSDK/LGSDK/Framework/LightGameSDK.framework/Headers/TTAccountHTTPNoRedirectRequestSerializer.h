//
//  TTAccountHTTPNoRedirectRequestSerializer.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/9/16.
//  Copyright © 2016 com.bytedance.news. All rights reserved.
//

#import "TTHTTPRequestSerializerBase.h"
#import "TTAccountHTTPRequestSerializer.h"



NS_ASSUME_NONNULL_BEGIN

/**
 Not follow 302 redirect
 */
@interface TTAccountHTTPNoRedirectRequestSerializer : TTAccountHTTPRequestSerializer

@end

NS_ASSUME_NONNULL_END
