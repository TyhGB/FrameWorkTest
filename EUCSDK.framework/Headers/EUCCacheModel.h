//
//  EUCCacheModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/3/30.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseCacheModel.h"
#import <MapKit/MapKit.h>

@class EUCMessageModel, EUCNewFileModel, EUCNewImageModel, EUCNewVideoModel, EUCNewVoiceModel;
@interface EUCCacheModel : EUCBaseCacheModel

/**
 创建dialog表与消息表

 @return 创建结果
 */
+ (BOOL)creatDialogAndMessageTable;

/**
 插入数据（做了去重处理，自觉在子线程中进行）
 Swift Conversion Group
 @param tableName 表名
 @param messageDict 插入内容
 @return 插入结果
 */
+ (BOOL)insertMessageIntoTable:(NSString *)tableName messageDict:(NSDictionary *)messageDict;

/**
 筛选socket发来的消息里的非ACK消息
 
 @param messages socket消息集
 @return 非ACK消息
 */
+ (NSMutableArray *)filterMessageWithNoSystemData:(NSMutableArray <NSDictionary *>*)messages;

/**
 查询消息表
 
 @param tableName 消息表名
 @param dialogID 会话ID
 @param offset 游标
 @param limit 获取多少条
 @return 返回这个范围的数据
 */
+ (NSMutableArray *)queryMessageTableName:(NSString *)tableName dialogID:(NSString *)dialogID offset:(NSInteger)offset limit:(NSInteger)limit;

// 插入一条dialog数据
+ (BOOL)insertDialogToTableWithDialogDict:(NSDictionary *)dialogDict;

/**
 * 更新表中的已读未读
 * @param readID     读取这条消息的人员ID
 * @param dialogID   会话ID
 */
+ (BOOL)updateMessageReadedID:(NSString *)readID dialogID:(NSString *)dialogID;



#pragma mark - 发送消息，存入数据库
/**
 向本地数据库插入一条文字消息

 @param message 消息内容
 @param dialogID 会话ID
 @param mmExt 表情信息
 @return 完整文字消息体
 */
+ (NSMutableDictionary *)sendTextMessage:(NSString *)message
                              inDialogID:(NSString *)dialogID
                                 at_list:(NSArray *)atList
                                emjoyDic:(NSDictionary *)mmExt;


/**
 向本地数据库插入一条文件消息
 
 @param newModel 新文件模型
 @param dialogID 会话ID
 @return 完整文件消息
 */
+ (NSMutableDictionary *)sendFileMessage:(EUCNewFileModel *)newModel
                              inDialogID:(NSString *)dialogID;


/**
 向本地数据库插入一条合并消息
 
 @param messages 要合并消息的消息模型集合
 @param message 合并消息标题
 @param dialogID 会话ID
 @return 完整合并消息
 */
+ (NSMutableDictionary *)sendMergeMessage:(NSArray <EUCMessageModel *>*)messages
                                  message:(NSString *)message
                               inDialogID:(NSString *)dialogID
                              isSaveLocal:(BOOL)isSaveLocal;


/**
 向本地数据库插入一条图片消息

 @param imageModel 图片模型
 @param dialogID 会话ID
 @return 完整图片消息
 */
+ (NSMutableDictionary *)sendNewImage:(EUCNewImageModel *)imageModel
                           inDialogID:(NSString *)dialogID;

/**
 发送小视频消息
 
 @param videoModel 小视频模型
 @param dialogID 会话ID
 @return 完整视频消息体
 */
+ (NSMutableDictionary *)sendNewVideo:(EUCNewVideoModel *)videoModel
                           inDialogID:(NSString *)dialogID;

/**
 发送语音消息
 
 @param voiceModel 语音模型
 @param dialogID 会话ID
 @return 完整语音消息体
 */
+ (NSMutableDictionary *)sendNewVoice:(EUCNewVoiceModel *)voiceModel
                           inDialogID:(NSString *)dialogID;


/**
 发送位置消息
 
 @param coordinate 经纬度
 @param location 位置地点
 @param encodedImageStr 小地图切图
 @param dialogID 会话ID
 @return 完整位置消息体
 */
+ (NSMutableDictionary *)sendMapMessage:(CLLocationCoordinate2D)coordinate
                               location:(NSString *)location
                        encodedImageStr:(NSString *)encodedImageStr
                               inDialog:(NSString *)dialogID;

/**
 发送文章消息

 @param message 文章链接
 @param articleTitle 文章标题
 @param articleContent 文章简介
 @param articleImgUrl 文章中第一张图片链接
 @param articleImgStr 文章中第一张图片链接
 @param dialogID 会话ID
 @return 完整文章消息体
 */
+ (NSMutableDictionary *)sendArticleMessage:(NSString *)message
                               articleTitle:(NSString *)articleTitle
                             articleContent:(NSString *)articleContent
                              articleImgUrl:(NSString *)articleImgUrl
                              articleImgStr:(NSString *)articleImgStr
                                 inDialogID:(NSString *)dialogID;


/**
 发送名片消息

 @param message 名片所有者名字
 @param cardUserAvatar 名片所有者头像
 @param cardUserID 名片所有者ID
 @param dialogID 会话ID
 @return 完整名片消息体
 */
+ (NSMutableDictionary *)sendCardMessage:(NSString *)message
                          cardUserAvatar:(NSString *)cardUserAvatar
                              cardUserID:(NSString *)cardUserID
                              inDialogID:(NSString *)dialogID;


/**
 重发，转发文件

 @param messageModel 消息数据模型
 @param dialogID 会话ID
 @return 发送的字典格式
 */
+ (NSMutableDictionary *)forwardFileMessageWithMessageModel:(EUCMessageModel *)messageModel inDialogID:(NSString *)dialogID;

/**
 转发除文件之外的消息
 
 @param messageModel 被转发消息数据模型
 @param dialogID 会话ID
 @return 发送的字典格式
 */
+ (NSMutableDictionary *)forwardNormalMessageWithMessageModel:(EUCMessageModel *)messageModel inDialogID:(NSString *)dialogID;


//根据条件查询此数据在数据表中的rowid
+ (u_int64_t)checkRowidFromTable:(NSString *)tableName byCriteria:(NSString *)criteria;
//获取数据表中最后一条rowid
+ (u_int64_t)lastRowidWithTableName:(NSString *)tableName;



#pragma mark - 真正好友的表
/** 创建好友表 */
+ (void)createRealFriendTable;

#pragma mark - 好友申请表
/** 创建好友申请表 */
+ (void)createFriendRequestTable;



#pragma mark - 手机通讯录
/** 创建手机通讯录表 */
+ (void)createAddressBookContactTable;

/** 更新手机通讯录表 */
+ (void)updateAddressBookContactTableWithList:(NSArray *)addressBookContactList ;


#pragma mark - 黑名单表
/** 创建黑名单表 */
+ (void)createTableToBlicklistList:(NSArray *)blicklistList;

@end
