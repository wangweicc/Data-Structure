//二叉树的二叉链表存储表示
typedef struct BiTNode
{
	DataType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;


//二叉树的先序遍历
void PreOrder(BiTree bt)
{
	if(bt==NULL)
	{
		return;
	}
	else
	{
		Visit(bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}


//二叉树的中序遍历
void InOrder(BiTree bt)
{
	if(bt==NULL)
	{
		return ;	
	}
	else
	{
		InOrder(bt->lchild);
		Visit(bt->data);
		InOrder(bt->rchild);
	}
}


//二叉树的后序遍历
void PostOrder(BiTree bt)
{
	if(bt==NULL)
	{
		return;
	}
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		Visit(bt->data);
	}
}


//二叉树的层次遍历
void LevelOrder(BiTree bt)
{
	if(bt==NULL)
	{
		return;
	}
	InitQueue(Q);
	p=bt;
	InQueue(Q,p);
	while(!QueueEmpty(Q))
	{
		DelQueue(Q,p);
		VIsit(p->data);
		if(p->lchild)
		{
			InQueue(Q,p->lchild);	
		}
		if(p->rchild)
		{
			InQueue(Q,p->rchild);
		}
	}
}