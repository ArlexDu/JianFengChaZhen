//
//  GameLevelScene.hpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#ifndef GameLevelScene_hpp
#define GameLevelScene_hpp

#include "cocos2d.h"

USING_NS_CC;

class GameLevelScene:public cocos2d::Layer{
public:
    GameLevelScene();
    ~GameLevelScene();
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameLevelScene);
    //触摸开始方法
    bool onTouchBegan(Touch* touch,Event* event);
    //触摸移动方法
    void onTouchMoved(Touch* touch,Event* event);
    //触摸结束方法
    void onTouchEnded(Touch* touch,Event* event);
    
    void onKeyReleased(EventKeyboard::KeyCode keycode,Event* event);
    
    //点击关卡按钮
    void onLevelBtnPressed(Ref* pSender,int level);
    //返回按钮回调
    void onBackBtnPressed(Ref* pSender);
private:
    Layer *levelLayer;
    Point pos1;
    Point pos2;
    //当前页编号
    int pageIndex;
};

#endif /* GameLevelScene_hpp */
