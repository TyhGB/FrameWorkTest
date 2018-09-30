//
//  EUCStyleDefine.h
//  EUCSDK
//
//  Created by 肖乐 on 2018/3/19.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//

#ifndef EUCStyleDefine_h
#define EUCStyleDefine_h

#pragma mark - 音视频相关
typedef NS_ENUM(NSInteger, EUCSessionStatus) {
    
    EUCSessionStatusDefault = 0, //未激活状态
    EUCSessionStatusActive       //激活状态
};

typedef NS_ENUM(NSInteger, EUCSessionEndReason) {
    
    EUCSessionEndReasonHangup = 1000,   //挂断操作
    EUCSessionEndReasonReject,          //拒接操作
    EUCSessionEndReasonReceiveHangup,   //收到对方挂断操作
    EUCSessionEndReasonReceiveReject,   //收到对方拒绝操作
    EUCSessionEndReasonOutTime,         //会议成员超时
    EUCSessionEndReasonBusy,            //成员繁忙
    EUCSessionEndReasonProcessed,       //其他端已经处理
    EUCSessionEndReasonNone             //无理由挂断
};

// 信令的所有类型
typedef NS_ENUM(NSInteger, EUCSignalingMessageType) {
    EUCSignalingMessageTypeCall = 1000,         //接收到视频邀请
    EUCSignalingMessageTypeAccept,              //对方回应邀请
    EUCSignalingMessageTypeIceCandidates,       //收到candidates
    EUCSignalingMessageTypeHungup,              //挂断
    EUCSignalingMessageTypeReject,              //拒绝
    EUCSignalingMessageTypeInviteinform,        //有人邀请
    EUCSignalingMessageTypeInvite,              //被邀请
    EUCSignalingMessageTypeProcessed,           //多端同步
    EUCSignalingMessageTypeBusy,                //对方有通话
    EUCSignalingMessageTypeStartCount,          //开始计时
    EUCSignalingMessageTypeOutTime,             //超时
    EUCSignalingMessageTypeInfo,                //通知消息
    EUCSignalingMessageTypeJoin                 //加入消息
};

/**
 本地影像载体显示模式

 - EUCRTCLocalViewGravityResize: 拉伸模式
 - EUCRTCLocalViewGravityResizeAspect 平铺模式
 - EUCRTCLocalViewGravityResizeAspectFill 填充模式
 */
typedef NS_ENUM(NSInteger, EUCRTCLocalViewGravity) {
    
    EUCRTCLocalViewGravityResize,
    EUCRTCLocalViewGravityResizeAspect,
    EUCRTCLocalViewGravityResizeAspectFill
};

#pragma mark - 服务器连接状态
typedef NS_ENUM(NSInteger, EUCIMClientStatus) {
    
    EUCIMClientStatusConnecting = 1000,  //连接中.
    EUCIMClientStatusConnected,          //连接成功
    EUCIMClientStatusNotConnect          //未连接
};

#pragma mark - 消息相关
// 消息发送者枚举
typedef NS_ENUM(NSInteger, EUCMessageFrom) {
    EUCMessageFromMe    = 0,  // 自己发的
    EUCMessageFromOther = 1   // 别人发的
};

// 消息类型枚举
typedef NS_ENUM(NSInteger, EUCMessageType) {
    EUCMessageTypeText       = 1 ,  // 文字
    EUCMessageTypeVoice      = 2 ,  // 语音
    EUCMessageTypePicture    = 3 ,  // 图片
    EUCMessageTypeFile       = 4 ,  // 文件
    EUCMessageTypeVideo      = 5,   // 小视频
    EUCMessageTypeStartEndAV = 6,   // 开始结束音视频
    EUCMessageTypeCard       = 7,   // 个人名片
    EUCMessageTypeMerge      = 8,  // 合并转发的消息
    EUCMessageTypeMap        = 9,   // 发送位置
    EUCMessageTypeArticle    = 10,  // 文章
    EUCMessageTypeIMS        = 12,  // IMS 消息
    EUCMessageTypeNotFriend  = 110, // 自定义类型，非好友
    EUCMessageTypeRecall     = 111,  // 回滚消息
    EUCMessageTypeTerminate  = 112   // 电话中断消息
};

#pragma mark - 会话相关
typedef NS_ENUM(NSInteger, EUCDialogListType) {
    
    EUCDialogListType_All = 1000,   //所有会话
    EUCDialogListType_GROUP,        //所有群组会话
    EUCDialogListType_SHOW          //所有显示的会话
};

#endif /* EUCStyleDefine_h */
