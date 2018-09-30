//
//  EUCFindFriendModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/6/9.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//  好友申请数据总模型

#import "EUCBaseModel.h"
#import "EUCUserModel.h"

@interface EUCFindFriendModel : EUCBaseModel

@property (nonatomic, strong) NSArray* friendRequestDatas;

@property (nonatomic, copy) NSString* current_page;
@property (nonatomic, strong) NSNumber* per_page;
@property (nonatomic, strong) NSNumber* total_entries;

@end

// 好友申请数据模型
@interface EUCFriendRequestModel : EUCBaseModel

/**
 申请人信息
 */
@property (nonatomic, strong) EUCUserModel *applicantUser;

/**
 被申请人信息
 */
@property (nonatomic, strong) EUCUserModel* user;

/**
 申请信息
 */
@property (nonatomic, copy) NSString* desTEXT;

/**
 申请记录id
 */
@property (nonatomic, copy) NSString* ID;

/** 广播消息的时候用到
 操作，validate等待验证，consent接受, refuse拒绝，Recommendation 好友推荐
 opration：validate 则user = null
 opration：consent|refuse 则applicantUser = null
 opration：Recommendation 则user为推荐人信息
 */
@property (nonatomic, copy) NSString* opration;

#pragma mark - 自定义属性
/* 是否是别人申请我-yes别人申请我，no我申请别人 */
@property (assign, nonatomic, readonly) BOOL othersRequest;

/** 是否浏览过
 0 : 没有浏览过
 1 : 已经浏览过
 */
@property (nonatomic, copy) NSString* brower;

/**此条数据放在数据库中的最新时间
 * 为了重新运行之后，数据库数据排序显示展示好友申请 
 */
@property (nonatomic, copy) NSString* saveTime;



@end
