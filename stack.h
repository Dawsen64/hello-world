#ifndef _STACK_H_
#define _STACK_H_
#define OVERFLOW -1
#define OK 1
typedef struct car { //���峵��car�Ľṹ
	char plat[5];//���ƺ�
	int time;    //������뿪��ʱ��
}car;
typedef struct { //����ջ(ͣ����)
	car* base;   //ջ��
	car* top;	 //ջ��
	int stacksize; // ��ǰ��ʹ�õ��������
}Paking;

typedef struct QNode{   //��������
	car vehicle;
    struct QNode* next;
}QNode;
typedef struct 
{   //�������У��洢�����ĳ�����Ϣ
	QNode* front;  //��ͷ
	QNode* rear;   //��β
	int QLength;   //���еĳ���
}Queue;
int InitStack(Paking* P, int n)  //����һ����ջ��ͣ����P������ʼ��,nΪջ����󳤶�
{
	P->base = (car*)malloc(n*sizeof(car));
	if (!P->base) return OVERFLOW;
	P->top = P->base;
	P->stacksize = n;
	return OK;
}
int InitQueue(Queue* Q)  //����һ�����У�ʧ�ܷ���-1
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	Q->QLength = 0;   //���еĳ�����Ϊ0
	if (!Q->front)
		return OVERFLOW;
	else return OK;
}

int StackLength(Paking P)  //����ջ�ĳ���
{
	return P.top - P.base;
}
void push(Paking* P, car e)  //����Ԫ��Ϊe���µ�ջ��Ԫ��
{
	*(P->top++) = e;
}
void pop(Paking* P, car* e)  //��ջ
{
	if (!e)
	{
		printf("�ڴ����ʧ��2����");
	}
	*e = *(--P->top);
}
car* search(Paking P, car e)  //���ҽ�Ҫ�뿪������λ��
{
	int i;
	for (i = 0; i < StackLength(P); i++)
	{
		if (strcmp((P.base + i)->plat, e.plat) == 0)
		{
			return (P.base + i);  //���ض�Ӧ�����±�Ԫ�ص�λ��ָ��
		}
			
	}
}
int QueueEmpty(Queue Q)  //�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���-1�����շ���1
{
	if (Q.front == Q.rear)	return OVERFLOW;
	else return OK;
}
void EnQueue(Queue* Q, car ca)//�Ӷ�β����һ��Ԫ��
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	if (!p)	printf("�ڴ����ʧ�ܣ���");
	else
	{
		p->vehicle = ca;
		Q->rear->next = p;
		Q->rear = p;
		Q->QLength++;
	}
}
void DeQueue(Queue* Q, car* ca)//�Ӷ�ͷɾ��һ��Ԫ�أ����Ѹ�Ԫ�أ�����������ca��
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
