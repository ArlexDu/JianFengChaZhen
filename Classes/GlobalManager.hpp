//
//  GlobalManager.hpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#ifndef GlobalManager_hpp
#define GlobalManager_hpp

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

typedef struct{
    float x;
    float y;
}CirclePoint;

class GlobalManager{
public:
    GlobalManager();
    ~GlobalManager();
    //全局单例
    static GlobalManager* singleInstance;
    //返回全局单例
    static GlobalManager* getInstance();
    //圆内接多边形顶点
    CirclePoint getCirclePoint(int n, int i,Point circleCenter,Point point);
    //判断两点的距离
    float getTwoPointDistance(Point pos_1, Point pos_2);
    //绘制半圆
    void drawSolidSector(const Vec2& origin,const Vec2& beginVec, const float radius1,const float radius2, const float radian, const int segments, const Color4F& color);
    //当前关卡
    int currentLevel;
    //是否播放音乐
    bool isPlayMusic;
    //是否播放音效
    bool isPlayEffect;
};

#endif /* GlobalManager_hpp */
