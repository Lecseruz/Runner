//
// Created by magomed on 24.01.17.
//

#include <SceneFactory.h>
#include "GameOverMenuScene.h"


auto GameOverScene::init()-> bool {
    srand ( time(NULL) );
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto sprite = cocos2d::Sprite::create("game_over.jpg");
    auto sprite1 = cocos2d::Sprite::create("my_window1.jpg");

    sprite->setPosition(1000, 700);
    mySprite = Runner::create("ninja/Run__000.png");
    mySprite->setPosition(1000, 350);
    mySprite->setScale(0.5);
    std::string a = "Your scored points: ";
    cocos2d::__String *point = cocos2d::__String::createWithFormat("%d", 0);
    myLabel = Label::createWithSystemFont(point->getCString(), "Arial", 32);
    myLabel->setPosition(Vec2(visibleSize.width / 2, 600));
    myLabel->enableOutline(Color4B(100, 50, 100, 100));
    createAnimation(mySprite);
    sprite1->setPosition(cocos2d::Vec2(600, 600));
    this->addChild(sprite1);
    this->addChild(mySprite);
    this->addChild(sprite);
    this->addChild(myLabel);
    this->scheduleUpdate();
    auto button = MenuItemImage::create("Retry Button.png", "Retry Button Clicked.png",
                                           CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
    button->setPosition( Point( visibleSize.width / 2 + origin.x, (visibleSize.height / 4 - 100) + origin.y ) );

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(GameOverScene::ExitGame, this));
    closeItem->setPosition( Point(visibleSize.width / 2 , visibleSize.height / 4 - 200));
    closeItem->setScale(2);

    auto menu = Menu::create( button, closeItem, NULL );
    menu->setPosition( Point::ZERO );

    this->addChild( menu );
    return true;
}

auto GameOverScene::createAnimation(cocos2d::Sprite *mySprite) -> void {
    cocos2d::Vector<cocos2d::SpriteFrame*> animNinja;
    animNinja.reserve(10);
    char str[100] = {0};
    for(int i = 0; i < 10; i++)
    {
        sprintf(str,"Dead__00%d.png",i);
        auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);

        animNinja.pushBack(frame);
    }

    auto animation = cocos2d::Animation::createWithSpriteFrames(animNinja, 0.5f);
    auto animate = cocos2d::RepeatForever::create(cocos2d::Animate::create(animation));
    mySprite->runAction(animate);
}

auto GameOverScene::update(float dt)-> void  {
    cocos2d::__String *point = cocos2d::__String::createWithFormat("%d", getTag());
    std::string a = "Your scored points: ";
    myLabel->setString(a + point->getCString());
}

auto GameOverScene::ExitGame(cocos2d::Ref *sender )-> void
{
    Director::getInstance()->end();
}

auto GameOverScene::GoToGameScene( cocos2d::Ref *sender ) -> void
{
    Director::getInstance()->replaceScene( TransitionFadeBL::create( 0.5 , SceneFactory::getInstanse().createGameScene()) );
}
