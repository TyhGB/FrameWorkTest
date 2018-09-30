//
//  EUCIMClient.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/2/26.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//  整个sdk的初始化入口

#import <Foundation/Foundation.h>
#import "EUCUserModel.h"
#import "EUCStyleDefine.h"
#import "EUCSessionModel.h"
typedef NS_ENUM(NSInteger, EUCIMClientVerifyStyle) {
    EUCIMClientVerifyStyleRegister = 1000, //注册
    EUCIMClientVerifyStyleForgetPassword,  //忘记密码
    EUCIMClientVerifyStyleChangePhone      //修改手机号
};

@class EUCIMClient;
@protocol EUCIMClientDelegate <NSObject>

@optional
/**
 @optional
 
 与服务器连接状态改变回调
 */
- (void)imClient:(EUCIMClient *)imClient didStatusChanged:(EUCIMClientStatus)status;

@required
/**
 likimToken过期回执

 @param imClient 用户执行对象
 
 @discussion 用户必须实现此方法,做退出登录处理
 */
- (void)didReceivedTokenOutDate:(EUCIMClient *)imClient;

/**
 另一设备登录，被顶回执

 @param imClient 用户执行对象
 */
- (void)didReceivedUserDisconnect:(EUCIMClient *)imClient;

@end


@interface EUCIMClient : NSObject

/**
 获取EUCSDK核心类单例

 @return EUCSDK核心类单例
 */
+ (instancetype)sharedEUCIMClient;

/**
 初始化EUCSDK
 
 @param appKey 略
 
 @discussion 您在使用EUCSDK所有功能，您必须先调用此方法初始化SDK。
 */
- (void)initializeSDKWithAppKey:(NSString *)appKey;


/**
 添加服务器回调代理

 @param delegate 要添加的代理
 @param delegateQueue 执行代理方法的队列，缺省为主队列
 */
- (void)addDelegate:(id<EUCIMClientDelegate>)delegate
            delegateQueue:(dispatch_queue_t)delegateQueue;

/**
 检测当前是否为登录状态

 @return 是否为登录状态
 
 @discussion 代替[Public loginStatus]方法
 */
- (BOOL)loginStatus;


/**
 获取当前LKIM-Token

 @return LKIM-Token
 */
- (NSString *)lkimToken;



/**
 获取当前Paas平台LKIM-Token
 除登陆注册和用户部分，其他网络请求都使用这个paasToken
 @return Paas LKIM-Token
 */
- (NSString *)paasLkimToken;

/**
 设置paas平台的token
 */
- (void)savePaasToken:(NSString *)paasToken;

/**
// 更新LKIM-Token
//
// @param success 更新成功回调
// @param failure 更新失败回调
//
// @discussion 用于每次登录成功之后
// */
//- (void)renewLkimTokenWithSuccess:(void(^)(id dataObject))success
//                          failure:(void(^)(NSError *error))failure;

/**
 与微会议socket服务器建立连接

 @param token 用户身份令牌
 @param userID 用户ID
 
 @discussion 在App整个生命周期，您只需要调用一次此方法与微会议服务器建立连接。
 之后无论是网络出现异常或者App有前后台的切换等，SDK内部都会负责自动重连。
 */
- (void)connectWithToken:(NSString *)token userID:(NSString *)userID;

/**
 断开与微会议socket服务器的连接

 @param isLogout 是否为退出登录
 */
- (void)disconnectIsLogout:(BOOL)isLogout;

/**
 注册微会议用户
 异步方法

 @param login login
 @param password 密码
 @param fullName 用户名
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncRegisterWithLogin:(NSString *)login
                      password:(NSString *)password
                      fullName:(NSString *)fullName
                       success:(void(^)(id dataObject))success
                       failure:(void(^)(NSError *error))failure;

/**
 账号登录
 异步方法

 @param userName 用户名
 @param password 密码
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncLoginWithUserName:(NSString *)userName
                      password:(NSString *)password
                       success:(void(^)(id dataObject))success
                       failure:(void(^)(NSError *error))failure;

/**
 手机验证登录
 异步方法

 @param mobile 手机号
 @param code 验证码
 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncSmsLoginWithMobile:(NSString *)mobile
                           code:(NSString *)code
                        success:(void(^)(id dataObject))success
                        failure:(void(^)(NSError *error))failure;

/**
 退出登录
 异步方法

 @param success 成功回调
 @param failure 失败回调
 */
- (void)asyncLogoutSuccess:(void (^)(id dataObject))success
                   failure:(void (^)(NSError *error))failure;

/**
 获取手机验证码

 @param mobile 手机号
 @param success 成功回调
 @param failure 失败回调
 */
- (void)sendSmsCodeWithMobile:(NSString *)mobile
                      success:(void(^)(id dataObject))success
                      failure:(void(^)(NSError *error))failure;

/**
 验证手机验证码（找回密码／注册 与 更换手机号）

 @param mobile 手机号
 @param code 验证码
 @param verifyStyle 验证类型
 @param success 成功回调
 @param failure 失败回调
 */
- (void)verifySmsWithMobile:(NSString *)mobile
                       code:(NSString *)code
             verifyStyle:(EUCIMClientVerifyStyle)verifyStyle
                    success:(void(^)(id dataObject))success
                    failure:(void(^)(NSError *error))failure;

/**
 根据用户ID获取用户信息
 
 @param userID 用户ID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getUserInfoWithUserID:(NSString *)userID
                      success:(void(^)(EUCUserModel *userModel))success
                      failure:(void(^)(NSError *error))failure;

/**
 保存用户模型

 @param userModel 要保存的用户模型
 @return 保存结果
 */
- (BOOL)saveUserModel:(EUCUserModel *)userModel;

/**
 将deviceToken传递给SDK

 @param deviceToken deviceToken
 */
- (void)bindDeviceToken:(NSString *)deviceToken;

/**
 登录成功后，向服务器注册deviceToken
 */
- (void)registerDeviceToken;

/**
 更新会话列表的信息，会更新数据库
 */
- (void)updateDialogs;


/**
 当前设备deviceToken
 */
@property (nonatomic, copy) NSString *deviceToken;

/**
 当前登录用户的用户信息
 
 @discussion 代替[Public userModel]方法
 */
@property (nonatomic, strong) EUCUserModel *userModel;

/**
 当前登录用户的用户ID
 */
@property (nonatomic, copy) NSString *user_id;

// 代替appDelegate里的sessionModel
@property (nonatomic, strong) EUCSessionModel *sessionModel;


@end
