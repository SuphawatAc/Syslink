//
//  REQPacket.h
//  CmdServiceFramework
//
//  Created by William on 2018/12/26.
//  Copyright © 2018 William. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface REQPacket : NSObject
+ (NSString *)buildJSONCMD: (NSString *)cmd;

+ (NSString *)buildJSONCMD: (NSString *)cmd
                 Parameter:(NSString *)parameter
               StringValue:(NSString *)value;

+ (NSString *)buildJSONCMD: (NSString *)cmd
                 Parameter:(NSString *)parameter
              IntegerValue:(NSInteger)value;

+ (NSString *)buildJSONCMD: (NSString *)cmd
                 Parameter:(NSString *)parameter
                 JOSNValue:(NSString *)value;

//====  http cmd  ====
+(NSDictionary*) buildHttpCMD:(NSString*)cmd;

+(NSDictionary*) buildHttpCMD:(NSString*)cmd
                    Parameter:(NSString *)parameter
                  StringValue:(NSString*)value;

+ (NSDictionary *)buildHttpCMD: (NSString *)cmd
                     Parameter: (NSString *)parameter
                  IntegerValue: (NSInteger)value;

@end

NS_ASSUME_NONNULL_END
