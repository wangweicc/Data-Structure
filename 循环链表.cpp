//循环链表
//带尾指针循环链表的合并
LinkList Connect(LinkList Ta,LinkList Tb)	//假设Ta、Tb都是非空的单循环链表
	p=Ta->next;								//p存表头结点
	Ta->next=Tb->next->next;				//Tb表头连结Ta表尾
	delete Tb->next;						//释放Tb表头结点
	Tb->next=p;								//修改指针
	return Tb;
}