//
//  LGCustomAutoTrack.h
//  LightGameSDK
//
//  Created by peiziming on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGCustomAutoTrack : NSObject

/**
 * 内置事件 "注册"
 * 举例:[BDAutoTrack registerEventByMethod:@"wechat" isSuccess:YES]; 支付方式 是否成功
 */
+ (void)registerEventByMethod:(NSString *)method isSuccess:(BOOL)isSuccess;

/**
 * 内置事件 "购买道具"
 * @param type 道具类型
 * @param name 道具名称
 * @param contentID 道具ID
 * @param number 道具数量
 * @param channel 支付渠道
 * @param currency 币种
 * @param amount 金额
 * @param isSuccess 是否成功
 * 举例:[BDAutoTrack purchaseEventWithContentType:@"gift" contentName:@"flower" contentID:@"008" contentNumber:1
 *  paymentChannel:@"wechat" currency:@"¥" currency_amount:1 isSuccess:YES];
 */
+ (void)purchaseEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                      paymentChannel:(NSString *)channel
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess;

/**
 * 登录
 */
+ (void)loginEventByMethod:(NSString *)method
                 isSuccess:(BOOL)isSuccess;

/**
 * 绑定社交账号
 */
+ (void)accessAccountEventByType:(NSString *)type
                       isSuccess:(BOOL)isSuccess;

/**
 * 完成教学任务/副本
 */
+ (void)questEventWithQuestID:(NSString *)questID
                    questType:(NSString *)type
                    questName:(NSString *)name
                   questNumer:(NSUInteger)number
                  description:(NSString *)desc
                    isSuccess:(BOOL)isSuccess;

/**
 * 升级
 */
+ (void)updateLevelEventWithLevel:(NSUInteger)level;

/**
 * 创建角⾊
 */
+ (void)createGameRoleEventByID:(NSString *)roleID;

/**
 * 查看内容/商品详情
 */
+ (void)viewContentEventWithContentType:(NSString *)type
                            contentName:(NSString *)name
                              contentID:(NSString *)contentID;

/**
 * 添加到购物⻋
 */
+ (void)addCartEventWithContentType:(NSString *)type
                        contentName:(NSString *)name
                          contentID:(NSString *)contentID
                      contentNumber:(NSUInteger)number
                          isSuccess:(BOOL)isSuccess;

/**
 * 提交购买/下单
 */
+ (void)checkoutEventWithContentType:(NSString *)type
                         contentName:(NSString *)name
                           contentID:(NSString *)contentID
                       contentNumber:(NSUInteger)number
                   isVirtualCurrency:(BOOL)isVirtualCurrency
                     virtualCurrency:(NSString *)virtualCurrency
                            currency:(NSString *)currency
                     currency_amount:(unsigned long long)amount
                           isSuccess:(BOOL)isSuccess;

/**
 * 添加支付渠道
 */
+ (void)accessPaymentChannelEventByChannel:(NSString *)channel
                                 isSuccess:(BOOL)isSuccess;

/**
 * 添加⾄收藏
 */
+ (void)addToFavouriteEventWithContentType:(NSString *)type
                               contentName:(NSString *)name
                                 contentID:(NSString *)contentID
                             contentNumber:(NSUInteger)number
                                 isSuccess:(BOOL)isSuccess;

@end

NS_ASSUME_NONNULL_END
