//
//  GameMusic.hpp
//  MyGame
//
//  Created by arlex on 2020/4/20.
//

#ifndef GameMusic_hpp
#define GameMusic_hpp

#include "cocos2d.h"

class GameMusic{
public:
    GameMusic();
    ~GameMusic();
    static GameMusic* getInstance();
    //播放音乐
    void playMusic(const char *music, bool loop=false);
    //播放音效
    void playEffect(const char *effect,bool loop=false);
    //停止音乐
    void stopMusic();
    //停止音效
    void stopAllEffect();
    //暂停音乐
    void pauseMusic();
    //回复音乐
    void resumeMusic();
};

#endif /* SimpleAudioEngine_hpp */
