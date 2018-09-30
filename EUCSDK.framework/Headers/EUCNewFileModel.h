//
//  EUCNewFileModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/10.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//  上传的新文件模型

#import "EUCBaseModel.h"
#import <UIKit/UIKit.h>

@interface EUCNewFileModel : EUCBaseModel


/**
 文件临时路径
 */
@property (nonatomic, copy, readonly) NSString *filePath;

/**
 文件名称
 */
@property (nonatomic, copy) NSString *fileName;

/**
 指向临时路径的标识
 */
@property (nonatomic, copy, readonly) NSString *client_msg_id;

/**
 文件缩略图
 */
@property (nonatomic, strong) UIImage *thumb;


/**
 初始化文件模型

 @param originPath 文件原路径
 @param fileName 文件名称
 @param thumb 文件缩略图
 @return 文件模型对象
 */
- (instancetype)initWithOriginPath:(NSString *)originPath
                          fileName:(NSString *)fileName
                             thumb:(UIImage *)thumb;

/**
 初始化文件模型

 @param originData 文件原二进制数据
 @param fileName 文件名称
 @param thumb 文件缩略图
 @return 文件模型对象
 */
- (instancetype)initWithOriginData:(NSData *)originData
                          fileName:(NSString *)fileName
                             thumb:(UIImage *)thumb;

@end
