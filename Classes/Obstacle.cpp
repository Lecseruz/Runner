//
// Created by magomed on 24.01.17.
//

#include "Obstacle.h"

void Obstacle::addPrototype(ObstacleEnum obstacleNum, Obstacle *obstacle) {
    prototipesNum.push_back(obstacleNum);
    prototipes.pushBack(obstacle);
}

Obstacle *Obstacle::createObstacle(ObstacleEnum obstacleNum) {

    if (std::find(prototipesNum.begin(), prototipesNum.end(), obstacleNum) != prototipesNum.end()) {
        auto iter = std::find(prototipesNum.begin(), prototipesNum.end(), obstacleNum);

        return prototipes.at(iter - prototipesNum.begin())->clone();
    }
    return nullptr;
}


Obstacle::~Obstacle() {
    ;
}
