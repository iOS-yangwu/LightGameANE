//
//  BDAccountSessionRSA.h
//  BDAccountSessionSDK
//
//  Created by bytedance on 2018/5/9.
//

#import <Foundation/Foundation.h>

@interface TTAccountSessionRSA : NSObject

- (BOOL)authChangeTokenWithHexString:(NSString *)hexString token:(NSString *)token;

@end
