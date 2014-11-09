#pragma once
#include "cocos2d.h"
class LessonMenu : public cocos2d::CCLayer
{
public:
	LessonMenu();
	~LessonMenu();
	CREATE_FUNC(LessonMenu);
	static cocos2d::CCScene* scene();
	virtual bool init();

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void enterItem(cocos2d::CCObject* pSender);
};

