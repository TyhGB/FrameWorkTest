//
//  EUCChatManager.h
//  EUCIMManager
//
//  Created by XLL on 2017/7/24.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CLLocation.h>


// 消息发送失败通知
UIKIT_EXTERN NSNotificationName const EUCSendMessageFailureNotification;
// 消息发送成功通知
UIKIT_EXTERN NSNotificationName const EUCSendMessageSuccessNotification;
// 发送文件进度通知
UIKIT_EXTERN NSNotificationName const EUCSendFileProgressNotification;

typedef NS_ENUM(NSUInteger, EUCChatManagerDataType) {
    EUCChatManagerDataTypeText,   // 文本消息
    EUCChatManagerDataTypeVoice,  // 语音消息
    EUCChatManagerDataTypeImage,  // 图片消息
    EUCChatManagerDataTypeVideo,  // 视频消息
    EUCChatManagerDataTypeMap,    // 位置消息
    EUCChatManagerDataTypeCard,   // 个人名片消息
    EUCChatManagerDataTypeFile,   // 文件消息
    EUCChatManagerDataTypeArticle, // 文章消息
    EUCChatManagerDataTypeMerge   // 聊天记录
};


@class EUCReceivedMessageModel, EUCChatManager, EUCMessageModel, EUCNewImageModel, EUCNewVideoModel, EUCNewVoiceModel, EUCNewFileModel, EUCFavoritesModel;
@protocol EUCChatManagerDelegate <NSObject>

/**
 发送成功的消息

 @param chatManager chatManager
 @param receivedMessageModel receivedMessageModel
 @param data 成功消息的数据
 @param placeholderImage 占位图
 @param isRetry 是否重试
 @param dataType 类型
 */
- (void)chatManager:(EUCChatManager *)chatManager sendMessageSuccessWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel data:(NSArray *)data placeholderImage:(UIImage *)placeholderImage isRetry:(BOOL)isRetry dataType:(EUCChatManagerDataType)dataType;

/**
 图片上传进度

 @param chatManager chatManager
 @param receivedMessageModel receivedMessageModel
 @param progresses 进度
 */
- (void)chatManager:(EUCChatManager *)chatManager uploadImageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel progresses:(CGFloat)progresses;

/**
 视频上传进度
 
 @param chatManager chatManager
 @param receivedMessageModel receivedMessageModel
 @param progresses 进度
 */
- (void)chatManager:(EUCChatManager *)chatManager uploadVideoWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel progresses:(CGFloat)progresses;


/**
 文件上传进度 (废弃，使用通知)

 @param chatManager chatManager
 @param receivedMessageModel receivedMessageModel
 @param progresses 上传进度
 */
- (void)chatManager:(EUCChatManager *)chatManager uploadFileWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel progresses:(CGFloat)progresses;

@end

@protocol EUCChatManagerReceiveDelegate <NSObject>

/**
 接收一条及以上的消息集合
 
 @param chatManager chatManager
 @param messages 接收到的消息集合
 */
- (void)chatManager:(EUCChatManager *)chatManager didReceiveMessages:(NSArray *)messages;


/**
 接收一条及以上已读回执

 @param chatManager chatManager
 @param reads 已读数据集合
 */
- (void)chatManager:(EUCChatManager *)chatManager didReceiveReads:(NSArray *)reads;

@end

@interface EUCChatManager : NSObject

/** 上传图片进度的字典 */
@property (nonatomic, strong, readonly) NSMutableDictionary <NSString *,NSMutableArray<EUCMessageModel *> *>*updalodProgressDic;

+ (instancetype)shareInstance;

/**
 添加接收消息的回调代理
 
 @param receiveDelegate 要添加的代理
 @param queue 执行代理方法的队列
 */
- (void)addReceiveDelegate:(id <EUCChatManagerReceiveDelegate>)receiveDelegate delegateQueue:(dispatch_queue_t)queue;

@property (nonatomic, weak) id<EUCChatManagerDelegate> delegate;



/**
 重连socket时，要把在没有连接socket时的消息重新发送一遍

 @param callbackData callbackData
 */
- (void)reconnectSocketWithCallback:(NSDictionary *)callbackData;

/**
 因为闪退或者崩溃或者杀死程序做的处理
 */
+ (void)exceptionHandle;

///////////////////////////// 完美分割线 /////////////////////////////////
#pragma mark - 构造消息方法
/**
 构造文本消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”
 
 @param dialogID 会话ID
 @param text 文本内容
 @param atList @成员集合
 @return 文本消息对象
 */
+ (EUCReceivedMessageModel *)createTextMessage:(NSString *)dialogID
                                          text:(NSString *)text
                                       at_list:(NSArray *)atList
                                     emojiInfo:(NSDictionary *)emojiDic;


