//
//  EUCRTCAudioSession.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/2/28.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EUCSignalingMessage.h"
#import "EUCUserModel.h"
#import "EUCStyleDefine.h"


@interface EUCRTCAudioSession : NSObject

/**
 是否正在语音会议
 */
@property (nonatomic, assign) BOOL isAudioing;

/**
 session状态
 */
@property (nonatomic, assign) EUCSessionStatus sessionStatus;

/**
 语音会议发起者ID
 */
@property (nonatomic, copy) NSString *callerID;

/**
 会话类型 1(公共会话, 暂未使用), 2(多人会话), 3(私人会话)
 */
@property (nonatomic, assign) NSString *dialogType;

/**
 成员集合
 */
@property (nonatomic, strong) NSArray *opponentsArr;

/**
 ims集合
 */
@property (nonatomic, strong) NSArray <EUCUserModel *>*imsArray;

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
 开启语音通话
 */
- (void)startAudioSession;

/**
 主动加入语音通话
 */
- (void)joinAudioSession;

/**
 被叫方同意语音通话
 */
- (void)answerAudioSession;

/**
 结束音频通话
 
 @param reason 结束缘由
 */
- (void)endAudioSession:(EUCSessionEndReason)reason;

/**
 邀请新成员加入会议

 @param newOppoents 新成员列表
 @param newImsArray 新ims成员列表
 */
- (void)inviteNewOppoents:(NSArray *)newOppoents newImsArray:(NSArray *)newImsArray;

/**
 切换扬声器模式与听筒模式

 @param isSpeaker 是否为扬声器模式
 
 @discussion 稍等，会介绍执行此方法时的声道模式环境配置
 */
- (void)switchAudioOverride:(BOOL)isSpeaker;

/**
 设置是否静音

 @param isMute 是否静音
 */
- (void)updateAudioIsMute:(BOOL)isMute;

#pragma mark - SDK UI
/**
 显示SDKUI
 
 @discussion 在调用此方法前必须确定调用者身份，及isInitiator要设定好
 */
- (void)showAudioSDKUI;

/**
 接收到挂断、拒绝、接收、超时、计时、繁忙等信令后更新SDK界面UI。

 @param signalingMessage 信令数据模型
 
 @discussion 调用此方法前，用户要确保使用了SDK中的UI界面，否则无意义
 */
- (void)updateSDKUIWithSignalingMessage:(EUCSignalingMessage *)signalingMessage;

/**
 关闭SDKUI
 
 @discussion 调用此方法前，用户要确保使用了SDK中的UI界面，否则无意义
 */
- (void)closeSDKUI;

@end
