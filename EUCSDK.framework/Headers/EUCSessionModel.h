//
//  EUCSessionModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/7/9.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCSessionModel : EUCBaseModel

@property (nonatomic, copy) NSString* v;
@property (nonatomic, copy) NSString* ID;
// application_id
@property (nonatomic, copy) NSString* application_id;
// 创建时间
@property (nonatomic, copy) NSString* created_at;
// ts
@property (nonatomic, copy) NSString* ts;
// expires_at
@property (nonatomic, copy) NSString* expires_at;
// 随机数
@property (nonatomic, copy) NSString* nonce;
// Token（重要） 原来的token 改成paasToken了
@property (nonatomic, copy) NSString* paasToken;
// 更新时间
@property (nonatomic, copy) NSString* updated_at;
// 当期那登录的user_id
@property (nonatomic, copy) NSString* user_id;

@property (nonatomic, copy) NSString* client_type;

@property (nonatomic, copy) NSString* client_version;

@end
