//
//  BDTuringConfig+Parameters.h
//  BDTuring
//
//  Created by bob on 2019/12/26.
//

#import "BDTuringConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDTuringConfig (Parameters)

- (NSMutableDictionary *)URLQueryParameters;
- (NSMutableDictionary *)eventParameters;

@end

NS_ASSUME_NONNULL_END
