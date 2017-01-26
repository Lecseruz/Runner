//
// Created by magomed on 14.01.17.
//

#include <SceneFactory.h>


auto GameWorldController::setInvisible(Node *node)->void {
    node->setVisible(false);
}

auto GameWorldController::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)-> void {
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW :{
            if (is_jumped()){
                break;
            }
            world->getRunner()->stopActionByTag(11);
            Command *command = new Jump();

            command->execute(world->getRunner());
            delete command;
            break;
        }
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW :{
            if (is_jumped()){
                break;
            }
            world->getRunner()->stopActionByTag(11);
            Command *command = new Duck();
            command->execute(world->getRunner());
            delete command;
            break;
        }
        default: break;
    }
}

auto GameWorldController::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)-> void {
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW :{

            break;
        }
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW : {
            if (is_jumped()) {
                break;
            }
            world->getRunner()->stopActionByTag(33);
            world->createAnimation();
            break;
        }
    }
}

auto GameWorldController::is_jumped()-> bool {
    return world->getRunner()->getPosition().y != Vec2(500, 350).y;
}

GameWorldController::GameWorldController(GameWorld *world):
        world(world)
{
    flag = new bool[world->getPipes().size()];
    for (int i = 0; i < world->getPipes().size(); ++i) {
        flag[i] = false;
    }
    _nextPipe = 0;
    _nextPipeSpawn = 0;

}

auto GameWorldController::get_time_tick() -> double {
    timeval time_;
    gettimeofday(&time_, NULL);
    unsigned long millisecs = (time_.tv_sec * 1000.0) + (time_.tv_usec/1000.0);
    return (double) millisecs;
}

auto GameWorldController::update(float dt)-> void {

    srand(time(NULL));
    double curTimeMillis = get_time_tick();
    if (curTimeMillis > _nextPipeSpawn) {
//        log("spawn: %f", _nextPipeSpawn);
        float randMillisecs = 2 * 1000;
        _nextPipeSpawn = randMillisecs + curTimeMillis;
        Size winSize = Director::getInstance()->getWinSize();
        Obstacle *pipe = world->getPipes().at(_nextPipe);
        _nextPipe++;
        if (_nextPipe == world->getPipes().size()) {
            _nextPipe = 0;
        }

        if (!pipe->isVisible()) {
            auto tmp = pipe;
            world->removeChild(pipe);
            int k = rand() % 2 + 1;
            if (k == 1) {
                pipe = Obstacle::getInstance().createObstacle(ObstacleEnum::PipeDown);
            } else {
                pipe = Obstacle::getInstance().createObstacle(ObstacleEnum::PipeUP);
            }
            pipe->setVisible(true);
            std::replace(world->getPipes().begin(), world->getPipes().end(), tmp, pipe);
            world->addChild(pipe);
        }
        pipe->runAction(Sequence::create(
                MoveBy::create(6.0, Vec2(-winSize.width - pipe->getContentSize().width, 0)),
                CallFuncN::create(this, callfuncN_selector(GameWorldController::setInvisible)),
                NULL // DO NOT FORGET TO TERMINATE WITH NULL (unexpected in C++)
        ));
    }


    int i = 0;
    if (world->getRunner()->getPosition().y == 350 && world->getRunner()->getActionByTag(22) != nullptr &&
        world->getRunner()->getActionByTag(2) == nullptr) {
        world->getRunner()->stopActionByTag(22);
        world->createAnimation();
    }
    for (Sprite *sprite : world->getPipes()) {
        if (checkBoxCollisionTopBottom(world->getRunner(), sprite)) {
            Jump::StopAction(world->getRunner());
            flag[i] = true;
        } else if (checkBoxCollisionLeftBack(world->getRunner(), sprite)) {
            flag[i] = true;
            world->getRunner()->setPosition(Vec2(sprite->getPosition().x - sprite->getBoundingBox().size.width - 20,
                                                 world->getRunner()->getPosition().y));
        } else if (flag[i]) {
            auto moveDown = MoveTo::create(0.5f, Vec2(world->getRunner()->getPosition().x, 350));
            world->getRunner()->runAction(moveDown);
            if (world->getRunner()->getActionByTag(33) == nullptr) {
                world->createAnimation();
            }
            flag[i] = false;
        }
        ++i;
    }
    if (checkBoxCollisionLeftBack(world->getRunner(), world->getSpike()))  {
        GoToExitScene(this);
    }
}

auto GameWorldController::checkBoxCollisionLeftBack(Sprite *box1, Sprite *box2)-> bool {
    Rect box1Rect = box1->getBoundingBox();
    Rect box2Rect = box2->getBoundingBox();

    return box1Rect.intersectsRect(box2Rect);
}

auto GameWorldController::checkBoxCollisionTopBottom(Sprite *box1, Sprite *box2)-> bool {
    Rect box1Rect = box1->getBoundingBox();
    Rect box2Rect = box2->getBoundingBox();

    float y = box2->getPosition().y + box2->getContentSize().height;
    return (!(box1Rect.getMaxX() < box2Rect.getMinX() ||
              box2Rect.getMaxX() < box1Rect.getMinX()) && (box1Rect.getMinY() <= y && box1Rect.getMinY() >= y -10));
}

auto GameWorldController::GoToExitScene(cocos2d::Ref *sender)-> void {
    auto scene = SceneFactory::getInstanse().createGameOverScene();
    scene->getChildByTag(10)->setTag(world->getTime());
    Director::getInstance()->pushScene(TransitionFade::create(0.5, scene));
}









