//
// Created by magomed on 14.01.17.
//

#ifndef MYGAME_JUMP_H
#define MYGAME_JUMP_H


#include "Command.h"
#include <cocos2d.h>

class Jump: public Command {
public:
    auto execute(cocos2d::Sprite *sprite)->void;
    auto createAnimation(cocos2d::Sprite *sprite)->void;
    static auto StopAction(cocos2d::Sprite *sprite)->void;
};


#endif //MYGAME_JUMP_H
