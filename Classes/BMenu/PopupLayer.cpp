#include "PopupLayer.h"
PopupLayer::PopupLayer()
{
}
PopupLayer::~PopupLayer()
{
}
PopupLayer* PopupLayer::create(Layer * targetLayer, const int type)
{
	PopupLayer* popupLayer = new PopupLayer();
	if (popupLayer && popupLayer->init(targetLayer, type))
	{
		popupLayer->autorelease();
		return popupLayer;
	}
	else
	{
		CC_SAFE_DELETE(popupLayer);
		return nullptr;
	}
}
bool PopupLayer::init(Layer * targetLayer, const int type)
{
	if (!Layer::init())
		return false;
	addChild(MenuBarrier::create(), 0);
	targetLayer->setTag(1);
	addChild(targetLayer, 1);
	return true;
}