/****************************************************************************
 Copyright (c) 2014-2015 Jingz @ Recca2 Studio.
 
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#pragma once

#include "AstarItem.h"
#include <map>
#include "AstarCalculate.h"
#include <set>
/*
*	item�����ں����ʹ��ʮ��������mapΪ��������ʵ���������
*
*
*/

struct ItemFCompare:public std::binary_function<AstarItem*,AstarItem*,bool>
{
	
public:
	bool operator()(const AstarItem* left,const AstarItem * right)const
	{
		return (left->getF()<right->getF());
	}
};


class AstarMapManager
{
	typedef int Row;
	typedef int Col;
	typedef cocos2d::Map<Col,AstarItem*> ColContainer;
public:
	AstarMapManager();
	~AstarMapManager(void);

	void init(cocos2d::TMXTiledMap * pMap,cocos2d::Vec2 tarPosi,bool cleanup = false);

	void reset(bool cleanup = false);

	//������������item,�����ɺ�ɢֵ��·��
	AstarItem * getItem(int row,int col,AstarItem * pParentItem);

	//todo,DO Not delete this pointer,just set it as nullptr
	AstarItem * getEmptyHeadItem(void)
	{
		CCAssert(m_EmptyHeadItem!=nullptr,"The map data should be inited before");
		return m_EmptyHeadItem;
	}

	bool isItemIn(int row,int col)const;

	//������Ӧ�ò���Ҫ����ӿڣ����������ǳ����ڴ������
	bool isItemIn(AstarItem *pItem)const;
	
	//todo ��;����
	void removeItem(AstarItem * p);
	//todo ��;����
	void removeItem(int row,int col);


	unsigned int  getTileGid(AstarItem* pItem,cocos2d::TMXTileFlags* flags = nullptr)const
	{
		CCAssert(m_pLayer!=nullptr,"The map data should be inited before");
		auto posi = pItem->getPosition();
		return m_pLayer->getTileGIDAt(posi);
	}

	unsigned int getTileGid(int row,int col) const
	{
		CCAssert(m_pLayer!=nullptr,"The map data should be inited before");
		//todo �Ը���Դ���Ǻ���Ϥ�����һ��
		return m_pLayer->getTileGIDAt(cocos2d::Vec2(row,col));
	}

	inline const cocos2d::Size& getMapSize()const
	{
		return m_pMap->getMapSize();
	}

	bool checkReachAble(int row,int col)const;

	static bool checkReachAble(cocos2d::TMXTiledMap * pMap,const std::string& sLayerName,cocos2d::Vec2 posi);

	static bool checkReachAble(cocos2d::TMXTiledMap * pMap,const std::string& sLayerName,int row,int col);

	//ת��Ϊ��ͼ����
	static cocos2d::Vec2 convertToMapPosi(cocos2d::TMXTiledMap * pMap,float x,float y);

protected:
	//����һ���µĽڵ�
	AstarItem * CreateNewItem(ColContainer* pContainer,int row,int col,AstarItem * pParentItem)
	{
		
			auto p = new AstarItem();
			p->init(row,col,pParentItem);
			auto tempG  = Calculate::calculateG(p,pParentItem);
			auto tempH  = Calculate::calculateH(row,col,m_vTarPosi.x,m_vTarPosi.y);
			auto tempF = tempG+tempH;
			p->setGHF(std::move(tempG),std::move(tempH),std::move(tempF));
			pContainer->insert(col,p);
			//������autorelease
			p->release();
			return p;
	}

	void clearPools(void)
	{
		
		if (m_mItemPools!=nullptr)
		{
			for (auto it_map = m_mItemPools->begin(); it_map != m_mItemPools->end(); ++it_map)
			{

				//it_map->second->clear();
				//it_map->second->reserve(it_map->second->bucketCount
				//������������ڴ�
				delete it_map->second;
				it_map->second = nullptr;
			}
			//��δʵ�ֵ�ͼitem����
			m_mItemPools->clear();
		}
		
	}

	void deletePtrs(void)
	{
		if (m_mItemPools!=nullptr)
		{
			clearPools();
			delete m_mItemPools;
			m_mItemPools = nullptr;
		}

		if (m_pLayer!=nullptr)
		{
			m_pLayer->release();
			m_pLayer = nullptr;
		}

		if (m_pMap!=nullptr)
		{
			m_pMap->release();
			m_pMap = nullptr;
		}


		if (m_EmptyHeadItem!=nullptr)
		{
			m_EmptyHeadItem->release();
			m_EmptyHeadItem = nullptr;
		}
	}

private:
	//��ʱʹ�õ�ַ��Сȥ����
	std::map<Row,ColContainer*> *  m_mItemPools;

	cocos2d::TMXTiledMap * m_pMap;

	//todo �Ը���Դ���Ǻ���Ϥ�����һ��,Ӧ��ʹ�������
	cocos2d::TMXLayer * m_pLayer;

	AstarItem * m_EmptyHeadItem;

	cocos2d::Vec2 m_vTarPosi;

};
