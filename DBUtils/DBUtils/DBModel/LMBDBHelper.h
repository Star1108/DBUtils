//
//  LMBDBHelper.h
//  DBUtil
//
//  Created by Star on 17/1/2.
//  Copyright © 2017年 刘落星. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDB.h"

@interface LMBDBHelper : NSObject

@property (nonatomic, retain, readonly) FMDatabaseQueue *dbQueue;

+ (LMBDBHelper *)shareInstance;

+ (NSString *)dbPath;

@end
