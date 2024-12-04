//数据结构单链表操作算法设计

int ListLength_L(Linklist)	//求单链表的表长
{
	LinkList p;
	p=L->next;
	i=0;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}


Status GetElem_L(LinkList L,int i,ElemType &e)	//获取线性表L中的某个数据元素的内容，通过变量e返回
{
	p=L->next;	//初始化
	j=1;
	while(p&&j<i)	//向后扫描，直到p指向第i个元素过p为空
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)		//第i个元素不存在
	{
		return ERROR;
	}
	e=p->data;		//取第i个元素
	return OK;
}


Lnode *LocateElem_L(LinkList L,ElemType e)	//在线性表L中查找值为e的数据元素
{
	//找到，则返回L中值为e的数据元素的地址，查找失败返回NULL
	while(p&&p->data!=e)
	{
		p=L->next;
	}
	return p;
}


Lnode *LocateElem_L(LinkList L,ElemType e)	//在线性表L中查找值为e的位置序号
{
	//找到，则返回L中值为e的数据元素的位置序号，查找失败返回NULL
	p=L->next;
	j=1;
	while(p&&p->data!=e){
		p=p->next;
		j++;
	}
	if(p){
		return j;
	}
	else{
		return 0;
	}
}


