//
// Created by magomed on 13.01.17.
//

#include "Runner.h"




Runner *Runner::create(std::string filename) {
    Runner *sprite = new (std::nothrow) Runner();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

Runner* Runner::create()
{
    Runner *sprite = new (std::nothrow) Runner();
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
