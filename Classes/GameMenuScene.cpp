//
//  GameMenuScene.cpp
//  MyGame
//
//  Created by 杜盛瑀 on 2020/4/14.
//

#include "GameMenuScene.hpp"

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
    
    auto visibleSize = Director::getInstance()->getWinSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    CCLOG("origin x is %f",origin.x);
    CCLOG("origin y is %f",origin.y);
    CCLOG("width is %f",visibleSize.width);
    CCLOG("height is %f",visibleSize.height);
    //绘制背景
    auto bg = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/bg.png");
    bg->setPosition(visibleSize/2);
    float spx = bg->getTextureRect().getMaxX();
    float spy = bg->getTextureRect().getMaxY();
    bg->setScale(visibleSize.width/spx,visibleSize.height/spy);
    this->addChild(bg);
    
    //标题
    auto title = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/title.png");
    title->setPosition(Vec2(visibleSize.width/2,visibleSize.height-100));
    spx = title->getTextureRect().getMaxX();
    title->setScale(visibleSize.width*0.8f/spx,visibleSize.width*0.8f/spx);
    this->addChild(title);
    
    //关卡
    auto level = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/level.png");
    level->setPosition(Vec2(visibleSize.width/2,visibleSize.height-200));
    spx = level->getTextureRect().getMaxX();
    level->setScale(visibleSize.width*0.2f/spx,visibleSize.width*0.2f/spx);
    this->addChild(level);
    
    //关卡数字
    auto levelTTF = Label::createWithCharMap("/Users/arlex/Documents/Project/MyGame/Resources/label_ball.png", 14, 20, '0');
    levelTTF->setString(StringUtils::format("%d",1));
    levelTTF->setPosition(level->getContentSize()/2);
    level->addChild(levelTTF);
    
    //开始按钮
    auto startBtn = MenuItemImage::create("/Users/arlex/Documents/Project/MyGame/Resources/start.png","/Users/arlex/Documents/Project/MyGame/Resources/start.png");
    startBtn->initWithCallback(CC_CALLBACK_1(GameMenuScene::onStartBtnPressed, this));
    startBtn->setPosition(visibleSize.width/2, visibleSize.height-300);
    
    //选择关卡按钮
    auto selectBtn = MenuItemImage::create("/Users/arlex/Documents/Project/MyGame/Resources/select.png","/Users/arlex/Documents/Project/MyGame/Resources/select.png");
    selectBtn->initWithCallback(CC_CALLBACK_1(GameMenuScene::onSelectBtnPressed, this));
    selectBtn->setPosition(visibleSize.width/2+20, visibleSize.height-400);
    spx = selectBtn->getContentSize().width;
    selectBtn->setScale(visibleSize.width*0.5f/spx,visibleSize.width*0.5f/spx);

    auto menu = Menu::create(startBtn,selectBtn,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

// 开始游戏
void GameMenuScene::onStartBtnPressed(Ref* pSender){
    CCLOG("start Game");
}

// 选择关卡
void GameMenuScene::onSelectBtnPressed(Ref* pSender){
    CCLOG("select Level");
}
