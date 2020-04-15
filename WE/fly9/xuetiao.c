
#include <stdlib.h>
#include <graphics.h>
#define width 500
#define hight 500
int x1 = 200; int y1 = 200;

int vx = 5; int vy = 2;
int main()
{
	initgraph(width, hight);
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		setfillcolor(RED);
		fillroundrect(5, 5, 400, 30,0,0);
		FlushBatchDraw();
	}
}