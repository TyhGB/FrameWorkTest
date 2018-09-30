//
//  EUCTrunkFileModel.h
//  EUCIMManager
//
//  Created by jintao on 2017/11/8.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCTrunkFileModel : EUCBaseModel

// 分片文件ID
@property (nonatomic, strong) NSNumber *trunk;
// 分片文件所在绝对路径
@property (nonatomic, copy) NSString *splitAbsolutePath;

@end
