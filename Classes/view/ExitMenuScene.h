//
// Created by magomed on 24.01.17.
//

#ifndef MYGAME_EXITMENUSCENE_H
#define MYGAME_EXITMENUSCENE_H

#include <cocos2d.h>
#include <Runner.h>
#include <view/GameWorld.h>



class ExitMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
//    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(ExitMenuScene);
private:
    void GoToGameScene( cocos2d::Ref *sender );

    Runner *mySprite;;
    auto createAnimation(cocos2d::Sprite *)->void;
};


#endif //MYGAME_EXITMENUSCENE_H
