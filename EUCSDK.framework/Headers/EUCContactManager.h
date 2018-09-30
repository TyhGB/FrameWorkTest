//
//  EUCContactManager.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/3/6.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//  好友管理实例

#import <Foundation/Foundation.h>
#import "EUCFriendModel.h"
#import "EUCFindFriendModel.h"

@protocol EUCContactManagerDelegate <NSObject>


/**
 接收到好友请求回执

 @param requestModels 好友请求数据模型集合
 */
- (void)didReceivedfriendRequest:(NSArray <EUCFriendRequestModel *>*)requestModels;

@end

@interface EUCContactManager : NSObject

/**
 初始化好友管理实例

 @return 好友管理实例
 */
+ (instancetype)sharedContactInstanced;

/**
 添加好友回执代理,包括收到好友申请,对方同意,对方拒绝等

 @param delegate 要添加的代理
 @param delegateQueue 执行代理方法的队列，缺省为主队列
 */
- (void)addDelegate:(id<EUCContactManagerDelegate>)delegate
      delegateQueue:(dispatch_queue_t)delegateQueue;


/**
 从服务器获取所有的好友
 异步方法
 
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getContactsFromServer:(void(^)(EUCFriendModel *friendModel))success
                      failure:(void(^)(NSError *error))failure;

/**
 从数据库获取所有的好友
 异步方法

 @return 好友列表
 */
- (NSArray *)getContacts;

/**
 同意好友请求
 异步方法

 @param friendID 对方ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)acceptContactInvitation:(NSString *)friendID
                        success:(void(^)(id dataObject))success
                        failure:(void(^)(NSError *error))failure;

/**
 拒绝好友请求
 异步方法

 @param friendID 对方ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)declineContactInvitation:(NSString *)friendID
                         success:(void(^)(id dataObject))success
                         failure:(void(^)(NSError *error))failure;

/**
 发起添加好友请求
 异步方法

 @param friendID 对方ID
 @param message 邀请信息
 @param success 成功回调
 @param failure 失败回调
 */
- (void)addContact:(NSString *)friendID
           message:(NSString *)message
           success:(void(^)(id dataObject))success
           failure:(void(^)(NSError *error))failure;

/**
 单向解除好友关系
 异步方法

 @param friendID 好友ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)deleteContact:(NSString *)friendID
              success:(void(^)(id dataObject))success
              failure:(void(^)(NSError *error))failure;

/**
 更新好友备注
 异步方法

 @param friendID 好友ID
 @param memo 好友备注
 @param success 成功回调
 @param failure 失败回调
 */
- (void)updateContactMemo:(NSString *)friendID
                     memo:(NSString *)memo
                  success:(void(^)(id dataObject))success
                  failure:(void(^)(NSError *error))failure;

/**
 通过电话号码获取用户信息
 异步方法

 @param phones 电话号集合
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getContactInfo:(NSArray *)phones
               success:(void(^)(NSArray <EUCUserModel *>*userModels))success
               failure:(void(^)(NSError *error))failure;

/**
 判断与对方是否为好友，或者不是好友的情况下的请求状态
 异步方法

 @param friendID 对方ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)findIsFriendAndRequestStatus:(NSString *)friendID
                             success:(void(^)(id dataObject))success
                             failure:(void(^)(NSError *error))failure;

/**
判断对方是否是企业通讯录成员

 @param userID 对方ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)findIsEnterpriseMember:(NSString *)userID
                       success:(void(^)(id dataObject))success
                       failure:(void(^)(NSError *error))failure;

@end
