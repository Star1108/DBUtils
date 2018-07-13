//
//  ViewController.m
//  DBUtil
//
//  Created by Star on 16/12/29.
//  Copyright © 2016年 刘落星. All rights reserved.
//

#import "ViewController.h"
#import "TestModel.h"
#import "User.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    for (int i = 0; i < 5; i++) {
        TestModel *model = [[TestModel alloc] init];
        BOOL success = [model save];
    }
    
    for (int i = 0; i < 3; i++) {
        TestModel *model = [[TestModel alloc] init];
        BOOL success = [model save];
    }
    
    for (int i = 0; i < 3; i++) {
        User *user = [[User alloc] init];
        BOOL success = [user save];
    }

    NSArray *arr = [TestModel findAll];
    for (TestModel *model in arr) {
        NSLog(@"TestModel.pk==%zd",model.pk);
    }
    
     NSArray *arr1 = [User findAll];
    for (User *model in arr1) {
        NSLog(@"User.pk==%zd",model.pk);
    }
    
    for (int i = 0; i < 3; i++) {
        TestModel *model = [[TestModel alloc] init];
        model.pk = i+8;
        BOOL success = [model saveOrUpdate];
    }
    
    NSArray *arr2 = [TestModel findAll];
    for (TestModel *model in arr2) {
        NSLog(@"TestModel.pk==%zd",model.pk);
    }
    
//    BOOL b = [TestModel deleteObjectsByCriteria:@"where name = 'liuluoxing'"];
    [TestModel deleteObjectsWithFormat:@"where name = '%@' and sex = '%zd'", @"liuluoxing", YES];
    NSArray *arr3 = [TestModel findAll];
    for (TestModel *model in arr3) {
        NSLog(@"TestModel.pk==%zd, sex = %zd",model.pk, model.sex);
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
