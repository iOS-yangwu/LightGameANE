//
//  TTAccountSessionTask.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/9/16.
//  Copyright © 2016 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountSessionTaskProtocol.h"



NS_ASSUME_NONNULL_BEGIN

@interface TTAccountSessionTask : NSObject
<
TTAccountSessionTask
>

- (instancetype)initWithSessionTask:(id)task;

@end

NS_ASSUME_NONNULL_END
