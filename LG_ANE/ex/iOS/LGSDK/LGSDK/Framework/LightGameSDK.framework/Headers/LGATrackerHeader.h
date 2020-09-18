//
//  LGATrackerHeader.h
//  Tracker
//
//  Created by fengyadong on 2017-3-14.
//  Copyright (c) 2017 toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>

static const NSUInteger kLGATrackerSDKVersion = 163;
static const NSString *kLGATrackerSDKVersionName = @"1.6.3";
static const NSString *kLGATrackerSDKType = @"lg_sdk";

/// 事件类型
typedef NS_ENUM(NSInteger,TTTrackEventType) {
    /// 正常事件
    TTTrackNormalEvent = 0,
    /// CDN事件，已废弃
    TTTrackCDNEvent = 1110
};

/// 网络状态
typedef NS_ENUM(NSInteger, LGAInstallNetworkConnection) {
    /// 初始状态
    LGAInstallNetworkNone = -1,
    /// 无网络连接
    LGAInstallNetworkNoConnection = 0,
    /// 移动网络连接
    LGAInstallNetworkMobileConnnection = 1,
    /// 2G网络连接
    LGAInstallNetwork2GConnection = 2,
    /// 3G网络连接
    LGAInstallNetwork3GConnection = 3,
    /// wifi网络连接
    LGAInstallNetworkWifiConnection = 4,
    /// 4G网络连接
    LGAInstallNetwork4GConnection = 5
};

/// 上报策略
typedef NS_ENUM(NSInteger, TTTrackPolicy) {
    /// 初始状态
    TTTrackPolicyNone = -1,
    /// 批量发送
    TTTrackPolicyBatch = 1,
    /// 实时发送
    TTTrackPolicyCritical = 2,
};

/// 上报触发场景
typedef NS_ENUM(NSUInteger, LGATrackerCleanerStartCleanFromType) {
    /// app启动触发
    LGATrackerCleanerStartCleanFromInitAppKey,
    /// 定时器触发
    LGATrackerCleanerStartCleanFromTimer,
    /// 切到前台触发
    LGATrackerCleanerStartCleanFromAppWillEnterForground,
    /// 切到后台触发
    LGATrackerCleanerStartCleanFromAppDidEnterBackground,
};

/// APP启动时上报启动原因,wiki: https://wiki.bytedance.com/pages/viewpage.action?pageId=55125960
typedef NS_ENUM(NSUInteger, LGATrackerLaunchFrom) {
    /// 初始状态
    LGATrackerLaunchFromInitialState = 0,
    /// 用户手动点击进入app
    LGATrackerLaunchFromUserClick = 1,
    /// 用户通过push点击进入app
    LGATrackerLaunchFromRemotePush = 2,
    /// 用户通过widget点击进入app
    LGATrackerLaunchFromWidget = 3,
    /// 用户通过sptlight点击进入app
    LGATrackerLaunchFromSpotlight = 4,
    /// 用户通过外部app唤醒进入app
    LGATrackerLaunchFromExternal = 5,
    /// 用户手动切回前台
    LGATrackerLaunchFromBackground = 6,
};
