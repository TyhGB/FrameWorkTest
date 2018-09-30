//
//  EUCUserMangaer.h
//  EUCIMManager
//
//  Created by sunqy on 2017/6/1.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EUCUserMangaer : NSObject

/**
 单例
 */
+ (instancetype)shareManager;

/** 通过标识来存储缓存*/
- (void)saveCacheObject:(id)object key:(NSString *)keyStr;

/** 通过标识来取出缓存*/
- (id)getCacheWithKey:(NSString *)keyStr;

/** 通过标识来删除指定缓存*/
- (void)removeCacheWithKey:(NSString *)keyStr;

/** 删除所有缓存*/
- (void)removeAllCache;

@end
