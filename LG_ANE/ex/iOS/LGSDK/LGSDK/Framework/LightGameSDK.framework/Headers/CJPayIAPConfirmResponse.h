//
//  CJPayIAPConfirmResponse.h
//  CJPay
//
//  Created by 王新华 on 2019/3/17.
//
#import "CJPayBaseResponse.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJPayIAPConfirmResponse : CJPayBaseResponse

@property (nonatomic, copy) NSString *tradeNo;
@property (nonatomic, copy) NSString *deleteOrderCache;

@end

NS_ASSUME_NONNULL_END
