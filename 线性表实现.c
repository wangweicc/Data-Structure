//线性表
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef int ElemType; 

typedef struct
{
	ElemType *elem; // 存放首地址的指针变量 
	int arr[MAX_SIZE];//定义数组arr长度为100
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
	printf("请输入你要插入的元素(输入-1终止输入)\n");
	for (i = 0;i < MAX_SIZE;i ++)
	{
		scanf("%d",&value);
		if (value == -1)
		{
			break;
		}
		list->elem[list->length] = value;
		list->length++;
	}
	
}  //顺序插入 

void ListInsert (SeqList *list)//在position处插入元素，使线性表长度加一 
{
	int position;
	int value;
	int i;
	while (1)
	{
	printf("请输入要插入元素的位置：(输入-1终止输入)\n");
	scanf("%d",&position);
	printf("请输入要插入元素的值：\n");
	scanf("%d",&value);

	if (position == -1)
	{
		break;
	} 
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
	break;
	}
	}
}  //插入在position处插入value 
	


int ListDelete (SeqList *list,int position ,int *value)
{
	if (position < 0||position > list-> length||position >= MAX_SIZE)//对position位置进行判断 
	{
		return -1;
	}
	*value = list->arr[position-1];
	int i;
	for ( i = position - 1;i < position;i++)//将position位置前元素前移 
	{
		list->arr[i] = list->arr[i+1];	
	}
	list->length--;
	return 0 ;
}//删除position处元素 

void printList(SeqList *list)
{
	int i;
	for (i=0 ; i<list->length ;i++)
	{
		printf("%d\n",list->elem[i]);
		printf("\n");
	}
	printf("\n");
} //打印线性表 

int GetElem (SeqList *list,int position ,int *value)
{
	if (position < 1 || position > list->length)
	{
		return -1;//返回失败的返回值 
	}
	*value = list->arr[position - 1];
	return 0;//返回成功的返回值 
}  //获取position处的值 

int PriorElem(SeqList *list,int position,int *value)
{
	if (position < 2 || position > list->length)
	{
		return -1;
	}
	*value = list->arr[position - 2];
	return 0 ;
} //获取前驱元素 

int NextElem(SeqList *list,int position,int *value)
{
	if (position < 0 || position > list->length)
	{
		return -1;
	}
	*value = list->arr[position];
	return 0 ;
}//获取后继元素 



void Menu()
{
	printf("===================线性表基础操作=============\n"); 
	printf("===================1.创建线性表===============\n"); 
	printf("===================2.在指定位置插入元素=======\n"); 
	printf("===================3.获取指定元素=============\n"); 
	printf("===================4.获取前驱元素=============\n"); 
	printf("===================5.获取后继元素=============\n"); 
	printf("===================6.检查表长=================\n"); 
	printf("===================7.打印线性表===============\n"); 
	printf("===================8.检查表是否为空表=========\n"); 
	printf("===================9.销毁线性表===============\n"); 
	printf("===================0.退出菜单=================\n"); 
	printf("===================线性表基础操作=============\n"); 
	printf("===================线性表基础操作=============\n"); 
	printf("===================线性表基础操作=============\n"); 
	printf("===================线性表基础操作=============\n"); 
} 

int main (void)
{

	 
	SeqList list;
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
	printf("%d\n",next_e);*/
	InitList (&list);
	Insert(&list);
	ListInsert(&list);
	ListEmpty(&list);
	ListLength(&list);
	printList(&list);
	DestroyList(&list);
	

}
