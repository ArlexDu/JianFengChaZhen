//
//  GameFailedLayer.hpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#ifndef GameFailedLayer_hpp
#define GameFailedLayer_hpp

#include "cocos2d.h"

USING_NS_CC;

class GameFailedLayer:public cocos2d::Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(GameFailedLayer);
    virtual bool init();
    //失败对话框
    void initWinLayer();
    //返回开始菜单
    void onReturnToMenuSceneBtnPressed(Ref* pSender);
    //返回选关
    void onReturnToSelectSceneBtnPressed(Ref* pSender);
    //分享
    void onSharedBtnPressed(Ref* pSender);
    //重玩按钮回调
    void onReplayBtnPressed(Ref* pSender);
};


#endif /* GameFailedLayer_hpp */
