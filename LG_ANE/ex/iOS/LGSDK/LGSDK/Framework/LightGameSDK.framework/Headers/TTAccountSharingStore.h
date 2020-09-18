//
//  TTAccountSharingStore.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/17/17.
//
//

#import <Foundation/Foundation.h>



/**
 *  应用之间进行数据共享的存储
 */
@interface TTAccountSharingStore : NSObject

/** Set SessionKey */
+ (void)setSessionKey:(NSString *)sessionKey;

/** Get SessionKey */
+ (NSString *)sessionKey;

@end
