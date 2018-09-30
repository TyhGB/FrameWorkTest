//
//  EUCContact.h
//  EUCIMManager
//
//  Created by sunqy on 2017/6/5.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCContact : NSObject

/**
 查询用户好友关系
 */
+ (void)findFriendShipByUserIDSuccess:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 根据号码查询已注册用户

 @param phones 所有的手机号码集合
 */
+ (void)findUserByPhones:(NSArray*)phones
                 success:(void (^)(id dataObject))success
                 failure:(void (^)(NSError *error))failure;

/**
 发起好友申请

 @param params 参数集(userId, description)
 */
+ (void)addFriendRequestWithParams:(NSDictionary*)params
                           success:(void (^)(id dataObject))success
                           failure:(void (^)(NSError *error))failure;

/**
 修改好友申请状态

 @param params 参数集(requestId, status)
 */
+ (void)updateFriendRequestStatusWithParams:(NSDictionary*)params
                                    success:(void (^)(id dataObject))success
                                    failure:(void (^)(NSError *error))failure;

/**
 解除用户好友

 @param friendId 参数集(friendId, status)
 */
+ (void)removeFriendSchemasWithFriendId:(NSString*)friendId
                                success:(void (^)(id dataObject))success
                                failure:(void (^)(NSError *error))failure;

/**
 更新好友备注

 @param params 参数集(friendId, memo)
 */
+ (void)updateFriendSchemasWithParams:(NSDictionary*)params
                              success:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 是否是互为好友以及好友申请状态

 @param params 参数(friendId)
 */
+ (void)findIsFriendAndRequestStatusParams:(NSDictionary*)params
                                   success:(void (^)(id dataObject))success
                                   failure:(void (^)(NSError *error))failure;

/**
 是否是企业通讯好友

 @param params 参数(userID)
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)findIsEnterpriseMemberParams:(NSDictionary*)params
                             success:(void (^)(id dataObject))success
                             failure:(void (^)(NSError *error))failure;
#pragma mark -
#pragma mark - 通讯录
/**
 增量新增/更新 或者删除 用户通讯录

 @param params 参数集(contactsJson)
 @param update 增量新增/更新 或 删除
 */
+ (void)saveContactsSchemaWithParams:(NSDictionary*)params
                              update:(BOOL)update
                             success:(void (^)(id dataObject))success
                             failure:(void (^)(NSError *error))failure;

/**
 好友推荐

 @param params 参数集(size)
 */
+ (void)getRecommendationUserWithParams:(NSDictionary*)params
                                success:(void (^)(id dataObject))success
                                failure:(void (^)(NSError *error))failure;


/**
 发送邀请

 @param phone 被邀请人的手机号
 */
+ (void)sendInvitationWithPhone:(NSString *)phone
                        success:(void (^)(id dataObject))success
                        failure:(void (^)(NSError *error))failure;

/**
 获取推荐邀请人

 @param params 参数集(size)
 */
+ (void)getInviterWithWithParams:(NSDictionary *)params
                         success:(void (^)(id dataObject))success
                         failure:(void (^)(NSError *error))failure;
@end
