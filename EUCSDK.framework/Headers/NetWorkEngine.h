//
//  NetWorkEngine.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/15.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import "BaseNetWorkEngine.h"

@interface NetWorkEngine : BaseNetWorkEngine

#pragma mark -

#pragma mark - 发送手机验证码
///**
// *  发送手机验证码
// *  GET /auth/sendsms
// *
// */
//+ (void)sendsmsWithParams:(NSDictionary*)params
//                  success:(void (^)(id dataObject))success
//                  failure:(void (^)(NSError *error))failure;
//
///**
// *  验证手机验证码 （用于 修改手机号）
// *  GET /auth/verifysms?
// *
// */
//+ (void)verifysmsWithParams:(NSDictionary*)params
//                    success:(void (^)(id dataObject))success
//                    failure:(void (^)(NSError *error))failure;
//
///**
// *  验证手机验证码 （用于 注册的时候）
// *  POST /auth/verifysms?
// *
// *  参数 mobile={mobile}&code={code}
// */
//
//+ (void)verifysmsPOSTWithParams:(NSDictionary*)param
//                        success:(void (^)(id dataObject))success
//                        failure:(void (^)(NSError *error))failure;

#pragma mark -
#pragma mark - 注册
///**
// *  注册用户 - Register
// *  POST users
// *
// */
//+ (void)registerWithParams:(NSDictionary*)param
//                   success:(void (^)(id dataObject))success
//                   failure:(void (^)(NSError *error))failure;
//
///**
// *  推荐注册用户 - Register
// *  POST /friend/register/recommendationUser
// */
//+ (void)recommendationUserSuccess:(void (^)(id dataObject))success
//                          failure:(void (^)(NSError *error))failure;

#pragma mark -
#pragma mark - 验证
///**
// *  未登录情况下修改用户密码
// *  POST auth/smspassword
// */
//+ (void)smspasswordWithParams:(NSDictionary*)param
//                      success:(void (^)(id dataObject))success
//                      failure:(void (^)(NSError *error))failure;
//
///**
// *  验证用户登录密码 - Verify the user password
// *  POST /users/verifypwd
// */
//+ (void)verifypwdWithParams:(NSDictionary*)param
//                    success:(void (^)(id dataObject))success
//                    failure:(void (^)(NSError *error))failure;


#pragma mark -
#pragma mark - 登录
///**
// * 用户密码登录
// * POST /auth/login
// *
// */
//+ (void)loginWithParams:(NSDictionary*)param
//                success:(void (^)(id dataObject))success
//                failure:(void (^)(NSError *error))failure;
//
///**
// *  手机验证码登录
// *  POST /auth/verifysms
// *
// */
//+ (void)smsloginWithParams:(NSDictionary*)param
//                   success:(void (^)(id dataObject))success
//                   failure:(void (^)(NSError *error))failure;
//
///**
// *  登出 - Logout
// *  DELETE login
// *
// *  无参数
// */
//+ (void)logoutWithParam:(NSDictionary *)params success:(void (^)(id dataObject))success
//                failure:(void (^)(NSError *error))failure;

/**
 * 注册设备token接口
 * /auth/registerDeviceToken
 applicationId     Yes     String     应用ID
 deviceType     Yes     String     设备类型
 deviceToken     Yes     String     设备token（默认值：用户ID）
 userId     Yes     String     设备类型（默认值：xiaomi）
 }
 */
+ (void)registerDeviceTokenWithParam:(NSDictionary *)params
                             success:(void (^)(id dataObject))success
                             failure:(void (^)(NSError *error))failure;

