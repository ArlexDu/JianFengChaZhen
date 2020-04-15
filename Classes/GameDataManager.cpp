//
//  GameDataManager.cpp
//  MyGame
//
//  Created by arlex on 2020/4/15.
//

#include "GameDataManager.hpp"
#include <cstring>

GameDataManager* GameDataManager::singleInstance = NULL;

GameDataManager* GameDataManager::getInstance(){
    if(NULL == singleInstance){
        singleInstance = new GameDataManager();
    }
    return singleInstance;
}

//c++构造函数后面跟“：”也表示赋值
GameDataManager::GameDataManager():csv("/Users/arlex/Documents/Project/MyGame/Resources/game.csv"){
    totalRow = csv.getRowCount()-1;
}

GameDataManager::~GameDataManager(){}

bool GameDataManager::init(){
    return true;
}

//载入游戏数据
void GameDataManager::loadGameData(int level){
//    获得出现的小球数量
    getObsBallNum(level);
//    获得用户的小球数量
    getUserBallNum(level);
//    获得旋转方向
    getRotateDir(level);
//    获得旋转速度
    getRotateSpeed(level);
//    获得遮罩圆的开始角度
    getStartAngle(level);
//    获得遮罩圆的结束角度
    getEndAngle(level);
}

// 获得出现的小球数量
int GameDataManager::getObsBallNum(int level){
    string key ="ObsNum";
    obsBallNum = std::stoi(csv[level][key]);
    CCLOG("出现的小球数：%d",obsBallNum);
    return obsBallNum;
}

//获得用户的小球数
int GameDataManager::getUserBallNum(int level){
    string key = "UserNum";
    userBallNum = std::stoi(csv[level][key]);
    CCLOG("用户的小球数：%d",userBallNum);
    return userBallNum;
}

//获得旋转方向
int GameDataManager::getRotateDir(int level){
    string key = "RotateDir";
    rotateDir = std::stoi(csv[level][key]);
    if(rotateDir == 1){
        CCLOG("旋转的方向：逆时针");
    }else{
        CCLOG("旋转的方向：顺时针");
    }
    
    return rotateDir;
}

//获得旋转速度
int GameDataManager::getRotateSpeed(int level){
    string key = "RotateSpeed";
    rotateSpeed = std::stoi(csv[level][key]);
    if(rotateDir == 1){
        rotateSpeed = 0-rotateSpeed;
    }
    CCLOG("旋转的速度：%d",rotateSpeed);
    return rotateSpeed;
}

//获得遮罩圆开始角度
int GameDataManager::getStartAngle(int level){
    string key = "StartAngle";
    startAngle = std::stoi(csv[level][key]);
    CCLOG("遮罩圆开始角度：%d",startAngle);
    return startAngle;
}

//获得遮罩圆结束角度
int GameDataManager::getEndAngle(int level){
    string key = "EndAngle";
    endAngle = std::stoi(csv[level][key]);
    CCLOG("遮罩圆结束角度：%d",endAngle);
    return endAngle;
}

//用户数据

//是否初始化
bool GameDataManager::getIsFirstInit(){
    auto isInit = UserDefault::getInstance()->getBoolForKey("_IsInitGameData");
    return isInit;
}

//存储是否初始化
void GameDataManager::setIsFirstInit(bool init){
    UserDefault::getInstance()->setBoolForKey("_IsInitGameData", init);
}

//获得当前已经完成的关卡数
int GameDataManager::getCurrentMaxLevel(){
    auto level = UserDefault::getInstance()->getIntegerForKey("current_max_level");
    return level;
}

//保存当前已经完成的关卡数
void GameDataManager::setCurrentMaxLevel(int level){
    auto maxLevel = UserDefault::getInstance()->getIntegerForKey("current_max_level");
    if(level>=maxLevel){
        UserDefault::getInstance()->setIntegerForKey("current_max_level", level);
    }
}
