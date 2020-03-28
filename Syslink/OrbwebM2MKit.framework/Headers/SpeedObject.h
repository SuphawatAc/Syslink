//
//  SpeedObject.h
//  OrbwebM2MKit
//
//  Created by William on 2019/10/30.
//  Copyright © 2019 Orbweb Taiwan Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SpeedObject : NSObject
@property NSTimeInterval Start, End;
@property NSInteger Avg, Min, Max;
@property NSInteger SendCount, ReceiveCount;

- (void) reset;
- (void) setStartTime;
- (void) setEndTime;
- (int) getTimes;
@end

NS_ASSUME_NONNULL_END
