#include <malloc.h>
#define MaxSize 50

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
typedef int ElemType;

void InitQueue1(SqQueue*& q)//��ʼ������
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestroyQueue1(SqQueue*& q)//���ٶ���
{
	free(q);
}

bool QueueEmpty1(SqQueue* q)//�ж��Ƿ�Ϊ��
{
	return(q->front == q->rear);
}

bool enQueue1(SqQueue*& q, ElemType e)//������
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool deQueue1(SqQueue*& q, ElemType& e)//������
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//���ζ���//

void InitQueue2(SqQueue*& q)//��ʼ��
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

//�������ж��Ƿ�Ϊ�ղ���ͬ��

bool enQueue2(SqQueue*& q, ElemType e)//������
{
	if ((q->rear + 1) % MaxSize == q->front)
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool deQueue2(SqQueue*& q, ElemType& e)//������
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}