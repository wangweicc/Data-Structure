//[1]ͷ�ļ�����
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*Ԥ��ʵ�ֹ��ܣ�
1.InitStack:����һ����ջS
2.DestroySack:����ջS
3.ClearStack:���ջS
4.StcakEmpty:ջ�շ���true,�ǿշ���false
5.GetTop:����ջ��Ԫ��
6.Push:����Ԫ����ջ��
7.Pop:��e����ջ��Ԫ��ֵ����ɾ��ջ��Ԫ��
8.StackPrint:��ӡջ������Ԫ��
*/

//[2]�궨�岿��
#define bool char
#define Init_MAX_SIZE 10
#define true 1
#define false 0
#define SElemType int

//[3]�ṹ�岿��
typedef struct SeqStack{
SElemType *base;//ջ��λ�ñ�ʶ
SElemType *top;//ջ��λ�ñ�ʶ
int data[Init_MAX_SIZE];//ջ���ݱ�����
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
    printf("ջ��ʼ���ɹ�\n");
}

void DestroySack(SeqStack *S)
{
    if (S->base != NULL)
        {
            free(S->base);
            S->base = NULL;
            S->top = NULL;
            printf("ջ������")��
        }
}

void ClearStack(SeqStack *S)
{
    S->top = -1;
    if (S->top == S->base)
        {
            printf("ջ�����");
        }
}

void StcakEmpty(SeqStack *S)
{
    if (S->top == -1)
        {
            printf("ջΪ��ջ");
            return true;
        }
    else
        {
            printf("ջ��Ϊ��ջ");
            return false;
        }
}

void Push(SeqStack *s, SElemType e)
{
    if (s->top == Init_MAX_SIZE-1)
        {
            printf("ջ����\n");
        }
    if (StackEmpty(&S) == 1)
        {
            printf("ջΪ��ջ");
        }

}

void StackPrint (SeqStack *S)
{
    if (s->top == -1)
        {
            printf("ջ�ǿ�ջ");
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
