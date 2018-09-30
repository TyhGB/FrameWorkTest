//
//  EUCPhoneAddressBookContactModel.h
//  EUCIMManager
//
//  Created by sunqy on 2017/6/3.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/ABAddressBook.h>
#import "BFContactModel.h"
#import "EUCUserModel.h"

@interface EUCPhoneAddressBookContactModel : BFContactModel

//全名，自己拼接的
//@property (copy, nonatomic) NSString *fullName;
//头像
@property (copy, nonatomic) UIImage *photo_TMP;
//唯一标示号码
@property (copy, nonatomic) NSString *phone;

@property (nonatomic, strong) EUCUserModel *userModel;
@property (nonatomic, copy, readonly) NSString *ID;


@property (assign, nonatomic) BOOL isIDCompare;

@property (assign, nonatomic) BOOL isABCompare;


// 选择状态
@property (nonatomic, assign) EUCUserModelSelectedState selectedState;

@end
