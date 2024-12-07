//[1]头文件部分
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*预期实现功能：
1.InitStack:构造一个空栈S
2.DestroySack:销毁栈S
3.ClearStack:清空栈S
4.StcakEmpty:栈空返回true,非空返回false
5.GetTop:返回栈顶元素
6.Push:插入元素至栈顶
7.Pop:用e返回栈顶元素值，并删除栈顶元素
8.StackPrint:打印栈中所有元素
*/

//[2]宏定义部分
#define bool char
#define Init_MAX_SIZE 10
#define true 1
#define false 0
#define SElemType int

//[3]结构体部分
typedef struct SeqStack{
SElemType *base;//栈底位置标识
SElemType *top;//栈顶位置标识
int data[Init_MAX_SIZE];//栈数据保存区
}SeqStack;

void InitStack(SeqStack *S)
{
    S->base = (SElemType*)malloc(Init_MAX_SIZE*sizeof(SElemType));
    if(!S->base)
        {
            exit(overflow_error);
        }
    S->base = -1;
    S->top = S->base;
    printf("栈初始化成功\n");
}

void DestroySack(SeqStack *S)
{
    if (S->base != NULL)
        {
            free(S->base);
            S->base = NULL;
            S->top = NULL;
            printf("栈已销毁")；
        }
}

void ClearStack(SeqStack *S)
{
    S->top = -1;
    if (S->top == S->base)
        {
            printf("栈已清除");
        }
}

void StcakEmpty(SeqStack *S)
{
    if (S->top == -1)
        {
            printf("栈为空栈");
            return true;
        }
    else
        {
            printf("栈不为空栈");
            return false;
        }
}

void Push(SeqStack *s, SElemType e)
{
    if (s->top == Init_MAX_SIZE-1)
        {
            printf("栈已满\n");
        }
    if (StackEmpty(&S) == 1)
        {
            printf("栈为空栈");
        }

}

void StackPrint (SeqStack *S)
{
    if (s->top == -1)
        {
            printf("栈是空栈");
            return;
        }
    int i;
    for( i = s->base ; i <= s->top ; i++)
    {
        printf("%d",s-data[i]);
    }
    printf("\n");
}










int main ()
{
    SeqStack Stack;
    return 0;
}
