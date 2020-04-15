#include <iostream>
#include <conio.h>

using namespace std;


inline double add(double , double );
inline double sub(double , double );
inline double mul(double , double );
inline double divi(double , double );
double Calc_result(double (*)(double ,double ),double ,double );
double (*Kind_Calc(char))(double ,double );

double Calc_result(double (*s)(double ,double ),double a,double b)
{
    return (*s)(a,b);
}


double add(double a, double b)
{
    return a+b;
}

double sub(double a, double b)
{
    return a-b;
}

double mul(double a, double b)
{
    return a*b;
}

double divi(double a, double b)
{
    if(b>=0.00001)
    return a/b;
    else
    return 0;
}


/**返回 函数指针 的函数*/
double (*Kind_Calc(char symble_k))(double ,double )
{
    
    switch(symble_k)
    {
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return mul;
        case '/':
            return divi;
        default:
            return add;
    }

}



int main ()
{

    //auto ptr_func = add;
    double num1,num2;
    char symble_k;
    cout << "输入算式：" << endl;
    cin >> num1 >> symble_k >> num2;

    cout << Calc_result(Kind_Calc(symble_k),num1,num2) << endl;

    getch();
    
    return 0;

}