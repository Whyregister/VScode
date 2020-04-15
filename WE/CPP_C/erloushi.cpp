

#include"stdio.h"
#include"windows.h"
#include"conio.h"
#include"time.h"


#define FrameX 13
#define FrameY 3
#define Frame_height 20
#define Frame_width 18

int i,j,Temp,Temp1,Temp2;
int a[80][80]={0};//0,1,2
int b[4];
struct Tetris
{
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int score;
	int level;
};
HANDLE hOut;
// 函数声明//
int  color(int c);                  //控制台文字颜色
void gotoxy(int x,int y);           //光标移动到指定位置
void DrwaGameframe();               //绘制游戏边框
void Flag(struct Tetris *);         //随机产生俄罗斯方块
void MakeTetris(struct Tetris *);   //制作俄罗斯方块
void PrintTetris(struct Tetris *);  //打印俄罗斯方块
void CleanTetris(struct Tetris *);  //清除俄罗斯方块的痕迹
int ifMove(struct Tetris *);       //判断是否能移动，返回值为1，能移动，否则不能移动
void Del_Fullline(struct Tetris *); //判断游戏是否满行，并删除满行的俄罗斯方块
void Gameplay();                    //开始游戏
void regulation();                  //游戏规则
void explation();                   //按键说明
void welcom();                      //欢迎界面
void Replay(struct Tetris *);       //重新开始游戏
void title();                       //欢迎界面上方标题
void flower();                      //欢迎界面上的字符装饰花
void close();                       //关闭游戏



//控制文字颜色//
int  color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
}


//控制文字显示位置//
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//欢迎界面标题//
void title()
{
	color(15);
	gotoxy(24,3);
	printf("俄 罗 斯 方 块");
	color(11);
	gotoxy(18,5);
	printf("■") ;
	gotoxy(18,6);
	printf("■■");
	gotoxy(18,7);
	printf("■") ;


	color(14);
	gotoxy(26,6);
	printf("■■") ;
	gotoxy(28,7);
	printf("■■") ;


	color(10);
	gotoxy(36,6);
	printf("■■") ;
	gotoxy(36,7);
	printf("■■") ;



	color(13);
	gotoxy(45,5);
	printf("■") ;
	gotoxy(45,6);
	printf("■") ;
	gotoxy(45,7);
	printf("■") ;
	gotoxy(45,8);
	printf("■") ;

	color(12);
	gotoxy(56,6);
	printf("■■") ;
	gotoxy(52,7);
	printf("■■■") ;
}

//绘制字符花
void flower()
{
	gotoxy(65,9);
	color(5);
	printf("（。＾▽＾）");
	gotoxy(65,11);
	printf("o(*￣▽￣*)o");
	color(2);
	gotoxy(66,12);
	printf("制作人：");
	gotoxy(66,13);
	printf("曾怡晨 胡鸿 何沛杰");
	gotoxy(66,14);
	color(3);
	printf("没错就是我们");
 }


 //菜单选项
  void welcome()
 {
 	int n;
 	color (14);
 	for(i = 9;i <= 20;i++)
 	{
 		for(j = 15;j <= 60;j++)
 		{
 			gotoxy(j,i);
 			if(i == 9 || i == 20)
 				printf("=");
 			else if(j == 15 || j == 59)
 				printf("||");
		 }
	 }
	 // 打印输出文字
	 color(12);
	 gotoxy(25,12);
	 printf("1.开始游戏");
	 gotoxy(40,12);
	 printf("2.按键说明");
	 gotoxy(25,17);
	 printf("3.游戏规则");
	 gotoxy(40,17);
	 printf("4.退出");
	 gotoxy(21,22);
	 color(3);
	 printf("请选择【1 2 3 4】:[ ]\b\b");
	 color(14);
	 scanf("%d",&n);
	 switch(n)
	 {
	 	case 1:
	 		system("cls");//清屏
		 	DrwaGameframe();
		 	 Gameplay();
	 		break;
	 	case 2:
	 		explation();
	 		break;
	 	case 3:
	 		regulation();
	 		break;
	 	case 4:
	 		close();
	 		break;
	  }
 }


 //打印输出游戏窗口
  void DrwaGameframe()
 {
 	int i;
 	gotoxy(FrameX+Frame_width-7,FrameY-2);
 	color(11);
 	printf("俄罗斯方块");
 	gotoxy(FrameX,FrameY);
 	color(12);
 	printf("╔");
	gotoxy(FrameX+2*Frame_width-2,FrameY);
	printf("╗");
	gotoxy(FrameX,FrameY+Frame_height);
	printf("╚");
	gotoxy(FrameX+2*Frame_width-2,FrameY+Frame_height);
	printf("╝");
	for(i = 2;i < 2*Frame_width-2;i+=2)
	{
		gotoxy(FrameX+i,FrameY);
		printf("═");
	}
	for(i = 2;i < 2*Frame_width-2;i+=2)
	{
		gotoxy(FrameX+i,FrameY+Frame_height);
		printf("═");
		a[FrameX+i][FrameY+Frame_height] = 2;
	}
	for(i = 1;i < Frame_height;i++)
	{
		gotoxy(FrameX,FrameY+i);
		printf("║");
		a[FrameX][FrameY+i] = 2;
	}
	for(i = 1;i < Frame_height;i++)
	{
		gotoxy(FrameX+2*Frame_width-2,FrameY+i);
		printf("║");
		a[FrameX+2*Frame_width-2][FrameY+i] = 2;
	}
	color(2);
	gotoxy(FrameX+2*Frame_width+3,FrameY+7);
	printf("**********");
	gotoxy(FrameX+2*Frame_width+3,FrameY+13);
	printf("**********");
	color(3);
	gotoxy(FrameX+2*Frame_width+13,FrameY+7);
	printf("下一出现方块：");
	color(14);
	gotoxy(FrameX+2*Frame_width+3,FrameY+17);
	printf("↑键：旋转");
	gotoxy(FrameX+2*Frame_width+3,FrameY+19);
	printf("空格：暂停游戏");
	gotoxy(FrameX+2*Frame_width+3,FrameY+15);
	printf("Ese：退出游戏");
 }




