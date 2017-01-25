//
// Created by magomed on 24.01.17.
//

#include "SceneFactory.h"

cocos2d::Scene *SceneFactory::createMainMenuScene() {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

Scene *SceneFactory::createGameScene() {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

cocos2d::Scene *SceneFactory::createExitScene() {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = ExitMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

SceneFactory::SceneFactory() {
    ;
}

auto SceneFactory::getInstanse() -> SceneFactory & {
    static SceneFactory object;
    return object;
}
