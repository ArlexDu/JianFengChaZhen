//
//  GameMainScene.hpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#ifndef GameMainScene_hpp
#define GameMainScene_hpp

#include "cocos2d.h"
#include "Ball.hpp"
#include "Defines.h"

USING_NS_CC;

//extern可以置于变量或者函数前，以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。此外extern也可用来进行链接指定
//extern LanguageType type;

class GameMainScene:public Layer{
public:
    GameMainScene();
    ~GameMainScene();
    
    //新建场景
    static Scene* createScene();
    
    //create方法
    CREATE_FUNC(GameMainScene);
    
    //初始化
    virtual bool init();
    //触摸开始方法
    bool onTouchBegan(Touch* touch,Event* event);
    //触摸移动方法
    void onTouchMoved(Touch* touch,Event* event);
    //触摸结束方法
    void onTouchEnded(Touch* touch,Event* event);
    //刷新游戏
    void update(float dt);
    
    void onKeyReleased(EventKeyboard::KeyCode keycode,Event* event);
public:
    //绘制场景
    void drawScene();
    //初始化玩家小球
    void initUserBall(int num);
    //绘制遮罩圆（以Y轴为0角度）
    //参数： 绘制的坐标，开始的角度，终止的角度，内部圆半径，外部圆半径，绘制的颜色
    void drawCoverCircle(Vec2& point, int startAngle, int endAngle, int radiusSmall, int radiusBig, Color4F& color);
    //将玩家小球加入旋转
    void addUserBallToCircle(Ball* ball);
    //检测小区是否碰撞
    void checkIsBallCollision(Ball* userBall, Ball* circleBall);
    //获得旋转动作
    ActionInterval *getCircleAction(float speed);
    //创建失败层
    void createFailedLayer();
    //创建胜利层
    void createSuccessLayer();
    //绘制飞行小球
    void createFlyBall();
    //游戏暂停按钮
    void onPauseBtnPressed(Ref* pSender);
    //点击显示辅助线
    void onAuxiliaryLineBtnPressed(Ref* pSender);
    //帮助按钮
    void onHelpBtnPressed(Ref* pSender);
private:
    //旋转速度（度/秒）
    float speed;
    //关卡用户小球个数
    int userBallNum;
    //中心圆
    Sprite* circle;
    //旋转动作
    ActionInterval* rotate;
    //所有小球列表
    std::vector<Ball*> ballList;
    //玩家小球列表
    std::vector<Ball*> userBallList;
    //飞行小球
    Sprite *flyBall;
    float flyBallX;
    float flyBallY;
    bool isBallCollision;
    bool isCanTouch;
    bool isFlyBallCollision;
};

#endif /* GameMainScene_hpp */
