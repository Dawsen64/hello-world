#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"
/*typedef struct { //���峵��car�Ľṹ
	char plat[5];//���ƺ�
	int time;    //������뿪��ʱ��
}car;
typedef struct { //����ջ(ͣ����)
	car* base;   //ջ��
	car* top;	 //ջ��
	int stacksize; // ��ǰ��ʹ�õ��������
}Paking;*/
 ///main����
int main(void)
{
	int n;
	int fee;//����ͣ���ѵı���
	char ch; //��ŵ������ȥ����Ϣ
	char ch1, ch2;
	car ca, ca0, ca1;//��ʱ����������������Ϣ
	Queue Q;//�������
	car* carplace, *pre ,*pre0;  //��Ҫ�뿪������λ��//����ָ��
	Paking P,P0;//PΪͣ������P0Ϊ����·����ʱͣ�ŵ�ջ
	//����ͣ����P��P0����������У�
	printf("������ͣ��������n:(��������n=2)		");
	scanf("%d", &n);
	ch = getchar();
	printf("������ͣ����:��$/min��(��������fee=1)	");
	scanf("%d", &fee);
	ch = getchar();
	if (InitStack(&P,n) == OK && InitStack(&P0,n) == OK && InitQueue(&Q) == OK)
	{
		printf("ͣ��������ϵͳ��ʼ���ɹ�!\n\n������������Ϣ��(ÿ����һ��������ʹ�ûس�)\n");
	}
	else printf("��ʼ��ʧ�ܣ�\n");
	while ((ch = getchar()) != 'E')
	{
		ch1 = getchar();
		gets(ca.plat);
		scanf("%d", &ca.time);
		ch2 = getchar();
		/*printf("%c\n%s\n%d\n", ch, ca.plat, ca.time);*/
		//�����뿪ͣ����ʱ����ͣ�����������Ȱ�����������ջ�ٳ�ͣ������
		//��ͣ����������������������ջ�ٳ�ͣ�����󣬱����һ������ջ�����ѳ�ͣ�����������뿪��ʱ����Ϊ�ó�����ͣ������ʱ��
		if (ch == 'D')
		{
			carplace = search(P, ca);
			if (carplace + 1 == P.top) //��Ҫ�뿪��������ջ��
			{   
				pop(&P, &ca0);//����ֱ�ӳ�ȥ��������Ϣ���ظ�ca0
					if (QueueEmpty(Q) == OK)//���������������
					{
						DeQueue(&Q, &ca1);
					//	printf("���г��ȣ�%d\n", Q.QLength);
						push(&P, ca1);
						P.top->time = ca0.time;
					}
					printf("	ͣ��ʱ����%d\n", ca.time - ca0.time);
					printf("	ͣ���ѣ�%d\n", (ca.time - ca0.time) * fee);
			}
			else  //Ҫ�뿪����������ջ������ջ��֮ǰ
			{
				while (P.top != carplace + 1)
				{
					pre0 = (car*)malloc(sizeof(car));
					if (!pre0)	printf("�����ڴ�ʧ��1����");
					pop(&P, pre0);
					push(&P0, *pre0);
					free(pre0);
				}
					pop(&P, &ca0);
					while (P0.top != P0.base)//��P0�������ת�ƻ���
					{
						pop(&P0, pre0);
						push(&P, *pre0);
					}
					if (QueueEmpty(Q) == OK)//���������������
					{
						DeQueue(&Q, &ca1);
						push(&P, ca1);
						P.top->time = ca0.time;
					}
					printf("	ͣ��ʱ����%d\n", ca.time - ca0.time);
					printf("	ͣ���ѣ�%d\n", (ca.time - ca0.time) * fee);
				}
			}
		else if (ch == 'A' && StackLength(P)==P.stacksize) //ͣ��������,����ͣ���������У�
		{
			EnQueue(&Q, ca);
			printf("	��ͣ�ڱ��%d��λ.\n", Q.QLength);
		}
		else  //ch=='A',��������ͣ����,�������ͣ��λ��
		{
			push(&P, ca);
			printf("	��ͣ��ͣ����%d�ų�λ.\n", StackLength(P));
		}
	}
	return 0;
}