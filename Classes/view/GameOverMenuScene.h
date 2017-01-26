//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_EXITMENUSCENE_H
#define MYGAME_EXITMENUSCENE_H

#include <cocos2d.h>
#include <Runner.h>
#include <view/GameWorld.h>




class GameOverScene : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual auto init()-> bool;

    auto update(float dt)-> void;

    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
private:

    auto ExitGame(cocos2d::Ref *sender )-> void;
    auto GoToGameScene( cocos2d::Ref *sender )-> void;

    cocos2d::Label *myLabel;
    Runner *mySprite;;
    auto createAnimation(cocos2d::Sprite *)->void;
};


#endif //MYGAME_EXITMENUSCENE_H
