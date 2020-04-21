//
//  SimpleAudioEngine.hpp
//  MyGame
//
//  Created by arlex on 2020/4/20.
//

#ifndef SimpleAudioEngine_hpp
#define SimpleAudioEngine_hpp

#include "cocos2d.h"
#include "GlobalManager.hpp"
#include "SimpleAudioEngine.hpp"

class GameMusic{
public:
    //播放音乐
    static void playMusic(const char *music, bool loop=false);
    //播放音效
    static void playEffect(const char *effect,bool loop=false);
    //停止音乐
    static void stopMusic();
    //停止音效
    static void stopAllEffect();
    //暂停音乐
    static void pauseMusic();
    //回复音乐
    static void resumeMusic();
};

#endif /* SimpleAudioEngine_hpp */
