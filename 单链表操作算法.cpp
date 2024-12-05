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


status ListInsert_L(LinkList &L,int i,ElemType e){	//在L中的第i个元素之前插入数据元素e
	p=l;
	j=0;
	while(p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i-1){
		return ERROR;
	}
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}


Status ListDelete_L(LinkList &L,int i,ElemType &e){	//将线性表L中第i个元素删除
	p=l;
	j=0;
	q=new LNode;
	while(p->next&&j<i-1){
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	e=q->data;
	delete q;
	return OK;
}


//头插法建立单链表
void CreateList_H(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	for(i=n;i>0;--i){
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}


//尾插法建立单链表
void CreateList_R(LinkList &L,int n){
	L=new LNode;
	r=new LNode;
	L->next=NULL;
	r=L;
	for(i=0;i<n;++i){
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

