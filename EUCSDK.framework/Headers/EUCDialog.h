//
//  EUCDialog.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/26.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCDialog : NSObject

/**
 创建会话

 @param params 参数集(occupants_ids, type)
 */
+ (void)createDialogWithParams:(NSDictionary*)params
                       success:(void (^)(id dataObject))success
                       failure:(void (^)(NSError *error))failure;

/**
 修改会话信息

 @param params 参数集(添加群成员(会话ID, push_all[occupants_ids][]) 或者 移除群成员(pull_all[occupants_ids][]), 编辑群名称(name), 我在群中的群昵称(nick_name))
 */
+ (void)editDialogWithParams:(NSDictionary*)params
                     success:(void (^)(id dataObject))success
                     failure:(void (^)(NSError *error))failure;


/**
 设置会话所有消息已读

 @param dialog_id 当前会话id
 */
+ (void)dialogReadWithID:(NSString*)dialog_id
                 success:(void (^)(id dataObject))success
                 failure:(void (^)(NSError *error))failure;

/**
 设置会话置顶

 @param dialog_id 会话id
 @param cancel 是否为取消置顶
 */
+ (void)dialogTopWithID:(NSString*)dialog_id
                 cancel:(BOOL)cancel
                success:(void (^)(id dataObject))success
                failure:(void (^)(NSError *error))failure;

/**
 设置消息免打扰

 @param dialog_id 会话ID
 @param cancel 是否为取消免打扰
 */
+ (void)dialogMuteWithID:(NSString*)dialog_id
                  cancel:(BOOL)cancel
                 success:(void (^)(id dataObject))success
                 failure:(void (^)(NSError *error))failure;

/**
 隐藏会话

 @param dialog_id 隐藏会话的id
 */
+ (void)hiddenDialogWithID:(NSString*)dialog_id
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 消息回撤

 @param message_id 撤回的消息id
 */
+ (void)messageRecallWithID:(NSString*)message_id
                    success:(void (^)(id dataObject))success
                    failure:(void (^)(NSError *error))failure;

/**
 同步会话列表（后台态运行同步会话列表）

 @param params 参数集(dialogs)
 */
+ (void)syncUserDialogsWithParams:(NSDictionary *)params
                          success:(void (^)(id dataObject))success
                          failure:(void (^)(NSError *error))failure;

/**
 查询会话列表
 */
+ (void)queryUserDialogsSuccess:(void (^)(id dataObject))success
                        failure:(void (^)(NSError *error))failure;

/**
 拉取会话历史信息

 @param params 参数集(id, type, limit, lastMessageId)
 */
+ (void)queryUserHistoryDialogsWithParams:(NSDictionary *)params
                                  success:(void (^)(id dataObject))success
                                  failure:(void (^)(NSError *error))failure;

/**
 查询会话详情,带有最近15条消息

 @param params 参数集(dialogIds)
 */
+ (void)queryDialogRecordsWithParams:(NSDictionary *)params
                             success:(void (^)(id dataObject))success
                             failure:(void (^)(NSError *error))failure;

/**
 查询用户的会话列表的信息

 @param success 成功回调
 @param failure 失败回调
 */
+ (void)queryDialogList:(void (^)(id dataObject))success
                failure:(void (^)(NSError *error))failure;
@end