#pragma mark -
//#pragma mark - 信息更新
///**
// *  更新Session - Renew Session
// *  POST session/renew
// *
// */
//+ (void)sessionRenewSuccess:(void (^)(id dataObject))success
//                    failure:(void (^)(NSError *error))failure;
//
//
///**
// *  修改用户信息 - Edit User Info
// *  PUT /users/{id}
// *
// */
//+ (void)PUTUserWithParams:(NSDictionary*)param
//                   userID:(NSString *)userID
//                  success:(void (^)(id dataObject))success
//                  failure:(void (^)(NSError *error))failure;
//
///**
// *  获得用户信息 - Get User Info
// *  GET users
// *
// */
//+ (void)userInfoWithUserID:(NSString*)userid
//                   success:(void (^)(id dataObject))success
//                   failure:(void (^)(NSError *error))failure;





//#pragma mark -
//#pragma mark - 二维码扫描
///**
// *  扫描二维码--App
// *  GET /auth/scanCode
// */
//+ (void)scanCodeWithParams:(NSDictionary*)param
//                   success:(void (^)(id dataObject))success
//                   failure:(void (^)(NSError *error))failure;
//
///**
// *  二维码登录验证--App
// *  POST /auth/registerByCode
// */
//+ (void)registerByCodeWithParams:(NSDictionary*)param
//                         success:(void (^)(id dataObject))success
//                         failure:(void (^)(NSError *error))failure;
//
///**
// *  二维码登录验证--Web
// *  GET /auth/initQRCode
// */
//+ (void)QRCodeSuccess:(void (^)(id dataObject))success
//              failure:(void (^)(NSError *error))failure;
//
///**
// *  二维码验证结果--Web
// *  GET /auth/isRegistered
// */
//+ (void)QRRegisteredWithParams:(NSDictionary*)params
//                       success:(void (^)(id dataObject))success
//                       failure:(void (^)(NSError *error))failure;
//
//
//
/**
 * 验证是否有IMS权限
 * GET auth/verifyIms
 */
+ (void)AuthVerifyIms:(void (^)(id dataObject))success
              failure:(void (^)(NSError *error))failure;

#pragma mark -
#pragma mark - 会话
/**
 *  创建会话 - Create Dialog
 *  POST /chat/Dialog
 *
 */
+ (void)createDialogWithParams:(NSDictionary*)params
                       success:(void (^)(id dataObject))success
                       failure:(void (^)(NSError *error))failure;

/**
 *  修改会话信息 - Edit Dialog
 *  PUT /chat/Dialog/{id}
 *
 */
+ (void)editDialogWithParams:(NSDictionary*)params
                     success:(void (^)(id dataObject))success
                     failure:(void (^)(NSError *error))failure;

/**
 *  设置会话所有消息已读 - Set Dialog Message As Read
 *  POST /chat/Dialog/{id}/read
 *
 */
+ (void)dialogReadWithID:(NSString*)dialog_id
                 success:(void (^)(id dataObject))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  设置会话置顶 - Put Dialog On Top
 *  POST／DELETE /chat/Dialog/{id}/top
 *
 *  @param dialog_id 会话id
 *  @param cancel    是否为取消置顶
 */
+ (void)dialogTopWithID:(NSString*)dialog_id
                 cancel:(BOOL)cancel
                success:(void (^)(id dataObject))success
                failure:(void (^)(NSError *error))failure;

/**
 *  设置消息免打扰 - Put Dialog mute
 *  POST／DELETE /chat/Dialog/{id}/mute
 *
 */
+ (void)dialogMuteWithID:(NSString*)dialog_id
                  cancel:(BOOL)cancel
                 success:(void (^)(id dataObject))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  隐藏会话 - Hidden Dialog
 *  POST /chat/Dialog/{id}/hide
 *
 *  参数 ID: 对话框的ID
 */
+ (void)hiddenDialogWithID:(NSString*)dialog_id
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 消息回撤 - Dialog
 Put chat/Message/recall/{id} 消息回撤、
 */
+ (void)messageRecallWithID:(NSString*)message_id
                    success:(void (^)(id dataObject))success
                    failure:(void (^)(NSError *error))failure;


#pragma mark -
#pragma mark - 通讯录好友
/**
 *  查询用户好友关系 - findFriendShipByUserID
 *  get
 *
 */
