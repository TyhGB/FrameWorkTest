//
//  EUCRTCAudioClient.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/2/28.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//  语音通话核心类

#import <Foundation/Foundation.h>
#import "EUCRTCAudioSession.h"
#import "EUCSignalingMessage.h"

@protocol EUCRTCAudioClientDelegate <NSObject>

@optional
/**
 收到语音会议请求回调

 @param audioSession 语音会议实例
 
 @discussion 可以在此回调中调用SDK提供的UI或显示自定义UI
 */
- (void)callAudioDidReceive:(EUCRTCAudioSession *)audioSession;

/**
 收到语音会议接受回调

 @param audioSession 语音会议实例
 @param acceptMessage 接收信令模型
 
  @discussion 主动方收到接收方响应后会执行此回执,用户可以在此方法中调用SDK提供的方法更新UI显示或者更新自定义UI显示
 */
- (void)callAudioDidAccept:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCAcceptMessage *)acceptMessage;

/**
 收到语音会议挂断回调

 @param audioSession 语音会议实例
 @param hangupMessage 挂断信令模型
 
 @discussion 收到挂断回执后，用户可以更新自定义UI，或者结束语音会议
 */
- (void)callAudioDidHangup:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCHangupMessage *)hangupMessage;

/**
 收到语音会议拒绝回调

 @param audioSession 语音会议实例
 @param rejectMessage 拒绝信令模型
 
 @discussion 收到拒绝回执后，用户可以更新自定义UI，或者结束语音会议
 */
- (void)callAudioDidReject:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCRejectMessage *)rejectMessage;

/**
 收到语音会议计时回调

 @param audioSession 语音会议实例
 @param startCountMessage 计时信令模型
 
 @discussion 收到计时回执后，用户可以更新自定义UI开启计时，或者调用SDK方法更新SDK内部UI
 */
- (void)callAudioDidStartCount:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCStartCountMessage *)startCountMessage;

/**
 收到语音会议成员超时回调

 @param audioSession 语音会议实例
 @param outTimeMessage 超时信令模型
 
 @discussion 收到超时回执后，用户可以更新自定义UI，或者调用SDK方法更新SDK内部UI
 */
- (void)callAudioDidOutTime:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCOutTimeMessage *)outTimeMessage;

/**
 收到语音会议对应正在忙回调

 @param audioSession 语音会议实例
 @param busyMessage 对方繁忙信令模型
 
 @discussion 收到繁忙回执后，用户可以更新自定义UI，或者调用SDK方法更新SDK内部UI
 */
- (void)callAudioDidBusy:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCBusyMessage *)busyMessage;

/**
 收到语音会议新加成员声明回调

 @param audioSession 语音会议实例
 @param informMessage 新加成员声明信令模型
 
 @discussion 收到新加成员声明回执后，用户可以更新自定义UI，或者调用SDK方法更新SDK内部UI
 */
- (void)callAudioDidInviteInform:(EUCRTCAudioSession *)audioSession signalingMessage:(EUCInviteInformMessage *)informMessage;

/**
 收到语音会议web处理回调

 @param audioSession 语音会议实例
 
 @discussion 收到其他端处理回执后，用户需要关闭自定义UI或SDKUI，并结束会议
 */
- (void)callAudioDidProcessed:(EUCRTCAudioSession *)audioSession;

/**
 收到当前在线且自己未加入的语音会议

 @param audioSession 语音会议实例
 
 @discussion 用于展示群组自己没有加入的会议
 */
- (void)callAudioNeedJoin:(EUCRTCAudioSession *)audioSession;

@required
/**
 SDK内部超时回执 必须实现
 
 @param audioSession 语音会议实例
 
 @discussion 收到此回执后，用户需要关闭自定义UI或者SDKUI
 */
- (void)callAudioDidReceiveSDKOutTime:(EUCRTCAudioSession *)audioSession;

@end

@interface EUCRTCAudioClient : NSObject


/**
 初始化语音会议核心对象

 @return 语音会议核心对象
 */
+ (instancetype)sharedRTCAudioClient;

/**
 语音通话回调代理
 */
@property (nonatomic, weak) id <EUCRTCAudioClientDelegate> delegate;

/**
 当前语音会话
 */
@property (nonatomic, strong) EUCRTCAudioSession *currentAudioSession;

/**
 所有语音通话信息集合
 */
@property (nonatomic, strong, readonly) NSMutableArray <EUCRTCAudioSession *>*audioSessionList;

/**
 创建一个语音会议

 @param opponents 会议成员
 @param imsArray ims通话成员
 @param dialogID 会话ID
 @return 语音会议对象
 */
- (EUCRTCAudioSession *)createNewSessionWithOpponents:(NSArray *)opponents
                                             imsArray:(NSArray *)imsArray
                                             dialogID:(NSString *)dialogID;

@end
