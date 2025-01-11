#include "CustomScene2.h"
#include "DiscordPressence.h"

USING_NS_CC;

cocos2d::Scene* CustomScene2::createScene() {
    return CustomScene2::create();
}

CustomScene2::~CustomScene2()
{
}

bool CustomScene2::init() {
    if (!Scene::init()) return false;

    DiscordPressence::getInstance()->updatePressence("state", "details");

    return true;

}

void CustomScene2::update(float dt) {
  DiscordPressence::getInstance()->tick();
}