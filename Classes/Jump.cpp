//
// Created by magomed on 14.01.17.
//

#include "Jump.h"

void Jump::execute(cocos2d::Sprite *sprite) {
    auto jump = cocos2d::JumpBy::create(2, cocos2d::Vec2(0, 0), 500, 1);
    auto callbackJump = cocos2d::CallFunc::create([](){
//        log("Jumped!");
    });
    createAnimation(sprite);
    auto seq = cocos2d::Sequence::create(jump, callbackJump/*, rotate, callbackRotate*/, nullptr);
    seq->setTag(2);
    // run it
    sprite->runAction(seq);
}

auto Jump::createAnimation(cocos2d::Sprite *sprite) -> void {
    cocos2d::Vector<cocos2d::SpriteFrame*> animNinja;
    animNinja.reserve(10);
    char str[100] = {0};
    for(int i = 0; i < 10; i++)
    {
        sprintf(str,"Jump__00%d.png",i);
        auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);

        animNinja.pushBack(frame);
    }

    auto animation = cocos2d::Animation::createWithSpriteFrames(animNinja, 0.2f);
    auto animate = cocos2d::RepeatForever::create(cocos2d::Animate::create(animation));
    animate->setTag(22);
    sprite->runAction(animate);
}

auto Jump::StopAction(cocos2d::Sprite *sprite)->void {
    sprite->stopActionByTag(2);
    sprite->stopActionByTag(22);
}
