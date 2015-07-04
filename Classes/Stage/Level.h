#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "cocos2d.h"
USING_NS_CC;

class Level : public Layer{
private:
	PhysicsWorld* world;
	TMXTiledMap* map;
	int objectCount = 0;
public:
	Level();

	static Scene* createScene();
	static Scene* createSceneWithMap(std::string mapPath);

	//PARSE TMX TO OBJECTS
	void prepareLayers();
	void createFixtures(TMXLayer* layer);
	void createRectFixture(TMXLayer* layer, Sprite* spr);

	void addObjects();
	void addObject(std::string className, ValueMap& prop);

	void update(float dt);

	CREATE_FUNC(Level);
};

#endif // __LEVEL_H__
