#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define width 1200
#define hight 1200

#define cou	60
#define	len	12
//数字雨数组
char thedigitalrain[60][12];
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

void Raining()//开始下雨；
{
	int i, j;
	for (i= 0;i< cou; i++)
	{
		settextcolor(RGB(255,255,255));
		for (j = 0; j < len; j++)
		{
			
			settextstyle(15, 5, _T("黑体"));

			outtextxy(posit[i] - 10 * j,i * 25, thedigitalrain[i][j]);
			settextcolor(RGB(0, 255 - 15 * j, 0));
		}
	}

	for (i = 0; i < cou; i++)	posit[i] += 1;

	for (i = 0; i < cou; i++)
		if (posit[i] - 15 * 10 > hight)
			posit[i] = 0;
}

int main()
{
	initgraph(width, hight);
	srand(time(NULL));
	POSITrain();
	creatdrain();
	BeginBatchDraw();
	while (1)
	{
		creatdrain();
		Raining();
		FlushBatchDraw();
		cleardevice();
	}
}