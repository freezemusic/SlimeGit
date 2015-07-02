#include "MainScene.h"
#include "BattleScene.h"
#include "EndScene.h"

USING_NS_CC;

Scene* EndScene::createScene(int cond){
    auto scene = Scene::create(); //auto-release
	auto layer = (cond==BATTLE_WIN) ? (Scene*)WinScene::create() : (Scene*)LoseScene::create(); //auto-release
    scene->addChild(layer);
    return scene;
}
void WinScene::nextScene(Ref* pSender){
	auto director = Director::getInstance();
	auto scene = MainScene::createScene();
	director->replaceScene(TransitionFadeUp::create(0.5f, scene));
}

//INIT
bool WinScene::init(){
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
		CC_CALLBACK_1(WinScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	//NEXT SCENE BUTTON (for debug)
	auto nextItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(WinScene::nextScene, this));
	nextItem->setPosition(origin);
	//MENU
	auto menu = Menu::create(closeItem, nextItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    //LABEL
    auto label = Label::createWithTTF("WinScene", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

	//SPRITE
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    return true;
}


void WinScene::menuCloseCallback(Ref* pSender)
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


void LoseScene::nextScene(Ref* pSender){
	auto director = Director::getInstance();
	auto scene = MainScene::createScene();
	director->replaceScene(TransitionFadeUp::create(0.5f, scene));
}

//INIT
bool LoseScene::init(){
	//SUPER
	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//CLOSE BUTTON
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(LoseScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	//NEXT SCENE BUTTON (for debug)
	auto nextItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(LoseScene::nextScene, this));
	nextItem->setPosition(origin);
	//MENU
	auto menu = Menu::create(closeItem, nextItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	//LABEL
	auto label = Label::createWithTTF("LoseScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//SPRITE
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	return true;
}


void LoseScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
