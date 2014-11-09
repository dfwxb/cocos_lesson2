#include "T13MenuContinus.h"

USING_NS_CC;

T13MenuContinus::T13MenuContinus()
{
}
T13MenuContinus::~T13MenuContinus()
{
}


CCScene* T13MenuContinus::scene()
{
	CCScene* pScene = CCScene::create();
	T13MenuContinus* pLayer = T13MenuContinus::create();
	pScene->addChild(pLayer);

	return pScene;
}

bool T13MenuContinus::init()
{
	if (!BaseLayer::init())
		return false;

	CCMenuItem* pItem = CCMenuItemFont::create("Cliclk me",
		this, menu_selector(T13MenuContinus::click));


	MyMenu* pMenu = MyMenu::create();
	addChild(pMenu);
	pMenu->addChild(pItem);

	return true;
}

void T13MenuContinus::click(CCObject* pSender)
{
	CCLog("-----Touched---------");
}