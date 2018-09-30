//
//  NetWorkParam.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/30.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetWorkParam : NSObject


/**
 参数转换

 @param param 参数
 @param url 域名
 @return 参数拼接结果
 */
+ (NSMutableDictionary *)transitParams:(NSDictionary*)param tmpURL:(NSString*)url;

@end
