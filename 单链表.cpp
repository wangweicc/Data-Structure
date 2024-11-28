//单链表的实现
/*
1.链式结构在逻辑上是连续的，在物理结构上不一定连续
2.结点一般是从堆上申请的
3.申请的空间，按照一定策略分配，可能连续可能不连续
4. ***链表的底层是通过指针将一个个零散的内存块链接起来，链表的每一个内存成为节点
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
//结点结构体
/*
链表结构体由两个部分组成
一个是数据域
一个是结构体指针（指针域） 
*/ 
typedef struct Node //***为什么有两个Node???
//struct后的 Node为结构体名，作用可以使他能够在结构体内外去使用
//Node最后的，表示 typedef的 新类型名称，作用在于下次使用不用关键字struct去声明变量 
{
	int data;//成员变量，用来存储节点的数据值 
	struct Node* next; //引用自己，因为Node这个名字没有完全定义好，所以用struct说明
	//同时 next指针指向Node ， 使得每一个结点都有指向下一个结点的链接 
}Node;
/*
typedef int Node*;
 
Node* create_node(int data) // 初始化操作 函数类型 Node* 为 int 
{
	Node* node = (Node*)malloc(MAX_SIZE*sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node; // 返回新创建的节点地址 
} 
*/
/*Node* create_list (int num)
{
	Node* head = create_node(1);//创建头结点 
	Node* tmp = head;//tmp为临时结点，作用为更新下一结点 
	int i;
	for (i = 2;i <= num ;++i)//为什么使用 ++i 而不是 i++ ?
	//不需要立即使用i的值的情况下，++i和i++都可以使用
	//但是在某些编译器的优化下++i会比i++更加高效
	//++i更直观地表现先增加的意图 
	{
		Node* node = create_node(i);//node为临时结点，作用为更新tmp同时创建新结点 
		tmp->next = node;
		tmp = node; //更新 
	}
}*/
int main()
{
	Node Node1 = {1 , NULL};//创建结点内容，数据域内容1，结点域内容空 
	
	return 0;
}

