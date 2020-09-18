//
//  CJPayIAPHeader.h
//  CJPay
//
//  Created by 王新华 on 9/22/19.
//

#ifndef CJPayIAPHeader_h
#define CJPayIAPHeader_h

#import "CJIAPOrderCenter.h"
#import "CJPayIAPConfirmResponse.h"
#import "CJIAPProductFilterTool.h"
#import "IESStoreManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CJPayIAPResultType) {
    CJPayIAPResultTypePaySuccess = 0, // 支付成功
    CJPayIAPResultTypePayFailure, // 支付失败
    CJPayIAPResultTypeFinishInApple, // 在Apple端finish 但是在财经服务器还没返回明确的结果
    CJPayIAPResultTypeCreateOrderFail,  // 下单失败
    CJPayIAPResultTypeHaveUnfinishOrder,  // 存在未完成订单
    CJPayIAPResultTypeUnknown,  //未知
};

typedef NS_ENUM(NSInteger, CJIAPStoreManagerErrorCode) {
    CJIAPStoreManagerErrorCodeUnFinishedOrder = 700,       // 有未完成订单
    CJIAPStoreManagerErrorCodeCreateOrderFailed,           // 新建订单失败
    CJIAPStoreManagerErrorCodeCacheOrderInfoFailed,        // 绑定订单号时失败
    CJIAPStoreManagerErrorCodeCacheAppleTransactionFailed, // 缓存苹果transaction时失败
    CJIAPStoreManagerErrorCodeConfirmNotSuccess,      // 到财经后台验证时，失败
    CJIAPStoreManagerErrorCodeRestoreWithoutIAPIDs,   // 调用restore，IAPIDs为空
    CJIAPStoreManagerErrorCodeHasUnconfirmedOrder,    // 存在未在财经后台校验通过的订单
};

typedef NS_ENUM(NSInteger, CJIAPStoreCreateOrderFailCode) {
    CJIAPStoreCreateOrderFailCodeHasUnConfirm,
    CJIAPStoreCreateOrderFailCodeHasPayingOrder,
    CJIAPStoreCreateOrderFailCodeRequestFail,
};

#define CJPayOrderPrefix @"CJ:"
#define CJPayIAPErrorDomain @"com.cjpay.error"

NS_ASSUME_NONNULL_END

#endif /* CJPayIAPHeader_h */
