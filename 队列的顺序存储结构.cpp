#include <malloc.h>
#define MaxSize 50

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
typedef int ElemType;

void InitQueue1(SqQueue*& q)//初始化队列
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestroyQueue1(SqQueue*& q)//销毁队列
{
	free(q);
}

bool QueueEmpty1(SqQueue* q)//判断是否为空
{
	return(q->front == q->rear);
}

bool enQueue1(SqQueue*& q, ElemType e)//进队列
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool deQueue1(SqQueue*& q, ElemType& e)//出队列
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//环形队列//

void InitQueue2(SqQueue*& q)//初始化
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

//销毁与判断是否为空操作同上

bool enQueue2(SqQueue*& q, ElemType e)//进队列
{
	if ((q->rear + 1) % MaxSize == q->front)
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool deQueue2(SqQueue*& q, ElemType& e)//出队列
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}