//
// Created by magomed on 23.01.17.
//

#include <SceneFactory.h>
#include "MainMenuScene.h"
USING_NS_CC;
//
//cocos2d::Scene *MainMenuScene::createScene() {
//    // 'scene' is an autorelease object
//    auto scene = cocos2d::Scene::create();
//
//    // 'layer' is an autorelease object
//    auto layer = MainMenuScene::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);
//
//    // return the scene
//    return scene;
//}

bool MainMenuScene::init() {
    srand ( time(NULL) );
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto window = cocos2d::Sprite::create("priroda_05.jpg");
    window->setPosition(1000,500);
    window->setScale(2);
    this->addChild(window);




    auto titleSprite = Sprite::create( "Title.png" );
    titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );

    this->addChild( titleSprite );

    auto closeItem = MenuItemImage::create("Play Button.png", "Play Button Clicked.png",
                                           CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    closeItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );

    auto menu = Menu::create( closeItem, NULL );
    menu->setPosition( Point::ZERO );

    this->addChild( menu );

    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
    Director::getInstance()->replaceScene( TransitionFade::create( 0.5 , SceneFactory::getInstanse().createGameScene() ) );
}

