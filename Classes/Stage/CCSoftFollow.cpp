#include "CCSoftFollow.h"
USING_NS_CC;

SoftFollow::SoftFollow(){
	_type = kSoftFollowNone;
	_marginRect = Rect::ZERO;
}

SoftFollow::~SoftFollow(){
	CC_SAFE_RELEASE(_followedNode);
}

SoftFollow* SoftFollow::create(Node* followNode){
	SoftFollow *follow = new SoftFollow();
	if (follow && follow->initWithTarget(followNode, Rect::ZERO)){
		follow->autorelease();
		return follow;
	}
	CC_SAFE_DELETE(follow);
	return nullptr;
}

SoftFollow* SoftFollow::create(Node* followNode, SoftFollowType type){
	SoftFollow *follow = new SoftFollow();
	follow->_type = type;
	if (follow && follow->initWithTarget(followNode, Rect::ZERO)){
		follow->autorelease();
		return follow;
	}
	CC_SAFE_DELETE(follow);
	return nullptr;
}

SoftFollow* SoftFollow::create(Node* followNode, Rect marginRect){
	SoftFollow *follow = new SoftFollow();
	follow->_marginRect = marginRect;
	if (follow && follow->initWithTarget(followNode, Rect::ZERO)){
		follow->autorelease();
		return follow;
	}
	CC_SAFE_DELETE(follow);
	return nullptr;
}

void SoftFollow::step(float dt){
	CC_UNUSED_PARAM(dt);

	if (_boundarySet)	{
		if (_boundaryFullyCovered)
			return;

		Point tempPos = _halfScreenSize - _followedNode->getPosition();

		float x = clampf(tempPos.x, _leftBoundary, _rightBoundary);
		float y = clampf(tempPos.y, _bottomBoundary, _topBoundary);

		if (_type == kSoftFollowXOnly){
			y = _target->getPositionY();
		}
		else if (_type == kSoftFollowYOnly){
			x = _target->getPositionX();
		}

		_target->setPosition(Point(x, y));

	}else{
		Point calcPos = _target->convertToWorldSpace(_followedNode->getPosition());

		if (_marginRect.containsPoint(calcPos)){
			return;
		}

		float x = _halfScreenSize.x - _followedNode->getPositionX();
		float y = _halfScreenSize.y - _followedNode->getPositionY();

		if (_type == kSoftFollowXOnly){
			y = _target->getPositionY();
		}
		else if (_type == kSoftFollowYOnly){
			x = _target->getPositionX();
		}

		_target->setPosition(Point(x, y));
	}
}