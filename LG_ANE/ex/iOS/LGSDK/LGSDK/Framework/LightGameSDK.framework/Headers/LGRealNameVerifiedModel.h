//
//  LGDeviceRNVerifiedModel.h
//  LightGameSDK
//
//  Created by wangchao on 2019/12/5.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGRealNameVerifiedModel : NSObject

// 是否实名
@property (nonatomic, assign) BOOL isRealNameVerified;
// 是否成年 当且仅当isRealNameVerified=YES时有效
@property (nonatomic, assign) BOOL isAdult;

@end

NS_ASSUME_NONNULL_END
