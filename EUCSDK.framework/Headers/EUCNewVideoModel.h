//
//  EUCNewVideoModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/1/23.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"
#import <UIKit/UIKit.h>

@interface EUCNewVideoModel : EUCBaseModel

- (instancetype)init NS_UNAVAILABLE;
/**
 内部生成，小视频名称
 */
@property (nonatomic, copy) NSString *videoName;

/**
 小视频时长
 */
@property (nonatomic, assign) NSInteger videoSeconds;

/**
 视频大小（单位：字节）
 */
@property (nonatomic, assign) NSInteger videoSize;

/**
 小视频缩略图
 */
@property (nonatomic, strong) UIImage *placeHolderImage;

/**
 指向临时路径标识
 */
@property (nonatomic, copy, readonly) NSString *client_msg_id;

/**
 初始化方法
 生成小视频临时路径，与指向临时路径的标识
 
 @param videoUrl 小视频本地路径url
 @param videoSeconds 视频时长 单位秒
 @param placeHolderImage 小视频缩略图
 @return 小视频对象
 */
- (instancetype)initWithVideoUrl:(NSURL *)videoUrl
                    videoSeconds:(NSInteger)videoSeconds
                placeHolderImage:(UIImage *)placeHolderImage;

@end
