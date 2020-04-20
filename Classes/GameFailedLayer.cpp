//
//  GameFailedLayer.cpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#include "GameFailedLayer.hpp"
#include "Defines.h"
#include "GameMainScene.hpp"
#include "GameMenuScene.hpp"
#include "GlobalManager.hpp"
#include "GameDataManager.hpp"
#include "GameLevelScene.hpp"


Scene* GameFailedLayer::createScene(){
    Scene *scene = Scene::create();
    auto *layer = GameFailedLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameFailedLayer::init(){
    if(!Layer::init()){
        return false;
    }
    //失败对话框
    initWinLayer();
    return true;
}

//胜利对话框
void GameFailedLayer::initWinLayer(){
    //背景图片
    auto bg = Sprite::create(RESOURCE_DIR+"MainScene/bg.png");
    bg->setPosition(WINSIZE/2);
    float spy = bg->getContentSize().height;
    bg->setScale(WINSIZE.height/spy, WINSIZE.height/spy);
    this->addChild(bg);
    
    //过关背景
    auto bgFailed = Sprite::create(RESOURCE_DIR+"ResultScene/failedBg.png");
    float spx = bgFailed->getContentSize().width;
    bgFailed->setScale(WINSIZE.width/spx, WINSIZE.width/spx);
    bgFailed->setPosition(Vec2(WINSIZE/2));
    this->addChild(bgFailed);
    
    //过关文字
    auto loseText = Label::create();
    loseText->setString("过关失败");
    loseText->setBMFontSize(50);
    loseText->setPosition(loseText->getContentSize()/2);
    bgFailed->addChild(loseText);
    
    //选关按钮
    auto selectBtn = MenuItemImage::create(RESOURCE_DIR+"ResultScene/selectLevel.png",RESOURCE_DIR+"ResultScene/selectLevel.png");
    selectBtn->initWithCallback(CC_CALLBACK_1(GameFailedLayer::onReturnToSelectSceneBtnPressed, this));
    spx = selectBtn->getContentSize().width;
    selectBtn->setScale(WINSIZE.width*0.2/spx, WINSIZE.width*0.2/spx);
    selectBtn->setPosition(Vec2(bgFailed->getContentSize().width/2-80,150));
    
    //重玩按钮
    auto replayBtn = MenuItemImage::create(RESOURCE_DIR+"ResultScene/replay.png",RESOURCE_DIR+"ResultScene/replay.png");
    replayBtn->initWithCallback(CC_CALLBACK_1(GameFailedLayer::onReplayBtnPressed, this));
    spx = replayBtn->getContentSize().width;
    replayBtn->setScale(WINSIZE.width*0.2/spx, WINSIZE.width*0.2/spx);
    replayBtn->setPosition(Vec2(bgFailed->getContentSize().width/2+80,150));
    
    //菜单
    auto menu = Menu::create(selectBtn,replayBtn,NULL);
    menu->setPosition(Vec2::ZERO);
    bgFailed->addChild(menu);
}

//返回开始菜单
void GameFailedLayer::onReturnToMenuSceneBtnPressed(Ref *pSender){
    Director::getInstance()->replaceScene(GameMenuScene::createScene());
}

//返回选关
void GameFailedLayer::onReturnToSelectSceneBtnPressed(Ref *pSender){
    Director::getInstance()->replaceScene(GameLevelScene::createScene());
}

//分享
void GameFailedLayer::onSharedBtnPressed(Ref *pSender){
    
}

//进入下一关
void GameFailedLayer::onReplayBtnPressed(Ref *pSender){
    Director::getInstance()->replaceScene(GameMainScene::createScene());
}
