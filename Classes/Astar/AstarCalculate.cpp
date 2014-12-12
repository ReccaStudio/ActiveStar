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


