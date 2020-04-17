//
//  GameMainScene.cpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#include "GameMainScene.hpp"
#include "GameDataManager.hpp"
#include "GameMenuScene.hpp"
#include "Defines.h"
#include "GlobalManager.hpp"

GameMainScene::GameMainScene():speed(0),userBallNum(0),rotate(NULL),isBallCollision(false),isCanTouch(false){
    
}

GameMainScene::~GameMainScene(){}

//新建场景
Scene* GameMainScene::createScene(){
    Scene *scene = Scene::create();
    Layer *layer = GameMainScene::create();
    scene->addChild(layer);
    return scene;
}

//初始化
bool GameMainScene::init(){
    if(!Layer::init()){
        return false;
    }
    ballList.clear();
    speed = GameDataManager::getInstance()->rotateSpeed;
    rotate = getCircleAction(speed);
    
    //绘制场景
    drawScene();
    //绘制玩家小球
    userBallNum = GameDataManager::getInstance()->userBallNum;
    initUserBall(userBallNum);
    
    //创建一个触摸监听
    auto touchListener = EventListenerTouchOneByOne::create();
    //向下传递触摸事件
    touchListener->setSwallowTouches(false);
    touchListener->onTouchBegan = CC_CALLBACK_2(GameMainScene::onTouchBegan,this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameMainScene::onTouchMoved,this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameMainScene::onTouchEnded,this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(GameMainScene::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    //注册捕捉监听
    auto listenerKeyPad = EventListenerKeyboard::create();
    listenerKeyPad->onKeyReleased=CC_CALLBACK_2(GameMainScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyPad, this);
    
    //每一帧执行update函数
    scheduleUpdate();
    return true;
}

//触摸开始方法
bool GameMainScene::onTouchBegan(Touch *touch, Event *event){
    if(!isCanTouch){
        return false;
    }
    if(isBallCollision){
        CCLOG("change ball collision");
        return false;
    }
    if(userBallList.size()>0){
        //vector at相比于[]会增加范围检查，如果索引超出vector的range则抛出异常
        //我觉得这里可以吧两个action放在一个sequence里面
        userBallList.at(0)->runAction(Sequence::create(
                                                       MoveTo::create(0.2f, Point(360,620)),
                                                       NULL));
        userBallList.at(0)->runAction(Sequence::create(
                                                       CallFunc::create(CC_CALLBACK_0(GameMainScene::addUserBallToCircle, this,userBallList.at(0))),
                                                       NULL));
    }
    return true;
}

//触摸移动方法
void GameMainScene::onTouchMoved(Touch *touch, Event *event){
    
}

//触摸结束方法
void GameMainScene::onTouchEnded(Touch *touch, Event *event){
    
}

//敲击空格键显示游戏菜单页面
void GameMainScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event){
    if(keycode == EventKeyboard::KeyCode::KEY_SPACE){
        Director::getInstance()->replaceScene(GameMenuScene::createScene());
    }
}

//刷新游戏
void GameMainScene::update(float dt){
    //刷新玩家小球位置
    auto max = userBallList.size()>=4?4:userBallList.size();
    //只显示四个玩家的小球，其余的隐藏
    for(unsigned int i=0;i<max;i++){
        auto ball = userBallList.at(i);
        if(!ball){
            continue;
        }
        ball->setPosition(WINSIZE.width/2,POSY-8*40 -WINSIZE.width*0.08*(i+1));
        ball->setVisible(true);
    }
    //检测是否碰撞，如果碰撞，游戏结束
    if(isBallCollision){
        circle->stopAction(rotate);
        //停止update函数
        unscheduleUpdate();
        createFailedLayer();
        return;
    }
    if(userBallNum == 0){
        unscheduleUpdate();
        createSuccessLayer();
    }
}

//绘制场景
void GameMainScene::drawScene(){
    //绘制游戏背景
    auto bg = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/MainScene/bg.png");
    bg->setPosition(WINSIZE/2);
    float spy = bg->getContentSize().height;
    bg->setScale(WINSIZE.height/spy, WINSIZE.height/spy);
    this->addChild(bg);
    
    //关卡
    auto level = Label::create();
    level->setString(StringUtils::format("第 %d 关",GlobalManager::getInstance()->currentLevel));
    level->setPosition(WINSIZE.width/2,WINSIZE.height-83);
    this->addChild(level);
    
    //投影
    /*auto shadow = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/MainScene/shadow.png");
    shadow->setPosition(WINSIZE.width/2,WINSIZE.height/2-500);
    this->addChild(shadow);
    //moveBy创建一个移动的动作，参数1：移动到目标需要的时间，参数2：目标坐标
    shadow->runAction(MoveBy::create(0.3f, Point(0,630)));*/
    
    //绘制中心圆
    circle = Sprite::create("/Users/arlex/Documents/Project/MyGame/Resources/MainScene/circle.png");
    circle->setPosition(WINSIZE.width/2,POSY);
    //中心圆的大小应该是屏幕的1/5
    float circleSpx = WINSIZE.width*0.2f/circle->getContentSize().width;
    //CCLOG("circle scale is %f",circleSpx);
    //CCLOG("screen width is %f",WINSIZE.width);
    //CCLOG("screen height is %f",WINSIZE.height);
    circle->setScale(circleSpx, circleSpx);
    this->addChild(circle,1);
    circle->runAction(rotate);
    CCLOG("circle x: %f, y: %f",circle->getPosition().x,circle->getPosition().y);
    //Sequence运动序列函数，表示按照什么顺序执行
    isCanTouch = true;
    /*circle->runAction(Sequence::create(
                                       MoveBy::create(0.3f, Point(0,700)),
                                       //这个是lambda匿名函数么？
                                       CallFunc::create([&](){isCanTouch = true;}),
                                       NULL));*/
    
    //绘制关卡障碍小球,就是外面围绕中心球转动的小球
    auto obsNum = GameDataManager::getInstance()->obsBallNum;
    for(int i=0;i<obsNum;i++){
        auto ball = Ball::create();
        auto pos = GlobalManager::getInstance()->getCirclePoint(obsNum, i, circle->getPosition(), Point(circle->getPosition().x,circle->getPosition().y- RADIUS));
        float spx = ball->getContentSize().width;
        //设置小球大小为屏幕宽度的1/20
        //因为障碍小球的在circle里面也会随着circle一起缩放，所以这里需要除以circle的缩放
        ball->setScale(WINSIZE.width*0.05/spx/circleSpx, WINSIZE.width*0.05/spx/circleSpx);
        //因为ball在circle下面，所以需要将ball的坐标从世界左边转换为circle的局部坐标
        ball->setPosition(circle->convertToNodeSpace(Point(pos.x,pos.y)));
        circle->addChild(ball);
        ballList.push_back(ball);
        
        //创建DrawNode:画线段连接中心圆与障碍小球
        DrawNode* drawNode = DrawNode::create();
        circle->addChild(drawNode,0);
        //懂了，circle内的局部坐标系圆点在circle左上角,所以circle本身的坐标不是（0，0）,而是circle->getContentSize()/2
        //ball->getPostion()获得是ball的局部坐标
        drawNode->drawSegment(circle->getContentSize()/2, ball->getPosition(), 1, Color4F(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f,1));
    }
    
    //这个应该是画辅助虚线
    DrawNode* drawDot = DrawNode::create();
    this->addChild(drawDot,10,"drawdot");
    for(int i=0;i<8;i++){
        drawDot->drawDot(Vec2(WINSIZE.width/2,POSY-40*i), 5,  Color4F(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f,1));
    }
    drawDot->setVisible(true);
    
    /*//暂停按钮
    auto pause=MenuItemImage::create(
                                "pause.png",
                                "pause.png",
                                CC_CALLBACK_1(GameMainScene::onPauseBtnPressed, this));
    pause->setPosition(80,WINSIZE.height-80);
    
    //辅助线按钮
    auto auxiliary=MenuItemImage::create(
                                     "auxiliary.png",
                                     "auxiliary.png",
                                     CC_CALLBACK_1(GameMainScene::onAuxiliaryLineBtnPressed, this));
    auxiliary->setPosition(640,WINSIZE.height-80);
    
    //帮助按钮
    auto help=MenuItemImage::create(
                                         "help.png",
                                         "help.png",
                                         CC_CALLBACK_1(GameMainScene::onHelpBtnPressed, this));
    help->setPosition(80,WINSIZE.height-200);
    
    auto menu = Menu::create(pause,auxiliary,help,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);*/
    
}

//绘制遮罩圆
void GameMainScene::drawCoverCircle(Vec2 &point, int startAngle, int endAngle, int radiusSmall, int radiusBig, Color4F &color){
    
}

//获得旋转动作
ActionInterval* GameMainScene::getCircleAction(float speed){
    //RepeatForever函数：重复执行某一个动作
    //RoateBy:顺时针的转动某一个角度
    auto action = RepeatForever::create(RotateBy::create(1.0f, speed));
    return action;
}

//初始化玩家小球
void GameMainScene::initUserBall(int num){
    for(int i=0;i<num;i++){
        auto ball = Ball::create(num-i);
        float spx = ball->getContentSize().width;
        //设置小球大小为屏幕宽度的1/20
        ball->setScale(WINSIZE.width*0.05/spx, WINSIZE.width*0.05/spx);
        ball->setPosition(WINSIZE.width/2,POSY-8*40-WINSIZE.width*0.08*(i+1));
        if(i<=4){
            ball->setVisible(true);
        }else{
            ball->setVisible(false);
        }
        this->addChild(ball);
        userBallList.push_back(ball);
        }
}

//将玩家小球加入旋转
void GameMainScene::addUserBallToCircle(Ball *ball){
    //创建一个元素
    auto newBall = Ball::create(stoi(ball->numTTF->getString()));
    float spx = newBall->getContentSize().width;
    //设置小球大小为屏幕宽度的1/20
    //因为障碍小球的在circle里面也会随着circle一起缩放，所以这里需要除以circle的缩放
    float circleSpx = WINSIZE.width*0.2f/circle->getContentSize().width;
    newBall->setScale(WINSIZE.width*0.05/spx/circleSpx, WINSIZE.width*0.05/spx/circleSpx);
    //convertToNodeSpace函数：把世界坐标转变为物体坐标，因为这里需要把新的小球加入circle的子节点，所以用circle的相对坐标设置
    CCLOG("circle x: %f, y: %f",circle->getPosition().x,circle->getPosition().y);
    newBall->setPosition(circle->convertToNodeSpace(Point(WINSIZE.width/2,circle->getPosition().y-RADIUS)));
    circle->addChild(newBall);
    
    //创建DrawNode：新的小球和圆球的连线
    DrawNode* drawNode = DrawNode::create();
    circle->addChild(drawNode,-1);
    drawNode->drawSegment(circle->getContentSize()/2, newBall->getPosition(), 1, Color4F(142.0f/255.0f,72.0f/255.0f,12.0f/255.0f,1));
    
    for(unsigned int i=0;i<ballList.size();i++){
        checkIsBallCollision(newBall, ballList.at(i));
    }
    ballList.push_back(newBall);
    
    //清空
    ball->removeFromParentAndCleanup(true);
    userBallNum--;
    CCLOG("userBallNum is %d",userBallNum);
    //删除第一个元素
    userBallList.erase(userBallList.begin(),userBallList.begin()+1);
}

//检测小球是否碰撞
void GameMainScene::checkIsBallCollision(Ball *userBall, Ball *circleBall){
    float distance =GlobalManager::getInstance()->getTwoPointDistance(userBall->getPosition(), circleBall->getPosition());
    if(distance<=WINSIZE.width*0.05f){
        isBallCollision = true;
        return;
    }
}

//创建失败层
void GameMainScene::createFailedLayer(){
    CCLOG("end game");
}

//创建胜利层
void GameMainScene::createSuccessLayer(){
    CCLOG("is ball collision is %d",isBallCollision);
    CCLOG("success game");
}

//游戏暂停按钮
void GameMainScene::onPauseBtnPressed(Ref *pSender){
    
}

//游戏显示辅助线
void GameMainScene::onAuxiliaryLineBtnPressed(Ref *pSender){
    
}

//游戏帮助按钮
void GameMainScene::onHelpBtnPressed(Ref *pSender){
    
}

//绘制飞行小球
void GameMainScene::createFlyBall(){
    flyBall = Ball::create();
    flyBall->setPosition(Vec2(-20,300));
    this->addChild(flyBall);
    flyBallX = flyBall->getPosition().x;
    flyBallY = flyBall->getPosition().y;
}
