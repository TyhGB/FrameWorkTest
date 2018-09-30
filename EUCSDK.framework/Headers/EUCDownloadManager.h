//
//  ECDownloadManager.h
//  ElecCarManager
//
//  Created by Tuling Code on 16/9/8.
//  Copyright © 2016年 BBDTek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EUCBaseModel.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, EUCDownloadStateType) {
    EUCDownloadStateTypeStart = 0,     /** 下载中 */
    EUCDownloadStateTypeSuspended,     /** 下载暂停 */
    EUCDownloadStateTypeCompleted,     /** 下载完成 */
    EUCDownloadStateTypeFailed,        /** 下载失败 */
    EUCDownloadStateTypeUnStart,       /** 暂未下载 */
    EUCDownloadStateTypeInvalid        /** 链接失效 */
};

@interface EUCDownloadModel : EUCBaseModel

/** 下载状态 */
@property (nonatomic, copy) void(^stateBlock)(EUCDownloadStateType stateType);

/** 流 */
@property (nonatomic, strong) NSOutputStream *stream;

/** 下载地址 */
@property (nonatomic, copy) NSString *url;

/** 文件名称 */
@property (nonatomic, copy) NSString *fileName;

/** 文件唯一标识 */
@property (nonatomic, copy) NSString *fileToken;

/** 获得服务器这次请求 返回数据的总长度 */
@property (nonatomic, assign) NSInteger totalLength;

/** 下载进度 */
@property (nonatomic, copy) void(^progressBlock)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress);

@end

// 下载进度通知
#define EUCDownloadProgressNotification @"EUCDownloadProgressNotification"
// 下载成功通知
#define EUCDownloadSuccessNotification @"EUCDownloadSuccessNotification"

@interface EUCDownloadManager : NSObject

/** 初始化单例对象 */
+ (instancetype)sharedInstance;

/**
 *  开启任务下载资源
 *
 *  @param url           下载地址
 *  @param fileToken     文件唯一标识fileToken，文件在我名下的fileToken
 *  @param fileName      存储本地的文件名称
 *  @param progressBlock 回调下载进度
 *  @param stateBlock    下载状态
 */
- (void)download:(NSString *)url fileName:(NSString *)fileName fileToken:(NSString *)fileToken progress:(void(^)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress))progressBlock state:(void(^)(EUCDownloadStateType stateType))stateBlock;

/**
 *  暂停下载
 */
- (void)pause:(NSString *)fileName WithFileID:(NSString *)fileID;

/**
 *  查询该资源的下载进度值
 *
 *  @param fileName 文件名称
 *  @param fileID   音频，视频，图片：下载链接。文件：fileToken
 *  @return 返回下载进度值
 */
- (CGFloat)progress:(NSString *)fileName WithFileID:(NSString *)fileID;

/**
 *  获取该资源总大小
 *
 *  @param fileName 文件名称
 *  @param nameUrl  fileID处理过后的文件下载链接（去除/）
 *  @return 资源总大小
 */
- (NSInteger)fileTotalLength:(NSString *)fileName WithNameUrl:(NSString *)nameUrl;

/**
 *  判断该资源是否下载完成
 *
 *  @param fileName 文件名称
 *  @param fileID  视频，图片：下载链接，文件：fileToken
 *  @return EUCDownloadStateTypeCompleted: 下载完成
 */
- (EUCDownloadStateType)isCompletion:(NSString *)fileName WithFileID:(NSString *)fileID;


/**
 *  @biref 判断是否有此文件的下载任务 ,适用于下载了一部分之后，退出App，或者重用机制
 *  @param fileName 文件名称
 *  @param fileID   图片，视频：下载链接，文件：fileToken
 *  @return  YES    有
 */
- (BOOL)isHaveFileTask:(NSString *)fileName WithFileID:(NSString *)fileID;


/**
 停止所有任务
 */
- (void)stopAllDownloadTask;


/**
 *  删除该资源
 *
 *  @param fileName 文件名称
 *  @param fileID   视频，图片：下载链接，文件：fileToken
 */
- (void)deleteFile:(NSString *)fileName WithFileID:(NSString *)fileID;


/**
 *  清空所有下载资源
 */
- (void)deleteAllFile;

/**
 *  将下载的资源转成二进制
 *  @param fileName 文件名
 *  @param fileID   文件唯一标识 视频图片音频：下载链接，文件：fileToken
 */
- (NSData *)converseFile:(NSString *)fileName WithFileID:(NSString *)fileID;

/**
 * 将下载的资源转成URL
 */
- (NSURL *)converseURLWithFile:(NSString *)fileName WithFileID:(NSString *)fileID;

/**
 * 获取文件路径
 */
- (NSString *)filePathWithFileName:(NSString *)fileName WithFileID:(NSString *)fileID;

/**
 将音频，小视频，图片等复制到指定路径
 注意：非文件所用

 @param fromPath 原有路径
 @param fileUrl  url
 @return YES     复制成功
 */
- (BOOL)copyFileWithFromPath:(NSString *)fromPath FileUrl:(NSString *)fileUrl WithFileName:(NSString *)fileName;



/**
 将文件复制到指定路径，并建立plist文件
 注意：文件专用
 
 @param fromPath 原有路径
 @param fileToken 文件fileToken
 @param fileName 文件名称
 @return YES 复制成功
 */
- (BOOL)copyRealFileWithFromOriginPath:(NSString *)fromPath FileToken:(NSString *)fileToken WithFileName:(NSString *)fileName;

@end
