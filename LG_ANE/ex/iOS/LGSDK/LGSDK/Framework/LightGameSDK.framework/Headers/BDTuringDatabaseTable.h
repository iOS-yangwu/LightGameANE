//
//  BDTuringDatabaseTable.h
//  BDTuring
//
//  Created by bob on 2019/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FMDatabaseQueue;

@interface BDTuringDatabaseTable : NSObject

- (instancetype)initWithTableName:(NSString *)tableName databaseQueue:(FMDatabaseQueue *)databaseQueue;

- (void)insertTrack:(NSString *)track;
- (void)removeTracksByID:(NSArray<NSString *> *)trackIDs;
- (NSMutableDictionary *)allTracks;

@end

NS_ASSUME_NONNULL_END
