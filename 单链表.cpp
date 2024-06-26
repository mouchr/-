#include <iostream>

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;

typedef int ElemType;

void CreateListF(LinkNode*& L, ElemType a[], int n)//头插法
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(LinkNode*& L, ElemType a[], int n)//尾插法
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void InitList(LinkNode*& L)//初始化
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode*& L)//销毁线性表
{
	LinkNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool ListEmpty(LinkNode* L)//判断是否为空表
{
	return(L->next == NULL);
}

int ListLength(LinkNode* L)//求线性表的长度
{
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return(n);
}

void DispList(LinkNode* L)//输出线性表
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

bool GetElem(LinkNode* L, int i, ElemType& e)//求线性表中的某个数据元素值
{
	int j = 0;
	LinkNode* p = L;
	if (i <= 0) return false;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		e = p->data;
		return true;
	}
}

int LocateElem(LinkNode* L, ElemType e)//按元素值查找
{
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)    //不存在返回0
		return(0);
	else return(i);    //存在返回逻辑序号i
}

bool ListInsert(LinkNode*& L, int i, ElemType e)//插入数据元素
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)//删除数据元素
{
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}