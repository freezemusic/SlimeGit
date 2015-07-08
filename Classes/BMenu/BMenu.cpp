#include "BMenu.h"
#include "MainScene.h"
#include "ui/CocosGUI.h"
#include "ui/UILayout.h"
#include "MenuBarrier.h"

using namespace ui;
USING_NS_CC;

/*Scene* BMenu::createScene(){
	auto scene = Scene::create(); //auto-release
	auto layer = BMenu::create(); //auto-release
	scene->addChild(layer);
	return scene;
}*/

BMenu::BMenu(){
}
BMenu::~BMenu(){

}
//INIT
bool BMenu::init(){
	//SUPER
	if (!Layer::init()){
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	Layout* layout = Layout::create();
	layout->setContentSize(Size(680, 450));
	layout->setBackGroundImageScale9Enabled(true);
	layout->setBackGroundImage("grey_panel.png");
	layout->setPosition(Vec2(origin.x + visibleSize.width / 2 - layout->getContentSize().width/2,
		origin.y + visibleSize.height / 2 - layout->getContentSize().height/2));
	this->addChild(layout,0);

	PageView* infopage = PageView::create();
	infopage->setContentSize(Size(360, 400));
	infopage->setPosition(Vec2(layout->getContentSize().width * 2 / 5, layout->getContentSize().height / 13));

	Layout* menupage = Layout::create();
	menupage->setContentSize(Size(360, 400));
	menupage->setBackGroundImageScale9Enabled(true);
	menupage->setBackGroundImage("grey_panel.png");
	Text* label1 = Text::create(StringUtils::format("Character"), "kenvector_future.ttf", 25);
	label1->setColor(Color3B(0, 0, 0));
	label1->setPosition(Vec2(infopage->getContentSize().width / 2, infopage->getContentSize().height - label1->getContentSize().height));
	menupage->addChild(label1);

	Layout* Storypage = Layout::create();
	Storypage->setContentSize(Size(360, 400));
	Storypage->setBackGroundImageScale9Enabled(true);
	Storypage->setBackGroundImage("red_panel.png");
	Text* label2 = Text::create(StringUtils::format("Story"), "kenvector_future.ttf", 25);
	label2->setColor(Color3B(0,0, 0));
	label2->setPosition(Vec2(infopage->getContentSize().width/2, infopage->getContentSize().height - label2->getContentSize().height));
	Storypage->addChild(label2);

	Layout* Controlpage = Layout::create();
	Controlpage->setContentSize(Size(360, 400));
	Controlpage->setBackGroundImageScale9Enabled(true);
	Controlpage->setBackGroundImage("green_panel.png");
	Text* label3 = Text::create(StringUtils::format("Control"), "kenvector_future.ttf", 25);
	label3->setColor(Color3B(0, 0, 0));
	label3->setPosition(Vec2(infopage->getContentSize().width/2, infopage->getContentSize().height - label3->getContentSize().height));
	Controlpage->addChild(label3);

	infopage->insertPage(menupage, 1);
	infopage->insertPage(Storypage, 2);
	infopage->insertPage(Controlpage, 0);
	infopage->scrollToPage(0);
	
	

	Button* mainmenu = Button::create("blue_button02.png", "blue_button03.png");
	mainmenu->setTitleText("Main Menu");
	mainmenu->setTitleFontName("kenvector_future.ttf");
	mainmenu->setTitleFontSize(20);
	mainmenu->setPosition(Vec2(mainmenu->getContentSize().width *3/4 ,
		layout->getContentSize().height - mainmenu->getContentSize().height*1.5));
	mainmenu->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			Director::getInstance()->resume();
			auto scene = MainScene::createScene();
			Director::getInstance()->replaceScene(scene);
			break;
		}
		default:
			break;
		}
	});
	layout->addChild(mainmenu);

	

	Button* Resume = Button::create("blue_button02.png", "blue_button03.png");
	Resume->setTitleText("Resume");
	Resume->setTitleFontName("kenvector_future.ttf");
	Resume->setTitleFontSize(20);
	Resume->setPosition(Vec2(mainmenu->getContentSize().width * 3 / 4,
		layout->getContentSize().height - mainmenu->getContentSize().height * 6));
	Resume->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			getParent()->removeFromParent();
			Director::getInstance()->resume();
		}
			break;
		default:
			break;
		}
	});

	layout->addChild(Resume);
	layout->addChild(infopage);
	
	return true;
}


void BMenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->popScene();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
