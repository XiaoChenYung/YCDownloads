//
//  YCDownloads.h
//  YCDownloads
//
//  Created by tm on 2016/10/17.
//  Copyright © 2016年 tm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HSSessionModel.h"
#import "NSString+Hash.h"
@interface YCDownloads : NSObject
//下载的路径
@property (nonatomic, copy) NSString *downloadPath;
//下载的URL数组
@property (nonatomic, strong) NSArray *downloadURLs;
//同时下载的最大数量
@property (nonatomic, assign) NSInteger maxCount;
/**
 *  单例
 *
 *  @return 返回单例对象
 */
+ (instancetype)sharedInstance;

/**
 *  开启任务下载资源
 *
 *  @param url           下载地址
 *  @param progressBlock 回调下载进度
 *  @param stateBlock    下载状态
 */
- (void)download:(NSString *)url progress:(void(^)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress))progressBlock state:(void(^)(DownloadState state))stateBlock;

/**
 *  查询该资源的下载进度值
 *
 *  @param url 下载地址
 *
 *  @return 返回下载进度值
 */
- (CGFloat)progress:(NSString *)url;

/**
 *  获取该资源总大小
 *
 *  @param url 下载地址
 *
 *  @return 资源总大小
 */
- (NSInteger)fileTotalLength:(NSString *)url;

/**
 *  判断该资源是否下载完成
 *
 *  @param url 下载地址
 *
 *  @return YES: 完成
 */
- (BOOL)isCompletion:(NSString *)url;

/**
 *  删除该资源
 *
 *  @param url 下载地址
 */
- (void)deleteFile:(NSString *)url;

/**
 *  清空所有下载资源
 */
- (void)deleteAllFile;
@end
