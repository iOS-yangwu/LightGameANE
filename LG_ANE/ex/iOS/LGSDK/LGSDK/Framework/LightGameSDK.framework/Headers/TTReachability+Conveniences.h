//
//  TTReachability+Conveniences.h
//  TTReachability
//
//  Created by 李卓立 on 2019/10/22.
//

#import "TTReachability.h"

@interface TTReachability (Conveniences)

/**
 便携方法，返回当前优先使用的SIM卡的Carrier对象数组，用来获取SIM卡的MNC等数据，主要是一些上报场景，目前按照以下规则获取实现：
 1. 单卡（或者双卡但设置中仅开启单张卡），返回 `[单卡]`
 2. 双卡，流量卡可知（iOS 13），返回 `[流量卡, 另一张卡]`
 3. 双卡，流量卡不可知（iOS 12），返回 `[主卡, 副卡]`
 4. 其他情况，返回 `[]`
 
 @warning 规则不一定满足任何需求，仅仅是一个便携方法，有自定义规则请使用提供的接口组合实现
 @return 按照以上规则进行筛选得到的SIM卡的Carrier对象数组
 */
+ (nonnull NSArray<CTCarrier *> *)currentPrioritizedCellularProviders;

/**
 便携方法，返回当前优先使用的SIM卡的CTRadioAccessTechnology数组，用来获取蜂窝连接的详细制式，主要是一些上报场景，目前按照以下规则获取实现：
 1. 单卡（或者双卡但设置中仅开启单张卡），返回 `[单卡]`
 2. 双卡，流量卡可知（iOS 13），返回 `[流量卡, 另一张卡]`
 3. 双卡，流量卡不可知（iOS 12），返回 `[主卡, 副卡]`
 4. 其他情况，返回 `[]`
 
 @warning 规则不一定满足任何需求，仅仅是一个便携方法，有自定义规则请使用提供的接口组合实现
 @return 按照以上规则进行筛选得到的SIM卡的CTRadioAccessTechnology数组
 */
+ (nonnull NSArray<NSString *> *)currentPrioritizedRadioAccessTechnologies;

@end
