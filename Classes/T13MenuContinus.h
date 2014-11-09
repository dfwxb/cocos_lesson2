#pragma once

#include "BaseLayer.h"

USING_NS_CC;

/*
	1. 注册定时器函数， 在定时器函数中，调用m_pSelectItem->active()
	2. 
*/
class MyMenu : public CCMenu
{
public:
	MyMenu() {} 
	~MyMenu() {}
	CREATE_FUNC(MyMenu);

	bool ccTouchBegan(CCTouch* touch, CCEvent* event)
	{
		bool bRet = CCMenu::ccTouchBegan(touch, event);

		if (bRet) {
			// 设置为选中
			if (this->m_pSelectedItem && m_eState == kCCMenuStateTrackingTouch) {
				this->m_pSelectedItem->selected();
			}

			// 注册定时器函数
			scheduleUpdate();
		}

		return bRet;
	}

	void ccTouchEnded(CCTouch* touch, CCEvent* event)
	{
		this->m_pSelectedItem->unselected();
		unscheduleUpdate();
	}

	void update(float dt)
	{
		if (this->m_pSelectedItem && m_eState == kCCMenuStateTrackingTouch) {
			this->m_pSelectedItem->activate();
		}
	}
};


class T13MenuContinus : public BaseLayer
{
public:
	T13MenuContinus();
	~T13MenuContinus();
	CREATE_FUNC(T13MenuContinus);
	static CCScene* scene();
	virtual bool init();

	void click(cocos2d::CCObject*);
};

