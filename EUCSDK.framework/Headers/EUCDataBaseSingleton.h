//
//  EUCDataBaseSingleton.h
//  EUCIMManager
//
//  Created by sunqy on 2017/6/12.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EUCPhoneAddressBookContactModel.h"
#import "EUCFindFriendModel.h"

typedef void (^FriensBlock)(NSMutableArray* friens);

@interface EUCDataBaseSingleton : NSObject

#pragma mark - 初始化
+ (instancetype)shareSingleton;

#pragma mark -
#pragma mark - 初始化数据

/**
 获取注册用户
 
 @param friensBlock 回传
 */
- (void)configDataWithBlock:(FriensBlock)friensBlock;

#pragma mark -
#pragma mark - 清空数据
- (void)clearData;

#pragma mark - proprety
/** 所有搜集到的已注册用户 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCUserModel *> *allUserArrM;

/** 真正的好友数据 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCUserModel *> *realFriendArrM;

/** 好友请求数据 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCFriendRequestModel *> *friendRequestArrM;

/** 未读数据 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCFriendRequestModel *>* unreadRequestArrM;

/** 黑名单 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCUserModel *> *blicklistArrM;

/** 通讯录数据 */
@property (nonatomic, strong, readonly) NSMutableArray<EUCPhoneAddressBookContactModel *> *abContactArrM;

/** 以首字母为key的字典 */
@property (nonatomic, strong, readonly) NSMutableDictionary <NSString *, NSMutableArray <EUCPhoneAddressBookContactModel *>*>* abContactDictM;


#pragma mark -
#pragma mark - 更新表
/** 更新真正好友表
 *  realFriendArr-真正好友信息数组
 */
- (BOOL)updateRealFriendTableWithArrM:(NSMutableArray<EUCUserModel *> *)realFriendArrM;

/* 删除某个好友处理
 */
- (void)deleteRealFriendWithUserModel:(EUCUserModel *)userModel;

/** 更新手机通讯录表
 *  abContactArr-手机通讯录信息数组
 */
- (void)updateABContactTableWithArrM:(NSMutableArray<EUCPhoneAddressBookContactModel *> *)abContactArrM;

/** 更新本地好友申请的请求语
 *  friendRequestModel-好友申请模型
 */
- (void)updateLocalDesTextForFriendRequestModel:(EUCFriendRequestModel *) friendRequestModel;

/** 更新本地好友申请的已读未读状态
 *  friendRequestModel-好友申请模型
 */
- (void)updateLocalReadStatuesForFriendRequestModel:(EUCFriendRequestModel *) friendRequestModel;

#pragma mark - Event
/**好友申请广播过来调用
 * friendRequsteArr-好友申请数组
 */
- (void)friendRequstePushAnswerWithFriendRequestModel:(NSArray <EUCFriendRequestModel *> *)friendRequsteArrM;


/** 更新某个好友信息
 *  userModel-好友信息模型
 *  friendStatus-好友关系，
 *  0非好友，1好友，2好友申请中，3黑名单.若传入nil则说明好友状态不改变
 */
- (BOOL)updateOnefriendWithUserModel:(EUCUserModel *)userModel friendStatus:(NSString *)friendStatus;


#pragma mark -
#pragma mark - 根据字段查询信息
/** 根据id返回对应用户信息
 *  若单例及数据库中均无此信息，则返回nil，在外部做判空，为空则网络请求
 */
- (EUCUserModel *)userModelWithID:(NSString *)ID;

///** 根据手机号码返回对应用户信息
// *  若属于好友则返回EUCUserModel，若属于通讯录则返回EUCPhoneAddressBookContactModel
// *  若单例及数据库中均无此信息，则返回nil，在外部做判空，为空则网络请求
// */
//- (id)userModelWithPhone:(NSString *)phone;

/** 返回本地和最新下发消息中的备注字段，以检测是否需要更新
 *  若两者备注相同／下发信息中备注较新，则返回nil，代表使用下发覆盖本地
 */
- (NSString *)memoForLocalCompareNewWithUserModel:(EUCUserModel *)userModel;

/** 添加好友页面search根据phone搜索本地好友数据
 *  因为是模糊查询，所以返回为数组
 *  因为可能为通讯录数据可能为单纯用户信息，所以需外部判断类型展示
 *  EUCPhoneAddressBookContactModel-手机通讯录模型，只区分是否为好友
 *  EUCUserModel-用户模型
 *  若返回为数组长度为0或nil则说明本地无此phone对应好友数据，需外部判空
 */
- (NSArray *)addFriendPageSearchWithPhone:(NSString *)phone;


/* 搜索页面根据用户模型获取相关好友申请
 */
- (EUCFriendRequestModel *)friendRequestWithUserModel:(EUCUserModel *)userModel;

/**
 从通讯录中查询是否有这个手机号码
 
 @param phone 所要查询的手机号码
 */
- (BOOL)findAddressBookWithPhone:(NSString*)phone;

@end
