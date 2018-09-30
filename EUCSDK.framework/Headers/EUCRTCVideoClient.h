//
//  EUCRTCVideoClient.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/3/15.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//  视频会议核心类

#import <Foundation/Foundation.h>
#import "EUCRTCVideoSession.h"
#import "EUCSignalingMessage.h"

@protocol EUCRTCVideoClientDelegate <NSObject>

@optional
/**
 收到视频会议请求回调
 
 @param videoSession 视频会议实例
 
 @discussion 可以在此回调中调用SDK提供的UI或显示自定义UI
 */
- (void)callVideoDidReceive:(EUCRTCVideoSession *)videoSession;

/**
 收到视频会议拒绝回调

 @param videoSession 视频会议实例
 @param rejectMessage 拒绝信令模型
 */
- (void)callVideoDidReject:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCRejectMessage *)rejectMessage;

/**
 收到视频会议挂断回执

 @param videoSession 视频会议实例
 @param hangupMessage 挂断信令模型
 */
- (void)callVideoDidHangup:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCHangupMessage *)hangupMessage;

/**
 收到视频会议正在忙回执

 @param videoSession 视频会议实例
 @param busyMessage 对方正在忙信令模型
 */
- (void)callVideoDidBusy:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCBusyMessage *)busyMessage;

/**
 收到视频会议超时回执

 @param videoSession 视频会议实例
 @param outTimeMessage 超时信令模型
 */
- (void)callVideoDidOutTime:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCOutTimeMessage *)outTimeMessage;

/**
 收到视频会议web端处理回执

 @param videoSession 视频会议实例
 */
- (void)callVideoDidProcessed:(EUCRTCVideoSession *)videoSession;

/**
 收到视频会议邀请回执

 @param videoSession 视频会议实例
 @param inviteMessage 邀请信令模型
 */
- (void)callVideoDidInvite:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCInviteMessage *)inviteMessage;

/**
 收到视频会议邀请新成员声明回调

 @param videoSession 视频会议实例
 @param informMessage 邀请新成员声明信令模型
 */
- (void)callVideoDidInviteInform:(EUCRTCVideoSession *)videoSession signalingMessage:(EUCInviteInformMessage *)informMessage;

/**
 收到当前在线且自己未加入的视频会议
 
 @param videoSession 视频会议实例
 
 @discussion 用于展示群组自己没有加入的会议
 */
- (void)callVideoNeedJoin:(EUCRTCVideoSession *)videoSession;

@required
/**
 收到视频会议本地视图影像

 @param localView 本地视图影像
 */
- (void)callVideoDidLocalView:(EUCRTCLocalView *)localView;

/**
 收到视频会议远程视图影像

 @param remoteView 远程视图影像
 */
- (void)callVideoDidRemoteView:(EUCRTCRemoteView *)remoteView;

/**
 SDK内部超时回执 必须实现
 
 @param videoSession 视频会议实例
 @param userID 超时人员
 
 @discussion 收到此回执后，用户需要关闭自定义UI或者SDKUI
 */
- (void)callVideoDidReceiveSDKOutTime:(EUCRTCVideoSession *)videoSession
                               userID:(NSString *)userID;

@end

@interface EUCRTCVideoClient : NSObject

/**
 初始化视频会话核心对象

 @return 视频会话核心对象
 */
+ (instancetype)sharedRTCVideoClient;

/**
 视频通话回调代理
 */
@property (nonatomic, weak) id <EUCRTCVideoClientDelegate> delegate;

/**
 当前视频会话
 */
@property (nonatomic, strong) EUCRTCVideoSession *currentVideoSession;

/**
 所有视频通话信息集合
 */
@property (nonatomic, strong, readonly) NSMutableArray <EUCRTCVideoSession *>*videoSessionList;

/**
 创建一个新的视频会话

 @param opponents 会议成员
 @param dialogID 会话ID
 @return 视频会议实例
 */
- (EUCRTCVideoSession *)createNewSessionWithOpponents:(NSArray *)opponents dialogID:(NSString *)dialogID;

@end
