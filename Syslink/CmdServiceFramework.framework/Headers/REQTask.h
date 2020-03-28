//
//  REQTask.h
//
//  Created by William on 2018/12/26.
//  Copyright © 2018 William. All rights reserved.
//

#ifndef __REQ_TASK_H__
#define __REQ_TASK_H__

#import <Foundation/Foundation.h>

typedef void(^RequestCompletion)(id _Nullable response,  NSError* _Nullable  error);
NS_ASSUME_NONNULL_BEGIN

@interface REQTask : NSObject

+ (void) setLogOut:(BOOL)log;
- (id) initWithPort:(NSInteger) port;
-(void) sendCommand:(NSString*)cmd
            Timeout:(NSTimeInterval)timeout
         Completion:(RequestCompletion)completion;
-(void) sendCommandCGI:(NSString*)cgi
            Completion:(RequestCompletion)completion;//发送cgi指令
-(void) disconnect;

@end

NS_ASSUME_NONNULL_END

#endif //__REQ_TASK_H__
