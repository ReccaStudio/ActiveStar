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

#include "AstarCalculate.h"
#include "AstarItem.h"
#include <cmath>

namespace Calculate
{
	//�������̵ĵ������д�֤������ʽ��������˶Ȫ�����д��룬���Ǹ���û���ἰ��ʽ��ʹ����һ��ħ��������֪����ˮƽ���޻��ǹ���Ϊ֮��
	//���㵱ǰ�ڵ�ĺ�ɢֵ����Ϊ���ڵ��GΪ��֪����ֱ������ÿ��̽���Ĺ̶���ɢֵ
	float calculateG(AstarItem * pCurItem,AstarItem * pNewParentItem)
	{
		int row = pCurItem->getRow();
		int col = pCurItem->getCol();

		int parentRow = pNewParentItem->getRow();
		int parentCol = pNewParentItem->getCol();
	
		int g = pNewParentItem->getG();
		//todo ��ɢֵʹ�õ�ħ�������¸��汾����Ϊ��Ч�ĺ�ɢ���ֵ
		//б���·�̿����������1.4��
		if (row != parentRow && col != parentCol)
		{
			g+=14;
		}
		else
		{
			g+=10;
		}
		//todo ����ǽ�Ǻ�ɢ����
		if (true)
		{

		}
		return g;
	}

	//Ѱ·�Ĺ���ֵ��Ŀǰ�������Ծ�����ơ�
	float calculateH(int row,int col,int targetX,int targetY)
	{
		return std::sqrt(std::pow(targetX-row,2)+std::pow(targetY-col,2))*10;
	}

	int calculateID(int row,int col)
	{
		return row*100+col;
	}
	
	int calculateID(AstarItem * pItem)
	{
		return pItem->getRow()*100+pItem->getCol();
	}
}


