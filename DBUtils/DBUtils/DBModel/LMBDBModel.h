//
//  LMBDBModel.h
//  DBUtil
//
//  Created by Star on 17/1/2.
//  Copyright © 2017年 刘落星. All rights reserved.
//

#import <Foundation/Foundation.h>

//SQLite五种数据类型
#define SQLTEXT     @"TEXT"
#define SQLINTEGER  @"INTEGER"
#define SQLREAL     @"REAL"
#define SQLBLOB     @"BLOB"
#define SQLNULL     @"NULL"


#define PrimaryKey  @"primary key"

#define primaryId   @"pk"


@interface LMBDBModel : NSObject

//主键 id
@property (nonatomic, assign)   int  pk;
//列名
@property (retain, readonly, nonatomic) NSMutableArray *columeNames;
//每一列类型
@property (retain, readonly, nonatomic) NSMutableArray *columeTypes;
//所有类属性类型
@property (retain, readonly, nonatomic) NSMutableArray *attributeTypes;

///获取该类的所有属性,不包括主键
+ (NSDictionary *)getPropertys;

///获取所有属性，包括主键
+ (NSDictionary *)getAllProperties;

///检查数据库中是否存在表
+ (BOOL)isExistInTable;

///获取数据库表中的字段
+ (NSArray *)getColumns;

///保存或更新,通过主键确定是新增还是更新，如果不存在主键，保存，有主键，则更新
- (BOOL)saveOrUpdate;

/// 保存或更新，根据特定的列数据确定是新增还是更新，如果可以获取记录，则更新，没有记录，则保存
- (BOOL)saveOrUpdateByColumnName:(NSString*)columnName AndColumnValue:(NSString*)columnValue;

///保存单个数据
- (BOOL)save;
///批量保存数据
+ (BOOL)saveObjects:(NSArray *)array;

///更新单个数据
- (BOOL)update;
///批量更新数据
+ (BOOL)updateObjects:(NSArray *)array;

///删除单个数据
- (BOOL)deleteObject;
///批量删除数据
+ (BOOL)deleteObjects:(NSArray *)array;

///通过条件删除数据(where子句)
+ (BOOL)deleteObjectsByCriteria:(NSString *)criteria;
///通过条件删除(多参数)
+ (BOOL)deleteObjectsWithFormat:(NSString *)format, ...;

///清空表
+ (BOOL)clearTable;

///查询表中全部数据
+ (NSArray *)findAll;

///通过主键查询数据
+ (instancetype)findByPK:(int)inPk;
+ (instancetype)findFirstWithFormat:(NSString *)format, ...;

///查找某条数据
+ (instancetype)findFirstByCriteria:(NSString *)criteria;

+ (NSArray *)findWithFormat:(NSString *)format, ...;

/**
 * 通过条件查找数据
 */
+ (NSArray *)findByCriteria:(NSString *)criteria;

/**
 * 创建表
 * 如果已经创建，返回YES
 */
+ (BOOL)createTable;

#pragma mark - override method
/** 如果子类中有一些property不需要创建数据库字段，那么在子类中重写这个方法
 */
+ (NSArray *)transients;

@end
