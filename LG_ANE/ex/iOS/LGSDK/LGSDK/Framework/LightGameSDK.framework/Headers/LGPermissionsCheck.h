//
//  ADPermissionsCheck.h
//  DeliverManager
//
//  Created by 王启威 on 2018/11/6.
//  Copyright © 2018 com.bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, ADPermissionsCheckType) {
    ADPermissionsCheckTypeAudio = 1 << 0,  // 麦克风
    ADPermissionsCheckTypeCamera = 1 << 1,  // 摄像头
    ADPermissionsCheckTypeLocation = 1 << 2,  // 定位
    ADPermissionsCheckTypePhotoLibrary = 1 << 3,  // 相册
    ADPermissionsCheckTypeNetworking = 1 << 4,  // 联网
    ADPermissionsCheckTypePush = 1 << 5,  // push
    ADPermissionsCheckTypeContacts = 1 << 6,  // 通讯录
    ADPermissionsCheckTypeEvent = 1 << 7,  // 日历
    ADPermissionsCheckTypeReminder = 1 << 8,   // 备忘录
};

typedef void(^ADPermissionsCheckBlock)(ADPermissionsCheckType type, BOOL isPermissionsAll);
typedef void(^ADPermissionsResultBlock)(BOOL isCancle);

NS_ASSUME_NONNULL_BEGIN

@interface LGPermissionsCheck : NSObject

/**
 检查相册权限
 
 @param show 是否显示弹框
 @param go 弹框是否有前往设置按钮
 @param blk 检查回调
 @param resultBlk 点击取消回调
 */
+ (void)checkPhotoLibraryWithShowAlert:(BOOL)show goSetting:(BOOL)go checkBlock:(ADPermissionsCheckBlock)blk resultBlock:(ADPermissionsResultBlock)resultBlk;

@end

NS_ASSUME_NONNULL_END
