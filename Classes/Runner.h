//
// Created by magomed on 13.01.17.
//

#ifndef MYGAME_MYSPRITE_H
#define MYGAME_MYSPRITE_H

#include "cocos2d.h"
#include <iostream>
USING_NS_CC;


class Runner: public Sprite {
public:
    static Runner* create(std::string filename);

    static Runner* create();
};


#endif //MYGAME_MYSPRITE_H
