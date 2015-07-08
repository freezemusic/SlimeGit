#ifndef _MENU_BARRIER_H_
#define _MENU_BARRIER_H_
#include "cocos2d.h"
USING_NS_CC;
class MenuBarrier : public Layer
{
public:
	MenuBarrier();
	~MenuBarrier();
	bool init();
	CREATE_FUNC(MenuBarrier);
};
#endif