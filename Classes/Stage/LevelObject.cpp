#include "LevelObject.h"
USING_NS_CC;

void LevelObject::setProperties(ValueMap& prop){
	float x = prop["x"].asFloat();
	float y = prop["y"].asFloat();
	entitySight = Node::create();
	entitySight->retain();
	entitySight->setPosition(Vec2(x, y));
	this->setPosition(Vec2(x, y));
	this->setFlippedX(false);
	this->setFlippedY(false);
}
void LevelObject::setEntitySight(bool b){
	front = b;
	auto director = Director::getInstance();
	Vec2 offset = (front ? 1 : -1) * Vec2(director->getVisibleSize().width / 4, 0);
	entitySight->setPosition(getPosition() + offset);
	this->setFlippedX(!front);
}
Node* LevelObject::getEntitySight(){
	return entitySight;
}

void LevelObject::update(){
	setEntitySight(front);
}