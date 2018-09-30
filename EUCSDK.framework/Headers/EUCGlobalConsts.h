//
//  EUCGlobalConsts.h
//  EUCSDK
//
//  Created by 肖乐 on 2018/2/27.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 空值判断
static inline BOOL IsEmptyValue(id _Nullable thing) {
    return (thing == nil)
    || ([thing respondsToSelector:@selector(length)]
        && [(NSData *) thing length] == 0)
    || ([thing respondsToSelector:@selector(count)]
        && [(NSArray *) thing count] == 0)
    || ([thing isKindOfClass:[NSNull class]]);
}

/** 对字符串的特殊处理,如果为空,则统一返回@"",否则原形 */
static inline NSString* checkValue (NSString* value) {
    if (IsEmptyValue(value)) {
        return @"";
    }
    return value;
}

// 为空, 返回nil 针对NSString
static inline NSString *_Nullable checkValueNil(NSString *_Nullable value) {
    if (IsEmptyValue(value)) {
        return nil;
    }
    return value;
}

// .h 文件中用到的宏
#define Single_interface(class)  + (instancetype)sharedSingleton;

// .m 文件中用到的宏
#define Single_implementation(class) \
static class *_instance; \
\
+ (instancetype)sharedSingleton \
{ \
if (_instance == nil) { \
_instance = [[self alloc] init]; \
} \
return _instance; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
}

// 打印日志
#ifdef DEBUG
#   define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define ELog(err) {if(err) DLog(@"%@", err)}
#else
#   define DLog(...)
#   define ELog(err)
#endif

// 强弱指针转换
#ifndef    weakify_self
#define weakify_self __weak typeof(self) weakSelf = self
#endif
#ifndef    strongify_self
#define strongify_self __typeof__(weakSelf) self = weakSelf
#endif

// 快速创建字符串的宏定义
#define EUCStr(...) [NSString stringWithFormat:__VA_ARGS__]
#define EUCFont(size) [UIFont systemFontOfSize:(size)]
#define EUCBFont(size) [UIFont boldSystemFontOfSize:(size)]
#define EUCCGM(X, Y, W, H) CGRectMake((X), (Y), (W), (H))

// 颜色
#define RGBA(R, G, B, A) [UIColor colorWithRed:(R)/255.0f green:(G)/255.0f blue:(B)/255.0f alpha:(A)]
#define RGB(R, G, B) RGBA(R, G, B, 1.0)
// 随机色
#define RandomColor RGB(arc4random()%255, arc4random()%255, arc4random()%255)

/** 通知宏 */
#define OKANotificationCenter [NSNotificationCenter defaultCenter]
#define OKAUserDefaults [NSUserDefaults standardUserDefaults]

// 版本
//#define IOS10 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define IOS10 @available(iOS 10.0, *)

