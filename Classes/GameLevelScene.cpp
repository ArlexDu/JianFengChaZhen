//
//  GameLevelScene.cpp
//  MyGame
//
//  Created by arlex on 2020/4/17.
//

#include "GameLevelScene.hpp"
#include "Defines.h"
#include "GameDataManager.hpp"
#include "GameMainScene.hpp"
#include "GlobalManager.hpp"
#include "GameMenuScene.hpp"

USING_NS_CC;
#define PAGE_CONTIANER_MAX 40
#define LEVEL_PAGES (int)(ceil((float)(GameDataManager::getInstance()->totalRow)/(float)(PAGE_CONTIANER_MAX)))

GameLevelScene::GameLevelScene():pageIndex(1){
    
}

GameLevelScene::~GameLevelScene(){
    
}

Scene* GameLevelScene::createScene(){
    auto scene = Scene::create();
    auto layer = GameLevelScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameLevelScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    //绘制游戏背景
    auto bg = Sprite::create(RESOURCE_DIR+"MainScene/bg.png");
    bg->setPosition(WINSIZE/2);
    float spy = bg->getContentSize().height;
    bg->setScale(WINSIZE.height/spy, WINSIZE.height/spy);
    this->addChild(bg);
    
    //返回按钮
    auto backBtn = MenuItemImage::create(RESOURCE_DIR+"levelScene/back.png",
                                      RESOURCE_DIR+"levelScene/back.png",
                                      CC_CALLBACK_1(GameLevelScene::onBackBtnPressed,this));
    float spx = backBtn->getContentSize().width;
    backBtn->setScale(WINSIZE.width*0.08/spx, WINSIZE.width*0.08/spx);
    backBtn->setAnchorPoint(Vec2(0.5,0));
    backBtn->setPosition(WINSIZE.width/2,50);
    
    auto menu = Menu::create(backBtn,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,1);
    
    levelLayer = Layer::create();
    this->addChild(levelLayer);
    
    //绘制关卡
    int index=0;
    int maxLevel = GameDataManager::getInstance()->totalRow;
    CCLOG("max level is %d",maxLevel);
    for(int i=1;i<=maxLevel;i++){
        MenuItemImage *item = NULL;
        if(i<=GameDataManager::getInstance()->getCurrentMaxLevel()){
            item=MenuItemImage::create(RESOURCE_DIR+"levelScene/has_pass.png",RESOURCE_DIR+"levelScene/has_pass.png",
                                       CC_CALLBACK_1(GameLevelScene::onLevelBtnPressed,this,i));
        }else{
            item=MenuItemImage::create(RESOURCE_DIR+"levelScene/has_pass.png",RESOURCE_DIR+"levelScene/has_pass.png",
                                       CC_CALLBACK_1(GameLevelScene::onLevelBtnPressed,this,i));
            //添加锁
            auto lock = Sprite::create(RESOURCE_DIR+"levelScene/lock.png");
            spx = lock->getContentSize().width;
            lock->setScale(WINSIZE.width*0.05/spx, WINSIZE.width*0.05/spx);
            lock->setPosition(Vec2(item->getContentSize())/2);
            item->addChild(lock,10);
        }
        spx = item->getContentSize().width;
        item->setScale(WINSIZE.width*0.15/spx, WINSIZE.width*0.15/spx);
        float x =WINSIZE.width*(int)(index/PAGE_CONTIANER_MAX)+80+index%5*(item->getContentSize().width*1.8f);
        float y =WINSIZE.height*0.9f-(index%PAGE_CONTIANER_MAX)/5*(item->getContentSize().height*1.8f);
        //CCLOG("x is %f, y is %f",x,y);
        item->setPosition(x,y);
        auto menu = Menu::create(item,NULL);
        menu->setPosition(Point::ZERO);
        levelLayer->addChild(menu);
        index++;
        //显示关卡数
        auto levelTTF = Label::create();
        levelTTF->setPosition(item->getContentSize()/2);
        levelTTF->setString(to_string(i));
        item->addChild(levelTTF);
    }
    //创建触摸监听
    auto touchListener = EventListenerTouchOneByOne::create();
    //向下传递触摸事件
    touchListener->setSwallowTouches(false);
    touchListener->onTouchBegan = CC_CALLBACK_2(GameLevelScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameLevelScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameLevelScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    //注册捕捉函数
    auto listenerKeyPad = EventListenerKeyboard::create();
    listenerKeyPad->onKeyReleased = CC_CALLBACK_2(GameLevelScene::onKeyReleased, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKeyPad, this);
    return true;
}

//触摸开始方法
bool GameLevelScene::onTouchBegan(Touch *touch, Event *event){
    pos1 = touch->getLocation();
    return true;
}

//触摸移动方法
void GameLevelScene::onTouchMoved(Touch *touch, Event *event){
    pos2 = touch->getLocation();
}

//触摸结束方法
void GameLevelScene::onTouchEnded(Touch *touch, Event *event){
    if((pos1.x-pos2.x)>=50){
        //向后翻页
        if(pageIndex<LEVEL_PAGES){
            if(levelLayer->getNumberOfRunningActions() == 0){
                levelLayer->runAction(MoveTo::create(0.5f, Point(-WINSIZE.width*pageIndex,0)));
                pageIndex++;
            }
        }else{
            pageIndex = LEVEL_PAGES;
        }
    }else if((pos1.x-pos2.x)<=-50){
        //向前翻页
        if(pageIndex>1){
            if(levelLayer->getNumberOfRunningActions() == 0){
                levelLayer->runAction(MoveTo::create(0.5f,Point(-WINSIZE.width*(pageIndex-2),0)));
            }
        }
    }else{
        pageIndex = 1;
    }
}

void GameLevelScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event){
    if(keycode == EventKeyboard::KeyCode::KEY_SPACE){
        Director::getInstance()->replaceScene(GameMenuScene::createScene());
    }
}

void GameLevelScene::onLevelBtnPressed(Ref *pSender, int level){
    GlobalManager::getInstance()->currentLevel = level;
    if(GlobalManager::getInstance()->currentLevel <= GameDataManager::getInstance()->getCurrentMaxLevel()){
        GameDataManager::getInstance()->loadGameData(GlobalManager::getInstance()->currentLevel);
        Director::getInstance()->replaceScene(GameMainScene::createScene());
    }
}

//返回按钮
void GameLevelScene::onBackBtnPressed(Ref *pSender){
    Director::getInstance()->replaceScene(GameMenuScene::createScene());
}
