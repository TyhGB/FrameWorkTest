//
//  EUCDataFileManager.h
//  EUCIMManager
//
//  Created by ShaoShanPeng on 2017/2/10.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

//文件存储总路径
#define DataFilePath EUCStr(@"%@/Library/Caches/MessageFile",NSHomeDirectory())

@interface EUCDataFileManager : NSObject

+ (instancetype)sharedManager;


/**
 从原路径写内容至临时路径
 __attribute__((deprecated("方法过期，请使用copyFileFromPath:ToPath:方法")))
 
 @param file 文件内容
 @param fileName 临时路径文件名
 @param fileID 临时路径相对路径的目录
 @return 操作结果
 */
- (BOOL)writeDataFile:(NSData *)file FileName:(NSString *)fileName FileID:(NSString *)fileID;

/**
 从临时路径读取内容
 
 @param fileName 临时路径文件名
 @param fileID 临时路径相对路径的目录
 @return 读取的内容
 */
- (id)readDataWithFileName:(NSString *)fileName FileID:(NSString *)fileID;

/**
 从原始路径url复制文件到临时路径(相册里的视频专用)

 @param originUrl 原绝对路径url
 @param fileName 临时路径文件名
 @param fileID 临时路径相对路径的目录
 @return 操作结果
 */
- (BOOL)copyFileWithOriginUrl:(NSURL *)originUrl FileName:(NSString *)fileName fileID:(NSString *)fileID;


/**
 从原路径复制文件到临时路径

 @param originPath 原绝对路径
 @param fileName 临时路径文件名
 @param fileID 临时路径相对路径的目录
 @return 操作结果
 */
- (BOOL)copyFileWithOriginPath:(NSString *)originPath FileName:(NSString *)fileName FileID:(NSString *)fileID;

/**
 获取临时路径的绝对路径

 @param fileName 临时路径文件名
 @param fileID 临时路径相对路径的目录
 @return 临时路径的绝对路径
 */
- (NSString *)getAbsoultePathWithFileName:(NSString *)fileName FileID:(NSString *)fileID;


/**
 从三方共享路径里剪切到本App，作为文件原路径(三方共享专用)

 @param originPath 共享路径
 @param fileName 临时路径文件名
 @return 操作结果
 */
- (BOOL)moveFileWithOriginPath:(NSString *)originPath FileName:(NSString *)fileName;

/**
 得到文件原始绝对路径(三方共享专用)

 @param relativePath 文件原始路径相对路径
 @return 文件原始绝对路径
 */
- (NSString *)getAbsolutePathWithrelativePath:(NSString *)relativePath;

@end
