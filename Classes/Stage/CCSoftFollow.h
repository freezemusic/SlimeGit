#ifndef __SOFT_FOLLOW_H__
#define __SOFT_FOLLOW_H__

#include "cocos2d.h"
USING_NS_CC;

enum SoftFollowType{
	kSoftFollowNone,
	kSoftFollowXOnly,
	kSoftFollowYOnly
};

class SoftFollow : public Follow{
private:
	SoftFollowType _type;
	Rect _marginRect;

	SoftFollow();
	~SoftFollow();
public:
	static SoftFollow* create(Node *followedNode);
	static SoftFollow* create(Node *followedNode, SoftFollowType type);
	static SoftFollow* create(Node *followedNode, Rect marginRect);

	virtual void step(float dt) override;
};

#endif //__SOFT_FOLLOW_H__