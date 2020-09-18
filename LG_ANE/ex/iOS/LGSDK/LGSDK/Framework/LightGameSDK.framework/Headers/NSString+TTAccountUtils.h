//
//  NSString+TTAccountUtils.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 10/19/16.
//  Copyright © 2016 Toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@interface NSString (tta_ContainsString)
- (BOOL)tta_containsString:(NSString *)aString;
@end

@interface NSString (tta_ConvertToJson)
- (NSDictionary *)tta_convertToDictionary;
@end

@interface NSString (tta_ImageOfBase64String)
/** 解码Base64字符串为图片 */
- (UIImage *)tta_imageFromBase64String;
/** 解码Base64字符串为图片数据流 */
- (NSData  *)tta_imageDataFromBase64String;
@end



@interface NSString (tta_URLEnDecoder)
/** 对字符串进行URL编码 */
- (NSString *)tta_URLEncodedString;
/** 对字符串进行URL解码 */
- (NSString *)tta_URLDecodedString;
@end



@interface NSString (tta_HexMix)
/** 对字符串进行混淆 */
- (NSString *)tta_hexMixedString;

- (NSString *)tta_MD5String;

@end



@interface NSString (tta_URLUtils)
/** 将字符串转化为对应的URL */
- (NSURL *)tta_URL;
/** 追加Query项至字符串并转化为对应的URL */
- (NSURL *)tta_URLByAppendQueryItems:(NSDictionary *)items;
/** 追加Query项至URL字符串 */
- (NSString *)tta_URLStringByAppendQueryItems:(NSDictionary *)items;
@end



@interface NSURL (tta_URLUtils)
/** 追加Query项至URL并生成新的URL */
- (NSURL *)tta_URLByAppendQueryItems:(NSDictionary *)items;
/** 解析URL，获取query items */
- (NSDictionary *)tta_queryDictionary;
@end



