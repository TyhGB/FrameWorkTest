//
//  NetWorkEngine+Article.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/11/12.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "NetWorkEngine.h"

@interface NetWorkEngine (Article)

/**
 * 消息发送
 * POST chat/Message/sendMessage
 */
+ (void)sendChatMessageWithParams:(NSDictionary *)params
                         progress:(void(^)(NSProgress *uploadProgress))progress
                          success:(void(^)(id dataObject))success
                          failure:(void(^)(NSError *error))failure;

/**
 * 文章转发
 * POST chat/article/transmitArticles
 */
+ (void)transmitArticlesWithParams:(NSDictionary *)params
                           success:(void(^)(id dataObject))success
                           failure:(void(^)(NSError *error))failure;

/**
 * 点击文章链接
 * POST /chat/article/clickArticleLinks
 */
+ (void)clickArticleLinksWithParams:(NSDictionary *)params
                            success:(void(^)(id dataObject))success
                            failure:(void(^)(NSError *error))failure;


@end
