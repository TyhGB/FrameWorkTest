//
//  NetWorkEngine+File.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/11/12.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "NetWorkEngine.h"

@interface NetWorkEngine (File)

///////////////////////////// 新文件上传接口 ///////////////////////////////////
/**
 *  直传文件（MultipartFile）
 *  POST /resource/upload
 */
+ (NSURLSessionDataTask *)uploadMultipartFileWithParams:(NSDictionary *)params
                             fileName:(NSString *)fileName
                             fileData:(id)fileData
                          fileDataKey:(NSString *)fileDataKey
                             progress:(void(^)(NSProgress *uploadProgress))progress
                              success:(void (^)(id dataObject))success
                              failure:(void (^)(NSError *error))failure;

/**
 *  直传文件 (Base64)
 *  POST /resource/uploadBase64
 */
+ (void)uploadBase64FileWithParams:(NSDictionary *)params
                          progress:(void(^)(NSProgress *uploadProgress))progress
                           success:(void (^)(id dataObject))success
                           failure:(void (^)(NSError *error))failure;

/**
 *  文件分片上传注册接口
 *  POST /resource/upload/splitDetail
 */
+ (void)registerSplitFileWithParams:(NSDictionary *)params
                            success:(void (^)(id dataObject))success
                            failure:(void (^)(NSError *error))failure;




/**
 *  文件分片上传接口
 *  POST /resource/splitUpload
 */
+ (NSURLSessionDataTask *)uploadSplitMultipartFileWithParams:(NSDictionary *)params
                                  fileName:(NSString *)fileName
                                  fileData:(id)fileData
                               fileDataKey:(NSString *)fileDataKey
                                  progress:(void(^)(NSProgress *uploadProgress))progress
                                   success:(void(^)(id dataObject))success
                                   failure:(void(^)(NSError *error))failure;



/**
 *  文件发送-获取新文件下载链接
 *  Post chat/ambryFile/sendFile
 */
+ (NSURLSessionDataTask *)sendFileWithParams:(NSDictionary *)params
                  fileName:(NSString *)fileName
                  fileData:(id)fileData
               fileDataKey:(NSString *)fileDataKey
                  progress:(void(^)(NSProgress *uploadProgress))progress
                   success:(void(^)(id dataObject))success
                   failure:(void(^)(NSError *error))failure;


/**
 *  文件发送-获取转发文件下载链接
 *  Post chat/ambryFile/forwardFile
 */
+ (void)forwardFileWithParams:(NSDictionary *)params
                      success:(void(^)(id dataObject))success
                      failure:(void(^)(NSError *error))failure;


/**
 *  群聊下载调用
 *  Post chat/ambryFile/downLoadFile
 */
+ (void)downloadFileWithParams:(NSDictionary *)params
                       success:(void(^)(id dataObject))success
                       failure:(void(^)(NSError *error))failure;

/**
 *  私聊下载调用
 *  Post chat/ambryFile/downLoadFile/3
 */
+ (void)downLoadPersonFileWithParams:(NSDictionary *)params
                             success:(void(^)(id dataObject))success
                             failure:(void(^)(NSError *error))failure;


/**
 *  查询用户上传的所有文件
 *  GET chat/ambryFile/findAllFiles
 */
+ (void)findAllFilesWithParams:(NSDictionary *)params
                       success:(void(^)(id dataObject))success
                       failure:(void(^)(NSError *error))failure;


/**
 *  根据fileToken获取下载链接
 *  GET chat/ambryFile/getDownLoadUrl
 */
+ (void)getDownLoadUrlWithParams:(NSDictionary *)params
                         success:(void(^)(id dataObject))success
                         failure:(void(^)(NSError *error))failure;

/**
 * 获取新文件下载链接注册（分片注册，适用于大于4M的文件）
 * Post chat/ambryFile/sendSplitFile/splitDetail
 */
+ (void)sendRegisterSplitFileWithParams:(NSDictionary *)params
                                success:(void(^)(id dataObject))success
                                failure:(void(^)(NSError *error))failure;


/**
 * 获取新文件下载链接（分片上传，适用于大于4M的文件）
 * POST  /chat/ambryFile/sendSplitFile
 */
+ (NSURLSessionDataTask *)sendUploadSplitFileWithParams:(NSDictionary *)params
                             fileName:(NSString *)fileName
                             fileData:(id)fileData
                          fileDataKey:(NSString *)fileDataKey
                             progress:(void(^)(NSProgress *uploadProgress))progress
                              success:(void(^)(id dataObject))success
                              failure:(void(^)(NSError *error))failure;

/**
 删除seafile指定文件
 DELETE chat/ambryFile/deleteFile
 */
+ (void)deleteFile:(NSDictionary *)params
           success:(void(^)(id dataObject))success
           failure:(void(^)(NSError *error))failure;

/**
 DELETE chat/ambryFile/bulkDeleteFile
 批量删除seafile文件
 批量删除seafile指定文件，fileTokens使用英文逗号隔开
 @param params 上传参数
 fileTokens   文件Keys
 */
+ (void)bulkDeleteFile:(NSDictionary *)params
               success:(void(^)(id dataObject))success
               failure:(void(^)(NSError *error))failure;

/**
 GET chat/ambryFile/findFilesByWord
 搜索文件
 */
+ (void)findFilesByWord:(NSDictionary *)params
                success:(void(^)(id dataObject))success
                failure:(void(^)(NSError *error))failure;



@end
