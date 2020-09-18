//
//  BDTuringBridgeCommand.h
//  BDTuring
//
//  Created by bob on 2019/8/26.
//

#import <Foundation/Foundation.h>
#import "BDTuringBridgeConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDTuringBridgeCommand : NSObject

@property (nonatomic, assign) BDTuringBridgeType bridgeType;
@property (nonatomic, copy) NSString *messageType;
@property (nonatomic, copy) NSString *bridgeName;
@property (nonatomic, copy) NSString *callbackID;
@property (nonatomic, copy) NSDictionary *params;

@property (nonatomic, strong, nullable) BDTuringBridgeCallCompletion callCompletion;
@property (nonatomic, strong, nullable) BDTuringBridgeOnHandler onHandler;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (instancetype)initWithName:(NSString *)bridgeName onHandler:(BDTuringBridgeOnHandler)onHandler;

- (void)addCode:(BDTuringBridgeMsg)code response:(nullable NSDictionary *)response type:(NSString *)type;
- (NSString *)toJSONString;

@end

NS_ASSUME_NONNULL_END
