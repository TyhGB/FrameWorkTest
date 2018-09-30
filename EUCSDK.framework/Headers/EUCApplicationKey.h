//
//  EUCApplicationKey.h
//  EUCSDK
//
//  Created by 肖乐 on 2018/3/6.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//  应用ID 代替applicationID

#import <Foundation/Foundation.h>

@interface EUCApplicationKey : NSObject


/**
 初始化应用ID管理类

 @return 应用ID管理对象
 */
+ (instancetype)sharedApplication;


/**
 应用ID
 */
@property (nonatomic, copy) NSString *applicationID;

@end
