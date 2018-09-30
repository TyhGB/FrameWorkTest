//
//  EUCFriendModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/6/14.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"
#import "EUCUserModel.h"

@interface EUCFriendModel : EUCBaseModel

@property (nonatomic, copy) NSString* current_page;
@property (nonatomic, copy) NSString* per_page;
@property (nonatomic, copy) NSString* total_entries;
/**
 好友信息列表集合
 */
@property (nonatomic, strong) NSMutableArray <EUCUserModel *>*friendSchemas;

//@property (nonatomic, strong, readonly) NSMutableArray* groupUsers;
//
///** 全部更新 */
//- (void)updateAllGroupUsers;
//
///**
// 通过 userModel 部分更新 可能是增加, 也有可能是移除
// */
//- (void)updateGroupUsersWithUserModel:(EUCUserModel*)userModel;
@end
