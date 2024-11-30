//线性表
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef int ElemType; 

typedef struct
{
	int *elem; // 存放首地址的指针变量 
	int length;//线性表的长度 
} SeqList;//结构体名 
/*
目前函数汇总：
1.InitList初始化线性表   把线性表长度置零
2.DestroyList销毁线性表  把线性表长度置零
3.ListEmpty检查是否为空表  空表返回1，非空返回0
4.ListLength返回表长  返回数值list->length
5.ListInsert插入元素  在position处插入数值
6.printList 打印线性表
7.GetElem  获取元素  获取position处的值 
8.PriorElem 获取先驱元素  获取position-1处的值
9.NextElem 获取后继元素  获取position+1处的值
10ListDelete  删除表中元素  目前存在问题 

//int arr[MAX_SIZE];//定义数组arr长度为100

*////////////
void InitList(SeqList *list)//线性表初始化，把线性表长度置零 
{
	list->length = 0;//初识线性表长度为零
	list->elem = (ElemType *)malloc(MAX_SIZE*sizeof(ElemType));
	//list->elem 为存储空间基址，，(ElemType*)为int *型内存 ，， MAX_SIZE*sizeof(ElemType) 为内存100与4乘积一共四百字节 
	if (list->elem == NULL)//判断是否分配成功 
	{
		printf("Memory allocation failed！\n");
		printf("初始化失败\n"); 
		exit(1);
	} 
	else
	{
		printf("初始化成功\n"); 
	}
}

void DestroyList(SeqList *list)
{
	if(list->elem != NULL)
	{
		free(list->elem);
		printf("删除成功\n"); 
		list->elem = NULL;
	} 
	list->length = 0;
} 


void ListEmpty(SeqList *list)
{
	if (list->length==0)
	{
	printf("是一个空表\n");
	}
	else
	{
	printf("不是空表\n");
	} 
}   //测试是否为空表，为空表返回1，返回不为0 


void ListLength(SeqList *list)
{
	printf("线性表的长度是%d\n",list->length);
} //返回表长，并以数值进行返回 


void Insert (SeqList *list)
{
	int i;
	int value; 
	printf("请输入你要创建的列表元素(输入-1终止输入)\n");
	for (i = 0;i < MAX_SIZE;i++)
	{
		scanf("%d",&value);
		if (value == -1)
		{
			printf("结束创建线性表！\n");
			break;
		}
		list->elem[list->length] = value;
		list->length++;
	}
}  //顺序插入 

void ListInsert (SeqList *list)//在position处插入元素，使线性表长度加一 
{
	int position;
	int j ;
	int value;
	int i;
	for (i = 0; i < MAX_SIZE ;i++)
	{
		printf("请输入要插入元素的位置(输入-1结束)：");
		scanf("%d",&position);
		if (position == -1)
		{
			printf("结束插入操作！\n");
			break;
		}
		printf("请输入要插入元素的值：");
		scanf("%d",&value);
		if (position < 0||position > list-> length||position >= MAX_SIZE)//对position位置进行判断 
		{
			printf("输入无效，位置无效或者列表已满\n");
		}
		else
		{
	 		for ( i = list->length ;i > position ;i--)
			{
			list->elem[i] = list->elem[i-1];	
			}
			list->elem[position] = value;
			list->length++;
			printf("元素已经成功插入\n");
		}
	}
}//插入在position处插入value

void ListDelete (SeqList *list)
{
	int position;
	int *value;
	int i;
	int j;
	for (j = 0 ; j < MAX_SIZE ;j++)
	{
		printf("请输入要删除元素的位置(输入-1结束删除)：");
		scanf("%d",&position); 
		if (position == -1)
		{
			printf("结束删除操作！\n");
			break;
		}
		if (position < 0||position > list-> length||position >= MAX_SIZE)//对position位置进行判断 
		{
			printf("输入的删除位置不合法！\n");
			break;
		}
	
		for ( i = position - 1;i < list->length-1 ; ++i)//将position位置前元素前移 
		{
			list->elem[i] = list->elem[i+1];	
		}
		list->length--;
		printf("删除成功\n");
}
	//break ;
}//删除position处元素 

void printList(SeqList *list)
{
	int i;
	printf("线性表如下\n"); 
	for (i=0 ; i<list->length ;i++)
	{
		printf("%d\t",list->elem[i]);
	}
	printf("\n");
} //打印线性表 

void GetElem (SeqList *list)
{
	int position;
	int value;
	int i,j;
	for (i = 0; i < list->length ; i++ )
	{
		printf("请输入要获取元素的位置(输入-1结束获取)：\n");
		scanf("%d",&position);
		if (position == -1)
		{
			printf("结束获取元素！\n");
			break;
		}
		value = list->elem[position-1];
		if (position < 1 || position > list->length)
		{
			printf("输入位置无效\n");
			break;
		}
		printf("该位置元素为%d\n",value);
	}
}  //获取position处的值 

