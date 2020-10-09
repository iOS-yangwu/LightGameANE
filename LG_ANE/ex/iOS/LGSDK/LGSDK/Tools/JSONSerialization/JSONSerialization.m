//
//  JSONSerialization.m
//
//  Created by 洋吴 on 2019/12/25.
//  Copyright © 2019 洋吴. All rights reserved.
//

#import "JSONSerialization.h"

@implementation JSONSerialization

+ (NSString *)toJsonStringWithDict:(NSDictionary *)dic{
    NSError *err;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dic options:0 error:&err];
    
    NSString *jsonString;
    if (!jsonData) {
        NSLog(@"%@",err);
    }else{
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    
    return jsonString;
}

+ (NSArray *)toArrayWithJsonString:(NSString *)jsonString{
    
    if (jsonString != nil) {
        NSData* data = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err;
        id jsonObject = [NSJSONSerialization JSONObjectWithData:data
                                                        options:NSJSONReadingAllowFragments
                                                          error:&err];
 
        if (err) return nil;
        
        if (jsonObject != nil){
            
            return jsonObject;
            
        }else{
            
            return nil;
        }
    }
    return nil;
}

+ (NSString *)convertToJsonData:(NSDictionary *)dict{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict
                                                       options:NSJSONWritingPrettyPrinted
                                                         error:&error];
    NSString *jsonString;
    
    if (!jsonData) {
        
        jsonString = @"";
        
    }else{
        
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    
    NSMutableString *mutStr = [NSMutableString stringWithString:jsonString];
    NSRange range = {0,jsonString.length};
    [mutStr replaceOccurrencesOfString:@" " withString:@"" options:NSLiteralSearch range:range];
    NSRange range2 = {0,mutStr.length};
    [mutStr replaceOccurrencesOfString:@"\n" withString:@"" options:NSLiteralSearch range:range2];
    return mutStr;
}

+ (NSDictionary *)toDictionaryWithJsonString:(NSString *)jsonString{
    
    if (jsonString == nil) return @{};
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData options:0 error:&err];
    if(err) return @{};
    return dic;
}

@end
