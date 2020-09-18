//
//  CJIAPStoreManager.h
//  CJPay
//
//  Created by 王新华 on 2019/3/15.
//

#import <Foundation/Foundation.h>
#import "CJPayIAPHeader.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CJIAPStoreDelegate <NSObject>

- (void)didFinishProductOrder:(nullable CJIAPProduct *)product resultType:(CJPayIAPResultType)resultType error:(nullable NSError *)error;
- (void)didFinishProductOrderInBack:(nullable CJIAPProduct *)product resultType:(CJPayIAPResultType)resultType error:(nullable NSError *)error;

@optional
//返回YES。事件不会再往后面的delegate传递。返回NO，会继续传递。无相关需求可不实现
//1. product不该自己处理时，返回NO。
//2.product需要自己处理时返回YES，不在向后传递事件。
//3. 如需要直接跳IAP购买，可将业务下单参数和该方法放回的product通过`- (void)startIAPWithParams:(NSDictionary *)bizParams product:(nullable SKProduct *)product`直接调起支付
- (BOOL)shouldInterceptAppStorePaymentQueue:(SKPaymentQueue *)queue payment:(SKPayment *)payment forProduct:(SKProduct *)product;
- (BOOL)shouldHandleProduct:(NSString *)productID;
// 供业务方根据当前存在的未验证订单来判断是否允许新的下单
// 1. 主要用来支持，有未confirm订单时，不让用户重新发起新的下单和支付
// 注意：每个业务线应该只处理自己的商品ID，操作非自己业务的商品ID会有很大隐患
- (BOOL)allowNewBuyingWithUnconfirmedProduct:(nullable NSArray<CJIAPProduct *> *)UnconfirmedProduct newBuyingProductID:(NSString *)productID newOrderParams:(NSDictionary *)params;
- (void)event:(NSString *)event params:(NSDictionary *)params;

// IESStoreHandler 事件向外传递，业务方是否实现可选；
@optional
- (void)iesBuyProduct:(NSString *)iapID productID:(NSString *)productID orderID:(nullable NSString * )orderID error:(nullable NSError *)error;
- (void)iesFetchOrderInfoWithProductID:(NSString *)productID
                               product:(SKProduct *)product;
- (void)iesSendTransactionWithOrderID:(nullable NSString *)orderID
                              receipt:(NSString *)receipt
                          transaction:(nullable SKPaymentTransaction *)transaction;
- (void)iesCheckFinalResultWithOrderID:(nullable NSString *)orderID
                               receipt:(NSString *)receipt
                           transaction:(nullable SKPaymentTransaction *)transaction;
@end

@interface CJIAPStoreManager : NSObject<IESStoreManagerHandler>

/**
 @deprecated Use `addCJIAPStoreDelegate:` or `removeCJIAPStoreDelegate` instead
 */
@property (nonatomic, weak) id<CJIAPStoreDelegate> delegate DEPRECATED_ATTRIBUTE;
@property (nonatomic, copy, readonly) NSHashTable *iapDelegates; // 多代理形式 和 单代理共存
// 在判断不是财经下单时，所有订单状态都会走这个delegate 和 handler
@property (nonatomic, weak) id<IESStoreManagerDelegate> iesStoreDelegate;
@property (nonatomic, weak) id<IESStoreManagerHandler> iesStoreHandler;
/**
 cjpay是否应该把事件传递给iesStoreHandler.总开关 默认为YES。当`cjpayShouldPassEventToIESStoreHandler`为NO时，不会像iesStoreHandler传递事件
 */
@property (nonatomic, assign) BOOL cjpayShouldPassEventToIESStoreHandler;

+ (CJIAPStoreManager *)shareInstance;

- (void)addCJIAPStoreDelegate:(id<CJIAPStoreDelegate>)delegate;
- (void)removeCJIAPStoreDelegate:(id<CJIAPStoreDelegate>)delegate;
- (nullable NSArray<id<CJIAPStoreDelegate>> *)getCopyIAPDelegates;

// 启动IAPManager，在app启动时进行，业务方需要调用，否则可能有订单回调不能正常处理
- (void)startupService;

//把CJIAPStoreManager作为订单的转发中心，同时会把IESStore的handler赋值给self的iesStoreHandler，把IESStore的delegate赋值给self 的iesStoreDelegate
- (void)becomeIESStoreDelegateCenter;
// 摘掉CJIAPStoreManager订单转发中心的能力，同时会把iesStoreDelegate 设置给IESStore的delegate，把iesStoreHandler设置给IESStore的handler
- (void)resignIESStoreDelegateCenter;

- (void)startIAPWithParams:(NSDictionary *)bizParams;
- (void)startIAPWithParams:(NSDictionary *)bizParams product:(nullable SKProduct *)product;

// 恢复购买
- (void)restoreTransactionsWithUid:(NSString *)uid Completion:(void(^)(BOOL success, NSError * _Nullable error))completion;
- (void)restoreTransactionsWithUid:(NSString *)uid WithIapIDs:(NSArray<NSString *> *)iapIDs
                           completion:(void(^)(BOOL success, NSError * _Nullable error))completion;

- (void)_syncServerIAPOrder:(CJIAPProduct *)product retryCount:(NSInteger) retryCount sleepTime:(CGFloat) sleepTime completion:(void(^)(NSError *error, CJPayIAPConfirmResponse *response, NSInteger retryCount))completion;

@end

NS_ASSUME_NONNULL_END
