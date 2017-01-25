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

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    virtual bool init();

    void update(float dt);

    CREATE_FUNC(GameWorld);

    Vector<Obstacle *> &getPipes();

    Runner* getRunner();

    Sprite* getSpike();

    auto createAnimation()->void;
private:

    std::shared_ptr<GameWorldController> controller;

    Vector<Obstacle *> pipes;

    Runner *mySprite;

    Sprite *spike_;

};

#endif // __HELLOWORLD_SCENE_H_