//
//  EUCMessageModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/3/25.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"
#import "EUCUserModel.h"
#import "EUCStyleDefine.h"
#import "EUCDownloadManager.h"

// 聊天气泡边框宽度
static CGFloat ChatBGBorderWidth = 2.0f;
// 聊天气泡箭头宽度
static CGFloat ChatBGBorderArrow = 7.3f;

// 时间文本与边框间隔宽度方向
static NSInteger const ChatTimeMarginW = 15;
// 时间文本与边框间隔高度方向
static NSInteger const ChatTimeMarginH = 8;

// 间隔高度方向
static NSInteger const ChatMarginH = 8;  //间隔高度方向

// 文本内容与气泡上边缘间隔
static NSInteger const ChatContentTop = 12;
// 文本内容与气泡下边缘间隔
static NSInteger const ChatContentBottom = 12;
// 文本内容与按钮左边缘间隔
static NSInteger const ChatContentLeft = 15;
// 文本内容与按钮右边缘间隔
static NSInteger const ChatContentRight = 15;

// 时间字体
#define ChatTimeFont [UIFont systemFontOfSize:13]
// 内容字体
#define ChatContentFont [UIFont systemFontOfSize:16]

// 发送状态-成功
static NSString *const EUCMessageSendSuccess = @"1";
// 发送状态-失败
static NSString *const EUCMessageSendFail = @"-1";
// 发送状态-发送中
static NSString *const EUCMessageSending = @"0";
// 发送状态-无网发送中
static NSString *const EUCMessageSendingNeedResend = @"-0";

// 语音消息-未读
static NSString *const EUCMessageVoiceUnRead = @"0";
// 语音消息-已读
static NSString *const EUCMessageVoiceRead = @"1";

@class EUCMessageExtraModel, EUCMessageDownLoadModel, EUCMessageFrameModel;
@interface EUCMessageModel : EUCBaseModel

/**
 消息内容
 如果是语音/图片/文件则是url
 设置message的时候(set方法)将extraDisplay中的fileToken有关的属性都设置了
 */
@property (nonatomic, copy) NSString*   message;

/**
 消息ID
 */
@property (nonatomic, copy) NSString *_id;

/**
 撤回消息的ID
 */
@property (nonatomic, copy) NSString *message_id;

#warning - SDKFIX
/**
 消息所属会话ID
 FIXME-这里以后要与后台沟通，进行统一
 */
@property (nonatomic, copy) NSString *chat_dialog_id;
@property (nonatomic, copy) NSString *dialog_id;

/**
 消息发送者ID
 */
@property (nonatomic, copy) NSString *sender_id;

/**
 消息类型
 */
@property (nonatomic, assign) EUCMessageType type;

/**
 时间戳
 */
@property (nonatomic, copy) NSString *date_sent;
@property (nonatomic, copy) NSString *updated_at;

/**
 已读消息-消息读取人ID
 */
@property (nonatomic, copy) NSString *user_id;

#warning - SDKFIX
/**
 已读消息-消息未读人员（源数据，可能是数组，可能是json）
 */
@property (nonatomic, strong) id recipient_ids;
/**
 对应recipient_ids，数组
 */
@property (nonatomic, strong) NSMutableArray *recipients;

#warning - SDKFIX
/**
 已读消息-消息已读人员（源数据，可能是数组，可能是json）
 */
@property (nonatomic, strong) id read_ids;
/**
 对应read_ids，数组
 */
@property (nonatomic, strong) NSMutableArray *reads;

/**
 消息额外字段（源数据，可能是字典，可能是json）
 */
@property (nonatomic, strong) id extra;
/**
 对应extra，模型
 */
@property (nonatomic, strong, readonly) EUCMessageExtraModel *extraDisplay;


#pragma mark - 自定义属性
/**
 临时路径，新文件，小视频，图片发送临时保存路径
 */
@property (nonatomic, copy) NSString *resourcePath;

/**
 是否隐藏消息发送时间
 */
@property (nonatomic, assign) BOOL dateHiden;

