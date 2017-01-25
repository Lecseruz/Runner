//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_OBSTACLE_H
#define MYGAME_OBSTACLE_H

#include <cocos2d.h>

enum ObstacleEnum { PipeDown, PipeUP};
class Obstacle : public cocos2d::Sprite {
public:
    virtual Obstacle* clone() {
        return nullptr;
    };
    virtual ~Obstacle();
    Obstacle* createObstacle(ObstacleEnum obstacleNum);
    void addPrototype(ObstacleEnum obstacleNum, Obstacle *obstacle);
    static Obstacle &getInstance() {
        static Obstacle object;
        return object;
    }

protected:
    Obstacle() {}

private:
    std::vector<ObstacleEnum> prototipesNum;
    cocos2d::Vector<Obstacle *> prototipes;
};



#endif //MYGAME_OBSTACLE_H
