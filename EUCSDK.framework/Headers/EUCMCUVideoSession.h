//
//  EUCMCUVideoSession.h
//  EUCSDK_Sample
//
//  Created by TyhOS on 2018/9/4.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebRTC/WebRTC.h>
#import "EUCStyleDefine.h"

@interface EUCMCULocalView :UIView
/**
 本地影像展示模式
 
 @discussion 缺省为EUCRTCLocalViewGravityResizeAspect平铺模式
 */
@property (nonatomic, assign) EUCRTCLocalViewGravity videoGravity;
// 使用webRTC内部视图做本地影像容器
@property (nonatomic, strong) RTCCameraPreviewView *localView;
// 视频轨迹
@property (nonatomic, strong) RTCVideoTrack *videoTrack;

@end
@interface EUCMCURemoteView : UIView
/**
 远程影像隶属人ID
 */
@property (nonatomic, copy, readonly) NSString *userID;
// 视频轨迹
@property (nonatomic, strong) RTCVideoTrack *videoTrack;
// 远程影像载体
@property (nonatomic, strong) RTCEAGLVideoView *remoteView;
@end

@interface EUCMCUVideoSession : NSObject

/**
 是否正在视频会议
 */
@property (nonatomic, assign) BOOL isVideoing;

/**
 session状态
 */
@property (nonatomic, assign) EUCSessionStatus sessionStatus;

/**
 视频会议发起者ID
 */
@property (nonatomic, copy) NSString *callerID;

/**
 成员集合
 */
@property (nonatomic, strong) NSArray *opponentsArr;

/**
 所在会话ID
 */
@property (nonatomic, copy) NSString *dialogID;

/**
 会议sessionID
 */
@property (nonatomic, copy) NSString *sessionID;

/**
 是否为发起方
 */
@property (nonatomic, assign) BOOL isInitiator;

/**
 会话类型 1(公共会话, 暂未使用), 2(多人会话), 3(私人会话)
 */
@property (nonatomic, assign) NSString *dialogType;
/**
 开启视频通话
 */
- (void)startVideoSession;

/**
 主动加入视频通话
 */
- (void)joinVideoSession;

/**
 被叫方同意视频通话
 */
- (void)answerVideoSession;

/**
 结束视频通话
 
 @param reason 结束缘由
 */
- (void)endVideoSession:(EUCSessionEndReason)reason;

/**
 设置摄像头是否可用
 
 @param videoEnable 摄像头是否可用
 */
- (void)updateVideoEnable:(BOOL)videoEnable;

/**
 设置是否静音
 
 @param isMute 是否静音
 */
- (void)updateVideoIsMute:(BOOL)isMute;

/**
 切换摄像头
 
 @param isUseBack 是否使用后置摄像头
 */
- (void)switchCameraIsUseBack:(BOOL)isUseBack;

/**
 切换扬声器模式与听筒模式
 
 @param isSpeaker 是否为扬声器模式
 */
- (void)switchVideoOverride:(BOOL)isSpeaker;

/**
 邀请新成员加入会议
 
 @param newOpponents 新成员
 */
- (void)inviteNewOppoents:(NSArray *)newOpponents;
@end
