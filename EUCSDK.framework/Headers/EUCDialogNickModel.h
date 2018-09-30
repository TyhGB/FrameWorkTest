//
//  EUCDialogNickModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/7/5.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCDialogNickModel : EUCBaseModel

// 会话ID
@property (nonatomic, copy) NSString *dialogID;
// 用户ID
@property (nonatomic, copy) NSString *userID;
// 用户昵称
@property (nonatomic, copy) NSString *nick_name;

@end
