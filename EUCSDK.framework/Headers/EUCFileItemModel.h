//
//  EUCFileItemModel.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/4/13.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"

typedef NS_ENUM(NSInteger, EUCFileHeaderViewType) {
    EUCFileHeaderViewTypePict = 0,       //图片
    EUCFileHeaderViewTypeDocument,       //文档
    EUCFileHeaderViewTypeVideo,          //视频
    EUCFileHeaderViewTypeMusic,          //音乐
    EUCFileHeaderViewTypeOther           //其他
};

// 文件精确类型
typedef NS_ENUM(NSInteger, EUCFileExactType) {
    
    EUCFileExactTypeZip = 1000, // 压缩包
    EUCFileExactTypeXlex,       // xlex类型
    EUCFileExactTypeWord,       // word文件
    EUCFileExactTypeUnknow,     // 未知文件
    EUCFileExactTypePPT,        // PPT文件
    EUCFileExactTypePDF,        // PDF文件
    EUCFileExactTypeTXT,        // txt文件
    EUCFileExactTypeMusic,      // 音乐类文件
    EUCFileExactTypePict,       // 图片文件
    EUCFileExactTypeVideo       // 视频文件
};

@class EUCDialogItemModel, EUCMessageModel;
@interface EUCFileItemModel : EUCBaseModel

@property (nonatomic, copy) NSString *videoUrl;

// 测试用
@property (nonatomic, assign) BOOL isNewFile;

// 文件绝对路径
@property (nonatomic, copy) NSString *path;
// 文件相对路径
@property (nonatomic, copy) NSString *relativePath;
// 文件名称
@property (nonatomic, copy) NSString *name;
// 文件的格式
@property (nonatomic, copy) NSString *extension;
// 自己文件的fileToken
@property (nonatomic, copy) NSString *fileToken_own;
// 文件发送者的fileToken
@property (nonatomic, copy) NSString *fileToken_friend;
// 文件模糊类型
@property (nonatomic, assign) EUCFileHeaderViewType fileType;
// 文件精确类型
@property (nonatomic, assign) EUCFileExactType exactType;
// 文件大小
@property (nonatomic, copy) NSString *fileSize;
// 文件大小（字节）
@property (nonatomic, assign) long long originSize;
// 文件发送者
@property (nonatomic, copy) NSString *file_Sender;
// 发送文件所在的会话ID
@property (nonatomic, copy) NSString *file_DialogID;
// 文件发送时间
@property (nonatomic, copy) NSString *file_SendDate;
// 文件url
@property (nonatomic, copy) NSString *fileUrl;
// 文件二进制
//@property (nonatomic, strong) NSData *fileData;
/** 是否为文件夹 */
@property (nonatomic, assign, getter = isDir) BOOL dir;

/** 打开或者关闭 */
@property (nonatomic, assign, getter = isOpened) BOOL opened;
//是否选中
@property (nonatomic, assign, getter=selected) BOOL isSelected;

/** 重写初始化文件模型的方法 */
- (instancetype)initWithPath:(NSString *)path name:(NSString *)name dir:(BOOL)dir;

/** 根据文件后缀获取文件精确类型 */
+ (EUCFileExactType)getExactFileTypeWithFileExtension:(NSString *)fileExitension;
/** 根据文件后缀获取文件模糊类型 */
+ (EUCFileHeaderViewType)getVagueFileTypeWithFileExtension:(NSString *)fileExitension;

/** 转换成messageModel */
- (EUCMessageModel *)convertToMessageModel;

@end
