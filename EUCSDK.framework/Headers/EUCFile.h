//
//  EUCFile.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/9/27.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCFile : NSObject

/**
 *  关于文件hashCode计算
 *  如果你能够确认文件 <= 4M，那么 hash = UrlsafeBase64([0x16, sha1(FileContent)])。也就是，文件的内容的sha1值（20个字节），前面加一个byte（值为0x16），构成 21 字节的二进制数据，然后对这 21 字节的数据做 urlsafe 的 base64 编码。
 *  如果文件 > 4M，则 hash = UrlsafeBase64([0x96, sha1([sha1(Block1), sha1(Block2), ...])])，其中 Block 是把文件内容切分为 4M 为单位的一个个块，也就是 BlockI = FileContent[I*4M:(I+1)*4M]。
 */

/**
 * Base64编码示例：
 data:audio/mp3;base64,//MoxAAAAANIAAAAAExBTUUDAAkIAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 *
 */

/**
 文件直传 (MultipartFile方式)

 @param params 上传参数
             hashCode-文件hashCode
 @param fileName 文件名称
 @param fileData 文件(MultipartFile)
 @param fileDataKey 文件对应key
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 
 @return 上传任务
 */
+ (NSURLSessionDataTask *)uploadMultipartFile:(NSDictionary *)params
                   fileName:(NSString *)fileName
                   fileData:(id)fileData
                fileDataKey:(NSString *)fileDataKey
                   progress:(void(^)(NSProgress *uploadProgress))progress
                    success:(void(^)(id dataObject))success
                    failure:(void(^)(NSError *error))failure;



/**
 文件直传 (Base64方式)

 @param params 上传参数
             hashCode-文件hashCode
             base64-文件base64编码
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 */
+ (void)uploadBase64File:(NSDictionary *)params
                progress:(void(^)(NSProgress *uploadProgress))progress
                 success:(void(^)(id dataObject))success
                 failure:(void(^)(NSError *error))failure;


/**
 文件分片注册

 @param params 上传参数
             hashCode-文件hashCode
             totalChunkNum-文件总分片数
             fileName-文件全名
             fileSize-文件大小（字节数）
 @param success 上传成功回调
 @param failure 上传失败回调
 */
+ (void)registerSplitFile:(NSDictionary *)params
                  success:(void(^)(id dataObject))success
                  failure:(void(^)(NSError *error))failure;


/**
 文件分片上传

 @param params 上传参数
             hashCode-文件hashCode
             chunkHashCode-文件分片hashCode
             chunkIndex-文件片索引
 @param fileName 文件名称
 @param fileData 文件(MultipartFile)
 @param fileDataKey 文件对应key
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 
 @return 上传任务
 */
+ (NSURLSessionDataTask *)uploadSplitMutipartFile:(NSDictionary *)params
                       fileName:(NSString *)fileName
                       fileData:(id)fileData
                    fileDataKey:(NSString *)fileDataKey
                       progress:(void(^)(NSProgress *uploadProgress))progress
                        success:(void(^)(id dataObject))success
                        failure:(void(^)(NSError *error))failure;

//////////////////////////// 文件发送 /////////////////////////////////


/**
 获取新文件下载链接 （新文件发送前上传）
 
 发送文件给群聊，则应包含fileToken_own、downloadUrl、fileName
 发送文件给私聊，则应包含fileToken_friend、downloadUrl、fileName

 @param params 上传参数
          dialogId-会话ID
 @param fileName 文件名称
 @param fileData 文件
 @param fileDataKey 文件对应key
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 
 @return 上传任务
 */
+ (NSURLSessionDataTask *)sendFile:(NSDictionary *)params
        fileName:(NSString *)fileName
        fileData:(id)fileData
     fileDataKey:(NSString *)fileDataKey
        progress:(void(^)(NSProgress *uploadProgress))progress
         success:(void(^)(id dataObject))success
         failure:(void(^)(NSError *error))failure;


