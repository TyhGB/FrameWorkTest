//
//  EUCSignalingMessage.h
//  EUCIMManager
//
//  Created by Tuling Code on 2016/12/29.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebRTC/RTCSessionDescription.h>
#import <WebRTC/RTCIceCandidate.h>
#import "EUCStyleDefine.h"


@class EUCMsgDataMessage;
@interface EUCSignalingMessage : NSObject

/** socket回应的数据创建模型 */
+ (instancetype)messageFromSocketDictionary:(NSDictionary *)responseDict;

@property (nonatomic, assign, readonly) EUCSignalingMessageType messageType;

//接收者ID
@property (nonatomic, copy) NSString *targetEasyrtcid;
//消息类型
@property (nonatomic, copy) NSString *msgType;
//发送消息方
@property (nonatomic, copy) NSString *senderEasyrtcid;
// 发送方是否为ims
@property (nonatomic, assign) BOOL isImsSender;

@property (nonatomic, strong) NSMutableDictionary *msgData;

@property (nonatomic, strong) EUCMsgDataMessage *msgDataMode;

@end


@interface EUCMsgDataMessage : NSObject

/** 呼叫类型 1,视频 2,音频 */
@property (nonatomic, copy) NSString *callType;
/**会话类型 1(公共会话, 暂未使用), 2(多人会话), 3(私人会话)*/
@property (nonatomic, copy) NSString *dialogType;
/** 视频发起者ID(对方ID) */
@property (nonatomic, copy) NSString *callerID;
/** 固定 WebRTCVideoChat */
@property (nonatomic, copy) NSString *moduleIdentifier;
/** 视频会议的参与者（除发起者外) */
@property (nonatomic, strong) NSMutableArray *opponentsIDs;
/** 发送者平台 */
@property (nonatomic, copy) NSString *platform;
/** 视频会议的ID */
@property (nonatomic, copy) NSString *sessionID;
/** 发起视频所在的会话ID */
@property (nonatomic, copy) NSString *dialogID;
/** 信令类型 */
@property (nonatomic, copy) NSString *signalType;
/** iceCandidates */
@property (nonatomic, strong) NSMutableArray *iceCandidates;
/** 交换时的offer或者anwser 在signalType为call/accept/invite使用 */
@property (nonatomic, copy) NSString *sdp;
/** 音频是传true */
@property (nonatomic, strong) NSNumber *composite;
/** 新成员 */
@property (nonatomic, strong) NSMutableArray *kNewOpponentsIDs;
/** 邀请人ID */
@property (nonatomic, strong) NSMutableArray *inviterID;
/** 在线人员ID集合 */
@property (nonatomic, strong) NSMutableArray *onlineIDs;
/** 新加字段isEnd(判断会议是否结束) */
@property (nonatomic, copy) NSString *isEnd;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end


//接收到视频邀请的消息
@interface EUCCallMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end


//收到视频邀请的回应"同意"消息
@interface EUCAcceptMessage : EUCSignalingMessage

@property (nonatomic, strong, readonly) RTCSessionDescription *sessionDescription;
//由sdp和RTCSdpType生成的RTCSessionDescription对象,来创建EUCAcceptMessage对象
- (instancetype)initWithDescription:(RTCSessionDescription *)sessionDescription AndMsgDict:(NSDictionary *)msgDict;

@end


//收到iceCandidates的消息
@interface EUCIceCandidateMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end


//收到挂断消息
@interface EUCHangupMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

//收到拒绝邀请消息
@interface EUCRejectMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end


//邀请通知
@interface EUCInviteInformMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

//收到邀请
@interface EUCInviteMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

//多端同步
@interface EUCProcessedMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

// 对方繁忙
@interface EUCBusyMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

// 开始计时
@interface EUCStartCountMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

// 超时
@interface EUCOutTimeMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

// 通知消息
@interface EUCInfoMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

// 加入消息
@interface EUCJoinMessage : EUCSignalingMessage

- (instancetype)initWithMsgDict:(NSDictionary *)msgDict;

@end

