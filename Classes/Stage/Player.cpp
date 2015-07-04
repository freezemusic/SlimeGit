#include "Player.h"
#include "Level.h"
USING_NS_CC;

SpriteBatchNode* Player::createBatch(){
	auto spriteBatch = SpriteBatchNode::create("slime_sprite.png");
	return spriteBatch;
}

Sprite* Player::createSprite(){

	auto sprCache = SpriteFrameCache::getInstance();
	sprCache->addSpriteFramesWithFile("slime_sprite.plist");
	this->setSpriteFrame("slime01.png");

	auto animation = Animation::create();
	char str[100] = { 0 };
	for (int i = 1; i <= 4; i++){
		sprintf(str, "slime0%d.png", i);
		animation->addSpriteFrame(sprCache->spriteFrameByName(str));
	}
	animation->setDelayPerUnit(0.2f);
	this->runAction(RepeatForever::create(Animate::create(animation)));
	return(this);
}

void Player::addSpriteToLevel(Level* const& level){
	auto batch = createBatch();
	auto sprite = createSprite();
	batch->addChild(sprite, 0, playerSpriteTag);
	level->addChild(batch, 0, playerBatchTag);
}

void Player::addBody(){
	auto body = PhysicsBody::createCircle(this->getContentSize().height*0.6f / 2);
	this->setPhysicsBody(body);
}
//void Player::addFixtures(){}