//
//  BDTuringVerifyView.h
//  BDTuring
//
//  Created by bob on 2019/8/29.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "BDTuring.h"
#import "BDTuringConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class WKWebView, BDTuringVerifyView, BDTuringRemoteService;

@protocol BDTuringVerifyViewDelegate;

@protocol BDTuringVerifyViewDelegate <NSObject>

@optional;

- (void)verifyViewDidShow:(BDTuringVerifyView *)verifyView;
- (void)verifyViewDidHide:(BDTuringVerifyView *)verifyView;
- (void)verifyViewDidDismiss:(BDTuringVerifyView *)verifyView;

- (void)verifyWebViewLoadDidSuccess:(BDTuringVerifyView *)verifyView;
- (void)verifyWebViewLoadDidFail:(BDTuringVerifyView *)verifyView;

@end


@interface BDTuringVerifyView : UIView<WKNavigationDelegate>


#pragma mark - BDTuringVerifyView

@property (nonatomic, strong, readonly) WKWebView *webView;
@property (nonatomic, assign, readonly) BDTuringRegionType regionType;
@property (nonatomic, copy, readonly) NSString *appID;
@property (nonatomic, weak, nullable) id<BDTuringVerifyViewDelegate> delegate;
@property (nonatomic, strong, nullable) BDTuringVerifyCallback callback;

@property (nonatomic, assign) long long startLoadTime;
@property (nonatomic, assign) NSInteger challengeCode;
@property (nonatomic, copy, nullable) NSString *scene;
@property (nonatomic, assign) BOOL shouldCloseFromMask;
@property (nonatomic, strong) BDTuringConfig *config;
@property (nonatomic, strong) BDTuringRemoteService *remote;

+ (instancetype)verifyViewAppID:(NSString *)appID
                     regionType:(BDTuringRegionType)regionType
                     verifyType:(BDTuringVerifyType)verifyType
                 presentingView:(nullable UIView *)presentingView;


- (void)adjustWebViewPosition;

- (void)closeVerifyViewFromFeedbackClose;
- (void)closeVerifyViewFromFeedbackButton;
- (void)closeVerifyViewFromMask;

- (void)loadVerifyWebView;
- (void)showVerifyView;
- (void)hideVerifyView;     /// only hide then will be dismissed
- (void)dismissVerifyView;  /// dismiss when verify end
- (void)closeVerifyView:(NSString *)reason;    /// hide then dismiss

@end

NS_ASSUME_NONNULL_END
