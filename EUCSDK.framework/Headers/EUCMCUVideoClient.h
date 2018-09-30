//
//  EUCMCUVideoClient.h
//  EUCSDK_Sample
//
//  Created by TyhOS on 2018/9/4.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EUCMCUVideoSession.h"
#import "EUCSignalingMessage.h"

@protocol EUCMCUVideoClientDelegate <NSObject>
@optional

/**
 收到视频会议请求回调
 
 @param videoSession 视频会议实例
 
 @discussion 可以在此回调中调用SDK提供的UI或显示自定义UI
 */
- (void)callMCUVideoDidReceive:(EUCMCUVideoSession *)videoSession;

/**
 收到视频会议拒绝回调
 
 @param videoSession 视频会议实例
 @param rejectMessage 拒绝信令模型
 */
- (void)callMCUVideoDidReject:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCRejectMessage *)rejectMessage;

/**
 收到视频会议挂断回执
 
 @param videoSession 视频会议实例
 @param hangupMessage 挂断信令模型
 */
- (void)callMCUVideoDidHangup:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCHangupMessage *)hangupMessage;

/**
 收到视频会议正在忙回执
 
 @param videoSession 视频会议实例
 @param busyMessage 对方正在忙信令模型
 */
- (void)callMCUVideoDidBusy:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCBusyMessage *)busyMessage;

/**
 收到视频会议邀请回执
 
 @param videoSession 视频会议实例
 @param inviteMessage 邀请信令模型
 */

- (void)callMCUVideoDidInvite:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCInviteMessage *)inviteMessage;

/**
 收到视频会议邀请新成员声明回调
 
 @param videoSession 视频会议实例
 @param informMessage 邀请新成员声明信令模型
 */
- (void)callMCUVideoDidInviteInform:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCInviteInformMessage *)informMessage;


/**
 收到当前在线且自己未加入的视频会议

 @param videoSession 用于展示群组自己没有加入的会议
 */
- (void)callMCUVideoNeedJoin:(EUCMCUVideoSession *)videoSession;

/**
 超时

 @param videoSession 视频会议实例
 @param outTimeMessage 超时信令
 */
- (void)callMCUVideoDidOutTime:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCOutTimeMessage *)outTimeMessage;


/**
 收到计时信令

 @param videoSession 视频会议实例
 @param startCountMessage 计时信令
 */
- (void)callMCUVideoDidStartCount:(EUCMCUVideoSession *)videoSession signalingMessage:(EUCStartCountMessage *)startCountMessage;


/**
 收到视频被其他端处理的信令
 
 @param videoSession 视频会议实例
 */
- (void)callMCUVideoDidProcessed:(EUCMCUVideoSession *)videoSession;
/**
 收到视频会议远程视图影像
 
 @param remoteView 远程视图影像
 */
- (void)callMCUVideoDidRemoteView:(EUCMCURemoteView *)remoteView;

/**
 收到视频会议本地视图影像
 
 @param localView 本地视图影像
 */
- (void)callMCUVideoDidLocalView:(EUCMCULocalView *)localView;
@end

@interface EUCMCUVideoClient : NSObject

/**
 初始化MCU视频会话

 @return MCU视频会话对象
 */
+ (instancetype)sharedMCUVideoClient;

/**
 视频通话回调代理
 */
@property (nonatomic,weak) id <EUCMCUVideoClientDelegate> delegate;

/**
 当前视频会话
 */
@property (nonatomic,strong) EUCMCUVideoSession *currentVideoSession;

/**
 所有视频通话信息集合
 */
@property (nonatomic, strong, readonly) NSMutableArray <EUCMCUVideoSession *>*videoSessionList;

/**
 创建一个新的视频会话
 
 @param opponents 会议成员
 @param dialogID 会话ID
 @return 视频会议实例
 */
- (EUCMCUVideoSession *)createNewSessionWithOpponents:(NSArray *)opponents dialogID:(NSString *)dialogID;

@end
