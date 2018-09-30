//
//  NSString+EUC.h
//  EUCSDK
//
//  Created by 肖乐 on 2018/2/27.
//  Copyright © 2018年 IMMoveMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (EUC)

// 默认头像
- (UIImage*)name2Image;

// NSString 转 UIColor
- (UIColor *)rgbColor;
// 将文件大小转成字符串
+ (NSString *)transformedValue:(NSNumber *)value;
// 判断字符串中是否有中文(下载的URL是否需要转码)
+ (BOOL)IsHaveChinese:(NSString *)urlStr;
// 转成mp3
- (NSString *)lameToMP3;

/** 计算字符串的高度 */
- (CGSize)btStringWithFont:(UIFont*)font width:(CGFloat)width height:(CGFloat)height;


/////* 中文转化为拼音 */
//- (NSString *)EUC_pinyin;

/**
 排序是否为a-z/A-Z,否返回 #
 */
- (NSString *)exchangeAToZ;
/**
 是否纯空格
 */
- (BOOL)isAllSpace;

- (NSString *)removeFromString:(NSString *)removeStr;
/**
 *  计算当前文件\文件夹的内容大小
 */
- (NSInteger)fileSize;

// 删除沙盒里的文件
-(void)deleteFile;

//判断是不是手机号
+ (BOOL)valiMobile:(NSString *)mobile;

// 所有相同searchKey的字符颜色都高亮
+ (NSMutableAttributedString *)allString:(NSString *)allString colorString:(NSString *)colorString color:(UIColor *)color;


//根据秒数转成分：秒
+ (NSString *)timeFormatted:(int)totalSeconds;



// 将时间字符串转成时间戳
- (NSTimeInterval)timeIntervalSince1970Date_IOS;

// 将图片裁剪后的urlString(默认都是50）
- (NSString *)imageStrWithWidth:(CGFloat )windth Height:(CGFloat )height;


// 将图片裁剪后的urlString
- (NSString *)imageStringWithWidth:(CGFloat )windth Height:(CGFloat )height;

/**     ------------------------------------------------------------------------
 *  快速计算出文本的真实尺寸
 *
 *  @param font    文字的字体
 *  @param maxSize 文本的最大尺寸
 *
 *  @return 快速计算出文本的真实尺寸
 */
- (CGSize)oka_sizeWithFont:(UIFont *)font
             withinMaxSize:(CGSize)maxSize;
@end
