//
// Created by magomed on 24.01.17.
//

#include "Obstacle.h"

auto Obstacle::addPrototype(ObstacleEnum obstacleNum, Obstacle *obstacle)-> void {
    prototipesNum.push_back(obstacleNum);
    prototipes.pushBack(obstacle);
}

auto Obstacle::createObstacle(ObstacleEnum obstacleNum)-> Obstacle * {

    if (std::find(prototipesNum.begin(), prototipesNum.end(), obstacleNum) != prototipesNum.end()) {
        auto iter = std::find(prototipesNum.begin(), prototipesNum.end(), obstacleNum);

        return prototipes.at(iter - prototipesNum.begin())->clone();
    }
    return nullptr;
}


Obstacle::~Obstacle() {
    ;
}
