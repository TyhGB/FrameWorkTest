//
//  EUCDialogModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2016/12/26.
//  Copyright © 2016年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"
#import "EUCUserModel.h"

@interface EUCDialogModel : NSObject

@property (nonatomic, copy) NSString* limit;
@property (nonatomic, copy) NSString* skip;

//会话列表
@property (nonatomic, strong) NSMutableArray* dialogs;

@end





@interface EUCDialogItemModel : EUCBaseModel
//该会话的聊天记录
@property (nonatomic, strong) NSMutableArray* messageList;

@property (nonatomic, copy) NSString* v;

@property (nonatomic, copy) NSString* ID;
//会话类型 1(公共会话, 暂未使用), 2(多人会话), 3(私人会话)
@property (nonatomic, copy) NSString* type;
//创建时间
@property (nonatomic, copy) NSString* created_at;
//更新时间
@property (nonatomic, copy) NSString* updated_at;
//Application ID
@property (nonatomic, copy) NSString* application_id;
//创建者ID
@property (nonatomic, copy) NSString* user_id;
//参与者的ID列表（包括创建者）
@property (nonatomic, strong) NSMutableArray* occupants_ids;
// 是否是自定义群名称
@property (nonatomic, assign) BOOL isCustomName;
// 参与者信息集合
// 此字段慎用，用到请找XLL
@property (nonatomic, strong) NSMutableArray *occupants;

//最后一条发送消息的用户ID
@property (nonatomic, copy) NSString* last_message_user_id;
//最后一条消息发送时间
@property (nonatomic, copy) NSString* last_message_date_sent;

//不知道为什么这个值是readonly 我已去掉
@property (nonatomic, copy) NSString* last_message_date_sentDisplay;
//最后一条消息内容
@property (nonatomic, copy) NSString* last_message;

// 最后一条消息的ID 主要用于去重
@property (nonatomic, copy) NSString* last_message_ID;

//会话的名字
@property (nonatomic, copy) NSString* name;
// 会话名字的拼音（后台自动生成）
@property (nonatomic, copy) NSString* name_pinyin;
//会话的头像URL
@property (nonatomic, copy) NSString* photo;

#pragma mark - 自定义
@property (nonatomic, strong) UIImage* photo_TMP;

@property (nonatomic, assign) BOOL isShow;
@property (nonatomic, strong) EUCUserModel *showUserModel;
@property (nonatomic, copy) NSString *searchResult;
@property (nonatomic, copy) NSString *searchKey;
#pragma mark - 
// 是否置顶
@property (nonatomic, assign) BOOL top;
// 是否免打扰
@property (nonatomic, assign) BOOL isMute;
// 未读数
@property (nonatomic, copy) NSString* unReadCount;
@property (nonatomic, copy) NSString* unReadText;

// 更新用户信息
//- (void)updateDialogUserInfo;

/**
 key是user_id
 value是对应的用户信息
 */
@property (nonatomic, strong, readonly) NSMutableDictionary* userInfoDictM;

// 是否显示顶部的线
@property (nonatomic, assign) BOOL topLineDisplay;

// 是否有人at我
@property (nonatomic, assign) BOOL isSomeoneAtMe;
// 是否是自定义群名称
//@property (nonatomic, assign) BOOL isCustomName;

// 是否顶头显示
@property (nonatomic, assign) BOOL bottomLineDisplayImmediate;

@property (nonatomic, strong, readonly) EUCUserModel* groupMasterMode;

//转发时编辑状态是否被选中
@property (nonatomic, assign, getter=selected) BOOL isSelected;

// 大搜索用
//@property (nonatomic, strong) EUCDialogNickModel *nickModel;
//@property (nonatomic, strong) NSArray *memberArr;
@end
