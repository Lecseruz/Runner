//
// Created by magomed on 24.01.17.
//

#include "SceneFactory.h"

auto SceneFactory::createMainMenuScene()-> cocos2d::Scene * {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

auto SceneFactory::createGameScene()-> Scene * {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

auto SceneFactory::createGameOverScene()-> cocos2d::Scene * {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();
    layer->setTag(10);
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
