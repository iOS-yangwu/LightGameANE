//
//  BDTuringJSBridge.h
//  BDTuring
//
//  Created by bob on 2019/8/26.
//

#import <Foundation/Foundation.h>
#import "BDTuringBridgeConstant.h"

NS_ASSUME_NONNULL_BEGIN
@class WKWebView;

@interface BDTuringJSBridge : NSObject

@property (nonatomic, weak, nullable, readonly)  WKWebView *webView;


- (instancetype)initWithWebView:(WKWebView *)webView;
- (void)uninstallBridge;

- (BOOL)webOnBridge:(NSString *)bridgeName;

- (void)call:(NSString *)bridgeName
         msg:(BDTuringBridgeMsg)msg
      params:(nullable NSDictionary *)params
  completion:(nullable BDTuringBridgeCallCompletion)completion;

- (void)on:(NSString *)bridgeName callback:(BDTuringBridgeOnHandler)callback;


@end

NS_ASSUME_NONNULL_END
