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
#define cou	60
#define	len	15
float vx = 1.5, vy = 1;
float vx1 = 0.5, vy1 = 0.5;
int cloac=1;
//关卡系数；
float G=1;
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

			settextstyle(16, 10, _T("黑体"));

			outtextxy(i * 25, posit[i] - 10 * j, thedigitalrain[i][j]);
			settextcolor(RGB(r*(255-16*j),g*(255-16*j),b*(255-16*j)));
		}
	}

	for (i = 0; i < cou; i++)	posit[i] += 3;

	for (i = 0; i < cou; i++)
		if (posit[i] - 15 * 10 > width)
			posit[i] = 0;
}

void Raining2(int r, int g, int b)//开始下雨；
{
	int i, j;
	for (i = 0; i < cou; i++)
	{
		settextcolor(RGB(255, 255, 255));
		for (j = 0; j < len; j++)
		{

			settextstyle(16, 10, _T("黑体"));

			outtextxy( posit[i] - 15 * j,i * 35, thedigitalrain[i][j]);
			settextcolor(RGB(r*(255 - 16 * j), g*(255 - 16 * j), b*(255 - 16 * j)));
		}
	}

	for (i = 0; i < cou; i++)	posit[i] +=10;

	/*for (i = 0; i < cou; i++)
		if (posit[i] - 15 * 10 > hight)
			posit[i] = 0;*/
}

//己机结构体
struct Mplane
{
	float x;
	float y;//x,y为坐标轴；
	int hp;//生命值；
	short int q;
	short int w;
	short int e;
	short int r;
	short int force;
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
	float x;
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
	float Vx;
	short int force;
	short int type;
	struct bullet * next;
}Bullet;
float I=0;

float Wvx;

DWORD t1, t2, t3, t4,t5,t6,t7,t8,c1,c2,e1,e2,T,r1,r2;
Bullet * mhead;//我机子弹头；
Eplane *ehead;//敌机头；
Bullet *ebullet;//敌方子弹头；
Bullet *wbullet;//僚机子弹头；
Supply *Sup;//补给头；
float supplyx=0.6,supplyy=0.5;

int Score=1200;

