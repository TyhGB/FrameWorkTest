//
//  BaseNetWorkEngine.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/15.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import "AFNetworking.h"
//#import "EUCIMClient.h"

@interface BaseNetWorkEngine : NSObject

/**
 *  POST data from newtork
 *
 *  @param url     path string
 *  @param param   NSDictionary
 *  @param failure error ever occur
 */
+ (void)POSTWithPath:(NSString *)url
               param:(id)param
            progress:(void(^)(NSProgress *  uploadProgress))progress
             success:(void (^)(id dataObject))success
             failure:(void (^)(NSError *error))failure;

/**
 *  GET data from newtork
 *
 *  @param url     path string
 *  @param param   NSDictionary
 *  @param failure error ever occur
 */
+ (void)GETWithPath:(NSString *)url
              param:(id)param
           progress:(void(^)(NSProgress *  uploadProgress))progress
            success:(void (^)(id dataObject))success
            failure:(void (^)(NSError *error))failure;

/**
 *  DELETE data from newtork
 *
 *  @param url     path string
 *  @param param   NSDictionary
 *  @param failure error ever occur
 */
+ (void)DELETEWithPath:(NSString *)url
                 param:(id)param
               success:(void (^)(id dataObject))success
               failure:(void (^)(NSError *error))failure;

/**
 *  PUT data from newtork
 *
 *  @param url     path string
 *  @param param   NSDictionary
 *  @param failure error ever occur
 */
+ (void)PUTWithPath:(NSString *)url
              param:(id)param
            success:(void (^)(id dataObject))success
            failure:(void (^)(NSError *error))failure;

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
 */
+ (NSURLSessionDataTask *)filePOST:(NSString *)url
          params:(NSDictionary *)params
        fileName:(NSString *)fileName
       fileDatas:(NSArray *)fileDatas
     fileDataKey:(NSString *)fileDataKey
        progress:(void(^)(NSProgress *  uploadProgress))progress
         success:(void (^)(id responseObject))success
         failure:(void (^)(NSError *error))failure;


@end
