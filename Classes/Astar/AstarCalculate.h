
#pragma once
extern class AstarItem;

namespace Calculate
{
	//�������̵ĵ������д�֤������ʽ��������˶Ȫ�����д��룬���Ǹ���û���ἰ��ʽ��ʹ����һ��ħ��������֪����ˮƽ���޻��ǹ���Ϊ֮��
	//���㵱ǰ�ڵ�ĺ�ɢֵ����Ϊ���ڵ��GΪ��֪����ֱ������ÿ��̽���Ĺ̶���ɢֵ
	float calculateG(AstarItem * pCurItem,AstarItem * pNewParentItem);

	//Ѱ·�Ĺ���ֵ��Ŀǰ�������Ծ�����ơ�
	float calculateH(int row,int col,int targetX,int targetY);

	int calculateID(int row,int col);

	int calculateID(AstarItem * p);
}