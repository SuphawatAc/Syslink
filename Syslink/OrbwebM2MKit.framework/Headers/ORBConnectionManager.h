//
//  ORBConnectionManager.h
//  OrbwebM2MKit
//
//  Created by William on 2019/10/9.
//  Copyright © 2019 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ORBConnectTask.h"

NS_ASSUME_NONNULL_BEGIN
extern NSString * const ORBConnectionLostNotification;

@interface ORBConnectionManager : NSObject
/**
 @discussion if wifi mode then connect type is 1 6 8 else connect type is 8 7
 */
@property BOOL isWifi;

/**
Access the shared 'ORBConnectionManager' instance
@return Returns the shared 'ORBConnectionManager' instance
*/

+ (instancetype)defaultManager;

/** Implements a M2M interface asynchronous to ORBM2MConnection
@note You MUST initialize the [ORBConnectionManager defaultManager] before calling any other method.
@discussion Connect M2M is asynchronous.
disconnect will be notified on the `ORBConnectionLostNotification` notification.
@param rdz_path M2M RDZ domain or ip address.s
@param SID M2M Connection SID.
@param remotePorts Remote ports for local mapping
@param account Authorization user ID.
@param password Authorization user password.
@param completeBlock callback (ORBConnectTask , NSError) result block.
@param speedBlock callback (ORBConnectTask) result block.
*/

- (void)CreateP2PConnectALLWithRDZ:(nonnull NSString *)rdz_path
                               SID:(nonnull NSString *)SID
                       remotePorts:(nonnull NSArray *)remotePorts
                           Account:(nullable NSString *)account
                          Password:(nullable NSString *)password
                           success:(nullable ConnectionResultBlock)completeBlock
                             Speed:(SpeedResultBlock)speedBlock;

/**
@discussion Retrieve the ORBConnectTask "trying to connect"
@param SID M2M Connection SID.
 */
- (nullable ORBConnectTask*) getGoing:(NSString *)SID;

/**
@discussion Retrieve the ORBConnectTask "already connected"
@param SID M2M Connection SID.
*/

- (nullable ORBConnectTask*) getConnectionWithSID:(nonnull NSString*)SID;

/**
@discussion Retrieve the ORBConnectTask "already connected"
@param SID M2M Connection SID.
@param specifiedType [M2MType_TCP_Lan, M2MType_TCP, M2MType_UDP, M2MType_Relay]
*/

- (nullable ORBConnectTask*) getConnectionWithSID:(nonnull NSString*)SID
                                        specified:(M2MType)specifiedType;

/**
@discussion Retrieve the ORBConnectTask "already connected"
@param server_id M2M Server ID.
*/

- (nullable ORBConnectTask*) getConnectionWithServerId:(nullable NSString *)server_id;

/** @brief mapped other port number
@param port other mappedPort if you need
@param SID M2M Connection SID.
@param completeBlock callback (NSInteger, NSError\*) mappedPort block.
*/

- (void)addPort:(NSInteger)port
        withSID:(NSString*)SID
        success:(void(^)(NSInteger mappedPort, NSError *error)) completeBlock;

/*! @brief Disconnect M2M with a specific sid. */
/// @param SID M2M Connection Session ID
- (BOOL)endConnectionWithSID:(nonnull NSString *)SID;

/*! @brief Disconnect M2M with a specific service id. */
/// @discussion Disconnect M2M connection with a specific Server ID.
/// @param server_id Server ID return upon successful connection established.
- (BOOL)endConnectionWithServerId:(nonnull NSString *)server_id;

/*! @brief Disconnect all M2M connection. */
- (BOOL)endAllConnections;



@end

NS_ASSUME_NONNULL_END
