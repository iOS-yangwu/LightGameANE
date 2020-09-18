//
//  LGCustomAutoTrack_ANE.m
//  LGSDK
//
//  Created by 洋吴 on 2020/9/15.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGCustomAutoTrack_ANE.h"
#import <LightGameSDK/LGCustomAutoTrack.h>


@implementation LGCustomAutoTrack_ANE

+ (void)registerEventByMethod:(NSString *)method isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack registerEventByMethod:method isSuccess:isSuccess];
}

+ (void)purchaseEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                      paymentChannel:(NSString *)channel
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack purchaseEventWithContentType:type contentName:name contentID:contentID contentNumber:number paymentChannel:channel currency:currency currency_amount:amount isSuccess:isSuccess];
}

+ (void)loginEventByMethod:(NSString *)method
                 isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack loginEventByMethod:method isSuccess:isSuccess];
}

+ (void)accessAccountEventByType:(NSString *)type
                       isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack accessAccountEventByType:type isSuccess:isSuccess];
}

+ (void)questEventWithQuestID:(NSString *)questID
                    questType:(NSString *)type
                    questName:(NSString *)name
                   questNumer:(NSUInteger)number
                  description:(NSString *)desc
                    isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack questEventWithQuestID:questID questType:type questName:name questNumer:number description:desc isSuccess:isSuccess];
}

+ (void)updateLevelEventWithLevel:(NSUInteger)level{
    
    [LGCustomAutoTrack updateLevelEventWithLevel:level];
}

+ (void)createGameRoleEventByID:(NSString *)roleID{
    
    [LGCustomAutoTrack createGameRoleEventByID:roleID];
}

+ (void)viewContentEventWithContentType:(NSString *)type
                            contentName:(NSString *)name
                              contentID:(NSString *)contentID{
    
    [LGCustomAutoTrack viewContentEventWithContentType:type contentName:name contentID:contentID];
}

+ (void)addCartEventWithContentType:(NSString *)type
                        contentName:(NSString *)name
                          contentID:(NSString *)contentID
                      contentNumber:(NSUInteger)number
                          isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack addCartEventWithContentType:type contentName:name contentID:contentID contentNumber:number isSuccess:isSuccess];
}

+ (void)checkoutEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                   isVirtualCurrency:(BOOL)isVirtualCurrency
                     virtualCurrency:(NSString *)virtualCurrency
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack checkoutEventWithContentType:type contentName:name contentID:contentID contentNumber:number isVirtualCurrency:isVirtualCurrency virtualCurrency:virtualCurrency currency:currency currency_amount:amount isSuccess:isSuccess];
}

+ (void)accessPaymentChannelEventByChannel:(NSString *)channel
                                 isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack accessPaymentChannelEventByChannel:channel isSuccess:isSuccess];
}

+ (void)addToFavouriteEventWithContentType:(NSString *)type
                               contentName:(NSString *)name
                                 contentID:(NSString *)contentID
                             contentNumber:(NSUInteger)number
                                 isSuccess:(BOOL)isSuccess{
    
    [LGCustomAutoTrack addToFavouriteEventWithContentType:type contentName:name contentID:contentID contentNumber:number isSuccess:isSuccess];
}

@end
