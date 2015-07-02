#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

enum battleCondition{ BATTLE_WIN, BATTLE_LOSE };
class BattleScene : public Layer{
public:
    //CREATE
    static Scene* createScene();
	void nextWinScene(Ref* pSender);
	void nextLoseScene(Ref* pSender);

    //INIT
    virtual bool init();
    
    //CALLBACK
    void menuCloseCallback(Ref* pSender);
    
	CREATE_FUNC(BattleScene);
};

#endif // __BATTLE_SCENE_H__
