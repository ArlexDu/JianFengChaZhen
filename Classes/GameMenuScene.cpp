//
//  GameMenuScene.cpp
//  MyGame
//
//  Created by arlex on 2020/4/14.
//

#include "GameMenuScene.hpp"
#include "GameMainScene.hpp"
#include "Defines.h"
#include "GlobalManager.hpp"
#include "GameLevelScene.hpp"
#include "GameMusic.hpp"

USING_NS_CC;

Scene* GameMenuScene::createScene(){
    auto scene = Scene::create();
    
    auto layer = GameMenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameMenuScene::init(){
    
    if(!Layer::init()){
        return false;
    }
    
    auto origin = Director::getInstance()->getVisibleOrigin();
//    CCLOG("origin x is %f",origin.x);
//    CCLOG("origin y is %f",origin.y);
//    CCLOG("width is %f",visibleSize.width);
//    CCLOG("height is %f",visibleSize.height);
    //绘制背景
    auto bg = Sprite::create(RESOURCE_DIR+"MainScene/bg.png");
    bg->setPosition(WINSIZE/2);
    float spx = bg->getTextureRect().getMaxX();
    float spy = bg->getTextureRect().getMaxY();
    bg->setScale(WINSIZE.width/spx,WINSIZE.height/spy);
    this->addChild(bg);
    
    //标题
    auto title = Sprite::create(RESOURCE_DIR+"MenuScene/title.png");
    title->setPosition(Vec2(WINSIZE.width/2,WINSIZE.height-100));
    spx = title->getTextureRect().getMaxX();
    title->setScale(WINSIZE.width*0.8f/spx,WINSIZE.width*0.8f/spx);
    this->addChild(title);
    
    //关卡数字
    auto levelTTF = Label::createWithTTF("",RESOURCE_DIR+"fonts/I-PenCrane-B-2.ttf", 30);
    levelTTF->setString(StringUtils::format("第 %d 關",GlobalManager::getInstance()->currentLevel));
    levelTTF->setColor(Color3B(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f));
    levelTTF->setPosition(Vec2(WINSIZE.width/2,WINSIZE.height-200));
    this->addChild(levelTTF);
    
    //开始按钮
    auto startBtn = MenuItemImage::create(RESOURCE_DIR+"MenuScene/start.png",RESOURCE_DIR+"MenuScene/start.png");
    startBtn->initWithCallback(CC_CALLBACK_1(GameMenuScene::onStartBtnPressed, this));
    startBtn->setPosition(WINSIZE.width/2, WINSIZE.height-300);
    
    auto menu = Menu::create(startBtn,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    //选择关卡文字
    auto selectTTF = Label::createWithTTF("選擇關卡",RESOURCE_DIR+"fonts/I-PenCrane-B-2.ttf", 30);
    selectTTF->setColor(Color3B(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f));
    selectTTF->setPosition(WINSIZE.width/2, WINSIZE.height-400);
    this->addChild(selectTTF);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(false);
    listener->onTouchBegan = [](Touch* t,Event* e){
        return true;
    };
    listener->onTouchEnded = CC_CALLBACK_1(GameMenuScene::onSelectBtnPressed, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //底部装饰
    auto bottom = MenuItemImage::create(RESOURCE_DIR+"MenuScene/bottom.png",RESOURCE_DIR+"MenuScene/bottom.png");
    bottom->setAnchorPoint(Vec2(0.5,0));
    bottom->setPosition(WINSIZE.width/2, 50);
    spx = bottom->getContentSize().width;
    bottom->setScale(WINSIZE.width/spx,WINSIZE.width/spx);
    this->addChild(bottom);
    
    //增加背景音乐
    GameMusic::getInstance()->playMusic((RESOURCE_DIR+"Audios/Naruto Main Theme.mp3").c_str(),true);
    
    return true;
}

// 开始游戏
void GameMenuScene::onStartBtnPressed(Ref* pSender){
    auto scene = GameMainScene::createScene();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0f,scene));
}

// 选择关卡
void GameMenuScene::onSelectBtnPressed(Ref* pSender){
    Director::getInstance()->replaceScene(GameLevelScene::createScene());
}
