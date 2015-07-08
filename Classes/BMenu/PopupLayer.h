#ifndef _POPUP_LAYER_H_
#define _POPUP_LAYER_H_
#include "cocos2d.h"
#include "MenuBarrier.h"
USING_NS_CC;
class PopupLayer : public Layer
{
public:
	PopupLayer();
	~PopupLayer();
	bool init(Layer * targetLayer, int type);
	static PopupLayer* create(Layer * targetLayer, const int type);
	static PopupLayer* create(Layer *  targetLayer)
	{
		return PopupLayer::create(targetLayer, 0);
	};
	
};
#endif