#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"NFA_DFA.h"

int main()
{
	int i, j;
	printf("������״̬����С��");
	scanf("%d", &status_num);
	printf("�������ַ�����С��");
	scanf("%d", &chars_num);

	char* NFA_status = malloc(sizeof(char) * (status_num + 1));//�洢NFA״̬��,״̬�õ�����ʾ�ַ�����p,q,r
	onechar* DFA_status = malloc(sizeof(onechar) * pow(2, status_num));//�洢DFA״̬��
	onechar* chars = malloc(sizeof(onechar) * chars_num);//�洢�ַ���

	printf("������״̬��������pqrsh��");
	scanf("%s", NFA_status);

	printf("�������ַ�����");
	for (i = 0; i < chars_num; i++)
	{
		scanf("%s", (chars + i)->block);
		getchar();
	}
	onechar** NFA_chart = (onechar*)malloc(sizeof(onechar*) * status_num);//���ڴ洢NFA��ת�Ʊ�
	for (i = 0; i < status_num; i++)
	{
		NFA_chart[i] = malloc(sizeof(onechar) * chars_num);
	}
	//���ڴ洢DFA��ת�Ʊ�
	onechar** DFA_chart = (onechar*)malloc(sizeof(onechar*) * pow(2, status_num));//DFA��״̬����಻����NFA״̬�����Ӽ�����
	for (i = 0; i < pow(2, status_num); i++)
	{
		DFA_chart[i] = malloc(sizeof(onechar) * chars_num);
	}

	for (i = 0; i < pow(2, status_num); i++)//��ת�Ʊ��еĸ���״̬��ʼ��Ϊ���ַ���
	{
		for (j = 0; j < chars_num; j++)
		{
			DFA_chart[i][j].block[0] = '\0';
		}
	}
	printf("������NFAת�Ʊ�(��#��ʾ��״̬)\n");
	for (i = 0; i < status_num; i++)
	{
		for (j = 0; j < chars_num; j++)
		{
			scanf("%s", NFA_chart[i][j].block);
			getchar();
		}
	}

	switch_NFAtoDFA(NFA_chart, DFA_chart, NFA_status, DFA_status);
	print(DFA_chart, DFA_status, NFA_chart, NFA_status, chars);
	Clear(NFA_status, NFA_chart,  DFA_status, DFA_chart, chars);
	system("pause");
	return 0;
}


	
