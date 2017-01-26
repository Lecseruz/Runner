#include "GameWorld.h"

USING_NS_CC;

auto GameWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)-> void
{
    controller->onKeyPressed(keyCode, event);
}

auto GameWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)-> void
{
    controller->onKeyReleased(keyCode, event);
}

// on "init" you need to initialize your instance
auto GameWorld::init()-> bool
{
    srand ( time(NULL) );
    if ( !Layer::init() )
    {
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
    auto sprite = Sprite::create("my_window1.jpg");
    sprite->setPosition(Vec2(600, 600));
    this->addChild(sprite);

    label = Label::create("0", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(winSize.width / 2, winSize.height -  label->getContentSize().height));
    time_ = 0;

    mySprite = Runner::create("ninja/Run__000.png");
    mySprite->setPosition(Vec2(500, 350));

    spike_ = Sprite::create("spikes.jpg");
    spike_->setScale(1);
    spike_->setAnchorPoint(Vec2(0.f, 0.f));
    spike_->setPosition(Vec2(0,0));
    this->addChild(spike_);
    mySprite->setScale(0.5);
    this->addChild(mySprite);
    createAnimation();

    this->schedule(schedule_selector(GameWorld::TimeMethod), 0.01);

    this->scheduleUpdate();
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(GameWorld::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameWorld::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);




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
    this->addChild(label, 1);
    return true;
}

auto GameWorld::update(float dt)-> void {
    controller->update(dt);
}

auto GameWorld::getRunner()-> Runner * {
    return mySprite;
}

auto GameWorld::getPipes()-> Vector<Obstacle *> & {
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


auto GameWorld::getSpike()-> Sprite * {
    return spike_;
}

auto GameWorld::getLabel() -> Label * {
    return label;
}

auto GameWorld::TimeMethod(float dt)-> void {
    time_ += dt;
    cocos2d::__String *timeToDisplay = cocos2d::__String::createWithFormat("%.2f", time_);
    label->setString(timeToDisplay->getCString());
}

auto GameWorld::getTime() -> int {
    return time_;
}
