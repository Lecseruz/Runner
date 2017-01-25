//
// Created by magomed on 14.01.17.
//

#ifndef MYGAME_DUCK_H
#define MYGAME_DUCK_H


#include "Command.h"

class Duck: public Command {
public:
    auto execute(cocos2d::Sprite *sprite)->void;
    auto createAnimation(cocos2d::Sprite *sprite)->void;
    static auto StopAction(cocos2d::Sprite *sprite)->void;
};


#endif //MYGAME_DUCK_H
