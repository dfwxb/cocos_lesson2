#include "LessonMenu.h"
#include "T01SpriteCreate.h"
#include "T02Layer.h"
#include "T03Cood.h"
#include "T04ZorderAndTag.h"
#include "T05CCLabelTTf.h"
#include "T06CCLabelAtlas.h"
#include "T07IBMFont.h"
#include "T08CCSpriteBatchNode.h"
#include "T09TextFieldTTF.h"
#include "T10EditBox.h"
#include "T11Menu.h"
#include "T12MenuItems.h"
#include "T13MenuContinus.h"
#include "T14SwitchControl.h"
#include "T15ControlSlider.h"
#include "T19Update.h"
#include "T20ProgressTimer.h"
#include "T21ScrollView.h"
#include "T22TableView.h"
#include "T23TableViewSmall.h"

USING_NS_CC;

LessonMenu::LessonMenu()
{
}
LessonMenu::~LessonMenu()
{
}
CCScene* LessonMenu::scene()
{
	CCScene* pScene = CCScene::create();
	LessonMenu* pLayer = LessonMenu::create();
	pScene->addChild(pLayer);

	return pScene;
}

static const char* s_lesson[] = {
	"T01SpriteCreate",
	"T02Layer",
	"T03Cood",
	"T04ZorderAndTag",
	"T05CCLabelTTf",
	"T06CCLabelAtlas",
	"T07IBMFont",
	"T08CCSpriteBatchNode",
	"T09TextFieldTTF",
	"T10EditBox",
	"T11Menu",
	"T12MenuItems",
	"T13MenuContinus",
	"T14SwitchControl",
	"T15ControlSlider",
	"T19Update",
	"T20ProgressTimer",
	"T21ScrollView",
	"T22TableView",
	"T23TableViewSmall"
};

bool LessonMenu::init()
{
	if (!CCLayer::init())
		return false;

	CCMenu* pMenu = CCMenu::create();
	addChild(pMenu);

	for (int i = 0; i < sizeof(s_lesson) / sizeof(*s_lesson); i++) {
		CCMenuItemFont* pItem = CCMenuItemFont::create(s_lesson[i]);
		pMenu->addChild(pItem);
		pItem->setTarget(this, menu_selector(LessonMenu::enterItem));
		pItem->setTag(10000 + i);
	}

	pMenu->alignItemsVertically();

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool LessonMenu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void LessonMenu::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	setPositionY(getPositionY() + pTouch->getDelta().y);
}

void LessonMenu::enterItem(CCObject* pSender)
{
	CCMenuItem* pItem = dynamic_cast<CCMenuItem*>(pSender);

	int nTag = pItem->getTag() - 10000;

	CCScene* pScene = NULL;

	switch (nTag) {
	case 0:
		pScene = T01SpriteCreate::scene();
		break;
	case 1:
		pScene = T02Layer::scene();
		break;
	case 2:
		pScene = T03Cood::scene();
		break;
	case 3:
		pScene = ZorderAndTag::scene();
		break;
	case 4:
		pScene = T05CCLabelTTf::scene();
		break;
	case 5:
		pScene = T06CCLabelAtlas::scene();
		break;
	case 6:
		pScene = T07IBMFont::scene();
		break;
	case 7:
		pScene = T08CCSpriteBatchNode::scene();
		break;
	case 8:
		pScene = T09TextFieldTTF::scene();
		break;
	case 9:
		pScene = T10EditBox::scene();
		break;
	case 10:
		pScene = T11Menu::scene();
		break;
	case 11:
		pScene = T12MenuItems::scene();
		break;
	case 12:
		pScene = T13MenuContinus::scene();
		break;
	case 13:
		pScene = T14SwitchControl::scene();
		break;
	case 14:
		pScene = T15ControlSlider::scene();
		break;
	case 15:
		pScene = T19Update::scene();
		break;
	case 16:
		pScene = T20ProgressTimer::scene();
		break;
	case 17:
		pScene = T21ScrollView::scene();
		break;
	case 18:
		pScene = T22TableView::scene();
		break;
	case 19:
		pScene = T23TableViewSmall::scene();
		break;
	default:
		break;
	}

	if (pScene) {
		CCDirector::sharedDirector()->pushScene(pScene);
	}
}
