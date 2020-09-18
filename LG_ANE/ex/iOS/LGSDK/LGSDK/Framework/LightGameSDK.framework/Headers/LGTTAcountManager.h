//
//  LGTTAcountManager.h
//  LightGameSDK
//
//  Created by peiziming on 2020/3/11.
//  Copyright © 2020 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGTTAcountManager : NSObject

+ (void)configInit;

+ (void)configTTAcountByIID:(NSString *)iid deviceID:(NSString *)deviceID ssID:(NSString *)ssID;

@end

NS_ASSUME_NONNULL_END
