//
//  WelcomeScene.cpp
//  MyGame
//
//  Created by arlex on 2020/4/14.
//

#include "WelcomeScene.hpp"
#include "GameDataManager.hpp"
USING_NS_CC;
//在AppDelegate中调用，获取包含WelcomeScene这个layer的scene
Scene* WelcomeScene::createScene(){
    // scene is an autorelease object
    auto scene = Scene::create();
    
    // WelcomeScene::create()其实调用的是CREATE_FUN这个宏，里面将这个对象放入了自动释放池
    // 同时在CRETAE_FUN的定义中调用了对象类的init函数
    auto layer = WelcomeScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    //return scene
    return scene;
    
}

// 初始化Welcome这个Layer对象
bool WelcomeScene::init(){
    // super init first
    if(!Layer::init()){
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getWinSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    // add welcome page
    auto sprite = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/welcome.png");
    
    // set the sprite position in the center fo layer
    sprite->setPosition(Vec2(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y));
    
    // add the sprite as a child to the layer
    this->addChild(sprite,0);
    
    initFirstLoginData();
    //获得最大关卡数据
    auto maxLevel = GameDataManager::getInstance()->getCurrentMaxLevel();
    GameDataManager::getInstance()->loadGameData(maxLevel);
}

//初始化第一次登录数据
void WelcomeScene::initFirstLoginData(){
    if(!GameDataManager::getInstance()->getIsFirstInit()){
        //设置已经初始化
        GameDataManager::getInstance()->setIsFirstInit(true);
        //初始化当前最大关卡
        GameDataManager::getInstance()->setCurrentMaxLevel(1);
    }
}

