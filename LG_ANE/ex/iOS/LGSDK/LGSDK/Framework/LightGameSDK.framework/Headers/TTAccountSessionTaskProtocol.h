//
//  TTAccountSessionTaskProtocol.h
//  TTAccountSDK
//
//  Created by liuzuopeng on 12/9/16.
//  Copyright © 2016 com.bytedance.news. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TTASessionTaskState) {
    TTASessionTaskStateRunning   = 0,
    TTASessionTaskStateSuspended = 1,
    TTASessionTaskStateCanceling = 2,
    TTASessionTaskStateCompleted = 3,
};


@protocol TTAccountSessionTask <NSObject>
@required
/*
 * The current state of the task.
 */
@property (readonly) TTASessionTaskState state;

/* -cancel returns immediately, but marks a task as being canceled.
 * The task will signal -URLSession:task:didCompleteWithError: with an
 * error value of { NSURLErrorDomain, NSURLErrorCancelled }.  In some
 * cases, the task may signal other work before it acknowledges the
 * cancelation.  -cancel may be sent to a task that has been suspended.
 */
- (void)cancel;

/*
 * Suspending a task will prevent the NSURLSession from continuing to
 * load data.  There may still be delegate calls made on behalf of
 * this task (for instance, to report data received while suspending)
 * but no further transmissions will be made on behalf of the task
 * until -resume is sent.  The timeout timer associated with the task
 * will be disabled while a task is suspended. -suspend and -resume are
 * nestable.
 */
- (void)suspend;
- (void)resume;

/*
 * Sets a scaling factor for the priority of the task. The scaling factor is a
 * value between 0.0 and 1.0 (inclusive), where 0.0 is considered the lowest
 * priority and 1.0 is considered the highest.
 *
 * The priority is a hint and not a hard requirement of task performance. The
 * priority of a task may be changed using this API at any time, but not all
 * protocols support this; in these cases, the last priority that took effect
 * will be used.
 *
 * If no priority is specified, the task will operate with the default priority
 * as defined by the constant NSURLSessionTaskPriorityDefault. Two additional
 * priority levels are provided: NSURLSessionTaskPriorityLow and
 * NSURLSessionTaskPriorityHigh, but use is not restricted to these.
 */
- (void)setPriority:(float)priority;
@end

NS_ASSUME_NONNULL_END

