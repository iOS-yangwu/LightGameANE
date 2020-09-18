//
//  LGAntiAddictionResultModel.h
//  LightGameSDK
//
//  Created by wangchao on 2019/12/6.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


// 防沉迷策略
typedef NS_ENUM(NSInteger, LGAntiAddictionPolicy) {
    LGAntiAddictionPolicyAdult = 1,     // 成年人，无限制
    LGAntiAddictionPolicyNotAdult,      // 未成年(1.5h/d,节假日3h/d,22:00-8:00禁止玩)
    LGAntiAddictionPolicyUserGuest,     // 账户游客(1.5h/15d，未实名设备15天不得重复创建游客)；游客实名后就成为未成年或成年人角色
    LGAntiAddictionPolicyDeviceGuest    // 设备游客(暂同未成年，时间段限制依靠配置项)
};

// 限制类型
typedef NS_ENUM(NSInteger, LGAntiAddictionLimitType) {
    LGAntiAddictionLimitTypeNone = 0,
    LGAntiAddictionLimitTypeTimeUsed,                // 可用时间用完
    LGAntiAddictionLimitTypeInLimitDuration,         // 处于限制时间段(比如未成年人晚间限制)
    LGAntiAddictionLimitTypeGuestRecreate,           // 未实名设备15天内不能重复创建游客
    LGAntiAddictionLimitTypeGuestExperenceTimeUsed,  // 游客体验时长用尽
    LGAntiAddictionLimitTypePreReminder              // 前置提醒
};

@interface LGAntiAddictionResultModel : NSObject

// 剩余时长 单位：min 当limitType != LGAntiAddictionLimitTypeInLimitDuration有效；会在游戏时长还剩30min和15min时候回调该信息
@property (nonatomic, assign) long canPlayTime;

// 达到防沉迷限制的类型
@property (nonatomic, assign) LGAntiAddictionLimitType limitType;

// 防沉迷策略
@property (nonatomic, assign) LGAntiAddictionPolicy antiAddictionPolicy;

@end

NS_ASSUME_NONNULL_END
