//
//  EUCDialogSingleton.h
//  EUCIMManager
//
//  Created by  肖乐乐 on 2017/6/21.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

/**
 * 用于对会话列表信息的处理:数据存表与显示
 */
#import <Foundation/Foundation.h>
#import "EUCReceivedMessageModel.h"
#import "EUCDialogNtfMessage.h"
#import "EUCSignalingMessage.h"
#import "EUCDialogModel.h"

@interface EUCDialogSingleton : NSObject

+ (instancetype)sharedSingleton;


/**
 从数据库中初始化会话所有数据，填入单例对象中

 @return 操作结果
 */
+ (BOOL)configData;


/**
 会话列表信息(总的)
 */
@property (nonatomic, strong, readonly) EUCDialogModel* dialogModel;

/**
 在"消息"中显示的所有会话,数据就是从dialogMode中而来,但是不显示删除的,隐藏的与没有对话的会话
 */
@property (nonatomic, strong, readonly) EUCDialogModel* dialogListModel;

/**
 数据重装

 @return 返回状态
 */
+ (BOOL)resetData;

/**
 我的群组: 数据就是从dialogMode中而来,所有的群列表
 */
@property (nonatomic, strong, readonly) EUCDialogModel* dialogGroupModel;



/**
 对会话列表排序
 */
- (void)sortDialogListModel;

/**
 收到一条 socket 消息, 更新数据
 
 @param dialogDictM 以房间号为key，对应消息为value的字典
 @return 未知的会话集合
 */
- (NSMutableDictionary*)updateDialogWithMessages:(NSMutableDictionary *)dialogDictM completion:(void(^)(void))completion;


/**
 收到socket消息, 判断是否使对应房间的isSomeAtMe成为YES

 @param messages 当前会话收到的消息list
 @param dialogItemModel 当前会话模型
 @return 处理后的会话模型
 */
- (EUCDialogItemModel *)updateDialogIsSomeAtMeWithMessage:(NSArray *)messages dialogItemModel:(EUCDialogItemModel *)dialogItemModel;

/**
 收到一条消息-处理数据
 具体消息模型与会话模型的相关处理
 */
- (EUCDialogItemModel *)handleDialogUpdateWithReceivedMessageDict:(NSDictionary *)messageDict dialogItemMode:(EUCDialogItemModel *)dialogItemMode;

/**
 收到一个新的会话数据更新的时候
 
 @param dialogDict 会话数据
 @return 成功与否
 */
- (BOOL)updateWithMsgData:(id)dialogDict;


/**
 收到signaling消息，需要检测，如果缺少数据，则进行处理，并返回

 @param signalingData signaling数据
 @param success 处理成功回调
 @param failure 处理失败回调
 */
- (void)checkAvailabilityWithSignalingData:(EUCSignalingMessage *)signalingData success:(void (^)(void))success failure:(void(^)(NSError *error))failure;

/**
 收到dialogNtf消息，检测数据，处理并返回
 
 @param dialogNtfData dialogNtf数据
 @param success 成功
 @param failure 失败
 */
- (void)checkAvailabilityWithDialogNtfData:(EUCDialogNtfMessage *)dialogNtfData success:(void (^)(EUCDialogItemModel *itemModel))success failure:(void(^)(NSError *error))failure;

/**
 清空当前用户的数据
 */
+ (void)clearCurUserData;


/**
 将model设置成已读

 @param model model
 */
+ (void)makeMessageReadWithModel:(EUCDialogItemModel *)model;

/**
 删除一个会话(退出群的时候)

 @param dialogItemMode 会话模型
 @return 是否包括我自己
 */
- (BOOL)deleteDialogWithModel:(EUCDialogItemModel*)dialogItemMode;

// 处理系统消息同步type为null,显示未知类型bug
+ (EUCMessageModel *)dealSystemMessage:(EUCMessageModel *)messageModel msgType:(NSString *)msgType;
- (NSString*)lastMessageWithMode:(EUCMessageModel*)messageMode;

/**
 更换设备导致的需要同步会话数据
 登录调后用
 
 @param dict 会话数据
 */
- (void)changeDeviceRefreshLocalDialogDataWithData:(NSDictionary *)dict;

@end
