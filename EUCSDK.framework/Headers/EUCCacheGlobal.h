//
//  EUCCacheGlobal.h
//  EUCIMManager
//
//  Created by 肖乐 on 2017/10/30.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//聊天记录缓存key值
UIKIT_EXTERN NSString *const EUCDialogListTableName;
UIKIT_EXTERN NSString *const EUCMessageListTableName;
UIKIT_EXTERN NSString *const EUCDialogNickNameTableName;
UIKIT_EXTERN NSString *const EUCAddressBookContactTableName;
UIKIT_EXTERN NSString *const EUCRealFriendTableName;
UIKIT_EXTERN NSString *const EUCFriendRequestTableName;
UIKIT_EXTERN NSString *const EUCBlicklistTableName;

@interface EUCCacheGlobal : NSObject

@end
