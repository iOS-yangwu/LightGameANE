//
//  TTAccountNewSessionTask.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/26/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTAccountDefine.h"



/**
 *  使用头条内部其他APP的SessionKey和该APP的installId来登录该APP
 *
 *  头条帐号使用跨应用`数据共享技术`进行登录
 */
@interface TTAccountNewSessionTask : NSObject
#pragma mark - 请求新的会话
/**
 *  使用SessionKey和InstallId请求新的会话
 *
 *  @param  sessionKey      当前会话Key
 *  @param  installId       新的InstallId
 *  @param  completedBlock  注册完成回调
 *  @return HTTP请求任务
 */
+ (id<TTAccountSessionTask>)requestNewSessionWithSessionKey:(NSString *)sessionKey
                                                  installId:(NSString *)installId
                                                 completion:(void(^)(TTAccountUserEntity *userEntity, NSError *error))completedBlock;
@end
