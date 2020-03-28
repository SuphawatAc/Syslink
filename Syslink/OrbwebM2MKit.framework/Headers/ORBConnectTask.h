//
//  ORBConnectTask.h
//  OrbwebM2MKit
//
//  Created by William on 2019/10/8.
//  Copyright © 2019 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ORBConnectObject.h"
#import "SpeedObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface ORBConnectTask : NSObject
typedef void(^ConnectionResultBlock)(ORBConnectTask  * _Nullable connection, NSError * _Nullable error);
typedef void(^SpeedResultBlock)(ORBConnectTask  * _Nullable connection);

@property (nonatomic, readonly) NSString *keyId;
@property (nonatomic, readonly) NSInteger connectMode;
@property (nonatomic, strong) NSString *serverId;
@property (nonatomic, strong) NSString *peerAddress;
@property (nonatomic, assign) NSInteger mErrorCode;

@property (nonatomic, assign) int m2mConnectionType;

@property (nonatomic, assign) NSTimeInterval start, end;
@property (nonatomic, assign) NSTimeInterval connect_time;
@property (nonatomic, assign) BOOL onCancel;

- (instancetype) initWithType:(M2MType)type
                       Object:(nonnull ORBConnectObject *)obj
                      success:(ConnectionResultBlock)completeBlock
                        Speed:(SpeedResultBlock)speedBlock;

- (BOOL)StartConnect;
- (BOOL)isPortMapped;
- (void) CloseConnect;
- (id)AddNewPort:(NSInteger)remotePort;


- (NSDictionary *) getMappingPort;
- (NSString *)getSID;
- (void) StartCMDTest;
- (SpeedObject *) getSpeedObject;

@end

NS_ASSUME_NONNULL_END
