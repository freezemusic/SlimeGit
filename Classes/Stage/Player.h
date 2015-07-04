#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "LevelObject.h"
#include "Level.h"
USING_NS_CC;

enum{ playerBatchTag, playerSpriteTag };

class Player : public LevelObject{
private:
	typedef LevelObject super;
	typedef Player self;
public:
	//Player();
	//virtual ~Player();

	//void setProperties(ValueMap& prop);
	SpriteBatchNode* createBatch();
	Sprite* createSprite();
	void addSpriteToLevel(Level* const& level);
	void addBody();
	//void addFixtures();

	CREATE_FUNC(Player);
};

#endif //__PLAYER_H__