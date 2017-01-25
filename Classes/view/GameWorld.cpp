#include "GameWorld.h"

USING_NS_CC;

void GameWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    controller->onKeyPressed(keyCode, event);
}

void GameWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    controller->onKeyReleased(keyCode, event);
}

// on "init" you need to initialize your instance
bool GameWorld::init()
{
    srand ( time(NULL) );
    if ( !Layer::init() )
    {
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
//    pipes.reserve(KNUMASTEROIDS);
    auto sprite = Sprite::create("my_window1.jpg");
    sprite->setPosition(Vec2(600, 600));
    this->addChild(sprite);
    mySprite = Runner::create("ninja/Run__000.png");
    mySprite->setPosition(Vec2(500, 350));

    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("ninja/runner.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerJump.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerDuck.plist");
    spritecache->addSpriteFramesWithFile("ninja/runnerDead.plist");


    spike_ = Sprite::create("spikes.jpg");
    spike_->setScale(1);
    spike_->setAnchorPoint(Vec2(0.f, 0.f));
    spike_->setPosition(Vec2(0,0));
    this->addChild(spike_);
    mySprite->setScale(0.5);
    this->addChild(mySprite);
    createAnimation();

    this->scheduleUpdate();
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(GameWorld::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameWorld::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    Pipe *pipeDown = Pipe::create("pipe1.png");
    pipeDown->setTag(1);
    pipeDown->setScale(2);
    pipeDown->setVisible(false);
    pipeDown->setPosition(Vec2(winSize.width + pipeDown->getContentSize().width / 2, 400));


    Obstacle::getInstance().addPrototype(ObstacleEnum::PipeDown, pipeDown);

    Pipe *pipeUp = Pipe::create("image2.jpg");
    pipeUp->setTag(2);
    pipeUp->setScale(2);
    pipeUp->setVisible(false);
    pipeUp->setPosition(Vec2(winSize.width + pipeUp->getContentSize().width / 2, 780));

    Obstacle::getInstance().addPrototype(ObstacleEnum::PipeUP, pipeUp);


    for(int i = 0; i < KNUMASTEROIDS; ++i) {
        int k = rand() % 2 + 1;
//        log("%d", k);
        switch(k){
            case 1:{
                pipes.pushBack(Obstacle::getInstance().createObstacle(ObstacleEnum::PipeDown));
                this->addChild(pipes.at(i));
                break;
            }
            case 2: {
                pipes.pushBack( Obstacle::getInstance().createObstacle(ObstacleEnum::PipeUP));
                this->addChild(pipes.at(i));
                break;
            }
            default:
                break;
        }
    }
    controller = std::make_shared<GameWorldController>(this);

    return true;
}

void GameWorld::update(float dt) {
    controller->update(dt);
}

Runner *GameWorld::getRunner() {
    return mySprite;
}

Vector<Obstacle *> &GameWorld::getPipes() {
    return pipes;
}

auto GameWorld::createAnimation()->void {
    if (mySprite->getActionByTag(22) == nullptr) {
        Vector<SpriteFrame *> animNinja;
        animNinja.reserve(10);
        char str[100] = {0};
        for (int i = 0; i < 10; i++) {
            sprintf(str, "Run__00%d.png", i);
            auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);

            animNinja.pushBack(frame);
        }

        auto animation = Animation::createWithSpriteFrames(animNinja, 0.1f);
        auto animate = RepeatForever::create(Animate::create(animation));
        animate->setTag(11);
        mySprite->runAction(animate);
    }
}


Sprite *GameWorld::getSpike() {
    return spike_;
}