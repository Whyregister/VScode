#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#define width 1400
#define hight 900
#define R 50

//数字雨
#define cou	50
#define	len	11
//系数；
char thedigitalrain[60][12];//数字雨数组
int posit[cou];

char creatrandalp()
{
	char c;
	while (1)
	{
		c = rand() % 123;
		if (c >= 65 && c <= 91 || c >= 97 && c <= 122)
			return c;
	}
}

void creatdrain()
{
	short int i, j;
	for (i = 0; i < cou; i++)
	{
		for (j = 0; j < len; j++)
		{
			thedigitalrain[i][j] = creatrandalp();
		}
	}
}

void POSITrain()
{
	int i;
	for (i = 0; i < cou; i++)	posit[i] = rand() % width;
}

void Raining(int r,int g,int b)//开始下雨；
{
	int i, j;
	for (i = 0; i < cou; i++)
	{
		settextcolor(RGB(255, 255, 255));
		for (j = 0; j < len; j++)
		{

			settextstyle(20, 5, _T("黑体"));

			outtextxy(i * 25, posit[i] - 10 * j, thedigitalrain[i][j]);
			settextcolor(RGB(b*(255 - 15 * j),g*(255 - 15 * j),b*(255 - 15 * j)));
		}
	}

	for (i = 0; i < cou; i++)	posit[i] += 3;

	for (i = 0; i < cou; i++)
		if (posit[i] - 15 * 10 > hight)
			posit[i] = 0;
}

//己机结构体
struct Mplane
{
	int x;
	float y;//x,y为坐标轴；
	int hp;//生命值；
	int Damage;//输出伤害
}*myplane,*wingplane;

//补给结构体
typedef struct _supply
{
	float  x;
	float  y;
	short int type;
	struct _supply * next;
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
	short int type;
	struct bullet * next;
}Bullet;

DWORD t1, t2, t3, t4,t5,t6,t7,t8;
Bullet * mhead;
Eplane *ehead;
Bullet *ebullet;
Bullet *wbullet;
Supply *Sup;


int Score=1200;

//游戏初始化；
void gamestart()
{
	srand(time(NULL));
	initgraph(width, hight);
	t1 = t5 =t3= t7=GetTickCount();

	//积分
	Score = 12000;

	//己方飞机；
	myplane = (Mplane*)malloc(sizeof(Mplane));
	myplane->x = width / 2, myplane->y = hight - 300;
	myplane->hp = 10000;

	//己方飞机子弹的头结点；
	mhead = (Bullet *)malloc(sizeof(Bullet));
	mhead->x = myplane->x, mhead->y = myplane->y;
	mhead->next = NULL;

	//僚机初始化；
	wingplane = (Mplane*)malloc(sizeof(Mplane));
	wingplane->x=width/4,wingplane->y=hight-300;
	
	//敌机头节点orBOSS
	ehead = (Eplane *)malloc(sizeof(Eplane));
	ehead->x = 0, ehead->y = 0, ehead->hp = 0;
	ehead->next = NULL;

	//敌机子弹
	ebullet = (Bullet*)malloc(sizeof(Bullet));
	ebullet->x = 0, ebullet->y = 0;
	ebullet->next = NULL;

	//补给初始化
	Sup =(Supply *)malloc(sizeof(Supply));
	Sup->y = 0, Sup->type = 0, Sup->x = 0;
	Sup->next = NULL;

	//雨的初始化
	POSITrain();
	creatdrain();

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
		tem->x = myplane->x, tem->y = myplane->y;
		tem->force = 9;
		if(o=='w')
		tem->x = wingplane->x, tem->y = wingplane->y;
		tem->force = 9;
		tem->next = mhead->next, mhead->next = tem;
		break;
	case 2:
		Eplane * etem;//增加敌机的节点；
		etem = (Eplane *)malloc(sizeof(Eplane));
		etem->x = rand() % (width-140)+70; etem->y = 0; etem->hp = etem->type = rand() % 3 + 1;
		etem->next = ehead->next, ehead->next = etem;
		break;
	}
}

