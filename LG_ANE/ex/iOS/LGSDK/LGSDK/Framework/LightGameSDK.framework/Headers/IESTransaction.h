//
//  IESTransaction.h
//  IESStore
//
//  Created by lixinlei on 2018/7/8.
//  Copyright © 2018年 com.bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IESProduct : NSObject<NSCoding>

@property (nonatomic, copy) NSString *iapID;
@property (nonatomic, strong) NSNumber *iesProductID;
@property (nonatomic, strong) SKProduct *skProduct;
- (instancetype)initWithIapID:(NSString *)iapID
                 iesProductID:(NSNumber *)iesProductID
                    skProduct:(SKProduct *)skProduct;

@end

@interface IESTransaction : NSObject<NSCoding>

@property (nonatomic, strong, nullable) IESProduct *product;
@property (nonatomic, strong, nullable) NSString *orderID;
@property (nonatomic, strong) NSString *receipt;
@property (nonatomic, strong, nullable) SKPaymentTransaction *transaction;
- (instancetype)initWithProduct:(nullable IESProduct *)product
                        orderID:(nullable NSString *)orderID
                        receipt:(NSString *)receipt
                    transaction:(nullable SKPaymentTransaction *)transaction;

@end

NS_ASSUME_NONNULL_END
