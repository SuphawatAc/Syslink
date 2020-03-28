//
//  PingTool.h
//  OrbwebM2MKit
//
//  Created by William on 2018/10/8.
//  Copyright © 2018年 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PingTool : NSObject
{
    
}
+ (instancetype) getInstance;
- (void) StartPingWithURL:(NSString *)url;
//- (void) StartPingWithAddress:(NSString *)address;
- (int) getPingtime;
@end

NS_ASSUME_NONNULL_END
