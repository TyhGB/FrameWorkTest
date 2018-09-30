//
//  EUCSendSinglingTool.h
//  EUCIMManager
//
//  Created by Tuling Code on 2017/1/9.
//  Copyright © 2017年 BBDTEK. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, EUCSendSinglingType) {
    EUCSendSinglingTypeCall = 1000,   // 发起视频会议
    EUCSendSinglingTypeAccept,        // 接受
    EUCSendSinglingTypeReject,        // 拒绝
    EUCSendSinglingTypeHangup,        // 挂断
    EUCSendSinglingTypeIceCandidate,  // candidate
    EUCSendSinglingTypeIceCandidates, // 新的candidate
    EUCSendSinglingTypeInvite,        // 中途邀请
    EUCSendSinglingTypeInvite_inform, // 中途邀请通知
    EUCSendSinglingTypeBusy,          // 正在忙信令
    EUCSendSinglingTypeJoin           // 加入信令
};

typedef void (^finishBlock)(NSArray *data);

@interface EUCSendSinglingTool : NSObject

+ (void)sendMessageWithSessionID:(NSString *)sessionID
                        dialogID:(NSString *)dialogID
                        callType:(NSString *)callType
                    opponentsIDs:(NSArray *)opponentsIDs
                 newOpponentsIDs:(NSArray *)newOpponentsIDs
                        callerID:(NSString *)callerID
                       inviterID:(NSString *)inviterID
                   iceCandidates:(NSArray *)iceCandidates
                 targetEasyrtcid:(NSString *)targetEasyrtcid
                             sdp:(NSString *)sdp
                    singlingType:(EUCSendSinglingType)type
                     finishBlock:(finishBlock)block;

@end
