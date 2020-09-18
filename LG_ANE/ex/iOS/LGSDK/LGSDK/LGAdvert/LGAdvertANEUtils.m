//
//  LGAdvertANEUtils.c
//  LGSDK
//
//  Created by 洋吴 on 2020/9/10.
//  Copyright © 2020 洋吴. All rights reserved.
//

#import "LGAdvertANEUtils.h"
#import "LGAdvertANE.h"

#pragma mark - string
NSString * LGAdvertGetStringFromFREObject(FREObject obj){
    
    uint32_t length;
    const uint8_t *value;
    FREGetObjectAsUTF8(obj, &length, &value);
    return [NSString stringWithUTF8String:(const char *)value];
}

FREObject LGAdvertCreateFREString(NSString * string){
    
    const char *str = [string UTF8String];
    FREObject obj;
    
    FRENewObjectFromUTF8((uint32_t)strlen(str)+1, (const uint8_t*)str, &obj);
    return obj;
}

#pragma mark - double
double LGAdvertGetDoubleFromFREObject(FREObject obj){
    
    double number;
    FREGetObjectAsDouble(obj, &number);
    return number;
}

FREObject LGAdvertCreateFREDouble(double value)
{
    FREObject obj = nil;
    FRENewObjectFromDouble(value, &obj);
    return obj;
}

#pragma mark int
int LGAdvertGetIntFromFREObject(FREObject obj){
    
    int32_t number;
    FREGetObjectAsInt32(obj, &number);
    return number;
}

FREObject LGAdvertCreateFREInt(int value){
    
    FREObject obj = nil;
    FRENewObjectFromInt32(value, &obj);
    return obj;
}

#pragma mark -bool
BOOL LGAdvertGetBoolFromFREObject(FREObject obj){
    
    uint32_t boolean;
    FREGetObjectAsBool(obj, &boolean);
    return boolean;
}

FREObject LGAdvertCreateFREBool(BOOL value){
    
    FREObject obj = nil;
    FRENewObjectFromBool(value, &obj);
    return obj;
}


#pragma mark objToJsonString
NSString *LGAdvertObj2ANEJSON(id obj){
    
    if (obj&&[NSJSONSerialization isValidJSONObject:obj]){
        
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:obj options:0 error:&error];
        if (jsonData==nil) {
            return @"";
        }
        NSString * json =[[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        return json;
    }
    return @"";
}


#pragma mark sendMessageToANE(NSString)
void LGAdvertSendANEMessage(int what,NSString *code,NSString *key,NSString *value){
    NSDictionary * dict = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithInt:what], @"what",value,key, nil];
    NSString *json = LGAdvertObj2ANEJSON(dict);
    LGAdvertANEDispatchStatusEventAsyn(code,json);
}

#pragma mark sendMessageToAne(Dictionary)
void LGAdvertSendANEMessageWithDict(NSDictionary *dict,NSString *code){
    
    NSString *json = LGAdvertObj2ANEJSON(dict);
    LGAdvertANEDispatchStatusEventAsyn(code,json);
}

void LGAdvertANEDispatchStatusEventAsyn(NSString  *type ,NSString *jsonString ){
    
    if(LGANEEventContext==NULL){
        return ;
    }
    const char * cTypeString = [type cStringUsingEncoding:NSUTF8StringEncoding];
    const char * cJsonString = [jsonString cStringUsingEncoding:NSUTF8StringEncoding];
    const uint8_t* ane_type = (const uint8_t*)cTypeString;
    const uint8_t* ane_params = (const uint8_t*) cJsonString;
    FREDispatchStatusEventAsync(LGANEEventContext,ane_type,ane_params);
}