+ (void)findFriendShipByUserIDSuccess:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 *  根据号码查询已注册用户- findUserByPhones
 *  post/get
 *
 *  参数
 *  phones-手机号集合，以英文逗号分隔
 */
+ (void)findUserByPhonesWithParams:(NSDictionary*)params
                           success:(void (^)(id dataObject))success
                           failure:(void (^)(NSError *error))failure;

/**
 *  发起好友申请 - addFriendRequest
 *  post
 *
 */
+ (void)addFriendRequestWithParams:(NSDictionary*)params
                           success:(void (^)(id dataObject))success
                           failure:(void (^)(NSError *error))failure;

/**
 *  修改好友申请状态 - updateFriendRequestStatus
 *  post
 *
 */
+ (void)updateFriendRequestStatusWithParams:(NSDictionary*)params
                                    success:(void (^)(id dataObject))success
                                    failure:(void (^)(NSError *error))failure;

/**
 *  解除用户好友 - removeFriendSchemas
 *  post
 *
 */
+ (void)removeFriendSchemasWithParams:(NSDictionary*)params
                              success:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 *  更新好友备注 - updateFriendSchemas
 *  post
 *
 */
+ (void)updateFriendSchemasWithParams:(NSDictionary*)params
                              success:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 *  是否是互为好友以及好友申请状态
 *  GET /friend/isFriendAndRequestStatus
 *
 *  参数 friendId-目标用户id
 */
+ (void)findIsFriendAndRequestStatusParams:(NSDictionary*)params
                                   success:(void (^)(id dataObject))success
                                   failure:(void (^)(NSError *error))failure;

/**
 是否是企业通讯录好友
 GET /addressBook/user/selectUserByAppUserId
 
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
 *  增量新增/更新用户通讯录- saveContactsSchema
 *  post
 *
 */
+ (void)saveContactsSchemaWithParams:(NSDictionary*)params
                       success:(void (^)(id dataObject))success
                       failure:(void (^)(NSError *error))failure;

/**
 *  删除用户通讯录- removeContactsSchema
 *  post/get
 *
 */
+ (void)removeContactsSchemaWithParams:(NSDictionary*)params
                             success:(void (^)(id dataObject))success
                             failure:(void (^)(NSError *error))failure;







/** 好友推荐 */
+ (void)getRecommendationUserWithParams:(NSDictionary*)params
                                success:(void (^)(id dataObject))success
                                failure:(void (^)(NSError *error))failure;

/** 发送邀请 */
+ (void)sendInvitationWithParams:(NSDictionary *)params
                         success:(void (^)(id dataObject))success
                         failure:(void (^)(NSError *error))failure;

/** 获取推荐邀请人 */
+ (void)getInviterWithWithParams:(NSDictionary *)params
                         success:(void (^)(id dataObject))success
                         failure:(void (^)(NSError *error))failure;



/** 同步会话列表（后台态运行同步会话列表） */
+ (void)syncUserDialogsWithParams:(NSDictionary *)params
                          success:(void (^)(id dataObject))success
                          failure:(void (^)(NSError *error))failure;

/** 查询会话列表 */
+ (void)queryUserDialogsSuccess:(void (^)(id dataObject))success
                        failure:(void (^)(NSError *error))failure;

/** 拉取会话历史信息 */
+ (void)queryUserHistoryDialogsWithParams:(NSDictionary *)params
                                 dialogID:(NSString *)dialogID
                                  success:(void (^)(id dataObject))success
                                  failure:(void (^)(NSError *error))failure;

/** 查询会话详情,带有最近15条消息 */
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

#pragma mark -
#pragma mar - 其它
/**
 地区接口
 */
+ (void)loclistSuccess:(void (^)(id dataObject))success
               failure:(void (^)(NSError *error))failure;

/** 获取广告页图片 */
+ (void)welcomePageInfoSuccess:(void (^)(id dataObject))success
                       failure:(void (^)(NSError *error))failure;




@end
