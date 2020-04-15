#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    /**一维数组*/
    int * oneD = new int[10];

    /**二维数组*/
    int (*twoD)[23] = new int[13][23]; //降维

    *(*(twoD+2) + 3) = 2020;

    cout << twoD[2][3] << endl; 

    getch();
    
    return 0;

}