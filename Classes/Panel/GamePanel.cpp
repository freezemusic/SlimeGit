#include "GamePanel.h"
#include "../Stage/Level.h"
#include "../Stage/Player.h"

USING_NS_CC;

GamePanel* GamePanel::createLayer(){
	auto panel = GamePanel::create();
	panel->setTouchEnabled(true);
	panel->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	panel->player = nullptr;
	//*DEBUG USE
	panel->debugLabel = Label::createWithTTF("Receiving..", "fonts/Marker Felt.ttf", 24);
	panel->debugLabel->setPosition(Vec2(200, 200));
	panel->addChild(panel->debugLabel);

	panel->pen = DrawNode::create();
	panel->addChild(panel->pen);

	return panel;
}

bool GamePanel::isPlayerExist(){
	return (player != nullptr);
}
void GamePanel::setPlayer(Player* player){
	this->player = player;
}
Player* GamePanel::getPlayer(){
	return player;
}

bool GamePanel::onTouchBegan(Touch* touch, Event* event){
	//CALCULATION
	startLoc = touch->getLocation();
	//DRAW BEGIN POINT
	pen->drawSolidCircle(startLoc, 70.0f, 0.0f, 100, Color4F(1, 0, 0, 0.1f));
	//PLAYER CHANGE SPRITE
	player->readyToJump(Vec2(0, 0));
	//DEBUG*
	auto para = player->getParent()->getParent();
	char str[100] = { 0 };
	sprintf(str, "Began: (%d, %d) %s", (int)(startLoc.x), (int)(startLoc.y), para->getName().c_str());
	debugLabel->setString(str);
	return true;
}
void GamePanel::onTouchMoved(Touch* touch, Event* event){
	//CALCULATION
	endLoc = touch->getLocation();
	auto dist = endLoc.distance(startLoc);
	float deltaX = startLoc.x - endLoc.x;
	float deltaY = startLoc.y - endLoc.y;
	//DRAW DISTANCE
	pen->clear();
	pen->drawSolidCircle(startLoc, 70.0f, 0.0f, 100, Color4F(1, 0, 0, 0.1f));
	pen->drawSolidCircle(endLoc, 30.0f, 0.0f, 100, Color4F(0, 1, 0, 0.1f));
	//PLAYER CHANGE SPRITE
	player->readyToJump(Vec2(deltaX, deltaY));

	//DEBUG*
	auto diff = touch->getDelta();
	auto para = (ParallaxNode*) (player->getParent()->getParent());
	auto map = para->getChildByName("Map");
	auto currentPos = para->getPosition();
	//para->setPosition(currentPos + diff);
	pen->drawSolidCircle(currentPos, 30.0f, 0.0f, 100, Color4F(0, 0, 1, 0.1f));
	char str[100] = { 0 };
	sprintf(str, "Moved: (%d, %d) %s", (int)(startLoc.x), (int)(startLoc.y), map->getName().c_str());
	debugLabel->setString(str);
}
void GamePanel::onTouchEnded(Touch* touch, Event* event){
	//CALCULATION
	endLoc = touch->getLocation();
	auto dist = endLoc.distance(startLoc);
	float deltaX = startLoc.x - endLoc.x;
	float deltaY = startLoc.y - endLoc.y;
	//DEBUG*
	char str[100] = { 0 };
	sprintf(str, "Ended: (%d, %d), Distance: %d", (int)deltaX, (int)deltaY, (int)dist);
	//REMOVE ALL POINTS DREW
	pen->clear();
	debugLabel->setString(str);
	//PLAYER MOVE
	player->move(Vec2(deltaX, deltaY));
}