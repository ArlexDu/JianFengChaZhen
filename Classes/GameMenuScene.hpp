//
//  GameMenuScene.hpp
//  MyGame
//
//  Created by arlex on 2020/4/14.
//

#ifndef GameMenuScene_hpp
#define GameMenuScene_hpp

#include "cocos2d.h"

class GameMenuScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    //实现静态创建方法
    CREATE_FUNC(GameMenuScene);
    
    //开始游戏
    void onStartBtnPressed(Ref* pSender);
    
    //选择关卡
    void onSelectBtnPressed(Ref* pSender);
};

#endif /* GameMenuScene_hpp */
