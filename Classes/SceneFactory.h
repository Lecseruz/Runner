//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_SCENEFACTORY_H
#define MYGAME_SCENEFACTORY_H

#include <AbstractFactory.h>
#include <cocos2d.h>
#include <view/MainMenuScene.h>
#include <view/GameWorld.h>
#include <view/GameOverMenuScene.h>


class SceneFactory: public AbstractFactory {
public:
    auto createMainMenuScene()->cocos2d::Scene *;
    auto createGameScene()->cocos2d::Scene *;
    auto createGameOverScene()->cocos2d::Scene *;
    static auto getInstanse()->SceneFactory&;
private:

    SceneFactory();
    SceneFactory(const SceneFactory&);
    SceneFactory operator=(const SceneFactory& );

};


#endif //MYGAME_SCENEFACTORY_H
