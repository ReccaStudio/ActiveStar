/****************************************************************************
Copyright (c) 2014-2015 Jingz @ ReccaStudio.


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

#include "HeapSortTools.h"

namespace HeapSort
{
	
	void createNewHeap(cocos2d::Vector<AstarItem*> * vItemList,cocos2d::Vector<AstarItem*>::iterator startIt,cocos2d::Vector<AstarItem*>::iterator endIt,AstarLessThan lessFunc,int nodesCount)
	{
		if(endIt<=startIt+1) return;

		int n = endIt-startIt;
		
		for (int j = 0; j<nodesCount; ++j)
		{
			placeElem(startIt,endIt-startIt,n/2-j,lessFunc);
		}
		


	}//createNewHeap


	//��λ��ĩλԪ������ΪmaxHeap,ʣ��Ԫ���Կ�ʼ�±�Ϊ�����µ���Ϊ��
	void genarateNextheap(cocos2d::Vector<AstarItem*> * vItemList,cocos2d::Vector<AstarItem*>::iterator startIt,cocos2d::Vector<AstarItem*>::iterator endIt,AstarLessThan lessFunc)
	{


		std::swap(*startIt,*(endIt-1));

		//ֻ��Ҫ�Ѷ���Ԫ�������ҳ������ٰ�v����հ�λ�ü���
		placeElem(startIt,endIt-1-startIt,1,lessFunc);

	}

	//ĩλ����Ԫ�أ��Կ�ʼ�±�Ϊ�����µ���Ϊ��
	void placeElem(cocos2d::Vector<AstarItem*>::iterator startIt,int n,int i,AstarLessThan lessFunc)
	{
		if (n<=1 || i<=0)
		{
			return ;
		}

		//����
		auto v = *(startIt-1+i);

		int k = i,j = 0;
			
		bool heap = false;

		while(!heap && 2*k <= n )//ʵ�ָ�ĸ����
		{
			j = 2*k;
			if(j<n)//������������
			{

				if ( !lessFunc( *(startIt-1+j),*(startIt-1+j+1) ) )
				{
					j = j+1;
					//std::swap(*(startIt-1+j),*(startIt-1+j+1));
				}

			}

			if(  lessFunc(v,*(startIt-1+j)) )
			{
				heap = true;
			}
			else 
			{
				*(startIt-1+k) = *(startIt-1+j);
				k = j;
			}
		}//while
		*(startIt-1+k) = v;


		//����
		v = *(startIt-1+i);

		heap = false;

		for ( k = i; !heap; )	
		{
			j = k/2;
			if (j<1)
			{
				break;
			}

			if ( !lessFunc( *(startIt-1+k),*(startIt-1+j) ) )
			{
				*(startIt-1+k) = *(startIt-1+j);
					k = j;
			}
			else
			{
				heap = true;
			}
		}//for
		
		*(startIt-1+k) = v;
	}























}//HeapSort
