//
//  NSString+Regex.h
//  CategoryManager
//
//  Created by  ZhuHong on 2017/4/8.
//  Copyright © 2017年 OKA_APP. All rights reserved.
//



#import <Foundation/Foundation.h>

// 基本匹配 : 数字, 汉字, 字符, 空格, 下划线, 点
typedef NS_OPTIONS(NSUInteger, OKARegexType) {
    OKARegexTypeNone      = 0 << 0, // 未知
    OKARegexTypeDigital   = 1 << 0, // 数字
    OKARegexTypeChinese   = 1 << 1, // 汉字
    OKARegexTypeCharacter = 1 << 2, // 字符
    OKARegexTypeSpace     = 1 << 3, // 空格
    OKARegexTypeUnderline = 1 << 4, // 下划线
    OKARegexTypeDot       = 1 << 5, // 点
    OKARegexTypeAT        = 1 << 6, // @
};

// 是否支持空字符串

@interface NSString (OKARegex)

/**
 * 通过 pattern 进行匹配
 */
- (BOOL)oka_regexMatchWithPattern:(NSString*)pattern;

/**
 * 基本匹配: 默认支持空字符串返回为YES的情况
 */
- (BOOL)oka_regexMatchWithType:(OKARegexType)rType;

/**
 * 基本匹配: 是否支持空字符串返回为YES的情况
 */
- (BOOL)oka_regexMatchWithType:(OKARegexType)rType returnWhenEmpty:(BOOL)empty;

/**
 * 基本匹配: 默认支持空字符串返回为YES的情况
 * 最大限制为 maxLimit 位
 */
- (BOOL)oka_regexMatchWithType:(OKARegexType)rType
                maxLimitLength:(NSUInteger)maxLimit;

/**
 * 基本匹配: 是否支持空字符串返回为YES的情况
 * 最大限制为 maxLimit 位
 */
- (BOOL)oka_regexMatchWithType:(OKARegexType)rType maxLimitLength:(NSUInteger)maxLimit returnWhenEmpty:(BOOL)empty ;


- (NSString*)oka_replaceStringInPattern:(NSString *)pattern withString:(NSString*)toString;

@end
