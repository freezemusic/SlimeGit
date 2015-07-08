#include "MenuBarrier.h"
MenuBarrier::MenuBarrier()
{
}
MenuBarrier::~MenuBarrier()
{
}
bool MenuBarrier::init()
{
	if (!Layer::init())
		return false;
	LayerColor* backLayerColor = LayerColor::create(Color4B(25, 25, 25, 125));
	this->addChild(backLayerColor);
	auto callback = [](Touch *, Event *)
	{
		return true;
	};
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = callback;
	listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
