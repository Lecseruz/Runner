//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_PIPE_H
#define MYGAME_PIPE_H

#include <cocos2d.h>
#include <Obstacle.h>
USING_NS_CC;

class Pipe: public Obstacle{
    std::string fileName;
public:
    auto setFileName(std::string filename)-> void;
    auto clone()-> Obstacle*;
    static auto create(std::string filename)-> Pipe*;
};


#endif //MYGAME_PIPE_H
