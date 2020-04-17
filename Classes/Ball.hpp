//
//  Ball.hpp
//  MyGame
//
//  Created by arlex on 2020/4/16.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "cocos2d.h"

USING_NS_CC;

class Ball:public Sprite{
public:
    Ball();
    ~Ball();
    
    //创建小球
    static Ball* create(int num=0);
    
    Label* numTTF;
};

#endif /* Ball_hpp */
