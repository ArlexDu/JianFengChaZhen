//
//  Defines.h
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#ifndef Defines_h
#define Defines_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

//屏幕相关
#define WINSIZE (Director::getInstance()->getWinSize())

//可视区域
#define VISIBLE_SIZE (Director::getInstance()->getVisibleSize())

//可视区域起点坐标
#define VISIBLE_ORIGIN_SIZE (Director::getInstance()->getVisibleOrigin())

//重写to_string
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
template<typename T>
string to_string(const T& t){
    ostringstream os;
    os<<t;
    return os.str();
}
#endif

const string RESOURCE_DIR = "/Users/arlex/Documents/Project/MyGame/Resources/";

//针的长度
#define RADIUS 150

//中间圆球的Y坐标
#define POSY 540

#endif /* Defines_h */
