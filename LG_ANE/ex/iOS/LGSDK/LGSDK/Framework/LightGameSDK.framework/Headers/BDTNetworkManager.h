//
//  BDTNetworkManager.h
//  BDTuring
//
//  Created by bob on 2019/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDTNetworkManager : NSObject

+ (nullable NSDictionary *)syncRequestForURL:(NSString *)requestURL
                                      method:(NSString *)method
                                 headerFiled:(nullable NSDictionary *)headerField
                             queryParameters:(nullable NSDictionary *)queryParameters;

@end

NS_ASSUME_NONNULL_END
