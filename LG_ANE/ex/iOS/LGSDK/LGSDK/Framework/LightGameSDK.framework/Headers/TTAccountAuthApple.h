//
//  TTAccountAuthApple.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/7/1.
//

#import <Foundation/Foundation.h>
#import "TTAccountAuthProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountAuthApple : NSObject
<TTAccountAuthProtocol>

@property (nonatomic, assign, getter=isNewPlatform) BOOL newPlatform;

@end

NS_ASSUME_NONNULL_END
