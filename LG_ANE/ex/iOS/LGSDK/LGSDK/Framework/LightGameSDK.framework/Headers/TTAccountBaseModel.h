//
//  TTAccountBaseModel.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/5/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTHTTPRequestSerializerProtocol.h"
#import "TTNetworkManager.h"
#import "TTRequestModel.h"
#import "TTAModelling.h"
#import "TTAccountDataModel.h"


/**
 *  所有使用Model的网络Request必须继承该类
 */
@interface TTABaseReqModel : TTRequestModel

@end



/**
 *  所有Response的Model都继承该类
 */
@interface TTABaseRespModel : NSObject
<
TTResponseModelProtocol
>

/**
 *  服务端返回的消息名称
 *  如success、exception、error
 */
@property (nonatomic, copy) NSString *message;

/**
 *  本次请求是否成功
 */
- (BOOL)isRespSuccess;

/**
 *  是否是服务端错误
 */
- (BOOL)isServerError;

/**
 *  是否是客户端参数错误
 */
- (BOOL)isClientError; //请求接口数据有问题（如果参数错误）

/**
 *  失败且不是服务端和客户端错误
 */
- (BOOL)isOtherRespError;

/**
 *  返回当前的错误码
 */
- (NSInteger)errorCode;

/**
 *  返回错误描述
 */
- (NSString *)errorDescription;

/**
 *  Transform Dictionary
 */
- (NSDictionary *)toDictionary;

@end




