//
//  NSData+GZip.h
//  Applog
//
//  Created by bob on 2019/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (BDGZip)

- (nullable NSData *)applog_dataByDecorator;

- (nullable NSData *)bd_dataByGZipCompressingWithError:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
