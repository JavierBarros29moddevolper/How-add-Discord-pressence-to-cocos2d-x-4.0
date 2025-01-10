#ifndef __CUSTOMSCENE_H__
#define __CUSTOMSCENE_H__

#include "cocos2d.h"

class CustomScene : public cocos2d::Scene {

static cocos2d::Scene* createScene();
~CustomScene();
virtual bool init();
void update(float dt);

CREATE_FUNC(CustomScene);

};


#endif ! // _CUSTOMSCENE_H_