/**
 文件在我名下的fileToken
 */
@property (nonatomic, copy) NSString *fileToken;

/**
 新的fileId替换原来的fileToken
 */
@property (nonatomic, copy) NSString *fileId;

/**
 消息发送状态
     发送成功 - EUCMessageSendSuccess
     发送失败 - EUCMessageSendFail
     发送中   - EUCMessageSending
     无网发送 - EUCMessageSendingNeedResend
 */
@property (nonatomic, copy) NSString *sendState;

/**
 语音消息读取状态
     已读取 - EUCMessageVoiceRead
     未读取 - EUCMessageVoiceUnRead
 */
@property (nonatomic, copy) NSString *voiceRead;

/**
 消息来源
 */
@property (nonatomic, assign, readonly) EUCMessageFrom from;

/**
 发送时间展示的字符串
 */
@property (nonatomic, copy) NSString *date_sentStr;

/**
 图片消息生成的占位图片
 */
@property (nonatomic, strong) UIImage *placeholderImage;

/**
 发送者信息模型
 */
@property (nonatomic, strong) EUCUserModel *userModel;

/**
 文件消息专用-下载信息模型
 */
@property (nonatomic, strong) EUCMessageDownLoadModel *downloadModel;

/**
 消息尺寸信息模型
 */
@property (nonatomic, strong) EUCMessageFrameModel *msgFramMode;

/**
 便民属性
 */
@property (nonatomic, assign, getter=selected) BOOL isSelected;

#pragma mark - 需要修改属性
/**
 大搜索时间展示
 */
@property (nonatomic, copy) NSString *searchSend_Date;
/**
 已接受到的用户列表（不一定已读）（暂未使用改字段）
 */
@property (nonatomic, strong) NSMutableArray*   delivered_ids;

/**
 语音是否播放中
 */
@property (nonatomic, assign) BOOL  voiceIsPlaying;

/**
 聊天记录cell高度
 */
@property (nonatomic, assign) CGFloat checkRecordHeight;

/**
 初始化文件消息下载信息
 */
- (void)getFileProgressValueAndLoadState;

/**
 5分钟外收到消息，是否展示时间标签

 @param start 上一个时间
 @param end 本次时间
 @return 本次时间是否展示
 */
- (BOOL)minuteOffSetStart:(NSString *)start end:(NSString *)end;
// 根据 缩略图 计算 视频消息 的 合适尺寸
+ (CGSize)getVideoMessageFitSizeWithThumb:(NSString *)thumb;

@end

#define TEXT_MESG_TYPE         @"txt_msgType"  //key for text message
#define TEXT_MESG_FACE_TYPE    @"facetype"     //key for big emoji type
#define TEXT_MESG_EMOJI_TYPE   @"emojitype"    //key for photo-text message
#define TEXT_MESG_DATA         @"msg_data"     //key for ext data of message

@interface EUCMessageExtraModel : EUCBaseModel

/**
 本地消息唯一标识
 */
@property (nonatomic, copy, readonly) NSString *client_msg_id;
/**
 撤回消息再编辑，原来消息的内容
 */
@property (nonatomic, copy) NSString *reCallMessage;
/**
 撤回消息原来的发送人
 */
@property (nonatomic, copy) NSString *reCallSender;

/**
 中断会议时的成员
 */
@property (nonatomic, strong) NSArray *opponents;

/**
 语音长度
 */
@property (nonatomic, assign, readonly) NSInteger seconds;
/**
 是否lame过 0没有  1有
 */
@property (nonatomic, copy) NSString *isLamed;

/**
 图片宽度
 */
@property (nonatomic, assign, readonly) NSInteger width;

/**
 图片高度
 */
@property (nonatomic, assign, readonly) NSInteger height;

/**
 位置消息经纬度
 */
@property (nonatomic, assign, readonly) double lat;
@property (nonatomic, assign, readonly) double lng;
@property (nonatomic, copy) NSString *address;

/**
 文章标题
 */
@property (nonatomic, copy) NSString *title;

