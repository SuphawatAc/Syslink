//
//  LogObject.h
//  OrbwebM2MKit
//
//  Created by William on 2018/10/8.
//  Copyright © 2018年 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LogObject : NSObject

+ (instancetype) getInstance;
- (void) setM2MVer:(NSString *)ver;
- (void) setOrbwebVer:(NSString *)ver;
- (NSString *) getM2MVer;
- (NSString *) getOrbwebVer;
- (void) trackLog: (NSString *)event :(NSDictionary *)obj;
- (void) P2PConnectInfo:(NSString *)sid
                       :(long)times
                       :(NSInteger)errorcode
                       :(NSInteger)p2pType
                       :(NSInteger)p2pMode
                       :(NSInteger)speed_time;

- (void) P2PDisconnectInfo:(NSString *)sid
                          :(NSInteger)errorCode
                          :(NSInteger)p2pType
                          :(NSInteger)p2pMode
                          :(NSInteger)spend_time;

@end

NS_ASSUME_NONNULL_END
