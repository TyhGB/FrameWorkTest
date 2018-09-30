//
//  EUCDBQueue.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/3/29.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDB.h"
@interface EUCDBQueue : NSObject

+ (instancetype)shareInstance;

@property (nonatomic, strong, readonly) FMDatabaseQueue *dbQueue;

- (void)setDataBaseName:(NSString *)baseName;

@end
