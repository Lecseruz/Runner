//
// Created by magomed on 14.01.17.
//

#ifndef MYGAME_GAMEWORLDCONTROLLER_H
#define MYGAME_GAMEWORLDCONTROLLER_H

#include "cocos2d.h"
#include "view/GameWorld.h"
#include "Jump.h"
#include "Duck.h"
#include <view/GameOverMenuScene.h>

USING_NS_CC;
class GameWorld;
class GameWorldController: public Ref {
public:
    GameWorldController(GameWorld *world);

    ~GameWorldController(){
        delete[] flag;
    }

    auto get_time_tick()->double;

    auto onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)->void ;

    auto onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)->void;

    auto is_jumped()-> bool;

    auto checkBoxCollisionLeftBack(Sprite *box1, Sprite *box2)-> bool;

    auto checkBoxCollisionTopBottom(Sprite *box1, Sprite *box2)-> bool;

    auto update(float dt)-> void;


private:
    auto GoToExitScene( cocos2d::Ref *sender )-> void;
    auto setInvisible(Node * node)-> void;



    bool *flag;
    GameWorld *world;
    int _nextPipe;
    double _nextPipeSpawn;
};


#endif //MYGAME_GAMEWORLDCONTROLLER_H
