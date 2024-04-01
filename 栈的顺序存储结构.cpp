#include <malloc.h>
#define MaxSize 50

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
typedef int ElemType;

void InitStack(SqStack*& s)//初始化栈
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestoryStack(SqStack*& s)//销毁栈
{
	free(s);
}

bool StackEmpty(SqStack* s)//判断栈是否为空
{
	return (s->top == -1);
}

bool Push(SqStack*& s, ElemType e)//进栈
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack*& s, ElemType& e)//出栈
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack* s, ElemType& e)//取栈顶元素
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

void trans(char* exp, char postexp[])//将中缀表达式转换为后缀表达式
{
	char e;
	SqStack* Optr;
	InitStack(Optr);
	int i = 0;
	while (*exp != '\0')
	{
		switch (*exp)
		{
		case '(':
			Push(Optr, '(');
			exp++;
			break;
		case ')':
			Pop(Optr, e);
			while (e != '(')
			{
				postexp[i++] = e;
				Pop(Optr, e);
			}
			exp++;
			break;
		case '+':
		case '-':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e != '(')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else break;
			}
			Push(Optr, *exp);
			exp++;
			break;
		case '*':
		case '/':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e == '*' || e == '/')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else break;
			}
			Push(Optr, *exp);
			exp++;
			break;
        default:
			while (*exp >= '0' && *exp <= '9')
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';
		}
	}
	while (!StackEmpty(Optr))
	{
		Pop(Optr, e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';
	DestoryStack(Optr);
}

int compvalue(char* postexp)//后缀表达式求值（若函数为double类型，注意将所有用到的函数均定义为double类型）
{
	double d, a, b, c, e;
	SqStack* Opnd;
	InitStack(Opnd);
	while (*postexp != '\0')
	{
		switch (*postexp)
		{
		case '+':
			Pop(Opnd, a);
			Pop(Opnd, b);
			c = b + a;
			Push(Opnd, c);
			break;
		case '-':
			Pop(Opnd, a);
			Pop(Opnd, b);
			c = b - a;
			Push(Opnd, c);
			break;
		case '*':
			Pop(Opnd, a);
			Pop(Opnd, b);
			c = b * a;
			Push(Opnd, c);
			break;
		case '/':
			Pop(Opnd, a);
			Pop(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				Push(Opnd, c);
				break;
			}
			else {
				printf("\n\t除零错误！\n");
				exit(0);
			}
			break;
		default:
			d = 0;
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push(Opnd, d);
			break;
		}
		postexp++;
	}
	GetTop(Opnd, e);
	DestoryStack(Opnd);
	return e;
}