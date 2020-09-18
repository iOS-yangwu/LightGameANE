//
//  BDAutoTrackDatabaseService.h
//  RangersAppLog
//
//  Created by bob on 2019/9/14.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN
@class BDAutoTrackBaseTable;

/// path:[BDAutoTrackUtility trackerDocumentPath]
///    - {$appid}/bytedance_auto_track.sqlite
@interface BDAutoTrackDatabaseService : BDAutoTrackService

- (instancetype)initWithAppID:(NSString *)appID;


/// key:tableName
- (NSDictionary<NSString *, NSArray *> *)allTracks;
- (void)insertTable:(NSString *)tableName
              track:(NSDictionary *)track
            trackID:(nullable NSString *)trackID;
- (void)removeTracks:(NSDictionary<NSString *, NSArray *> *)trackIDs;
- (NSArray<NSString *> *)allTableNames;

/// for monitor
- (BDAutoTrackBaseTable *)ceateTableWithName:(NSString *)tableName;

- (void)finalVacuumOrDelete;

@end

FOUNDATION_EXTERN BDAutoTrackDatabaseService * _Nullable bd_databaseServiceForAppID(NSString *appID);


FOUNDATION_EXTERN void bd_databaseInsertTrack(NSString *tableName,
                                              NSDictionary *track,
                                              NSString *_Nullable trackID,
                                              NSString *appID);
FOUNDATION_EXTERN void bd_databaseRemoveTracks(NSDictionary<NSString *, NSArray *> *trackIDs,
                                               NSString *appID);

FOUNDATION_EXTERN BDAutoTrackBaseTable * bd_databaseCeateTable(NSString *tableName, NSString *appID);

FOUNDATION_EXTERN NSString * bd_databaseFilePath(void); /// old database file
FOUNDATION_EXTERN NSString *bd_databaseFilePathAppID(NSString *appID);

NS_ASSUME_NONNULL_END
