//
//  BFContactModel.h
//  OkayappsFrameworkDemo
//
//  Created by zhangzuolin on 15/1/26.
//  Copyright (c) 2015年 okayapps.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/ABAddressBook.h>
#import <UIKit/UIKit.h>

#pragma mark ---------------
#pragma mark BFPhoneWithLabel

@interface BFPhoneWithLabel : NSObject
//号码
@property (nonatomic, readonly) NSString *phone;
//标签
@property (nonatomic, readonly) NSString *label;

- (id)initWithPhone:(NSString *)phone label:(NSString *)label;

@end

#pragma mark ---------------
#pragma mark BFSocialProfile

typedef NS_ENUM(NSUInteger, BFSocialNetworkType)
{
    BFSocialNetworkUnknown = 0,
    BFSocialNetworkFacebook = 1,
    BFSocialNetworkTwitter = 2,
    BFSocialNetworkLinkedIn = 3
};

@interface BFSocialProfile : NSObject
//社交类型
@property (nonatomic, readonly) BFSocialNetworkType socialNetwork;
//用户名
@property (nonatomic, readonly) NSString *username;
//用户识别号
@property (nonatomic, readonly) NSString *userIdentifier;
//网址
@property (nonatomic, readonly) NSURL *url;

- (instancetype)initWithSocialDictionary:(NSDictionary *)dictionary;

@end

#pragma mark ---------------
#pragma mark BFContactAddress

@interface BFContactAddress : NSObject
//街道
@property (nonatomic, readonly) NSString *street;
//城市
@property (nonatomic, readonly) NSString *city;
//州
@property (nonatomic, readonly) NSString *state;
@property (nonatomic, readonly) NSString *zip;
//国家
@property (nonatomic, readonly) NSString *country;
//国家代码
@property (nonatomic, readonly) NSString *countryCode;

- (id)initWithAddressDictionary:(NSDictionary *)dictionary;

@end

#pragma mark ---------------
#pragma mark BFContactModel

@interface BFContactModel : NSObject
//公选择用，无意义
@property (assign, nonatomic, getter=isSelected) BOOL selected;

//记录id
@property (copy, nonatomic, readonly) NSNumber *recordID;
//名
@property (copy, nonatomic) NSString *firstName;
//姓
@property (copy, nonatomic) NSString *lastName;
//中间名
@property (copy, nonatomic, readonly) NSString *middleName;
//全名
@property (copy, nonatomic) NSString *compositeName;
//全名拼音
@property (copy, nonatomic) NSString *compositePinyinName;
//昵称
@property (copy, nonatomic, readonly) NSString *nickname;
//所属单位
@property (copy, nonatomic, readonly) NSString *organization;
//工作名称
@property (copy, nonatomic, readonly) NSString *jobTitle;
//职务
@property (copy, nonatomic, readonly) NSString *department;
//生日
@property (copy, nonatomic, readonly) NSDate *birthday;
//标签
@property (copy, nonatomic, readonly) NSString *note;
//创建日期
@property (copy, nonatomic, readonly) NSDate *creationDate;
//修改日期
@property (copy, nonatomic, readonly) NSDate *modificationDate;
//头像
@property (copy, nonatomic, readonly) UIImage *photo;
//所有号码 这里应该也是 readonly 才对
@property (copy, nonatomic) NSArray *phones;
//所有email地址
@property (copy, nonatomic, readonly) NSArray *emails;
//所有地址
@property (copy, nonatomic) NSArray *addresses;
//所有个人主页
@property (copy, nonatomic, readonly) NSArray *socialProfiles;

//初始化数据
- (void)setPersonProperty:(ABRecordRef)recordRef;

@end
