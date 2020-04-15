#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#define width 1200
#define hight 1000
#define r 50

//己机结构体
struct Mplane
{
	int x;
	float y;//x,y为坐标轴；
	int hp;//生命值；
}myplane,wingplane;

//补给结构体
typedef struct _supply
{
	float  x;
	float  y;
	short int type;
}Supply;

//敌机结构体
typedef struct EMplane
{
	int x;
	float y;//x,y为坐标；
	int hp;//生命值；
	short int type;//敌机类型编号；
	struct EMplane * next;
}Eplane;
//子弹结构体
typedef struct bullet
{
	float x;
	float y;
	short int force;
	struct bullet * next;
}Bullet;

DWORD t1, t2, t3, t4,t5,t6,t7,t8;
Bullet * mhead;
Eplane *ehead;
Bullet *ebullet;
Bullet *wbullet;
//游戏初始化；
void gamestart()
{
	srand(time(NULL));
	initgraph(width, hight);
	t1 = t5 =t3= t7=GetTickCount();

	//己方飞机；
	myplane.x = width / 2, myplane.y = hight - 300;
	myplane.hp = 10000;

	//己方飞机子弹的头结点；
	mhead = (Bullet *)malloc(sizeof(Bullet));
	mhead->x = myplane.x, mhead->y = myplane.y;
	mhead->next = NULL;

	//僚机初始化；
	wingplane.x=width/4,wingplane.y=hight-300;
	//敌机头节点
	ehead = (Eplane *)malloc(sizeof(Eplane));
	ehead->x = 0, ehead->y = 0;
	ehead->next = NULL;

	//敌机子弹
	ebullet = (Bullet*)malloc(sizeof(Bullet));
	ebullet->x = 0, ebullet->y = 0;
	ebullet->next = NULL;

	BeginBatchDraw();

}

//增加链表节点，1为子弹，2为敌机；
void addnode(int i,char o)
{


	switch (i)
	{
	case 1:
		Bullet * tem;
		tem = (Bullet *)malloc(sizeof(Bullet));//增加子弹节点；
		if(o=='m')
		tem->x = myplane.x, tem->y = myplane.y;
		if(o=='w')
		tem->x = wingplane.x, tem->y = wingplane.y;

		tem->next = mhead->next, mhead->next = tem;
		break;
	case 2:
		Eplane * etem;//增加敌机的节点；
		etem = (Eplane *)malloc(sizeof(Eplane));
		etem->x = rand() % (width-30); etem->y = 0; etem->hp = etem->type = rand() % 3 + 1;
		etem->next = ehead->next, ehead->next = etem;
		break;
	}
}

//敌方子弹链表节点的增加；
void addebullet(short int x, float y, short int type)//敌机子弹的发射；
{
	Bullet * ebtem;//增加子弹节点；
	ebtem = (Bullet *)malloc(sizeof(Bullet));
	ebtem->force = type;
	ebtem->x = x, ebtem->y = y;
	ebtem->next = ebullet->next, ebullet->next = ebtem;
}

