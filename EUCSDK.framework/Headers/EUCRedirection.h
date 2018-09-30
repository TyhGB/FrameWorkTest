//
//  EUCRedirection.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/20.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCRedirection : NSObject

// 初始化单例对象
+ (instancetype)shareInstanced;

- (void)getRedirectionUrl:(NSString *)originUrl Completion:(void(^)(NSString *realUrl, NSError *error))completion;

@end