//敌方子弹链表节点的增加；
void addebullet(short int x, float y, short int type)//敌机子弹的发射；
{
	Bullet * ebtem;//增加子弹节点；
	ebtem = (Bullet *)malloc(sizeof(Bullet));
	ebtem->force =ebtem->type=type;
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
		switch (p->type)
		{
		case 1:
			p->y += 0.8;
			p->x -= 0.005*(p->x - myplane->x);//追踪敌机；
			p = p->next;
			break;
		case 2:
			p->y += 0.8;
			p->x -= 0.005*(p->x - myplane->x);//追踪敌机；
			p = p->next;
			break;
		case 3:
			p->y += 1;
			p->x -= 0.005*(p->x - myplane->x);//追踪敌机；
			p = p->next;
			break;
		case 4:
		case 5:
			p->y += 1;
			p = p->next;
			break;
		case 6:
			p->y += 1;
			p->x -= 0.001*(p->x - myplane->x);//追踪敌机；
			p = p->next;
			break;
		default:
			p->y += 1;
			p->x -= 0.0001*p->type;//追踪敌机；
			p = p->next;
			break;
		}
		
	}

	pre = ebullet, p = ebullet->next;
	while (p != NULL)
	{
		if (p->y >= hight||p->force<=0)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			if (pow(fabs(p->x - myplane->x), 2) + pow(fabs(p->y - myplane->y), 2) <= 900)
			{
				myplane->hp -= p->force;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else 
				if(pow(fabs(p->x - wingplane->x), 2) + pow(fabs(p->y - wingplane->y), 2) <= 900)
			{
				wingplane->hp -= p->force;
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

	p = ebullet->next;
	int tem;
	while (p)
	{
		m = mhead->next;
		while (m)
		{
			if ((pow(fabs(p->x - m->x), 2) + pow(fabs(m->y - p->y), 2) <= 600))
			{
				tem=p->force;
				p->force -= m->force;
				m->force -= tem;

				m = m->next;

			}
			else
			{
				m = m->next;
			}

		}
			p = p->next;
	}

	

}

//己方子弹的移动；
void bulletmove()
{
	Bullet * p = mhead->next, *pre;
	while (p != NULL)
	{
		p->y -= 2;//移动速度；
		p = p->next;
	}

	pre = mhead, p = mhead->next;
	while (p != NULL)//遍历检索，场外释放；
	{
		if (p->y <= 0||p->force<=0)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
			if (ehead->hp >= 0)
			{
				if (pow(fabs(ehead->x - p->x), 2) + pow(fabs(p->y - ehead->y), 2) <= 4900)
				{
					ehead->hp -= p->force;
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
	if (t8 - t7 > 400)
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
	c = _getch();
			
	switch (c)
			
	{
			
	case 's':break;
			
	case 'i':Score += 2000;
			break;
	}
		
	
}

//敌机的移动,敌机的移动过程相撞；
void eplanemove()
{
	Eplane * p = ehead->next, *pre;
	while (p)
	{
		p->y += 1;
		p = p->next;
	}

	pre = ehead, p = ehead->next;
	while (p != NULL)
	{
		if (p->y > hight)//飞出场外或hp=0;
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
			if (p->hp <= 0)
			{
				Score += p->type*5;
				pre->next = p->next;
				free(p);
				p = pre->next;
				
			}
		//敌机与我方飞机相碰；
		else
			if (pow(fabs(p->x - myplane->x), 2) + pow(fabs(p->y - myplane->y), 2) <= 900)
			{
				myplane->hp -= 10 * p->type;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
		//敌机与僚机相碰；
			else
			{
				if (pow(fabs(p->x - wingplane->x), 2) + pow(fabs(p->y - wingplane->y), 2) <= 1000)

				{
					wingplane->hp -= 5 * p->type;
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
	
	

	//绘制雨
	
	//绘制飞机；
	circle(myplane->x, myplane->y, 40);
	//printf("己方飞机为(%d,%f)\n", myplane->x, myplane->y);

	//绘制僚机；
	solidpie(wingplane->x - 80 ,wingplane->y - 80, wingplane->x + 80, wingplane->y + 80, -0.7, 3.7615);

	//绘制自己飞机子弹；
	Bullet * p = mhead->next;
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
		switch (eb->type)
		{
		case 1:
		case 4:
			solidpie(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 1, 2.114159);
			eb = eb->next;
			break;
		case 2:
		case 5:
			solidroundrect(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 18, 12);
			eb = eb->next;
			break;
		case 3:
		case 6:
			arc(eb->x - 15, eb->y - 15, eb->x + 15, eb->y + 15, 1, 2.114159);
			eb = eb->next;
			break;
		default:
			solidpie(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 1, 2.114159);
			eb=eb->next;
			break;
		}

	}

	//绘制补给；
	Supply * su = Sup->next;
	while (su)
	{
		//switch (su->type)
		//{
		//case 2:
			setfillcolor(RGB(0, 255, 0));
			fillcircle(su->x, su->y,50);
		//}
		su = su->next;

	}

	//绘制boss
	if (ehead->hp > 0)
	{
		circle(ehead->x, ehead->y, 100);
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
				e->hp-=m->force;//敌机掉血；
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
		case 'q':myplane->x -= 20;
			break;
		case 'e':myplane->y += 20;
			break;
		case 'r':myplane->x += 20;
			break;
		case 'w':myplane->y -= 20;
			break;
		case 'k':stop();//游戏暂停；
			break;
		case '1':Score += 2000;
			break;
		case 'd':myplane->x = wingplane->x;
			myplane->y = wingplane->y + 60;
			break;
		}
	}
	MOUSEMSG wmove;
	while (MouseHit())
	{
		wmove = GetMouseMsg();
		if (wmove.uMsg == WM_MOUSEMOVE)
			wingplane->x =wmove.x, wingplane->y = wmove.y;
		
	}

}

//产生敌机；
void createplane()
{
	t2 = GetTickCount();
	if (t2 - t1 >= 1500)
	{
		addnode(2,'i');
		t1 = t2;
	}


	//敌机发射子弹；
	Eplane * e = ehead->next;
	short int i = 0;//用于分开子弹的发射；
	t4 = GetTickCount();
	if (t4 - t3 >= 300)
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
	if(t6-t5>=8000&&!Sup->next)
	{
	Supply* sup1 =(Supply *)malloc(sizeof(Supply));
	sup1->x = rand() % (width-160) + 80, sup1->y = rand() % (hight-300) + 150,sup1->type=rand()%3;
	sup1->next = Sup->next, Sup->next = sup1;
	t5 = t6;
	}
	else
		if (t6 - t5 >= 8000 && Sup->next)
		{
			free(Sup->next);
			Sup->next = NULL;
			t5 = t6;
		}

	Supply * sup2 = Sup->next,*s=Sup;
	while (sup2)
	{
		if (pow(fabs(sup2->x - myplane->x), 2) + pow(fabs(sup2->y - myplane->y), 2) <= 900)
		{
			switch (sup2->type)
			{
			default:
				break;
			}
			s->next = sup2->next;
			free(sup2);
			sup2 = s->next;
		}
		else
			if (pow(fabs(sup2->x - wingplane->x), 2) + pow(fabs(sup2->y - wingplane->y), 2) <= 900)
			{
				switch (sup2->type)
				{
					;
				}
				s->next = sup2->next;
				free(sup2);
				sup2 = s->next;
			}
			else
			{
				sup2 = sup2->next;
				s = s->next;
			}

	}

}

//BOSS的生成；
void number1()
{
	ehead->x = width / 2, ehead->y = 100;
	ehead->type = 5,ehead->hp=1000;
}

float vx=1.5, vy=1;

void boss1move()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ehead->x+= vx, ehead->y+= vy;
	if (ehead->x > width - 30 || ehead->x < 30)
		vx = -vx;
	if (ehead->y >= 400 || ehead->y < 30)
		vy = -vy;
}

//敌方boss的子弹发射


//各种移动；

void MOVE()
{
	bulletmove();
	eplanemove();
	ebulletmove();
}

//各种生成；
void CREATTHING()
{
	creatmybullet();
	createplane();
	creatsupply();
}


//主调函数；
int main()
{

	gamestart();
	while (1)
	{
		
		while (Score>=1000)
		{
			number1();//Boss的初始化

			while (ehead->hp>0)
			{
			creatmybullet();//产生己方子弹；

			bulletmove();//子弹的移动；
			


			ebulletmove();

			t4 = GetTickCount();
			if (t4-t3>=100)
			{
				addebullet(ehead->x, ehead->y, rand() % 10-5);//-5-4
				t3 = t4;
			}
			
			
			creatdrain();
			Raining(0, 0, 1);

			gameprintf();//游戏的绘制；

			//creatsupply();//补给的生成；

			eplanemove();

			ebulletmove();

			boss1move();//boss的移动；

			gameinput();//用户的输入；
			FlushBatchDraw();
			cleardevice();
			}
			break;
			
		}
		
		
		CREATTHING();
		MOVE();
		bulletstrikt();
		//数字雨；
		creatdrain();
		Raining(0, 1, 0);
		
		gameprintf();
		FlushBatchDraw();
		gameinput();
		cleardevice();

	}


	return 1;
}


/*1,数字雨
2，补给的掉落；
3，关卡BOSS
4,血条
5，*/









