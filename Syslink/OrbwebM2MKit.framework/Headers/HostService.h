//
//  HostService.h
//  iFacecall
//
//  Created by William on 2018/8/1.
//  Copyright © 2018年 William. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HostService : NSObject
+ (HostService *) defaultManager;

- (void) startService:(NSString *)token
          UserAccount:(NSString *) account
            VideoPort:(NSInteger) VP
            AudioPort:(NSInteger) AP;
- (void) stopService;
- (NSString *)getDeviceID;
@end