void PriorElem(SeqList *list)
{
	int position,value;
	int i;
	for (i = 0 ; i < list->length; i++)
	{	
	printf("请输入要获取前驱元素的位置(输入-1结束获取)：");
	scanf("%d",&position); 
	if (position < 2 || position > list->length)
	{
		break;
	}
	if (position == -1)
	{
		printf("结束输入！\n");
		break;
	}
	value = list->elem[position - 2];
	printf("该前驱元素为%d\n",value);
	}

} //获取前驱元素 

void NextElem(SeqList *list)
{
	int position,value;
	int i;
	for (i = 0 ; i < list->length; i++)
	{	
	printf("请输入要获取后继元素的位置：");
	scanf("%d",&position); 
	if (position < 0 || position > list->length)
	{
		break;
	}
	if (position == -1)
	{
		break;
	}
	value = list->elem[position];
	printf("该后继元素为%d\n",value);
	}

}//获取后继元素 



void Menu()
{
	int choice;
	SeqList list;
	int i;
	printf("-------------------线性表基础操作-------------\n"); 
	printf("-------------------0.退出菜单-----------------\n"); 
	printf("-------------------1.创建线性表---------------\n"); 
	printf("-------------------2.输入线性表元素-----------\n"); 
	printf("-------------------3.获取指定元素-------------\n"); 
	printf("-------------------4.获取前驱元素-------------\n"); 
	printf("-------------------5.获取后继元素-------------\n"); 
	printf("-------------------6.检查表长-----------------\n"); 
	printf("-------------------7.打印线性表---------------\n"); 
	printf("-------------------8.检查表是否为空表---------\n"); 
	printf("-------------------9.销毁线性表---------------\n"); 
	printf("-------------------10.按指定位置插入元素------\n");
	printf("-------------------11.按指定位置删除元素------\n");
	
	for(i = 0 ; i < INT_MAX ; i++)
	{
		printf("请输入线性表操作对应的序号：");
		scanf("%d",&choice);
		if(choice < 0 || choice > 11 )
		{
			printf("输入不合法，请重新输入!\n");
			continue;
		}
		else
		{
			switch(choice)
			{
				case 0: printf("退出菜单成功!\n"); exit(0); //退出菜单
				case 1: InitList(&list); break;
				case 2: Insert(&list); break;
				case 3: GetElem(&list); break;
				case 4: PriorElem(&list); break;
				case 5: NextElem(&list); break;
				case 6: ListLength(&list); break;
				case 7: printList(&list); break;
				case 8: ListEmpty(&list); break;
				case 9: DestroyList(&list); break;
				case 10: ListInsert(&list); break;
				case 11: ListDelete(&list); break;
			}
		}
	} 
} 

int main (void)
{	
	SeqList list;
	Menu();
	/*InitList (&list);
	Insert(&list);
	printList(&list); 
	ListInsert(&list);
	printList(&list); */ 

}



/*	int i;
	while(1)
	{
		Menu();
		scanf("请选择对线性表的操作%d",i);
		switch(i)
		{
			case 0: exit(0) ; //退出系统
			case 1: InitList(&list) ; //创建线性表
			case 2; ListInsert(&list);
			
			 
		}
		
		
	}
*/
	
/*	InitList (&list);
	
	ListInsert(&list,0,10);
	ListInsert(&list,1,20);
	ListInsert(&list,2,30);
	ListInsert(&list,3,40);
	ListInsert(&list,4,50);
	ListInsert(&list,5,60);
	ListInsert(&list,6,70);
	ListInsert(&list,7,80);
	ListInsert(&list,8,90);
	ListInsert(&list,9,100);
	
	
	int length = ListLength(&list);
	printf("Length:%d\n",length);
	
	printList(&list);
	
	int e;
	GetElem(&list,1,&e);
	
	
	int pre_e;
	PriorElem(&list,2,&pre_e);
	
	
	int next_e;
	NextElem(&list,0,&next_e);
	
	int value;
	ListDelete(&list,2,&value);
	
	printList(&list);
	
	int length2 = ListLength(&list);
	
	printf("%d\n",length);
	
	int testvalue = ListEmpty(list);
	printf("%d\n",testvalue);
	
	DestroyList (&list);
	
	ListInsert(&list,0,120);
	
	printList(&list);
	
	
	printf("%d\n",e);
	printf("%d\n",pre_e);
	printf("%d\n",next_e);
	InitList (&list);
	Insert(&list);
	ListInsert(&list);
	ListEmpty(&list);
	ListLength(&list);
	GetElem(&list);
	PriorElem(&list);
	NextElem(&list); 
	printList(&list);
	ListDelete(&list);
	printList(&list);
	DestroyList(&list);*/
	