//当前用户id和对应的数据库
#define EUCCurrentUser EUCStr(@"EUCCurrentUser_%@", [EUCIMClient sharedEUCIMClient].user_id)
#define EUCUserDataBaseName (EUCStr(@"DB_%@.db",[EUCIMClient sharedEUCIMClient].user_id))
/** 未读数改变 */
UIKIT_EXTERN NSString *const EUCBadgeValueChangeNotification;
// token过期通知
UIKIT_EXTERN NSString *const EUCTokenOutDateNotification;
/** socket状态改变通知 */
UIKIT_EXTERN NSString *const EUCSocketStatusNotification;
/** 被顶通知 */
UIKIT_EXTERN NSString *const EUCUserDisconnectNotification;
/** 语音通话内部超时通知 */
UIKIT_EXTERN NSString *const EUCAudioTimeOutNotification;
/** 视频通话内部超时通知 */
UIKIT_EXTERN NSString *const EUCVideoTimeOutNotification;
/** 好友申请 */
UIKIT_EXTERN NSString *const EUCDidNtfFriendNotification;
UIKIT_EXTERN NSString *const EUCDidNtfFriendKey;
/* 非好友关系 */
UIKIT_EXTERN NSString *const EUCUserModeFriendTypeNoFriend;
/* 好友关系 */
UIKIT_EXTERN NSString *const EUCUserModeFriendTypeRealFriend;
/* 被好友申请中 */
UIKIT_EXTERN NSString *const EUCUserModeFriendTypeFriendRequest;
/* 对好友申请中 */
UIKIT_EXTERN NSString *const EUCUserModeFriendTypeFriendSelfRequest;
/* 黑名单 */
UIKIT_EXTERN NSString *const EUCUserModeFriendTypeBlicklist;
/** 好友信息更新 */
UIKIT_EXTERN NSString *const EUCUpdateFriendInfoNotification;
/** 未读数获取成功 */
UIKIT_EXTERN NSString *const EUCUnreadFriendInfoNotification;
/** 共享缓存路径 */
UIKIT_EXTERN NSString *const EUCGroupDefaultsName;
/** 登录关键字 */
UIKIT_EXTERN NSString *const EUCLoginUserIDKey;
/** LKIMid关键字 */
UIKIT_EXTERN NSString *const LKIMUserID;
/** deviceToken关键字 */
UIKIT_EXTERN NSString *const EUCDeviceTokenKey;
///** socketl连接失败 请用户重新获取paasToken 并存储 再重连*/
//UIKIT_EXTERN NSString *const EUCSocketeConnectedFail;
/** 收到视频会议本地影像通知 */
UIKIT_EXTERN NSString *const EUCLocalTrackNotification;
/** 收到MCU视频会议本地影像通知*/
UIKIT_EXTERN NSString *const EUCMCULocalTrackNotification;
/** 收到视频会议远程影像通知 */
UIKIT_EXTERN NSString *const EUCRemoteTrackNotification;
/** 收到MCU视频会议远程影像通知 */
UIKIT_EXTERN NSString *const EUCMCURemoteTrackNotification;
// 会话群通知
UIKIT_EXTERN NSString *const EUCGroupBroadcastNotification;
// 群昵称表插入线程
UIKIT_EXTERN char *const EUCDialogNickInsertQueue;
//手机通讯录联系人表插入线程
UIKIT_EXTERN char *const EUCAddressBookContactListQueue;
//好友单例处理队列
UIKIT_EXTERN char *const EUCFriendDateBaseSingletonQueue;
//黑名单插入线程
UIKIT_EXTERN char *const EUCBlicklistListQueue;
//时间格式串
UIKIT_EXTERN NSString *const EUCDateFormatString;
/** 下载好的语音消息名字 */
UIKIT_EXTERN NSString *const EUCVoiceMessageName;
/** 小视频消息名字 */
UIKIT_EXTERN NSString *const EUCVideoMessageName;

/** 草稿箱前缀*/
UIKIT_EXTERN NSString *const EUCDraftsPrefix_IOS;
/** 消息发送失败前缀*/
UIKIT_EXTERN NSString *const EUCMessageSendFailure_IOS;
/** 消息发送中前缀*/
UIKIT_EXTERN NSString *const EUCMessageSending_IOS;
/** 更新最后一条消息通知 */
UIKIT_EXTERN NSNotificationName const EUCUpdateDialogMessageNotification;
/** 会话同步完成通知 */
UIKIT_EXTERN NSNotificationName const EUCDialogSyncNotification;
/** 消息收取状态 */
UIKIT_EXTERN NSString *const EUCDialogsValidityNotification;
// 接收消息通知
UIKIT_EXTERN NSNotificationName const EUCDidReceivedMessageNotification;
// 接收已读通知
UIKIT_EXTERN NSNotificationName const EUCDidReceivedReadNotification;

/** 消息收藏单页请求量 */
UIKIT_EXTERN NSInteger const EUCFavoritesPageSize;

/** 视频消息竖屏时宽度 */
UIKIT_EXTERN CGFloat EUCVideoMessageVerticalWidth;
/** 视频消息横屏时高度 */
UIKIT_EXTERN CGFloat EUCVideoMessageHorizontalHeight;
/** 视频消息竖屏时最大高度 */
UIKIT_EXTERN CGFloat EUCMessageVerticalMaxHeight;
/** 视频消息横屏时最大宽度 */
UIKIT_EXTERN CGFloat EUCMessageHorizontalMaxWidth;