/**
 文章描述
 */
@property (nonatomic, copy) NSString *article_desc;

/**
 文章图片（base64）
 */
@property (nonatomic, copy) NSString *articleImgStr;

/**
 文章图片（url）
 */
@property (nonatomic, copy) NSString *image_url;

/**
 个人名片用户ID
 */
@property (nonatomic, copy) NSString *recommend_user_id;

/**
 个人名片用户头像
 */
@property (nonatomic, copy) NSString *recommend_user_avatar;

/**
 文件名
 */
@property (nonatomic, copy) NSString *name;

/**
 合并的所有消息数据 (解析出来是一个messageModel的数组)
 */
@property (nonatomic, copy) NSString *mergeJsonMessages;
/**
 该消息发送的用户所在会话显示的名字
 */
@property (nonatomic, copy) NSString *senderName;
/**
 该消息发送的用户所在会话显示的头像
 */
@property (nonatomic, copy) NSString *senderAvatar;

/**
 文件类型
 */
@property (nonatomic, copy) NSString *file_type;

/**
 文件大小
 */
@property (nonatomic, assign) long size;

/**
 额外字段，区分文件来源
 */
@property (nonatomic, assign, getter=fromOtherApp) BOOL isFromOtherApp;

/**
 是否为新文件，1，是  0，不是
 */
@property (nonatomic, copy, readonly) NSString *isNewFile;

/**
 文件在发送方名下的fileToken
 */
@property (nonatomic, copy) NSString *fileToken_own;

/**
 文件在接受方名下的fileToken
 */
@property (nonatomic, copy) NSString *fileToken_friend;

/**
 文件缩略图 base64
 */
@property (nonatomic, copy) NSString *thumb;
//thumb用来在我的页面文件列表中显示，cellThumb用来显示chatRoom中cell的缩略图
//区别在于thumb压缩程度更大，cellThumb是原来的压缩程度。
@property (nonatomic, copy) NSString *cellThumb;
/**
 @成员ID集合
 */
@property (nonatomic, strong) NSArray *at_list;

/**
 多媒体消息类型
     1-视频
     2-语音
 */
@property (nonatomic, copy) NSString *call_type;

#pragma mark - BMQQ集成
@property (nonatomic, copy) NSString *txt_msgType;
@property (nonatomic) id msg_data;
@property (nonatomic, strong) NSArray *msgData_list;

/**
 消息撤回-原消息发送时间
 */
@property (nonatomic, strong) NSNumber *sendDate;

/**
 文件是否失效
     NO-没有失效 默认
     YES-失效
 */
@property (nonatomic, assign) BOOL fileInValid;

/**
 文件上传进度
 */
@property (nonatomic, assign) CGFloat uploadProgress;

#pragma mark - 可以舍弃字段
/**
 文件原发送人ID
 */
@property (nonatomic, copy) NSString *fileSender;

/**
 文件在原发送人名下的fileToken
 */
@property (nonatomic, copy) NSString *fileSenderToken;

@end

@interface EUCMessageDownLoadModel : EUCBaseModel

/** 对文件下载时的,下载状态,默认暂未下载*/
@property (nonatomic, assign) EUCDownloadStateType loadStateType;

/** 文件下载的当前进度*/
@property (nonatomic, assign) CGFloat progressValue;

@end


@interface EUCMessageFrameModel : EUCBaseModel

/**
 消息发送人名称frame
 */
@property (nonatomic, assign) CGRect nameF;

/**
 消息发送人头像frame
 */
@property (nonatomic, assign) CGRect iconF;

/**
 消息发送时间frame
 */
@property (nonatomic, assign) CGRect timeF;

/**
 气泡frame
 */
@property (nonatomic, assign) CGRect contentF;

/**
 加载，重发frame
 */
@property (nonatomic, assign) CGRect indicatorF;

/**
 已读未读frame
 */
@property (nonatomic, assign) CGRect readTagF;

/**
 cell高度
 */
@property (nonatomic, assign) CGFloat cellHeight;

@end
