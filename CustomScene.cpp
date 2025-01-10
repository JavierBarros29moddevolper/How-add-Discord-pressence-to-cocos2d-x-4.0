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

    auto dcPressence = DiscordPressence::getInstance();
    if (dcPressence->init()) {
     dcPressence->updatePressence("Add your state","Add your details");
    }

    return true;

}

void CustomScene::update(float dt) {
 auto dcPressence = DiscordPressence::getInstance();
   if (dcPressence->core) {
    dcPressence->core->RunCallbacks();
   }
}