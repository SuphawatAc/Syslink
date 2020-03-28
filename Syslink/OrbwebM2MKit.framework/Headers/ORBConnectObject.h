//
//  ORBConnectObject.h
//  OrbwebM2MKit
//
//  Created by William on 2019/10/9.
//  Copyright © 2019 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define USED_FULL_CONNECT 1
#define USED_TWO_WAY 0

NS_ASSUME_NONNULL_BEGIN

#define M2MType_LAN_ONLY 0

/** @brief ORBM2MType */
typedef NS_OPTIONS (NSUInteger, M2MType) {
    /// LAN TCP
    M2MType_TCP_Lan = 1,
    /// TCP NAT Traversal
    M2MType_TCP = 1 << 1,
    /// UDP NAT Traversal
    M2MType_UDP = 1 << 2,
    /// Relay
    M2MType_Relay = 1 << 3,
    
    /// P2P option
    M2MType_P2P = M2MType_TCP | M2MType_UDP,
};

typedef NS_ENUM(NSUInteger, M2MErrorCode) {
    
    /// M2M connect success
    M2M_CONN_ERROR_NONE = 0,
    /// Rendezvous server received unknown data format.
    M2M_CONN_SERVER_POST_UNKNOWDATA = 1001,
    /// Rendezvous server cannot identify device role(client/host).
    M2M_CONN_SERVER_UNKNOWNROLE = 1002,
    /// Client/host registered with invalid SID
    M2M_CONN_SERVER_INVALID_SID = 1003,
    /// Rendezvous server cannot find TaT Server.
    M2M_CONN_SERVER_NO_VALID_TAT = 1004,
    /// Host not registered
    M2M_CONN_SERVER_HOST_NOT_EXIST = 1005,
    /// Rendezvous server response unknown info
    M2M_CONN_SERVER_UNKNOWNINFO_ERROR = 1006,
    /// Rendezvous server error
    M2M_CONN_HOST_RENDEZVOUS_SERVER_ERROR = 2000,
    /// Host register to TaT server timeout
    M2M_CONN_HOST_REGISTER_TAT_SERVER_TIMEOUT,
    /// Host register to TaT server fail
    M2M_CONN_HOST_REGISTER_TAT_SERVER_FAIL,
    /// Session ID is not registered.
    M2M_CONN_HOST_SESSION_ID_NOT_REGISTERED,
    /// Session ID is already registered.
    M2M_CONN_HOST_SESSION_ID_ALREADY_REGISTERED,
    /// tunnel is not ready.
    M2M_CONN_HOST_TUNNEL_NOT_EXIST,
    /// Host local port is already used
    M2M_CONN_HOST_LOCAL_PORT_ALREADY_USED,
    /// Host local port is not in port mapping
    M2M_CONN_HOST_LOCAL_PORT_NOT_MAPPED,
    /// Host local port is not under listening.
    M2M_CONN_HOST_LOCAL_PORT_NOT_LISTENED,
    /// Missing host configuration file.
    M2M_CONN_HOST_MISSING_CONFIGURATION,
    /// Host has no memory
    M2M_CONN_HOST_NOMEMORY,
    
    /// Rendezvous server error
    M2M_CONN_CLIENT_RENDEZVOUS_SERVER_ERROR = 3000,
    /// Client connect host timeout.
    M2M_CONN_CLIENT_CONNECT_HOST_TIMEOUT,
    /// Client connect host fail.
    M2M_CONN_CLIENT_CONNECT_HOST_FAIL,
    /// Session ID is not registered.
    M2M_CONN_CLIENT_SESSION_ID_NOT_REGISTERED,
    /// Session ID is already registered.
    M2M_CONN_CLIENT_SESSION_ID_ALREADY_REGISTERED,
    /// Tunnel is not ready.
    M2M_CONN_CLIENT_TUNNEL_NOT_EXIST,
    /// Host local port is already used
    M2M_CONN_CLIENT_LOCAL_PORT_ALREADY_USED,
    /// Host local port is not in port mapping
    M2M_CONN_CLIENT_LOCAL_PORT_NOT_MAPPED,
    /// Host local port is not under listening.
    M2M_CONN_CLIENT_LOCAL_PORT_NOT_LISTENED,
    /// Missing client configuration file.
    M2M_CONN_CLIENT_MISSING_CONFIGURATION,
    /// Client has no memory.
    M2M_CONN_CLIENT_NOMEMORY,
    // client connect tat fail.
    M2M_CONN_CLIENT_CONNECT_TAT_FAIL,
    // clinet register nic fail.
    M2M_CONN_CLIENT_REG_NIC_FAIL_RSP,
    
    M2M_CONN_CLIENT_DOMAIN_ERROR = 3100,
    
    M2M_CONN_CLIENT_CLOSE_CONNECT = 3101,
    
    /// M2M bonjour service invalidate SID.
    M2M_BJ_INVALID_SID = 4000,
    /// M2M bonjour service invalidate timeout.
    M2M_BJ_INVALID_TIMEOUT,
    /// M2M bonjour service host not existed.
    M2M_BJ_HOST_EXISTED,
    /// M2M bonjour service has no memory.
    M2M_BJ_NOMEMORY,
    /// M2M bonjour service timeout.
    M2M_BJ_TIMEOUT,
    /// M2M bonjour service unknown error.
    M2M_BJ_UNKNOWN
};

@interface ORBConnectObject : NSObject

@property (nonatomic, readonly) NSString *rdz_ip;
@property (nonatomic, readonly) NSString *SessonID;
@property (nonatomic, readonly) NSArray *mPorts;
@property (nonatomic, readonly) NSString *m2m_account, *m2m_password;

- (instancetype) initWithRDZ:(NSString *)rdz_path
                         SID:(NSString *)SID
                 remotePorts:(NSArray *)remotePorts
                     Account:(NSString *)account
                    Password:(NSString *)password;
       


@end

NS_ASSUME_NONNULL_END
