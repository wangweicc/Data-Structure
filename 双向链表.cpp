//双向链表的插入
void ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//在带头结点的双向循环链表L中第i个位置之前插入元素e
	if(!(p=GetElemP_DuL(L,i))){
		return ERROR;
	}
	s=new DuLNode;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}


//双向链表的删除
void ListDelete_Dul(DuLink &L,int i,ElemType &e){
	//删除带头结点的双向循环链表L的第i个元素，并用e返回
	if(!(p=GetElemP_DuL(L,i))){
		return ERROR;
	}
	e=p->data;
	p->prioor->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return OK;
}





