#import <Foundation/Foundation.h>

@protocol CapturePCMDelegate <NSObject>
- (void)returnDataPCM:(NSMutableData *)data;
@end

@interface CapturePCM : NSObject
@property (nonatomic,strong) id<CapturePCMDelegate>delegate;
- (instancetype)initWithSampleRate:(Float64)rate;
- (void) closeCapturePCM;
- (void)startRecord;
- (void)stopRecord;
@end
