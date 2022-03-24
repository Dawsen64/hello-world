#ifndef _NFA_DFA_H_
#define _NFA_DFA_H_
#define MAX_NUM 20

//不超过二十个状态的NFA
typedef struct onechar
{
	char block[MAX_NUM];//用于存储一个20个字符的字符数组
}onechar;

int status_num, chars_num, num = 1;//status是NFA状态集数量，chars_num是字符集数量，num是DFA状态集数量。
void switch_NFAtoDFA(onechar** NFA_chart, onechar** DFA_chart, char* NFA_status, onechar* DFA_status);
void switch1(onechar** NFA_chart, onechar** DFA_chart, char* NFA_status, char* s, int n);
void analse_status(char* s1, char* s2);
void print(onechar** DFA_chart, onechar* DFA_status, onechar** NFA_chart, char* NFA_status, onechar* chars);
void Clear(char* NFA_status, onechar** NFA_chart, onechar* DFA_status, onechar** DFA_chart, onechar* chars);

void switch_NFAtoDFA(onechar** NFA_chart, onechar** DFA_chart, char* NFA_status, onechar* DFA_status)
{
	int i = 0, j = 0, n = 0, flag = 1;//NFA与DFA转移表的第一行是相同的，num是DFA的状态集数量
	DFA_status[0].block[0] = NFA_status[0];
	DFA_status[0].block[1] = '\0';
	while (n != num)
	{
		switch1(NFA_chart, DFA_chart, NFA_status, DFA_status[n].block, n);
		for (i = 0; i < chars_num; i++)
		{
			for (j = 0; j < num; j++)//n,表示已经求完第n个状态的转移函数
			{
				if (strcmp(DFA_chart[n][i].block, DFA_status[j].block) == 0)//不匹配说明是新状态(所有不匹配才可以)
				{
					flag = 0;//已存在的状态
				}
			}
			if (flag == 1 && DFA_chart[n][i].block[0] != '#')
			{
				strcpy(DFA_status[num].block, DFA_chart[n][i].block);
				num++;
			}
			flag = 1;
		}
		n++;
	}

}
void switch1(onechar** NFA_chart, onechar** DFA_chart, char* NFA_status, char* s, int n)
{
	//S是要匹配的DFA的新状态
	int i = 0, j, k;
	while (s[i] != '\0')
	{
		for (j = 0; j < status_num; j++)
		{
			if (s[i] == NFA_status[j])
			{
				for (k = 0; k < chars_num; k++)
				{
					analse_status(DFA_chart[n][k].block, NFA_chart[j][k].block);
				}
			}
		}
		i++;
	}
}

void analse_status(char* s1, char* s2)
{
	char s[MAX_NUM];
	int i = 0, j = 0, k = 0, flag = 1;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != '#')
		{
			s[j] = s1[i];
			j++;
		}
	}
	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] != '#')
		{
			for (k = 0; k < j; k++)
			{
				if (s2[i] == s[k])
					flag = 0;
			}
			if (flag == 1)
			{
				s[j] = s2[i];
				j++;
			}
			flag = 1;
		}
	}
	
	for (i = 0; i < j - 1; i++)//冒泡排序，防止出现pqr,rpq是不同状态
	{
		for (k = 0; k < j - 1; k++)
		{
			if (s[k] > s[k + 1])
			{
				char tmp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = tmp;
			}
		}
	}
	s[j] = '\0';
	if (j == 0)
	{
		s[0] = '#';
		s[1] = '\0';
	}
	strcpy(s1, s);
}

void print(onechar** DFA_chart, onechar* DFA_status, onechar** NFA_chart, char* NFA_status, onechar* chars)
{
	int i, j;
	//打印NFA
	printf("\n\n用户输入的NFA：\n\n");
	printf(" 状态\\字符     ");
	for (i = 0; i < chars_num; i++)
	{
		printf("%-10s", chars[i].block);
	}
	printf("\n");
	for (i = 0; i < status_num; i++)
	{
		printf("    %-10c", NFA_status[i]);
		for (j = 0; j < chars_num; j++)
		{
			printf("%-10s ", NFA_chart[i][j].block);
		}
		printf("\n");
	}
	printf("\n\n");
	//打印DFA
	printf("经计算得到的DFA：\n\n");
	printf(" 状态\\字符     ");
	for (i = 0; i < chars_num; i++)
	{
		printf("%-10s", chars[i].block);
	}
	printf("\n");
	for (i = 0; i < num; i++)
	{
		printf("    %-10s", DFA_status[i].block);
		for (j = 0; j < chars_num; j++)
		{
			printf("%-10s ", DFA_chart[i][j].block);
		}
		printf("\n");
	}
	return 0;
}
void Clear(char* NFA_status, onechar** NFA_chart, onechar* DFA_status, onechar** DFA_chart, onechar* chars)
{
	int i;
	free(NFA_status); NFA_status = NULL;
	for (i = 0; i < status_num; i++)
	{
		free(NFA_chart[i]);
		NFA_chart[i] = NULL;
	}
	free(NFA_chart); NFA_chart = NULL;

	free(DFA_status); DFA_status = NULL;
	for (i = 0; i < num; i++)
	{
		free(DFA_chart[i]);
		DFA_chart[i] = NULL;
	}
	free(DFA_chart); DFA_chart = NULL;
	free(chars); chars = NULL;
}
#endif