//绘制俄罗斯方块
void MakeTetris(struct Tetris *tetris)
{
a[tetris->x][tetris->y] = b[0];//中心方块位置的图形状态
switch (tetris->flag)//共七大类，19种类型
{
case 1: //田字方块
{
color(10);
a[tetris->x][tetris->y - 1] = b[1];
a[tetris->x + 2][tetris->y-1]=b[2];
a[tetris->x + 2][tetris->y] = b[3];
break;
}
case 2://直线方块 ■■■■
{
color(13);
a[tetris->x - 2][tetris->y] = b[1];
a[tetris->x + 2][tetris->y] = b[2];
a[tetris->x + 4][tetris->y] = b[3];
break;
}
case 3://直线方块
/* ■
   ■
   ■
   ■*/
{
	color(13);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y - 2] = b[2];
	a[tetris->x][tetris->y + 1] = b[3];
	break;
}
case 4://T字方块
	/*
	■■■
	  ■
	*/
{
	color(11);
	a[tetris->x - 2][tetris->y] = b[1];
	a[tetris->x + 2][tetris->y] = b[2];
	a[tetris->x][tetris->y + 1] = b[3];
	break;
}
case 5://顺时针270T字方块
	/*
	  ■
	■■
	  ■
	*/
{
	color(11);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y + 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;
}
case 6:
	/*
	    ■
	  ■■■
	*/
{
	color(11);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x - 2][tetris->y] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;
}
case 7://顺时针90°T字方块
	/*
	■
	■■
	■
	*/
{
	color(11);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y + 1] = b[2];
	a[tetris->x - 2][tetris->y] = b[3];
	break;
}
case 8:/*
	 ■■
	   ■■
	   */
{
	color(14);
	a[tetris->x][tetris->y + 1] = b[1];
	a[tetris->x - 2][tetris->y] = b[2];
	a[tetris->x + 2][tetris->y + 1] = b[3];
	break;

}
case 9:/*顺时针Z字方块
	   ■
	 ■■
	 ■
	   */
{
	color(14);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x - 2][tetris->y] = b[2];
	a[tetris->x - 2][tetris->y + 1] = b[3];
	break;
}

case 10:/*反转Z字方块
		■■
      ■■

		*/
{
	color(14);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x - 2][tetris->y - 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;
}

