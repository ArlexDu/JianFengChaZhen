//
//  GameMusic.cpp
//  MyGame
//
//  Created by arlex on 2020/4/20.
//

#include "GameMusic.hpp"
#include "GlobalManager.hpp"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "Defines.h"

USING_NS_CC;
static GameMusic* simpleInstance = NULL;

GameMusic::GameMusic(){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic((RESOURCE_DIR+"Audios/Naruto Main Theme.mp3").c_str());
}

GameMusic::~GameMusic(){
    
}

GameMusic* GameMusic::getInstance(){
    if(simpleInstance == NULL){
        simpleInstance = new GameMusic();
    }
    return simpleInstance;
}

//播放音乐
void GameMusic::playMusic(const char *music,bool loop){
    if(GlobalManager::getInstance()->isPlayMusic){
        if(!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
            CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(music,loop);
            //设置环境音量大小
            CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.1);
        }
    }
}

//播放音效
void GameMusic::playEffect(const char *effect,bool loop){
    if(GlobalManager::getInstance()->isPlayEffect){
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(effect,loop);
    }
}

//停止音乐
void GameMusic::stopMusic(){
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

//停止音效
void GameMusic::stopAllEffect(){
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
}

//暂停音乐
void GameMusic::pauseMusic(){
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//恢复音乐
void GameMusic::resumeMusic(){
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
