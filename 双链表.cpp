typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;

void CreateListF(DLinkNode*& L, ElemType a[], int n)//头插法
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void CreateListR(DLinkNode*& L, ElemType a[], int n)//尾插法
{
	DLinkNode* s, * r;
	L = (DLinkNode)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s= (DLinkNode)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s; s->prior = r;
		r = s;
	}
	r->next = NULL;
}

bool ListInsert(DLinkNode*& L, int i, ElemType e)//插入结点
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}

bool ListDelete(DLinkNode*& L, int i, ElemType& e)//删除结点
{
	int j = 0;
	DLinkNode* p = L, * q;
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
		if (q->next != NULL)
			q->next->prior = p;
		free(q);
		return true;
	}
}

/*把双链表改为循环列表的过程是将它的尾结点next指针域
  由原来为空改为指向头结点，将它的头结点prior指针域改
  为指向尾结点，整个双链表形成两个环*/