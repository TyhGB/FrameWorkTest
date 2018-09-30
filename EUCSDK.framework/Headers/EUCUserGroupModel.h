//
//  EUCUserGroupModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/7/9.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCUserGroupModel : EUCBaseModel

@property (nonatomic, copy) NSString* firstCharacter;

@property (nonatomic, strong) NSMutableArray* users;

@end