//敌方子弹的移动，攻击效果；
void ebulletmove()//敌机子弹的移动；
{
	Bullet * p = ebullet->next, *pre;
	Bullet * m1 = ebullet->next, *m;
	while (p != NULL)
	{
		p->y += 0.4;
		p->x -=(p->x-myplane.x)*0.003;//追踪敌机；
		p = p->next;
	}

	pre = ebullet, p = ebullet->next;
	while (p != NULL)
	{
		if (p->y >= hight)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			if (pow(fabs(p->x - myplane.x), 2) + pow(fabs(p->y - myplane.y), 2) <= 900)
			{
				myplane.hp -= p->force;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else 
				if(pow(fabs(p->x - wingplane.x), 2) + pow(fabs(p->y - wingplane.y), 2) <= 900)
			{
				wingplane.hp -= p->force;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			
				else
			{
				pre = pre->next;
				p = p->next;
			}
		}
	}

	pre = ebullet, p = ebullet->next;

	while (p)
	{
		m = mhead->next;
		m1 = mhead;
		while (m)
		{
			if (p && (pow(fabs(p->x - m->x), 2) + pow(fabs(m->y - p->y), 2) <= 600))
			{
				m1->next = m->next;
				free(m);
				m = m1->next;

				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else
			{
				m1 = m1->next;
				m = m->next;
			}

		}
		if (p)
		{
			pre = pre->next;
			p = p->next;
		}


	}

}

//己方子弹的移动；
void bulletmove()
{
	Bullet * p = mhead->next, *pre;
	while (p != NULL)
	{
		p->y -= 0.35;//移动速度；
		p = p->next;
	}

	pre = mhead, p = mhead->next;
	while (p != NULL)//遍历检索，场外释放；
	{
		if (p->y <= 0)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = pre->next;
			p = p->next;
		}

	}
}

//己方子弹的生成；
void creatmybullet()
{
	t8 = GetTickCount();
	if (t8 - t7 > 700)
	{
			addnode(1, 'm');
			addnode(1, 'w');
			t7 = t8;
	}

}

//游戏暂停；
void stop()
{
	char c;
	while (1)
	{
		if (_kbhit)
		{
			c = _getch();
			if (c = 's')
				break;
		}
	}
}

//敌机的移动,敌机的移动过程相撞；
void eplanemove()
{
	Eplane * p = ehead->next, *pre;
	while (p)
	{
		p->y += 0.1;
		p = p->next;
	}

	pre = ehead, p = ehead->next;
	while (p != NULL)
	{
		if (p->y > hight || p->hp <= 0)//飞出场外或hp=0;
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		//敌机自己飞机相碰；
		else
			if (pow(fabs(p->x - myplane.x), 2) + pow(fabs(p->y - myplane.y), 2) <= 900)
			{
				myplane.hp -= 10 * p->type;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
		//敌机与僚机相碰；
			else
			{
				if (pow(fabs(p->x - wingplane.x), 2) + pow(fabs(p->y - wingplane.y), 2) <= 1000)

				{
					wingplane.hp -= 10 * p->type;
					pre->next = p->next;
					free(p);
					p = pre->next;
				}

				else
				{
					pre = pre->next;
					p = p->next;
				}
			}
			
	}
}

//游戏进行图形绘制；
void gameprintf()
{
	cleardevice();
	//system("cls");
	Bullet * p = mhead->next;
	//绘制飞机；
	circle(myplane.x, myplane.y, 40);
	//printf("己方飞机为(%d,%f)\n", myplane.x, myplane.y);

	//绘制僚机；

	solidpie(wingplane.x - 80 ,wingplane.y - 80, wingplane.x + 80, wingplane.y + 80, -0.7, 3.7615);

	//绘制自己飞机子弹；
	while (p != NULL)
	{
		circle(p->x, p->y, 10);
		//printf("己方子弹为（%d,%f）\n", p->x, p->y);
		p = p->next;
	}
	//绘制敌机；
	Eplane * e = ehead->next;
	while (e)
	{
		switch (e->type)
		{
		case 1:rectangle(e->x - 20, e->y - 20, e->x + 20, e->y + 20);
			break;
		case 2:solidcircle(e->x, e->y, 20);
			break;
		case 3:solidpie(e->x - 20, e->y - 20, e->x + 20, e->y + 20, 60, 120);
			break;

		}

		//printf("敌机（%d,%f）\n", e->x, e->y);
		e = e->next;
	}
	//绘制敌方子弹；
	Bullet  * eb = ebullet->next;
	while (eb)
	{
		switch (eb->force)
		{
		case 1:
			solidpie(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 1, 2.114159);
			eb = eb->next;
			break;
		case 2:
			solidroundrect(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 18, 12);
			eb = eb->next;
			break;
		case 3:
			arc(eb->x - 15, eb->y - 15, eb->x + 15, eb->y + 15, 1, 2.114159);
			eb = eb->next;
			break;
		}

	}

}

//攻击逻辑
void bulletstrikt()
{
	Bullet * m = mhead->next, *m1 = mhead;
	Eplane * e = ehead->next, *e1 = ehead;

	while (e)
	{
		m = mhead->next;
		m1 = mhead;
		while (m)
		{
			if (pow(fabs(m->x - e->x), 2) + pow(fabs(m->y - e->y), 2) <= 900)
			{
				e->hp--;
				m1->next = m->next;
				free(m);
				m = m1->next;
			}
			else
			{
				m1 = m1->next;
				m = m->next;
			}

		}

		e = e->next;
	}
}

//用户交互操作处理；
void gameinput()
{
	char c;

	if (_kbhit())
	{
		c = _getch();
		switch (c)
		{
		case 'q':myplane.x -= 20;
			break;
		case 'e':myplane.y += 20;
			break;
		case 'r':myplane.x += 20;
			break;
		case 'w':myplane.y -= 20;
			break;
		case 'k':stop();//游戏暂停；
			break;
		case 'd':myplane.x = wingplane.x;
			myplane.y = wingplane.y + 60;
			break;
		}
	}
	MOUSEMSG wmove;
	while (MouseHit())
	{
		wmove = GetMouseMsg();
		if (wmove.uMsg == WM_MOUSEMOVE)
			wingplane.x =wmove.x, wingplane.y = wmove.y;
		
	}

}

//产生敌机；
void createplane()
{
	t2 = GetTickCount();
	if (t2 - t1 >= 2500)
	{
		addnode(2,'i');
		t1 = t2;
	}


	//敌机发射子弹；
	Eplane * e = ehead->next;
	short int i = 0;//用于分开子弹的发射；
	t4 = GetTickCount();
	if (t4 - t3 >= 1300)
	{
		
		while (e)
		{
			if (i % 2)
			{
				addebullet(e->x, e->y, e->type);
				e = e->next;
				i += 1;
			}
			else
			{
				e = e->next;
				i += 1;
			}
		}
		t3 = t4;
	}
}

//随机生成补给；
void creatsupply()
{
	t6 = GetTickCount();
	if(t6-t5>=5000)
	{
	Supply* sup1 =(Supply *)malloc(sizeof(Supply));
	sup1->x = rand() % 300 + 400, sup1->y = rand() % 300 + 500;
	t5 = t6;
	}

}


//主调函数；
int main()
{

	gamestart();
	while (1)
	{
		
		while (0)
		{


			bulletmove();
			gameprintf();
			FlushBatchDraw();
		}

		createplane();
		bulletmove();
		eplanemove();
		ebulletmove();
		bulletstrikt();
		creatmybullet();
		gameprintf();
		FlushBatchDraw();
		gameinput();
		

	}


	return 1;
}









