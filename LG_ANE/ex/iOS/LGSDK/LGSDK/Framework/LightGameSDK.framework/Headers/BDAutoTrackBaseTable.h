//
//  BDAutoTrackBaseTable.h
//  Applog
//
//  Created by bob on 2019/1/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BDAutoTrackDatabaseQueue;

@interface BDAutoTrackBaseTable : NSObject

@property (nonatomic, copy, readonly) NSString *tableName;

- (instancetype)initWithTableName:(NSString *)tableName
                    databaseQueue:(BDAutoTrackDatabaseQueue *)databaseQueue;

- (void)insertTrack:(NSDictionary *)track;

- (void)insertTrack:(NSDictionary *)track
            trackID:(nullable NSString *)trackID;

- (void)removeTracksByID:(NSArray<NSString *> *)trackIDs;

- (NSArray<NSDictionary *> *)allTracks;

@end

NS_ASSUME_NONNULL_END
