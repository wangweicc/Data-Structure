//哈夫曼树中权越大的叶子离根越近
//1.构造森林全是根
//2.选用两小造新树
//3.删除两小添新人
//重复2、3剩单根

//哈夫曼树构造算法的实现
typedef struct{
	int weight;
	itn parent,lch,rch;
}HTNode,*HuffmanTree;


//哈夫曼树的构造
void CreatHuffmanTree(HuffmanTree &HT,int n)
{
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1];  //0号单元未用，HT[m]表示根结点
	for(i=1;i<=n;i++)
	{
		scanf(HT[i].weight);
	}
	for(i=n+1;i<=m;++i)
	{
		Select(HT,i-1,s1,s2);  //在HT[k](1<=k<=i-1)中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1和s2
		HT[s1].parent=i;
		HT[s2].parent=i;  //表示从F中删除s1,s2
		HT[i].lch=s1;
		HT[i].rch=s2;  //s1和s2分别作为i的左右孩子
		HT.weight=HT[s1].weight+HT[s2].weight;  //i的权值为左右孩子的权值之和
	}
}