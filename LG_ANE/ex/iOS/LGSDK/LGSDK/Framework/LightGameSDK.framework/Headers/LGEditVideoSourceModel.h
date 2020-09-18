//
//  LGEditVideoSourceModel.h
//  LightGameSDK
//
//  Created by peiziming on 2019/6/4.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGVideoConfigModel.h"
#import "LGSplashAdModel.h"

@class LGRecordSwitchModel;


@interface LGEditVideoSourceModel : NSObject

@property (nonatomic, strong) LGVideoConfigModel *configModel;
@property (nonatomic, strong) LGRecordSwitchModel *switchModel;
@property (nonatomic, strong) LGSplashAdModel *splashModel;

@property (nonatomic, assign) BOOL isCanUseMV;

@end

