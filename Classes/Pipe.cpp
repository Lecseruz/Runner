//
// Created by magomed on 24.01.17.
//

#include "Pipe.h"

auto Pipe::create(std::string filename)-> Pipe * {
    Pipe *sprite = new (std::nothrow) Pipe();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->setFileName(filename);
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

auto Pipe::clone()-> Obstacle * {
    Pipe *pipe = create(fileName);
    pipe->setScale(this->getScale());
    pipe->setPosition(this->getPosition());
    pipe->setTag(this->getTag());
    return pipe;
}

auto Pipe::setFileName(std::string filename)-> void {
    this->fileName = filename;
}
