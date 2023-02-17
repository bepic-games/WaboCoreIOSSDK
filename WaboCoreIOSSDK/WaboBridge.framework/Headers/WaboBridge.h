//
//  WaboBridge.h
//  WaboBridge
//
//  Created by Bepic on 2022/11/28.
//

#import <Foundation/Foundation.h>

//! Project version number for WaboBridge.
FOUNDATION_EXPORT double WaboBridgeVersionNumber;

//! Project version string for WaboBridge.
FOUNDATION_EXPORT const unsigned char WaboBridgeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <WaboBridge/PublicHeader.h>





/// ------------------------------
NS_ASSUME_NONNULL_BEGIN

#if defined (__cplusplus)
extern "C" {
#endif

// 定义一个结构体(用于Unity 和 iOS 之间的数据交互)
typedef struct Parameter {  // 注意:结构体属性按必须此顺序排列
    const char * _Nonnull symbol;
    int code;
    const char * _Nonnull msg;
    const char * _Nullable data;
} Params;
// 定义 C# 回调函数
typedef void (*CSFunction)(Params * _Nonnull params);
// 声明外部接口(Other Linker Flags => -undefined dynamic_lookup)
extern void UnitySendMessage(const char *, const char *, const char *);
char * WaboBridgeOCClassMethod(const char * _Nonnull className, const char * _Nonnull methodName, const char * _Nullable jsonParams, CSFunction _Nullable csFunc);
char * WaboBridgeOCInstanceMethod(const char * _Nonnull className, const char * _Nonnull methodName, const char * _Nullable jsonParams, CSFunction _Nullable csFunc);
#if defined (__cplusplus)
}
#endif

// 封装 Bean
@interface CSBean : NSObject
    @property (nonatomic, copy) NSString * symbol;
    @property (nonatomic) CSFunction csFunc;
@end
@interface UnityBridge : NSObject
/// OC 回调到 C#
/// - Parameters:
///   - bean: Bean
///   - params: 回调参数
+ (void) callback:(CSBean * _Nullable)bean params:(Params * _Nonnull) params;

/// OC 回调到 C#
/// - Parameters:
///   - bean: Bean
///   - code: 状态码
///   - msg: 回调信息
///   - data: 回调数据
+ (void) callback:(CSBean * _Nullable)bean code:(int)code msg:(NSString * _Nonnull)msg data:(NSString * _Nullable)data;

/// OC 回调到 C#[成功状态]
/// - Parameters:
///   - bean: Bean
///   - msg: 回调信息
+ (void) succ:(CSBean * _Nullable)bean msg:(NSString * _Nonnull)msg;

/// OC 回调到 C#[成功状态]
/// - Parameters:
///   - bean: Bean
///   - msg: 回调信息
///   - data: 回调数据
+ (void) succ:(CSBean * _Nullable)bean msg:(NSString * _Nonnull)msg data:(NSString * _Nonnull)data;

/// OC 回调到 C#[失败状态]
/// - Parameters:
///   - bean: Bean
///   - msg: 回调信息
+ (void) fail:(CSBean * _Nullable)bean msg:(NSString * _Nonnull)msg;

/// OC 调用 C#(用于Unity2019.3及以上版本)
/// - Parameters:
///   - goName: The name of the target GameObject
///   - name: The script method to call on that object(必须是挂在对应游戏物体上的脚本定义的函数)
///   - msg: The message string to pass to the called method
+ (void) sendMessageToGOWithName:(NSString * _Nonnull)goName functionName:(NSString * _Nonnull)name message:(NSString * _Nullable)msg;

/// OC 调用 C#(适配Unity2019.2及以下版本)
/// - Parameters:
///   - obj: The name of the target GameObject
///   - method: The script method to call on that object
///   - msg: The message string to pass to the called method
+ (void) unitySendMessage:(NSString * _Nonnull)obj method:(NSString * _Nonnull)method msg:(NSString * _Nullable)msg;
@end

NS_ASSUME_NONNULL_END
