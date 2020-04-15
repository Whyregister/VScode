#include <stdlib.h>
//#include <graphics.h>
#define width 500
#define hight 500
int x1 = 200; int y1 = 200;

int vx = 5; int vy = 2;
int main()
{
	initgraph(width, hight);

	while (1)
	{
		cleardevice();
		circle(x1, y1, 30);
		Sleep(10);
		x1 += vx, y1 += vy;
		if (x1 > width - 30 || x1 < 30)
			vx = -vx;
		if (y1 >= hight - 30 || y1 < 30)
			vy = -vy;
	}
}