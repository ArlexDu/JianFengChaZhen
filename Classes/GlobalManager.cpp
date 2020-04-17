//
//  GlobalManager.cpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#include "GlobalManager.hpp"

#define PI 3.1415926

USING_NS_CC;

//创建全局单例
GlobalManager* GlobalManager::singleInstance = NULL;

GlobalManager* GlobalManager::getInstance(){
    if(singleInstance == NULL){
        singleInstance = new GlobalManager();
    }
    return singleInstance;
}

GlobalManager::GlobalManager():currentLevel(1),isPlayMusic(true),isPlayEffect(true){
    
}

//得到圆外面的针的位置：在圆周平均分布
CirclePoint GlobalManager::getCirclePoint(int n, int i, Point circleCenter, Point point){
    float a=2*PI/n;
    auto radius = sqrt((point.y-circleCenter.y)*(point.y-circleCenter.y)+(point.x-circleCenter.x)*(point.x-circleCenter.x));
    CirclePoint pos;
    pos.y = radius*sin(a*i)+circleCenter.y;
    pos.x = radius*cos(a*i)+circleCenter.x;
    return pos;
}

//判断两点的距离
float GlobalManager::getTwoPointDistance(Point pos_1, Point pos_2){
    auto distance = pos_1.getDistance(pos_2);
    return distance;
}
