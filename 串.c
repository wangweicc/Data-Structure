//串的顺序存储结构
#define MAXLEN 255
Typedef struct{
	char ch[MAXLEN+1];
	int length;
}SString;


//串的模式匹配算法
//BF算法
int StrIndex(SString S,int pos,SString T){
	//从串S的下标pos起，串T第一次出现的位置
	int i,j;
	if(T.length==0){
		return 0;
	}
	i=pos;
	j=0;
	while(i<S.length&&j<T.length){
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=T.length){
		return i-j+1;
	}
	else{
		return 0;
	}
}



//KMP算法
int Index_KMP(SString S,SString T,int pos){
	int i=pos;
	j=1;
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>T.length){
		return i-T.length;
	}
	else{
		return 0;
	}
}


//next函数算法
void get_next(SString T,int next[])
{
	i=1;
	next[l]=0;
	j=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;
			++j;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}
}
