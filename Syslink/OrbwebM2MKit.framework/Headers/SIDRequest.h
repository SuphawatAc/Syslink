//
//  SIDRequest.h
//  OrbwebM2MKit
//
//  Created by William on 2018/8/30.
//  Copyright © 2018年 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#define POST_METHOD @"POST"
#define GET_METHOD @"GET"

typedef void(^RequestBlcok) (NSString *api, NSInteger code , NSData *data);

@interface SIDRequest : NSObject

- (NSString *)base64:(NSData *)data;
- (void) setCTK:(NSString *)token;
- (void) setUserToken:(NSString *)token;
- (void) setUserID:(NSString *)user;
- (void) startRequest: (RequestBlcok) block;
- (void) cancelTask;

@property NSString *RequestAPI;
@property NSString *method;
@property NSData *RequestData;

@end