/**
 获取转发文件下载链接  (文件转发前)
 
 群聊若未下载文件就直接转发文件，则视作已下载，应先调用下载文件接口
 #warning - XLL
   只有转发私聊调用此接口？
 
 @param params 上传参数
             fileToken-文件seafileKey
             dialogId-会话ID
 @param success 请求成功回调
 @param failure 请求失败回调
 */
+ (void)forwardFile:(NSDictionary *)params
            success:(void(^)(id dataObject))success
            failure:(void(^)(NSError *error))failure;



/**
 群聊下载调用
 
         通知后端同志们，你要下载这个文件
         后端同志同步将文件放入seafile，并返回给你这个文件在你的seafile的标签
 @param params 上传参数
             fileToken-文件seafileKey
 @param success 请求成功回调
 @param failure 请求失败回调
 */
+ (void)downLoadFile:(NSDictionary *)params
             success:(void(^)(id dataObject))success
             failure:(void(^)(NSError *error))failure;


/**
 私聊下载调用

 @param params 上传参数
             fileToken-此文件在我名下的seafileKey
 @param success 请求成功回调
 @param failure 请求失败回调
 */
+ (void)downLoadPersonFile:(NSDictionary *)params
                   success:(void(^)(id dataObject))success
                   failure:(void(^)(NSError *error))failure;

/**
 获取新文件下载链接注册（分片注册，适用于大于4M的文件）
 
 @param params 上传参数
             dialogId-会话ID
             hashCode-文件hashCode
             totalChunkNum-文件总分片数
             fileName-文件全名
             fileSize-文件大小（字节数）
 @param success 请求成功回调
 @param failure 请求失败回调
 */
+ (void)sendRegisterSplitFile:(NSDictionary *)params
                      success:(void(^)(id dataObject))success
                      failure:(void(^)(NSError *error))failure;


/**
 获取新文件下载链接（分片上传，适用于大于4M的文件）

 @param params 上传参数
             dialogId-会话ID
             hashCode-文件hashCode
             chunkHashCode-文件分片hashCode
             chunkIndex-文件片索引
 @param fileName 文件名称
 @param fileData 文件
 @param fileDataKey 文件对应key
 @param progress 上传进度回调
 @param success 上传成功会掉
 @param failure 上传失败回调
 
 @return 上传任务
 */
+ (NSURLSessionDataTask *)sendUploadSplitFile:(NSDictionary *)params
                   fileName:(NSString *)fileName
                   fileData:(id)fileData
                fileDataKey:(NSString *)fileDataKey
                   progress:(void(^)(NSProgress *uploadProgress))progress
                    success:(void(^)(id dataObject))success
                    failure:(void(^)(NSError *error))failure;



/**
 查询用户上传的所有文件

 @param params 上传参数
             userId-文件发送者ID
 @param success 查询成功回调
 @param failure 查询失败回调
 */
+ (void)findAllFiles:(NSDictionary *)params
             success:(void(^)(id dataObject))success
             failure:(void(^)(NSError *error))failure;



/**
 根据fileToken获取下载链接

 @param params 上传参数
             fileToken-文件在我名义下的fileToken
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)getDownLoadUrl:(NSDictionary *)params
               success:(void(^)(id dataObject))success
               failure:(void(^)(NSError *error))failure;


/**
 DELETE chat/file/deleteFile
 删除seafile指定文件
 @param params 上传参数
        fileToken   文件Key
 */
+ (void)deleteFile:(NSDictionary *)params
           success:(void(^)(id dataObject))success
           failure:(void(^)(NSError *error))failure;

/**
 DELETE chat/file/bulkDeleteFile
 批量删除seafile文件
 批量删除seafile指定文件，fileTokens使用英文逗号隔开
 @param params 上传参数
 fileTokens   文件Keys
 */
+ (void)bulkDeleteFile:(NSDictionary *)params
           success:(void(^)(id dataObject))success
           failure:(void(^)(NSError *error))failure;


/**
 GET chat/file/findFilesByWord
 搜索文件
 */
+ (void)findFilesByWord:(NSDictionary *)params
                success:(void(^)(id dataObject))success
                failure:(void(^)(NSError *error))failure;

@end
