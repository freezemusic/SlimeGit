/*******************
 * Level is the main class create the Scene
 * and the Node Tree is as follow:
 * Scene{ 
 *    Level { Parallax {Player, Monster, Map{ Fixtures }, ...} },
 *    GamePanel
 * }
 *******************/

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "cocos2d.h"
#include "../Panel/GamePanel.h"
class Player;
USING_NS_CC;

enum{ levelTag, panelTag };

class Level : public Layer{
private:
	PhysicsWorld* world;
	TMXTiledMap* map;
	int objectCount = 0;
public:
	Level();

	static Scene* createScene();
	static Scene* createSceneWithMap(std::string mapPath);

	void createLevel(std::string mapPath);
	ParallaxNode* createParallax(std::string mapPath);
	//PARSE TMX TILES TO SPRITES
	void prepareLayers();
	void createFixtures(TMXLayer* layer);
	void createRectFixture(TMXLayer* layer, Sprite* spr);
	//PARSE TMX OBJECT TO OBJECTS
	void addObjects();
	void addObject(std::string className, ValueMap& prop);
	void setGamePanelOnPlayer(Player* player);
	Rect scaleRect(Rect& rect, float scale);

	void update(float dt);
	void updateCameraOnPlayer(Player* player);

	CREATE_FUNC(Level);
};

#endif // __LEVEL_H__
