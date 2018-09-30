//
//  EUCDialogNtfMessage.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/6/30.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@class EUCDialogNtfMsgDataModel;
@interface EUCDialogNtfMessage : EUCBaseModel

// 广播接受者ID (仅接收)
@property (nonatomic, copy) NSString *easyrtcid;
// 接受者ID
@property (nonatomic, copy) NSString *targetEasyrtcid;
// 发送者身份
@property (nonatomic, copy) NSString *senderEasyrtcid;
// 服务器时间
//@property (nonatomic, copy) NSString *serverTime;
// 信令内容
@property (nonatomic, strong) EUCDialogNtfMsgDataModel *msgData;
// 消息类型
@property (nonatomic, copy) NSString *msgType;
// ？
@property (nonatomic, copy) NSString *offline_msg_id;
// ？当前会话ID集合
@property (nonatomic, strong) NSMutableArray *offline_recipient_ids;

@end

typedef NS_ENUM(NSInteger, EUCDialogNtfMsgStyle) {
    EUCDialogNtfMsgStylePullUser = 1000,   // 移除成员
    EUCDialogNtfMsgStylePushUser,          // 添加成员
    EUCDialogNtfMsgStyleUpdateDialogName,  // 更新群名称
    EUCDialogNtfMsgStyleUpdateNickName,    // 更新群昵称
    EUCDialogNtfMsgStyleDeleteDialog,      // 解散群组
    EUCDialogNtfMsgStyleChangePhoto,       // 改变头像
    EUCDialogNtfMsgStyleCreateDialog,      // 创建会话(群组)
    EUCDialogNtfMsgStyleRecallMessage,     // 回滚消息
};

@interface EUCDialogNtfMsgDataModel : EUCBaseModel

// 操作（pullUser移除成员;pushUser添加成员;updateDialogName更新群名称;updateNickName修改群昵称;deleteDialog解散群）
//pullUser | pushUser data为该成员id数组
//updateDialogName data为新的群名称
//updateNickName data为成员的昵称
//deleteDialog data为null

// 修改的数据
@property (nonatomic, copy) NSString* data;
// 解析下来的list
@property (nonatomic, strong) NSMutableArray *dataList;
// 会话ID
@property (nonatomic, copy) NSString *dialogID;
// 通知消息的内容
@property (nonatomic, copy) NSString *message;
// 操作
@property (nonatomic, copy) NSString *operation;
// 操作类型
@property (nonatomic, assign) EUCDialogNtfMsgStyle ntfMsgStyle;
// 操作者ID
@property (nonatomic, copy) NSString *operatorUserId;
// 消息ID
@property (nonatomic, copy) NSString *ID;

@property (nonatomic, copy) NSString* date_sent;

// 消息回撤类型专用 有一个字段 sendDate 原消息发送时间
@property (nonatomic, strong) NSDictionary* extra;

@end
