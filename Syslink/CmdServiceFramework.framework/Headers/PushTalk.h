//
//  PushTalk.h
//  CmdServiceFramework
//
//  Created by William on 2018/12/26.
//  Copyright © 2018 William. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PushTalkCallback)(id response, NSError* error);

@interface PushTalk : NSObject
@property BOOL usedJsonMode;

+ (void) setLogOut:(BOOL)log;
- (id) initWithPort:(NSInteger) port callback:(PushTalkCallback)callback;
- (id) initWithPort:(NSInteger) port;
- (void) SendAudio:(NSData *)data;
- (void) closeSpeaker;

@end

NS_ASSUME_NONNULL_END
