#include "CustomScene.h"
#include "DiscordPressence.h"

USING_NS_CC;

cocos2d::Scene* CustomScene::createScene() {
    return CustomScene::create();
}

CustomScene::~CustomScene()
{
    DiscordPressence::getInstance()->shutdown();
}

bool CustomScene::init() {
    if (!Scene::init()) return false;

    if (DiscordPressence::getInstance()->init()) {
     DiscordPressence::getInstance()->updatePressence("state", "details");
    }

    return true;

}

void CustomScene::update(float dt) {
  DiscordPressence::getInstance()->tick();
}
