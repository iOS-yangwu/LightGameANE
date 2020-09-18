//
//  BDTuringURLConfig.h
//  BDTuring
//
//  Created by bob on 2019/8/27.
//

#import <Foundation/Foundation.h>
#import "BDTuringConfig.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, BDTuringURLType) {
    BDTuringURLTypeInfo,    ///< 信息
    BDTuringURLTypeVerify,  ///< 图片验证码
    BDTuringURLTypeSMS,     ///< 短信上行验证码
};


@interface BDTuringURLConfig : NSObject

+ (nullable NSString *)hostForType:(BDTuringURLType)type
                        regionType:(BDTuringRegionType)regionType
                             appID:(NSInteger)appID;

@end

NS_ASSUME_NONNULL_END
