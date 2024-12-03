#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define InitSize 50
using namespace std;
#define LISTSIZE 100  //宏定义的常量表示线性表的最大长度
typedef int DataType;  //制定顺序表中的数据元素的类型为整型
typedef struct{
	int data[LISTSIZE];  //线性表占用的数组空间
	int length;  //线性表的实际长度
}SeqList;
void del_dupnum(SeqList &L)  //删除重复元素
{
	int min=L.data[0];
	int tmp=L.data[0];
	for(int i=1;i<=L.length;i++)
	{
		if(L.data[i]==tmp)
		{
			L.data[i]=min;
		}
		else
		{
			tmp=L.data[i];	
		}
	}
	int p=1,q=1;
	while(q<=L.length){
		if(L.data[q]!=min)
		{
			L.data[p]=L.data[q];
			p++;
		}
		q++;
	}
	L.length=p-1;
}

void print(SeqList &L)  //打印顺序表中的数据元素
{
	int i=0;
	for(i=0;i<=L.length-1;i++)
	{
		cout<<L.data[i]<<" ";
	}
}

int main()
{
	SeqList L={{1,1,2,2,2,3,4,5,5,5,8,9,9,10,10,10,10,10,10,11},20};  //顺序表L，包含数据元素和顺序表长度
	cout<<"原本顺序表里面的元素有:"<<" ";
	print(L);
	del_dupnum(L);
	printf("\n");
	cout<<"进行去重后，顺序表里面的元素有:"<<" ";
	print(L);  //打印验证是否删除成功
	return 0;
}