/**
 构造位置消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”

 @param dialogID 会话ID
 @param coordinate 经纬度
 @param address 地址
 @param mapImageStr 地图截图base64
 @return 位置消息对象
 */
+ (EUCReceivedMessageModel *)createLocationMessage:(NSString *)dialogID
                                        coordinate:(CLLocationCoordinate2D)coordinate
                                           address:(NSString *)address
                                 mapImageBase64Str:(NSString *)mapImageStr;


/**
 构造名片消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”

 @param dialogID 会话ID
 @param cardName 名片人姓名
 @param cardAvatar 名片人头像
 @param cardID 名片人ID
 @return 名片消息对象
 */
+ (EUCReceivedMessageModel *)createCardMessage:(NSString *)dialogID
                                      cardName:(NSString *)cardName
                                    cardAvatar:(NSString *)cardAvatar
                                        cardID:(NSString *)cardID;


/**
 构造文章消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”
 
 @param dialogID 会话ID
 @param articleUrl 文章链接
 @param articleTitle 文章标题
 @param articleDescription 文章描述
 @param articleBase64Str 文章图片base64(根据网页img标签的src属性决定是否为base64)
 @param articleUrlStr 文章图片url(根据网页img标签的src属性巨鼎是否为url)
 @return 文章消息对象
 */
+ (EUCReceivedMessageModel *)createArticleMessage:(NSString *)dialogID
                                       articleUrl:(NSString *)articleUrl
                                     articleTitle:(NSString *)articleTitle
                               articleDescription:(NSString *)articleDescription
                              articleImgBase64Str:(NSString *)articleBase64Str
                                 articleImgUrlStr:(NSString *)articleUrlStr;


/**
 构造图片消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”
 
 @param dialogID 会话ID
 @param imageModel 图片临时模型
 @return 图片消息对象
 */
+ (EUCReceivedMessageModel *)createImageMessage:(NSString *)dialogID
                                     imageModel:(EUCNewImageModel *)imageModel;


/**
 构造小视频消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态“发送中”

 @param dialogID 会话ID
 @param videoModel 小视频模型 
 @return 视频消息对象
 */
+ (EUCReceivedMessageModel *)createVideoMessage:(NSString *)dialogID
                                     videoModel:(EUCNewVideoModel *)videoModel;


/**
 构造语音消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态“发送中”

 @param dialogID 会话ID
 @param voiceModel 语音模型
 @return 语音消息对象
 */
+ (EUCReceivedMessageModel *)createVoiceMessage:(NSString *)dialogID
                                     voiceModel:(EUCNewVoiceModel *)voiceModel;

/**
 构造合并消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”

 @param dialogID 会话ID
 @param messages 多条消息的消息模型集合
 @return 合并消息对象
 */
+ (EUCReceivedMessageModel *)createMergeMessage:(NSString *)dialogID
                                       messages:(NSArray <EUCMessageModel *>*)messages;

/**
 构造文件消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”

 @param dialogID 会话ID
 @param fileModel 文件模型
 @return 文件消息对象
 */
+ (EUCReceivedMessageModel *)createFileMessage:(NSString *)dialogID
                                     fileModel:(EUCNewFileModel *)fileModel;

/**
 构造转发消息，并在本地数据库异步插入这条消息的消息体
 插入的消息体，发送状态为“发送中”

 @param dialogID 会话ID
 @param originModel 被转发的消息模型
 @return 转发消息对象
 */
+ (EUCReceivedMessageModel *)createForwardMessage:(NSString *)dialogID originMessage:(EUCMessageModel *)originModel;


#pragma mark - 发送消息方法
/**
 发送文本消息
 内部处理了会话列表最后一条消息显示
 
 @param receivedMessageModel 文本消息对象
 @param isRetry isRetry
 */
- (void)sendTextMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


/**
 发送位置消息
 内部处理了会话列表最后一条消息显示

 @param receivedMessageModel 位置消息对象
 @param isRetry isRetry
 */
- (void)sendLocationMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


/**
 发送名片消息
 内部处理了会话列表最后一条消息显示

 @param receivedMessageModel 名片消息对象
 @param isRetry isRetry
 */
- (void)sendCardMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


/**
 发送文章消息
 内部处理了会话列表最后一条消息显示

 @param receivedMessageModel 文章消息对象
 @param isRetry isRetry
 */
- (void)sendArticleMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


/**
 发送图片消息
 内部首先会做上传处理，上传进度由通知发放。并且处理了会话列表最后一条消息显示

 @param receivedMessageModel 图片消息对象
 @param isRetry isRetry
 */
- (void)sendImageMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;

