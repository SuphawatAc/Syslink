//
//  SIDObject.h
//  OrbwebM2MKit
//
//  Created by William on 2018/8/30.
//  Copyright © 2018年 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SIDRequest.h"
#define REG_CMD @"/register"
#define GET_NODE_ID @"/getNodeSID"
#define GET_CMD @"/quryNodeSID/"


@interface SIDObject : NSObject
@property NSString *userToken;
@property NSString *userID;
@property NSString *device_id;

//Host api
- (void) onRegister:(RequestBlcok) block;
- (void) getSessionID:(RequestBlcok) block;

//Client api
- (void) quryNodeSID:(NSString *)did :(RequestBlcok) block;
- (NSString *) getDeviceID;

//Private api
+ (NSString *) getBundleID;
+ (NSString *)md5:(NSString *)str;
@end
