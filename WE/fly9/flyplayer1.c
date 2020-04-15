#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define width 600
#define hight 500
#define r 50

//己机结构体



struct Mplane
{
	int x;
	int y;
}myplane;
//敌机结构体
typedef struct EMplane
{
	int x;
	int y;
	struct EMplane * next;
}Eplane;
//子弹结构体
typedef struct bullet
{
	int x;
	int y;
	struct bullet * next;
}Bullet;

Bullet * mhead;
Eplane *ehead;
void gamestart()
{
	//initgraph(500, 600);
	myplane.x = myplane.y = 300;

	//己方飞机子弹的头结点；
	mhead = (Bullet *)malloc(sizeof(Bullet));
	mhead->x = myplane.x, mhead->y = myplane.y;
	mhead->next = NULL;

	//敌机头节点
	Eplane *ehead = (Eplane *)malloc(sizeof(Eplane));
	ehead->next = NULL;

}

void addnode(int i)//增加节点；
{
	

	switch (i)
	{
	case 1:
		Bullet * tem;
		tem = (Bullet *)malloc(sizeof(Bullet));//增加子弹节点；
		tem->x = myplane.x, tem->y = myplane.y;
		tem->next=mhead->next,mhead->next=tem;
		break;
	case 2:
		Eplane * etem;
		etem = (Eplane *)malloc(sizeof(Eplane));
		etem->next = ehead->next, ehead->next = etem;
		break;
	}
}

void bulletmove()
{
	Bullet * p = mhead->next,*pre;
	while (p!= NULL)
	{
		p->y-=1;
		p=p->next;
	}

	pre = mhead, p = mhead->next;
	while (p!=NULL)
	{
		if (p->y <= 0)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
			p = p->next;
	}
	
}


void gameprintf()
{
	//cleardevice();
	system("cls");
	Bullet * p = mhead,*q;
	//绘制飞机；
	//circle(myplane.x, myplane.y,40);
	printf("己方飞机为(%d,%d)\n", myplane.x, myplane.y);
	//绘制自己飞机子弹；
	while (p!= NULL)
	{
		/*circle(p->x, p->y,10);
		Sleep(1);*/
		printf("己方子弹为（%d,%d）\n", p->x, p->y);
		p = p->next;
	}
	
}

void gameinput()//用户的键盘操作；
{
	char c;
	
	if (_kbhit())
	{
		c = _getch();
		switch (c)
		{
		case 'a':myplane.x-=20;
			break;
		case 's':myplane.y+=20;
			break;
		case 'd':myplane.x+=20;
			break;
		case 'w':myplane.y-=20;
			break;
		case 'x': addnode(1);//发射子弹
			break;
		}
	}

}

int main()
{
	
	gamestart();
	while (1)
	{
		
		bulletmove();
		gameprintf();
		gameinput();
		
	}
	return 1;
}










/*int main()
{
	int x=250, y=300;
	int i = 5;
	initgraph(width,hight);
	while (1)
	{	
		cleardevice();
		circle(x, y, r);
		x += i, y += i;
		if (x >= (width - r) || (y >= hight - r)||x<r||y<=r)
			i = -i;
		Sleep(20);
		
	}
	return 0;
}*/