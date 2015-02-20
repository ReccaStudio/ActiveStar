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
class AstarItem;

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