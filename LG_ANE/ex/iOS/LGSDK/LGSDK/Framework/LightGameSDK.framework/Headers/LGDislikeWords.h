//
//  LGDislikeWords.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BUDislikeWords;
@interface LGDislikeWords : NSObject

@property (nonatomic, copy, readonly) NSString *dislikeID;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, assign, readonly) BOOL isSelected;
@property (nonatomic, copy, readonly) NSArray<LGDislikeWords *> *options;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError **)error;

+ (NSArray<LGDislikeWords *> *)getLgOptions:(NSArray<BUDislikeWords *> *)buArr;

@end

NS_ASSUME_NONNULL_END
