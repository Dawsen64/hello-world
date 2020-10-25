#ifndef _STACK_H_
#define _STACK_H_
#define OVERFLOW -1
#define OK 1
typedef struct car { //定义车辆car的结构
	char plat[5];//车牌号
	int time;    //到达或离开的时间
}car;
typedef struct { //定义栈(停车场)
	car* base;   //栈底
	car* top;	 //栈顶
	int stacksize; // 当前可使用的最大容量
}Paking;

typedef struct QNode{   //单链队列
	car vehicle;
    struct QNode* next;
}QNode;
typedef struct 
{   //单链队列，存储汽车的车牌信息
	QNode* front;  //队头
	QNode* rear;   //队尾
	int QLength;   //队列的长度
}Queue;
int InitStack(Paking* P, int n)  //构造一个空栈（停车场P）并初始化,n为栈的最大长度
{
	P->base = (car*)malloc(n*sizeof(car));
	if (!P->base) return OVERFLOW;
	P->top = P->base;
	P->stacksize = n;
	return OK;
}
int InitQueue(Queue* Q)  //构造一个队列，失败返回-1
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	Q->QLength = 0;   //队列的长度置为0
	if (!Q->front)
		return OVERFLOW;
	else return OK;
}

int StackLength(Paking P)  //返回栈的长度
{
	return P.top - P.base;
}
void push(Paking* P, car e)  //插入元素为e的新的栈顶元素
{
	*(P->top++) = e;
}
void pop(Paking* P, car* e)  //出栈
{
	if (!e)
	{
		printf("内存访问失败2！！");
	}
	*e = *(--P->top);
}
car* search(Paking P, car e)  //查找将要离开车辆的位置
{
	int i;
	for (i = 0; i < StackLength(P); i++)
	{
		if (strcmp((P.base + i)->plat, e.plat) == 0)
		{
			return (P.base + i);  //返回对应数组下标元素的位置指针
		}
			
	}
}
int QueueEmpty(Queue Q)  //判断队列是否为空，为空返回-1，不空返回1
{
	if (Q.front == Q.rear)	return OVERFLOW;
	else return OK;
}
void EnQueue(Queue* Q, car ca)//从队尾插入一个元素
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	if (!p)	printf("内存分配失败！！");
	else
	{
		p->vehicle = ca;
		Q->rear->next = p;
		Q->rear = p;
		Q->QLength++;
	}
}
void DeQueue(Queue* Q, car* ca)//从队头删除一个元素，并把该元素（汽车）返回ca中
{
	QNode* p;
	p = Q->front->next;
	*ca = p->vehicle;
	Q->front->next = p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	Q->QLength--;
}
#endif
