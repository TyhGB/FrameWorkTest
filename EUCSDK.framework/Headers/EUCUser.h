//
//  EUCUser.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/16.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCUser : NSObject

#pragma mark - 重新获取paasToken

#pragma mark - 注册
/**
 *  注册用户 - Register
 *  POST users
 *
 *  @param param   NSDictionary
 *  {
        login      登录名(手机号)
        password   密码
        full_name  昵称
 }
 */
+ (void)registerWithParams:(NSDictionary*)param
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 *  推荐注册用户 - Register
 *  POST /friend/register/recommendationUser
 *  注册用户后，将该用户推荐给通讯录中有他联系方式的其他用户
 */
+ (void)recommendationUserSuccess:(void (^)(id dataObject))success
                          failure:(void (^)(NSError *error))failure;

#pragma mark -
#pragma mark - 登录
/**
 * 用户密码登录
 * POST /auth/login
 *
 *  @param param   NSDictionary
 *  {
        login    登录名(手机号)
        password 密码
 }
 */
+ (void)loginWithParams:(NSDictionary*)param
                success:(void (^)(id dataObject))success
                failure:(void (^)(NSError *error))failure;

/**
 *  手机验证码登录
 *  POST /auth/verifysms
 *
 *  @param params   NSDictionary
 *  {
        mobile  登录名(手机号)
        code    验证码
    }
 */
+ (void)smsloginWithParams:(NSDictionary*)params
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 *  登出 - Logout
 *  DELETE login
 *
 *  无参数
 */
+ (void)logoutSuccess:(void (^)(id dataObject))success
              failure:(void (^)(NSError *error))failure;

/**
 * 注册设备token接口
 * /auth/registerDeviceToken
 */
+ (void)registerDeviceToken;

#pragma mark -
#pragma mark - 信息更新
/**
 *  更新Session - Renew Session
 *  POST session/renew
 *
 *  无参数
 */
+ (void)sessionRenewSuccess:(void (^)(id dataObject))success
                    failure:(void (^)(NSError *error))failure;

/**
 *  修改用户信息 - Edit User Info
 *  PUT /users/{id}
 *  修改那个属性, 就将新值传进去
 *  @param param   NSDictionary
 *  {
         full_name   姓名
    }
 */
+ (void)PUTUserWithParams:(NSDictionary*)param
                  success:(void (^)(id dataObject))success
                  failure:(void (^)(NSError *error))failure;

/**
 *  获得用户信息 - Get User Info
 *  GET users
 *  @param userid 用户id
 */
+ (void)userInfoWithUserID:(NSString*)userid
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;


#pragma mark -
#pragma mark - 验证
/**
 *  未登录情况下修改用户密码
 *  POST auth/smspassword
 */
+ (void)smspasswordWithParams:(NSDictionary*)param
                      success:(void (^)(id dataObject))success
                      failure:(void (^)(NSError *error))failure;

/**
 *  验证用户登录密码 - Verify the user password
 *  POST /users/verifypwd
 */
+ (void)verifypwdWithParams:(NSDictionary*)param
                    success:(void (^)(id dataObject))success
                    failure:(void (^)(NSError *error))failure;

#pragma mark -
#pragma mark - 发送手机验证码
/**
 *  发送手机验证码
 *
 *  @param params   NSDictionary
    {
         mobile 手机号
    }
 */
+ (void)sendsmsWithParams:(NSDictionary*)params
                  success:(void (^)(id dataObject))success
                  failure:(void (^)(NSError *error))failure;

/**
 *  验证手机验证码 （找回密码／注册 与 更换手机号）
 *  GET /auth/verifysms?
 *
 *  @param params   NSDictionary
 *  {
        mobile 手机号
        code   验证码
    }
 *  @param changePhone 是否用于更换手机号
 */
+ (void)verifysmsWithParams:(NSDictionary*)params
                changePhone:(BOOL)changePhone
                    success:(void (^)(id dataObject))success
                    failure:(void (^)(NSError *error))failure;

/**
 *  验证手机验证码 （用于 注册的时候）
 *  POST /auth/verifysms?
 *
 *  @param params   NSDictionary
 *  {
      mobile 手机号
      code   验证码
     }
 */
+ (void)verifysmsPOSTWithParams:(NSDictionary*)params
                        success:(void (^)(id dataObject))success
                        failure:(void (^)(NSError *error))failure;


#pragma mark -
#pragma mark - 二维码扫描
/**
 *  扫描二维码--App
 *  GET /auth/scanCode
 */
+ (void)scanCodeWithParams:(NSDictionary*)param
                   success:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 *  二维码登录验证--App
 *  POST /auth/registerByCode
 */
+ (void)registerByCodeWithParams:(NSDictionary*)param
                         success:(void (^)(id dataObject))success
                         failure:(void (^)(NSError *error))failure;

/**
 *  二维码登录验证--Web
 *  GET /auth/initQRCode
 */
+ (void)QRCodeSuccess:(void (^)(id dataObject))success
              failure:(void (^)(NSError *error))failure;

/**
 *  二维码验证结果--Web
 *  GET /auth/isRegistered
 */
+ (void)QRRegisteredWithParams:(NSDictionary*)params
                       success:(void (^)(id dataObject))success
                       failure:(void (^)(NSError *error))failure;

@end