float evx5 = 0.7;
//游戏初始化；
void gamestart()
{
	srand(time(NULL));
	initgraph(width, hight);
	T=r1=e1=c1=t1= t5 =t3= t7=GetTickCount();

	//积分
	Score = 0;

	//己方飞机；
	myplane = (Mplane*)malloc(sizeof(Mplane));
	myplane->x = width / 2, myplane->y = hight - 300;
	myplane->hp = 600;
	myplane->force = 1;
	myplane->q = myplane->w = myplane->e = myplane->r=0;

	//己方飞机子弹的头结点；
	mhead = (Bullet *)malloc(sizeof(Bullet));
	mhead->x = myplane->x, mhead->y = myplane->y;
	mhead->next = NULL;

	//僚机初始化；
	wingplane = (Mplane*)malloc(sizeof(Mplane));
	wingplane->x=width/4,wingplane->y=hight-300;
	wingplane->hp = 600;
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
void addnode(int i,short int type)
{
	Bullet * tem;
	Eplane * etem;
	tem = (Bullet *)malloc(sizeof(Bullet));
	switch (i)
	{
		
	case 1:
		
		//增加子弹节点；
		tem->x = myplane->x, tem->y = myplane->y;
		tem->type =type;
		tem->Vx = I;
		tem->force = 10;
		tem->next = mhead->next, mhead->next = tem;
		break;
	case 4:
		tem->x = wingplane->x, tem->y = wingplane->y;
		tem->force = 10;
		tem->type =type;
		tem->Vx = Wvx;
		tem->next = mhead->next, mhead->next = tem;
		break;
	case 2:
		//增加敌机的节点；
		etem = (Eplane *)malloc(sizeof(Eplane));
		etem->x = rand() % (width-140)+70; etem->y = 0; etem->hp = 30,etem->type=type;
		etem->next = ehead->next, ehead->next = etem;
		break;
	case 3:
		//增加3boss分机的节点；
		etem = (Eplane *)malloc(sizeof(Eplane));
		etem->x = ehead->x; etem->y = ehead->y; etem->hp = 100000;
		etem->type =type;
		etem->next = ehead->next, ehead->next = etem;
		break;
	case 5://子弹升级；
		tem->x = myplane->x+20, tem->y = myplane->y;
		tem->type = type;
		tem->Vx = I;
		tem->force = 10;
		tem->next = mhead->next, mhead->next = tem;
		break;
	case 6:
		tem->x = myplane->x - 20, tem->y = myplane->y;
		tem->type =type;
		tem->Vx = I;
		tem->force = 10;
		tem->next = mhead->next, mhead->next = tem;
		break;
	}
}

//敌方子弹链表节点的增加；
void addebullet(short int x, float y, short int type)//敌机子弹的发射；
{
	Bullet * ebtem;//增加子弹节点；
	ebtem = (Bullet *)malloc(sizeof(Bullet));
	ebtem->force =ebtem->type=type;
	ebtem->Vx = 5;
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
		case 1://普通子弹；
			p->y += 4;
			p = p->next;
			break;
		case 2:
			p->y += 4;
			p->x -= (p->x - myplane->x)*0.01;//追踪敌机；
			p = p->next;
			break;
		case 3:
			p->y += 4;
			p->x -= (p->x - myplane->x) / fabs(p->x - myplane->x)*1.5;//追踪敌机；
			p = p->next;
			break;	
		case 4://反弹子弹；
			
			if (p->x > width - 30 || p->x < 30)
			p->Vx = -p->Vx;
			p->x += p->Vx, p->y += 1.5;
			p = p->next;
			break;
		default:
			p->y += 2;
			p->x -= 0.07*p->type;//追踪敌机；
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
			if (pow(fabs(p->x - myplane->x), 2) + pow(fabs(p->y - myplane->y), 2) <=cloac*3155)
			{
				myplane->hp -= p->force;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else 
				if(pow(fabs(p->x - wingplane->x), 2) + pow(fabs(p->y - wingplane->y), 2) <=3155)
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
		
			
			if ((pow(fabs(p->x - m->x), 2) + pow(fabs(m->y - p->y), 2) <=200))
			{
				if (m->type ==210)
				{
					p->force -= m->type;
					m = m->next;
				}
				else
				{

				tem=p->force;
				p->force -= m->force;
				m->force -= tem;
				m = m->next;
				}
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
		switch (p->type)
		{
		case 11:
			p->x += 5;//右边
			p = p->next;
			break;
		case 12:
			p->x += 5;//右下
			p->y += 5;
			p = p->next;
			break;
		case 13:
			p->x -= 5;//左边；
			p = p->next;
			break;
		case 14:
			p->y += 5;//下边；
			p = p->next;
			break;
		case 15:
			p->y -= 5;//上边；
			p = p->next;
			break;
		case 16:
			p->x += 5;//右上；
			p->y -= 4;
			p = p->next;
			break;
		case 17:
			p->x -= 5;//左下；
			p->y += 4;
			p = p->next;
			break;
		case 18:
			p->x -= 5;//左上；
			p->y -= 4;
			p = p->next;
			break;
		case 19:
			p->y -= 4;
			p->x += Wvx;
			p = p->next;
			break;
		default:

		p->y -=4;//移动速度；
		p->x += p->Vx;
		p = p->next;
		
		break;
		}
		
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
				if (pow(fabs(ehead->x - p->x), 2) + pow(fabs(p->y - ehead->y), 2) <=22500+pow(p->type,2))
				{
					if (p->type == 210)
					{
					ehead->hp -=1;
					pre = pre->next;
					p = p->next;
					}
					else
					{
						ehead->hp -= p->force;
						myplane->Damage = p->force;
						pre->next = p->next;
						free(p);
						p = pre->next;
					}
					
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

float wvx=0.9, wvy=0.7;
//僚机的移动；
void wingplanemove()
{
	
	
	if (wingplane->x > width - 30 || wingplane->x < 30)
		wvx = -wvx;
	if (wingplane->y <= 500 || wingplane->y >=800)
		wvy = -wvy;
	wingplane->x += wvx, wingplane->y += wvy;

}

//己方子弹的生成；
void creatmybullet()
{
	e2=t8 = GetTickCount();
	if (t8 - t7 > 300)
	{
		if (e2 - e1 < 7000 && e1 !=T)
		{
			addnode(1, 11);
			addnode(1, 12);
			addnode(1, 13);
			addnode(1, 14);
			addnode(1, 15);
			addnode(1, 16);
			addnode(1, 17);
			addnode(1, 18);
			t7 = t8;
		}
		else
		{
			if (myplane->force > 30)
			{
				addnode(5, 10);
				addnode(6, 10);
				addnode(1, 10);

				t7 = t8;
			}
			else
			{
				addnode(4,19);
				addnode(1,10);
				t7 = t8;

			}
			
		}
			
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
	case 'n':ehead->hp -= 500;

	}
		
	
}

//敌机的移动,敌机的移动过程相撞；
void eplanemove()
{
	Eplane * p = ehead->next, *pre;
	while (p)
	{
		switch(p->type)
		{
	
		case 100:
		p->x += vx1, p->y -= vy1;
		if (p->x > width - 50 || p->x < 50)
			vx1 = -vx1;
		if (p->y >= 500 || p->y < 30)
		vy1 = -vy1;
		break;
	
		case 1:
			p->y += 2;
		case 2:
			p->y += 1;
		break;
		case 3:
			p->y += 0.8;
			break;
		case 4:
			p->x += 0.5;
			p->y += 1;
			break;
		case 5:
			p->x += evx5, p->y += 0.9;
			if (p->x > width - 50 || p->x < 50)
			evx5 = -evx5;
			break;
	}
		p = p->next;
	}

	pre = ehead, p = ehead->next;
	while (p != NULL)
	{
		if (p->y > hight||p->x>width-30)//飞出场外或hp=0;
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
			if (p->hp <= 0)
			{
				Score += p->type*10;
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
		//敌机与我方飞机相碰；
		else
			if (pow(fabs(p->x - myplane->x), 2) + pow(fabs(p->y - myplane->y), 2) <=6400*cloac&&p->type!=100)
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
	//绘制隐形；
	if (cloac<0)
		circle(myplane->x, myplane->y,70);
	//绘制飞机；
	circle(myplane->x, myplane->y, 55);
	setfillcolor(YELLOW);
	fillrectangle(width - 5-myplane->hp, 5, width - 5, 30);
	setfillcolor(NULL);

	//绘制僚机与血条；
	setfillcolor(YELLOW);
	solidpie(wingplane->x - 80 ,wingplane->y - 80,  wingplane->x + 80, wingplane->y + 80,-0.7,3.7615);

	/*setfillcolor(BLUE);
	fillrectangle(width- 5-wingplane->hp, 45, width - 5, 70);
	setfillcolor(NULL);*/

	//绘制自己飞机子弹；
	Bullet * p = mhead->next;
	while (p != NULL)
	{
		switch (p->type)
		{
			
		case 210:
			setfillcolor(RED);
			fillcircle(p->x, p->y,187);
			setfillcolor(NULL);
			p = p->next;
			break;
		default:
			setfillcolor(YELLOW);
			solidpie(p->x - 10, p->y - 10, p->x + 10, p->y + 10, 3.7615, -0.7);
			setfillcolor(NULL);
			p = p->next;
			break;
		}
		
		
	}
	
	setfillcolor(BLUE);
	//绘制敌机；
	Eplane * e = ehead->next;
	while (e)
	{
		switch (e->type)
		{
		case 1:rectangle(e->x - 40, e->y - 40, e->x + 40, e->y + 40);
			break;
		case 2:solidcircle(e->x, e->y, 40);
			break;
		case 3:solidpie(e->x - 40, e->y - 40, e->x + 40, e->y + 40, 60, 120);
			break;
		case 4:
			setfillcolor(YELLOW);
			solidpie(e->x - 40, e->y - 40,e->x+ 40,e->y + 40, -0.7, 3.7615);
			break;
		case 5:
			setfillcolor(GREEN);
			solidpie(e->x - 40, e->y - 40, e->x + 40, e->y + 40, -0.7, 3.7615);
			break;
		case 100:
			setfillcolor(GREEN);
			fillcircle(e->x, e->y, 100);
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
			setfillcolor(RED);
			fillrectangle(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9);
			eb = eb->next;
			setfillcolor(BLUE);
			break;
		case 2:
			solidroundrect(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 18, 12);
			eb = eb->next;
			break;
		case 3:
		case 6:
			arc(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9, 1, 2.114159);
			eb = eb->next;
			break;
		case 4:
			setfillcolor(GREEN);
			fillrectangle(eb->x - 9, eb->y - 9, eb->x + 9, eb->y + 9);
			setfillcolor(NULL);

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
		switch (su->type)
		{
			case 1:
			case 2:
			case 3:
				setfillcolor(GREEN);
				fillcircle(su->x, su->y, 30);
				setfillcolor(NULL);					//回血补给
				break;
			case 4:
			case 5:
				setfillcolor(BROWN);
				fillcircle(su->x, su->y, 30);
				setfillcolor(NULL);	//Q技能
				break;
			case 6:
			case 7:
				setfillcolor(MAGENTA);
				fillcircle(su->x, su->y, 30);
				setfillcolor(NULL);	//W技能
				break;
			case 8:
			case 9:
				setfillcolor(BLUE);
				fillcircle(su->x, su->y, 30);
				setfillcolor(NULL);	//e技能
				break;
			case 10:
				setfillcolor(RED);
				fillcircle(su->x, su->y, 30);
				setfillcolor(NULL);	//R技能；
				break;
			case 11:
				setfillcolor(RED);
				fillrectangle(su->x - 15, su->y - 15, su->x + 15, su->y + 15);
				setfillcolor(NULL);
				break;
			default:
				break;
		}
		su = su->next;

	}

	//绘制boss
	if (ehead->hp > 0)
	{
		setfillcolor(GREEN);
		fillcircle(ehead->x, ehead->y, 150);
		setfillcolor(NULL);
		//BOSS血条；
		setfillcolor(RED);
		fillrectangle(5, 5, ehead->hp / 2 + 5, 30);
		setfillcolor(NULL);
		settextcolor(GREEN); 
		TCHAR s[5];
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
			if (pow(fabs(m->x - e->x), 2) + pow(fabs(m->y - e->y), 2) <=1600+pow(m->type,2))
			{
				if (m->type ==210)
				{
					e->hp -= m->force;//敌机掉血；
					m1 = m1->next;
					m = m->next;
				}
				else
				{
					e->hp -= m->force;//敌机掉血；
					m1->next = m->next;
					free(m);
					m = m1->next;
				}
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
		case 'f':I=3;
			break;
		case 'd':I=-3;
			break;
		case 'q':
			if (myplane->q > 0)
			{
				addnode(1,210);
				myplane->q -= 1;
			}
			
			break;
		case 'w':
			if(myplane->w>0)
		{
				cloac = -1;
				c1 = GetTickCount();
				myplane->w -= 1;
		}
			break;
		case 'e':
			if (myplane->e > 0)
			{
				e1 = GetTickCount();
				myplane->e -= 1;
			}
			break;
		case 'r':
			if (myplane->r > 0)
			{
				r1 = GetTickCount();

				
				myplane->r -= 1;
			}
			
			break;
			
		case 'k':stop();//游戏暂停；
			break;
		case '1':Score += 2000;
			break;
		case '2':
			Wvx = -5;
			break;
		case '3':
			Wvx = 0;
			break;
		case '4':
			Wvx = 5;
			break;
		}
	}
	MOUSEMSG wmove;
	while (MouseHit())
	{
		wmove = GetMouseMsg();
		if (wmove.uMsg == WM_MOUSEMOVE)
			myplane->x =wmove.x, myplane->y = wmove.y;
		if (wmove.uMsg == WM_LBUTTONDOWN)
			I = 0;
		
	}

}

//产生敌机；
void createplane(short int t)
{
	t2 = GetTickCount();
	if (t2 - t1 >= 900)
	{
		addnode(2,rand()%3+t);
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
	if(t6-t5>=1000&&!Sup->next)
	{

	Supply* sup1 =(Supply *)malloc(sizeof(Supply));
	sup1->x = rand() % (width - 160) + 80, sup1->y = rand() % (hight - 400) + 300;
	sup1->type = rand() % 11+1;
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

	if (Sup->next)
	{


		Sup->next->x += supplyx, Sup->next->y-=supplyy;
	if (Sup->next->x> width - 80 || Sup->next->x < 80)
		supplyx = -supplyx;
	if (Sup->next->y>hight-99|| Sup->next->y<300)
			supplyy= -supplyy;
	
	}
	

	Supply * sup2 = Sup->next,*s=Sup;
	while (sup2)
	{
		if (pow(fabs(sup2->x - myplane->x), 2) + pow(fabs(sup2->y - myplane->y), 2) <= 5000)
		{
			switch (sup2->type)
			{
			case 1:
			case 2:
			case 3:
				myplane->hp += rand() % 60+40;
				break;
			case 4:
			case 5:
				myplane->q += 1;
				break;
			case 6:
			case 7:
				myplane->w += 1;
				break;
			case 8:
			case 9:
				myplane->e += 1;
				break;
			case 10:
				myplane->r += 1;
				break;
			case 11:
				if (myplane->force > 30)
				{
					addnode(5, 10);
					addnode(6, 10);
				}
				else
				myplane->force +=5;
				break;
			default:
				break;
			}
			s->next = sup2->next;
			free(sup2);
			sup2 = s->next;
		}
		else
			if (pow(fabs(sup2->x - wingplane->x), 2) + pow(fabs(sup2->y - wingplane->y), 2) <=5000)
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

	
		c2 = GetTickCount();
		if (c2 - c1 > 8000)
		cloac = 1;

		r2 = GetTickCount();
		if (r2 - r1 < 4000&&r1!=T)
		{
			Eplane * ep = ehead->next;
			ehead->hp -=1;
			while (ep&&ep->y>70)
			{
				creatdrain();
				ep->hp -= 70;
				ep = ep->next;
			}
			Raining2(1, 0, 0);
		}


}

//BOSS的生成；
void number1()
{
	vx = 1.5, vy = 1;
	ehead->x = width / 2, ehead->y = 100;
	ehead->type = 5,ehead->hp=1500;
}
void boss1move()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	if (ehead->x > width - 50 || ehead->x < 50)
		vx = -vx;
	if (ehead->y >= 400 || ehead->y < 30)
		vy = -vy;
	if (pow(fabs(ehead->x - myplane->x), 2) + pow(fabs(ehead->y - myplane->y), 2) <= 19000*cloac)
	{
		ehead->hp -= 30;
		myplane->hp -= 50;
	}
	ehead->x+= vx, ehead->y+= vy;
}

///////////////////////////////////vx,vy;

//2boss初始化与生成
void numberboss2()

{
	vx = 2, vy = 1;
	ehead->hp = 2000, ehead->type;
	ehead->x = width / 2, ehead-> y= 100;
}

void boss2move()
{
	
	if (ehead->x > width - 50|| ehead->x < 50)
		vx = -vx;
	if (ehead->y >= 700 || ehead->y < 30)
		vy = -vy;
	if (pow(fabs(ehead->x - myplane->x), 2) + pow(fabs(ehead->y - myplane->y), 2) <= 3600 * cloac)
	{
		ehead->hp -= 30;
		myplane->hp -= 50;
	}
	ehead->x += vx, ehead->y += vy;
}


//3boss初始化
void numberboss3()
{
	vx = 1.5, vy = 1;
	ehead->hp = 2500, ehead->type;
	ehead->x = width / 2, ehead->y = 100;
}

void boss3move()
{
	
		
		if (ehead->x > width - 30 || ehead->x < 30)
			vx = -vx;
		if (ehead->y >= 700 || ehead->y < 30)
			vy = -vy;
		if (pow(fabs(ehead->x - myplane->x), 2) + pow(fabs(ehead->y - myplane->y), 2) <= 3600 * cloac)
		{
			ehead->hp -= 30;
			myplane->hp -= 50;
		}
		ehead->x += vx, ehead->y += vy;
}

void MOVE()
{
	bulletmove();
	eplanemove();
	ebulletmove();
	wingplanemove();
}

//各种生成；
void CREATTHING()
{
	creatmybullet();
	creatsupply();
}



//主调函数；
int main()
{

NUM1:	gamestart();

	while (myplane->hp>0)
	{
		
	while (Score>=1000)
		{
			number1();//Boss的初始化

			while (ehead->hp>0&&myplane>0)
			{
			creatmybullet();//产生己方子弹；
			wingplanemove();
			bulletmove();//子弹的移动；
			ebulletmove();
			t4 = GetTickCount();
			if (t4-t3>=250)
			{
				addebullet(ehead->x, ehead->y, rand()%3+1);//-5-4
				t3 = t4;
			}
			
			
			creatdrain();
			Raining(1, 1, 0);
			gameprintf();//游戏的绘制；

			creatsupply();//补给的生成；
			bulletstrikt();
			eplanemove();

			ebulletmove();

			boss1move();//boss的移动；

			gameinput();//用户的输入；
			FlushBatchDraw();
			cleardevice();
			}
			if (myplane->hp <= 0)
				exit(0);
			myplane->hp += 200;
			Score = 0;
			ehead->hp = 0;
			goto NUM2;
		}

		
		
		CREATTHING();
		MOVE();
		createplane(1);
		bulletstrikt();
		//数字雨；
		creatdrain();
		Raining(0, 1, 0);
		
		gameprintf();
		FlushBatchDraw();
		gameinput();
		cleardevice();

	}

	exit(0);
NUM2:	
	while (1)
	{
		while (Score >= 1000)
		{
			//Boss的初始化
			numberboss2();
			while (ehead->hp > 0&&myplane->hp>0)
			{
				creatmybullet();//产生己方子弹；
				wingplanemove();
				bulletmove();//子弹的移动；
				ebulletmove();
				t4 = GetTickCount();
				if (t4 - t3 >=200-G)
				{
					if (ehead->hp < 500)
					{
						
						addebullet(ehead->x, ehead->y,4);//-5-4
						t3 = t4;

					}
					else
					{
						addebullet(ehead->x, ehead->y, rand() % 4 + 1);//-5-4
						t3 = t4-100;
						
					}
					if (vx + vy < 6)
						vx += 0.01, vy += 0.01;
				}

				
				


				creatdrain();
				Raining(0, 0, 1);

				gameprintf();//游戏的绘制；

				creatsupply();//补给的生成；

				eplanemove();

				ebulletmove();

				wingplanemove();
				boss2move();//boss的移动；

				gameinput();//用户的输入；
				FlushBatchDraw();
				cleardevice();
			}
			if (myplane->hp <= 0)
				exit(0);
			myplane->hp += 200;
			Score = 0;
			ehead->hp = 0;
			goto NUM3;

		}


		createplane(2);
		CREATTHING();
		MOVE();
		bulletstrikt();
		//数字雨；
		creatdrain();
		Raining(0, 0, 1);

		gameprintf();
		FlushBatchDraw();
		gameinput();
		cleardevice();

	}

NUM3:	
	while (1)
	{
		while (Score >= 1000)
		{
			//Boss的初始化
			numberboss3();
			while (ehead->hp > 0 && myplane->hp>=0)
			{
				creatmybullet();//产生己方子弹；
				wingplanemove();
				bulletmove();//子弹的移动；
				ebulletmove();
				Eplane * e = ehead;
				t4 = GetTickCount();
				if (t4 - t3 >= 300)
				{

					while (e)
					{
						addebullet(e->x, e->y,rand()%3+2);
						e = e->next;
					}
					if (vx + vy < 6)
					{
						vx += 0.01, vy += 0.01;
						
					}
						t3 = t4;
				}

				if (ehead->hp < 500 && ehead->hp>400)
				{
					ehead->hp -= 100;
					vx1=vx, vy1=vy;
					addnode(3,100);
				}
				creatdrain();
				Raining(1, 0, 0);

				gameprintf();//游戏的绘制；

				creatsupply();//补给的生成；

				bulletstrikt();

				eplanemove();

				ebulletmove();

				boss1move();//boss的移动；

				gameinput();//用户的输入；
				FlushBatchDraw();
				cleardevice();
			}
			if (myplane->hp <= 0)
				exit(0);
			myplane->hp += 200;
			Score = 0;
			goto NUM4;
		}


		createplane(3);
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

NUM4:
		while (myplane->hp>=0)
	{

		createplane(3);
		CREATTHING();
		MOVE();
		bulletstrikt();
		//数字雨；
		creatdrain();
		Raining(1, 0, 0);

		gameprintf();
		FlushBatchDraw();
		gameinput();
		cleardevice();

	}


	return 1;
}











