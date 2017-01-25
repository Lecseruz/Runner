//
// Created by magomed on 14.01.17.
//

#ifndef MYGAME_GAMEWORLDCONTROLLER_H
#define MYGAME_GAMEWORLDCONTROLLER_H

#include "cocos2d.h"
#include "view/GameWorld.h"
#include "Jump.h"
#include "Duck.h"
#include <view/ExitMenuScene.h>

USING_NS_CC;
class GameWorld;
class GameWorldController: public Ref {
public:
    GameWorldController(GameWorld *world);

    ~GameWorldController(){
        delete[] flag;
    }

    auto get_time_tick()->double;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    bool is_jumped();

    bool checkBoxCollisionLeftBack(Sprite *box1, Sprite *box2);

    bool checkBoxCollisionTopBottom(Sprite *box1, Sprite *box2);

    void update(float dt);
private:
    void GoToExitScene( cocos2d::Ref *sender );
    auto setInvisible(Node * node)->void;

    bool *flag;
    GameWorld *world;
    double time_;
    int _nextPipe;
    double _nextPipeSpawn;
};


#endif //MYGAME_GAMEWORLDCONTROLLER_H
