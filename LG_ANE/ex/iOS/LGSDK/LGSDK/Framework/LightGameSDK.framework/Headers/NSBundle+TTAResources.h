//
//  NSBundle+TTAResources.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 4/19/17.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UIButton.h>
#import "NSString+TTAccountUtils.h"



NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (tta_ResourceBundle)

+ (NSBundle *)tta_resourceBundle;

@end



@interface UIImage (tta_AccountResources)

+ (UIImage *)tta_imageNamed:(NSString *)name;

@end



@interface UIImageView (tta_ImageLoaderByName)

@property (nonatomic, copy) NSString *tta_imageName;

@end



@interface UIButton (tta_ImageLoaderByName)

/** set Normal State image */
@property (nonatomic, copy) NSString *tta_imageName;

/** set Highlighted State image */
@property (nonatomic, copy) NSString *tta_hlImageName;

@end

NS_ASSUME_NONNULL_END

