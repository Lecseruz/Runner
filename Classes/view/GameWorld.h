#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "controller/GameWorldController.h"
#include <ctime>
#include <Runner.h>
#include <Pipe.h>

USING_NS_CC;

#define KNUMASTEROIDS 4
class GameWorldController;
class GameWorld : public cocos2d::Layer
{
public:

    auto onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)-> void;

    auto onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)-> void;

    virtual auto init()-> bool;

    auto update(float dt)-> void;

    CREATE_FUNC(GameWorld);

    auto getPipes()-> Vector<Obstacle *> &;

    auto getRunner()-> Runner*;

    auto  getSpike()->Sprite*;

    auto getLabel()-> Label *;

    auto getTime()->int;

    auto createAnimation()->void;

    auto TimeMethod(float dt)-> void;
private:

    float time_;

    std::shared_ptr<GameWorldController> controller;

    Vector<Obstacle *> pipes;

    cocos2d::Label *label;

    Runner *mySprite;

    Sprite *spike_;

};

#endif // __HELLOWORLD_SCENE_H_