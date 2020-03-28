//
//  CMDConnect.h
//  CmdServiceFramework
//
//  Created by William on 2019/9/9.
//  Copyright © 2019 William. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^MessageCallback)(NSString *message);

@interface CMDConnect : NSObject

- (id) init:(NSInteger) port Completion:(MessageCallback)completion;
- (void) startConnect;
- (void) StopConnect;
- (void) sendCommand:(NSString *)message;
@end

NS_ASSUME_NONNULL_END