case 11:/*顺时针Z字方块
	  ■
	  ■■
		■

		*/
{
	color(14);
	a[tetris->x][tetris->y + 1] = b[1];
	a[tetris->x - 2][tetris->y - 1] = b[2];
	a[tetris->x - 2][tetris->y] = b[3];
	break;
}
case 12:/*7字方块
	  ■■
		■
		■
		*/
{
	color(12);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y + 1] = b[2];
	a[tetris->x - 2][tetris->y - 1] = b[3];
	break;
}
case 13:/*顺时针90°7字方块
		    ■
		■■■
		*/
{
	color(12);
	a[tetris->x - 2][tetris->y] = b[1];
	a[tetris->x + 2][tetris->y - 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;
}
case 14:/* 顺时针180°7字方块
		■
		■
		■■
		*/
{
	color(12);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y + 1] = b[2];
	a[tetris->x + 2][tetris->y + 1] = b[3];
	break;
}
case 15:/*
		■■■
		■
		*/
{
	color(12);
	a[tetris->x - 2][tetris->y] = b[1];
	a[tetris->x - 2][tetris->y + 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;
}
case 16:/*
		■■
		■
		■
		*/
{
	color(12);
	a[tetris->x][tetris->y + 1] = b[1];
	a[tetris->x][tetris->y - 1] = b[2];
	a[tetris->x + 2][tetris->y - 1] = b[3];
	break;
}

case 17:/*
		■■■
		    ■
		*/
{
	color(12);
	a[tetris->x - 2][tetris->y] = b[1];
	a[tetris->x + 2][tetris->y + 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
	break;

}

case 18:/*
		■
		■
	  ■■
		*/
{
	color(12);
	a[tetris->x][tetris->y - 1] = b[1];
	a[tetris->x][tetris->y + 1] = b[2];
	a[tetris->x - 2][tetris->y + 1] = b[3];
	break;
}

case 19:/*
		■
		■■■

		*/
{
	color(12);
	a[tetris->x - 2][tetris->y] = b[1];
	a[tetris->x - 2][tetris->y - 1] = b[2];
	a[tetris->x + 2][tetris->y] = b[3];
}
}
}


//打印俄罗斯方块
void PrintTetris(struct Tetris *tetris)
{
	for(i=0;i<4;i++)
	{
	 b[i]=1;
	}
	MakeTetris(tetris);
	for(i=tetris->x-2;i<=tetris->x+4;i+=2)
	{
		for(j=tetris->y-2;j<=tetris->y+1;j++)
		{
			if(a[i][j]==1&&j>FrameY)
			{
				gotoxy(i,j);
				printf("■");
			}
		}
	}
	//打印菜单信息
	gotoxy(FrameX+2*Frame_width+3,FrameY+1);
	color(4);
	printf("level:");
	color(12);
	printf("%d",tetris->level);

	color(4);
	gotoxy(FrameX+2*Frame_width+3,FrameY+3);
	printf("score:");
	color(12);
	printf("%d",tetris->score);


	color(4);
	gotoxy(FrameX+2*Frame_width+3,FrameY+5);
	printf("speed:");
	color(12);
	printf("%d",tetris->speed);
}


//判断方块是否可移动
int ifMove(struct Tetris *tetris)
{
	if(a[tetris->x][tetris->y]!=0)
	{
		return 0;
	}
	else
	{
			if ((tetris->flag == 1 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 2 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 && a[tetris->x + 4][tetris->y] == 0)) ||
		(tetris->flag == 3 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y - 2] == 0 && a[tetris->x][tetris->y + 1] == 0)) ||
		(tetris->flag == 4 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 && a[tetris->x][tetris->y + 1] == 0)) ||
		(tetris->flag == 5 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y] == 0)) ||
		(tetris->flag == 6 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y] == 0)) ||
		(tetris->flag == 7 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 8 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0)) ||
		(tetris->flag == 9 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0)) ||
		(tetris->flag == 10 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 11 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0)) ||
		(tetris->flag == 12 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0)) ||
		(tetris->flag == 13 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 14 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y + 1] == 0)) ||
		(tetris->flag == 15 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 16 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0)) ||
		(tetris->flag == 17 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
		(tetris->flag == 18 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y + 1] == 0)) ||
		(tetris->flag == 19 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)))
		{
			return 1;
		}
	}
	return 0;
}








//清除俄罗斯方块下落痕迹
void  CleanTetris(struct Tetris *tetris)
{
	for(i=0;i<4;i++)
	{
		b[i]=0;
	}
	MakeTetris(tetris);
	for(i=tetris->x-2;i<=tetris->x+4;i+=2)
	{
		for(j=tetris->y-2;j<=tetris->y+1;j++)
		{
			if(a[i][j]==0&&j>FrameY)
			{
				gotoxy(i,j);
				printf(" ");
			}
		}
	}
}








