#ifndef __MENU_H__
#define __MENU_H__

#include "cocos2d.h"
USING_NS_CC;


class BMenu : public Layer{
public:
	//CREATE
	//static Scene* createScene();
	//INIT
	//virtual bool init();

	BMenu();
	~BMenu();
	bool init();
	//CALLBACK
	void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(BMenu);
};

#endif // __MENU_H__