/**
 发送小视频消息
 内部会先做上传处理，上传进度由通知发送。并且处理了会话列表最后一条消息显示
 
 @param receivedMessageModel 小视频消息对象
 @param isRetry isRetry
 */
- (void)sendVideoMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;

/**
 发送语音消息
 内部会先做上传处理，并且处理了会话列表最后一条消息显示

 @param receivedMessageModel 语音消息对象
 @param isRetry isRetry
 */
- (void)sendVoiceMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;

/**
 发送合并消息
 内部处理了会话列表最后一条消息的显示

 @param receivedMessageModel 合并消息对象
 @param isRetry isRetry
 */
- (void)sendMergeMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


/**
 发送文件消息
 内部会先做上传处理，上传进度由通知发送。并且处理了会话列表最后一条消息显示

 @param receivedMessageModel 文件消息对象
 @param isRetry isRetry
 */
- (void)sendFileMessageWithReceivedMesageModel:(EUCReceivedMessageModel *)receivedMessageModel retrySend:(BOOL)isRetry;


#pragma mark - 转发消息方法
/**
 转发消息
 内部会处理会话的最后一条消息

 @param receivedMessageModel 消息对象
 */
- (void)sendForwardMessageWithReceivedMessageModel:(EUCReceivedMessageModel *)receivedMessageModel;


#pragma mark - 消息其他功能
/**
 发送已读回执

 @param dialogID 会话ID
 @param completion 发送结果回调
 */
- (void)sendMessageRead:(NSString *)dialogID
             completion:(void(^)(id dataObject, NSError *error))completion;


/**
 撤回消息

 @param messageModel 需要撤回的消息对象
 @param completion 撤回完成回调
 */
- (void)recallMessage:(EUCMessageModel *)messageModel
           completion:(void(^)(id dataObject, NSError *error))completion;

/**
 收藏消息

 @param messageModel 需要收藏的消息对象
 @param completion 收藏完成回调
 */
- (void)favoriteMessage:(EUCMessageModel *)messageModel
             completion:(void(^)(NSError *error))completion;

/**
 收藏多条消息
 注意：messageModels.count 必须> 1

 @param messageModels 多条消息对象集合
 @param completion 收藏完成回调
 */
- (void)favoriteMessages:(NSArray <EUCMessageModel *>*)messageModels
             complection:(void(^)(id dataObject, NSError *error))completion;

/**
 获取某一页的收藏消息集合

 @param page 页数
 @param success 成功回调消息收藏模型的集合
 @param failure 失败回调
 */
- (void)asyncGetFavoriteList:(NSInteger)page
                     success:(void(^)(NSArray <EUCFavoritesModel *>*favoriteList))success
                     failure:(void(^)(NSError *error))failure;

/**
 删除收藏的消息

 @param favoriteID 消息收藏ID
 @param completion 操作完成回调
 */
- (void)asyncRemoveFavorite:(NSString *)favoriteID
                 completion:(void(^)(NSError *error))completion;


#pragma mark - 本地消息
/**
 获取某个会话中pageOffset偏移量的消息

 @param dialogID 会话ID
 @param pageOffset 消息在数据表中的偏移量
 @param limit 一次拉取的条数
 @return 获取到的EUCMessageModel列表
 */
- (NSArray <EUCMessageModel *>*)getLocalMessages:(NSString *)dialogID pageOffset:(int)pageOffset limit:(int)limit;


/**
 根据指定的消息ID，从DB里移除此条消息
 同步方法，会阻塞当前线程

 @param messageID 指定的消息ID
 @return 移除结果
 */
- (BOOL)deleteLocalMessage:(NSString *)messageID;

/**
 根据指定的会话ID，从DB里移除这个会话相关的所有消息
 同步方法，会阻塞当前线程

 @param dialogID 会话ID
 @return 清理结果
 */
- (BOOL)clearDialogAllMessages:(NSString *)dialogID;

/**
 更新消息至DB
 同步方法，会阻塞当前线程

 @param receivedMessage 消息
 @return 更新结果
 */
- (BOOL)updateMessage:(EUCReceivedMessageModel *)receivedMessage;

/**
 同步消息

 @param type 同步类型  同步7天 @"1"；同步30天 @"3"；下拉请求 @"0"
 @param limit 同步的条数
 @param lastMsgID 从某一条消息开始同步的消息ID
 @param dialogID 会话ID
 @param progress 同步进度
 @param success 成功回调
 @param failure 失败回调
 */
- (void)syncHistoryMessage:(NSString *)type
                     limit:(NSInteger)limit
                 lastMsgID:(NSString *)lastMsgID
                  dialogID:(NSString *)dialogID
                  progress:(void(^)(NSProgress *))progress
                   success:(void(^)(NSArray <EUCMessageModel *>*))success
                   failure:(void(^)(NSError *))failure;

@end
