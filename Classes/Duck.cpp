//
// Created by magomed on 14.01.17.
//

#include "Duck.h"

void Duck::execute(cocos2d::Sprite *sprite) {
    createAnimation(sprite);
}

auto Duck::createAnimation(cocos2d::Sprite *sprite) -> void {
    cocos2d::Vector<cocos2d::SpriteFrame*> animNinja;
    animNinja.reserve(10);
    char str[100] = {0};
    for(int i = 0; i < 10; i++)
    {
        sprintf(str,"Slide__00%d.png",i);
        auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);

        animNinja.pushBack(frame);
    }

    auto animation = cocos2d::Animation::createWithSpriteFrames(animNinja, 0.1f);
    auto animate = cocos2d::RepeatForever::create(cocos2d::Animate::create(animation));
    animate->setTag(33);
    sprite->runAction(animate);
}

auto Duck::StopAction(cocos2d::Sprite *sprite) -> void {
    sprite->stopActionByTag(33);
}
