//
//  FMDBHelper+corvertJSONString.h
//  Pods
//
//  Created by ShaoShanPeng on 2017/2/20.
//
//

#import <Foundation/Foundation.h>

@interface ConvertJSONString :NSObject


/** 将json字符串转换为数组或字典 */
+ (id)convertJsonStringToObject:(id)object;

/** 将字典转换成json */
+ (id)convertObjectToJsonString:(id)object;

@end
