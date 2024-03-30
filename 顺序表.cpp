#include <iostream>
#define MaxSize 50

typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

typedef int ElemType;

void CreateList(SqList*& L, ElemType a[], int n)//建立顺序表
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++; i++;
	}
	L->length = k;
}

void InitList(SqList*& L)//初始化顺序表
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void DestoryList(SqList*& L)//销毁顺序表
{
	free(L);
}

bool ListEmpyt(SqList* L)//判断线性表是否为空
{
	return(L->length == 0);
}

int ListLength(SqList* L)//求线性表的长度
{
	return(L->length);
}

void DispList(SqList* L)//输出线性表
{
	for (int i = 0; i < L->length; i++)
		printf("%d", L->data[i]);
	printf("\n");
}

bool GetElem(SqList* L, int i, ElemType& e)//求线性表中某个数据元素值
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList* L, ElemType e)//按元素值查找
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e)//插入数据元素
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[i] = e;
	L->length++;
	return true;
}

bool ListDelete(SqList*& L, int i, ElemType& e)//删除数据元素
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}