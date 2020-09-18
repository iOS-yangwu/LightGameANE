//
//  CJIAPOrderCenter.h
//  CJPay
//
//  Created by 王新华 on 2019/3/18.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

NS_ASSUME_NONNULL_BEGIN
@interface CJIAPCoreParam : JSONModel

@property(nonatomic, copy) NSString *appID;
@property(nonatomic, copy) NSString *merchantID;
@property(nonatomic, copy) NSString *uid;
@property(nonatomic, copy) NSString *tradeNo;
@property(nonatomic, copy) NSString *outTradeNo; // 这个订单号一定拼接到最后一个竖线的后面，不能改位置哦

- (instancetype)initWith:(NSString *)appID merchantID: (NSString *)merchantID uid: (NSString *)uid tradeNo: (NSString *)tradeNo outTradeNo:(NSString *)outTradeNo;

- (instancetype)initWith:(NSString *)fullOrderID;

- (NSString *)fullOrderID;

@end

@interface CJIAPProduct : JSONModel

@property (nonatomic, assign) NSInteger createTime;
@property (nonatomic, copy) NSString *tradeNo;
@property (nonatomic, copy) NSString *receipt;
@property (nonatomic, copy) NSString *productID; // 商品的iapID
@property (nonatomic, copy) NSString *transactionID;
@property (nonatomic, copy) NSString *originalTransactionID;
@property (nonatomic, copy) NSDictionary *otherVerifyParams;
@property (nonatomic, assign) BOOL verifyInForeground; // 内存变量 不缓存
@property (nonatomic, copy) NSString *transactionDate;
@property (nonatomic, copy) NSString *originalTransactionDate;
@property (nonatomic, copy) NSString *outOrderNo; // 外部订单号，一般为商户侧订单号

- (BOOL)isValid;

- (BOOL)receiptIsValid;

- (BOOL)isRestoreProduct;

@end

@interface CJIAPOrderCenter : JSONModel

+ (CJIAPOrderCenter *)sharedInstance;

@property (nonatomic, assign) NSUInteger queueCapacity; // 最小30
@property(nonatomic, assign) NSInteger timerInternal;   // 最小120
@property (nonatomic, assign) BOOL firstConfig;

@property (nonatomic, readonly, strong) NSMutableDictionary<NSString* ,CJIAPProduct *> *unverifiedProducts;

- (BOOL)finishOrderWith:(CJIAPProduct *)product;

- (void)addOrderToCacheQueue:(CJIAPProduct *)product completion:(void(^)(BOOL success))completion;

- (void)timingCheckUnverifiedProducts;

- (void)configRetrySleepTime:(NSInteger)retrySleepTime queueCapacity:(NSUInteger) queueCapacity;

@end

NS_ASSUME_NONNULL_END
