//
//  IESStoreManager.h
//  IESStore
//
//  Created by lixinlei on 2018/7/8.
//  Copyright © 2018年 com.bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IESTransaction.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IESStoreManagerHandler <NSObject>
@required
- (NSString *)currentUserID;
- (void)fetchOrderInfoWithProductID:(NSNumber *)productID
                            product:(SKProduct *)product
                         completion:(void(^)(NSString *orderID, NSError *error))completion;
- (void)sendTransactionWithOrderID:(nullable NSString *)orderID
                  receipt:(NSString *)receipt
              transaction:(nullable SKPaymentTransaction *)transaction
               completion:(void(^)(BOOL success, NSError *error))completion;
- (void)checkFinalResultWithOrderID:(nullable NSString *)orderID
                             receipt:(NSString *)receipt
                         transaction:(nullable SKPaymentTransaction *)transaction
                          completion:(void(^)(BOOL forceComplete, BOOL allowFinishOnFail, BOOL success, NSError *error))completion;
@optional
- (BOOL)shouldAddAppStorePayment:(SKPaymentQueue *)queue payment:(SKPayment *)payment forProduct:(SKProduct *)product;

@end

typedef NS_ENUM(NSUInteger, IESStoreManagerCompleteOccurrence) {
    IESStoreManagerCompleteOccurrenceBuy,                // 购买后验证完成
    IESStoreManagerCompleteOccurrenceResumeFromApple,    // 重启后苹果恢复订单后验证完成
    IESStoreManagerCompleteOccurrenceResumeFromLocal,    // 本地发现未验证订单后验证完成
    IESStoreManagerCompleteOccurrenceBuyAbnormally,      // 苹果某些特殊情况先返回失败，又返回成功的情况
};

@protocol IESStoreManagerDelegate <NSObject>
@optional
- (void)didUpdatedTransaction:(SKPaymentTransaction *)transaction;
- (void)didFindUnverifiedTransaction:(IESTransaction *)transaction;
- (void)didVerifyUnverifiedTransaction:(IESTransaction *)transaction;
- (void)didAddPaymentWithTransaction:(IESTransaction *)transaction success:(BOOL)success;
- (void)didSaveTransaction:(IESTransaction *)transaction;
- (void)didSaveOrderID:(NSString *)orderID withTransactionID:(NSString *)transactionID NS_DEPRECATED_IOS(1_0, 1_0, "Please use -didSaveOrderID:withTransaction");
- (void)didFinishTransaction:(IESTransaction *)transaction;
- (void)didResumeTransaction:(IESTransaction *)transaction;
- (void)didPurchaseTransactionAbnormally:(IESTransaction *)transaction;
- (void)didLoadTransaction:(SKPaymentTransaction *)transaction fromObserver:(BOOL)fromObserver;
- (void)didCompleteTransaction:(nullable IESTransaction *)transaction success:(BOOL)success error:(nullable NSError *)error occurrence:(IESStoreManagerCompleteOccurrence)occurrence;
- (void)willVerifyTransaction:(IESTransaction *)transaction occurrence:(IESStoreManagerCompleteOccurrence)occurrence;

- (void)didSaveOrderID:(NSString *)orderID withTransaction:(SKPaymentTransaction *)transaction;
- (void)beforAddPaymentWithIapID:(NSString *)iapID productID:(NSNumber *)productID orderID:(NSString *)orderID error:(NSError *)error;
- (void)didFinishSendTransaction:(IESTransaction *)transaction success:(BOOL)success error:(NSError *)error;
- (void)willCheckFinalResultWithTransaction:(IESTransaction *)transaction;
- (void)didFinishCheckFinalResultWithTransaction:(IESTransaction *)transaction success:(BOOL)success error:(NSError *)error;

@end

typedef NS_ENUM(NSUInteger, IESStoreManagerLoggerType) {
    IESStoreManagerLoggerTypeError,
    IESStoreManagerLoggerTypeWarning,
    IESStoreManagerLoggerTypeInfo,
};

@interface IESStoreManager : NSObject

// fetchOrderInfo重试次数，默认2次
@property (nonatomic, assign) NSUInteger fetchOrderInfoRetryCount;
// sendReceipt重试次数，默认2次
@property (nonatomic, assign) NSUInteger sendReceiptRetryCount;
// checkFinalResult轮询策略，数组元素为轮询间隔，数组长度为轮询次数，默认为@[@1, @2, @3, @4, @5, @5, @5, @5]，不可以为空数组
@property (nonatomic, strong) NSArray<NSNumber *> *checkFinalResultPollingIntervals;

@property (nonatomic, assign, readonly) BOOL existsUnverifiedTransaction;
// 是否允许在有未验证订单情况下购买，默认不允许。慎用，如果再次购买同一件商品，这件商品之前未验证完成，苹果不会有任何回调，可能会导致UI卡死（比如这时候有一个HUD在转圈就会因为接收不到回调而无限转下去）。
@property (nonatomic, assign) BOOL canBuyWhenExistsUnverifiedTransaction;

@property (nonatomic, weak) id <IESStoreManagerHandler> handler;
@property (nonatomic, weak) id <IESStoreManagerDelegate> delegate;
@property (nonatomic, copy) void(^logger)(IESStoreManagerLoggerType, NSString *);
@property (nonatomic, strong, readonly) NSDictionary<NSString *, SKProduct *> *productsDict; // products缓存
@property (nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *orderIDDict;
+ (instancetype)defaultManager;
- (void)requestProducts:(NSSet *)identifiers
             completion:(void(^)(NSArray<SKProduct *> *products, NSError * _Nullable error))completion;
- (void)buyProduct:(NSString *)iapID
         productID:(NSNumber *)productID
           product:(SKProduct *)product
        completion:(void(^)(BOOL success, NSString * _Nullable orderID, NSError * _Nullable error))completion;
- (void)buyProduct:(NSString *)iapID
         productID:(NSNumber *)productID
        completion:(void(^)(BOOL success, NSString * _Nullable orderID, NSError * _Nullable error))completion;
- (void)checkUnverifiedTransactionIfNeeded;
- (void)restoreTransactionsCompletion:(void(^)(BOOL success, NSError * _Nullable error))completion;
- (void)restoreTransactions:(NSString *)orderIdentifier
                 completion:(void(^)(BOOL success, NSError * _Nullable error))completion;
- (void)restoreTransactionsWithIapIDs:(NSArray<NSString *> *)iapIDs
                           completion:(void(^)(BOOL success, NSError * _Nullable error))completion;
@end

NS_ASSUME_NONNULL_END
