//
//  TestModel.m
//  DBUtil
//
//  Created by Star on 16/12/29.
//  Copyright © 2016年 刘落星. All rights reserved.
//

#import "TestModel.h"

@implementation TestModel

-(instancetype)init{
    if (self = [super init]) {
        self.name = @"liuluoxing";
        self.age = @"10";
        self.sex = NO;
        self.array = @[[[User alloc] init], [[User alloc] init]];
        self.dic = @{@"user":[[User alloc] init]};
        self.user = [[User alloc] init];
    }
    return self;
}

@end