/** 消息表插入线程 */
UIKIT_EXTERN char *const EUCMessageInsertQueue;
/** 消息表查询线程 */
UIKIT_EXTERN char *const EUCMessageListQueue;
/** 消息表更新线程 */
UIKIT_EXTERN char *const EUCMessageUpdateQueue;
/** 消息表删除线程 */
UIKIT_EXTERN char *const EUCMessageDeleteQueue;
/** 接收到消息关键字 */
UIKIT_EXTERN NSString *const EUCDidSendOrReceivedMessageKey;

/** 为文件插入属性发送时间key */
UIKIT_EXTERN NSString *const EUCFileAttributeSendDateKey;
/** 为文件插入属性发送者key */
UIKIT_EXTERN NSString *const EUCFileAttributeSenderKey;
/** 文件发送所在的会话ID */
UIKIT_EXTERN NSString *const EUCFileAttributeFileDialogKey;
/** 为文件下载链接插入属性 */
UIKIT_EXTERN NSString *const EUCFileAttributeFileUrlKey;
/** 文件在自己seafile云下的key */
UIKIT_EXTERN NSString *const EUCFileAttributeFileTokenOwnKey;
/** 文件发送者seafile云下的key */
UIKIT_EXTERN NSString *const EUCFileAttributeFileTokenFriendKey;

/** 获取手机通讯录数量 */
UIKIT_EXTERN NSString* const EUCFetchABContactCountNotification;
/** 修改自己的名字 */
UIKIT_EXTERN NSString *const EUCUpateMySelfNameNotification;
// 删除好友-隐藏好友对话列表需要刷新
UIKIT_EXTERN NSString *const EUCDeleteFriendHiddenChatNotification;
/**二维码相关的一个地址*/
UIKIT_EXTERN NSString *const EUCQRCodeWebLoginURLTip;

/** 匹配 URL 的正则表达式 */
UIKIT_EXTERN NSString *const EUCUrlRegularStr;

/** 匹配 email 的正则表达式 */
UIKIT_EXTERN NSString *const EUCEmailRegularStr;

/** 点击menuView对表情面板通知 */
UIKIT_EXTERN NSString *const EUCMenuViewToEmojiPadNotification;
/** 滑动表情面板堆menuView通知 */
UIKIT_EXTERN NSString *const EUCEmojiPadToMenuViewNotification;

// 文件上传进度通知
UIKIT_EXTERN NSString *const EUCUploadProgressNotification;
// 文件上传失败通知
UIKIT_EXTERN NSString *const EUCUploadFailureNotification;
// 文件上传完成通知
UIKIT_EXTERN NSString *const EUCUploadSuccessNotification;
/** 收藏删除通知 */
UIKIT_EXTERN NSString *const EUCDeleteFavoriteNotification;
/** 历史消息同步通知 */
UIKIT_EXTERN NSString *const EUCHistoryMessageSyncNotification;
/** 自己修改本群昵称修改成功通知 */
UIKIT_EXTERN NSString *const EUCUpateNickGroupNameNotification;
/** 群昵称修改成功通知 */
UIKIT_EXTERN NSString *const EUCUpateDialogNameNotification;
/** 音视频,对方挂断通知 */
UIKIT_EXTERN NSString *const EUCHungupNotification;
/** 开启语音会议通知 */
UIKIT_EXTERN NSString *const EUCStartAudioNotification;
/** 消息撤回通知 */
UIKIT_EXTERN NSString *const EUCMessageWithdrewNotification;

@interface EUCGlobalConsts : NSObject

/** 是否为 iPad 设备 */
+ (BOOL)userInterfaceIdiomiPad;

/** 服务器地址 */
+ (NSString *)netWorkServiceAddress;

/** 验证码地址 */
+ (NSString *)verificationCodeAddress;

/** 文件地址 */
+ (NSString*)filekServiceAddress;

/** socket */
+ (NSString *)socketServerPath;

/**
 获取时间戳
 */
+ (NSString *)getTimestamp;
@end

NS_ASSUME_NONNULL_END
