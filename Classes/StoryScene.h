#ifndef __STORY_SCENE_H__
#define __STORY_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class StoryScene : public Layer{
public:
    //CREATE
    static Scene* createScene();
	void nextScene(Ref* pSender);

    //INIT
    virtual bool init();
    
    //CALLBACK
    void menuCloseCallback(Ref* pSender);
    
	CREATE_FUNC(StoryScene);
};

#endif // __STORY_SCENE_H__
