//
//  EUCReceivedMessageModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/3/25.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

/**
 * 接收到一条消息的模型
 */
#import "EUCMessageModel.h"

@interface EUCReceivedMessageModel : EUCBaseModel

/**
 接收者的Dialog ID
 */
@property (nonatomic, copy) NSString *targetRoom;

/**
 消息类型
 */
@property (nonatomic, copy) NSString *msgType;

/**
 发送者的ID
 */
@property (nonatomic, copy) NSString *easyrtcid;

/**
 时间戳
 */
@property (nonatomic, copy) NSString *serverTime;

/**
 接收者的ID
 */
@property (nonatomic, copy) NSString*   targetEasyrtcid;

/**
 发送者的ID（仅接收）
 */
@property (nonatomic, copy) NSString *senderEasyrtcid;

/**
 消息体
 */
@property (nonatomic, strong) EUCMessageModel *msgData;

@end
