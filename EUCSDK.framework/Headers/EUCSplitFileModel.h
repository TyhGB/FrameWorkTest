//
//  EUCSplitFileModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/9/25.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@class EUCSplitFileDataModel, EUCSplitFileRspModel;
@interface EUCSplitFileModel : EUCBaseModel

// 返回码
@property (nonatomic, strong) NSNumber *code;
// 返回消息
@property (nonatomic, copy) NSString *message;
// 返回的核心数据
@property (nonatomic, strong) EUCSplitFileDataModel *data;

@end


@interface EUCSplitFileDataModel : EUCBaseModel

// 是否还有待传的分片
@property (nonatomic, strong) NSNumber *hasNext;
// 已传分片
@property (nonatomic, strong) NSArray *uploadedChunks;
// 文件下载链接
@property (nonatomic, copy) NSString *resourceUrl;
// 文件发送核心数据
@property (nonatomic, strong) EUCSplitFileRspModel *sendFileRsp;

@end

@interface EUCSplitFileRspModel : EUCBaseModel

// 此文件在我名下的fileToken
@property (nonatomic, copy) NSString *fileToken_own;
// 此文件在发送对象名下的fileToken
@property (nonatomic, copy) NSString *fileToken_friend;
// 文件下载链接
@property (nonatomic, copy) NSString *downloadUrl;

@end
