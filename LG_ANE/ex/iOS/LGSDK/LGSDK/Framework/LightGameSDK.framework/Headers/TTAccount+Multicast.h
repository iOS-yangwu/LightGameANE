//
//  TTAccount+Multicast.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/25/17.
//
//

#import "TTAccount.h"
#import "TTAccountMulticast.h"



NS_ASSUME_NONNULL_BEGIN

@interface TTAccount (Multicast)

/**
 *  添加帐号消息观察者
 *
 *  @attention delegate是弱持有
 *
 *  @param delegate 观察者
 */
+ (void)addMulticastDelegate:(NSObject<TTAccountMulticastProtocol> * _Nonnull)delegate;

/**
 *  移除帐号消息观察者
 *
 *  @param delegate 观察者
 */
+ (void)removeMulticastDelegate:(NSObject<TTAccountMulticastProtocol> * _Nonnull)delegate;

@end

NS_ASSUME_NONNULL_END
