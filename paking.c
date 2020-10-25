#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"
/*typedef struct { //定义车辆car的结构
	char plat[5];//车牌号
	int time;    //到达或离开的时间
}car;
typedef struct { //定义栈(停车场)
	car* base;   //栈底
	car* top;	 //栈顶
	int stacksize; // 当前可使用的最大容量
}Paking;*/
 ///main函数
int main(void)
{
	int n;
	int fee;//定义停车费的变量
	char ch; //存放到达或离去的信息
	char ch1, ch2;
	car ca, ca0, ca1;//临时存放输入的汽车的信息
	Queue Q;//定义队列
	car* carplace, *pre ,*pre0;  //将要离开汽车的位置//计数指针
	Paking P,P0;//P为停车场，P0为因让路而临时停放的栈
	//构造停车场P，P0，便道（队列）
	printf("请输入停车场长度n:(测试数据n=2)		");
	scanf("%d", &n);
	ch = getchar();
	printf("请输入停车费:（$/min）(测试数据fee=1)	");
	scanf("%d", &fee);
	ch = getchar();
	if (InitStack(&P,n) == OK && InitStack(&P0,n) == OK && InitQueue(&Q) == OK)
	{
		printf("停车场管理系统初始化成功!\n\n请输入汽车信息：(每输入一个数据请使用回车)\n");
	}
	else printf("初始化失败！\n");
	while ((ch = getchar()) != 'E')
	{
		ch1 = getchar();
		gets(ca.plat);
		scanf("%d", &ca.time);
		ch2 = getchar();
		/*printf("%c\n%s\n%d\n", ch, ca.plat, ca.time);*/
		//车辆离开停车场时，若停车场不满，先把若干汽车出栈再出停车场；
		//若停车场已满，把若干汽车出栈再出停车场后，便道第一辆车入栈，并把出停车场的汽车离开的时间置为该车进入停车场的时间
		if (ch == 'D')
		{
			carplace = search(P, ca);
			if (carplace + 1 == P.top) //若要离开的汽车在栈顶
			{   
				pop(&P, &ca0);//汽车直接出去，并把信息返回给ca0
					if (QueueEmpty(Q) == OK)//如果队列里有汽车
					{
						DeQueue(&Q, &ca1);
					//	printf("队列长度：%d\n", Q.QLength);
						push(&P, ca1);
						P.top->time = ca0.time;
					}
					printf("	停车时长：%d\n", ca.time - ca0.time);
					printf("	停车费：%d\n", (ca.time - ca0.time) * fee);
			}
			else  //要离开的汽车不在栈顶，在栈顶之前
			{
				while (P.top != carplace + 1)
				{
					pre0 = (car*)malloc(sizeof(car));
					if (!pre0)	printf("申请内存失败1！！");
					pop(&P, pre0);
					push(&P0, *pre0);
					free(pre0);
				}
					pop(&P, &ca0);
					while (P0.top != P0.base)//把P0里的汽车转移回来
					{
						pop(&P0, pre0);
						push(&P, *pre0);
					}
					if (QueueEmpty(Q) == OK)//如果队列里有汽车
					{
						DeQueue(&Q, &ca1);
						push(&P, ca1);
						P.top->time = ca0.time;
					}
					printf("	停车时长：%d\n", ca.time - ca0.time);
					printf("	停车费：%d\n", (ca.time - ca0.time) * fee);
				}
			}
		else if (ch == 'A' && StackLength(P)==P.stacksize) //停车场已满,汽车停入便道（队列）
		{
			EnQueue(&Q, ca);
			printf("	已停在便道%d号位.\n", Q.QLength);
		}
		else  //ch=='A',车辆进入停车场,输出汽车停的位置
		{
			push(&P, ca);
			printf("	已停在停车场%d号车位.\n", StackLength(P));
		}
	}
	return 0;
}