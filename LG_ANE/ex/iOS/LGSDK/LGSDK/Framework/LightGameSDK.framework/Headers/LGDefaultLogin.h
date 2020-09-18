//
//  LGDefaultLogin.h
//  LightGameSDK
//
//  Created by peiziming on 2019/7/28.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGDefaultLogin.h"
#import "LGUserModel.h"

NS_ASSUME_NONNULL_BEGIN


typedef void(^LGAuthRecieveCodeBlock)(NSInteger errCode, NSString *authCode, LGLoginType loginType);


@interface LGDefaultLogin : NSObject

@property(nonatomic, copy)LGAuthRecieveCodeBlock authRecieveCodeBlock;

@end

NS_ASSUME_NONNULL_END