//判断是否满行
void Del_Fullline(struct Tetris *tetris)
{
	int k,del_rows=0;
	for(j==FrameY+Frame_height-1;j>=FrameY+1;j--)
	{
		k=0;
		for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
		{
			if(a[i][j]==1)
			{
				k++;
				if(k==Frame_width-2)
				{
					for(k=FrameX+2;k<FrameX+2*Frame_width-2;k+=2)
					{
						a[k][j]=0;
						gotoxy(k,j);
						printf(" ");
					}
					for(k=j-1;k>FrameY;k--)
					{
						for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
						{
							if(a[i][k]==1)
							{
								a[i][k]==0;
								gotoxy(i,k);
								a[i][k+1]==1;
								gotoxy(i,k+1);
								printf("■");
							}
						}
					}
					j++;
					del_rows++;
				}
			}
		}
	}
	tetris->score==100*del_rows;
	if(del_rows>0&&(tetris->score%1000==0||tetris->score/1000>tetris->level-1))
	{
		tetris->speed-=20;
		tetris->level++;
	}
}
















//随机产生俄罗斯方块类型序号
void Flag(struct Tetris *tetris)
{
	tetris->number++;               // 记住产生方块个数
	srand(time(NULL));              //初始化随机数
	if(tetris->number==1)
	{
		tetris->flag=rand()%19+1;   //记住第一个方块序号
	}
	tetris->next=rand()%19+1;       //记住第下一个方块序号
}


//开始游戏
void Gameplay()
{
	int n;
	struct Tetris t,*tetris=&t;
	char ch;
	tetris->number=0;
	tetris->speed=300;
	tetris->score=0;
	tetris->level=1;
	while(1)
	{

		Flag(tetris);
		Temp=tetris->flag;
    	tetris->x =FrameX+2*Frame_width+6;
    	tetris->y =FrameY+10;
	    tetris->flag=tetris->next;
    	PrintTetris(tetris);
    	tetris->x=FrameX+Frame_width;
	    tetris->y=FrameY-1;
    	tetris->flag=Temp;

    	//按键操作
    	while(1)                                    //控制方块方向，直到方块不再下移
		{
			label: PrintTetris(tetris);             //打印俄罗斯方块
			Sleep(tetris->speed);                  //延缓时间
			CleanTetris(tetris);                   //清除痕迹
			Temp1=tetris->x;                       //记住中心方块横坐标的值
			Temp2=tetris->flag;                    //记住当前俄罗斯方块序号
			if(kbhit())                            //判断是否有键盘输入，有则用ch接收
			{
				ch=getch();
				if(ch==75)                         //按 ←建向左动，中心横坐标减2
				{
					tetris->x-=2;
				}
				if(ch==77)                         //按 →建向右动，中心横坐标加2
				{
					tetris->x+=2;
				}
				if(ch==80)                          //按 ↓加速下降
				{
					if(ifMove(tetris)!=0)
					{
						tetris->y+= 2;
					}
					if(ifMove(tetris)==0)
					{
						tetris->y=FrameY+Frame_height-2;
					}
			  }
			 if(ch==72)                              //按 ↑建则变体，既当前方块顺时针旋转90度
			 {
			 	if(tetris->flag>=2&&tetris->flag<=3)
			 	{
			 		tetris->flag++;
			 		tetris->flag%=2;
			 		tetris->flag+=2;
				 }
				 if(tetris->flag>=4&&tetris->flag<=7)
			 	{
			 		tetris->flag++;
			 		tetris->flag%=4;
			 		tetris->flag+=4;
				 }
				 if(tetris->flag>=8&&tetris->flag<=11)
			 	{
			 		tetris->flag++;
			 		tetris->flag%=4;
			 		tetris->flag+=8;
				 }
				 if(tetris->flag>=12&&tetris->flag<=15)
			 	{
			 		tetris->flag++;
			 		tetris->flag%=4;
			 		tetris->flag+=12;
				 }
				 if(tetris->flag>=16&&tetris->flag<=19)
			 	{
			 		tetris->flag++;
			 		tetris->flag%=4;
			 		tetris->flag+=16;
				 }
			 }
			 if(ch==32)                         //按空格，暂停
			 {
			 	PrintTetris(tetris);
			 	while(1)
			 	{
			 		if(kbhit())                //再按空格，继续游戏
			 		{
			 			ch=getch();
			 			if(ch==32)
			 			{
			 				goto label;
						 }
					 }
				 }
			 }
			 if(ch==27)
			 {
			 	system("cls");
			 	memset(a,0,6400*sizeof(int));        //初始化BOX数组
			 	welcome();
			 }
			 if(ifMove(tetris)==0)                   //如果不可动，上面操作无效
			 {
			 	tetris->x=Temp1;
			 	tetris->flag=Temp2;
			 }
			 else                                    //如果可动，执行操作
			 {
			 	goto label;
			 }
		}
		tetris->y++;                                 //如果无操作指令，方块向下移动
		if(ifMove(tetris)==0)                        //如果向下移动且不可动，方块放在此处
		{
			tetris->y--;
			PrintTetris(tetris);
			Del_Fullline(tetris);
			break;
		}
	  }
	  for(i=tetris->y-2;i<tetris->y+2;i++)          //游戏结束条件，方块触到框顶位置
	  {
	  	if(i==FrameY)
	  	{
	  		system("cls");
	  		gotoxy(29,7);
	  		printf("   \n");
	  		color(12);
	  		printf("\t\t\t■■■■  ■      ■  ■■    \n");
	  		printf("\t\t\t■        ■■    ■  ■  ■  \n");
	  		printf("\t\t\t■■■    ■  ■  ■  ■   ■ \n");
	  		printf("\t\t\t■        ■    ■■  ■  ■  \n");
	  		printf("\t\t\t■■■■  ■      ■  ■■    \n");
	  		gotoxy(17,18);
	  		color(14);
	  		printf("我要重新玩一局------1");
			gotoxy(44,18);
			printf("不玩了，退出吧------2\n");
			int n;
			gotoxy(32,20);
			printf("选择【1/2】：");
			color(11);
			scanf("%d",&n);
			switch(n)
			{
				case 1:
					system("clse");
					Replay(tetris);                 //重新开始游戏
					break;
				case 2:
					exit(0);
					break;
			}
		  }
	  }
	  tetris->flag=tetris->next;                    //清除下一个俄罗斯方块图形（右边窗口）
	  tetris->x=FrameX+2*Frame_width+6;
	  tetris->y=FrameY+10;
	  CleanTetris(tetris);
   }
}

