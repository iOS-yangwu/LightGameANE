//
//  IESStore.h
//  IESStore
//
//  Created by lixinlei on 2018/7/7.
//  Copyright © 2018年 com.bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IESStoreObserver<NSObject>
@required
// 应用启动，如果有未finish的订单，系统会自动回调
- (void)storeDidResumeTransaction:(SKPaymentTransaction *)transaction;
- (void)storeDidUpdatedTransaction:(SKPaymentTransaction *)transaction;
// 苹果在某些特殊情况（比如更新了充值协议时，会先调用一次失败，再调用一次成功），第二次调用成功时的回调
- (void)storeDidPurchaseTransactionAbnormally:(SKPaymentTransaction *)transaction;
// 用来统计未校验订单是从苹果回调获取还是我们手动获取
- (void)storeFirstLoadTransaction:(SKPaymentTransaction *)transaction fromObserver:(BOOL)fromObserver;
// 在AppStore购买商品触发的回调
- (BOOL)storeShouldAddAppStorePayment:(SKPaymentQueue *)queue payment:(SKPayment *)payment forProduct:(SKProduct *)product;

@end

@interface IESStore : NSObject<SKPaymentTransactionObserver>

@property (nonatomic, weak) id<IESStoreObserver> observer;

+ (IESStore *)defaultStore;
+ (BOOL)canMakePayments;
+ (NSString *)receipt;
- (void)addProduct:(SKProduct *)product;
- (void)requestProducts:(NSSet *)identifiers
                success:(void (^)(NSArray<SKProduct *> *products))successBlock
                failure:(void (^)(NSError * _Nullable error))failureBlock;
- (void)addPayment:(NSString *)productIdentifier
   orderIdentifier:(NSString *)orderIdentifier
           success:(void (^)(SKPaymentTransaction *transaction))successBlock
           failure:(void (^)(SKPaymentTransaction * _Nullable transaction, NSError *error))failureBlock;
- (void)restoreTransactionsSuccess:(void (^)(NSArray<SKPaymentTransaction *> *transactions))successBlock
                           failure:(void (^)(NSError *error))failureBlock;
- (void)restoreTransactions:(NSString *)orderIdentifier
                    success:(void (^)(NSArray *transactions))successBlock
                    failure:(void (^)(NSError *error))failureBlock;
- (void)finishTransaction:(SKPaymentTransaction *)transaction;

@end

NS_ASSUME_NONNULL_END
