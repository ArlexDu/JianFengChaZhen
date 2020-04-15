//
//  GameDataManager.hpp
//  MyGame
//
//  Created by arlex on 2020/4/15.
//

#ifndef GameDataManager_hpp
#define GameDataManager_hpp

#include "cocos2d.h"
#include "CSVParser.hpp"

USING_NS_CC;
using namespace CSVParser;

class GameDataManager{

public:
    static GameDataManager* getInstance();
    static GameDataManager* singleInstance;
    GameDataManager();
    ~GameDataManager();
    virtual bool init();

    //载入游戏数据
    void loadGameData(int level);
    //获得出现的小球数
    int getObsBallNum(int level);
    //获得用户的小球数
    int getUserBallNum(int level);
    //获得旋转的速度
    int getRotateSpeed(int level);
    //获得旋转的方向
    int getRotateDir(int level);
    //获得遮罩圆开始角度
    int getStartAngle(int level);
    //获得遮罩圆结束的角度
    int getEndAngle(int level);
    
    //获得是否初始化
    bool getIsFirstInit();
    //存储是否初始化
    void setIsFirstInit(bool init);
    //获得当前已经完成的关卡数
    int getCurrentMaxLevel();
    //保存当前已经完成的关卡数
    void setCurrentMaxLevel(int level);
    
public:
    //初始化出现的小球数
    int obsBallNum;
    //用户的小球数
    int userBallNum;
    //旋转的速度
    int rotateSpeed;
    //旋转的方向
    int rotateDir;
    //总行数
    int totalRow;
    //遮罩圆开始角度
    int startAngle;
    //遮罩圆结束角度
    int endAngle;
private:
    Csv csv;
    
};

#endif /* GameDataManager_hpp */
