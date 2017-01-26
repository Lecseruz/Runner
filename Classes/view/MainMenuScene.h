//
// Created by magomed on 23.01.17.
//

#ifndef MYGAME_MAINMENUSCENE_H
#define MYGAME_MAINMENUSCENE_H

#include <cocos2d.h>
#include <view/GameWorld.h>
#include "SimpleAudioEngine.h"

class MainMenuScene : public cocos2d::Layer
{
public:

//    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual auto init()-> bool;

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
    auto ExitGame(cocos2d::Ref *sender )-> void;
    auto GoToGameScene( cocos2d::Ref *sender )-> void;

};

#endif //MYGAME_MAINMENUSCENE_H
