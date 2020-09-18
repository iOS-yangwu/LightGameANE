//
//  BDTuringUtility.h
//  BDTuring
//
//  Created by bob on 2019/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN long long turing_currentIntervalMS(void);
FOUNDATION_EXTERN NSString * turing_queryFromDictionary(NSDictionary *params);
FOUNDATION_EXTERN NSString * turing_requestURLWithQuery(NSString *requestURL, NSDictionary *query);
FOUNDATION_EXTERN NSString * turing_sandBoxDocumentsPath(void);
FOUNDATION_EXTERN NSString * turing_sdkDocumentPath(void);
FOUNDATION_EXTERN NSString * turing_sdkDocumentPathForAppID(NSString *appID);
FOUNDATION_EXTERN NSString * turing_sdkDatabaseFileAppID(NSString *appID);
FOUNDATION_EXTERN NSBundle * turing_sdkBundle(void);

NS_ASSUME_NONNULL_END
