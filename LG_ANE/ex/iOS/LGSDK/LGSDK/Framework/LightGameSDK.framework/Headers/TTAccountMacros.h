//
//  TTAccountMacros.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 2/9/17.
//  Copyright © 2017 com.bytedance.news. All rights reserved.
//

#ifndef TTAccountMacros_h
#define TTAccountMacros_h



/***********************************************************
 *                                                         *
 *                  Singleton macros                       *
 *                                                         *
 ***********************************************************/
#define TTAccountSingletonDecl \
    + (instancetype)sharedInstance;

#define TTAccountSingletonImp \
    + (instancetype)sharedInstance { \
        static id sharedInst = nil;     \
        static dispatch_once_t onceToken; \
        dispatch_once(&onceToken, ^{    \
            sharedInst = [self new];    \
        });     \
        return sharedInst;  \
    }



#ifdef TTAccountIsEmptyString
    #undef TTAccountIsEmptyString
#endif
#define TTAccountIsEmptyString(str) \
    (!str || ![str isKindOfClass:[NSString class]] || str.length == 0)
#ifdef TTAccountIsEmptyDictionary
    #undef TTAccountIsEmptyDictionary
#endif
#define TTAccountIsEmptyDictionary(dic) \
    (!dic || ![dic isKindOfClass:[NSDictionary class]] || dic.count == 0)




/***********************************************************
 *                                                         *
 *                  dispatch macros                        *
 *                                                         *
 ***********************************************************/
#ifdef tta_dispatch_sync_main_thread_safe
    #undef tta_dispatch_sync_main_thread_safe
#endif
#define tta_dispatch_sync_main_thread_safe(block) \
    ({   \
        typeof (block) _tmpBlockInDispatch = (block); \
        if ([NSThread isMainThread]) { \
            if (_tmpBlockInDispatch) _tmpBlockInDispatch(); \
        } else { \
            dispatch_sync(dispatch_get_main_queue(), ^{if (_tmpBlockInDispatch) _tmpBlockInDispatch();}); \
        }   \
    })



#ifdef tta_dispatch_async_main_thread_safe
    #undef tta_dispatch_async_main_thread_safe
#endif
#define tta_dispatch_async_main_thread_safe(block) \
    ({   \
        typeof (block) _tmpBlockInDispatch = (block); \
        if ([NSThread isMainThread]) { \
            if (_tmpBlockInDispatch) _tmpBlockInDispatch(); \
        } else { \
            dispatch_async(dispatch_get_main_queue(), ^{if (_tmpBlockInDispatch) _tmpBlockInDispatch();}); \
        }   \
    })



/***********************************************************
 *                                                         *
 *                  Color Macros                           *
 *                                                         *
 ***********************************************************/
#define TTAccountUIColorFromHexRGB(rgbValue) \
    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                    green:((float)((rgbValue & 0x00FF00) >>  8))/255.0 \
                     blue:((float)((rgbValue & 0x0000FF) >>  0))/255.0 \
                    alpha:1.0]

#define TTAccountUIColorFromHexRGBA(rgbaValue) \
    [UIColor colorWithRed:((float)((rgbaValue & 0xFF000000) >> 24))/255.0 \
                    green:((float)((rgbaValue & 0x00FF0000) >>  16))/255.0 \
                     blue:((float)((rgbaValue & 0x0000FF00) >>  8))/255.0 \
                    alpha:((float)((rgbaValue & 0x000000FF) >>  0))/255.0]



/***********************************************************
 *                                                         *
 *                  Device Context                         *
 *                                                         *
 ***********************************************************/
#define TTACCOUNT_IS_IPAD \
    (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define TTACCOUNT_IS_IPHONE \
    (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define TTACCOUNT_DEVICE_SYS_VERSION \
    ([[[UIDevice currentDevice] systemVersion] floatValue])

typedef NS_ENUM(NSUInteger, TTAccountSMSCheckScene) {
    TTAccountSMSCheckResetPWD,//重置密码
};

typedef NS_ENUM(NSUInteger, TTAccountLoginScene) {
    TTAccountQuickRegister,//手机号短信注册
    TTAccountQuickLogin,//手机号短信登录
    TTAccountPWDLogin, //帐号密码登录
    TTAccountPWDMergeAuthToken, //账密登录帐号，帐号合并场景下获取授权token
    TTAccountEmailPWDLogin, //邮箱密码登录
    TTAccountMobilePWDLogin, //手机号密码登录
    TTAccountOneKeyLogin, //火山一键登录
};

typedef NS_ENUM(NSUInteger, TTAccountPWDScene) {
    TTAccountSetPWD,//初始化密码
    TTAccountChangePWD, //修改密码
    TTAccountResetPWD, //忘记密码的时候点击重置密码
    TTAccountResetPWDByTicket, //忘记密码的时候点击重置密码,使用ticket重置密码
};

typedef NS_ENUM(NSUInteger, TTAccountMergeScene) {
    TTAccountCheckPrimaryAccount,//检查能否作为主帐号
    TTAccountMergeAccount, //帐号合并
};

typedef NS_ENUM(NSUInteger, TTAccount3rdAuthScene) {
    TTAccount3rdLogin, //第三方登录
    TTAccount3rdBind, //第三方绑定
    TTAccount3rdMergeToken, //获取被合并的第三方帐号信息
};

typedef NS_ENUM(NSUInteger, TTAccountCommandType) {
    TTAccountLoginCommand  = 100,//登录（快速登录/火山专用一键登录/账密登录）
    TTAccountLogoutCommand = 200,//登出
    //TTAccountRegisterCommand = 300,//手机号注册
    TTAccountGetSMSCodeCommand = 400,//获取短信验证码
    TTAccountGetVoiceCodeCommand = 500,//获取语音验证码
    TTAccountGetCaptchaCommand = 600,//图片验证码（获取/刷新）
    TTAccountSetPWDCommand = 700,//密码相关（初始化/修改/重置）
    TTAccountBindMobileCommand = 800,//手机号绑定
    TTAccountUnbindMobileCommand = 900,//手机号解绑
    TTAccountChangeMobileCommand = 1000,//修改手机号
    TTAccountGetSharedAccountCommand = 1100,//获得共享帐号（例如西瓜、抖音）信息
    TTAccountGetMergeAccountCommand = 1200,//获取被合并帐号信息
    TTAccountMergeCommand = 1300,//合并
    TTAccountSMSCheckCommand = 1400,//短信验证码校验
};

typedef NS_ENUM(NSUInteger, TTAccount3rdCommandType) {
    TTAccount3rdAuthCommand = 3000,//第三方授权（登录/绑定/获取被合并的第三方帐号信息）
    TTAccount3rdUnbindCommand = 3100,//第三方帐号解绑
    TTAccount3rdSwitchBindCommand = 3200,//第三方帐号换绑（使用第三方平台SDK授权成功后，绑定头条帐号时发现该第三方帐号已绑定其它头条帐号时，进行解绑操作）
};

#endif /* TTAccountMacros_h */
