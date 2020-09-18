//
//  BDTuringRemoteService.h
//  BDTuring
//
//  Created by bob on 2019/9/19.
//

#import "BDTuringService.h"
#import "BDTuringConfig.h"
#import "BDTuring.h"
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *_Nullable (^BDTuringDebugURLBlock) (NSInteger type, BDTuringRegionType vendor);

@interface BDTuringRemoteService : BDTuringService

@property (nonatomic, copy, readonly, nullable) NSString *maskRGB;
@property (nonatomic, assign, readonly) CGFloat maskAlpha;
@property (nonatomic, assign, readonly) long long period; /// 单位 毫秒
@property (nonatomic, assign, readonly) CGFloat width;
@property (nonatomic, assign, readonly) CGFloat height;

@property (nonatomic, strong) BDTuringConfig *config;
@property (nonatomic, assign) BOOL boe;

/// for Test
@property (nonatomic, strong, nullable) BDTuringDebugURLBlock debugURLBlock;

/// 会检查时间要求
- (NSInteger)checkAndFetchConfigForRegionType:(BDTuringRegionType)regionType;
/// 直接发请求
- (NSInteger)fetchConfigForRegionType:(BDTuringRegionType)regionType;


- (NSInteger)updateWithResponse:(nullable NSDictionary *)response;
- (nullable NSString *)pictureH5URLForRegionType:(BDTuringRegionType)regionType;
- (nullable NSString *)SMSH5URLForRegionType:(BDTuringRegionType)regionType;
- (nullable NSString *)infoHostForRegionType:(BDTuringRegionType)regionType;

@end

FOUNDATION_EXTERN BDTuringRemoteService *_Nullable turing_remoteService(NSString *appID);

NS_ASSUME_NONNULL_END
