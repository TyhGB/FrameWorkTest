//
//  EUCFileAttributes.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/4/27.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//  为文件添加属性，获取属性功能
//  一般指发送文件的时间，发送人

#import <Foundation/Foundation.h>

@interface EUCFileAttributes : NSObject

/**
 * @brief 为文件添加属性
 * @param filePath 文件路径
 * @param key      属性key
 * @param value    属性value
 */
+ (BOOL)extendedStringValueWithFilePath:(NSString *)filePath key:(NSString *)key value:(NSString *)value;

/**
 * @brief 查询文件属性
 * @param filePath 文件路径
 * @param key      属性key
 */
+ (NSString *)stringValueWithFilePath:(NSString *)filePath key:(NSString *)key;


/**
 * @brief 获取文件大小
 * @param filePath 文件路径
 */
+ (NSString *)fileSizeAtPath:(NSString*)filePath;


/**
 * @brief 文件为转换大小
 * @param filePath 文件路径
 */
+ (long long)fileOriginSizeAtPath:(NSString*)filePath;

@end
