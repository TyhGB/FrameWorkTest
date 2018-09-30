//
//  EUCNewImageModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/12/1.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//  发送图片临时模型

#import "EUCBaseModel.h"
#import <UIKit/UIKit.h>

@interface EUCNewImageModel : EUCBaseModel

- (instancetype)init NS_UNAVAILABLE;
/**
 图片名称
 */
@property (nonatomic, copy) NSString *imageName;

/**
 图片数据
 */
@property (nonatomic, strong) NSData *imageData;

/**
 缩略图
 */
@property (nonatomic, strong) UIImage *placeHolderImage;

/**
 指向临时路径标识
 */
@property (nonatomic, copy, readonly) NSString *client_msg_id;


/**
 初始化方法
 生成图片临时路径，与指向临时路径的标识

 @param imageName 图片名称
 @param placeHolderImage 缩略图片
 @return 图片对象
 */
- (instancetype)initWithImageData:(NSData *)imageData
                        imageName:(NSString *)imageName
                 placeHolderImage:(UIImage *)placeHolderImage;

@end
