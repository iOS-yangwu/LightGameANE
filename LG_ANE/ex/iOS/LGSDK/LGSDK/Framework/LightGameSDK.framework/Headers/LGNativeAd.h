//
//  LGNativeAd.h
//  LightGameSDK
//
//  Created by wangchao on 2019/7/9.
//  Copyright © 2019 byteDance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LGAdSlot.h"
#import "LGMaterialMeta.h"
#import "LGDislikeWords.h"
#import "LGNativeAdRelatedView.h"
#import "LGAdImage.h"

@protocol LGNativeAdDelegate;


NS_ASSUME_NONNULL_BEGIN

@interface LGNativeAd : NSObject

/**
 Ad slot description.
 */
@property (nonatomic, strong, readwrite, nullable) LGAdSlot *adslot;

/**
 Ad slot material.
 */
@property (nonatomic, strong, readonly, nullable) LGMaterialMeta *data;

/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <BUNativeAdDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<LGNativeAdDelegate> delegate;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes 'pushViewController' and 'presentViewController'.
 */
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Initializes native ad with ad slot.
 @param slot : ad slot description.
 including slotID,adType,adPosition,etc.
 @return BUNativeAd
 */
- (instancetype)initWithSlot:(LGAdSlot *)slot;

/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view video ad details page, make a call, send email, download the app, open the webpage using a browser,open the webpage within the app, etc.
 @param containerView : required.
 container view of the native ad.
 @param clickableViews : optional.
 Array of views that are clickable.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterView;

/**
 Actively request nativeAd datas.
 */
- (void)loadAdData;

- (id)getBuNativeAd;

@end


@protocol LGNativeAdDelegate <NSObject>

@optional

/**
 This method is called when native ad material loaded successfully.
 */
- (void)nativeAdDidLoad:(LGNativeAd *)nativeAd;

/**
 This method is called when native ad materia failed to load.
 @param error : the reason of error
 */
- (void)nativeAd:(LGNativeAd *)nativeAd didFailWithError:(NSError *_Nullable)error;

/**
 This method is called when native ad slot has been shown.
 */
- (void)nativeAdDidBecomeVisible:(LGNativeAd *)nativeAd;

/**
 This method is called when native ad is clicked.
 */
- (void)nativeAdDidClick:(LGNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 This method is called when the user clicked dislike reasons.
 Only used for dislikeButton in BUNativeAdRelatedView.h
 @param filterWords : reasons for dislike
 */
- (void)nativeAd:(LGNativeAd *)nativeAd dislikeWithReason:(NSArray<LGDislikeWords *> *)filterWords;

@end


NS_ASSUME_NONNULL_END
