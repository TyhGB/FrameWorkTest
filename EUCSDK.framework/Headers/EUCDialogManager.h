//
//  EUCDialogManager.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/3/8.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//  会话模块实例

#import <Foundation/Foundation.h>
#import "EUCDialogModel.h"
#import "EUCDialogNtfMessage.h"
#import "EUCStyleDefine.h"

@class EUCDialogManager;
@protocol EUCDialogManagerDelegate <NSObject>

/**
 收到群会话广播回执

 @param dialogManager 会话模块实例
 @param ntfMessage 广播模型
 
 @discussion 包括收到有人修改群名称，有人退群，添加成员等
 */
- (void)dialogManager:(EUCDialogManager *)dialogManager
 didReceivedBroadcast:(EUCDialogNtfMessage *)ntfMessage;

/**
 发送消息后，更新了最后一条消息回执

 @param dialogManager 会话模块实例
 @param itemModel 最新会话模型
 */
- (void)dialogManager:(EUCDialogManager *)dialogManager didUpdateLastMsg:(EUCDialogItemModel *)itemModel;

/**
 完成会话同步回执

 @param dialogManager 会话模块实例
 */
- (void)didFinishDialogSync:(EUCDialogManager *)dialogManager;

@end

@interface EUCDialogManager : NSObject
/**
 初始化会话模块实例

 @return 会话模块实例
 */
+ (instancetype)sharedDialogInstance;

/**
 添加会话群广播回执代理

 @param delegate 要添加的代理
 @param delegateQueue 执行代理方法的队列 缺省为主队列
 */
- (void)addDelegate:(id<EUCDialogManagerDelegate>)delegate
      delegateQueue:(dispatch_queue_t)delegateQueue;

/**
 获取本地会话列表

 @param dialogListType 会话列表类型
 @return 本地会话列表
 */
- (NSArray <EUCDialogItemModel *>*)getDialogList:(EUCDialogListType)dialogListType;

/**
 更新本地会话模型数据

 @param itemModel 更新后的会话模型
 @return 更新结果
 
 @discussion 比如更新会话的最后一条消息等
 */
- (BOOL)updateDialogItemModel:(EUCDialogItemModel *)itemModel;

/**
 隐藏会话

 @param dialogID 会话ID
 
 @return 操作结果
 
 @discussion 并没有将此会话从数据库中删除，而是隐藏不显示。其对应的消息在本地也得到保留
 */
- (BOOL)hiddenDialog:(NSString *)dialogID;

/**
 设置会话置顶状态

 @param dialogID 会话ID
 @param isTop 是否置顶
 @return 操作结果
 */
- (BOOL)setDialogToTop:(NSString *)dialogID
                 isTop:(BOOL)isTop;

/**
 设置会话消息免打扰状态
 异步方法

 @param dialogID 会话ID
 @param isMute 是否免打扰
 */
- (void)asyncSetDialogMute:(NSString *)dialogID
                    isMute:(BOOL)isMute
                   success:(void(^)(void))success
                   failure:(void(^)(NSError *error))failure;

/**
 创建一个会话
 异步方法

 @param memberIDs 会话成员集合
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncCreateDialog:(NSArray *)memberIDs
                  success:(void(^)(EUCDialogItemModel *itemModel))success
                  failure:(void(^)(NSError *error))failure;

/**
 获取会话详情信息
 异步方法

 @param dialogID 会话ID
 @param success 成功回调
 @param failure 失败回调
 
 @discussion 调用此方法，会更新本地会话为最新数据
 */
- (void)asyncGetDialogDetailInfo:(NSString *)dialogID
                         success:(void(^)(EUCDialogItemModel *itemModel))success
                         failure:(void(^)(NSError *error))failure;


/**
 修改群名称
 异步方法

 @param dialogID 会话ID
 @param newName 修改的群名称
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncEditGroupName:(NSString *)dialogID
                   newName:(NSString *)newName
                   success:(void(^)(void))success
                   failure:(void(^)(NSError *error))failure;

/**
 修改本人在群里的昵称
 异步方法

 @param dialogID 会话ID
 @param newNickName 修改的昵称名
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncChangeNickName:(NSString *)dialogID
                newNickName:(NSString *)newNickName
                    success:(void(^)(void))success
                    failure:(void(^)(NSError *error))failure;

/**
 退出群组
 异步方法

 @param dialogID 会话ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncExitGroup:(NSString *)dialogID
               success:(void(^)(void))success
               failure:(void(^)(NSError *error))failure;

/**
 添加群成员

 @param dialogID 会话ID
 @param memberList 添加的成员ID集合
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncAddGroupMember:(NSString *)dialogID
                 memberList:(NSArray *)memberList
                    success:(void(^)(void))success
                    failure:(void(^)(NSError *error))failure;

/**
 删除群成员
 异步方法

 @param dialogID 会话ID
 @param memberList 删除的成员ID集合
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncDeleteGroupMember:(NSString *)dialogID
                    memberList:(NSArray *)memberList
                       success:(void(^)(void))success
                       failure:(void(^)(NSError *error))failure;

@end
