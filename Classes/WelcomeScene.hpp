//
//  WelcomeScene.hpp
//  MyGame
//
//  Created by arlex on 2020/4/14.
//

#ifndef WelcomeScene_hpp
#define WelcomeScene_hpp

//#pragma once 为了避免同一个头文件被包含（include）多次，作用同上面的#ifndef

#include "cocos2d.h"

class WelcomeScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    //实现静态创建方法
    CREATE_FUNC(WelcomeScene);
    
    //初始化第一次登录数据
    void initFirstLoginData();
};

#endif /* WelcomeScene_hpp */
