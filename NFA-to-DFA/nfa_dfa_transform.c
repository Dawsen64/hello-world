#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"NFA_DFA.h"

int main()
{
	int i, j;
	printf("请输入状态集大小：");
	scanf("%d", &status_num);
	printf("请输入字符集大小：");
	scanf("%d", &chars_num);

	char* NFA_status = malloc(sizeof(char) * (status_num + 1));//存储NFA状态集,状态用单个表示字符，如p,q,r
	onechar* DFA_status = malloc(sizeof(onechar) * pow(2, status_num));//存储DFA状态集
	onechar* chars = malloc(sizeof(onechar) * chars_num);//存储字符集

	printf("请输入状态集：（如pqrsh）");
	scanf("%s", NFA_status);

	printf("请输入字符集：");
	for (i = 0; i < chars_num; i++)
	{
		scanf("%s", (chars + i)->block);
		getchar();
	}
	onechar** NFA_chart = (onechar*)malloc(sizeof(onechar*) * status_num);//用于存储NFA的转移表
	for (i = 0; i < status_num; i++)
	{
		NFA_chart[i] = malloc(sizeof(onechar) * chars_num);
	}
	//用于存储DFA的转移表
	onechar** DFA_chart = (onechar*)malloc(sizeof(onechar*) * pow(2, status_num));//DFA的状态集最多不超过NFA状态集的子集数量
	for (i = 0; i < pow(2, status_num); i++)
	{
		DFA_chart[i] = malloc(sizeof(onechar) * chars_num);
	}

	for (i = 0; i < pow(2, status_num); i++)//把转移表中的各个状态初始化为空字符串
	{
		for (j = 0; j < chars_num; j++)
		{
			DFA_chart[i][j].block[0] = '\0';
		}
	}
	printf("请输入NFA转移表：(用#表示空状态)\n");
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


	
