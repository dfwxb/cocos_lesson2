#pragma once

#include "cocos-ext.h"
#include "BaseLayer.h"

USING_NS_CC_EXT;
USING_NS_CC;

class T23TableViewSmall : public BaseLayer, CCTableViewDataSource, CCTableViewDelegate
{
public:
	T23TableViewSmall();
	~T23TableViewSmall();
	CREATE_FUNC(T23TableViewSmall);
	static CCScene* scene();
	virtual bool init();

	// CCTableViewDataSource函数重载和实现
	virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx) {
		return cellSizeForTable(table);
	};
	virtual CCSize cellSizeForTable(CCTableView *table) {
		return CCSizeMake(40, 40);
	};
	virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx) {
		return dynamic_cast<CCTableViewCell*>(m_pCells->objectAtIndex(idx));
	}

	virtual unsigned int numberOfCellsInTableView(CCTableView *table) {
		return m_pCells->count();
	}

	// CCTableViewDelegate类的纯虚函数的实现
	virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell) {
		CCLOG("-----Touched cell is %d-----", cell->getIdx());
	}
	virtual void scrollViewDidScroll(CCScrollView* view) {

	}
	virtual void scrollViewDidZoom(CCScrollView* view) {

	}

private:
	CCArray* m_pCells; // 存放cells的数组
};

