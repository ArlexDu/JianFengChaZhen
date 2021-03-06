//
//  Ball.cpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#include "Ball.hpp"
#include "Defines.h"

Ball::Ball(){
    
}

Ball::~Ball(){
    
}

//创建数字小球

Ball* Ball::create(int num){
    Ball *ball = new Ball();
    ball->initWithFile(RESOURCE_DIR+"MainScene/luoxuanwan.png");
    if(num!=0){
        ball->numTTF = Label::create();
        ball->numTTF->setString(to_string(num));
        ball->numTTF->setPosition(ball->getContentSize()/2);
        ball->addChild(ball->numTTF);
    }else{
        ball->setTexture(RESOURCE_DIR+"MainScene/ball.png");
    }
    
    return ball;
}
