//
// Created by magomed on 23.01.17.
//

#ifndef MYGAME_MAINMENUSCENE_H
#define MYGAME_MAINMENUSCENE_H

#include <cocos2d.h>
#include <view/GameWorld.h>

class MainMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
//    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
    void GoToGameScene( cocos2d::Ref *sender );

};

#endif //MYGAME_MAINMENUSCENE_H
