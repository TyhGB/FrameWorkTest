//
//  HttpManager.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/15.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import "AFNetworking.h"
//#import "EUCIMClient.h"

@interface HttpManager : NSObject


+ (instancetype)shareHttpTool;

@property (strong, nonatomic, readonly) AFHTTPSessionManager *httpManager;

- (AFSecurityPolicy *)customSecurityPolicy;

/**
 *  发送POST请求
 *
 *  @param url     请求路径
 *  @param params  请求参数
 *  @param success 请求成功后的回调（请将请求成功后想做的事情写到这个block中）
 *  @param failure 请求失败后的回调（请将请求失败后想做的事情写到这个block中）
 */

- (void)POST:(NSString *)url
      params:(NSDictionary *)params
    progress:(void(^)(NSProgress *  uploadProgress))progress
     success:(void (^)(NSURLSessionDataTask *operation, id responseObject))success
     failure:(void (^)(NSURLSessionDataTask *operation, NSError *error))failure;

/**
 *  发送GET请求 
 *
 *  @param url     请求路径
 *  @param params  请求参数
 *  @param success 请求成功后的回调（请将请求成功后想做的事情写到这个block中）
 *  @param failure 请求失败后的回调（请将请求失败后想做的事情写到这个block中）
 */
- (void)GET:(NSString *)url params:(NSDictionary *)params progress:(void(^)(NSProgress *  uploadProgress))progress success:(void (^)(NSURLSessionDataTask *operation, id responseObject))success failure:(void (^)(NSURLSessionDataTask *operation, NSError *error))failure;

/**
 *  发送DELETE请求
 *
 *  @param url     请求路径
 *  @param params  请求参数
 *  @param success 请求成功后的回调（请将请求成功后想做的事情写到这个block中）
 *  @param failure 请求失败后的回调（请将请求失败后想做的事情写到这个block中）
 */
- (void)DELETE:(NSString *)url
        params:(NSDictionary *)params
       success:(void (^)(NSURLSessionDataTask *, id))success
       failure:(void (^)(NSURLSessionDataTask *, NSError *))failure;

/**
 *  发送PUT请求
 *
 *  @param url     请求路径
 *  @param params  请求参数
 *  @param success 请求成功后的回调（请将请求成功后想做的事情写到这个block中）
 *  @param failure 请求失败后的回调（请将请求失败后想做的事情写到这个block中）
 */
- (void)PUT:(NSString *)url
     params:(NSDictionary *)params
    success:(void (^)(NSURLSessionDataTask *, id))success
    failure:(void (^)(NSURLSessionDataTask *, NSError *))failure;

/**
 发送 POST 请求(上传文件)
 
 @param url 请求路径
 @param params 请求参数
 @param fileName 文件名称
 @param fileDatas 文件数据集合
 @param fileDataKey 文件对应key
 @param progress 请求进度
 @param success 请求成功的回调
 @param failure 请求失败的回调
 @return 当前请求任务对象
 */
- (NSURLSessionDataTask*)filePOST:(NSString *)url
                           params:(NSDictionary *)params
                         fileName:(NSString *)fileName
                         fileDatas:(NSArray *)fileDatas
                      fileDataKey:(NSString *)fileDataKey
                         progress:(void(^)(NSProgress *  uploadProgress))progress
                          success:(void (^)(NSURLSessionDataTask *operation, id responseObject))success
                          failure:(void (^)(NSURLSessionDataTask *operation, NSError *error))failure;

/** 取消当前正在发送中的请求 */
+ (void)cancelAllRequest;

@end
