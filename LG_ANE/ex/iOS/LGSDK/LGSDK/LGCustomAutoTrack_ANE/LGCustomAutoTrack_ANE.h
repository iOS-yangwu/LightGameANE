//
//  LGCustomAutoTrack_ANE.h
//  LGSDK
//
//  Created by 洋吴 on 2020/9/15.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGCustomAutoTrack_ANE : NSObject

+ (void)registerEventByMethod:(NSString *)method isSuccess:(BOOL)isSuccess;

+ (void)purchaseEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                      paymentChannel:(NSString *)channel
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess;

+ (void)loginEventByMethod:(NSString *)method
                 isSuccess:(BOOL)isSuccess;

+ (void)accessAccountEventByType:(NSString *)type
                       isSuccess:(BOOL)isSuccess;

+ (void)questEventWithQuestID:(NSString *)questID
                    questType:(NSString *)type
                    questName:(NSString *)name
                   questNumer:(NSUInteger)number
                  description:(NSString *)desc
                    isSuccess:(BOOL)isSuccess;

+ (void)updateLevelEventWithLevel:(NSUInteger)level;

+ (void)createGameRoleEventByID:(NSString *)roleID;

+ (void)viewContentEventWithContentType:(NSString *)type
                            contentName:(NSString *)name
                              contentID:(NSString *)contentID;

+ (void)addCartEventWithContentType:(NSString *)type
                        contentName:(NSString *)name
                          contentID:(NSString *)contentID
                      contentNumber:(NSUInteger)number
                          isSuccess:(BOOL)isSuccess;

+ (void)checkoutEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                   isVirtualCurrency:(BOOL)isVirtualCurrency
                     virtualCurrency:(NSString *)virtualCurrency
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess;

+ (void)accessPaymentChannelEventByChannel:(NSString *)channel
                                 isSuccess:(BOOL)isSuccess;

+ (void)addToFavouriteEventWithContentType:(NSString *)type
                               contentName:(NSString *)name
                                 contentID:(NSString *)contentID
                             contentNumber:(NSUInteger)number
                                 isSuccess:(BOOL)isSuccess;

@end

NS_ASSUME_NONNULL_END
