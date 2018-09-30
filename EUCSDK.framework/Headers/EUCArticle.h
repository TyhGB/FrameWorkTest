//
//  EUCArticle.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/27.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface EUCArticle : NSObject


/**
 消息发送（分享文章）

 @param params 请求参数
             applicationId-应用ID
             targetRoom-发送的会话
             sender_id-发送者ID
             msgType-消息类型(文章为article)
             msgData-消息体（json字符串）
 @param success 请求成功
 @param failure 请求失败
 */
+ (void)sendChatMessage:(NSDictionary *)params
               progress:(void(^)(CGFloat progressValue))progress
                success:(void(^)(id dataObject))success
                failure:(void(^)(NSError *error))failure;



/**
 转发文章

 @param params 请求参数
             url-文章url
             dialogId-会话ID
 @param success 请求成功
 @param failure 请求失败
 */
+ (void)transmitArticles:(NSDictionary *)params
                 success:(void(^)(id dataObject))success
                 failure:(void(^)(NSError *error))failure;



/**
 点击文章链接

 @param params 请求参数
             url-文章url
             dialogId-会话ID
 @param success 请求成功
 @param failure 请求失败
 */
+ (void)clickArticleLinks:(NSDictionary *)params
                  success:(void(^)(id dataObject))success
                  failure:(void(^)(NSError *error))failure;

@end
