//
//  EUCSplitFileUpload.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/9/22.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EUCSplitFileManager.h"

//@class EUCSplitFileManager;
@interface EUCSplitFileUpload : NSObject

/**
 同步分片上传大文件

 @param fileManager 文件信息管理
 @param success 上传成功回调
 @param failure 注册失败回调
 */
+ (void)syncUploadFileWithSplitFileManager:(EUCSplitFileManager *)fileManager progress:(void (^)(CGFloat currentProgress))progress success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure;


/**
 异步分片上传大文件

 @param fileManager 文件信息管理
 @param success 上传成功回调
 @param failure 失败回调
 */
+ (void)asyncUploadFileWithSplitFileManager:(EUCSplitFileManager *)fileManager success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure;


/**
 直传（multipart/form-data）

 @param fileManager 文件信息管理
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 */
+ (void)uploadMultipartFile:(EUCSplitFileManager *)fileManager progress:(void (^)(NSProgress *uploadProgress))progress success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure;



/**
 直传 (base64)

 @param fileManager 文件信息管理
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 上传失败回调
 */
+ (void)uploadBase64File:(EUCSplitFileManager *)fileManager progress:(void (^)(NSProgress *uploadProgress))progress success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure __attribute__((unavailable("此方式适用于web端,前端勿用")));
// NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "此方法适用于web端")


///////////////////////////////// 完美分割线-文件发送 //////////////////////////////////////

/**
 同步发送文件
 小于4M，直传。大于4M，同步分片上传

 @param fileManager 文件信息管理
 @param dialogID 会话ID
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 注册失败回调
 */
+ (void)syncSendFileWithSplitFileManager:(EUCSplitFileManager *)fileManager dialogID:(NSString *)dialogID progress:(void (^)(CGFloat currentProgress))progress success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure;


/**
 异步发送文件
 小于4M，直传。大于4M，异步分片上传
 
 @param fileManager 文件信息管理
 @param dialogID 会话ID
 @param progress 上传进度回调
 @param success 上传成功回调
 @param failure 注册失败回调
 */
+ (void)asyncSendFileWithSplitFileManager:(EUCSplitFileManager *)fileManager dialogID:(NSString *)dialogID progress:(void (^)(CGFloat currentProgress))progress success:(void (^)(id dataObject))success failure:(void (^)(NSError *error))failure;


/**
 暂停上传任务

 @param client_msg_id 当前上传文件的本地标识
 @return 操作成功
 */
+ (BOOL)pauseTaskWithClient_msg_id:(NSString *)client_msg_id;


/**
 恢复上传任务

 @param client_msg_id 当前上传文件的本地标识
 @return 操作失败
 */
+ (BOOL)resumeTaskWithClient_msg_id:(NSString *)client_msg_id;

@end
