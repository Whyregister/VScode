#include <iostream>
#include <conio.h>
#include "Landowener.h"
#include "Student.h"
using namespace std;

int main()
{
    Landowener* lan1 = new Landowener("�ܿ���");
    
    lan1->TouchCards(20);
    lan1->ShowInfor();

    getch();
    delete lan1;
    return 0;

}


