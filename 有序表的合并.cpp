//有序表合并————顺序表实现
void MergeList_Sq(SqLiat LA,SqList LB,SqList &LC){
	pa=LA.elem;
	pb=LB.elem;							//指针pa和pb的初值分别指向两个表的第一个元素
	LC.length=LA.length+LB.length;		//新表长度为待合并两表之和
	LC.elem=new ElemType[LC.length]pc=LC.elem;
	pa_last=LA.elem+LA.length-1;
	pb_last=LB.elem+LB.length-1;
	while(pa<=pa_last&&pb<=pb_last){	//两个表都非空
		if(*pa<=*pb){					//依次摘取两表中值较小的结点
			*pc++=*pa++;
		}
		else{
			*pc++=*pb++;
		}
	}
	while(pa<=pa_last){
		*pc++=*pa++;
	}
	while(pb<=pb_last){
		*pc++=*pb++;
	}


//有序表合并————顺序表实现
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	pa=La->next;
	pb=Lb->next;
	pc=Lc=La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	delete Lb;      
}





