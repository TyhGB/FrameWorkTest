//
//  EUCUserMode.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/1/2.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EUCBaseModel.h"
#import "EUCStyleDefine.h"

/**
 收取会话信息状态
 */
typedef NS_ENUM(NSUInteger, EUCDialogsValidityType) {
    /** 未知 */
    EUCDialogsValidityTypeUnkown,
    /** 收取中... */
    EUCDialogsValidityTypeIng,
    /** 收取失败 */
    EUCDialogsValidityTypeFaile,
    /** 收取完成 */
    EUCDialogsValidityTypeFinish
};

typedef NS_ENUM(NSInteger, EUCMemberCellStyle) {
    EUCMemberCellStyleNormal, // 正常模式
    EUCMemberCellStyleEdit    // 编辑模式
};

typedef NS_ENUM(NSInteger, EUCUserModelSelectedState) {
    EUCUserModelSelectedStateUnselected,   // 没有选中
    EUCUserModelSelectedStateSelected,     // 选中
    EUCUserModelSelectedStateUnenable      // 不可选
};


@interface EUCUserModel : EUCBaseModel

// 配合会话用户信息数据
// 该用户所在的会话ID
@property (nonatomic, copy) NSString *dialogID;
// 该用户所在群昵称
@property (nonatomic, copy) NSString *nick_name;

// 这个ID就是user_id
@property (nonatomic, copy) NSString* ID;

@property (nonatomic, copy) NSString* application_id;
// Email
@property (nonatomic, copy) NSString* email;
// 姓名(昵称) 接口改了可能会有问题 比如修改用户名称的时候传值是fullName不再是full_name
@property (nonatomic, copy) NSString* full_name;
// 群组显示的名字
@property (nonatomic, copy) NSString *groupName;
// 用于显示
@property (nonatomic, copy) NSString* info_full_name;
// 是否有IMS权限
@property (nonatomic, assign) BOOL isIMS;

// 用于大搜索显示
@property (nonatomic, copy) NSString *searResult;
@property (nonatomic, copy) NSString *searchKey;
@property (nonatomic, copy) NSString *nick_nameSTR;

// 新的朋友搜索显示
@property (nonatomic, copy) NSString *desText;
// 登录账号
@property (nonatomic, copy) NSString* login;
// 密码（HMAC加密）
@property (nonatomic, copy) NSString* password;

@property (nonatomic, copy) NSString* created_at;
// 最后一次请求时间
@property (nonatomic, copy) NSString* last_request_at;
// 更新时间
@property (nonatomic, copy) NSString* updated_at;
// 头像url地址
@property (nonatomic, copy) NSString* avatar;
// 头像 自定义属性
@property (nonatomic, strong) UIImage* avatar_TMP;
@property (nonatomic, strong) UIImage* avatar_Dis;

// 电话
@property (nonatomic, copy) NSString* phone;
// 性别
@property (nonatomic, copy) NSString *gender;
// 个人简介
@property (nonatomic, copy) NSString *about;
// 地区
@property (nonatomic, copy) NSString *region;
// 座机
@property (nonatomic, copy) NSString* office_phone;
// 用户标签
@property (nonatomic, strong) NSArray* user_tags;
// SIP账号地址
@property (nonatomic, copy) NSString* sip_account;
// 置顶会话ID列表
@property (nonatomic, strong) NSMutableArray* top_dialogs;

/**
 置顶失败的 (由置顶转成非置顶状态失败的所有集合) (自定义)
 */
@property (nonatomic, strong, readonly) NSMutableArray* top_failure_dialogs;
/**
 取消置顶失败 (由非置顶转成置顶状态失败的所有集合) (自定义)
 */
@property (nonatomic, strong, readonly) NSMutableArray* failure_top_dialogs;

// 消息免打扰ID列表
@property (nonatomic, strong) NSMutableArray *mute_notifications;
// 名字的拼音（后台自动生成，以空格分隔）
@property (nonatomic, copy) NSString* full_name_pinyin;
// 消息里显示的名字 优先级：备注名/昵称名/全名
- (void)showNameWithDialogID:(NSString *)dialogID nameBlock:(void (^)(NSString *nama))nameBlock;

// 可能是数组,也有可能是字符串
@property (nonatomic, strong) id hidden_dialogs;
@property (nonatomic, strong, readonly) NSMutableArray* hiddenDialogs;

@property (nonatomic, strong) NSMutableArray* hidden_custom_dialogs;

/**
 判断是否在删除/影藏序列中
 */
- (BOOL)containsHindenDialogID:(NSString*)dialogID;

/**
 在删除/影藏序列中删除
 */
- (BOOL)removeHindenDialogIDs:(NSArray*)dialogIDs;


/**
 是否处于置顶状态
 */
- (BOOL)containsTopDialogID:(NSString*)dialogID;

/**
 所有置顶的会话
 */
- (NSMutableArray*)allTopDialog;

// 选择状态
@property (nonatomic, assign) EUCUserModelSelectedState selectedState;
@property (nonatomic, assign) EUCMemberCellStyle cellStyle;
@property (nonatomic, assign, getter=imsSelected) BOOL isImsSelected;

/**
 备注
 */
@property (nonatomic, copy) NSString* memo;

@property (nonatomic, copy) NSString *we_id;
// 注册的时候,会在用户信息中返回当前注册用户的token
@property (nonatomic, copy) NSString* token;

@property (assign, nonatomic) BOOL isPhoneCompare;


/* 0无申请，1是本用户申请了对方，2是对方申请了本用户，3位双方互相申请显示接受
 */
@property (nonatomic, copy) NSString *friendRequestStatus;
@property (assign, nonatomic) BOOL isFriend;

/* 好友状态
 * 0非好友，1好友，2被好友申请中 3对好友申请中 4黑名单
 */
@property (nonatomic, copy) NSString *friendStatus;


/** 用户是否打开了指纹识别 */
@property (nonatomic, assign) BOOL fingerprintStatus;

/** 用户是否打开了手势识别 */
@property (nonatomic, assign) BOOL gesturePwdStatus;

/** 用户手势密码是否可见 */
@property (nonatomic, assign) BOOL gesturePwdVisibleStatus;

/** 是否因验证失败导致退出 */
@property (nonatomic, assign) BOOL logOutByVerifyFailed;

/** 用户关闭了系统指纹 */
@property (nonatomic, assign) BOOL userTurnOffSystemFingerprint;

/** 用户是否跳转到了设置 */
@property (nonatomic, assign) BOOL jumpToSettings;

/** 用户的手势密码 */
@property (nonatomic, copy) NSString *gesturePwd;

/** 会话信息的有效性
 YES: 登录成功之后正确的拉取了历史消息
 NO:  登录成功之后没有正确的拉取历史消息, 需要
 */
@property (nonatomic, assign) EUCDialogsValidityType dialogsValidityType;


@end
