//
//  AudioConvert.h
//  iFacecall
//
//  Created by William on 2018/8/6.
//  Copyright © 2018年 William. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

@protocol AudioConvertDelegate <NSObject>

@optional
- (void)onEncode:(NSData *)data;
@end

@interface AudioConvert : NSObject
{
    AudioStreamBasicDescription srcFormat;
    AudioStreamBasicDescription destFormat;
    id<AudioConvertDelegate> _delegate;
    AudioConverterRef _ConvertRef;
    AudioBufferList inAaudioBufferList;
}

@property AudioStreamBasicDescription srcFormat;
@property AudioStreamBasicDescription destFormat;
@property id<AudioConvertDelegate> delegate;
- (id) initWithFormat:(AudioStreamBasicDescription) src
               target:(AudioStreamBasicDescription) dest;
- (void) closeAudioConvert;
- (void) setConvertBuffer:(NSData *)data;

@end
