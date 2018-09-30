//
//  EUCNickNameSingleton.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/7/13.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EUCDialogNickModel;
@interface EUCNickNameSingleton : NSObject

+ (instancetype)sharedInstance;


@property (nonatomic, strong, readonly) NSMutableArray <EUCDialogNickModel *>*nickListArray;
// 从数据库获取数据
- (BOOL)configData;


/**
 根据单例进行判断

 @param nickModel 昵称模型
 */
- (void)updateOrInsertNickNameData:(EUCDialogNickModel *)nickModel;

// 清空数据
- (void)clearData;

@end
