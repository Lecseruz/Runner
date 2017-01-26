//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_ABSTRACTFACTORY_H
#define MYGAME_ABSTRACTFACTORY_H

#include <cocos2d.h>

class AbstractFactory {
    virtual cocos2d::Scene *createMainMenuScene() = 0;
    virtual cocos2d::Scene *createGameScene() = 0;
    virtual cocos2d::Scene *createGameOverScene() = 0;
};


#endif //MYGAME_ABSTRACTFACTORY_H
