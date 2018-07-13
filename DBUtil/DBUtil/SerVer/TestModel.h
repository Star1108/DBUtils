//
//  TestModel.h
//  DBUtil
//
//  Created by Star on 16/12/29.
//  Copyright © 2016年 刘落星. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMBDBModel.h"
#import "User.h"

@interface TestModel : LMBDBModel

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *age;

@property (nonatomic, assign) BOOL sex;

@property (nonatomic, strong) NSArray *array;

@property (nonatomic, strong) NSDictionary *dic;

@property (nonatomic, strong) User *user;

@property (nonatomic, assign) NSInteger value_int;
@property (nonatomic, assign) NSInteger value_integer;

@property (nonatomic, assign) long value_long;

@property (nonatomic, assign) double value_double;
@property (nonatomic, assign) float value_float;

@property (nonatomic, assign) char value_char;

@property (nonatomic, strong) id value_id;

@end
