//
//  EUCUUIDString.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/9/26.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

/**
 * 自定义的 UUIDString , 来自港行
 */

#import <Foundation/Foundation.h>

@interface EUCUUIDString : NSObject


/**
 随机的一串字符串 除非删包重装会改变

 @return 返回随机的一串字符串
 */
+ (NSString*)UUIDString;

// 随机生成的
+ (NSString*)randomString;

@end
