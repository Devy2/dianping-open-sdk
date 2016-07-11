//
//  DPAPI.h
//  apidemo
//
//  Created by ZhouHui on 13-1-28.
//  Copyright (c) 2013年 Dianping. All rights reserved.
//

/*
 修改两个文件:DPAPI.h和DPRequest.m, 并在info.plist中加入支持https
 运行界面: "API名称"选择"v1/deal/find_deals", 再点"调用接口"
 
 错误一: 无法更改AppKey和AppSecret
 原因: 第一次运行程序, 会把DPAPI.h中的宏定义写入文件; 无论怎么再修改, 也都是从文件中读取老的key和secrect
 
 错误二: 避免在提供给别人的SDK中导入AppDelegate.h头文件
 
 错误三: 使用了不该使用第三方库JSON
 第三方开源库,解析JSON用自带,不需要第三方SBJson
 */

#import <Foundation/Foundation.h>
#import "DPRequest.h"

//#define kDPAppKey             @"975791789"
//#define kDPAppSecret          @"5e4dcaf696394707b9a0139e40074ce9"
#define kDPAppKey             @"4123794720" //DPAppDelegate.m单例,从沙盒读取
#define kDPAppSecret          @"5a908d5484254cf4879bb47131bfd822"

#ifndef kDPAppKey
#error
#endif

#ifndef kDPAppSecret
#error
#endif

@interface DPAPI : NSObject

- (DPRequest*)requestWithURL:(NSString *)url
					  params:(NSMutableDictionary *)params
					delegate:(id<DPRequestDelegate>)delegate;

- (DPRequest *)requestWithURL:(NSString *)url
				 paramsString:(NSString *)paramsString
					 delegate:(id<DPRequestDelegate>)delegate;

@end
