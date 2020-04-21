//
//  GameSuccessLayer.cpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#include "GameSuccessLayer.hpp"
#include "Defines.h"
#include "GameMainScene.hpp"
#include "GameMenuScene.hpp"
#include "GlobalManager.hpp"
#include "GameDataManager.hpp"
#include "GameLevelScene.hpp"

Scene* GameSuccessLayer::createScene(){
    Scene *scene = Scene::create();
    auto *layer = GameSuccessLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameSuccessLayer::init(){
    if(!Layer::init()){
        return false;
    }
    //胜利对话框
    initWinLayer();
    return true;
}

//胜利对话框
void GameSuccessLayer::initWinLayer(){
    //背景图片
    auto bg = Sprite::create(RESOURCE_DIR+"MainScene/bg.png");
    bg->setPosition(WINSIZE/2);
    float spy = bg->getContentSize().height;
    bg->setScale(WINSIZE.height/spy, WINSIZE.height/spy);
    this->addChild(bg);
    
    //过关背景
    auto bgWin = Sprite::create(RESOURCE_DIR+"ResultScene/successBg.png");
    float spx = bgWin->getContentSize().width;
    bgWin->setScale(WINSIZE.width/spx, WINSIZE.width/spx);
    bgWin->setPosition(Vec2(WINSIZE/2));
    this->addChild(bgWin);
    
    //过关文字
    auto winText = Label::createWithTTF("勝 利",RESOURCE_DIR+"fonts/I-PenCrane-B-2.ttf", 60);
    winText->setPosition(WINSIZE.width/2,WINSIZE.height*0.55);
    winText->setColor(Color3B(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f));
    this->addChild(winText);
    
    //选关按钮
    auto selectBtn = MenuItemImage::create(RESOURCE_DIR+"ResultScene/selectLevel.png",RESOURCE_DIR+"ResultScene/selectLevel.png");
    selectBtn->initWithCallback(CC_CALLBACK_1(GameSuccessLayer::onReturnToSelectSceneBtnPressed, this));
    spx = selectBtn->getContentSize().width;
    selectBtn->setScale(WINSIZE.width*0.2/spx, WINSIZE.width*0.2/spx);
    selectBtn->setPosition(Vec2(bgWin->getContentSize().width/2-80,150));
    
    //下一关按钮
    auto nextBtn = MenuItemImage::create(RESOURCE_DIR+"ResultScene/next.png",RESOURCE_DIR+"ResultScene/next.png");
    nextBtn->initWithCallback(CC_CALLBACK_1(GameSuccessLayer::onNextLevelBtnPressed, this));
    spx = nextBtn->getContentSize().width;
    nextBtn->setScale(WINSIZE.width*0.2/spx, WINSIZE.width*0.2/spx);
    nextBtn->setPosition(Vec2(bgWin->getContentSize().width/2+80,150));
    
    //菜单
    auto menu = Menu::create(selectBtn,nextBtn,NULL);
    menu->setPosition(Vec2::ZERO);
    bgWin->addChild(menu);
}

//返回开始菜单
void GameSuccessLayer::onReturnToMenuSceneBtnPressed(Ref *pSender){
    GameDataManager::getInstance()->setCurrentMaxLevel(GlobalManager::getInstance()->currentLevel+1);
    Director::getInstance()->replaceScene(GameMenuScene::createScene());
}

//返回选关
void GameSuccessLayer::onReturnToSelectSceneBtnPressed(Ref *pSender){
    Director::getInstance()->replaceScene(GameLevelScene::createScene());
}

//分享
void GameSuccessLayer::onSharedBtnPressed(Ref *pSender){
    
}

//进入下一关
void GameSuccessLayer::onNextLevelBtnPressed(Ref *pSender){
    int curr = GlobalManager::getInstance()->currentLevel;
    int maxLevel = GameDataManager::getInstance()->totalRow;
    if(curr>=maxLevel){
        //如果已经是最后一关，则调回到游戏主菜单页面
        Director::getInstance()->replaceScene(GameMenuScene::createScene());
    }else{
        //初始化下一关
        GameDataManager::getInstance()->setCurrentMaxLevel(GlobalManager::getInstance()->currentLevel+1);
        GlobalManager::getInstance()->currentLevel = GlobalManager::getInstance()->currentLevel+1;
        GameDataManager::getInstance()->loadGameData(GlobalManager::getInstance()->currentLevel);
        Director::getInstance()->replaceScene(GameMainScene::createScene());
    }
}
