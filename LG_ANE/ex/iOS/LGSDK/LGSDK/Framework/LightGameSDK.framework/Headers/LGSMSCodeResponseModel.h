//
//  LGSMSCodeResponseModel.h
//  LightGameSDK
//
//  Created by wangchao on 2019/8/1.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGSMSCodeResponseModel : NSObject<NSCopying, NSMutableCopying>

@property (nonatomic, assign) BOOL hasResponse;
@property (nonatomic, copy) NSString *mobile;
@property (nonatomic, copy) NSString *captcha;
@property (nonatomic, copy) NSString *ticket;
@property (nonatomic, copy) NSString *authCode;
@property (nonatomic, copy) NSString *errCode;
@property (nonatomic, copy) NSString *errMsg;

@end

NS_ASSUME_NONNULL_END
