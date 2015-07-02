#ifndef __END_SCENE_H__
#define __END_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class EndScene : public Layer{
public:
    //CREATE
    static Scene* createScene(int cond);
    
	CREATE_FUNC(EndScene);
};
class WinScene : public Layer{
public:
	//CREATE
	void nextScene(Ref* pSender);

	//INIT
	virtual bool init();

	//CALLBACK
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(WinScene);
};
class LoseScene : public Layer{
public:
	//CREATE
	void nextScene(Ref* pSender);

	//INIT
	virtual bool init();

	//CALLBACK
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(LoseScene);
};

#endif // __END_SCENE_H__
