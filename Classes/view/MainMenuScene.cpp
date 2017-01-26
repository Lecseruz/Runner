//
// Created by magomed on 23.01.17.
//

#include <SceneFactory.h>
#include "MainMenuScene.h"
USING_NS_CC;

auto MainMenuScene::init()-> bool {
    srand ( time(NULL) );
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();


    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("ninja/runner.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerJump.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerDuck.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerDead.plist");

    auto pipeDown = Pipe::create("pipe1.png");
    pipeDown->setTag(1);
    pipeDown->setScale(2);
    pipeDown->setVisible(false);
    pipeDown->setPosition(Vec2(winSize.width + pipeDown->getContentSize().width / 2, 400));


    Obstacle::getInstance().addPrototype(ObstacleEnum::PipeDown, pipeDown);

    auto pipeUp = Pipe::create("image2.jpg");
    pipeUp->setTag(2);
    pipeUp->setScale(2);
    pipeUp->setVisible(false);
    pipeUp->setPosition(Vec2(winSize.width + pipeUp->getContentSize().width / 2, 780));

    Obstacle::getInstance().addPrototype(ObstacleEnum::PipeUP, pipeUp);


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto window = cocos2d::Sprite::create("priroda_05.jpg");
    window->setPosition(1000,500);
    window->setScale(3);
    this->addChild(window);

    auto titleSprite = Sprite::create( "Title.png" );
    titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );

    this->addChild( titleSprite );

    auto button1 = MenuItemImage::create("Play Button.png", "Play Button Clicked.png",
                                           CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    button1->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenuScene::ExitGame, this));
    closeItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 - 200));
    closeItem->setScale(2);

    auto menu = Menu::create( button1, closeItem, NULL );
    menu->setPosition( Point::ZERO );
    this->addChild(menu);

    return true;
}

auto MainMenuScene::ExitGame(cocos2d::Ref *sender )-> void
{
    Director::getInstance()->end();
}
auto MainMenuScene::GoToGameScene( cocos2d::Ref *sender )-> void
{
    Director::getInstance()->replaceScene( TransitionFade::create( 0.5 , SceneFactory::getInstanse().createGameScene() ) );
}

