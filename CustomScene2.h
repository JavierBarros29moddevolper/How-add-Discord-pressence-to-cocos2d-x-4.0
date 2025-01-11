#ifndef __CUSTOMSCENE2_H__
#define __CUSTOMSCENE2_H__

#include "cocos2d.h"

class CustomScene2 : public cocos2d::Scene {

static cocos2d::Scene* createScene();
~CustomScene2();
virtual bool init();
void update(float dt);

CREATE_FUNC(CustomScene2);

};


#endif ! // _CUSTOMSCENE_H_