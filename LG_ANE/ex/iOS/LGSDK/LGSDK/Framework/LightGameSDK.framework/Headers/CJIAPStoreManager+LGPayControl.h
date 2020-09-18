//
//  CJIAPStoreManager+LGPayControl.h
//  LightGameSDK
//
//  Created by peiziming on 2020/3/3.
//  Copyright © 2020 byteDance. All rights reserved.
//

#import <LightGameSDK/LightGameSDK.h>

typedef NS_ENUM(NSInteger, LGIsCanPayErrorCode) {
    LGIsCanPaySuccess = 0, // 可以支付
    LGIsCanPayNetError = 1011, // 请求失败
    LGIsCanPayUnLogin = 1010, // 用户未登录
    LGIsCanPayParamError = 4, // 参数错误
    LGIsCanPayDataBaseError = 10, // 服务器数据库错误
    LGIsCanPayPayloadError = 60000, // external_order_payload 反序列化错误
    LGIsCanPaySignError = 60002, // 签名错误
    LGIsCanPayUserError = 60003, // 用户不匹配
    LGIsCanPayNoRealNameError = 61001, // 用户未实名
    LGIsCanPayEightYearsOldError = 61002, // 8岁以下用户禁止支付
    LGIsCanPaySingleLimitError = 61003, // 未成年用户达到单次支付限额
    LGIsCanPayLimitError = 61004, // 未成年用户达到月限额
};

@protocol LGPayControlDelegate <NSObject>

/**
 *  支付前服务端创建订单接口结果返回  如：在调用IAP支付前，未登录或支付参数错误等问题。
 */
- (void)lgPayErrorCode:(LGIsCanPayErrorCode)code errorMsg:(NSString *_Nonnull)errorMsg;

@end

@interface CJIAPStoreManager (LGPayControl)

/**
 * 支付前服务端创建订单接口结果返回协议
 */
@property(nonatomic, weak) id <LGPayControlDelegate> _Nullable lgPayDelegate;

/*
 注册回调服务
 @param delegate 支付结果回调
 **/
- (void)registerLGServices:(id <CJIAPStoreDelegate>_Nonnull) delegate;

/*
 * 调起支付接口
 * @param bizParams 订单相关参数
 * 参数举例（更详细信息参考服务文档说明）
 {
    "order_no" : "2020-03-23 15:12:01", // 订单号
    "product_id" : "50006", // 产品id
    "custom_callback_info" : "--", // 自定义回调信息
    "valid_time" : 900,    // 订单有效期，单位为秒
    "sign_type" : "MD5",  // 签名类型 仅支持MD5
    "total_amount" : 6,   // 订单金额，单位为分
    "subject" : "测试商品", // 订单名称
    "notify_url" : "https:\/\/tt.test", // 游戏服务端异步回调地址
    "trade_time" : 1584947521,  // 订单创建时间
    "body" : "测试商品", // 订单详情
    "sign" : "C7BA4CAE0A26D2CC545F37C9CFC0DE64" // 签名
 }
 **/
- (void)lg_startIAPWithJsonStringParams:(NSString *_Nonnull)bizParams;

/*
 * 是否可以支付
 * @param totalAmount 订单支付金额
 */
- (void)isCanPay:(NSInteger)totalAmount complete:(void(^_Nonnull)(BOOL isCanPay, LGIsCanPayErrorCode status, NSString * _Nullable message))complete;

@end
