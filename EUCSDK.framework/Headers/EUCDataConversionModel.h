//
//  EUCDataConversionModel.h
//  EUCIMManager
//
//  Created by  ZhuHong on 2017/10/12.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import "EUCBaseModel.h"
#import "EUCDialogModel.h"

@interface EUCDataConversionModel : EUCBaseModel

+ (NSMutableArray*)messageModelsFramRecords:(NSArray*)records all:(BOOL)all chat_dialog_id:(NSString*)chat_dialog_id;

+ (EUCDialogItemModel*)updateDialogModelFromRecordDict:(NSDictionary*)recordDict unReadCount:(NSString*)unReadCount;

@end