//重新开始游戏
void Replay(struct Tetris *tetris)
{
	system("cls");
	memset(a,0,6400*sizeof(int));
	DrwaGameframe();
	Gameplay();
}

//按键说明

void explation()
{
	int i,j=1;
	system("cls");
	color(13);
	gotoxy(32,3);
	printf("按键说明");
	color(2);
	for(i=6;i<=16;i++)
	{
		for(j=15;j<=60;j++)
		{
			gotoxy(j,i);
			if(i==6||i==16)
			{
				printf("=");
			}
			else if(j==15||j==59)
			{
				printf("||");
			}
		}
	}
	color(3);
	gotoxy(18,7);
	printf("tip1：玩家可通过 ← →方向键来移动方块");
	color(10);
	gotoxy(18,9);
	printf("tip2：玩家可通过 ↑使方块旋转");
	color(14);
	gotoxy(18,11);
	printf("tip3：玩家可通过 ↓使方块加速下落");
	color(11);
	gotoxy(18,13);
	printf("tip4：按空格暂停游戏，再按空格继续游戏");
	color(4);
	gotoxy(18,15);
	printf("tip5：按ESC退出游戏");
	getch();
	system("cls");
 }


 //游戏规则

 void  regulation()
 {
 	int i,j=1;
 	system("cls");
 	color(13);
 	gotoxy(34,3);
 	printf("游戏规则");
 	color(2);
	for(i=6;i<=18;i++)
	{
		for(j=12;j<=70;j++)
		{
			gotoxy(j,i);
			if(i==6||i==18)
			{
				printf("=");
			}
			else if(j==12||j==69)
			{
				printf("||");
			}
		}
	}
	color(12);
	gotoxy(16,7);
	printf("tip1：不同形状的小方块从屏幕上方落下，玩家通过调整");
	gotoxy(22,9);
	printf("方块的位置和方向，使它们在屏幕底部拼出完整的");
	gotoxy(16,11);
	printf("一条或几条");
	color(14);
	gotoxy(16,13);
	printf("tip2：每消除一行积分增加100");
	color(11);
	gotoxy(16,15);
	printf("tip3：每累计1000分，会提升一个等级");
	color(10);
	gotoxy(16,17);
	printf("tip4：提升等级会使方块下落速度加快，游戏难度加大");
	getch();          //按任意键返回主界面
	system("cls");

}


//退出程序

void close()
{
	exit(0);
}


 int main()
 {
 	title();
 	flower();
 	welcome();
 	return 0;
 }








