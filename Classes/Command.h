//
// Created by magomed on 14.01.17.
//

#ifndef MYGAME_COMMAND_H
#define MYGAME_COMMAND_H

#include <cocos2d.h>

class Command {
public:
    virtual auto execute(cocos2d::Sprite *sprite)->void = 0;
    virtual ~Command() {};
};


#endif //MYGAME_COMMAND_H
