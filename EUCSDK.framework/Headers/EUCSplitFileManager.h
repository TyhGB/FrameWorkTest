//
//  EUCSplitFileManager.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/9/22.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCSplitFileManager : NSObject

// 本地文件上传标识（消息标识）
@property (nonatomic, copy) NSString *client_msg_id;
// 文件路径
@property (nonatomic, copy) NSString *filePath;
// 分片文件存储文件夹的绝对路径
@property (nonatomic, copy) NSString *splitFilePath;
// 文件名称
@property (nonatomic, copy) NSString *fileName;
// 文件缩略图(base64)
@property (nonatomic, copy) NSString *thumb;
// 文件hashCode(urlsafe的base64)
@property (nonatomic, copy) NSString *fileHash;
// 文件总大小
@property (nonatomic, assign) NSUInteger fileLength;
// 文件片总个数
@property (nonatomic, assign) NSInteger trunkCount;
// 文件句柄
@property (nonatomic, strong) NSFileHandle *fileHandle;
// 每个文件片对应的上传进度
@property (nonatomic, strong) NSMutableDictionary *trunkInfoDict;


/**
 初始化自定义的文件管理器

 @param filePath 文件路径
 @param fileName 文件名称
 @param thumb 文件缩略图
 @param client_msg_id 本地文件标识
 @return 自定义文件管理器对象
 */
- (instancetype)initWithFilePath:(NSString *)filePath FileName:(NSString *)fileName Thumb:(NSString *)thumb Client_msg_id:(NSString *)client_msg_id;


/**
 文件哈希

 @param hashSucess 哈希成功回调
 */
- (void)fileHash:(void (^)(void))hashSucess __attribute__((deprecated("方法过期，请勿再继续使用")));

/**
 创建未上传分片的文件片文件

 @param uploadTrunks 已上传的分片
 @return 创建的分片文件路径集合
 */
- (NSMutableArray *)createFileBeforeUpload:(NSArray *)uploadTrunks;

/**
 删除分片文件

 @param splitPath 分片文件绝对路径
 */
- (void)deleteSplitFileWithSplitPath:(NSString *)splitPath;

@end


