//
//  EUCFileHash.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/9/26.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCFileHash : NSObject


/**
 通过文件路径得出文件urlsafe的base64编码

 @param filePath 文件路径
 @return urlsafe的base64编码
 */
+ (void)fileHashWithFilePath:(NSString *)filePath hashSucess:(void (^)(NSString *fileHash))hashSucess;


/**
 通过文件二进制得到文件urlsafe的base64编码

 @param fileData 文件二进制
 @return urlsafe的base64编码
 */
//+ (NSString *)fileHashWithFileData:(NSData *)fileData;
+ (void)fileHashWithFileData:(NSData *)fileData hashSucess:(void (^)(NSString *fileHash))hashSucess;


/**
 LL整理最终版

 @param filePath 文件路径
 @return urlsafe的base64编码
 */
+ (NSString *)fileHashWithFilePath:(NSString *)filePath;

// 分片使用
+ (NSString *)fileHashWithFileData:(NSData *)fileData;

@end
