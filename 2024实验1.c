/*   
（为方便测试，其中元素定义为：typedef  int  Elemtype，数组容量设为20）
编程实现以下功能：
由用户输入2个递增有序的整型元素的顺序表A和B，其中A的容量大于A+B的有效长度。请把A和B按序合并后放在A中，A和B中若有重复元素，合并后只存1次，然后输出顺序表的内容。
请按照以上要求编程，并把源程序文件和执行文件在此上传。若执行文件直接上传系统不接收，可以上传压缩文件
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 20

typedef int ElemType; 

typedef struct
{
	int *elem; // 存放首地址的指针变量 
	int length;//线性表的长度 
} SeqList;//结构体名

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

// 合并两个有序表
void MergeLists(SeqList *A, SeqList *B)
{
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length)
    {
        if (A->elem[i] < B->elem[j])
        {
            A->elem[k++] = A->elem[i++];
        }
        else if (A->elem[i] > B->elem[j])
        {
            A->elem[k++] = B->elem[j++];
        }
        else
        {
            A->elem[k++] = A->elem[i++]; // 保留一个相同元素
            j++;
        }
    }

    // 将剩余的A或B中的元素添加到A中
    while (i < A->length)
    {
        A->elem[k++] = A->elem[i++];
    }

    while (j < B->length)
    {
        A->elem[k++] = B->elem[j++];
    }

    A->length = k;
}

int main ()
{
	SeqList listA, listB;

    // 初始化两个顺序表
    InitList(&listA);
    InitList(&listB);

    // 输入顺序表A
    printf("请输入顺序表A的元素（递增有序，输入-1终止）：\n");
    Insert(&listA);

    // 输入顺序表B
    printf("请输入顺序表B的元素（递增有序，输入-1终止）：\n");
    Insert(&listB);

    // 检查A的容量是否足够
    if (listA.length + listB.length > MAX_SIZE)
    {
        printf("A的容量不足以容纳A和B的合并结果，请重新运行程序。\n");
        return 1;
    }

    // 合并A和B到A中
    MergeLists(&listA, &listB);

    // 打印合并后的A
    printf("合并后的顺序表A:\n");
    printList(&listA);

    // 释放内存
    free(listA.elem);
    free(listB.elem);

    return 0; 
	
}
