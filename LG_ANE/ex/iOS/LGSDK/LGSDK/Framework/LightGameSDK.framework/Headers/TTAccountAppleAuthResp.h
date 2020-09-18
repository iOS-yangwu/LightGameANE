//
//  TTAccountAppleAuthResp.h
//  TTAccountSDK
//
//  Created by 王鹏 on 2019/7/1.
//

#import "TTAccountAuthResponse.h"
#import <Foundation/NSPersonNameComponents.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTAccountAppleAuthResp : TTAccountAuthResponse

@property (nonatomic,   copy, nonnull) NSString *code;
@property (nonatomic, strong) NSPersonNameComponents *fulleName;
@property (nonatomic, copy) NSString *email;
/// 混淆后的用户email和name信息拼接的json串
@property (nonatomic, copy) NSString *extraData;
/** 第三方平台回传的状态state */
@property (nonatomic,   copy, nullable) NSString *state;

@end

NS_ASSUME_NONNULL_END
