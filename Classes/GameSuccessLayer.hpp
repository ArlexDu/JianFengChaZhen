//
//  GameSuccessLayer.hpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#ifndef GameSuccessLayer_hpp
#define GameSuccessLayer_hpp

#include "cocos2d.h"
USING_NS_CC;

class GameSuccessLayer:public cocos2d::Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(GameSuccessLayer);
    virtual bool init();
    //胜利对话框
    void initWinLayer();
    //返回开始菜单
    void onReturnToMenuSceneBtnPressed(Ref* pSender);
    //返回选关
    void onReturnToSelectSceneBtnPressed(Ref* pSender);
    //分享
    void onSharedBtnPressed(Ref* pSender);
    //下一关按钮回调
    void onNextLevelBtnPressed(Ref* pSender);
};

#endif /* GameSuccessLayer_hpp */
