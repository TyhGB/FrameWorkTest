//
//  EUCSocketManager.h
//  EUCIMManager
//
//  Created by XLL on 2016/12/29.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "EUCSDK/EUCSDK-Swift.h"

@class EUCSignalingMessage;
@protocol EUCSocketManagerDelegate <NSObject>


/**
 socket连接结果回调
 */
@optional
- (void)connectTimeoutCallback:(NSDictionary *)callbackData;

@end

@protocol EUCSocketManagerVideoDelegate <NSObject>


/**
 视频通话信令回调

 @param message 视频信令
 */
- (void)didReceivedVideoMessageData:(EUCSignalingMessage *)message;

@end

@protocol EUCSocketManagerAudioDelegate <NSObject>

/**
 语音通话信令回调

 @param message 语音信令
 */
- (void)didReceivedAudioMessageData:(EUCSignalingMessage *)message;

@end

@protocol EUCSocketManagerMCUManagerDelegate <NSObject>

/**
 MCU视频通话信令回调
 
 @param message 语音信令
 */
- (void)didReceivedMCUVideoMessageData:(EUCSignalingMessage *)message;

@end

// 接收消息通知
UIKIT_EXTERN NSNotificationName const EUCDidReceivedMessageNotification;
// 接收已读通知
UIKIT_EXTERN NSNotificationName const EUCDidReceivedReadNotification;

@interface EUCSocketManager : NSObject

/**
 socket连接代理
 */
@property (nonatomic, weak) id <EUCSocketManagerDelegate> delegate;

/**
 视频信令接收代理
 */
@property (nonatomic, weak) id <EUCSocketManagerVideoDelegate> videoDelegate;

/**
 语音信令接收代理
 */
@property (nonatomic, weak) id <EUCSocketManagerAudioDelegate> audioDelegate;

/**
 mcu视频信令接收代理
 */
@property (nonatomic, weak) id <EUCSocketManagerMCUManagerDelegate> mcuVideoDelegate;
/** 记录重连次数 */ 
@property (nonatomic, assign) NSUInteger reconnectCount;

@property (nonatomic, strong) SocketIOClient *socketClient;
@property (nonatomic, strong) SocketManager *socketManager;
/**
 单例生成器
 */
+ (instancetype)sharedManager;


/**
 初始化socket并连接
 */
- (void)connect;

// 发送消息
- (void)sendDataWithDictionary:(NSDictionary *)dictMsg finishBlock:(void(^)(NSArray *data))finishBlock;
// 断开连接
- (void)disConnectSocket;

/**
 响: 叮咚
 */
- (void)startPlayer;

@end
