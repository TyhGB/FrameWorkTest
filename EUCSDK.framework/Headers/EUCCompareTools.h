//
//  EUCCompareTools.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/11/27.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCCompareTools : NSObject

/**
 仅仅是对日期的标胶
 */
+ (NSComparisonResult)compareToolsWithOne:(NSString*)one two:(NSString*)two;

@end
