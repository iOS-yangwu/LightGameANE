//
//  BDTuringMacro.h
//  BDTuring
//
//  Created by bob on 2019/8/26.
//

#ifndef BDTuringMacro_h
#define BDTuringMacro_h

#define BDTuringWeakSelf __weak typeof(self) wself = self
#define BDTuringStrongSelf __strong typeof(wself) self = wself

#define BDSemaphoreLock(lock) dispatch_semaphore_wait(lock, DISPATCH_TIME_FOREVER);
#define BDSemaphoreUnlock(lock) dispatch_semaphore_signal(lock);

#endif /* BDTuringMacro_h */
