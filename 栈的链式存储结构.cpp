#include <malloc.h>
typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LinkStNode;

typedef int ElemType;

void InitStack(LinkStNode*& s)//³õÊ¼»¯Õ»
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestoryStack(LinkStNode*& s)//Ïú»ÙÕ»
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool StackEmpty(LinkStNode* s)//ÅĞ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	return(s->next == NULL);
}

void Push(LinkStNode*& s, ElemType e)//½øÕ»
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LinkStNode*& s, ElemType& e)//³öÕ»
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode* s, ElemType& e)//È¡Õ»¶¥ÔªËØ
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}