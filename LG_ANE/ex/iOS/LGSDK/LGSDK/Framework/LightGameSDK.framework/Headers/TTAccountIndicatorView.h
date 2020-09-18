//
//  TTAccountIndicatorView.h
//  TTAccountSDK
//
//  Created by 冯靖君 on 16/1/26.
//
//

#import <UIKit/UIKit.h>
#import "NSBundle+TTAResources.h"



NS_ASSUME_NONNULL_BEGIN


@class TTAccountIndicatorView;
typedef
void (^TTAccountIndicatorViewDidDismissBlock)(TTAccountIndicatorView *indicateView, BOOL isUserTap);



typedef
NS_ENUM(NSInteger, TTAccountIndicatorViewStyle) {
    kTTAccountIndicatorViewStyleImage = 0,      //icon+文字样式
    kTTAccountIndicatorViewStyleWaitingView     //转等待提示+文字样式
};



@interface TTAccountIndicatorView : UIView

/**
 *  指示器是否显示手动dismiss按钮，默认NO
 */
@property (nonatomic, assign) BOOL showDismissButton;

/**
 *  指示器是否一定时间后自动消失，默认YES
 *  @Attention 需要控制指示器更新text或icon时，需要设置为NO
 */
@property (nonatomic, assign) BOOL autoDismiss;


#pragma mark - Instance initializer

/**
 *  创建实例指示器，可显示在指定view上，生命周期跟随view
 *
 *  @param style              指示器类型，不可同时显示icon和waitingView
 *  @param indicatorText      tip文字，可为空
 *  @param indicatorImage     icon图片
 *  @param handler            指示器消失后的处理block
 *
 *  @return 指示器实例
 */
- (instancetype)initWithIndicatorStyle:(TTAccountIndicatorViewStyle)style
                         indicatorText:(nullable NSString *)indicatorText
                        indicatorImage:(nullable UIImage *)indicatorImage
                        dismissHandler:(nullable TTAccountIndicatorViewDidDismissBlock)handler NS_DESIGNATED_INITIALIZER;
/**
 *  展示指示器
 *
 *  @param parentView 展示指示器的父superView
 */
- (void)showFromParentView:(nullable UIView *)parentView;

/**
 *  手动销毁指示器，通常在autoDismiss设为NO后使用
 */
- (void)dismissFromParentView;

/**
 *  更新指示器tip文字
 *
 *  @param newIndicatorText 更新后要显示的tip文字
 *  @param removed          如果指示器类型是TTIndicatorViewStyleWaitingView，是否需要停止并移除
 */
- (void)updateIndicatorWithText:(nullable NSString *)newIndicatorText
        shouldRemoveWaitingView:(BOOL)removed;

/**
 *  更新指示器iconImage，同时TTIndicatorViewStyle强制更新为TTIndicatorViewStyleImage
 *
 *  @param newIndicatorImage 更新后要显示的iconImage
 */
- (void)updateIndicatorWithImage:(nullable UIImage *)newIndicatorImage;


#pragma mark - Class initializer

/**
 *  创建便捷指示器，并显示在keyWindow（如果有，否则创建新的window）上
 *
 *  @param style              指示器类型，不可同时显示icon和waitingView
 *  @param indicatorText      tip文字，可为空
 *  @param indicatorImage     icon图片
 *  @param handler            指示器消失后的处理
 */
+ (void)showWithIndicatorStyle:(TTAccountIndicatorViewStyle)style
                 indicatorText:(nullable NSString *)indicatorText
                indicatorImage:(nullable UIImage *)indicatorImage
                   autoDismiss:(BOOL)autoDismiss
                dismissHandler:(nullable TTAccountIndicatorViewDidDismissBlock)handler;

/**
 *  强制销毁所有window上的所有指示器
 */
+ (void)dismissIndicators;

@end


NS_ASSUME_NONNULL_END
