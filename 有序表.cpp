//除ListInsert()算法与顺序表有差别，其余均相同

void ListInsert1(SqList*& L, ElemType e)//有序顺序表插入数据元素
{
	int i = 0, j;
	while (i < L->length && L->data[i] < e)
		i++;
	for (j = ListLength(L); j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
}

void ListInsert2(LinkNode*& L, ElemType e)//有序单链表插入数据元素
{
	LinkNode* pre = L, * p;
	while (pre->next != NULL && pre->next->data < e)
		pre = pre->next;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = pre->next;
	pre->next = p;
}

void UnionList(SqList* LA, SqList* LB, SqList*& LC)//顺序表存放有序表的二路归并
{
	int i = 0, j = 0, k = 0;
	LC = (SqList*)malloc(sizeof(SqList));
	while (i < LA->length && j < LB->length)
	{
		if (LA->data[i] < LB->data[j])
		{
			LC->data[k] = LA->data[i];
			i++; k++;
		}
		else {
			LC->data[k] = LB->data[j];
			j++; k++;
		}
	}
	while (i < LA->length)
	{
		LC->data[k] = LA->data[i];
		i++; k++;
	}
	while (j < LB->length)
	{
		LC->data[k] = LB->data[j];
		j++; k++;
	}
	LC->length = k;
}

void UnionList1(LinkNode* LA, LinkNode* LB, LinkNode*& LC)//单链表存放有序表的二路归并
{
	LinkNode* pa = LA->next, * pb = LB->next, * r, * s;
	LC = (LinkNode*)malloc(sizeof(LinkNode));
	r = LC;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
		}
		else {
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pb->data;
			r->next = s;
			r = s;
			pb = pb->next;
		}
	}
	while (pa!=NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = pa->data;
		r->next = s;
		r = s;
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = pb->data;
		r->next = s;
		r = s;
		pb = pb->next;
	}
	r->next = NULL;
}