//
//  CMDService.h
//  CmdServiceFramework
//
//  Created by William on 2018/12/26.
//  Copyright © 2018 William. All rights reserved.
//

#import <Foundation/Foundation.h>
#define DEVICE_TYPE_JSON 1
#define DEVICE_TYPE_AUDIO 2
//#define DEVICE_TYPE_BYTES 3

NS_ASSUME_NONNULL_BEGIN

@interface CMDService : NSObject

- (id) initJSONCMD:(NSString *)req;
- (id) initAudioReq:(NSData *)data;
- (NSData *)getData;


@end

NS_ASSUME_NONNULL_END
