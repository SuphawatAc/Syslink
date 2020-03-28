//
//  REQHttp.h
//  CmdServiceFramework
//
//  Created by 谭琪元 on 2018/12/27.
//  Copyright © 2018 William. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^HttpCompletion)(id response, NSError* error);
NS_ASSUME_NONNULL_BEGIN

@interface REQHttp : NSObject

/**
 *  http://127.0.0.1:1003/device.cgi?CMD_ID=...
 *  @param port 端口（如：1003）
 *  @param url  请求体（如：device.cgi）
 */
-(instancetype) initWithPort:(NSInteger)port url:(NSString*)url;

/**
 *  发送cgi指令
 *  @param param   请求参数，从REQPacket.h中生成获取
 *  @param completion   回调
 */
-(void) sendCommandCGI:(NSDictionary*)param completion:(HttpCompletion)completion;
@end

NS_ASSUME_NONNULL_END
