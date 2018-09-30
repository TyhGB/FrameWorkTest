//
//  EUCNewVoiceModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2018/2/5.
//  Copyright © 2018年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

@interface EUCNewVoiceModel : EUCBaseModel

/**
 音频名称
 */
@property (nonatomic, copy) NSString *voiceName;
/**
 音频时长
 */
@property (nonatomic, assign) NSInteger voiceLength;

/**
 指向临时路径的标识
 */
@property (nonatomic, copy) NSString *client_msg_id;

/**
 初始化方法
 生成语音临时路径，与指向临时路径的标识

 @param originPath 语音原路径
 @param voiceLength 语音时长
 @return 语音对象
 */
- (instancetype)initWithOriginPath:(NSString *)originPath
                       voiceLength:(NSInteger)voiceLength;

@end
