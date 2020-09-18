//
//  TTResponseModelProtocol.h
//  Pods
//
//  Created by ZhangLeonardo on 15/9/7.
//
//
//  同TTRequestModel，该接口也是为了脚本化而设计，不同的是返回使用的接口设计，请求使用的是基类设计
//  原因是各个业务组之前使用的model化的工具不同，这样，只要实现接口所需要的方法， 其他的，自行选择。
//  

#import <Foundation/Foundation.h>

@protocol TTResponseModelProtocol <NSObject>

-(id)initWithDictionary:(NSDictionary*)dict error:(NSError**)err;

@end

