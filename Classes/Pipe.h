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
    void setFileName(std::string filename);
    Obstacle* clone();
    static Pipe* create(std::string filename);
};


#endif //MYGAME_PIPE_H
