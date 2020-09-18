//
//  CJIAPProductFilterTool.h
//  CJPay
//
//  Created by 王新华 on 2019/7/3.
//

#import <Foundation/Foundation.h>
#import "CJIAPOrderCenter.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJIAPProductFilterTool : NSObject

+ (NSArray<CJIAPProduct *>*)filterSpecifyProducts:(NSArray<CJIAPProduct *>*)unconfirmProducts productID:(NSString *)productID;

@end

NS_ASSUME_NONNULL_END
