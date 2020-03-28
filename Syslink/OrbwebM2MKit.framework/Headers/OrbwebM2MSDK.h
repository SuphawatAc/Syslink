//
//  OrbwebM2MSDK.h
//  M2MFramework
//
//  Created by William on 2019/2/18.
//  Copyright © 2019 William. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RDZ_TYPE_WW 0
#define RDZ_TYPE_CN 1
#define RDZ_TYPE_CUST 2

NS_ASSUME_NONNULL_BEGIN

@interface OrbwebM2MSDK : NSObject


+ (OrbwebM2MSDK*) getInstance;
+ (void) setRegion:(NSInteger) region;
+ (void) setRDZDomain:(NSString *)path;
- (NSString *) getIP;
- (NSString *) getHost;
- (NSString *) setupDonameAddress;
- (void) changeIP;
- (void) releaseSDK;
@end

NS_ASSUME_NONNULL_END
