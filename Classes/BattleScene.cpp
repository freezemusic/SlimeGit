#include "BattleScene.h"
#include "EndScene.h"

USING_NS_CC;

Scene* BattleScene::createScene(){
    auto scene = Scene::create(); //auto-release
	auto layer = BattleScene::create(); //auto-release
    scene->addChild(layer);
    return scene;
}
void BattleScene::nextWinScene(Ref* pSender){
	auto director = Director::getInstance();
	auto scene = EndScene::createScene(BATTLE_WIN);
	director->replaceScene(TransitionFadeUp::create(0.5f, scene));
}
void BattleScene::nextLoseScene(Ref* pSender){
	auto director = Director::getInstance();
	auto scene = EndScene::createScene(BATTLE_LOSE);
	director->replaceScene(TransitionFadeUp::create(0.5f, scene));
}

//INIT
bool BattleScene::init(){
    //SUPER
    if ( !Layer::init() ){
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //CLOSE BUTTON
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
		CC_CALLBACK_1(BattleScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	//NEXT SCENE BUTTON (for debug)
	auto nextWinItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(BattleScene::nextWinScene, this));
	nextWinItem->setPosition(Vec2(origin.x, origin.y + 100));
	auto nextLoseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(BattleScene::nextLoseScene, this));
	nextLoseItem->setPosition(Vec2(origin.x + 100, origin.y));
	//MENU
	auto menu = Menu::create(closeItem, nextWinItem, nextLoseItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    //LABEL
    auto label = Label::createWithTTF("BattleScene", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

	//SPRITE
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    return true;
}


void BattleScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
