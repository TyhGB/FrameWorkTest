//
//  EUCBaseCacheModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/30.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCBaseCacheModel : EUCBaseModel

// 及时显示方法
+ (void)setDefaultsDataWithObject:(id)object userID:(NSString *)userID;
+ (id)getDefaultsDataWithUserID:(NSString *)userID;
+ (void)removeDefaultsDataWithUserID:(NSString *)userID;


/**
 创建表

 @param sql 创建表sql语句
 @return 是否创建成功
 */
+ (BOOL)createTableWithSql:(NSString *)sql;



/**
 条件查询表 (同步，会阻塞主线程) Swift使用

 @param tableName 表明
 @param criteria 查询条件
 @return 查询内容
 */
+ (NSMutableArray *)querySwiftDataWithTableName:(NSString *)tableName byCriteria:(NSString *)criteria;
/**
 条件查询表 （同步，会阻塞主线程）OC使用
 
 @param tableName 表名
 @param criteria 查询条件 举例EUCStr(@"date_sent = \'%@\'", myDateSent)
 @return 查询内容
 */
+ (NSMutableArray *)queryDataWithTableName:(NSString *)tableName byCriteria:(NSString *)criteria, ... NS_REQUIRES_NIL_TERMINATION;

/**
 查询整张表 (同步，会阻塞主线程)
 
 @param tableName 表名
 @return 查询内容
 */
+ (NSMutableArray *)queryAllDataWithTableName:(NSString *)tableName;


/**
 条件查询表

 @param sql 查询sql语句
 @param tableName 表名
 @return 查询内容
 */
+ (NSMutableArray*)queryTableWithSQL:(NSString*)sql withTableName:(NSString *)tableName;


/**
 直接插入数据 (同步，会阻塞主线程)
 
 @param tableName 表名
 @param keyValues 插入内容
 @return 插入结果
 */
+ (BOOL)insertDataTable:(NSString *)tableName message:(NSDictionary *)keyValues;

/**
 通过条件更新数据 (同步，会阻塞主线程)
     根据条件，找到并使用keyValues更新老数据
 
 @param tableName 表名
 @param keyValues 新数据内容
 @param criteria 条件 例：EUCStr(@"date_sent = \'%@\'", myDateSent)
 @return 更新结果
 */
+ (BOOL)updateMessageData:(NSString *)tableName keyValues:(NSDictionary *)keyValues byCriteria:(NSString *)criteria;

/**
 通过条件更新一条数据 (同步，会阻塞主线程)
          根据条件，找到并使用keyValues更新老数据

 @param tableName 表名
 @param key 数据库对应字段
 @param value 数据库对应字段值
 @param criteria 筛选条件  例：EUCStr(@"date_sent = \'%@\'", myDateSent)
 @return 更新结果
 */
+ (BOOL)updateMessageData:(NSString *)tableName key:(NSString *)key value:(id)value byCriteria:(NSString *)criteria;

/**
 事务删除整张表 （同步，会阻塞主线程）
 
 @param tableName 表名
 @return 删除结果
 */
+ (BOOL)deleteAllDateWithTableName:(NSString *)tableName;


/**
 条件删除 (同步，会阻塞主线程)
 
 @param tableName 表名
 @param format 删除条件 例：EUCStr(@"date_sent = \'%@\'", myDateSent)
 @return 删除结果
 */
+ (BOOL)deleteDataWithTableName:(NSString *)tableName byFormat:(NSString *)format, ...;


@end
