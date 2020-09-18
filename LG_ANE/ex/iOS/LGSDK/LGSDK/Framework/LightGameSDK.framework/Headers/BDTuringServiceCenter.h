//
//  BDTuringServiceCenter.h
//  BDTuring
//
//  Created by bob on 2019/9/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol BDTuringService;

@interface BDTuringServiceCenter : NSObject

+ (instancetype)defaultCenter;

#pragma mark - commom use

/// will strong hold service
- (void)registerService:(id<BDTuringService>)service;
- (void)unregisterService:(id<BDTuringService>)service;
- (nullable id<BDTuringService>)serviceForName:(NSString *)serviceName appID:(NSString *)appID;

- (void)unregisterAllServices;

@end

FOUNDATION_EXTERN NSMutableDictionary * turing_headerFiled(NSString *appID);

NS_ASSUME_NONNULL_END
