#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public Layer{
public:
    //CREATE
    static Scene* createScene();
	void nextScene(Ref* pSender);

    //INIT
    virtual bool init();
    
    //CALLBACK
    void menuCloseCallback(Ref* pSender);
    
	CREATE_FUNC(MainScene);
};

#endif // __MAIN_SCENE_H__
