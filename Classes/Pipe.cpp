//
// Created by magomed on 24.01.17.
//

#include "Pipe.h"

Pipe *Pipe::create(std::string filename) {
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

Obstacle *Pipe::clone() {
    Pipe *pipe = create(fileName);
    pipe->setScale(this->getScale());
    pipe->setPosition(this->getPosition());
    pipe->setTag(this->getTag());
    return pipe;
}

void Pipe::setFileName(std::string filename) {
    this->fileName = filename;
}
